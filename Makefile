CC      = gcc
CFLAGS  = -Wall -Wextra -g -std=c11
TARGET  = contacts
OBJS    = main.o contact.o

$(TARGET): $(OBJS)
		$(CC) $(OBJS) -o $(TARGET)

%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		rm -f *.o $(TARGET)

run: $(TARGET)
		./$(TARGET)

.PHONY: clean run
