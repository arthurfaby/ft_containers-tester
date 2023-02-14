#!/bin/bash

VECTOR_FILES="./vector/srcs/*.cpp"
#VECTOR_FILES="./vector/srcs/assign.cpp"

CC="c++"
CFLAGS="-std=c++98 -Wall -Wextra -Werror"
FT="-DNS=ft"

OK_TEXT="\e[92m[OK]\e[0m"
KO_TEXT="\e[91m[K0]\e[0m"

COLS_CURRENT_TEST=24
COLS_COMPILATION=13
COLS_EXIT_CODE=11
COLS_OUTPUT=8
COLS_SPEED=7

function print_header {
	echo "# **************************************************************************** #"
	echo "#                                                                              #"
	echo "#                                                         :::      ::::::::    #"
	echo "#                                                       :+:      :+:    :+:    #"
	echo "#    ft_containers tester                             +:+ +:+         +:+      #"
	echo "#                                                   +#+  +:+       +#+         #"
	echo "#                                                 +#+#+#+#+#+   +#+            #"
	echo "#    By: afaby <afaby@student.42angouleme.fr>          #+#    #+#              #"
	echo "#                                                     ###   ########.fr        #"
	echo "#                                                                              #"
	echo "# **************************************************************************** #"
	echo
}

function center_text {
	LEN=${#1}
	printf "%*s" $[$2/2+$LEN/2] "$1"
	printf "%*s" $[$2/2-$LEN/2] ""
	echo -n "║"
}

function out_std {
	BASE=$(basename $1)
	TEST_NAME=${BASE%.*}

	echo -n "║"
	center_text $TEST_NAME $COLS_CURRENT_TEST


	$COMPILE $1 2> /dev/null
	START_STD_SEC=`date +%s`
	START_STD_NSEC=`date +%N`
	./a.out > vector/logs/${TEST_NAME}_std 2> /dev/null
	END_STD_SEC=`date +%s`
	END_STD_NSEC=`date +%N`
	
	STD_EXIT_CODE=$?
	rm -rf a.out
	$COMPILE $FT $1 2> vector/errors/${TEST_NAME}_ft
	if [ $? -eq 0 ]
	then 
		echo -en "    $OK_TEXT     ║"
		rm -rf vector/errors/${TEST_NAME}_ft
	else
		echo -e "    $KO_TEXT     ║   $KO_TEXT    ║  $KO_TEXT  ║  $KO_TEXT  ║"
		echo "╠════════════════════════╬═════════════╬═══════════╬════════╬════════╣"
		return
	fi
	START_FT_SEC=`date +%s`
	START_FT_NSEC=`date +%N`
	./a.out > vector/logs/${TEST_NAME}_ft 2> /dev/null
	END_FT_SEC=`date +%s`
	END_FT_NSEC=`date +%N`
	FT_EXIT_CODE=$?
	rm -rf a.out
	if [ $STD_EXIT_CODE -eq $FT_EXIT_CODE ]
	then
		echo -en "   $OK_TEXT    ║"
	else
		echo -en "   $KO_TEXT    ║"
	fi
	diff vector/logs/${TEST_NAME}_std vector/logs/${TEST_NAME}_ft > vector/diffs/${TEST_NAME}.diff
	DIFF_EXIT_CODE=$?
	if [ $DIFF_EXIT_CODE -eq 0 ]
	then 
		echo -en "  $OK_TEXT  ║"
	else
		echo -en "  $KO_TEXT  ║"
	fi

	TOTAL_DIFF_STD=$( echo "($END_STD_SEC - $START_STD_SEC) * 1000000 + ($END_STD_NSEC - $START_STD_NSEC) / 1000"  | bc )
	TOTAL_DIFF_FT=$( echo "($END_FT_SEC - $START_FT_SEC) * 1000000 + ($END_FT_NSEC - $START_FT_NSEC) / 1000"  | bc )

	
	RATIO=$(echo "scale=1; $TOTAL_DIFF_STD / $TOTAL_DIFF_FT" | bc)

	GREATER=$(echo "$RATIO > 20.0" | bc)
	if [ $GREATER -eq 1 ]
	then
		echo -en "\e[91m"
		echo -en "  x$RATIO"
		echo -en "\e[0m"
		echo
	else
		echo -en "\e[92m"
		echo -en "  x"
		if [ $(echo "$RATIO < 1.0" | bc) -eq 1 ]
		then
			echo -en "0"
		fi
		echo -en "$RATIO"
		echo -en "\e[0m"
		echo
	fi
	echo "╠════════════════════════╬═════════════╬═══════════╬════════╬════════╣"
}

COMPILE="$CC $CFLAGS"

function test_vector { 
	./tester.sh clean
	if [ ! -d vector/logs ]
	then
		mkdir vector/logs
	fi
	if [ ! -d vector/diffs ]
	then
		mkdir vector/diffs
	fi
	if [ ! -d vector/errors ]
	then
		mkdir vector/errors
	fi
	echo "╔════════════════════════════════════════════════════════════════════╗"
	echo "║                                VECTOR                              ║"
	echo "╠════════════════════════╦═════════════╦═══════════╦════════╦════════╣"
	echo "║      Current test      ║ Compilation ║ Exit code ║ Output ║  Time  ║"
	echo "╠════════════════════════╬═════════════╬═══════════╬════════╬════════╣"
	
	for file in $VECTOR_FILES
	do
		out_std $file
	done
}

if [ "$1" == "clean" ]
then
	rm -rf ./vector/diffs
	rm -rf ./vector/logs
	rm -rf ./vector/errors
	exit
fi

if [ $# -eq 0 ]
then
	exit 1
fi

print_header

for var in "$@"
do
	if [ "$var" == "vector" ]
	then
		test_vector
	fi
done
