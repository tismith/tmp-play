This is a collection of test programs that play around with C++ template metaprogramming.

Most of the interesting stuff is in list.{c,h}pp
In there is a LIST data structure that can generate compile time lists of ints
(stored in typedefs) over which computations or code can be generated at 
compile time. The coolest example in there is the compile time merge-sort. 

There is the start of some church encoding experiments in church.{c,h}pp

There is a basic compile time Fibonacci generator in fib.{c,h}pp

There is a compile time GCD calculator in gcd.{c,h}pp

There are some dodgy conditional execution templates in conditional.{c,h}pp

For more information, check the first in a series of blog posts at:
http://tismith.id.au/2014/template-metaprogramming-fun.html
