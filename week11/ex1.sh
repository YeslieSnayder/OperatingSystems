#![/bin/sh]
IMAGE=lofs.img
FSDISK=lofsdisk

# Allocation and creating file system
dd if=/dev/zero of=$IMAGE bs=1M count=50
losetup -fP $IMAGE
sudo mkfs.ext4 ./$IMAGE

# Mounting the created filesystem (loopback)
mkdir $FSDISK
mount -o loop $IMAGE $FSDISK
df -hP $FSDISK
