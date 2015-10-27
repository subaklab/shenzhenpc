# Develop Environment On Mac OSX

## lpc21isp 

Firmware uploader using ftdi232

```
sudo brew install lpc21isp
```

## gcc 

```
#!/bin/sh

GCC_VERSION="gcc-arm-none-eabi-4_9-2015q2"
GCC_OS="-20150609-mac"
GCC="$GCC_VERSION$GCC_OS"

curl -L https://launchpad.net/gcc-arm-embedded/4.9/4.9-2015-q2-update/+download/$GCC.tar.bz2 > $GCC.tar.bz2 

tar xvfz $GCC.tar.bz2
rm $GCC.tar.bz2

export PATH="`pwd`/$GCC_VERSION/bin:$PATH"
arm-none-eabi-gcc --version | head -1
````

## UnitTest
 * CppUTest 설치하기 - http://cpputest.github.io/
