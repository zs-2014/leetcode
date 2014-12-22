/*
Given a linked list, determine if it has a cycle in it.
Follow up:
Can you solve it without using extra space?
*/


#include <cstdio>
#include <cstdlib>
using namespace std ;

//Definition for singly-linked list.
struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution 
{
public:
    bool do_has_cycle(ListNode* pre, ListNode *back)
    {
        if(back == NULL || back ->next == NULL)
        {
            return false ;
        }
        if(pre == back)
        {
            return true ;
        }
        return do_has_cycle(pre ->next, back ->next ->next) ;
        
    }
    bool hasCycle(ListNode *head) 
    {
        if(head == NULL || head ->next == NULL)
        {
            return false ;
        }
        return do_has_cycle(head, head ->next ->next) ;
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
    printf("hasCycle = %s\n", slt.hasCycle(&node1)?"YES":"NO") ;
    return 0 ;
}
