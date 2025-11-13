Test2c: Test2c.o Car.o Model.o Option.o
	g++ Test2c.o Car.o Model.o Option.o -o Test2c

Test2c.o: Test2c.cpp Car.h Model.h Option.h
	g++ -c Test2c.cpp

Car.o: Car.cpp Car.h Model.h Option.h
	g++ -c Car.cpp

Model.o: Model.cpp Model.h
	g++ -c Model.cpp

Option.o: Option.cpp Option.h
	g++ -c Option.cpp

clean:
	rm -f *.o Test2c

