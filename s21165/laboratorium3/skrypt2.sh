#!/bin/bash
#fibonacci sequence function
fib()
{
ind=$1

if (( ind <= 1 ))
 then echo 0
 return 0
elif (( ind == 2 ))
 then echo 1
return 1

else
  echo $(( $(fib $((ind - 1)) ) + $(fib $((ind - 2)) ) )) 
fi
 }

if(("$1" < 14))
then
echo fibbonacci sequence number $1 is $(fib $1)

else echo "to big"
fi
