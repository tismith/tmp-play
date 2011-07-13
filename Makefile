all: fib gcd list conditional church

church: church.cpp church.hpp
	$(CXX) -o $@ $<

conditional: conditional.cpp conditional.hpp
	$(CXX) -o $@ $<

list: list.cpp list.hpp
	$(CXX) -o $@ $<

fib: fib.cpp fib.hpp
	$(CXX) -o $@ $<

gcd: gcd.cpp gcd.hpp
	$(CXX) -o $@ $<

.PHONY: clean
clean: 
	-rm -rf fib *.o gcd list conditional church
