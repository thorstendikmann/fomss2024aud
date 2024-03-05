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
  - [Assembler & Qemu](#assembler--qemu)
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
```console
# sudo or do as user `root`
apt-get install cmake build-essential
```
- There are some libraries and tools we utilize, so let's install them, too. _Note:_ You could skip these for now and look in the [recommended addons](#recommended-addons) section below for the details.

```console
apt-get install gdb
apt-get install googletest libgtest-dev
apt-get install libboost-all-dev
```
- If you want to utilize the doxygen-generated documentation:
```console
apt-get install doxygen graphviz
```
- For memory (leak) checking
```console
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
```console
apt-get install docker
```

## Building and running the software

### Without docker

- The top level [Makefile](Makefile) takes care fore running an out-of-source build in the `build` folder.
```console
mkdir -p build && cd build
cmake ..
# or if you have installed gtest and boost:
cmake .. -DWITH_GTEST=ON -DWITH_BOOST=ON

make
bin/hello/hello_world_c
```

### With docker

- The same [Makefile](Makefile) contains several commands to simplify the build and execution with docker.
```console
make dockerbuild  # only build image
make docker       # build & run
```
- Running the image will execute [run.sh](src/run.sh) inside the image - The script just calls a couple of compiled programs.
- The [Dockerfile](Dockerfile) also contains a section to automatically start a "documentation server" - this will be available at [localhost:8080/](http://localhost:8080/) then.

## Recommended addons

### Boost

- Boost is a library collection offering many additions to the C++ standard library, including structures and algorithms.
- Install boost libraries (... all)
```console
apt-get install libboost-all-dev
```
- Ensure you run CMake with the `-DWITH_BOOST=ON` option, e.g.
```console
cmake .. -DWITH_BOOST=ON
```

### GoogleTest

GoogleTest is a well-known testing and mocking framework for C++. It's for unit testing "and beyond", while we will docus on utilizing it ensuring our algorithms do what they're supposed to.
```console
apt-get install googletest libgtest-dev
```
- Ensure you run CMake with the `-DWITH_GTEST=ON` option, e.g.
```console
cmake .. -DWITH_GTEST=ON
```

## Optional parts

The scripts contained in this repository can be used to experiment with other programming languages and environments. Optional, but a good start for a playground.

### Assembler & Qemu

- Install assembler and qemu emulator. Add architecture if needed.
```console
# dpkg --print-architecture
#dpkg --add-architecture armel

apt-get install crossbuild-essential-armel
apt-get install qemu-user
```console
- Cross-Build with CMake for ARM:
```
cmake .. -DCMAKE_TOOLCHAIN_FILE=../CMake-Toolchain-linux-arm.txt
```
- Execute cross-compiled assembler with `qemu-arm` 
```console
qemu-arm bin/hello_world_asm_arm
```

### Rust

- Install rust compiler and package manager.
```console
# package rustup in future Debian versions?
apt-get install rustc cargo rustfmt
```
- Build rust files
```console
cargo build
```
- Run binaries
```console
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
```console
cd  terraform
terraform init
terraform plan
terraform apply -auto-approve
# terraform destroy
```
- This should setup a "plain" build environment with an installed docker.
- At the end of the script, the `instance_public_ip_addr` will be displayed. Then you can login:
```console
ssh admin@<xx.yyy.zz.dd>
# and on remote system:
mkdir workspace && cd workspace
git clone https://github.com/thorstendikmann/fomss2024aud.git
cd fomss2024aud/
```
- ... and build:
```console
mkdir build && cd build
cmake ..
make
```
- ... or via Docker:
```console
cd ~/workspace/fomss2024aud
make docker
```

## References

### Examples and some additional literature:

- Kernighan, B. W., & Ritchie, D. M. (1988). The C programming language.
- Stroustrup, Bjarne. Die C++ Programmiersprache. Pearson Deutschland GmbH, 2000.

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

