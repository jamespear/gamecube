CC = g++
CFLAGS = -g -Wall
TARGET = $(wildcard *.cpp)
LINKER_FLAGS = -I../SDL2/include -lSDL2 -I../JUCE/modules
TARGET_NAME = gamecube
all: $(TARGET)
	$(CC) $(TARGET) $(CFLAGS) $(LINKER_FLAGS) -o $(TARGET_NAME)
	./$(TARGET_NAME)
clean:
	rm *.o $(TARGET_NAME)

