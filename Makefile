?PHONY: clean

clean:
	rm parsing || true

mpc.h:
	curl --no-clobber -o mpc.h https://raw.githubusercontent.com/orangeduck/mpc/master/mpc.h
mpc.c:
	curl --no-clobber -o mpc.c https://raw.githubusercontent.com/orangeduck/mpc/master/mpc.c

parsing: clean mpc.h mpc.c
	cc -std=c99 -Wall parsing.c mpc.c -lreadline -lm -o parsing
