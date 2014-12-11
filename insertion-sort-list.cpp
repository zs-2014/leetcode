/*
sort a linked list using insertion sort.
*/

#include <cstdio>
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
    ListNode *do_insert(ListNode *head, ListNode *node)
    {
       if(head == NULL) 
       {
            node ->next = NULL ;
            return node ; 
       }
       //头结点直接判断，这样，以后的插入肯定是头结点之后，就不会存在更改头结点的问题了
       if(head ->val > node ->val)
       {
            node ->next = head ;
            return node ;
       }
       ListNode *cur = head ;
       ListNode *pre = head ;
       while(cur != NULL)
       {
            cur = cur ->next ;
            //从小 -------->大排序
            if(cur == NULL || cur ->val > node ->val)
            {
                break ;  
            }
            pre = cur ; 
       }
        pre ->next = node ;
        node ->next = cur ;
       return head ;
    }

    ListNode *insertionSortList(ListNode *head) 
    {
        ListNode *new_head = NULL ;
        ListNode *node = head ;
        while(head != NULL)
        {
            node = head ;
            head = head ->next ;
            node ->next = NULL ;
            new_head = do_insert(new_head, node) ;
        }
        return new_head ;
    }
};

void print_list_node(ListNode *head)
{
    while(head != NULL)
    {
        printf("%d,", head ->val) ;
        head = head ->next ;
    }
}

int main(int argc, char *argv[])
{
    Solution slt ;
    ListNode node1(3) ;
    ListNode node2(2) ;
    ListNode node3(1) ;
    ListNode node4(10) ;
    ListNode node5(2) ;
    node1.next = &node2 ;
    node2.next = &node3 ;
    node3.next = &node4;
    node4.next = &node5 ;
    node5.next = NULL ;
    print_list_node(slt.insertionSortList(&node1)) ;
    return 0 ;
}
