Test2a: Test2a.o Car.o Model.o
	g++ Test2a.o Car.o Model.o -o Test2a

Test2a.o: Test2a.cpp Car.h Model.h
	g++ -c Test2a.cpp

Car.o: Car.cpp Car.h Model.h
	g++ -c Car.cpp

Model.o: Model.cpp Model.h
	g++ -c Model.cpp

clean:
	rm -f *.o Test2a

