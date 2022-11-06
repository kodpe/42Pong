#!/bin/bash
SRC_VAR="SRC"
SRC_DIR="src"
#
FILES=$(find $SRC_DIR -name "*.c" | sed -e 's/.c$//' | sed -e 's/$/ \\/' | sed -e "s/^$SRC_DIR\//\t/")
KEY="auto-sources"
ID=$(date +%S%H%M%d%m%y)
REF=$(cat -n Makefile | grep "\-$KEY\-" | awk '{print $1}')
if [[ ! $(echo $REF | wc -w) -eq 2 ]]; then
	echo "makefile error: unfound invalid token '#-$KEY-'"
	exit
fi
TOP=$(cat Makefile | head -$(($(echo $REF | awk '{print $1}') - 1)))
BOT=$(cat Makefile | tail +$(($(echo $REF | awk '{print $2}') + 1)))
echo "$TOP" >Makefile
echo "#-$KEY-##############$ID#" >>Makefile
echo "$SRC_VAR = \$(addsuffix .c, \\" >>Makefile
echo "$FILES" >>Makefile
echo -e '\t)' >>Makefile
echo "#-$KEY-##############$ID#" >>Makefile
echo "$BOT" >>Makefile
