CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11
LIBS =  -lcheck
LINUX = -lrt -lpthread -lm 
LFLAGS = -fprofile-arcs -ftest-coverage
OS = $(shell uname -s)


all: clean gcov_report

s21_matrix.a:
	$(CC) -c $(CFLAGS) s21_*.c
	ar rcs s21_matrix.a s21_*.o

mytest:
	gcc -Wall -Werror -Wextra test.c s21_*.c -o test
	./test

test: s21_matrix.a
ifeq ($(OS), Darwin)
	$(CC) $(CFLAGS) tests/*.c s21_matrix.a -o unit_tests $(LIBS)
else
	$(CC) tests/*.c s21_matrix.a -o unit_tests $(LIBS) $(LINUX)
endif
	./unit_tests

gcov_report:
ifeq ($(OS), Darwin)
	$(CC) $(CFLAGS) $(LFLAGS) s21_*.c tests/*.c -o test.out $(LIBS)
else
	$(CC) $(CFLAGS) $(LFLAGS) s21_*.c tests/*.c -o test.out $(LIBS) $(LINUX)
endif
	./test.out
	lcov -t "test" -o test.info -c -d .
	genhtml -o ./report test.info
	open ./report/index.html

style:
	cp ../materials/linters/.clang-format ./.clang-format
	clang-format -i ./*.c ./*.h
	clang-format -n ./*.c ./*.h

valgrind: test
	valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all -s ./unit_tests

clean:
	rm -rf unit_tests *.o *.a
	rm -rf *.gcda
	rm -rf *.gcno
	rm -rf *.info
	rm -rf *.gcov
	rm -rf report
	rm -rf gcov_test
	rm -rf test.out