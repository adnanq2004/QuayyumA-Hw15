#include "file.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char ** parse_args(char * line) {

	char ** ret_args = malloc(strlen(line));
	char * templine = line;
	int i;
	int count = 0;
	for (i = 0; i < strlen(templine); i++) {
		if (templine[i] == ' ') {
			count++;	
		}
	}
	for (i = 0; i < count; i++) {
		ret_args[i] = strsep(&line, " ");
	}
	ret_args[count] = 0;
	return ret_args;

}

int main(int argc, char * argv[]) {

	char * l;

	if (argc < 2) {

		printf("using test case 'ls -a -l'");
		strcpy(l, "ls -a -l");
	
	}

	else {
	
		printf("using test case '%s'", argv[1]);
		l = argv[1];

	}

	char ** args = parse_args(l);
                execvp(args[0], args);
                free(args);


	return 0;

}
