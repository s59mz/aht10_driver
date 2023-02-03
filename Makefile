#
#  Makefile for simple kernel module.
#
#  Copyright (C) 2023 Matjaz Zibert - S59MZ
#

obj-m := aht10.o

KERNEL_SRC ?= $(LINUX_DIR)

all default: modules   

install: modules_install

modules modules_install help clean:
	$(MAKE) -C $(KERNEL_SRC) M=$(shell pwd) $@

