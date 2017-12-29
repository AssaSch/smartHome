# *** MACROS
CXXFLAGS=-g -ansi -pedantic -Wall -Wconversion -fPIC -c -std=c++11
CXX=g++

INC_PATH=../../
INC_PATH_OBJECT=./
CXXFLAGS += -I$(INC_PATH) -I$(INC_PATH_OBJECT)

# *** TARGETS
SRCS=$(wildcard *.cpp)
OBJS=$(SRCS:.cpp=.o)

TARGET=home

$(TARGET): $(OBJS)
	$(CXX) -Wall $(OBJS)
	$(CXX) -shared -Wl,-soname,libctest.so.1 -o libctest.so.1.0   *.o
	mv libctest.so.1.0 /opt/lib
	ln -sf /opt/lib/libctest.so.1.0 /opt/lib/libctest.so.1
	ln -sf /opt/lib/libctest.so.1.0 /opt/lib/libctest.so
    
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

