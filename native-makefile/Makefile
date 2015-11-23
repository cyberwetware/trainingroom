CC  	= gcc
CFLAGS  = -g -Wall

TARGET  = timidwolf 
OBJECTS = timidwolf.o

$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(TARGET)

%.o : %.c
	$(CC) $(CFLAGS) -c $<

clean:
	$(RM) $(OBJECTS) $(TARGET)

