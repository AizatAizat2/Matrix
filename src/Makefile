CC=gcc
FLAGS=-Wall -Werror -Wextra -std=c11
SOURCE=$(wildcard s21_*.c)
OBJECTS=$(patsubst %.c, %.o, $(SOURCE))
COVERAGE=-fprofile-arcs -ftest-coverage

SYSTEM := $(shell uname -s)
ifeq ($(SYSTEM),Linux)
    LFLAGS = -lcheck -lsubunit -lm -lrt -lpthread -L. -l:s21_matrix.a
endif
ifeq ($(SYSTEM),Darwin)
	LFLAGS = -lcheck -lm -lpthread s21_matrix.a
endif

all: s21_matrix.a

gcov_report: clean
	$(CC) $(FLAGS) $(COVERAGE) -c s21_matrix.h $(SOURCE)
	ar -rcs s21_matrix.a $(OBJECTS)
	$(CC) $(FLAGS) $(COVERAGE) -c test.c -o test.o
	$(CC) $(FLAGS) $(COVERAGE) test.o -o test $(LFLAGS)
	chmod +x test
	./test
	mkdir gcov_report
	gcov test.c $(SOURCE)
	lcov -c -d ./ --output-file ./coverage.info
	genhtml ./coverage.info --output-directory ./gcov_report/

open:
	open gcov_report/index.html

test: clean test.o s21_matrix.a
	$(CC) $(FLAGS) test.o -o test $(LFLAGS)
	chmod +x test
	./test

valgrind: test
	valgrind --tool=memcheck --leak-check=full --log-file=1.txt ./test
	grep "errors from" 1.txt
	rm -rf 1.txt

test.o: test.c s21_matrix.h
	$(CC) $(FLAGS) -c test.c -o test.o

s21_matrix.a: $(OBJECTS)
	ar -rcs s21_matrix.a $(OBJECTS)

$(OBJECTS): $(SOURCE)
	$(CC) $(FLAGS) -c s21_matrix.h $(SOURCE)

clang-check: clean
	cp ../materials/linters/.clang-format ./
	clang-format -n *.c *.h
	rm .clang-format

clean:
	rm -rf s21_matrix.a test *.o *.gcda *.gcno *.gcov *.gch ./gcov_report *.html *.css *.info
