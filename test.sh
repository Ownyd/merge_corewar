#!/bin/bash

red=$'\033[1;31m'
grn=$'\033[1;32m'
yel=$'\033[1;33m'
blu=$'\033[1;34m'
mag=$'\033[1;35m'
cyn=$'\033[1;36m'
end=$'\033[0m'

usage() {
   echo "usage: champion.cor folder"
   exit
}

loading_whell() {
	declare -a spin=("\r${yel}•${blu}∙∙${end}" "\r${blu}∙${yel}•${blu}∙${end}" "\r${blu}∙∙${yel}•${end}")
	i=0
	while [ 1 ]
	do
	  i=$(( (i+1) %4 ))
	  printf "${spin[$i]}"
	  sleep .5
	done
}

clean_exit() {
	echo -e "\r$win win / $nb_oponent oponent"
	kill $PID_LOADING_WHELL >/dev/null 2>&1
}

if [[ $# != 2 ]]; then
	usage
fi

make 2>&1 > /dev/null

win=0
nb_oponent=0

file_champ=$(echo "$1" | rev | cut -f1 -d"/" | rev)

last=`find . -regex ".*\.\(cor\)" -not -name "$file_champ" | tail -1`

find $2 -regex ".*\.\(cor\)" -not -name "$file_champ" | while read oponent; do
	file_oponent=`echo "$oponent" | rev | cut -f1 -d"/" | rev`

	loading_whell &
	PID_LOADING_WHELL=$!
	disown 

	res=`./corewar $1 $oponent 2>&1 | tail -1`
	kill $PID_LOADING_WHELL >/dev/null 2>&1

	if [[ "$res" = "le joueur"* ]]; then
		name=`echo $res | cut -f2 -d"(" | cut -f1 -d")"`
		num=`echo $res | cut -f1 -d"(" | cut -f3 -d" "`
		echo -e "\r$file_champ ${cyn}vs${end} $file_oponent:"

		if [[ "$num" = 1 ]]; then
			echo "${grn}You win !${end}"
			let win++
		else
			echo "${red}You lose !${end}"
		fi
		echo ""
		let nb_oponent++
	fi;
	export test="toto"

	if [[ $last = $oponent ]]; then
		echo "$win win / $nb_oponent oponent"
	fi
	trap 'clean_exit' EXIT
done
