/*
Given two words (start and end), and a dictionary, find all shortest transformation sequence(s) from start to end, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the dictionary
For example,

Given:
start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]
Return
  [
    ["hit","hot","dot","dog","cog"],
    ["hit","hot","lot","log","cog"]
  ]
Note:
All words have the same length.
All words contain only lowercase alphabetic characters.


先广度优先搜索每一层，一旦找到，则不再继续搜索下去，因为是要找最短的
在查找路径的时候，可以从end------>start搜索，这样可以有效的减少搜索
的量
*/

#include <vector>
#include <queue>
#include <string>
#include <unordered_set>
#include <map>
#include <algorithm>
#include <cstdio>
using namespace std ;

class Solution 
{
public:
    int cmp(const string &str1, const string &str2)
    {
        int i = 0 ;
        int cnt = 0 ;
        for(i=0 ;i<str1.size() ;i++)
        {
            if(str1[i] != str2[i])
            {
                cnt++ ;
            }
        }
        return cnt ;
    }
    void copy_path(const string &start, const string &word, int depth, vector<string>& ret_vec, 
                   const vector< unordered_set<string> > &parents_vec, vector<vector<string>> &ret) 
    {
       if(depth == 1)     
       {
            if(cmp(start, word) <= 1)
            {
                ret_vec[0] = start ; 
                ret.push_back(ret_vec) ;
            }
            return  ;
       } 
       int i=0 ;
       string tmp = word ;
       for(i=0; i< tmp.size(); i++)
       {
            char old = tmp[i] ;
            char a = 'a' ;
            for(a='a'; a<= 'z'; a++)
            {
                tmp[i] = a ;
                //只在父节点中找
                if(tmp != word && parents_vec[depth-1].find(tmp) != parents_vec[depth-1].end()) 
                {
                    ret_vec[depth-1] = tmp;
                    copy_path(start, tmp, depth-1, ret_vec, parents_vec, ret) ;
                }
            }
            tmp[i] = old ;
       }
    }

    void copy_result(const string &start, const string &end, 
                     const vector<string> &str_queue, int curr_idx, 
                     int cnt, const vector< unordered_set<string> > &parents_vec,
                     vector<vector<string>> &ret, int depth)
    {
        int flag = 0 ;
        vector<string> ret_vec ;
        if(find(str_queue.begin()+curr_idx, str_queue.begin()+curr_idx+cnt, end) != str_queue.begin() + curr_idx + cnt)
        {        
            ret_vec.resize(depth) ; 
            ret_vec[depth-1] = end ;
            copy_path(start, end, depth-1, ret_vec, parents_vec, ret) ;
            return ;
        }
        int i = 0 ; 
        ret_vec.resize(depth+1) ;
        ret_vec[depth] = end ;
        while(i < cnt) 
        {
            ret_vec[depth-1] = str_queue[i+curr_idx] ;
            if(cmp(str_queue[i+curr_idx], end) == 1)
            {
                copy_path(start, str_queue[i+curr_idx], depth-1, ret_vec, parents_vec, ret) ;
            }
            i++ ;
        }
        return ;
    }
    //广度优先搜索
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) 
    {
        vector<string> ret_vec ;
        vector<vector<string>> ret ;
        //记录每一层节点以便在查找路径时使用
        vector< unordered_set<string> > parents_vec ;
        unordered_set<string> root ;
        root.insert(start) ;
        parents_vec.push_back(root) ;
        if(cmp(start, end) <= 1)
        {
            if(start != end)
            {
                ret_vec.push_back(start) ;
                ret_vec.push_back(end) ;
                ret.push_back(ret_vec) ;
            }
            return ret ;
        }
        vector<string> str_queue ; 
        unordered_set<string> parents_set ; 
        parents_set.insert(start) ;
        str_queue.push_back(start) ;
        int curr_idx = 0 ;
        int parent_leaf_cnt = 1 ;
        int child_leaf_cnt = 1 ;
        int depth = 0 ;
        while(curr_idx < str_queue.size())
        {
           depth++ ;
           parent_leaf_cnt = child_leaf_cnt ;
           child_leaf_cnt = 0 ;
           unordered_set<string> leaf_set ;
           //一层一层的遍历节点
           while(parent_leaf_cnt > 0)
           {
                const string &word = str_queue[curr_idx] ;
                if(cmp(word, end) <= 1)
                {
                   copy_result(start, end, str_queue, curr_idx, parent_leaf_cnt, parents_vec, ret, depth) ; 
                   return ret ;
                }
                string tmp = word ;
                int i=0 ;
                for(i=0; i < tmp.size(); i++)
                {
                    char a = 'a' ; 
                    char old = tmp[i] ;
                    for(a='a'; a<='z'; a++)
                    {
                       tmp[i] = a ; 
                       //在父节点中出现过的，则不应该在后面出现
                       if(dict.find(tmp) != dict.end() && parents_set.find(tmp) == parents_set.end())
                       {
                            parents_set.insert(tmp) ;
                            if(leaf_set.find(tmp) == leaf_set.end())
                            {
                                leaf_set.insert(tmp) ;
                            }
                            str_queue.push_back(tmp) ;
                            child_leaf_cnt++ ;
                       }
                    }
                    tmp[i] = old ;
                }
                parent_leaf_cnt-- ;
                curr_idx++ ;
           }
           //记录叶子节点
           parents_vec.push_back(leaf_set) ;
        }
    }
};

