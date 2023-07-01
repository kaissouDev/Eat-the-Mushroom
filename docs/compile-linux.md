## <b>How To compile on Linux ? :</b>

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

Note that you should also install dependencies here is the command if you are running ubuntu, there are alternatives for other Linux distributions

```
sudo apt-get update
sudo apt-get install -y g++ clang libc++-dev libc++abi-dev cmake ninja-build libx11-dev libxcursor-dev libxi-dev libgl1-mesa-dev libfontconfig1-dev libxrandr-dev libxinerama-dev libgtk-3-dev
```


Once everything is in order, we can start compiling: 

```
mkdir build
cd build
cmake -G Ninja ..
ninja
```

and if all went well the executable should be in "build/bin/Eat-the-mushroom