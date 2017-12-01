#!/bin/bash
WORDFILE=$1

while true; do
    lines=$(cat $WORDFILE | wc -l);
    rnum=$(($RANDOM*$RANDOM%$lines+1));
    sleep 2;
    sed -n "$rnum p" $WORDFILE > /tmp/my_fifo;
done
