GCC_VERSION="gcc-arm-none-eabi-4_9-2015q2"
export PATH="`pwd`/$GCC_VERSION/bin:$PATH"
arm-none-eabi-gcc --version | head -1
export PATH="`pwd`/lpc21isp:$PATH"
lpc21isp
