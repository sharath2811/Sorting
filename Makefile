KSorted: ksorted.o minheap.o
	g++ ksorted.o minheap.o -o KSorted	

ksorted.o: ksorted.cpp minheap.h
	g++ -c ksorted.cpp

minheap.o: minheap.h minheap.cpp
	g++ -c minheap.cpp

clean: 
	rm -f *.o 

run: KSorted
	./KSorted
