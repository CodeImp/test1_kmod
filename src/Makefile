#
# veeamsnap kernel module make file
#
KERNEL_MODULE_NAME := test1_kmod

KERNEL_MODULE_OBJECT_FILE_LIST := test1_main.o 


obj-m := $(KERNEL_MODULE_NAME).o
$(KERNEL_MODULE_NAME)-y += $(KERNEL_MODULE_OBJECT_FILE_LIST)
ccflags-y := -g -ggdb -O1 -DDEBUG $(COMPATIBILITY_FLAGS) -Wno-multichar

all:
	@echo Making all...
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
	@echo Completed.

clean:
	@echo Cleaning ...
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
	@echo Completed.
