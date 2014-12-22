/*
Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
*/

#include <cstdio>
#include <cstdlib>
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
    bool hasPathSum(TreeNode *root, int sum) 
    {
        if(root == NULL)
        {
            return false ;
        }
        if(root ->left == NULL && root ->right == NULL && sum == root ->val)
        {
            return true ;
        }
        int ret = false ;
        if(root ->left)
        {
            if(hasPathSum(root ->left, sum - root->val))
            {
                return true ;
            }
        }
        if(root ->right)
        {
            return hasPathSum(root ->right, sum - root ->val) ;
        }
        return false ;
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
    printf("hasPathSum :%s\n", slt.hasPathSum(&node1, 22) ? "YES":"NO") ;
}
