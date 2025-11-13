Test2b: Test2b.o Option.o
	g++ Test2b.o Option.o -o Test2b

Test2b.o: Test2b.cpp Option.h
	g++ -c Test2b.cpp

Option.o: Option.cpp Option.h
	g++ -c Option.cpp

clean:
	rm -f *.o Test2b

