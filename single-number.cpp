/*
Given an array of integers, every element appears twice except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
*/

#include <cstdio>
class Solution 
{
public:
    int singleNumber(int A[], int n) 
    {
        if(n == 0)
        {
            return A[0] ;
        }
        while(--n > 0)
        {
            A[n-1] = A[n]^A[n-1] ;
        }
        return A[0] ;
    }
};

int main(int argc, char *argv[])
{
    Solution slt ;
    int a[] = {1,2,1,2,3} ;
    printf("single number  = %d\n", slt.singleNumber(a, 5))  ; 
    return 0 ;
}

