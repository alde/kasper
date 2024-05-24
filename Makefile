?PHONY: clean

clean:
	rm repl


repl: clean
	cc -std=c99 -Wall main.c -ledit -o repl
