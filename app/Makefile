TARGET = aht
SOURCES = aht.c 

CC=$(CROSS_COMPILE)gcc

OBJECTS = $(SOURCES:%.c=%.o)

$(TARGET): $(OBJECTS)
	$(CC)  $^ -o $@

%.o: %.c
	$(CC) -c $< -o $@

clean:
	rm $(OBJECTS) $(TARGET)
