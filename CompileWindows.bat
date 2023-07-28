@echo off

if not exist "build" (
  mkdir build
)
if not exist "3rdparty/raylib" if not exist "3rdparty/fmt" (
  .\update.bat
)
cd build
call "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvars64.bat" > NUL
echo "call msvc ..."
cmake -G Ninja .. > NUL 
echo "Generating CmakeFiles"
ninja > NUL
echo "Compiling Please Wait..."

cd bin
.\Eat-The-Mushroom.exe
cd .. 
cd ..
pause