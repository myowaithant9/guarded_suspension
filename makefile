OUTPUT = main
OBJS =  \
	request.o \
	requestQueue.o \
	clientThread.o \
	serverThread.o \
	main.o

CC = gcc
CFLAGS = -g
LDFLAGS := -lpthread
COMPILE_FLAGS = -c
.SUFFIXES: .c .o

.c.o:
	$(CC) $(CFLAGS) $(LDFLAGS) $(COMPILE_FLAGS) -o $@ $<

$(OUTPUT): $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(OUTPUT) $^

clean:
	rm -rf $(OUTPUT) $(OBJS)
