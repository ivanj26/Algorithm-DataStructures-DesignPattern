# the compiler: gcc for C program, define as g++ for C++
CC = g++

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CFLAGS  = -std=c++11

# the build target executable:
TARGET = driver

all: $(TARGET)

$(TARGET): $(TARGET).cpp
	$(CC) $(CFLAGS) -o $(TARGET).out $(TARGET).cpp $(LIBRARIES)

clean:
	$(RM) $(TARGET)

run:
	./$(TARGET).out