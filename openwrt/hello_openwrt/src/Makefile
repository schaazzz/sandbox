PROJ = hello_openwrt
OBJS = $(PROJ).o
CC = ../../../staging_dir/toolchain-mips_gcc4.1.2/bin/mips-linux-gcc
CFLAGS =   
OFLAGS = -Wall -c

all: $(PROJ)

$(PROJ): $(OBJS) 
	$(CC) $(CFLAGS) $(OBJS) -o $(PROJ)

$(PROJ).o: $(PROJ).c
	 $(CC) $(OFLAGS) $(PROJ).c 

clean:
	rm -rf *.o $(PROJ) 

install:
	cp -f $(PROJ) /mnt/nas/Miscellaneous/dbg_bin/
