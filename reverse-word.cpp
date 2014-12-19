/*
Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the".

click to show clarification.

Clarification:
What constitutes a word?
A sequence of non-space characters constitutes a word.
Could the input string contain leading or trailing spaces?
Yes. However, your reversed string should not contain leading or trailing spaces.
How about multiple spaces between two words?
Reduce them to a single space in the reversed string
*/
#include <string>
#include <cstdio>
using namespace std ;

class Solution 
{
public:
    void reverse_word(string &s, int start_idx, int end_idx)
    {
        for(; start_idx < end_idx ; ++start_idx, --end_idx) 
        {
            char c = s[start_idx]  ;       
            s[start_idx] = s[end_idx] ;
            s[end_idx] = c ;
        }
    }
    
    void reverse(string &s)
    {
        string tmp;
        tmp.reserve(s.size()) ;
        int cnt = s.size();
        int start_idx = -1 ;
        while(--cnt >= 0)
        {
           if(s[cnt] != ' ') 
           {
                if(start_idx == -1)
                {
                    start_idx = tmp.size() ; 
                }
                tmp.push_back(s[cnt]) ;
           }
           else
           {
                //如果前面一个不是space，那么添加进去，否则删除这儿space
                if(tmp.size() > 0 && tmp[tmp.size()-1] != ' ')
                {
                    reverse_word(tmp, start_idx, tmp.size()-1) ;
                    tmp.push_back(' ') ;
                    start_idx = -1 ;
                }
           }
        }
        if(start_idx != -1)
        {
            reverse_word(tmp, start_idx, tmp.size() -1) ;
        }
        if(tmp.size() > 0 && tmp[tmp.size()-1] == ' ')
        {
            tmp.erase(tmp.size()-1) ;
        }
        s = tmp ;
    }
    void reverseWords(string &s) 
    {
        reverse(s);
    }
};

int main(int argc, char *argv[])
{
    Solution slt ;
    string str("   th e     sky is blue") ;
    slt.reverseWords(str) ;
    printf("reverse =  [%s]\n", str.c_str()) ;
    return 0 ; 
}
