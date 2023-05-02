#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];
    if (access(filename, F_OK) == -1) {
        printf("%s file does not exist.\n", filename);
        return 1;
    }

    if (remove(filename) == 0) {
        printf("%s file deleted successfully.\n", filename);
        return 0;
    }
    else {
        printf("Failed to delete %s file. ", filename);
        if (errno == EACCES) {
            printf("%s\n%s\n%s\n",
		"EACCES: Permission denied.",
		"The file may be open in another application",
		"May not have sufficient permissions to delete file"
		);
        }
        else {
            printf("Unknown error.\n");
        }
        return 1;
    }
}
