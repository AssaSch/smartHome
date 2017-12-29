# *** MACROS
CXXFLAGS=-g -ansi -pedantic -Wall -Wconversion -std=c++11
CXX=g++

INC_PATH=../../includes/
CXXFLAGS += -I$(INC_PATH)

# *** TARGETS
SRCS=$(wildcard *.cpp)
OBJS=$(SRCS:.cpp=.o)

HUB_SRCS=$(wildcard ../../modules/EventType_t.cpp)
HUB_OBJS=$(SRCS:.cpp=.o)

TARGET=home

$(TARGET): $(OBJS) $(HUB_OBJS)
	$(CXX) $(OBJS) $(HUB_OBJS)  -pthread -o $(TARGET)

all: $(TARGET)

include depends

depends:
	$(CXX) -MM -I$(INC_PATH) $(SRCS) $(HUB_SRCS) > depends

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

