/*
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

For example,
Given board =

[
  ["ABCE"],
  ["SFCS"],
  ["ADEE"]
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false
*/

#include <vector>
#include <string>
#include <cstdio>
using namespace std ;

/*
其实对于一些大量数据查找，效率还可以优化！
使用map记录哪个字母在那个i,j是否已经查找过，
这样如果已经查找过了的，则就直接知道结果了，
不用再遍历了
 */
class Solution 
{
public:
    bool search(vector<vector<char> > &board, const string &word, int idx, int i, int j, vector<vector<char> > &traverse_map)
    {
        if(i < 0 || i >= board.size() || j < 0 || j >= board[i].size() || idx >= word.size() || board[i][j] != word[idx] || traverse_map[i][j] == 1)
        {
            return false ;
        }
        if(idx == word.size()-1)
        {
            return true ;
        }
        traverse_map[i][j] = 1;
        bool ret = false;
        ret = search(board, word, idx+1, i-1, j, traverse_map) ;
        if(!ret)
        {
            ret = search(board, word, idx+1, i, j+1, traverse_map) ;
        }
        if(!ret)
        {
            ret = search(board, word, idx+1, i+1, j, traverse_map) ;
        }
        if(!ret)
        {
            ret = search(board, word, idx+1, i, j-1, traverse_map) ;
        }
        traverse_map[i][j] = 0 ;
        return ret; 
    }
    bool exist(vector<vector<char> > &board, string word) 
    { 
        int i = 0 ;
        vector<vector<char> > traverse_map(board.size(), vector<char>(board[0].size(), 0)) ;
        for(i=0; i<board.size(); i++)
        {
            int j = 0 ;
            for(j=0; j<board[i].size(); j++)
            {
               //从这个位置查找
               if(board[i][j] == word[0]) 
               {
                    if(search(board, word, 0, i, j, traverse_map))
                    {
                        return true ;
                    }
               }
            }
        }
        return false ;
    }
};

int main(int argc, char *argv[])
{
    vector<vector<char> > board ;
    vector<char> row ;
    row.push_back('a') ;
    row.push_back('b') ;
    row.push_back('c') ;
    row.push_back('e') ;
    board.push_back(row) ;
    row.clear();
    row.push_back('s') ;
    row.push_back('f') ;
    row.push_back('c') ;
    row.push_back('s') ;
    board.push_back(row) ;
    row.clear();
    row.push_back('a') ;
    row.push_back('d') ;
    row.push_back('e') ;
    row.push_back('e') ;
    board.push_back(row) ;
    row.clear();
    Solution slt ;
    printf("abcced is exist %s\n", slt.exist(board, "abcced")?"YES":"NO") ;
    printf("see is exist %s\n", slt.exist(board, "see")?"YES":"NO") ;
    printf("abcb is exist %s\n", slt.exist(board, "abcb")?"YES":"NO") ;
    return 0 ;
}
