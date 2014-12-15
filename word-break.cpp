/*
Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

For example, given
s = "leetcode",
dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code".
*/

#include <string>
#include <map>
#include <unordered_set>
#include <iostream>
using namespace std ;
class Solution {
public:
    int find(int idx, const string &word, multimap<string, pair<int, bool> > &mmap)
    {
        pair <multimap<string, pair<int, bool> >::iterator, multimap<string, pair<int, bool> >::iterator > ret ;
        ret = mmap.equal_range(word) ;
        multimap<string, pair<int, bool> >::iterator it = ret.first ;
        for(; it != ret.second; ++it)
        {
            if(it ->second.first == idx)
            {
                return it ->second.second == true ? 1:0 ;
            }
        }
        return -1 ;
        
    }
    bool do_word_break(const string &s, int start_idx, unordered_set<string> &dict, multimap<string, pair<int, bool> > &mmap)
    {
        if(start_idx >= s.size())
        {
            return true ;
        }
        string word ;
        while(start_idx < s.size())
        {
            word += s[start_idx] ;
            int ret = find(start_idx, word, mmap) ;
            //曾经已经查找过了，那么直接返回即可
            if(ret != -1)
            {
                return ret == 1 ?true:false ;
            }
            if(dict.find(word) != dict.end())
            {
                ret = do_word_break(s, start_idx+1, dict, mmap) ;
                mmap.insert(pair<string, pair<int, bool> >(word, pair<int, bool>(start_idx, ret == 1 ? true:false))) ;
                if(ret == true)
                {
                    return true ;
                }
            }
            start_idx++ ;
        }
        return false ;
    }
    bool wordBreak(string s, unordered_set<string> &dict) 
    {
        multimap<string, pair<int, bool> > mmap ;
        return do_word_break(s, 0, dict, mmap) ;
    }
};

int main(int argc, char *argv[])
{
    Solution slt;
    string str("bb") ;
    unordered_set<string> dict({"b", "bb", "aa"}) ;
    cout<<"ret = "<<slt.wordBreak(str, dict)<<endl ;
    str = "bba" ;
    cout<<"ret = "<<slt.wordBreak(str, dict)<<endl ;
    return 0  ;
}
