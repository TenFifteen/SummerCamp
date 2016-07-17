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

/**
 * 做了一张表，其实更简单的是做一张更大的表，一个数字对应一个罗马串， 根据权重直接return就行。
 * 当然也可以做一张更小的表，所有的做在一排，然后滑动就行。
 * 这里面利用一个性质，就是给定权重的情况下，一个数字是唯一对应一个罗马串的。并且，当数字为0
 * 的时候，返回空串。
 */
class Solution {
    public:
        string getRoman(int digit, int weight)
        {
            static string table[4] =
            {
                "IIIVIIIX",
                "XXXLXXXC",
                "CCCDCCCM",
                "MMM"
            };

            if (digit <= 3) return table[weight].substr(0, digit);
            else if (digit == 4) return table[weight].substr(2, 2);
            else if (digit <= 8) return table[weight].substr(3, digit-4);
            else return table[weight].substr(6);
        }

        string intToRoman(int num) {
            string ans;
            int weight = 0;
            while (num) {
                ans = getRoman(num % 10, weight++) + ans;
                num /= 10;
            }

            return ans;
        }
};
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
