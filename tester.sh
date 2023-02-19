#!/bin/bash

VECTOR_FILES="./vector/srcs/*.cpp"
MAP_FILES="./map/srcs/*.cpp"

CC="c++"
CFLAGS="-std=c++98 -Wall -Wextra -Werror -g"
FT="-DNS=ft"

OK_TEXT="\e[92m[OK]\e[0m"
KO_TEXT="\e[91m[KO]\e[0m"
TO_TEXT="\e[91m[TO]\e[0m"
SEGV_TEXT="\e[91m[SEGV]\e[0m"


COLS_CURRENT_TEST=34
COLS_COMPILATION=13
COLS_EXIT_CODE=11
COLS_OUTPUT=8

COUNT_VECTOR=0
COUNT_MAX_VECTOR=$(ls ./vector/srcs/*.cpp | wc -l)

COUNT_MAP=0
COUNT_MAX_MAP=$(ls ./map/srcs/*.cpp | wc -l)

COMPILE="$CC $CFLAGS"

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

function out_std_vector {
	COUNT_VECTOR=$(( $COUNT_VECTOR + 1 ))
	BASE=$(basename $1)
	TEST_NAME=${BASE%.*}
	FT_BIN_NAME="ft_${TEST_NAME}"
	STD_BIN_NAME="std_${TEST_NAME}"

	echo -n "║"
	center_text $TEST_NAME $COLS_CURRENT_TEST


	$COMPILE $1 -o vector/bin/${STD_BIN_NAME} 2> /dev/null & std_pid=$!;
	$COMPILE $FT $1 -o vector/bin/${FT_BIN_NAME} 2> vector/errors/${TEST_NAME}_ft & ft_pid=$!;

	wait ${std_pid};
	wait ${ft_pid}; ft_exit_code=$?;
	if [ $ft_exit_code -eq 0 ]
	then 
		echo -en "    $OK_TEXT     ║"
		rm -rf vector/errors/${TEST_NAME}_ft
	else
		echo -e "    $KO_TEXT     ║   $KO_TEXT    ║  $KO_TEXT  ║"
	#	echo "╠══════════════════════════════════╬═════════════╬═══════════╬════════╣"
		return
	fi

	{ ./vector/bin/${STD_BIN_NAME} > vector/logs/${TEST_NAME}_std; } 2>> vector/errors/${TEST_NAME}_std & std_pid=$!;
	
	{ ./vector/bin/${FT_BIN_NAME} > vector/logs/${TEST_NAME}_ft; } 2>> vector/errors/${TEST_NAME}_ft & ft_pid=$!;

	wait ${ft_pid};	FT_EXIT_CODE=$?;

	wait ${std_pid}; STD_EXIT_CODE=$?;
	if [ $STD_EXIT_CODE -eq $FT_EXIT_CODE ]
	then
		echo -en "   $OK_TEXT    ║"
	elif [ $FT_EXIT_CODE -eq 139 ]
	then
		echo -en "  $SEGV_TEXT   ║"
	else
		echo -en "   $KO_TEXT    ║"
	fi
	diff vector/logs/${TEST_NAME}_std vector/logs/${TEST_NAME}_ft > vector/diffs/${TEST_NAME}.diff
	DIFF_EXIT_CODE=$?
	if [ $DIFF_EXIT_CODE -eq 0 ]
	then 
		echo -e "  $OK_TEXT  ║"
		rm -rf vector/diffs/${TEST_NAME}.diff
	else
		echo -e "  $KO_TEXT  ║"
	fi
	if [ $COUNT_VECTOR -eq $COUNT_MAX_VECTOR ]
	then
		echo "╚══════════════════════════════════╩═════════════╩═══════════╩════════╝"
	#else
		#echo "╠══════════════════════════════════╬═════════════╬═══════════╬════════╣"
	fi
}


function out_std_map {
	COUNT_MAP=$(( $COUNT_MAP + 1 ))
	BASE=$(basename $1)
	TEST_NAME=${BASE%.*}
	FT_BIN_NAME="ft_${TEST_NAME}"
	STD_BIN_NAME="std_${TEST_NAME}"

	echo -n "║"
	center_text $TEST_NAME $COLS_CURRENT_TEST


	$COMPILE $1 -o map/bin/${STD_BIN_NAME} 2> /dev/null & std_pid=$!;
	$COMPILE $FT $1 -o map/bin/${FT_BIN_NAME} 2> map/errors/${TEST_NAME}_ft & ft_pid=$!;

	wait ${std_pid};
	wait ${ft_pid}; ft_exit_code=$?;
	if [ $ft_exit_code -eq 0 ]
	then 
		echo -en "    $OK_TEXT     ║"
		rm -rf map/errors/${TEST_NAME}_ft
	else
		echo -e "    $KO_TEXT     ║   $KO_TEXT    ║  $KO_TEXT  ║"
		if [ $COUNT_MAP -eq $COUNT_MAX_MAP ]
		then
			echo "╚══════════════════════════════════╩═════════════╩═══════════╩════════╝"
		#else
			#echo "╠══════════════════════════════════╬═════════════╬═══════════╬════════╣"
		fi
		return
	fi

	{ timeout 5 ./map/bin/${STD_BIN_NAME} > map/logs/${TEST_NAME}_std; } 2> /dev/null & std_pid=$!;
	
	{ timeout 5 ./map/bin/${FT_BIN_NAME} > map/logs/${TEST_NAME}_ft; } 2>> map/errors/${TEST_NAME}_ft & ft_pid=$!;

	wait ${ft_pid};	FT_EXIT_CODE=$?;
	wait ${std_pid}; STD_EXIT_CODE=$?;

	if [ $STD_EXIT_CODE -eq $FT_EXIT_CODE ]
	then
		echo -en "   $OK_TEXT    ║"
	elif [ $FT_EXIT_CODE -eq 139 ]
	then
		echo -en "  $SEGV_TEXT   ║"
	elif [ $FT_EXIT_CODE -eq 124 ]
	then
		echo -en "   $TO_TEXT    ║"
	else
		echo -en "   $KO_TEXT    ║"
	fi
	diff map/logs/${TEST_NAME}_std map/logs/${TEST_NAME}_ft > map/diffs/${TEST_NAME}.diff
	DIFF_EXIT_CODE=$?
	if [ $DIFF_EXIT_CODE -eq 0 ]
	then 
		echo -e "  $OK_TEXT  ║"
		rm -rf map/diffs/${TEST_NAME}.diff
	else
		echo -e "  $KO_TEXT  ║"
	fi
	if [ $COUNT_MAP -eq $COUNT_MAX_MAP ]
	then
		echo "╚══════════════════════════════════╩═════════════╩═══════════╩════════╝"
	#else
		#echo "╠══════════════════════════════════╬═════════════╬═══════════╬════════╣"
	fi
}

function test_vector { 
#	./tester.sh clean "vector"
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
	if [ ! -d vector/bin ]
	then
		mkdir vector/bin
	fi
	echo "╔═════════════════════════════════════════════════════════════════════╗"
	echo "║                                VECTOR                               ║"
	echo "╠══════════════════════════════════╦═════════════╦═══════════╦════════╣"
	echo "║           Current test           ║ Compilation ║ Exit code ║ Output ║"
	echo "╠══════════════════════════════════╬═════════════╬═══════════╬════════╣"	

	for file in $VECTOR_FILES
	do
		out_std_vector $file
	done
	for file in vector/logs/*
	do
		if [ ! -s $file ]
		then
			rm -f $file
		fi
	done
	for file in vector/errors/*
	do
		if [ ! -s $file ]
		then
			rm -f $file
		fi
	done
	for file in vector/diffs/*
	do
		if [ ! -s $file ]
		then
			rm -f $file
		fi
	done
}

function test_map { 
#	./tester.sh clean "map"
	if [ ! -d map/logs ]
	then
		mkdir map/logs
	fi
	if [ ! -d map/diffs ]
	then
		mkdir map/diffs
	fi
	if [ ! -d map/errors ]
	then
		mkdir map/errors
	fi
	if [ ! -d map/bin ]
	then
		mkdir map/bin
	fi
	echo "╔═════════════════════════════════════════════════════════════════════╗"
	echo "║                                   MAP                               ║"
	echo "╠══════════════════════════════════╦═════════════╦═══════════╦════════╣"
	echo "║           Current test           ║ Compilation ║ Exit code ║ Output ║"
	echo "╠══════════════════════════════════╬═════════════╬═══════════╬════════╣"	

	for file in $MAP_FILES
	do
		out_std_map $file
	done
	for file in map/logs/*
	do
		if [ ! -s $file ]
		then
			rm -f $file
		fi
	done
	for file in map/errors/*
	do
		if [ ! -s $file ]
		then
			rm -f $file
		fi
	done
	for file in map/diffs/*
	do
		if [ ! -s $file ]
		then
			rm -f $file
		fi
	done
}

if [ "$1" == "clean" ]
then
	rm -rf ./$2/diffs
	rm -rf ./$2/logs
	rm -rf ./$2/errors
	rm -rf ./$2/bin
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
	if [ "$var" == "map" ]
	then
		test_map
	fi
done
