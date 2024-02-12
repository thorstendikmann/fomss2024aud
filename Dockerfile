FROM    debian:stable
RUN     apt-get -q update --fix-missing && apt-get -qy upgrade 

## C/C++ Development environment
RUN     apt-get -qy install --no-install-recommends \
        apt-utils \
        cmake \
        build-essential \
        g++-multilib \
        locales \
        make \
        wget \
        bash \
        curl
# Additional applications and libraries
RUN     apt-get -qy install --no-install-recommends \
        libgtest-dev \
        googletest
        
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
RUN     mkdir -p /tmp
COPY    . /tmp/app
RUN     mkdir -p /build \
        cd /build && \
        cmake /tmp/app -DCMAKE_INSTALL_PREFIX=/ && \
        make && \
        make install DESTDIR=/app &&\
        rm /build -Rf

CMD /tmp/app/src/run.sh