int main(int argc, char *argv[])
{
    Solution slt ;
    unordered_set<string>dict({"hot","dot","dog","lot","log"}) ;
    vector<vector<string>> ret = slt.findLadders("hit", "cog", dict) ;
    int i = 0 ;
    for(i=0 ;i<ret.size() ;i++)
    {
        int j = 0 ;
        for(j=0 ;j < ret[i].size(); j++)
        {
            printf("%s,", ret[i][j].c_str()) ;
        }
        printf("\n") ;
    }
    return 0 ;
}
/*
 * 下面使用的是记住父节点的idx的方法，原本以为会快一下，没想到还慢了点！
 */
#include <vector>
#include <queue>
#include <string>
#include <unordered_set>
#include <map>
#include <algorithm>
#include <cstdio>
using namespace std ;

class Solution 
{
public:
    int cmp(const string &str1, const string &str2)
    {
        int i = 0 ;
        int cnt = 0 ;
        for(i=0 ;i<str1.size() ;i++)
        {
            if(str1[i] != str2[i])
            {
                cnt++ ;
            }
        }
        return cnt ;
    }
    void copy_path(int depth, const string &word, const vector<string>& str_queue, vector<string>& ret_vec,
                    vector<vector<string>> &ret, const map<string, vector<int>> &parent_idx_map)
    {
       const vector<int> &vec_idx = parent_idx_map.find(word) ->second ;
       int i = 0 ;
       for(i=0; i< vec_idx.size(); i++)
       {
            if(vec_idx[i] != -1)
            {
                ret_vec[depth-1] = str_queue[vec_idx[i]] ;
                copy_path(depth-1, ret_vec[depth-1], str_queue, ret_vec, ret, parent_idx_map) ;
            }
            else
            {
                ret.push_back(ret_vec) ;
            }
       }
    }

