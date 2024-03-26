CC = g++
CFLAGS = -g -Wall
TARGET = $(wildcard *.cpp)
LINKER_FLAGS = -I/Library/Developer/CommandLineTools/SDKs/MacOSX10.15.sdk/System/Library/Frameworks/IOKit.framework/Versions/A/Headers/usb
TARGET_NAME = gamecube
all: $(TARGET)
	$(CC) $(TARGET) $(CFLAGS) $(LINKER_FLAGS) -o $(TARGET_NAME)
	./$(TARGET_NAME)
clean:
	rm *.o $(TARGET_NAME)

