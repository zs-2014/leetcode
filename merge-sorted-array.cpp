/*
 Given two sorted integer arrays A and B, merge B into A as one sorted array.
 Note:
 You may assume that A has enough space (size that is greater or equal to m + n) to hold additional elements from B. The number of elements initialized in A and B are m and n respectively.
 */

#include <iostream>
#include <cstring>
using namespace std ;
class Solution 
{
public:
    void merge(int A[], int m, int B[], int n) 
    {
        if(n == 0)
        {
            return ;
        }
        if(m == 0 || A[m-1] <= B[0])          
        {
           memcpy(A+m, B, sizeof(int)*n) ;
           return ;
        }
        int *pEnd = A + m + n - 1 ;
        m -= 1 ;
        n -= 1 ;
        while(n >= 0 && m >= 0)
        {
           if(A[m] <= B[n]) 
           {
               *pEnd-- = B[n--] ;
           }
           else
           {
               *pEnd-- = A[m--] ;
           }
        }
        while(m >= 0)
        {
            *pEnd-- = A[m--] ;
        }
        while(n >= 0)
        {
            *pEnd-- = B[n--] ;
        }
  }
};

int main(int argc, char *argv[])
{
    Solution slt ;
    int A[8] = {1,2,3,4} ;
    int B[] = {1,2,3,4} ;
    slt.merge(A, 4, B, 4) ;
    int i = 0 ;
    for(i=0; i<8 ;i++)
    {
        cout<<A[i] <<"," ;
    }
    cout<<endl ;
    return 0 ;
}

