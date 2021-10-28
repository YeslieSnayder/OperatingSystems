#include <sys/types.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <stdio.h>

int main() {
	//chroot(".");
	DIR *dir = opendir("/");
	if (dir == NULL) return -1;

	struct dirent *dp;
	while ((dp = readdir(dir)) != NULL) {
		if (dp->d_type == DT_REG)
			printf("%s\n", dp->d_name);
	}
	closedir(dir);
	return 0;
}
