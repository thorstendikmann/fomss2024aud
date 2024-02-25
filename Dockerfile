##
## Buildenv
##
FROM    debian:stable  AS buildenv

LABEL   version="1.0.1"
LABEL   description="Build environment for compiling and executing examples and exercises."
LABEL   com.example.vendor="FOM"
LABEL   org.opencontainers.image.authors="Thorsten Dikmann"
LABEL   description="Container building source code for some programming examples."

RUN     apt-get -q update --fix-missing && apt-get -qy upgrade 

## C/C++ Development environment
RUN     apt-get -qy install --no-install-recommends \
        apt-utils \
        cmake \
        build-essential \
        g++-multilib \
        locales \
        wget \
        bash \
        curl
# Additional applications and libraries
RUN     apt-get -qy install --no-install-recommends \
        valgrind \
        libgtest-dev \
        googletest \
        libboost-all-dev \
        doxygen \
        graphviz

# Assembler & Virtualization
RUN     apt-get -qy install --no-install-recommends \
        crossbuild-essential-armel \
        qemu-user

## Rust
RUN     apt-get -qy install --no-install-recommends \
        rustc cargo rustfmt git ca-certificates

## Python
RUN     apt-get -qy install --no-install-recommends \
        python3 \
        python3-venv \
        python3-pip

# Setting up virtual env
ENV     VIRTUAL_ENV=/opt/venv
RUN     python3 -m venv $VIRTUAL_ENV
ENV     PATH="$VIRTUAL_ENV/bin:$PATH"

COPY    requirements.txt .
RUN     pip3 install -r requirements.txt

## Compile
ARG     buildroot=/buildenv
ARG     builddir=$buildroot/build
ARG     appdir=$buildroot/app
ARG     destdir=$buildroot/destdir

RUN     mkdir -p $buildroot &&\
        mkdir -p $builddir &&\
        mkdir -p $appdir &&\
        mkdir -p $destdir && \
        mkdir -p ~/.cargo && \
        echo '[net]\n' >> ~/.cargo/config &&\
        echo 'git-fetch-with-cli = true\n\n' >> ~/.cargo/config

COPY    . $appdir

## We skip rust and asm here to speedup the process
##  -DWITH_RUST=ON -DWITH_ASM=ON
RUN     cd $builddir && \
        cmake $appdir \
          -DCMAKE_INSTALL_PREFIX=/ \
          -DWITH_DOC=ON -DWITH_GTEST=ON \
          -DWITH_BOOST=ON && \
        make && \
        make install DESTDIR=$destdir &&\
        rm $builddir -Rf

# Remove everything but Python scripts
RUN     cd $appdir && find . -type f ! -name '*.py' -delete && find . -type d -empty -delete

##
## Runner
##

FROM    alpine:latest    AS runner
RUN     apk --no-cache add ca-certificates bash
#       glibc & libstdc++.so.6 - See https://pet2cattle.com/2022/11/alpine-not-found
RUN     apk --no-cache add libc6-compat libstdc++
RUN     apk add --no-cache valgrind
RUN     apk add --no-cache python3 py3-pip

### No Cache from here
### Add "no cache" command: see https://stackoverflow.com/questions/35134713/disable-cache-for-specific-run-commands
#ADD "https://www.random.org/cgi-bin/randbyte?nbytes=10&format=h" skipcache

COPY    --from=buildenv /buildenv/destdir /app
COPY    --from=buildenv /buildenv/app/src /app/src

RUN     /app/bin/run.sh

##
## Setup doc Webserver ... for fun
##
FROM    m4rcu5/lighttpd    AS docserver

COPY    --from=runner /app/share/doc/html /var/www/localhost/htdocs