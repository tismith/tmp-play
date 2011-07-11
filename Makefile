all: fib gcd

fib: fib.cpp fib.hpp
	$(CXX) -o $@ $<

gcd: gcd.cpp gcd.hpp
	$(CXX) -o $@ $<

.PHONY: clean
clean: 
	-rm -rf fib *.o gcd
