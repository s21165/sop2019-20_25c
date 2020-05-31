#!/bin/bash

string=${1?Error: no input}






if [[ $string =~ "@" ]] 
then
   echo "mail"

elif  [[ $string =~ "-" ]]
 then echo "kod pocztowy"




elif [[ "$string" == [A-Z]* ]]
 then echo "Imie"

else
echo "nie jest mailem, kodem pocztowym ani imieniem"
fi

	






     











