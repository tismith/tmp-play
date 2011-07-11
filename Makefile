all: fib gcd

fib: fib.cpp fib.h
	$(CXX) -o $@ $<

gcd: gcd.cpp gcd.h
	$(CXX) -o $@ $<

.PHONY: clean
clean: 
	-rm -rf fib *.o gcd
