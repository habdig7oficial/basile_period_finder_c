compile:
	gcc src/functions/compress.c src/functions/decompress.c src/main.c -o compact

run: compile
	./compact -c abcabcaaaaabbbbbbccccc