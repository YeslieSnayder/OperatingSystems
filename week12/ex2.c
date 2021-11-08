#include <linux/input.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
	FILE *file;
	FILE *fp;
	struct input_event event;
	char *str = (char*) malloc(50 * sizeof(char));
	
	fp = fopen("./ex2.txt", "w+");
	file = fopen("/dev/input/by-path/platform-i8042-serio-0-event-kbd", "r");
	if (file != NULL) {
		while(1) {
			fread(&event, sizeof(struct input_event), 1, file);
			if (event.type == EV_KEY) {
				if (event.value == 0)
					sprintf(str, "\nRELEASED 0x%04x (%d)\n", event.code, event.code);
				else if (event.value == 1)
					sprintf(str, "\nPRESSED 0x%04x (%d)\n", event.code, event.code);
				else if (event.value == 2)
					sprintf(str, "\nHOLD 0x%04x (%d)\n", event.code, event.code);
				printf(str);
				fputs(str, fp);
				fflush(fp);
			}
		}
		fclose(file);
		fclose(fp);
	}
}
