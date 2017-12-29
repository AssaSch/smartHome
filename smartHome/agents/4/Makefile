CXX = g++                             				   # C compiler
CXXFLAGS = -fPIC -Wall -g -I../../includes/     		# C flags
LDFLAGS = -shared                      					 # linking flags
RM = rm -f                              				# rm command
TARGET_LIB = libcTestSprinkler.so              			   # target lib

SRCS = AgentFour_t.cpp               				 # source file
DEPS = AgentFour_t.h                  			       # header file
OBJS = $(SRCS:.cpp=.o)               			     # object file

.PHONY: all
all: ${TARGET_LIB}

$(TARGET_LIB): $(OBJS)
	$(CXX) ${LDFLAGS} -o $@ $^       # -o $@ says, put the output of the compilation in the file named on the left side of the :


.PHONY: clean
clean:
	-${RM} ${TARGET_LIB} ${OBJS}



