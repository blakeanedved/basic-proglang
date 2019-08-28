all: interpreter

interpreter: interpreter.c
	rm -f BPL
	gcc -o BPL interpreter.c

minified: minified.c
	rm -f BPL
	gcc -o BPL minified.c

debug: interpreter.c
	rm -f BPL
	gcc -g -o BPL interpreter.c

clean:
	rm -f BPL
