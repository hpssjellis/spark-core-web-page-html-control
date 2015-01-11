
REM dir/x gives the short file names.
REM you need to get these paths correct to nodejs, ARM, spark-cli, dfu files

set PATH=C:\Windows;C:\Windows\System32;c:\progra~1\nodejs;c:

\progra~1\GNUTOO~1\4947E~1.920\bin;H:\AEE653~1\cp12\spark\dfu;H:

\APPLIC~1\npm



echo "*************************************" >>myoutput.txt 2>&1

echo "spark flash --usb cc3000 " >>myoutput.txt 2>&1

echo "*************************************" >>myoutput.txt 2>&1

spark flash --usb cc3000    >>myoutput.txt 2>&1

echo "*************************************" >>myoutput.txt 2>&1


REM makes an output file called myoutput. Delete the file to start again.
