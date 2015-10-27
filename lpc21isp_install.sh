curl -L https://github.com/capiman/lpc21isp/archive/master.zip > lpc21isp.zip
unzip lpc21isp.zip
cd lpc21isp-master
make
chmod +x lpc21isp
export PATH="`pwd`:$PATH"
cd ..
rm lpc21isp.zip
