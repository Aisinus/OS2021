echo Aisen > _ex3.txt
chmod ugo-x _ex3.txt
ls -l _ex3.txt >> ex3.txt
chmod uo=rwx _ex3.txt
ls -l _ex3.txt >> ex3.txt
chmod g=u _ex3.txt
ls -l _ex3.txt >> ex3.txt
echo 660 User and Group can read and write, no other permissions granted >> ex3.txt
echo 777 All user and group have full permissions - write, read, execute >> ex3.txt
echo 775 Everyone has all permissions, except other cannot write >> ex3.txt
