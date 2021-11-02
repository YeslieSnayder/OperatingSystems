#![/bin/sh]

FSDISK=lofsdisk
EX=ex2.c

sudo echo 'Andrey' > $FSDISK/file1.txt
sudo echo 'Kuzmickiy' > $FSDISK/file2.txt

sudo cp $EX $FSDISK
sudo gcc $FSDISK/$EX -o $FSDISK/ex2.out
gcc $EX -o ex2.out

if [ ! -d $FSDISK/bin ]
then
	sudo mkdir $FSDISK/bin
fi
sudo cp /bin/bash $FSDISK/bin
sudo cp /bin/ls $FSDISK/bin
sudo cp /bin/cat $FSDISK/bin
sudo cp /bin/echo $FSDISK/bin

# Copy shared directory
if [ ! -d $FSDISK/lib ]
then
	sudo mkdir $FSDISK/lib
	sudo mkdir $FSDISK/lib64
	sudo mkdir $FSDISK/lib/x86_64-linux-gnu
fi
# Bash
sudo cp /lib/x86_64-linux-gnu/libtinfo.so.6 $FSDISK/lib/x86_64-linux-gnu
sudo cp /lib/x86_64-linux-gnu/libc.so.6 $FSDISK/lib/x86_64-linux-gnu
sudo cp /lib64/ld-linux-x86-64.so.2 $FSDISK/lib64

# ls
sudo cp /lib/x86_64-linux-gnu/libselinux.so.1 $FSDISK/lib/x86_64-linux-gnu
sudo cp /lib/x86_64-linux-gnu/libpcre2-8.so.0 $FSDISK/lib/x86_64-linux-gnu

# Other libraries for 'cat' and 'echo' are included in 'bash' and 'ls'

#sudo chroot $FSDISK /bin/bash
#sudo ./$FSDISK/ex2.out >> $FSDISK/ex2.txt

sudo chroot $FSDISK ./ex2.out > ex2.txt
exit
./ex2.out >> ex2.txt
