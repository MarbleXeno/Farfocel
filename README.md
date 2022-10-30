# Welcome to Farfocel
Farfocel is a set of tools (or an engine, if you want to call it like that) for making 2D games with SFML and C++. It's my personal project for learning C++ development, so keep in mind that the code you'll see is probably not in the best quality.

### Currently, the project consists of 4 main managers + smaller utilities:
#### 1. Scene Manager - a convenient tool for managing scenes
#### 2. Input and Event Managers - bind functions to user inputs and/or events
#### 3. Resource Loader and Storer - load assets for your game, store and get them when you need
#### 4. Sprite Animation Manager - load 2D sprite animations from Texture Atlases and apply them to your sprites

In the future, I want to add an error logger and a simple GUI library.

## Latest update:
Migrated the project from Premake5 to CMake for better compatibility with IDEs and text editors.
The compiling process is now much easier.

## How to compile Farfocel
Farfocel uses CMake as its build tool. All you need to do is copy the GitHub project and generate the solution for your desired IDE or compiler. 

On Windows, Farfocel fetches the SFML library source and compiles it according to your build type.

On Linux/MacOS, Farfocel uses only the dynamic version of SFML. Before you start compiling, you have to [install it first on your machine](https://www.sfml-dev.org/tutorials/2.5/start-linux.php).
