
# CPPUTest (host x86): Install Development Environment
 - Windows(cygwin), Linux, Mac OSX
 - Check this page https://subak-io.gitbooks.io/shenzhenboard-unittest/content/cpputest.html
 
참고:

 - CppUTest 설치하기 - http://cpputest.github.io/


# ARM GCC Install (target board)

## lpc21isp 

Firmware uploader using ftdi232

```
sudo brew install lpc21isp
apt-get install lpc21ips

```

## ARM GCC installation.

```
cat > arm_gcc_install.sh 

if [[ "$(uname)" == "Darwin" ]]; then
OS="mac"
elif [[ "$(expr substr $(uname -s) 1 5)" == "Linux" ]]; then
OS="linux"
elif [[ "$(expr substr $(uname -s) 1 10)" == "MINGW32_NT" ]]; then
    # Do something under Windows NT platform
fi

GCC_VERSION="gcc-arm-none-eabi-4_9-2015q2"
GCC_OS="-20150609-$OS"
GCC="$GCC_VERSION$GCC_OS"

curl -L https://launchpad.net/gcc-arm-embedded/4.9/4.9-2015-q2-update/+download/$GCC.tar.bz2 > $GCC.tar.bz2

tar xvfz $GCC.tar.bz2
rm $GCC.tar.bz2

export PATH="`pwd`/$GCC_VERSION/bin:$PATH"
arm-none-eabi-gcc --version | head -1
````

### Install and set path
```
source arm_gcc_install.sh
```
