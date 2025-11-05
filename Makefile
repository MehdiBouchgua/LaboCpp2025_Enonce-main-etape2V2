Test2a:	Test2a.cpp Model.o
	g++ Test2a.cpp Model.o -o Test2a
Model.o:	Model.o Model.h
	g++ Model.cpp -c
