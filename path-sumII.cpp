/*
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return
[
   [5,4,11,2],
   [5,8,4,5]
]
*/
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std ;

//Definition for binary tree
struct TreeNode 
{
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution 
{
public:
    void do_path_sum(TreeNode *root, int sum, vector< vector<int> > &ret, vector<int>&ret_vec)
    {
        if(root == NULL)
        {
            return ;
        }
        if(root ->left == NULL && root ->right == NULL && root ->val == sum)
        {
            ret_vec.push_back(sum) ;
            ret.push_back(ret_vec) ;
            ret_vec.pop_back() ;
            return ;
        }
        if(root ->left)
        {
            ret_vec.push_back(root ->val) ;
            do_path_sum(root ->left, sum - root ->val, ret, ret_vec) ;
            ret_vec.pop_back() ;
        }
        if(root ->right)
        {
            ret_vec.push_back(root ->val) ;
            do_path_sum(root ->right, sum-root ->val, ret, ret_vec) ;
            ret_vec.pop_back() ;
        }
    }
    vector<vector<int> > pathSum(TreeNode *root, int sum) 
    {
        vector<vector<int> > ret ;
        vector<int> ret_vec ;
        if(root == NULL)
        {
            return ret;
        }
        do_path_sum(root, sum, ret, ret_vec) ;
        return ret ;
    }
};

int main(int argc, char *argv[])
{
    TreeNode node1(5) ; 
    TreeNode node2(4) ;
    node1.left = &node2 ;
    TreeNode node3(11) ;
    node2.left = &node3 ;
    TreeNode node4(7) ;
    node3.left = &node4 ; 
    TreeNode node5(2) ; 
    node3.right = &node5 ;
    TreeNode node6(8) ;
    node1.right = &node6 ;
    TreeNode node7(13) ;
    node6.left = &node7 ;
    TreeNode node8(4) ;
    node6.right = &node8 ;
    TreeNode node9(1) ;
    node8.right = &node9 ;
    Solution slt ;
    vector<vector<int> > ret = slt.pathSum(&node1, 22) ;
    int i = 0 ;
    for(i=0; i<ret.size(); i++)
    {
        int j = 0 ;
        for(j=0; j<ret[i].size(); j++)
        {
            printf("%d,", ret[i][j]) ;
        }
        printf("\n") ;
    }
    return 0 ;
}
