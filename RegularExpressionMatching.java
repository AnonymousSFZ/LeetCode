/*
 * @lc app=leetcode.cn id=10 lang=java
 *
 * [10] 正则表达式匹配
 *
 * https://leetcode-cn.com/problems/regular-expression-matching/description/
 *
 * algorithms
 * Hard (20.67%)
 * Total Accepted:    8.9K
 * Total Submissions: 43K
 * Testcase Example:  '"aa"\n"a"'
 *
 * 给定一个字符串 (s) 和一个字符模式 (p)。实现支持 '.' 和 '*' 的正则表达式匹配。
 * 
 * '.' 匹配任意单个字符。
 * '*' 匹配零个或多个前面的元素。
 * 
 * 
 * 匹配应该覆盖整个字符串 (s) ，而不是部分字符串。
 * 
 * 说明:
 * 
 * 
 * s 可能为空，且只包含从 a-z 的小写字母。
 * p 可能为空，且只包含从 a-z 的小写字母，以及字符 . 和 *。
 * 
 * 
 * 示例 1:
 * 
 * 输入:
 * s = "aa"
 * p = "a"
 * 输出: false
 * 解释: "a" 无法匹配 "aa" 整个字符串。
 * 
 * 
 * 示例 2:
 * 
 * 输入:
 * s = "aa"
 * p = "a*"
 * 输出: true
 * 解释: '*' 代表可匹配零个或多个前面的元素, 即可以匹配 'a' 。因此, 重复 'a' 一次, 字符串可变为 "aa"。
 * 
 * 
 * 示例 3:
 * 
 * 输入:
 * s = "ab"
 * p = ".*"
 * 输出: true
 * 解释: ".*" 表示可匹配零个或多个('*')任意字符('.')。
 * 
 * 
 * 示例 4:
 * 
 * 输入:
 * s = "aab"
 * p = "c*a*b"
 * 输出: true
 * 解释: 'c' 可以不被重复, 'a' 可以被重复一次。因此可以匹配字符串 "aab"。
 * 
 * 
 * 示例 5:
 * 
 * 输入:
 * s = "mississippi"
 * p = "mis*is*p*."
 * 输出: false
 * 
 */
class Solution {
    public boolean isMatch(String s, String p) {
        if(p.length()==0)
    		return s.length()==0;
        // return false if s is not null while pattern string is.
		if(s.length()!=0&&p.charAt(0)==s.charAt(0)||p.charAt(0)=='.'&&s.length()!=0){
            // if s[0] == p[0] or p[0] == '.'
            // then skip "x" in s or "x*" in pattern string
	        if(p.length()>1&&p.charAt(1)=='*')
	            return isMatch(s.substring(1), p)||isMatch(s, p.substring(2));
	        else
	            return isMatch(s.substring(1), p.substring(1));
	    }else{
            // if s[0] != p[0] and p[0]!='.'
            // then s and p is a match only if p[1] == '*'
	        if(p.length()>1&&p.charAt(1)=='*')
	            return isMatch(s, p.substring(2));
	        else
	            return false;
	    }
    }
}
