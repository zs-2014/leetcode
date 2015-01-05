/*
Given a string S, find the longest palindromic substring in S. 
You may assume that the maximum length of S is 1000, 
and there exists one unique longest palindromic substring.
*/

#include <cstdio>
#include <string>
#include <cstdlib>
#include <vector>
using namespace std ;

class Solution 
{
public:
    bool is_palindrome(const string &s, int start_idx, int end_idx)
    {
        while(start_idx < end_idx)
        {   
            if(s[start_idx++] != s[end_idx--])
            {
                return false;
            }
        }
        return true ;
    }

    //双重循环超时
    string longestPalindrome_double_loop(string s) 
    {
        int i = 0 ;
        string ret("") ;
        for(i=0; i < s.size(); i++)
        {
            int j = i+1 ;
            //从第i+1开始，寻找最长的回文数
            for(; j < s.size(); j++)
            {
                //i -->j是否是回文数
                if(is_palindrome(s, i, j))              
                {
                    if(ret.size() <= j - i + 1) 
                    {
                        ret = s.substr(i, j-i+1) ;
                    }
                }
            }
        }
        if(ret.size() == 0 && s.size() != 0)
        {
            return s.substr(0, 1) ;
        }
        return ret ;
    }
    //这种方式是寻找回文数的中心
    string longestPalindrome(string s) 
    {
        if(s.size() == 0)
        {
            return string("") ;
        }
        int i = 1 ;
        int start_idx = -1 ;
        int end_idx = -1 ;
        for(i=0; i < s.size(); i++)
        {       
            int j = 0 ;
            //奇偶个数的处理
            for(j=0; j<2; j++)
            {
                int l = i-j ;
                if(l < 0)
                {
                    continue ;
                }
                int h = i ;
                bool flag = false;
                while(l >= 0 && h < s.size())
                {
                    if(s[l] == s[h])    
                    {
                        l-- ;
                        h++ ;
                    }
                    else
                    {
                        l++;
                        h-- ;
                        if(end_idx - start_idx <= h - l)
                        {
                            end_idx = h ;
                            start_idx = l ;
                        }
                        flag = true ;
                        break ;
                    }
                }
                if(flag == false)
                {
                    if(h == s.size() && l != -1)
                    {
                        l++ ;   
                    }
                    else if(h != s.size() && l == -1)
                    {
                        h-- ;   
                    }
                    l = l >=0?l:0 ;
                    h = h < s.size()?h:s.size()-1 ;
                    if(end_idx - start_idx <= h - l)
                    {
                        end_idx = h ;
                        start_idx = l ;
                    }
                }
            }
        }
        return s.size() == 1?s.substr(0, 1):s.substr(start_idx, end_idx - start_idx+1) ;
    }
};

int main(int argc, char *argv[])
{
    Solution slt ;
    string s ;
    s = "a" ;  
    printf("a longest palindrome is:[%s]\n", slt.longestPalindrome(s).c_str()) ;
    s = "aad" ;
    printf("aad longest palindrome is:[%s]\n", slt.longestPalindrome(s).c_str()) ;
    s = "ab" ;
    printf("ab longest palindrome is:[%s]\n", slt.longestPalindrome(s).c_str()) ;
    s = "abccb" ;
    printf("abccb longest palindrome is:[%s]\n", slt.longestPalindrome(s).c_str()) ;
    s = "bbccb" ;
    printf("bbccb longest palindrome is:[%s]\n", slt.longestPalindrome(s).c_str()) ;
    s = "bbbbb" ;
    printf("bbbbb longest palindrome is:[%s]\n", slt.longestPalindrome(s).c_str()) ;
    s = "bbbbbb" ;
    printf("bbbbbb longest palindrome is:[%s]\n", slt.longestPalindrome(s).c_str()) ;
    

    return 0 ;
}
