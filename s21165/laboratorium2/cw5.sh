#! /bin/bash
input=${1?Error: no args}

firstletter=${input:0:1}
lastletter=${input: -1}
echo $firstletter
echo $lastletter
case "$input" in 
  *SOP*)
   echo -e \\e[32mSOP\\e[0m 
    ;;
esac

