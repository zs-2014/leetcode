/* 
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element
*/
#include <cstdio>
#include <stack>
using namespace std ;

class MinStack 
{
public:
    void push(int x) 
    {
        val_stk.push(x) ;
        if(min_val_stk.empty() || x <= min_val_stk.top())
        {
            min_val_stk.push(x) ;
        }
    }
    void pop() 
    {
        int top = val_stk.top() ;
        val_stk.pop() ;
        if(top == min_val_stk.top())
        {
            min_val_stk.pop() ;
        }
    }

    int top() 
    {
        return val_stk.top() ;
    }

    int getMin() 
    {
        return min_val_stk.top() ;
    }

private:
    stack<int> val_stk ;
    stack<int> min_val_stk ;
};

int main(int argc, char *argv[])
{
   MinStack min_stack ;  
   min_stack.push(1) ;
   min_stack.push(0) ;
   min_stack.push(3) ;
   min_stack.push(0) ;
   printf("min = %d top = %d\n", min_stack.getMin(), min_stack.top()) ;
   min_stack.pop() ;
   printf("min = %d top = %d\n", min_stack.getMin(), min_stack.top()) ;
}
