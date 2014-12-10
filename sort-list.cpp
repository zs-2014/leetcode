/*
Sort a linked list in O(n log n) time using constant space complexity.
*/

#include <ctime>
#include <cstdlib>
#include <cstdio>
using namespace std ;

//Definition for singly-linked list.
struct ListNode 
{
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

typedef ListNode list_node_t ;

class Solution 
{
public:
    //查找中间元素的时候，back指针每次走一步， front指针每次走两步
    list_node_t * find_middle_node(list_node_t *start_node, list_node_t *end_node)
    {
        list_node_t *front = start_node ;
        list_node_t *back = start_node ;
        while(front != end_node)
        {
           front = front ->next;
           if(front != end_node)
           {
                front = front ->next ;
           }
           else
           {
               return back ;
           }
           back = back ->next ;
        }
        return back ;
    }

    //和对数组进行归并排序的思想一样
    list_node_t *merge_sort(list_node_t *low_node, list_node_t *high_node)
    {
        if(low_node == NULL || high_node == NULL)
        {
            return NULL ;
        }
        if(low_node == high_node)    
        {
            low_node ->next = NULL ;
            return low_node; 
        }
        list_node_t *mid_node = find_middle_node(low_node, high_node) ;
        list_node_t *mid_next = mid_node ->next ;
        low_node = merge_sort(low_node, mid_node);
        //mid_next 不能使用mid_node->next代替，因为在merge_sort(low_node, mid_node) 的过程中，mid_node ->next 可能会被置空
        mid_node = merge_sort(mid_next, high_node) ;
        //合并操作
        list_node_t *cur = NULL ;
        list_node_t *head = NULL ;
        list_node_t *tmp = NULL ;
        //从小 ----->大排序
        //leetcode 上规定的是从小到大，否则提交不过
        while(low_node != NULL && mid_node != NULL)
        {
            tmp = NULL ;
            if(low_node ->val< mid_node ->val) 
            {
                tmp = mid_node ; 
                mid_node = mid_node ->next ;
            }
            else
            {
               tmp = low_node ;
               low_node = low_node ->next ;
            }
            if(head != NULL)
            {
                cur ->next = tmp ;
                cur = tmp ;
            }
            else
            {
                head = cur = tmp ;
            }
        }
        while(low_node != NULL)
        {
            cur ->next = low_node ;
            cur = cur ->next ;
            low_node = low_node ->next ;
        }
        while(mid_node != NULL)
        {
            cur ->next = mid_node ;
            cur = cur ->next ;
            mid_node = mid_node ->next ;
        }
        if(cur != NULL)
        {
            cur ->next = NULL ;
        }
        return head ;
    }
    //原本c写的，不想改，就留这了
    list_node_t *sort(list_node_t *head)
    {
        if(head == NULL)    
        {
            return NULL;
        }
        list_node_t *tail = head ;
        while(tail ->next != NULL)
        {
            tail = tail ->next ;
        }
        return merge_sort(head, tail) ;
    }
    ListNode *sortList(ListNode *head) 
    {
        return sort(head) ;        
    }
};

void print_list(list_node_t *head)
{
    while(head != NULL)
    {
        printf("%d,", head ->val) ;
        head = head ->next ;
    }
    printf("\n") ;
}

list_node_t *create_list(int num)
{
    list_node_t *head = NULL ;
    list_node_t *cur = NULL ;
    int i = 0 ;
    srand(time(NULL)) ;
    for(i=0 ;i<num ;i++)
    {
        if(head != NULL)                
        {
           cur ->next = (list_node_t *)malloc(sizeof(list_node_t)) ; 
           cur = cur ->next ;
           cur ->val = rand()%num ;
           cur ->next = NULL ;
        }
        else
        {
            head = cur = (list_node_t *)malloc(sizeof(list_node_t)) ;
            cur ->val = rand()%num ;
            cur ->next = NULL ;
        }
    }
    return head ;
}

void free_list(list_node_t *head)
{
    list_node_t *tmp = head ; 
    while(head != NULL)
    {
        tmp = head ->next ;
        free(head) ;
        head = tmp ;
    }
}

int main(int argc, char *argv[])
{
    Solution slt ;
    list_node_t *head = create_list(11) ;
    print_list(head) ;
    print_list(slt.sortList(head)) ;
    free(head) ;
    return 0 ;
}
