/* Given a string, find the length of the longest substring without
 * repeating characters.
 */
int lengthOfLongestSubstring(string s) {
        int max=s.length()?1:0, i =1 ;
        string buffer, substring;
        for(int j=0; j<(int)s.length(); j++){
            i=i>1?(i-1):1;
            for(; j+i<=(int)s.length(); i++){
                substring=s.substr(j, i);
                buffer=s.substr(j+i, 1);
                if(substring.find(buffer)!=string::npos){
                    max=i>max?i:max;
                    break;
                }
            }
        }
        return max;
    }