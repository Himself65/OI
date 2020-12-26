include ./.env
GNU-COMPILE 	=
CFLAGS			= -g
CC 				= $(GNU-COMPILE)g++

OBJDIR 			= $(CURDIR)/../out

FILES 			:= Uva100.cpp
FILES 			+= Uva107.cpp

OBJ-SUFFIX		= o
OBJ-FORMAT		= %.$(OBJ-SUFFIX)
OBJS			= $(patsubst %.cpp,$(OBJ-FORMAT),$(FILES))

prepare:
	mkdir -p $(OBJDIR)

TARGET 			:= $(patsubst %.cpp,$(OBJ-FORMAT),$(TARGET))

run: $(TARGET)
ifneq ($(REDEFINE),1)
	$(OBJDIR)/$(TARGET)
else
	@echo "redefine I/O"
	$(OBJDIR)/$(TARGET) > $(OBJDIR)/$(OUTPUT) < $(OBJDIR)/$(INPUT)
endif

$(OBJ-FORMAT): %.cpp
	$(CC) $(CFLAGS) -o $(OBJDIR)/$@ $^

.PHONY: all clean
all: prepare $(OBJS)

clean:
	-rm -rf $(OBJDIR)
