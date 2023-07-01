## <b>How To compile on Windows ? :</b>

warning cmake and ninja must be installed! 
(cmake >= 20)

the first thing you need to do is copy the repository with git

```
git clone https://github.com/kaissouDev/Eat-the-Mushroom.git
cd Eat-the-Mushroom
```

then you'll need to update the git sub-modules 

```
git submodule update --init --recursive
```

Once everything is in order, we can start compiling: 


<b> With MSVC </b>
```
call "C:\Program Files\Microsoft Visual Studio\2022\Community\Common7\Tools\VsDevCmd.bat" -arch=x64
mkdir build
cd build
Cmake -G Ninja ..
ninja
```

<b> With Mingw </b>
```
mkdir build
cd build
Cmake -G Ninja ..
ninja
```

and if all went well the executable should be in "build/bin/Eat-the-mushroom