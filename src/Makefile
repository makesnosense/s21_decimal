CC = gcc
# CFLAGS = -std=c11
CFLAGS = -Wall -Wextra -Werror -std=c11
COVERAGE_FLAGS = -fprofile-arcs -ftest-coverage
TESTFLAGS:= -lcheck -lm
# ADDITIONAL_TEST_FLAGS = 
DISTRO:=

ifeq ($(shell uname),Darwin)
	GCOVR_THEME = --html-theme github.dark-green
else
	DISTRO := $(shell cat /etc/os-release | grep ^ID= | cut -d'=' -f2 | tr -d '"')
	ifneq ($(DISTRO),arch)
		TESTFLAGS+= -lsubunit 
	endif
endif


TESTS_DIR = tests
TESTS_SRC_FILES = $(wildcard $(TESTS_DIR)/*.c)
GCOV_REPORT_DIR = gcov_report

DECIMAL_SRC_FILES = $(wildcard *.c)
DECIMAL_OBJ_DIR = object_files
DECIMAL_OBJ_FILES = $(patsubst %.c,$(DECIMAL_OBJ_DIR)/%.o,$(DECIMAL_SRC_FILES))
DECIMAL_LIB = s21_decimal.a


all: $(DECIMAL_LIB)


test: clean build_tests
	./run_tests

gcov_report: CFLAGS += $(COVERAGE_FLAGS)
gcov_report: clean build_tests test
	@mkdir -p $(GCOV_REPORT_DIR)
	@gcovr -o $(GCOV_REPORT_DIR)/gcov_report.html --html --html-self-contained --html-details $(GCOVR_THEME) --exclude $(TESTS_DIR)	
	@open $(GCOV_REPORT_DIR)/gcov_report.html
	rm -f *.gcda *.gcno *.gcov

build_tests: clean $(TESTS_SRC_FILES) $(DECIMAL_LIB)
	$(CC) $(CFLAGS) $(TESTS_SRC_FILES) $(DECIMAL_LIB) -o run_tests $(TESTFLAGS)

$(DECIMAL_LIB): $(DECIMAL_OBJ_FILES)
	ar rcs $@ $^ 

$(DECIMAL_OBJ_DIR)/%.o: %.c
	@mkdir -p $(DECIMAL_OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -drf $(DECIMAL_OBJ_DIR)
	rm -f $(DECIMAL_LIB)
	rm -f run_tests
	rm -f *.gcda *.gcno *.gcov
	rm -drf $(GCOV_REPORT_DIR)

