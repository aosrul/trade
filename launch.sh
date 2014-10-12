#!/bin/sh

file="stocks/ibm5.txt"
option=""
if [ $1 ]
then
option=$1
fi
if [ $2 ]
then
file=$2
fi
money=100000
echo "php trade_moulinette -p trade -f "  $file " -m " $money " " $option

php  trade_moulinette.php -p trade -f $file -m $money $option