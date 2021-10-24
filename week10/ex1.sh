#![/bin/sh]
touch _ex1.txt
echo 'Andrey Kuzmickiy BS20-04\nSome text' > _ex1.txt
ln _ex1.txt _ex1_1.txt
ln _ex1.txt _ex1_2.txt
for file in _ex1.txt _ex1_1.txt _ex1_2.txt
do
	ls -i $file >> ex1.txt
done
