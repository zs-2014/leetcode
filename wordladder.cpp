/*Given two words (start and end), and a dictionary, find the length of shortest transformation sequence from start to end, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the dictionary
For example,

Given:
start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]
As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

Note:
Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
*/
/*
    从end开始，在集合中查找和end相差一个字符的end1, end1和start相比，如果相等，那么查找完毕，就是start ->end1 ->end是最短的
    如果end1和start不相等，那么问题就转化成了start 转化到end1需要的最少的步骤 + 1(end1 ->end),此时的问题和最初的问题又一样了，
    只不过每取出一个，可用集合里就少一个字符而已
    在每次找和endn相差一个字符的单词不存在时，表示此路行不通，因为每次只能改变一个字符  
    start ->end = start ->end1 ->end
    f(start, endn) = f(start, endn-1)+1
    性能太差了
*/

#include <iostream>
#include <unordered_set>
#include <map>
#include <string>
#include <vector>
#include <queue>
using namespace std ;

class Solution 
{
public:
    bool cmp(const string &str1, const string &str2)
    {    
        int i = 0 ;
        int diff_cnt = 0;
        for(i=0; i<str1.size(); i++)
        {
            if(str1[i] != str2[i]) 
            {
                diff_cnt++ ;
            }
            if(diff_cnt > 1)
            {
                return false ;
            }
        }
        return diff_cnt == 1 ? true : false ;
    }
    //在lst中查找相差一个字母的单词
    int find(const string & src, unordered_set<string> &dict, vector<string> &vec)
    {
        unordered_set<string>::iterator it = dict.begin() ;
        while(it != dict.end())
        {
            if(cmp(src, *it))
            {
                vec.push_back(*it) ;
                it = dict.erase(it) ;
                continue ;
            }
            ++it ;
        }
        return vec.size()  ;
    }
    //这一种算法，性能太差时间总是超时
    int do_ladder_length(string &start, string &end, unordered_set<string> &dict, map<string, int> &mp)
    {
        map<string, int>::iterator mpit = mp.find(start+end) ;
        if(mpit != mp.end())
        {
            return mpit ->second ;
        }
        if(cmp(start, end))
        {
            mp[start+end] = 2 ;
            return 2 ;
        }
        vector<string> vec ;
        find(start, dict, vec) ; 
        int len = 0 ;
        vector<string>::iterator it = vec.begin() ;
        while( it != vec.end())
        {
            int l = do_ladder_length(*it, end, dict, mp) ; 
            if(l != 0)
            { 
                    if(len == 0)
                    {
                       len = l ; 
                    }
                    else
                    {
                        len = len>l?l:len ;
                    }
            }
            ++it;
        }
        dict.insert(vec.begin(), vec.end()) ;
        if(len != 0)
        {
            mp[start + end] = len + 1;
        }
        else
        {
            mp[start + end] = 0 ;
        }
        return len == 0?0:len+1;
    }

    int ladderLength(string start, string end, unordered_set<string> &dict) 
    { 
        //map<string, int> mp ;
        //return do_ladder_length(start, end, dict, mp) ;
        map<string, int> mp ;
        mp[start] = 1 ;
        queue<string> q ;
        q.push(start) ;
        while(!q.empty())
        { 
            string word = q.front() ;
            q.pop() ; 
            //已经找到了
            if(cmp(word, end))
            {
                return mp[word] + 1 ;
            }
            //采用注释中的寻找方法的话，还是会超时
            //unordered_set<string>::iterator it = dict.begin() ;
            //while(it != dict.end())
            //{
                //相差了一个字符
              //  if(cmp(word, *it))    
               // {
                    //在mp中不应该出现
                //    if(mp.find(*it) == mp.end())
                 //   {
                  //      q.push(*it) ; 
                   //     mp[*it] = mp[word] + 1 ;
                   // }
                //}
                //++it ;
            //}
            string tmp = word ;
            int i = 0 ;
            for(i=0 ;i < word.size() ;i++)
            {
                char old = tmp[i] ;
                char c = 'a' ;
                for(c='a'; c<'z'; c++)
                {
                   tmp[i] = c ;
                   if(dict.find(tmp) != dict.end() && mp.find(tmp) == mp.end()) 
                   {
                        q.push(tmp) ;
                        mp[tmp] = mp[word] + 1 ;
                   }
                }
                tmp[i] = old ;
            }
            //    ++it ;
            //}
        }
        return q.empty()?0:mp[end] ;
    }
};

int main(int argc, char *argv[])
{
    unordered_set<string> order_set({"hot","dot","dog","lot","log"}) ;
    Solution slt ;
    cout<<"min length:"<<slt.ladderLength("hit", "cog", order_set) ;
}
