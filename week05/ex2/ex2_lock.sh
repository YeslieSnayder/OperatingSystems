#!/bin/bash
for i in 1 2 3 4 5 6 7 8 9 10
do
	if [ -e file.lock ]; then
		filename=file.txt
	else
		ln file.txt file.lock
		filename=file.lock
	fi
	num=$( tail -n 1 $filename )
	echo $((num+1)) >> $filename
done

rm file.lock

