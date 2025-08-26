# OpenGL Setup on Ubuntu

This project uses **OpenGL**, **GLFW**, and **GLEW** for graphics rendering.

## Installation

Run the following commands on Ubuntu/Debian:

```bash
sudo apt update
sudo apt install build-essential cmake
sudo apt install mesa-common-dev libgl1-mesa-dev
sudo apt install libglfw3-dev libglew-dev
```

## To compile
```bash
g++ main.cpp -o sym -lGL -lglfw -lGLEW
```

## To run
```bash
./sym
```