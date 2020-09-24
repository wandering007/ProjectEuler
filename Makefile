CC		:= gcc
CXX     := g++
CXXFLAGS	:= -std=c++11
CPPFLAGS := -Wall -Wextra -g

BIN		:= bin
SRC		:= src
INCLUDE	:= include
LIB		:= lib

LIBRARIES	:=

ifeq ($(OS),Windows_NT)
EXECUTABLE	:= $(PID).exe
SOURCEDIRS	:= $(SRC)
INCLUDEDIRS	:= $(INCLUDE)
LIBDIRS		:= $(LIB)
else
EXECUTABLE	:= $(PID)
SOURCEDIRS	:= $(shell find $(SRC) -type d)
INCLUDEDIRS	:= $(shell find $(INCLUDE) -type d)
LIBDIRS		:= $(shell find $(LIB) -type d)
endif

CINCLUDES	:= $(patsubst %,-I%, $(INCLUDEDIRS:%/=%))
CLIBS		:= $(patsubst %,-L%, $(LIBDIRS:%/=%))

SOURCES		:= $(SOURCEDIRS)/$(PID).cpp
OBJECTS		:= $(SOURCES:.cpp=.o)

all: $(BIN)/$(EXECUTABLE)

.PHONY: clean
clean:
	-$(RM) $(BIN)/$(EXECUTABLE)
	-$(RM) $(OBJECTS)


run: all
	./$(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) $(CINCLUDES) $(CLIBS) $^ -o $@ $(LIBRARIES)
