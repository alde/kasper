#include <stdio.h>
#include <stdlib.h>

#include <editline/readline.h>

#ifndef __APPLE__
#include <editline/history.h>
#endif

static char* VERSION = "0.0.1";

int main(int argc, char** argv) {
	printf("kasper version %s\n", VERSION);
	printf("Press Ctrl+c to Exit\n");
	
	while (1) {
		char* input = readline("kasper> ");
		add_history(input);

		printf("No you're a %s\n", input);

		free(input);
	}

	return 0;
}
