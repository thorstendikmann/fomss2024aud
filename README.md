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

### Docker - Linux

- If docker is used, the "host" Linux only needs to have docker installed.
- [Install Docker Desktop on Linux](https://docs.docker.com/desktop/install/linux-install/)

### Docker - Windows with WSL

- [Docker Desktop WSL 2 backend on Windows](https://docs.docker.com/desktop/wsl/)
- [Get started with Docker remote containers on WSL 2](https://learn.microsoft.com/en-us/windows/wsl/tutorials/wsl-containers)
- In the WSL guest system:
```
aptitude install docker
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
- Running the image will execute [run.sh](src/run.sh) inside the image - the script just calls a couple of compiled programs.

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