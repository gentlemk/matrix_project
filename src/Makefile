CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11

# --- Dirs ---
OBJ_NAME_DIR = obj
TEST_OBJ_NAME_DIR = t_obj
REPORT_DIR = report

# --- src ---
SRC = ./matrix/*.c ./helpers/*.c
TSRC = tests/*.c

# --- obj ---
OBJ = $(OBJ_NAME_DIR)/*.o
TOBJ = $(TEST_OBJ_NAME_DIR)/*.o


LIB_NAME = s21_matrix.a
NAME = s21_matrix
GCOV_NAME = s21_gcov

GCOV_FILES = *.gcda *.gcno *.info ./$(REPORT_DIR) $(GCOV_NAME)
UNAME = $(shell uname -s)

ifeq ($(UNAME), Linux)
	LIBS = -lcheck -lm -lrt -lpthread -lsubunit
endif
ifeq ($(UNAME), Darwin)
	LIBS = -lcheck
endif

all: clean $(LIB_NAME) test

clean:
	rm -rf $(LIB_NAME) $(NAME) $(OBJ_NAME_DIR) $(TEST_OBJ_NAME_DIR) $(GCOV_FILES) *.o

test: $(OBJ) $(TOBJ)
	$(CC) $(CFLAGS) $^ -o $(NAME) $(LIBS)
	./$(NAME)

$(LIB_NAME): $(OBJ)
	ar rcs $@ $^

$(OBJ): $(SRC)
	mkdir -p $(OBJ_NAME_DIR)
	$(CC) $(CFLAGS) -c ./$^
	mv *.o $(OBJ_NAME_DIR)

$(TOBJ): $(TSRC)
	mkdir -p $(TEST_OBJ_NAME_DIR)
	$(CC) $(CFLAGS) -c ./$^
	mv *.o $(TEST_OBJ_NAME_DIR)

rebild: clean $(LIB_NAME) test

valgrind: 
	valgrind --tool=memcheck --leak-check=yes ./$(NAME) 2>&1 | grep "ERROR"

gcov_report:
	mkdir -p $(REPORT_DIR)
	$(CC) $(CFLAGS) --coverage $(SRC) $(TSRC) $(LIBS) -o ./$(GCOV_NAME)
	./$(GCOV_NAME)
	lcov --capture --directory . --output-file coverage.info
	genhtml coverage.info --output-directory ./$(REPORT_DIR)
	rm -rf *.gcda *.gcno *.info $(GCOV_NAME)

style:
	clang-format -style=Google -n ./helpers/*.[ch] ./matrix/*.[ch] ./tests/*.[hc] helpers.h s21_matrix.h

fix-style:
	clang-format -style=Google -i ./helpers/*.[ch] ./matrix/*.[ch] ./tests/*.[hc] helpers.h s21_matrix.h