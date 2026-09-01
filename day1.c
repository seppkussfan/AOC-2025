#include <stdio.h>

typedef struct Turn {
	char direction;
	int magnitude;
} Turn;

int power (int base, int exponent) {
	if (exponent == 0) {
		return 1;
	}
	return base * power(base, exponent -1);
}

Turn take_input() {
	// Collect input for each row
	char input[20];
	fgets(input, 20, stdin);
	
	int magnitude = 0;
	int power_counter = 0;
	for (int i=20; i>0; i--) {
		if (input[i] <= 57 && input[i] >= 47){
			int num = (int) input[i] - 48;
			num = num * power(10, power_counter);
			magnitude = magnitude + num;
			power_counter++;
		}	
	}
	
	Turn t = {.direction = input[0], .magnitude = magnitude}; 
	return t;
}

int main() {
	// Reading data and storing into array;
	Turn arr[4177];
	for (int i=0; i < 4177; i++) {
		Turn t = take_input();
		arr[i] = t;
	}
	
	int dial = 50;
	int count_zero = 0;	

	for (int i=0; i<4177; i++) {
		Turn t = arr[i];
		if (t.direction == 'L'){
			dial = dial - t.magnitude;
		} else {
			dial = dial + t.magnitude;
		}

		dial = dial % 100;
		if (dial == 0) {
			count_zero++;
		}
	}
	printf("Value of Dial: %d\n", dial);
	printf("Value of Counter: %d\n", count_zero);	
	return 0;
}
