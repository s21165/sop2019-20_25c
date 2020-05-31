#! /bin/bash

NAME=${1?Error: no name given}
if [ "${NAME: -1}" = "a" ]
then
echo $NAME "ma kota, a kot ma": ${NAME/%a/ę}
else
echo $NAME "ma kota, a kot ma": "${NAME}a"
fi



