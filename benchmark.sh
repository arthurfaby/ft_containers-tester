#!/bin/bash

VECTOR_FILES="./vector/srcs/*.cpp"
MAP_FILES="./map/srcs/*.cpp"
STACK_FILES="./stack/srcs/*.cpp"

CC="c++"
CFLAGS="-std=c++98 -Wall -Wextra -Werror -DTEST_SIZE=1000"
FT="-DNS=ft"

OK_TEXT="\e[92m[OK]\e[0m"
KO_TEXT="\e[91m[K0]\e[0m"
SEGV_TEXT="\e[91m[SEGV]\e[0m"


COLS_CURRENT_TEST=34
COLS_SPEED=22
COLS_STL_TIME=18
COLS_FT_TIME=18

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
	echo -en "\e[0m"
	echo -n "║"
}

function out_std_vector {
	COUNT_VECTOR=$(( $COUNT_VECTOR + 1 ))
	BASE=$(basename $1)
	TEST_NAME=${BASE%.*}

	echo -n "║"
	center_text $TEST_NAME $COLS_CURRENT_TEST


	$COMPILE $1 2> /dev/null
	START_STD_SEC=`date +%s`
	START_STD_NSEC=`date +%N`
	./a.out > vector/logs/${TEST_NAME}_std 2> /dev/null
	STD_EXIT_CODE=$?
	END_STD_SEC=`date +%s`
	END_STD_NSEC=`date +%N`
	
	rm -rf a.out
	$COMPILE $FT $1 2> vector/errors/${TEST_NAME}_ft

	START_FT_SEC=`date +%s`
	START_FT_NSEC=`date +%N`
	{ ./a.out > vector/logs/${TEST_NAME}_ft; } 2>> vector/errors/${TEST_NAME}_ft
	FT_EXIT_CODE=$?
	END_FT_SEC=`date +%s`
	END_FT_NSEC=`date +%N`
	rm -rf a.out


	TOTAL_DIFF_STD=$( echo "($END_STD_SEC - $START_STD_SEC) * 1000 + ($END_STD_NSEC - $START_STD_NSEC) / 1000000"  | bc )
	TOTAL_DIFF_FT=$( echo "($END_FT_SEC - $START_FT_SEC) * 1000 + ($END_FT_NSEC - $START_FT_NSEC) / 1000000"  | bc )

	
	RATIO=$(echo "scale=1; $TOTAL_DIFF_FT / $TOTAL_DIFF_STD" | bc)


	echo -en "\e[93m"
	center_text "${TOTAL_DIFF_STD}ms" $COLS_STL_TIME
	echo -en "\e[93m"
	center_text "${TOTAL_DIFF_FT}ms" $COLS_FT_TIME


	GREATER=$(echo "$RATIO > 20.0" | bc)
	if [ $GREATER -eq 1 ]
	then
		echo -en "\e[91m"
		tmp_string="x$RATIO"
		center_text $tmp_string $COLS_SPEED
		echo -en "\e[0m"
		echo
	else
		echo -en "\e[92m"
		tmp_string="x"
		if [ $(echo "$RATIO < 1.0" | bc) -eq 1 ]
		then
			if [ $(echo "$RATIO != 0" | bc) -eq 1 ]
			then
				tmp_string+="0"
			fi
		fi
		tmp_string+="$RATIO"
		center_text $tmp_string $COLS_SPEED
		echo -en "\e[0m"
		echo
	fi
	if [ $COUNT_VECTOR -eq $COUNT_MAX_VECTOR ]
	then
		echo "╚══════════════════════════════════╩══════════════════╩══════════════════╩══════════════════════╝"	
#	else
#		echo "╠══════════════════════════════════╬══════════════════════════════════════════╣"
	fi
}

function out_std_map {
	COUNT_MAP=$(( $COUNT_MAP + 1 ))
	BASE=$(basename $1)
	TEST_NAME=${BASE%.*}

	echo -n "║"
	center_text $TEST_NAME $COLS_CURRENT_TEST


	$COMPILE $1 2> /dev/null
	START_STD_SEC=`date +%s`
	START_STD_NSEC=`date +%N`
	./a.out > map/logs/${TEST_NAME}_std 2> /dev/null
	STD_EXIT_CODE=$?
	END_STD_SEC=`date +%s`
	END_STD_NSEC=`date +%N`
	
	rm -rf a.out
	$COMPILE $FT $1 2> map/errors/${TEST_NAME}_ft

	START_FT_SEC=`date +%s`
	START_FT_NSEC=`date +%N`
	{ ./a.out > map/logs/${TEST_NAME}_ft; } 2>> map/errors/${TEST_NAME}_ft
	FT_EXIT_CODE=$?
	END_FT_SEC=`date +%s`
	END_FT_NSEC=`date +%N`
	rm -rf a.out


	TOTAL_DIFF_STD=$( echo "($END_STD_SEC - $START_STD_SEC) * 1000 + ($END_STD_NSEC - $START_STD_NSEC) / 1000000"  | bc )
	TOTAL_DIFF_FT=$( echo "($END_FT_SEC - $START_FT_SEC) * 1000 + ($END_FT_NSEC - $START_FT_NSEC) / 1000000"  | bc )

	
	RATIO=$(echo "scale=1; $TOTAL_DIFF_FT / $TOTAL_DIFF_STD" | bc)

	echo -en "\e[93m"
	center_text "${TOTAL_DIFF_STD}ms" $COLS_STL_TIME
	echo -en "\e[93m"
	center_text "${TOTAL_DIFF_FT}ms" $COLS_FT_TIME

	GREATER=$(echo "$RATIO > 20.0" | bc)
	if [ $GREATER -eq 1 ]
	then
		echo -en "\e[91m"
		tmp_string="x$RATIO"
		center_text $tmp_string $COLS_SPEED
		echo -en "\e[0m"
		echo
	else
		echo -en "\e[92m"
		tmp_string="x"
		if [ $(echo "$RATIO < 1.0" | bc) -eq 1 ]
		then
			if [ $(echo "$RATIO != 0" | bc) -eq 1 ]
			then
				tmp_string+="0"
			fi
		fi
		tmp_string+="$RATIO"
		center_text $tmp_string $COLS_SPEED
		echo -en "\e[0m"
		echo
	fi
	if [ $COUNT_MAP -eq $COUNT_MAX_MAP ]
	then
		echo "╚══════════════════════════════════╩══════════════════╩══════════════════╩══════════════════════╝"	
#	else
#		echo "╠══════════════════════════════════╬══════════════════════════════════════════╣"
	fi
}

