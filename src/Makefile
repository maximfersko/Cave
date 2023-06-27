CXX = g++ -std=c++17 #--verbose
SRC = app/model/*.cc
TEST = ./test.cc
LIBCHECK = -lgtest
GCOV = --coverage

lint:
	@clang-format -i --verbose app/model/*.cc  app/model/*.h app/controller/*.cc app/controller/*.h app/model/matrix/*.inl  app/model/matrix/*.h app/view/*.cc app/view/*.h

clean:
	rm -rf test leaks *.dSYM *.out *.cfg Maze.tar.gz build leaks.out
	rm -rf *.gcno *.gcda *.gcov *.info report .clang-format main
	rm -rf *.o *.a

install: uninstall
	mkdir build
	cp -r app/* build
	cd build; qmake maze.pro
	make -C build

uninstall:
	rm -rf build

test: clean
	$(CXX) $(SRC) $(TEST) $(LIBCHECK) $(GCOV) -o test
	./test

gcov_report: test
	lcov -t "test" --no-external -o test.info -c -d ./
	genhtml -o report test.info
	open report/index.html
	
dist:
	rm -rf Maze.tar.gz
	tar -czvf Maze.tar.gz *
