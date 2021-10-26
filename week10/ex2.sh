echo Aisen > ~/OS2021/week01/file.txt
link ~/OS2021/week01/file.txt _ex2.txt
var="$(stat -c '%i' ~/OS2021/week01/file.txt)"
find ~/OS2021/week10/ -inum $var > ex2.txt
find ~/OS2021/week10/ -inum $var -exec rm {} \; >> ex2.txt
