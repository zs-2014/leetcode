/* 
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node. 
 */

#include <iostream>
#include <queue>
using namespace std ;


// Definition for binary tree
struct TreeNode 
{
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    int minDepth(TreeNode *root) 
    {
        if(root == NULL)
        {
            return 0 ;
        }
        queue<int> depth_q ;
        queue<TreeNode *> node_q ;
        node_q.push(root) ;
        depth_q.push(0) ;
        while(!node_q.empty())
        {
            TreeNode *node = node_q.front() ;
            node_q.pop() ;
            int parent_dpth = depth_q.front() ;
            depth_q.pop() ;
            if(node ->left == NULL && node ->right == NULL)
            {
                return parent_dpth + 1 ;
            }
            if(node ->left != NULL)
            {
                node_q.push(node ->left) ;
                depth_q.push(parent_dpth + 1) ;
            }
            if(node ->right != NULL)
            {
                node_q.push(node ->right) ;
                depth_q.push(parent_dpth + 1) ;
            }
        }
        return 0  ;
    }
};

int main(int argc, char *argv[])
{
    TreeNode root(0) ;
    TreeNode node1(1) ;
    TreeNode node2(2) ;
    TreeNode node3(3) ;
    root.left = &node1 ;
    root.right = &node2  ;
    root.right ->right = &node3 ;
    Solution slt ;
    cout<<"min depth" <<slt.minDepth(&root)<<endl ;
    root.right = NULL ;
    cout<<"min depth:"<<slt.minDepth(&root)<<endl ;
    return 0 ;
}
