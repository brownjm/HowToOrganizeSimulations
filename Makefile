CXX=g++
CPPFLAGS=-g

SRCS=driver.cc simulation.cc sum.cc
OBJS=$(subst .cc,.o,$(SRCS))

%.o: %.cc
	$(CXX) $(CPPFLAGS) -c $<

all: main

main: main.cc $(OBJS)
	$(CXX) $(CPPFLAGS) main.cc -o main.out $(OBJS)

clean:
	rm -f *.o *.out
