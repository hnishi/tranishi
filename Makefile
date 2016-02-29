
CXX = g++ # compiler
CXXFLAGS = -Wall -g -O2 -pipe # compiler option, -Wall enables strict warnings
TARGET = tranishi # the name of the program you want to make
SRCS =  main.cpp pdbnishi.cpp tranishi.cpp inpnishi.cpp # the names of all source files
DEPS = nlib.h math_nishi.h # header; a dependency of *.o files
OBJS := $(SRCS:.cpp=.o) # change the suffix from cpp to o

$(TARGET): $(OBJS)
	g++ -Wall -o $@ $(OBJS)
$(OBJS): $(DEPS)	# enable rebuilding with changing header

clean:
	rm -f $(TARGET) $(OBJS)

