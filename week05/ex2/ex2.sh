#!/bin/bash

for a in 1 2 3 4 5 6 7 8 9 10
do
	num=$( tail -n 1 file.txt )
	echo $((num+1)) >> file.txt
done

