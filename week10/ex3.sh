#![/bin/sh]
FILE=_ex3.txt
MAIN=ex3.txt

echo 'INITIAL permissions' > $MAIN
touch $FILE
ls -l $FILE >> $MAIN

echo '\nRemove execute permissions' >> $MAIN
chmod 664 $FILE
ls -l $FILE >> $MAIN

echo '\nUser and Others have all permissions' >> $MAIN
chmod u=rwx,o=rwx $FILE
ls -l $FILE >> $MAIN

echo '\nGroup permissions are equal' >> $MAIN
chmod g=u $FILE
ls -l $FILE >> $MAIN

echo '\n\nAnswers' >> $MAIN
echo '660: Makes the file read\write for user(owner) and group of the user and removes all permissions for other users.' >> $MAIN
echo '775: Gives all permissions for user(owner) and his group, also gives read/execute access for other users.' >> $MAIN
echo '777: Gives all permissions of that file for everyone.' >> $MAIN
