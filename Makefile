all: scanner.c queue.c
		gcc -g -o scanner scanner.c queue.c ping.c -lpthread
clean:
		rm -rf *.0 scanner
