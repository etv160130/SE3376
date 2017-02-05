/*
 * lscat.c
 * Reads through dirs, prints files with .c ext
 * ./lscat .
 */

#include <sys/types.h>

#include <dirent.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {

	DIR *dp;
	struct dirent *dirp;

	if (argc != 2) {
		fprintf(stderr, "usage: %s dir_name\n", argv[0]);
		exit(1);
	}

	if ((dp = opendir(argv[1])) == NULL ) {
		fprintf(stderr, "can't open '%s'\n", argv[1]);
		exit(1);
	}

	char filename[80];
	int  name_length;

	while ((dirp = readdir(dp)) != NULL ){
      	printf("%s\n", dirp->d_name);
      	memset(filename, '\0', sizeof(filename));
       	strcpy(filename, dirp->d_name);
       	printf(" ** %s ", filename);
       	name_length = strlen(filename);
       	printf(" name_length=%d \n", name_length);
       	// place the code here to find ".c" at the end of name
       	// if so, open the file, read a line & print it until EOF, and close it.
       	//

		char* per = strrchr(filename, '.');

		if(per && !strcmp(per, ".c")){
			int c;

			FILE *fc;
			fc = fopen(filename, "r");

			char *line;
			size_t len = 0;
			ssize_t read;

			while ((read = getline(&line, &len, fc)) != -1){
				printf("%s", line);
			}

			close(fc);
		}
  }

	closedir(dp);
	return(0);
}
