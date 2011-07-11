fib: fib.cpp fib.h
	$(CXX) -o $@ $<

.PHONY: clean
clean: 
	-rm -rf fib *.o
