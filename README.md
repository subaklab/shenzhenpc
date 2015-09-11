# Develop Envicronment On Mac OSX

## lpc21isp 

Firmware uploader using ftdi232

```
sudo brew install lpc21isp
```

## gcc 

```
#!/bin/sh

GCC=gcc-arm-none-eabi-4_9-2015q2-20150609-mac
wget https://launchpad.net/gcc-arm-embedded/4.9/4.9-2015-q2-update/+download/$GCC.tar.bz2
tar xvfz $GCC.tar.bz2

export PATH=$PATH:`pwd`/$GCC/bin
rm $GCC.tar.bz2
````
