#!/bin/bash

# Update package lists
sudo apt-get update

# Install additional package
sudo apt-get install -y \
    libgtest-dev \
    googletest \
    libboost-all-dev \
    doxygen \
    graphviz

# install python requirements
pip install -r requirements.txt