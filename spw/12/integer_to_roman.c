#include <stdio.h>
#include <stdlib.h>


int LOG(int weight) 
{
	switch(weight) {
		case 1:
			return 0;
		case 10:
			return 1;
		case 100:
			return 2;
		case 1000:
			return 3;
	}
	return -1;
}
/**
 * wieght:1		1	2	3	4	5	6	7	8	 9	
 *				I	II	III	IV	V	VI	VII	VIII IX
 * wieght:10	1	2	3	4	5	6	7	8	 9	
 *				X	XX	XXX	XL	L	LX	LXX	LXXX XC
 * wieght:100	1	2	3	4	5	6	7	8	 9	
 *				C	CC	CCC	CD	D	DC	DCC	DCCC MD
 * wieght:1000	1	2	3
 *				M	MM	MMM
 */
char *get_digit(int digit, int weight)
{
	char one[] = {'I', 'X', 'C', 'M'};
	char five[] = {'V', 'L', 'D'};

	char *roman_digit = malloc(sizeof(char) * 8);

	if (digit == 0) {
		roman_digit[0] = '\0';
		return roman_digit;
	}
	if (digit <= 3) {
		roman_digit[digit] = '\0';
		while (--digit >= 0) roman_digit[digit] = one[LOG(weight)];
		return roman_digit;
	}

	if (digit == 4 || digit == 9) {
		roman_digit[0] = one[LOG(weight)];
		roman_digit[1] = digit == 4 ? five[LOG(weight)] : one[LOG(weight*10)];
		roman_digit[2] = '\0';
		return roman_digit; 
	}

	if (digit <= 8) {
		roman_digit[0] = five[LOG(weight)];
		roman_digit[digit-4] = '\0';
		while (--digit >= 5) roman_digit[digit-4] = one[LOG(weight)];
		return roman_digit;
	}
}

/**
 * First we notice that every digit of num can correspond to a Roman string 
 * Then we notice that they only relate to the digit and its' weight
 */
char *intToRoman(int num)
{
	char *roman_num = malloc(sizeof(char) * 32);

	int weight = 1, temp = num;
	while (temp / 10) {
		weight *= 10;
		temp /= 10; // without this, we will fall into endless loop
	}
	//printf("weight=%d\n", num);

	int digit;
	int pos = 0;
	// get each digit from the high-order position
	while (num) {
		digit = num / weight;
		char *roman_digit = get_digit(digit, weight);
		//printf("digit:%d, weight:%d, roman:%s\n", digit, weight, roman_digit);
		int i = 0;
		//warn!! dont forget to write the '[i]'
		while (roman_digit[i]) roman_num[pos++] = roman_digit[i++];
		free(roman_digit);

		num %= weight;
		weight /= 10;
	}
	roman_num[pos] = '\0';

	return roman_num;
}

int main()
{
	int num;
	while (~scanf("%d", &num)) {
		char *roman = NULL;
		printf("the Roman form of integer %d is %s\n", num, roman=intToRoman(num));
		free(roman);
	}

	return 0;
}
