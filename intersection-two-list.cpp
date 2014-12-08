/*
Write a program to find the node at which the intersection of two singly linked lists begins.
For example, the following two linked lists:
A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗            
B:     b1 → b2 → b3
begin to intersect at node c1.
Notes:
If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.
Credits:
Special thanks to @stellari for adding this problem and creating all test cases. 
*/
//Definition for singly-linked list.
#include <iostream>
#include <cstdio>
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
    int length(ListNode *node)
    {
        int count = 0 ;
        while(node != NULL)
        {
            count++ ;
            node = node ->next;
        }
        return count ;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        int len_a = length(headA) ; 
        int len_b = length(headB) ;
        int i = 0 ;
        //headA比headB长
        if(len_a > len_b)
        {
            i = 0 ;
           while(i < len_a - len_b) 
           {
                headA = headA ->next ;
                i++ ;
           }
        }
        //headB比headA长
        else if(len_b > len_a)
        {
            i = 0 ;
            while(i < len_b - len_a) 
            {
                headB = headB ->next ;
                i++ ;
            }
        }
        while(headA != NULL && headB != NULL)
        {
            if(headA == headB)
            {
               return headA ; 
            }
            headA = headA ->next ;
            headB = headB ->next ;
        }
        return NULL ;
    }
};

int main(int argc, char *argv[])
{
   ListNode head1(0) ; 
   ListNode head2(1) ; 
   ListNode head3(0);
   head1.next = &head3;
   head2.next = &head3 ;
   Solution slt ;
   if(slt.getIntersectionNode(&head2, &head1) != NULL)
   { 
        cout<<"not null\n" ;
   }
   else
   {
        cout<<"null\n"  ;
   }
    return 0 ;
}
