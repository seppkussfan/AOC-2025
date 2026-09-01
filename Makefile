# Define the executable and the test rule
.PHONY: test

test: a
	@echo "Running test with input.txt..."
	clang day1.c
	./a.out < input.txt

