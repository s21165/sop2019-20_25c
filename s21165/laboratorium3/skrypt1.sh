#!/bin/bash
tekst="$1"
color="$2"

# User-defined function
colorfull(){
        # $f is local variable
	local f="$1"
	local f2="$2"





case $2 in
	"red") echo -e \\e[31m$f\\e[0m  ;;
	"green") echo -e \\e[32m$f\\e[0m  ;;
	"brown") echo -e \\e[33m$f\\e[0m  ;;
	"blue") echo -e \\e[34m$f\\e[0m  ;;
	"purple") echo -e \\e[35m$f\\e[0m  ;;
	"cyan") echo -e \\e[36m$f\\e[0m  ;;
	"gray") echo -e \\e[37m$f\\e[0m  ;;

  
  *) echo "not defined color"
esac

     
}


colorfull "$tekst" "$color"







