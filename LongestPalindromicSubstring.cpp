/* Given a string s, find the longest palindromic substring in s. 
 * You may assume that the maximum length of s is 1000.
 */
string longestPalindrome(string s) {
        int j, k, cnt, n=(int)s.length();
        string maxSubStr;
        if(n==0)
            return "";
        else if(n==1)
            return s.substr(0,1);
        
        for(int i=0; i<n-1;i++){
            j=i, k=i+1, cnt=1;
            if(s[j]==s[k]){ // same characters
                do {
                    cnt++;
                    k++;
                }while(k<n&&s[j]==s[k]);
                j--;
            }else
                k++;
            
            while(j>=0&&k<n&&s[j]==s[k]){
                cnt+=2;
                j--;
                k++;
            } // end while
            
            if(cnt>maxSubStr.length())
                maxSubStr=s.substr(j+1, cnt);
        } // end for
        return maxSubStr;
    }