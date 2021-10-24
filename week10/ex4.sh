#![/bin/sh]

if [ ! -d tmp ]
then
	mkdir tmp
fi
touch tmp/file1
touch tmp/file2
link tmp/file1 tmp/link1

gcc ex4.c -o ex4
./ex4 > ex4.txt
