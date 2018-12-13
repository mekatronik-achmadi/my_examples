PROJECT		= FuzzySim

CXXSRC		= ../main.cpp ../my_fuzzy.cpp
CXXINC		= .

CXX			= g++
CXXFLAG		= -Wall
CXXLIB		= -lstdc++
CXXOBJ		= $(CXXSRC:%.cpp=%.o)

$(PROJECT):$(CXXOBJ)
	$(CC) $(CXXFLAG) $(CXXOBJ) -o $(PROJECT) $(CXXLIB)

%.o: %.cpp
	$(CC) $(CXXFLAG) -c $< -o $@

clean:
	rm *.o $(PROJECT)
