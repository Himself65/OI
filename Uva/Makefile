include ./.env
GNU-COMPILE 	=
CGLAGS			= -g
CC 				= $(GNU-COMPILE)g++

OBJDIR 			= $(CURDIR)/../out

FILES 			:= Uva100.cpp
FILES 			+= Uva107.cpp

OBJ-SUFFIX		= out
OBJS			= $(patsubst %.cpp,%.$(OBJ-SUFFIX),$(FILES))

prepare:
	mkdir -p $(OBJDIR)

TARGET 			:= $(OBJDIR)/$(TARGET).$(OBJ-SUFFIX)
run:
	@$(TARGET)

%.out: %.cpp
	$(CC) $(CFLAGS) -o $(OBJDIR)/$@ $^

all: prepare $(OBJS)

.PHONY: clean
clean:
	-rm -rf $(OBJDIR)
