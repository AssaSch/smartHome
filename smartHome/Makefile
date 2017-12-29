# *** MACROS
CXXFLAGS=-g -ansi -pedantic -Wall -Wconversion -std=c++11
CXX=g++

INC_PATH=includes/
MODULES_PATH=modules/
CXXFLAGS += -I$(INC_PATH)

# export LD_LIBRARY_PATH=./agents/:$LD_LIBRARY_PATH

# *** TARGETS
SRCS=$(wildcard $(MODULES_PATH)*.cpp)
OBJS=$(SRCS:.cpp=.o)

TARGET=home

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -pthread -rdynamic -ldl -Wl,-rpath,"./agents/" -o $(TARGET)
	export LD_LIBRARY_PATH=./agents/:$LD_LIBRARY_PATH

all: $(TARGET)

include depends

depends:
	$(CXX) -MM -I$(INC_PATH) $(SRCS) > depends

# *** COMMANDS
clean:
	-rm $(TARGET)
	-rm $(MODULES_PATH)*.o
	-rm depends

run:
	./$(TARGET)
	
gdb:
	gdb $(TARGET)
##################################

