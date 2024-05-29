# Compiler and Compiler Flags
CC=gcc
CFLAGS=-Wall -g -Iinclude -Ikernel/20192582 -Ikernel/OS_project

# Linker flags
LDFLAGS=-lreadline

# The build target executable:
TARGET=minios

# Source, Object files
SRCS=kernel/kernel.c kernel/system.c kernel/20192582/montecarlo_pi.c kernel/OS_project/OS_time.c kernel/OS_project/createfile.c kernel/OS_project/deletefile.c kernel/OS_project/writefile.c kernel/OS_project/IPC_W.c kernel/OS_project/IPC_R.c kernel/OS_project/sys_fork.c kernel/OS_project/sys_exec.c kernel/OS_project/sys_abort.c kernel/OS_project/sys_exit.c kernel/OS_project/sys_waitpid.c kernel/OS_project/wait_time.c kernel/OS_project/wait_event.c kernel/OS_project/signal_event.c 

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
