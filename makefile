#comment the following line if you are using SYSV
DFLAG=-DBSD
dohpart: ll.o hgraph.o dohpart.o system.o
	g++  -O2 -o dohpart dohpart.o hgraph.o ll.o system.o -lm

system.o: system.hpp system.cc
	g++  -O2 -c -Wall ${DFLAG} system.cc


ll.o: ll.hpp ll.cc
	g++  -O2 -c -Wall ll.cc 

hgraph.o: hgraph.hpp hgraph.cc
	g++  -O2 -c -Wall hgraph.cc 


dohpart.o: dohpart.cc
	g++  -O2 -c -Wall dohpart.cc 


