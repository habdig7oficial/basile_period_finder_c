compile:
	gcc -g src/functions/compress.c src/functions/decompress.c src/main.c -o compact.out

debug: compile
	lldb ./compact.out -- -d a3-b4-c5-abcd3

run: compile
	#	 ./compact.out -d a3-b4-c5-abcd3-zy10000 -c
	# ./compact.out -c abababcccc
	./compact.out -t 
