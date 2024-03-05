# README

This repository contains material and source code examples corresponding to the "Algorithm & Datastructures" lecture at FOM Hochschule für Oekonomie & Management gGmbH.

The source code can be compiled "traditionally" utilizing CMake or conveniently compiled and executed in a Docker container.

**Table of Contents**

<!-- 
Updating toc:
cd ~ && npm install doctoc
~/node_modules/doctoc/doctoc.js --github README.md
 -->

<!-- START doctoc generated TOC please keep comment here to allow auto update -->
<!-- DON'T EDIT THIS SECTION, INSTEAD RE-RUN doctoc TO UPDATE -->

- [README](#readme)
  - [Local Build Requirements](#local-build-requirements)
  - [Docker-based Build Requirements](#docker-based-build-requirements)
    - [Docker in "native" Linux](#docker-in-native-linux)
    - [Docker - Windows with WSL (+Ubuntu/Debian)](#docker---windows-with-wsl-ubuntudebian)
  - [Building and running the software](#building-and-running-the-software)
    - [Without docker](#without-docker)
    - [With docker](#with-docker)
  - [Recommended addons](#recommended-addons)
    - [Boost](#boost)
    - [GoogleTest](#googletest)
  - [Optional parts](#optional-parts)
    - [Assembler \& Qemu](#assembler--qemu)
    - [Rust](#rust)
    - [Terraform](#terraform)
  - [References](#references)
    - [Examples and some additional literature:](#examples-and-some-additional-literature)
    - [Toolchain](#toolchain)

<!-- END doctoc generated TOC please keep comment here to allow auto update -->

## Local Build Requirements

This section describes how to compile and run the source code directly on the computer without any additional container.

<!-- ### Debian(-based) Linux & Windows with WSL -->

Any reasonably recent Debian version or Debian-based system like Ubuntu or Linux Mint will be suitable for this guide, either running directly on the computer or within the "Windows Subsystem for Linux".

- Most notably, a C/C++ development environemt needs to be installed. Luckily, Debian covers most of if in the package `build-essential`.
```sh
# sudo or do as user `root`
apt-get install cmake build-essential
```
- There are some libraries and tools we utilize, so let's install them, too. _Note:_ You could skip these for now and look in the [recommended addons](#recommended-addons) section below for the details.

```sh
apt-get install gdb
apt-get install googletest libgtest-dev
apt-get install libboost-all-dev
```
- If you want to utilize the doxygen-generated documentation:
```sh
apt-get install doxygen graphviz
```
- For memory (leak) checking
```sh
apt-get install valgrind
```

## Docker-based Build Requirements

### Docker in "native" Linux

- The "host" system only needs to have docker installed.
- [Install Docker Desktop on Linux](https://docs.docker.com/desktop/install/linux-install/)

### Docker - Windows with WSL (+Ubuntu/Debian)

- With WSL, it's a bit trickyer - we need to install Docker in Windows, first. There is documentation on how to do that:
    - [Docker Desktop WSL 2 backend on Windows](https://docs.docker.com/desktop/wsl/)
    - [Get started with Docker remote containers on WSL 2](https://learn.microsoft.com/en-us/windows/wsl/tutorials/wsl-containers)
- In the WSL Linux guest system:
```sh
apt-get install docker
```

## Building and running the software

### Without docker

- The top level [Makefile](Makefile) takes care fore running an out-of-source build in the `build` folder.
```sh
mkdir -p build && cd build
cmake ..
# or if you have installed gtest and boost:
cmake .. -DWITH_GTEST=ON -DWITH_BOOST=ON

make
bin/hello/hello_world_c
```

### With docker

- The same [Makefile](Makefile) contains several commands to simplify the build and execution with docker.
```sh
make dockerbuild  # only build image
make docker       # build & run
```
- Running the image will execute [run.sh](src/run.sh) inside the image - The script just calls a couple of compiled programs.
- The [Dockerfile](Dockerfile) also contains a section to automatically start a "documentation server" - this will be available at [localhost:8080/](http://localhost:8080/) then.

## Recommended addons

### Boost

- Boost is a library collection offering many additions to the C++ standard library, including structures and algorithms.
- Install boost libraries (... all)
```sh
apt-get install libboost-all-dev
```
- Ensure you run CMake with the `-DWITH_BOOST=ON` option, e.g.
```sh
cmake .. -DWITH_BOOST=ON
```

### GoogleTest

GoogleTest is a well-known testing and mocking framework for C++. It's for unit testing "and beyond", while we will docus on utilizing it ensuring our algorithms do what they're supposed to.
```sh
apt-get install googletest libgtest-dev
```
- Ensure you run CMake with the `-DWITH_GTEST=ON` option, e.g.
```sh
cmake .. -DWITH_GTEST=ON
```

## Optional parts

The scripts contained in this repository can be used to experiment with other programming languages and environments. Optional, but a good start for a playground.

### Assembler & Qemu

- Install assembler and qemu emulator. Add architecture if needed.
```sh
# dpkg --print-architecture
#dpkg --add-architecture armel

apt-get install crossbuild-essential-armel
apt-get install qemu-user
```

- Cross-Build with CMake for ARM:
```sh
cmake .. -DCMAKE_TOOLCHAIN_FILE=../CMake-Toolchain-linux-arm.txt
```
- Execute cross-compiled assembler with `qemu-arm`

```sh
qemu-arm bin/hello_world_asm_arm
```

### Rust

- Install rust compiler and package manager.
```sh
# package rustup in future Debian versions?
apt-get install rustc cargo rustfmt
```
- Build rust files
```sh
cargo build
```
- Run binaries
```sh
cargo run --bin hello
cargo run --bin hellorust
```
- Run tests


### Terraform

Not having a suitable build environment at hand? No problem! With today's hyperscalers, we're only a couple of commands away from building one. This is utilizing AWS here - could be any hyperscaler, though.

- Installation: see [Install Terraform](https://developer.hashicorp.com/terraform/install)
- AWS Provider Documentation: [AWS Provider](https://registry.terraform.io/providers/hashicorp/aws/latest/docs)
- Ensure you have a local ssh key in `~/.ssh/id_ed25519.pub`.
- Running Terraform to setup a build environment:
```sh
cd  terraform
terraform init
terraform plan
terraform apply -auto-approve
# terraform destroy
```
- This should setup a "plain" build environment with an installed docker.
- At the end of the script, the `instance_public_ip_addr` will be displayed. Then you can login:
```sh
ssh admin@<xx.yyy.zz.dd>
# and on remote system:
mkdir workspace && cd workspace
git clone https://github.com/thorstendikmann/fomss2024aud.git
cd fomss2024aud/
```
- ... and build:
```sh
mkdir build && cd build
cmake ..
make
```
- ... or via Docker:
```sh
cd ~/workspace/fomss2024aud
make docker
```

## References

### Examples and some additional literature:

- R. Sedgewick, Algorithms in C / C++, Parts 1-4,5. Addison-Wesley, 1998–2002.
- R. Sedgewick and K. Wayne, Algorithmen und Datenstrukturen. Pearson, 2014.
- J. Canning, A. J. Broder, and R. Lafore, Data Structures & Algorithms in Python. Addison-Wesley, 2023.
- D. E. Knuth, The Art of computer programming. Volume 1-4. Addison-Wesley Professional, 1997–2022.
- H. Knebl, Algorithmen und Datenstrukturen. Springer, 2019.
- R. H. Güting and S. Dieker, Datenstrukturen und Algorithmen, Springer, 2018.
- G. Pomberger and H. Dobler, Algorithmen und Datenstrukturen: eine systematische Einführung in die Programmierung. Pearson, 2008.
- D. Harel and Y. A. Feldman, Algorithmics: The spirit of computing. Pearson Education, 2004.
- B. N. Miller and D. L. Ranum, Problem solving with algorithms and data structures using Python. Franklin, Beedle & Associates Inc., 2011. 
- A. Solymosi and U. Grude, Grundkurs Algorithmen und Datenstrukturen in JAVA, vol. 4. Springer, 2017.
- P. Widmayer and T. Ottmann, Algorithmen und Datenstrukturen. Springer, 2017.

- B. W. Kernighan and D. M. Ritchie, The C programming language. Prentice Hall, 1988.
- B. Stroustrup, Die C++ Programmiersprache. Addison-Wesley, 2000.
- B. Stroustrup, Einführung in die Programmierung mit C++. Pearson Studium, 2010. Note: you will need [std_lib_facilities.h](https://github.com/BjarneStroustrup/Programming-_Principles_and_Practice_Using_Cpp/blob/master/std_lib_facilities.h)
- T. Theis, Einstieg in C. Rheinwerk Verlag, 2023.
- R. Krooß and J. Wolf, C von A bis Z - das umfassende Handbuch. Rheinwerk Computing, 2023.
- D. Bär, Schrödinger programmiert C++. Rheinwerk Computing, 2024.
- U. Kaiser and M. Guddat, C/C++ - Das umfassende Lehrbuch. Galileo Press, 2014. T. T. Will, Einführung in C++. Galileo Computing, 2023.

- J. Ernesti and P. Kaiser, Python 3. Rheinwerk, 2023.
- M. Inden, Einfach Python. dpunkt Verlag, 2022.
- S. Elter, Schrödinger programmiert Python. Rheinwerk Verlag, 2021.


### Toolchain

- [CMake](https://cmake.org/)
- [GCC](https://gcc.gnu.org/)
- [Doxygen](https://www.doxygen.org)
- [Docker](https://www.docker.com/)
- [GNU Make](https://www.gnu.org/software/make/)
- [Windows Subsystem for Linux](https://learn.microsoft.com/en-us/windows/wsl/)
- [QEMU](https://www.qemu.org/)
- [Git](https://git-scm.com/)
- [Terraform](https://www.terraform.io/)
- [Rust & Cargo](https://doc.rust-lang.org/stable/cargo/)
- [Debian](https://www.debian.org/)
- [Valgrind](https://valgrind.org/)
- [Google Test](https://google.github.io/googletest/)
- [Boost C++ Libraries](https://www.boost.org/)
- [doctoc](https://github.com/thlorenz/doctoc) - for updating the "table of contents" of this file.

