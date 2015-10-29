if [[ "$(expr substr $(uname -s) 1 9)" == "CYGWIN_NT" ]]; then
  curl -L https://github.com/Ladvien/LPC21ISP_Win/archive/master.zip > lpc21isp.zip
  unzip lpc21isp.zip 
  mv LPC21ISP_WIN-master lpc21isp
  cd lpc21isp
  chmod +x lpc21isp.exe
else 
  curl -L https://github.com/capiman/lpc21isp/archive/master.zip > lpc21isp.zip
  unzip lpc21isp.zip 
  mv lpc21isp-master lpc21isp
  cd lpc21isp
  make
  chmod +x lpc21isp
fi

export PATH="`pwd`:$PATH"
cd ..
rm lpc21isp.zip
