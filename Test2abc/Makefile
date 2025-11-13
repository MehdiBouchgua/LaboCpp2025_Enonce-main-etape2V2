# ========================================================
# Makefile global - Étapes 2a, 2b, 2c
# Projet C++ : Gestion d’une concession automobile
# ========================================================

CXX = g++
CXXFLAGS = -Wall -std=c++17

# === Cibles ===
ALL = Test2a Test2b Test2c

# ========================================================
# Cibles principales
# ========================================================

all: $(ALL)

# ---------- Étape 2a ----------
Test2a: Model.o Car_2a.o Test2a.o
	$(CXX) $(CXXFLAGS) -o $@ $^

Car_2a.o: Car.cpp Car.h Model.h
	$(CXX) $(CXXFLAGS) -DSTEP2A -c Car.cpp -o Car_2a.o

Test2a.o: Test2a.cpp Car.h Model.h
	$(CXX) $(CXXFLAGS) -c Test2a.cpp

# ---------- Étape 2b ----------
Test2b: Option.o Test2b.o
	$(CXX) $(CXXFLAGS) -o $@ $^

Option.o: Option.cpp Option.h
	$(CXX) $(CXXFLAGS) -c Option.cpp

Test2b.o: Test2b.cpp Option.h
	$(CXX) $(CXXFLAGS) -c Test2b.cpp

# ---------- Étape 2c ----------
Test2c: Model.o Option.o Car_2c.o Test2c.o
	$(CXX) $(CXXFLAGS) -o $@ $^

Car_2c.o: Car.cpp Car.h Model.h Option.h
	$(CXX) $(CXXFLAGS) -DSTEP2C -c Car.cpp -o Car_2c.o

Test2c.o: Test2c.cpp Car.h Model.h Option.h
	$(CXX) $(CXXFLAGS) -c Test2c.cpp

# ---------- Fichiers communs ----------
Model.o: Model.cpp Model.h
	$(CXX) $(CXXFLAGS) -c Model.cpp

# ========================================================
# Nettoyage
# ========================================================

clean:
	rm -f *.o $(ALL)

# ========================================================
# Exécutions rapides
# ========================================================

run2a: Test2a
	./Test2a

run2b: Test2b
	./Test2b

run2c: Test2c
	./Test2c

