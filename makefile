CXX = g++
CXXFLAGS = -Wall

proj4: War.o driver.cpp Warhorse.o Horse.o Light.o Medium.o Heavy.o Untrained.o
	$(CXX) $(CXXFLAGS) War.o driver.cpp Warhorse.o Horse.o Light.o Medium.o Heavy.o Untrained.o -o proj4
War.o: War.cpp War.h
	$(CXX) $(CXXFLAGS) -c War.cpp
Warhorse.o: Warhorse.cpp Warhorse.h
	$(CXX) $(CXXFLAGS) -c Warhorse.cpp
Horse.o: Horse.h Horse.cpp
	$(CXX) $(CXXFLAGS) -c Horse.cpp
Light.o: Light.cpp Light.h
	$(CXX) $(CXXFLAGS) -c Light.cpp
Medium.o: Medium.cpp Medium.h
	$(CXX) $(CXXFLAGS) -c Medium.cpp
Heavy.o: Heavy.cpp Heavy.h
	$(CXX) $(CXXFLAGS) -c Heavy.cpp
Untrained.o: Untrained.cpp Untrained.h
	$(CXX) $(CXXFLAGS) -c Untrained.cpp

run:
	./proj4 proj4_data.txt
val:
	valgrind ./proj4 proj4_data.txt
