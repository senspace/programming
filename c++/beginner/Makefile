
CC = g++
TARGET = array
SOURCE = array.cpp
OBJECTS = array.o

all: $(TARGET) clean

$(TARGET):$(OBJECTS)
	@echo "Link $(OBJECTS) to $(TARGET) begin ..."
	$(CC) -o $(TARGET) $(OBJECTS)

$(OBJECTS): $(SOURCE)
	@echo "Compile $(OBJECTS) begin ..."
	$(CC) -c $(SOURCE)

# clean the linked and complied files
.PHONY: clean cleanest
clean:
	@echo "Removing complied files ..."
	-rm $(OBJECTS)
cleanest:
	@echo "Removing linked and complied files ..."
	-rm $(TARGET) $(OBJECTS)

