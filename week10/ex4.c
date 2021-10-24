#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main() {
	DIR *dirp = opendir("tmp");
	if (dirp == NULL) 
		return -1;

	struct dirent *dp = malloc(sizeof(struct dirent));
	struct stat *info = malloc(sizeof(struct stat));
	
	// Search through directory
	while ((dp = readdir(dirp)) != NULL) {

		// If file is regular or hard link
		if (dp->d_type == DT_REG) {
			char filename[260];
			snprintf(filename, sizeof(filename), "%s%s", "tmp/", dp->d_name);
			stat(filename, info);

			// If file has hard links
			if (info->st_nlink > 1) {
				long unsigned int ino = info->st_ino;
				long unsigned int nlinks = info->st_nlink;
				long unsigned int cur_link = 1;
				DIR *in_dir = opendir("tmp"); // There is no check for existence of directory, because we already know that it exists.
				struct dirent *in_dp = malloc(sizeof(struct dirent));
				
				// Search through the directory again to find new files
				printf("%s - ", dp->d_name);
				while ((in_dp = readdir(in_dir)) != NULL) {
					if (in_dp->d_type == DT_REG) {
						snprintf(filename, sizeof(filename), "%s%s", "tmp/", in_dp->d_name);
						stat(filename, info);

						// Found hard link or the file itself
						if (ino == info->st_ino) {
							// Just formating the output
							if (cur_link == nlinks) {
								printf("%s\n", in_dp->d_name);
								break;
							} else
								printf("%s, ", in_dp->d_name);
							cur_link++;
						}
					}
				}
				closedir(in_dir);
			}
		}
	}
	closedir(dirp);
	return 0;
}
