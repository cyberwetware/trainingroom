CC  	= g++
CFLAGS  = -g -Wall
CXXFLAGS = $(CFLAGS) 
LDFLAGS	=

TARGET  = UserVector 
OBJECTS = Vector.o User.o

$(TARGET) : $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $(TARGET)

%.o : %.c
	$(CC) $(CFLAGS) -c $<

%.o : %.cpp
	$(CC) $(CXXFLAGS) -c $<

clean:
	$(RM) $(OBJECTS) $(TARGET)

