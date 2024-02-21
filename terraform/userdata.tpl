#!/bin/bash
# See https://docs.docker.com/engine/install/debian
sudo apt-get update -y &&
sudo apt-get install -y \
  aptitude \
  apt-transport-https \
  ca-certificates \
  curl \
  gnupg-agent \
  cmake \
  build-essential \
  git \
  valgrind \
  googletest \
  libgtest-dev \
  gdb \
  software-properties-common &&
sudo install -m 0755 -d /etc/apt/keyrings &&
sudo curl -fsSL https://download.docker.com/linux/debian/gpg -o /etc/apt/keyrings/docker.asc &&
sudo chmod a+r /etc/apt/keyrings/docker.asc &&
echo \
  "deb [arch=$(dpkg --print-architecture) signed-by=/etc/apt/keyrings/docker.asc] https://download.docker.com/linux/debian \
  $(. /etc/os-release && echo "$VERSION_CODENAME") stable" | \
  sudo tee /etc/apt/sources.list.d/docker.list > /dev/null
sudo apt-get update &&
sudo apt-get install -y docker-ce docker-ce-cli containerd.io docker-buildx-plugin docker-compose-plugin
sudo usermod -aG docker admin

sudo apt-get install -y libboost-all-dev