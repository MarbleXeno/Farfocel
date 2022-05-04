# An Official Logo of Farfocel - now animated:
![An official logo of Farfocel](GithubProjectAssets/official_frcl_engine_logo_animated_2010_cooltext_text_generator.gif)

# Why is the development progress so slow!?
Because I'm lazy and often don't have much time.

# Which IDE is used to write this project?
I test this project on different IDEs/compilers regularly, to see if everything works correctly. Primarily though, I use Jetbrains CLion and Visual Studio 2022.

# How to compile?
Farfocel "Engine" uses Premake5 as its primary build system and the SFML library for multimedia functionalities.

There is a possibility to use a CMake build system by using [this Premake5 extension](https://github.com/Enhex/premake-cmake).
The guide below is based upon the Premake5.

### 1) On Windows
On Windows, you can compile Farfocel "Engine" using a Visual Studio or MingW. Create the project for your desired IDE/compiler
using the Premake5 that is included in the vendor directory. Generate the project for Visual Studio (recomended) or MingW and 
compile it. You will obtain a static library.

***Keep in mind!***
As for now, with the Github project, statically compiled SFML library for MingW compiler (.a extension) **is not included**, which means, you have to
compile it yourself. Making it possible to generate a Premake5 project without the use of static SFML library is on my to-do list.
In the meantime, [here's a guide](https://www.sfml-dev.org/tutorials/2.5/compile-with-cmake.php) which will help you generating a static SFML project for MingW which you can then compile.

### 2) On Linux/MacOS
On Linux/MacOS, Farfocel "Engine" uses a dynamic version of SFML library. Download it for your system using [this guide](https://www.sfml-dev.org/download/sfml/2.5.1/).
Install a C++ compiler and Premake5. After that, you can generate a Farfocel "Engine" project and compile it. You will obtain
a static library.

# How to use it
For now, to use the "Engine", you need to compile it from source yourself. If you already didn't, go to the section
describing it to learn how to do that. After compiling it, you will obtain a static library which you can link to. Don't forget to add 'Farfocel.hpp' public header, and 'EntryPoint.hpp' files to your include paths.

***Keep in mind!***
You have to add the SFML library to your app project, since the Farfocel uses and requires it.

**If you don't want to create your own app project, you can also use a Sandbox project included in this repo,**
which is already setup and uses Premake5.