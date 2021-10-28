#![/bin/sh]

FSDISK=lofsdisk
EX=ex2.c

sudo echo 'Andrey' > $FSDISK/file1.txt
sudo echo 'Kuzmickiy' > $FSDISK/file2.txt

sudo cp $EX $FSDISK
sudo gcc $FSDISK/$EX -o $FSDISK/ex2.out

if [ ! -d $FSDISK/bin ]
then
	sudo mkdir $FSDISK/bin
fi
sudo cp /bin/bash $FSDISK/bin

(sudo chroot $FSDISK /bin/bash && ./ex2.out > ex2.txt)
./$FSDISK/ex2.out >> $FSDISK/ex2.txt
