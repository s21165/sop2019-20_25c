#!/bin/bash
#fibonacci sequence function
fib()
{
ind=$1
local f="$1"

if (( ind <= 1 ))
 then echo 0

elif (( ind == 2 ))
 then echo 1


else
  echo $(( $(fib $((ind - 1)) ) + $(fib $((ind - 2)) ) )) 

fi


 }




my_function () {


  f=`echo $(fib $1)`
  return $f
}






if(("$1" < 14|| ))
then

my_function
echo fibbonacci sequence number $1 is $(fib $1)

else echo "to big"
fi



