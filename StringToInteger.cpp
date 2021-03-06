/* Implement atoi which converts a string to an integer.

The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.

The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.

If no valid conversion could be performed, a zero value is returned.

Note:

Only the space character ' ' is considered as whitespace character.
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. If the numerical value is out of the range of representable values, INT_MAX (231 − 1) or INT_MIN (−231) is returned. */

int myAtoi(string str) {
	bool sign = 0;
	int i = -1, j, result = 0;
	const int nextToMax = INT_MAX / 10;
	// get rid of the blank
	while (str.length() > 0 && str[++i] == ' ');
	// check the first non-space character
	if (str[i] == '+' || str[i] == '-')
		sign = str[i++] == '+' ? 0 : 1;
	else if (str[i] < '0' || str[i] > '9')
		return 0;
	// get count of numeric characters
	j = i;
	while (str[j] >= '0'&&str[j] <= '9')
		j++;
	// convert into integer
	while (i < j) {
		if (result > nextToMax || result == nextToMax && (sign ? (str[i] > '8') : (str[i] > '7')))
			return sign ? INT_MIN : INT_MAX;
		result = result * 10 + str[i++] - 48;
	}
	return sign ? (result*(-1)) : result;
}