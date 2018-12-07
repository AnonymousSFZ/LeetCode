/* Given a 32-bit signed integer, reverse digits of an integer.
 * Note:
 * Assume we are dealing with an environment which could only store 
 * integers within the 32-bit signed integer range: [−2^31, 2^31 − 1]. 
 * For the purpose of this problem, assume that your function returns 
 * 0 when the reversed integer overflows.
 */
 int reverse(int x) {
    bool sign=x<0?1:0;
    string output, input=to_string(x);
    output.assign(input.rbegin(), sign?(input.rend()-1):input.rend());
    while(output[0]=='0'&&output.length()>1)
        output.erase(output.begin());
    if(output.length()==10&&
        (sign?output.compare("2147483648"):output.compare("2147483647"))>=0)
        return 0;
    if(sign)
        output.insert(0, "-");
    return stoi(output);
}

int reverse(int x) {
    int result = 0, tmp;
    while (x!=0) {
        tmp = result * 10 + x % 10;
        if (result != tmp / 10)
            return 0;
        else
            result = tmp;
        x /= 10;
    }
    return result;
}

// Official Answer
int reverse(int x) {
    int rev = 0;
    while (x != 0) {
        int pop = x % 10;
        x /= 10;
        if (rev > INT_MAX/10 || (rev == INT_MAX / 10 && pop > 7)) return 0;
        if (rev < INT_MIN/10 || (rev == INT_MIN / 10 && pop < -8)) return 0;
        rev = rev * 10 + pop;
    }
    return rev;
}