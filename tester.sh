#!/bin/bash

VECTOR_FILES="./vector/srcs/*.cpp"
MAP_FILES="./map/srcs/*.cpp"
STACK_FILES="./stack/srcs/*.cpp"

CC="c++"
CFLAGS="-std=c++98 -Wall -Wextra -Werror -g"
FT="-DNS=ft"

OK_TEXT="\e[92m[OK]\e[0m"
KO_TEXT="\e[91m[KO]\e[0m"
TO_TEXT="\e[91m[TO]\e[0m"
SEGV_TEXT="\e[91m[SEGV]\e[0m"
LEAKS_TEXT="\e[91m[LEAKS]\e[0m"
INVRW_TEXT="\e[91m[INVRW]\e[0m"
CONDJ_TEXT="\e[91m[CONDJ]\e[0m"


COLS_CURRENT_TEST=34
COLS_COMPILATION=13
COLS_EXIT_CODE=11
COLS_OUTPUT=8

COUNT_VECTOR=0
COUNT_MAX_VECTOR=$(ls ./vector/srcs/*.cpp | wc -l)

COUNT_MAP=0
COUNT_MAX_MAP=$(ls ./map/srcs/*.cpp | wc -l)

COUNT_STACK=0
COUNT_MAX_STACK=$(ls ./stack/srcs/*.cpp | wc -l)

COMPILE="$CC $CFLAGS"

function print_header {
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
		echo -e "    $KO_TEXT     ║   $KO_TEXT    ║  $KO_TEXT  ║    $KO_TEXT    ║"
		if [ $COUNT_MAP -eq $COUNT_MAX_MAP ]
		then
			echo "╚══════════════════════════════════╩═════════════╩═══════════╩════════╩════════════╝"
		fi
		return
	fi

	{ ./vector/bin/${STD_BIN_NAME} > vector/logs/${TEST_NAME}_std; } 2>> vector/errors/${TEST_NAME}_std & std_pid=$!;
	
	{ valgrind --log-file=./vector/leaks/ft_${TEST_NAME} ./vector/bin/${FT_BIN_NAME} > vector/logs/${TEST_NAME}_ft; } 2>> vector/errors/${TEST_NAME}_ft & ft_pid=$!;

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
		rm -rf vector/errors/${TEST_NAME}_ft
	fi
	diff vector/logs/${TEST_NAME}_std vector/logs/${TEST_NAME}_ft > vector/diffs/${TEST_NAME}.diff
	DIFF_EXIT_CODE=$?
	if [ $DIFF_EXIT_CODE -eq 0 ]
	then 
		echo -en "  $OK_TEXT  ║"
		rm -rf vector/diffs/${TEST_NAME}.diff
	else
		echo -en "  $KO_TEXT  ║"
	fi
	LEAKS=$(cat ./vector/leaks/ft_${TEST_NAME} | grep LEAK | wc -l)
	INVRW=$(cat ./vector/leaks/ft_${TEST_NAME} | grep Invalid | wc -l)
	CONDJ=$(cat ./vector/leaks/ft_${TEST_NAME} | grep Conditional | wc -l)
	if [ $LEAKS -ne 0 ] 
	then
		echo -e "   $LEAKS_TEXT  ║"
	elif [ $INVRW -ne 0 ]
	then
		echo -e "   $INVRW_TEXT  ║"
	elif [ $CONDJ -ne 0 ]
	then
		echo -e "   $CONDJ_TEXT  ║"
	else
		echo -e "    $OK_TEXT    ║"
		rm -rf vector/leaks/ft_${TEST_NAME}
	fi
	if [ $COUNT_VECTOR -eq $COUNT_MAX_VECTOR ]
	then
		echo "╚══════════════════════════════════╩═════════════╩═══════════╩════════╩════════════╝"
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
		echo -e "    $KO_TEXT     ║   $KO_TEXT    ║  $KO_TEXT  ║    $KO_TEXT    ║"
		if [ $COUNT_MAP -eq $COUNT_MAX_MAP ]
		then
			echo "╚══════════════════════════════════╩═════════════╩═══════════╩════════╩════════════╝"
		fi
		return
	fi

	{ ./map/bin/${STD_BIN_NAME} > map/logs/${TEST_NAME}_std; } 2> /dev/null & std_pid=$!;
	
	{ valgrind --log-file=./map/leaks/ft_${TEST_NAME} ./map/bin/${FT_BIN_NAME} > map/logs/${TEST_NAME}_ft; } 2>> map/errors/${TEST_NAME}_ft & ft_pid=$!;

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
		rm -rf map/errors/${TEST_NAME}_ft
	fi
	diff map/logs/${TEST_NAME}_std map/logs/${TEST_NAME}_ft > map/diffs/${TEST_NAME}.diff
	DIFF_EXIT_CODE=$?
	if [ $DIFF_EXIT_CODE -eq 0 ]
	then 
		echo -en "  $OK_TEXT  ║"
		rm -rf map/diffs/${TEST_NAME}.diff
	else
		echo -en "  $KO_TEXT  ║"
	fi
	LEAKS=$(cat ./map/leaks/ft_${TEST_NAME} | grep LEAK | wc -l)
	INVRW=$(cat ./map/leaks/ft_${TEST_NAME} | grep Invalid | wc -l)
	CONDJ=$(cat ./map/leaks/ft_${TEST_NAME} | grep Conditional | wc -l)
	if [ $LEAKS -ne 0 ] 
	then
		echo -e "   $LEAKS_TEXT  ║"
	elif [ $INVRW -ne 0 ]
	then
		echo -e "   $INVRW_TEXT  ║"
	elif [ $CONDJ -ne 0 ]
	then
		echo -e "   $CONDJ_TEXT  ║"
	else
		echo -e "    $OK_TEXT    ║"
		rm -rf map/leaks/ft_${TEST_NAME}
	fi
	if [ $COUNT_MAP -eq $COUNT_MAX_MAP ]
	then
		echo "╚══════════════════════════════════╩═════════════╩═══════════╩════════╩════════════╝"
	fi
}

function out_std_stack {
	COUNT_STACK=$(( $COUNT_STACK + 1 ))
	BASE=$(basename $1)
	TEST_NAME=${BASE%.*}
	FT_BIN_NAME="ft_${TEST_NAME}"
	STD_BIN_NAME="std_${TEST_NAME}"

	echo -n "║"
	center_text $TEST_NAME $COLS_CURRENT_TEST


	$COMPILE $1 -o stack/bin/${STD_BIN_NAME} 2> /dev/null & std_pid=$!;
	$COMPILE $FT $1 -o stack/bin/${FT_BIN_NAME} 2> stack/errors/${TEST_NAME}_ft & ft_pid=$!;

	wait ${std_pid};
	wait ${ft_pid}; ft_exit_code=$?;
	if [ $ft_exit_code -eq 0 ]
	then 
		echo -en "    $OK_TEXT     ║"
		rm -rf stack/errors/${TEST_NAME}_ft
	else
		echo -e "    $KO_TEXT     ║   $KO_TEXT    ║  $KO_TEXT  ║    $KO_TEXT    ║"
		if [ $COUNT_STACK -eq $COUNT_MAX_STACK ]
		then
			echo "╚══════════════════════════════════╩═════════════╩═══════════╩════════╩════════════╝"
		fi
		return
	fi

	{ ./stack/bin/${STD_BIN_NAME} > stack/logs/${TEST_NAME}_std; } 2> /dev/null & std_pid=$!;
	
	{ valgrind --log-file=./stack/leaks/ft_${TEST_NAME} ./stack/bin/${FT_BIN_NAME} > stack/logs/${TEST_NAME}_ft; } 2>> stack/errors/${TEST_NAME}_ft & ft_pid=$!;

	wait ${ft_pid};	FT_EXIT_CODE=$?;
	wait ${std_pid}; STD_EXIT_CODE=$?;

	if [ $STD_EXIT_CODE -eq $FT_EXIT_CODE ]
	then
		echo -en "   $OK_TEXT    ║"
		rm -rf stack/errors/${TEST_NAME}_ft
	elif [ $FT_EXIT_CODE -eq 139 ]
	then
		echo -en "  $SEGV_TEXT   ║"
	elif [ $FT_EXIT_CODE -eq 124 ]
	then
		echo -en "   $TO_TEXT    ║"
	else
		echo -en "   $KO_TEXT    ║"
	fi
	diff stack/logs/${TEST_NAME}_std stack/logs/${TEST_NAME}_ft > stack/diffs/${TEST_NAME}.diff
	DIFF_EXIT_CODE=$?
	if [ $DIFF_EXIT_CODE -eq 0 ]
	then 
		echo -en "  $OK_TEXT  ║"
		rm -rf stack/diffs/${TEST_NAME}.diff
	else
		echo -en "  $KO_TEXT  ║"
	fi
	LEAKS=$(cat ./stack/leaks/ft_${TEST_NAME} | grep LEAK | wc -l)
	INVRW=$(cat ./stack/leaks/ft_${TEST_NAME} | grep Invalid | wc -l)
	CONDJ=$(cat ./stack/leaks/ft_${TEST_NAME} | grep Conditional | wc -l)
	if [ $LEAKS -ne 0 ] 
	then
		echo -e "   $LEAKS_TEXT  ║"
	elif [ $INVRW -ne 0 ]
	then
		echo -e "   $INVRW_TEXT  ║"
	elif [ $CONDJ -ne 0 ]
	then
		echo -e "   $CONDJ_TEXT  ║"
	else
		echo -e "    $OK_TEXT    ║"
		rm -rf stack/leaks/ft_${TEST_NAME}
	fi	
	if [ $COUNT_STACK -eq $COUNT_MAX_STACK ]
	then
		echo "╚══════════════════════════════════╩═════════════╩═══════════╩════════╩════════════╝"
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
	if [ ! -d vector/leaks ]
	then
		mkdir vector/leaks
	fi
	echo "╔══════════════════════════════════════════════════════════════════════════════════╗"
	echo "║                                        VECTOR                                    ║"
	echo "╠══════════════════════════════════╦═════════════╦═══════════╦════════╦════════════╣"
	echo "║           Current test           ║ Compilation ║ Exit code ║ Output ║  Valgrind  ║"
	echo "╠══════════════════════════════════╬═════════════╬═══════════╬════════╬════════════╣"	

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
	if [ ! -d map/leaks ]
	then
		mkdir map/leaks
	fi
	echo "╔══════════════════════════════════════════════════════════════════════════════════╗"
	echo "║                                          MAP                                     ║"
	echo "╠══════════════════════════════════╦═════════════╦═══════════╦════════╦════════════╣"
	echo "║           Current test           ║ Compilation ║ Exit code ║ Output ║  Valgrind  ║"
	echo "╠══════════════════════════════════╬═════════════╬═══════════╬════════╬════════════╣"	


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

function test_stack { 
#	./tester.sh clean "stack"
	if [ ! -d stack/logs ]
	then
		mkdir stack/logs
	fi
	if [ ! -d stack/diffs ]
	then
		mkdir stack/diffs
	fi
	if [ ! -d stack/errors ]
	then
		mkdir stack/errors
	fi
	if [ ! -d stack/bin ]
	then
		mkdir stack/bin
	fi
	if [ ! -d stack/leaks ]
	then
		mkdir stack/leaks
	fi
	echo "╔══════════════════════════════════════════════════════════════════════════════════╗"
	echo "║                                         STACK                                    ║"
	echo "╠══════════════════════════════════╦═════════════╦═══════════╦════════╦════════════╣"
	echo "║           Current test           ║ Compilation ║ Exit code ║ Output ║  Valgrind  ║"
	echo "╠══════════════════════════════════╬═════════════╬═══════════╬════════╬════════════╣"	
	for file in $STACK_FILES
	do
		out_std_stack $file
	done
	for file in stack/logs/*
	do
		if [ ! -s $file ]
		then
			rm -f $file
		fi
	done
	for file in stack/errors/*
	do
		if [ ! -s $file ]
		then
			rm -f $file
		fi
	done
	for file in stack/diffs/*
	do
		if [ ! -s $file ]
		then
			rm -f $file
		fi
	done
}


if [ "$1" == "clean" ]
then
	rm -rf ./map/diffs/
	rm -rf ./map/logs/
	rm -rf ./map/errors/
	rm -rf ./map/bin/
	rm -rf ./map/leaks/
	rm -rf ./vector/diffs/
	rm -rf ./vector/logs/
	rm -rf ./vector/errors/
	rm -rf ./vector/bin/
	rm -rf ./vector/leaks/
	rm -rf ./stack/diffs/
	rm -rf ./stack/logs/
	rm -rf ./stack/errors/
	rm -rf ./stack/bin/
	rm -rf ./stack/leaks/
	exit
fi

if [ $# -eq 0 ]
then
	test_stack
	test_vector
	test_map
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
	if [ "$var" == "stack" ]
	then
		test_stack
	fi
done
