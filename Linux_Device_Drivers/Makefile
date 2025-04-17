# Specify the kernel module object. Here hello.o is bult from hello_world.c
obj-m += hello_world.o
CFLAGS_hello_world.o := -g

# "all" target to compile the module.
all: 
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

# "clean" target to clean the build artifacts.
clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean 
