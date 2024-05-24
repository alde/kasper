#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
#include <string.h>

static char buffer[2048]

char* readline(char* prompt) {
	fputs(prompt, stdout);
	fgets(buffer, 2048, stdin);
	char* cpy = malloc(strlen(buffer)+1);
	strcpy(cpy, buffer);
	cpy[strlen(cpy)-1] = '\0';
	return cpy;
}

void add_history(char* unused) {}
#else
#include <editline/readline.h>
#ifndef __APPLE__
#include <editline/history.h>
#endif
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
