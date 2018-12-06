/* The string "PAYPALISHIRING" is written in a zigzag pattern on a 
 * given number of rows like this: (you may want to display this 
 * pattern in a fixed font for better legibility)
 * 
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 *
 * And then read line by line: "PAHNAPLSIIGYIR"
 */

string convert(string s, int numRows) {
	int n = s.length();
	string result;
	if (numRows == 1)
		return s;
	for (int i = 0; i<numRows; i++) {
		for (int j = 0, k = 0; i + j<n; j += (i == (numRows - 1) || i == 0) ? 
			(2 * numRows - 2) : ((!(k & 1)) ? ((numRows - i) * 2 - 2) : 2 * i), k++) {
			result.append(s, i+j, 1);
		}
	}
	return result;
}