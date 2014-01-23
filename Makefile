all: fib gcd list conditional church

church.cpp: church.hpp
church: church.cpp

conditional.cpp: conditional.hpp
conditional: conditional.cpp 

list.cpp: list.hpp
list: list.cpp 

fib.cpp: fib.hpp
fib: fib.cpp

gcd.cpp: gcd.hpp
gcd: gcd.cpp 

.PHONY: clean
clean: 
	-rm -rf *.o fib gcd list conditional church
