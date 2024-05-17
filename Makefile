# Compiler and Compiler Flags
CC=gcc
CFLAGS=-Wall -g -Iinclude -Ikernel/20192582

# Linker flags
LDFLAGS=-lreadline

# The build target executable:
TARGET=minios

# Source, Object files
SRCS=kernel/kernel.c kernel/system.c kernel/20192582/montecarlo_pi.c kernel/20192582/OS_time.c kernel/20192582/createfile.c kernel/20192582/deletefile.c kernel/20192582/writefile.c

OBJS=$(SRCS:.c=.o) 

# Include directory
INCLUDE_DIR=include

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) $(LDFLAGS)
	
# To obtain object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up:
clean:
	rm -f $(OBJS) $(TARGET)
