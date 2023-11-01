make: 
	sudo sysctl -w kernel.randomize_va_space=0 && gcc -z execstack -fno-stack-protector -z norelro -g -O0 holjak.c -o holjak
