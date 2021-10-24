#![/bin/sh]
FILE_ROOT=..
FILE_PATH=$FILE_ROOT/week01
FILE=$FILE_PATH/file.txt

if [ ! -d $FILE_PATH ]
then
	mkdir $FILE_PATH
fi

touch $FILE
echo 'Andrey Kuzmickiy BS20-04\nText for second task' > $FILE
link $FILE _ex2.txt

INODE=$(stat -c '%i' $FILE)
find $FILE_ROOT -inum $INODE >> ex2.txt
find $FILE_ROOT -inum $INODE -exec rm {} \; >> ex2.txt
