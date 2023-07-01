## <b>How To compile on Macos ? :</b>

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

<b> In Apple Silicone </b>
```
mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=Release -G "Ninja" -DCMAKE_OSX_ARCHITECTURES=arm64 -DCMAKE_OSX_DEPLOYMENT_TARGET=10.15 -DCMAKE_OSX_SYSROOT=/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk ..
ninja
```

<b> In Apple Intel </b>

```
mkdir build
cd build
cmake -B ${{github.workspace}}/build -DCMAKE_BUILD_TYPE=${{env.BUILD_TYPE}} -G "Ninja" -DCMAKE_OSX_ARCHITECTURES=x86_64 -DCMAKE_OSX_DEPLOYMENT_TARGET=10.15 -DCMAKE_OSX_SYSROOT=/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk
ninja
```

and if all went well the executable should be in "build/bin/Eat-the-mushroom