    void copy_result(int depth, const string &end, vector<vector<string>>& ret,
                    const map<string, vector<int>> &parent_idx_map, 
                    int curr_idx, int cnt, const vector<string> &str_queue)
    { 
        vector<string> ret_vec ;
        //如果最后一个词是end的话，那么depth是不一样的
        if(find(str_queue.begin() + curr_idx, str_queue.begin() + curr_idx + cnt, end) != str_queue.begin() + curr_idx + cnt)
        { 
            ret_vec.resize(depth) ;
            ret_vec[depth-1] = end ;
            copy_path(depth-1, end, str_queue, ret_vec, ret, parent_idx_map) ;
            return ;
        }
        ret_vec.resize(depth + 1) ;
        ret_vec[depth] = end ;
        int i = 0 ; 
        while(i < cnt)
        {
            if(cmp(str_queue[curr_idx+i], end) <= 1)  
            {
                ret_vec[depth-1] = str_queue[curr_idx+i] ;
                copy_path(depth-1, str_queue[curr_idx+i], str_queue, ret_vec, ret, parent_idx_map) ; 
            }
            i++ ;
        }
    }
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) 
    {
        vector<string> ret_vec ;
        vector<vector<string>> ret ;
        if(cmp(start, end) <= 1)
        {
            if(start != end)
            {
                ret_vec.push_back(start) ;
                ret_vec.push_back(end) ;
                ret.push_back(ret_vec) ;
            }
            return ret ;
        }
        map<string, int> depth_map ;
        depth_map[start] = 0 ;
        vector<string> str_queue ; 
        unordered_set<string> parents_set ; 
        map<string, vector<int> > parent_idx_map ;
        parent_idx_map[start] = vector<int>(1, -1) ;
        parents_set.insert(start) ;
        str_queue.push_back(start) ;
        int curr_idx = 0 ;
        int parent_leaf_cnt = 1 ;
        int child_leaf_cnt = 1 ;
        int depth = 0 ;
        while(curr_idx < str_queue.size())
        {
           depth++ ;
           parent_leaf_cnt = child_leaf_cnt ;
           child_leaf_cnt = 0 ;
           while(parent_leaf_cnt > 0)
           {
                const string &word = str_queue[curr_idx] ;
                if(cmp(word, end) <= 1)
                {
                    copy_result(depth, end, ret, parent_idx_map, curr_idx, parent_leaf_cnt, str_queue) ;
                    return ret ;
                }
                string tmp = word ;
                int i=0 ;
                for(i=0; i < tmp.size(); i++)
                {
                    char a = 'a' ; 
                    char old = tmp[i] ;
                    for(a='a'; a<='z'; a++)
                    {
                       tmp[i] = a ; 
                       if(dict.find(tmp) != dict.end())
                       {
                            unordered_set<string>::const_iterator p_iter = parents_set.find(tmp) ;
                            //如果这个节点没遍历过，则加入其中
                            if(p_iter == parents_set.end())
                            { 
                                parents_set.insert(tmp) ;
                                depth_map[tmp] = depth ; 
                                //记录这个单词的父节点
                                parent_idx_map[tmp] = vector<int>(1, curr_idx) ;
                                str_queue.push_back(tmp) ;
                                child_leaf_cnt++ ;
                                continue ;
                            }
                            //查找这个词所在的层次
                            map<string, int>::iterator dpt_iter = depth_map.find(tmp) ;
                            //如果这个词所在的层次小于（必然小于）当前层次，则符合
                            if (dpt_iter ->second == depth) 
                            {
                                map<string, vector<int> >::iterator idx_iter = parent_idx_map.find(tmp) ;
                                idx_iter ->second.push_back(curr_idx) ;
                            }
                       }
                    }
                    tmp[i] = old ;
                }
                parent_leaf_cnt-- ;
                curr_idx++ ;
           }
        }
    }
};

int main(int argc, char *argv[])
{
    Solution slt ;
    //unordered_set<string>dict({"hot","dot","dog","lot","log"}) ;
    //vector<vector<string>> ret = slt.findLadders("hit", "cog", dict) ;
    unordered_set<string>dict({"ted","tex","red","tax","tad","den","rex","pee"}) ;
    vector<vector<string>> ret = slt.findLadders("red", "tax", dict) ;
    int i = 0 ;
    for(i=0 ;i<ret.size() ;i++)
    {
        int j = 0 ;
        for(j=0 ;j < ret[i].size(); j++)
        {
            printf("%s,", ret[i][j].c_str()) ;
        }
        printf("\n") ;
    }
    return 0 ;
}
