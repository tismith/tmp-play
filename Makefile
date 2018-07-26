CXXFLAGS += -Wextra -Wall -pedantic

all: fib gcd list conditional church

.PHONY: clean
clean:
	-rm -rf fib *.o gcd list conditional church
