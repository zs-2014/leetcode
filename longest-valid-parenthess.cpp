/*
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.
For "(()", the longest valid parentheses substring is "()", which has length = 2.
Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
*/

#include <cstdio>
#include <string>
#include <cstdlib>
#include <vector>
using namespace std ;

class Solution 
{
public:
    int longestValidParentheses(string s) 
    {
		vector<int> ret_stk;
		vector<char> tmp_stk ; 
		tmp_stk.reserve(s.size()) ;
		ret_stk.reserve(s.size()) ;
		int i = 0 ;
		int back = 0;
		for(i=0; i < s.size(); i++)
		{
			if(s[i] == '(')
			{
				tmp_stk.push_back(s[i]) ;	
				ret_stk.push_back(1) ;
			}
			else if(s[i] == ')')
			{
				//-1 == ')'
				if(tmp_stk.size() == 0)	
				{
					ret_stk.push_back(-1) ;
				}
                //说明这个括号是匹配的，但是需要从ret_stk向前找
				else if(tmp_stk.back() == '(')
				{
					tmp_stk.pop_back() ;
					// 1 == '('
					if(ret_stk.back() == 1)
					{
						back = ret_stk.size() ;
						ret_stk[ret_stk.size() - 1] = 2 ;
					}
					//匹配了，向后查找匹配的项
					else
					{
						while(--back >= 0 && ret_stk[back] != 1)	
							;
						ret_stk[back] = 2 ;
					}
				}
				else
				{
					ret_stk.push_back(-1) ;	
				}
			}
		}
		i = 0 ;
		int max_len = 0;
		int curr_len = 0 ;
		for(i=0; i< ret_stk.size(); i++)
		{
			if(ret_stk[i] != 2)
			{
				if(curr_len > max_len)	
				{
					max_len = curr_len ;
				}
				curr_len = 0 ;
			}
			else
			{
				curr_len += 2 ;
			}
		}
		return curr_len > max_len?curr_len:max_len ;
    }
};

int main(int argc, char *argv[])
{
	Solution slt ;
	string s ;
	s = "()" ;  
	printf("%s longestValidParentheses is:[%d]\n",s.c_str(), slt.longestValidParentheses(s)) ;
	s = "(()" ;
	printf("%s longestValidParentheses is:[%d]\n",s.c_str(), slt.longestValidParentheses(s)) ;
	s = "(((" ;
	printf("%s longestValidParentheses is:[%d]\n",s.c_str(), slt.longestValidParentheses(s)) ;
	s = ")))" ;
	printf("%s longestValidParentheses is:[%d]\n",s.c_str(), slt.longestValidParentheses(s)) ;
	s = "()()" ;
	printf("%s longestValidParentheses is:[%d]\n",s.c_str(), slt.longestValidParentheses(s)) ;
	s = "(()()" ;
	printf("%s longestValidParentheses is:[%d]\n",s.c_str(), slt.longestValidParentheses(s)) ;
	s = ")()())" ;
	printf("%s longestValidParentheses is:[%d]\n",s.c_str(), slt.longestValidParentheses(s)) ;
	s = ")()())()()((()))" ;
	printf("%s longestValidParentheses is:[%d]\n",s.c_str(), slt.longestValidParentheses(s)) ;
	s = ")()())()()((()))))))()()()()()()()()()))()()()" ;
	printf("%s longestValidParentheses is:[%d]\n",s.c_str(), slt.longestValidParentheses(s)) ;
	s = "()(()";
	printf("%s longestValidParentheses is:[%d]\n",s.c_str(), slt.longestValidParentheses(s)) ;
	return 0 ;
}
