# README

This repository contains material and source code examples corresponding to the "Algorithm & Datastructures" lecture at FOM Hochschule für Oekonomie & Management gGmbH.

The source code can be conveniently compiled and executed in a Docker container.

## Requirements

### Direct - Linux & Windows with WSL

- The description of all necessary tools is included in [Dockerfile](Dockerfile).
- Most notably, a C/C++ development environemt needs to be installed:
```
apt-get install cmake build-essential gdb ## ... and more
apt-get install googletest libgtest-dev
```
- For memory (leak) checking
```
apt-get install valgrind
```
- If you want to utilize the doxygen-generated documentation:
```
apt-get install doxygen graphviz
```

### Docker - Linux

- If docker is used, the "host" Linux only needs to have docker installed.
- [Install Docker Desktop on Linux](https://docs.docker.com/desktop/install/linux-install/)

### Docker - Windows with WSL (+Ubuntu/Debian)

- [Docker Desktop WSL 2 backend on Windows](https://docs.docker.com/desktop/wsl/)
- [Get started with Docker remote containers on WSL 2](https://learn.microsoft.com/en-us/windows/wsl/tutorials/wsl-containers)
- In the WSL guest system:
```
apt-get install docker
```

## Building and running the software

### Without docker

- The top level [Makefile](Makefile) takes care fore running an out-of-source build in the `build` folder.
```
make
build/bin/hello_world_c
```

### With docker

- The same [Makefile](Makefile) contains several commands to simplify the build and execution with docker.
```
make dockerbuild  ## only build image
make docker       ## build & run
```
- Running the image will execute [run.sh](src/run.sh) inside the image - The script just calls a couple of compiled programs.
- The [Dockerfile](Dockerfile) also contains a section to automatically start a "documentation server" - this will be available at [localhost:8080/](http://localhost:8080/) then.

# Optional parts

## Boost

- Boost is a library collection offering several tasks, structures and algorithms.
- Install boost libraries
```
apt-get install libboost-all-dev
```

## Assembler & Qemu

- Install assembler and qemu emulator. Add architecture if needed.
```
## dpkg --print-architecture
#dpkg --add-architecture armel

apt-get install crossbuild-essential-armel
apt-get install qemu-user
```
- Cross-Build with CMake for ARM:
```
cmake .. -DCMAKE_TOOLCHAIN_FILE=../CMake-Toolchain-linux-arm.txt
```
- Execute cross-compiled assembler with `qemu-arm` 
```
qemu-arm bin/hello_world_asm_arm
```

## Rust

- Install rust compiler and package manager.
```
## package rustup in future Debian versions?
apt-get install rustc cargo rustfmt
```
- Build rust files
```
cargo build
```
- Run binaries
```
cargo run --bin hello
cargo run --bin hellorust
```
- Run tests


## Terraform

### Install

- See [Install Terraform](https://developer.hashicorp.com/terraform/install)
- AWS Provider Documentation: [AWS Provider](https://registry.terraform.io/providers/hashicorp/aws/latest/docs)
- Running Terraform
```
terraform plan
terraform apply -auto-approve
terraform destroy
```

# References

Examples and 

- Kernighan, B. W., & Ritchie, D. M. (1988). The C programming language.
- Stroustrup, Bjarne. Die C++ Programmiersprache. Pearson Deutschland GmbH, 2000.