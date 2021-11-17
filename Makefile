CXX = g++
CXXFLAGS = -g -std=c++11 -Wall -Werror=return-type -Werror=uninitialized # --coverage
# Do not allow compiling if a non-void function is missing a return statement
# Do not allow compiling if a variable is used without being initialized

OBJECTS = main.o passserver.o
TESTS = test-1-hashtable test-2-hashtable test-3-passserver
CATCH = test/catch/catch.o

main: $(OBJECTS)
	$(CXX) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -rf *.dSYM test/*.dSYM
	rm -f *.o *.gc* test/*.o test/*.gc* *.dSYM $(addprefix test/,$(TESTS)) main $(CATCH)

$(TESTS): $(CATCH)
	$(CXX) $(CXXFLAGS) -o test/$@ $^
	test/$@ --success "$(SUB_TEST)"

test-all: $(TESTS)
test-1-hashtable: test/test-1-hashtable.cpp hashtable.o
test-2-hashtable: test/test-2-hashtable.cpp hashtable.o
test-3-passserver: test/test-3-passserver.cpp passserver.o hashtable.o
