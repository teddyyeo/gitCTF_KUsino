make: 
	gcc -z execstack -fno-stack-protector -z norelro -g -O0 holjak.c -o holjak && ./holjak