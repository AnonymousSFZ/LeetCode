/* Determine whether an integer is a palindrome. An integer is 
a palindrome when it reads the same backward as forward. */

bool isPalindrome(int x) {
    vector<int> vec;
    int i=0, rep;
    if(x<0)
        return false;
    while(x){
        vec.push_back(x%10);
        x/=10;
        i++;
    }
    rep=i/2;
    for(int j=0; j<rep;j++){
        if(vec[j]!=vec[i-j-1])
            return false;
    }
    return true;
}

bool isPalindrome(int x) {
    int reverse=0;
    if(x<0 || x>9&&x%10==0)
        return 0;
    while(x>reverse){
        reverse=reverse*10+x%10;
        x/=10;
    }
    return x==reverse||x==reverse/10;
}