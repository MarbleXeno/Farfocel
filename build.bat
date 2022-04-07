@echo off

IF "%~1" == "" GOTO PrintHelp
IF "%~1" == "compile" GOTO Compile
IF "%~1" == "rebuild" GOTO Rebuild
IF "%~1" == "run" GOTO Run

echo Starting generating the project for selected option.
echo.
vendor\premake\premake5.exe %1
GOTO Done

:PrintHelp

echo.
echo    Enter 'build.bat ~action~' where ~action~ is one of the following:
echo.
echo        compile           - Just compile using mingw with the use of makefiles.
echo        rebuild           - Generate new makefiles and then compile them using mingw.
echo        run               - Launch compiled application.
echo.
echo        gmake2            - Generate GNU makefiles for multiplatform compilation on Windows, Linux and macOS.
echo        codelite          - Generate CodeLite project files.
echo        vs2005            - Generate Visual Studio 2005 project files.
echo        vs2008            - Generate Visual Studio 2008 project files.
echo        vs2010            - Generate Visual Studio 2010 project files.
echo        vs2012            - Generate Visual Studio 2012 project files.
echo        vs2013            - Generate Visual Studio 2013 project files.
echo        vs2015            - Generate Visual Studio 2015 project files.
echo        vs2017            - Generate Visual Studio 2017 project files.
echo        vs2019            - Generate Visual Studio 2019 project files.
echo        vs2022            - Generate Visual Studio 2022 project files.
echo        xcode4            - Generate Apple Xcode 4 project files.
echo.
GOTO Done

:Compile
mingw32-make
GOTO Done

:Rebuild
echo Starting generating makefiles.
echo.
vendor\premake\premake5.exe gmake2
echo.
echo Starting compiling using makefiles.
echo.
mingw32-make
GOTO Done


:Run
IF "%~2" == "" goto RunHelp

IF "%~2" == "debug" Sandbox\bin\Debug\Sandbox.exe
IF "%~2" == "release" Sandbox\bin\Release\Sandbox.exe
goto Done
:RunHelp
echo.
echo    Enter 'build.bat run ~action~' where ~action~ is one of the following:
echo.
echo         debug
echo         release
echo.
goto Done

:Done