function out_std_stack {
	COUNT_STACK=$(( $COUNT_STACK + 1 ))
	BASE=$(basename $1)
	TEST_NAME=${BASE%.*}

	echo -n "║"
	center_text $TEST_NAME $COLS_CURRENT_TEST


	$COMPILE $1 2> /dev/null
	START_STD_SEC=`date +%s`
	START_STD_NSEC=`date +%N`
	./a.out > stack/logs/${TEST_NAME}_std 2> /dev/null
	STD_EXIT_CODE=$?
	END_STD_SEC=`date +%s`
	END_STD_NSEC=`date +%N`
	
	rm -rf a.out
	$COMPILE $FT $1 2> stack/errors/${TEST_NAME}_ft

	START_FT_SEC=`date +%s`
	START_FT_NSEC=`date +%N`
	{ ./a.out > stack/logs/${TEST_NAME}_ft; } 2>> stack/errors/${TEST_NAME}_ft
	FT_EXIT_CODE=$?
	END_FT_SEC=`date +%s`
	END_FT_NSEC=`date +%N`
	rm -rf a.out


	TOTAL_DIFF_STD=$( echo "($END_STD_SEC - $START_STD_SEC) * 1000 + ($END_STD_NSEC - $START_STD_NSEC) / 1000000"  | bc )
	TOTAL_DIFF_FT=$( echo "($END_FT_SEC - $START_FT_SEC) * 1000 + ($END_FT_NSEC - $START_FT_NSEC) / 1000000"  | bc )

	
	RATIO=$(echo "scale=1; $TOTAL_DIFF_FT / $TOTAL_DIFF_STD" | bc)

	echo -en "\e[93m"
	center_text "${TOTAL_DIFF_STD}ms" $COLS_STL_TIME
	echo -en "\e[93m"
	center_text "${TOTAL_DIFF_FT}ms" $COLS_FT_TIME

	GREATER=$(echo "$RATIO > 20.0" | bc)
	if [ $GREATER -eq 1 ]
	then
		echo -en "\e[91m"
		tmp_string="x$RATIO"
		center_text $tmp_string $COLS_SPEED
		echo -en "\e[0m"
		echo
	else
		echo -en "\e[92m"
		tmp_string="x"
		if [ $(echo "$RATIO < 1.0" | bc) -eq 1 ]
		then
			if [ $(echo "$RATIO != 0" | bc) -eq 1 ]
			then
				tmp_string+="0"
			fi
		fi
		tmp_string+="$RATIO"
		center_text $tmp_string $COLS_SPEED
		echo -en "\e[0m"
		echo
	fi
	if [ $COUNT_STACK -eq $COUNT_MAX_STACK ]
	then
		echo "╚══════════════════════════════════╩══════════════════╩══════════════════╩══════════════════════╝"	
#	else
#		echo "╠══════════════════════════════════╬══════════════════════════════════════════╣"
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
	echo "╔═══════════════════════════════════════════════════════════════════════════════════════════════╗"
	echo "║                                            VECTOR                                             ║"
	echo "╠══════════════════════════════════╦══════════════════╦══════════════════╦══════════════════════╣"
	echo "║           Current test           ║     STL time     ║     FT time      ║         Ratio        ║"
	echo "╠══════════════════════════════════╬══════════════════╬══════════════════╬══════════════════════╣"
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
	echo "╔═══════════════════════════════════════════════════════════════════════════════════════════════╗"
	echo "║                                               MAP                                             ║"
	echo "╠══════════════════════════════════╦══════════════════╦══════════════════╦══════════════════════╣"
	echo "║           Current test           ║     STL time     ║     FT time      ║         Ratio        ║"
	echo "╠══════════════════════════════════╬══════════════════╬══════════════════╬══════════════════════╣"


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
	echo "╔═══════════════════════════════════════════════════════════════════════════════════════════════╗"
	echo "║                                              STACK                                            ║"
	echo "╠══════════════════════════════════╦══════════════════╦══════════════════╦══════════════════════╣"
	echo "║           Current test           ║     STL time     ║     FT time      ║         Ratio        ║"
	echo "╠══════════════════════════════════╬══════════════════╬══════════════════╬══════════════════════╣"

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
