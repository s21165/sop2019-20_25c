#!/bin/bash
file=${1?Error: no input}
input="$PWD/$file"


while IFS= read -r line
do
if [  $line == "Witek"  ]; then
        echo -e \\e[31mWitek\\e[0m 
else
echo "$line"
fi

done < "$input"







