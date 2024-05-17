CC=gcc
C_FLAGS=-Wall -Werror -Wextra
L_FLAGS=
G_FLAGS=--coverage
STD=-std=c11
ALL_FILES=s21_string.h functions/*.c functions/*.h functions/s21_sprintf/*.c functions/s21_sprintf/*.h functions/s21_sprintf/services/*.c functions/s21_sprintf/configures/*.c functions/s21_sprintf/configures/generics/*.c tests/*.c tests/*.h
TEST_FILES=tests/s21_test_
FUNC_FILES=functions/*.c functions/s21_sprintf/*.c functions/s21_sprintf/configures/*.c functions/s21_sprintf/services/*.c functions/s21_sprintf/configures/generics/*.c
TEST_NAME=s21_test_
LIB_NAME=s21_string.a
FILES_OUT=*.o
OS = $(shell uname)
V_FLAGS=--trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all -s

ifeq ($(OS),Linux)
	L_FLAGS = -lpthread -pthread -lcheck -lm -lrt -lsubunit
else
	L_FLAGS = -lcheck -lm
endif

all: gcov_report

test: clean s21_string.a
	$(CC) $(STD) $(C_FLAGS) $(TEST_FILES)memchr.c -L. $(LIB_NAME) -o $(TEST_NAME)memchr $(L_FLAGS) $(G_FLAGS)
	$(CC) $(STD) $(C_FLAGS) $(TEST_FILES)memcmp.c -L. $(LIB_NAME) -o $(TEST_NAME)memcmp $(L_FLAGS) $(G_FLAGS)
	$(CC) $(STD) $(C_FLAGS) $(TEST_FILES)memcpy.c -L. $(LIB_NAME) -o $(TEST_NAME)memcpy $(L_FLAGS) $(G_FLAGS)
	$(CC) $(STD) $(C_FLAGS) $(TEST_FILES)memset.c -L. $(LIB_NAME) -o $(TEST_NAME)memset $(L_FLAGS) $(G_FLAGS)
	$(CC) $(STD) $(C_FLAGS) $(TEST_FILES)strchr.c -L. $(LIB_NAME) -o $(TEST_NAME)strchr $(L_FLAGS) $(G_FLAGS)
	$(CC) $(STD) $(C_FLAGS) $(TEST_FILES)strcspn.c -L. $(LIB_NAME) -o $(TEST_NAME)strcspn $(L_FLAGS) $(G_FLAGS)
	$(CC) $(STD) $(C_FLAGS) $(TEST_FILES)strlen.c -L. $(LIB_NAME) -o $(TEST_NAME)strlen $(L_FLAGS) $(G_FLAGS)
	$(CC) $(STD) $(C_FLAGS) $(TEST_FILES)strncat.c -L. $(LIB_NAME) -o $(TEST_NAME)strncat $(L_FLAGS) $(G_FLAGS)
	$(CC) $(STD) $(C_FLAGS) $(TEST_FILES)strncmp.c -L. $(LIB_NAME) -o $(TEST_NAME)strncmp $(L_FLAGS) $(G_FLAGS)
	$(CC) $(STD) $(C_FLAGS) $(TEST_FILES)strncpy.c -L. $(LIB_NAME) -o $(TEST_NAME)strncpy $(L_FLAGS) $(G_FLAGS)
	$(CC) $(STD) $(C_FLAGS) $(TEST_FILES)strpbrk.c -L. $(LIB_NAME) -o $(TEST_NAME)strpbrk $(L_FLAGS) $(G_FLAGS)
	$(CC) $(STD) $(C_FLAGS) $(TEST_FILES)strrchr.c -L. $(LIB_NAME) -o $(TEST_NAME)strrchr $(L_FLAGS) $(G_FLAGS)
	$(CC) $(STD) $(C_FLAGS) $(TEST_FILES)strstr.c -L. $(LIB_NAME) -o $(TEST_NAME)strstr $(L_FLAGS) $(G_FLAGS)
	$(CC) $(STD) $(C_FLAGS) $(TEST_FILES)strtok.c -L. $(LIB_NAME) -o $(TEST_NAME)strtok $(L_FLAGS) $(G_FLAGS)
	$(CC) $(STD) $(C_FLAGS) $(TEST_FILES)strerror.c -D $(OS) -L. $(LIB_NAME) -o $(TEST_NAME)strerror $(L_FLAGS) $(G_FLAGS)
	$(CC) $(STD) $(C_FLAGS) $(TEST_FILES)sprintf.c -L. $(LIB_NAME) -o $(TEST_NAME)sprintf $(L_FLAGS) $(G_FLAGS)
	$(CC) $(STD) $(C_FLAGS) $(TEST_FILES)sscanf.c -L. $(LIB_NAME) -o $(TEST_NAME)sscanf $(L_FLAGS) $(G_FLAGS)
	$(CC) $(STD) $(C_FLAGS) $(TEST_FILES)to_lower.c -L. $(LIB_NAME) -o $(TEST_NAME)to_lower $(L_FLAGS) $(G_FLAGS)
	$(CC) $(STD) $(C_FLAGS) $(TEST_FILES)to_upper.c -L. $(LIB_NAME) -o $(TEST_NAME)to_upper $(L_FLAGS) $(G_FLAGS)
	$(CC) $(STD) $(C_FLAGS) $(TEST_FILES)insert.c -L. $(LIB_NAME) -o $(TEST_NAME)insert $(L_FLAGS) $(G_FLAGS)
	$(CC) $(STD) $(C_FLAGS) $(TEST_FILES)trim.c -L. $(LIB_NAME) -o $(TEST_NAME)trim $(L_FLAGS) $(G_FLAGS)
	make run_test
run_test:
	./$(TEST_NAME)memchr
	./$(TEST_NAME)memcmp
	./$(TEST_NAME)memcpy
	./$(TEST_NAME)memset
	./$(TEST_NAME)strchr
	./$(TEST_NAME)strcspn
	./$(TEST_NAME)strlen
	./$(TEST_NAME)strncat
	./$(TEST_NAME)strncmp
	./$(TEST_NAME)strncpy
	./$(TEST_NAME)strpbrk
	./$(TEST_NAME)strrchr
	./$(TEST_NAME)strstr
	./$(TEST_NAME)strtok
	./$(TEST_NAME)strerror
	./$(TEST_NAME)sprintf
	./$(TEST_NAME)sscanf
	./$(TEST_NAME)to_lower
	./$(TEST_NAME)to_upper
	./$(TEST_NAME)insert
	./$(TEST_NAME)trim
valgrind: test
	CK_FORK=no valgrind $(V_FLAGS) ./$(TEST_NAME)memchr
	CK_FORK=no valgrind $(V_FLAGS) ./$(TEST_NAME)memcmp
	CK_FORK=no valgrind $(V_FLAGS) ./$(TEST_NAME)memcpy
	CK_FORK=no valgrind $(V_FLAGS) ./$(TEST_NAME)memset
	CK_FORK=no valgrind $(V_FLAGS) ./$(TEST_NAME)strchr
	CK_FORK=no valgrind $(V_FLAGS) ./$(TEST_NAME)strcspn
	CK_FORK=no valgrind $(V_FLAGS) ./$(TEST_NAME)strlen
	CK_FORK=no valgrind $(V_FLAGS) ./$(TEST_NAME)strncat
	CK_FORK=no valgrind $(V_FLAGS) ./$(TEST_NAME)strncmp
	CK_FORK=no valgrind $(V_FLAGS) ./$(TEST_NAME)strncpy
	CK_FORK=no valgrind $(V_FLAGS) ./$(TEST_NAME)strpbrk
	CK_FORK=no valgrind $(V_FLAGS) ./$(TEST_NAME)strrchr
	CK_FORK=no valgrind $(V_FLAGS) ./$(TEST_NAME)strstr
	CK_FORK=no valgrind $(V_FLAGS) ./$(TEST_NAME)strtok
	CK_FORK=no valgrind $(V_FLAGS) ./$(TEST_NAME)strerror
	CK_FORK=no valgrind $(V_FLAGS) ./$(TEST_NAME)sprintf
	CK_FORK=no valgrind $(V_FLAGS) ./$(TEST_NAME)sscanf
	CK_FORK=no valgrind $(V_FLAGS) ./$(TEST_NAME)to_lower
	CK_FORK=no valgrind $(V_FLAGS) ./$(TEST_NAME)to_upper
	CK_FORK=no valgrind $(V_FLAGS) ./$(TEST_NAME)insert
	CK_FORK=no valgrind $(V_FLAGS) ./$(TEST_NAME)trim
s21_string.a:
	$(CC) $(STD) $(C_FLAGS) -c $(FUNC_FILES) -D $(OS)
	make create_lib
	rm -rf *.o
create_lib:
	ar rcs $(LIB_NAME) $(FILES_OUT)
gcov_report: clean test
	lcov -t "s21_string" -o s21_string.info -c -d .
	genhtml -o report s21_string.info
	open ./report/index.html
clang_check:
	cp ../materials/linters/.clang-format ./
	clang-format -n $(ALL_FILES)
clang:
	cp ../materials/linters/.clang-format ./
	clang-format -i $(ALL_FILES)
clean:
	rm -rf *.o
	rm -rf *.gcno
	rm -rf *.gcov
	rm -rf *.gcda
	rm -rf *.a
	rm -rf *.info
	rm -rf report
	rm -rf s21_t*
test1: test
	clear
	CK_FORK=no valgrind $(V_FLAGS) ./$(TEST_NAME)sprintf
	make clean