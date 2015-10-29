if [[ "$(expr substr $(uname -s) 1 9)" == "CYGWIN_NT" ]]; then
  curl -L https://github.com/Ladvien/LPC21ISP_Win/archive/master.zip > lpc21isp.zip
  unzip lpc21isp.zip
  cd LPC21ISP_WIN-master
  chmod +x lpc21isp.exe
else 
  curl -L https://github.com/capiman/lpc21isp/archive/master.zip > lpc21isp.zip
  unzip lpc21isp.zip
  cd lpc21isp-master
  make
  chmod +x lpc21isp
fi

export PATH="`pwd`:$PATH"
cd ..
rm lpc21isp.zip
