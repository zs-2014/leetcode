/*  
Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word is a valid dictionary word.

Return all such possible sentences.

For example, given
s = "catsanddog",
dict = ["cat", "cats", "and", "sand", "dog"].

A solution is ["cats and dog", "cat sand dog"]
*/

#include <string>
#include <map>
#include <vector>
#include <unordered_set>
#include <cstdio>
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
    bool do_word_break(const string &s, int start_idx, 
                       unordered_set<string> &dict, 
                       multimap<string, pair<int, bool> > &mmap,
                       vector<string > &ret_vec, string &ret_str)
    {
        if(start_idx >= s.size())
        {
            ret_vec.push_back(ret_str) ;
            return true ;
        }
        int ret_str_sz = ret_str.size() ;
        if(ret_str_sz != 0)
        {
            ret_str += ' ' ;
        }
        int flag = false ;
        string word ;
        while(start_idx < s.size())
        {
            word += s[start_idx] ;
            ret_str += s[start_idx] ;
            if(dict.find(word) != dict.end())
            {
                int is_exists = find(start_idx, word, mmap) ;
                //曾经查找过
                if(is_exists != -1)
                {
                    //更新到flag中去
                    if(is_exists && !flag)
                    {
                        flag = true ;
                    }
                    //按照此不能合理划分
                    else if(!is_exists)
                    {
                        start_idx++ ;
                        continue ;
                    }
                }
                int ret = do_word_break(s, start_idx+1, dict, mmap, ret_vec, ret_str) ;
                if(ret && !flag)
                {
                    flag = true ;
                }
                if(is_exists == -1)
                {
                    mmap.insert(pair<string, pair<int, bool> >(word, pair<int, bool>(start_idx, ret))) ;
                }
            }
            start_idx++ ;
        }
        if(ret_str_sz < ret_str.size())
        {
            ret_str.erase(ret_str_sz) ;
        }
        return flag;
    }
    vector<string> wordBreak(string s, unordered_set<string> &dict) 
    {
        vector<string> ret_vec ;
        string ret_str ;
        multimap<string, pair<int, bool> > mmap ;
        do_word_break(s, 0, dict, mmap, ret_vec, ret_str) ;
        return ret_vec ;
    }
};

int main(int argc, char *argv[])
{
    Solution slt;
    string str("catsanddog") ;
    unordered_set<string> dict({"cat", "cats", "and", "sand", "dog"}) ;
    vector<string> ret = slt.wordBreak(str, dict) ;
    int i = 0 ;
    for(i=0; i<ret.size(); i++)
    {
        printf("%s\n", ret[i].c_str()) ;
    }
    return 0  ;
}
