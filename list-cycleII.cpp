/*
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
Follow up:
Can you solve it without using extra space?
*/

//Definition for singly-linked list.
#include<cstdio>
#include <cstdlib>
using namespace std ;

struct ListNode 
{
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};

class Solution 
{
public:
    ListNode *find_fist_meet_node(ListNode *pre, ListNode *back)
    {
        if(back == NULL || back ->next == NULL)
        {
            return NULL ;
        }
        if(pre == back)
        {
            return pre ;
        }
        return find_fist_meet_node(pre ->next, back ->next ->next) ;
    }
    ListNode *find_cycle_begin_node(ListNode *node1, ListNode *node2)
    {
        if(node1 == NULL || node2 == NULL)
        {
            return NULL ;
        }
        if(node1 == node2)
        {
            return node1 ;
        }
        return find_cycle_begin_node(node1 ->next, node2 ->next) ;
    }
    ListNode *detectCycle(ListNode *head) 
    {
        if(head == NULL || head ->next == NULL)
        {
            return NULL ;
        }
        return find_cycle_begin_node(head, find_fist_meet_node(head ->next, head ->next ->next)) ;
    }
};

int main(int argc, char *argv[])
{
    ListNode node1(1) ;
    ListNode node2(2) ;
    node1.next = &node2 ;
    ListNode node3(3) ;
    node2.next = &node3 ;
    ListNode node4(4) ;
    node3.next = &node4  ;
    node4.next = &node2 ;
    Solution slt ;
    printf("begin node value = %d\n", slt.detectCycle(&node1) ->val) ;
    return 0 ;
}
