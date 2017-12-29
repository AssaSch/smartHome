# *** MACROS
CXXFLAGS=-g -ansi -pedantic -Wall -Wconversion -std=c++11
CXX=g++

INC_PATH=../../
CXXFLAGS += -I$(INC_PATH)

# *** TARGETS
SRCS=$(wildcard *.cpp)
OBJS=$(SRCS:.cpp=.o)

TARGET=home

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -pthread -o $(TARGET)

all: $(TARGET)

include depends

depends:
	$(CXX) -MM -I$(INC_PATH) $(SRCS) > depends

# *** COMMANDS
clean:
	-rm $(TARGET)
	-rm *.o
	-rm depends

run:
	./$(TARGET)
	
gdb:
	gdb $(TARGET)
##################################

