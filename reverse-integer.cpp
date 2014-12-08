/*
Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321

click to show spoilers.

Have you thought about this?
Here are some good questions to ask before coding. Bonus points for you if you have already thought through this!

If the integer's last digit is 0, what should the output be? ie, cases such as 10, 100.

Did you notice that the reversed integer
*/

#include <iostream>
using namespace std ;

class Solution 
{
public:
    int reverse(int x) 
    {
        int flag = false ;    
        if(x < 0)
        {
            x = -x ;
            flag = true ;
        }
        int ret = 0 ;
        while(x != 0)
        {
            if((0x80000000-x%10)/10 < ret)
            {
                return 0 ;
            }
            ret = ret*10 + x%10 ;
            x = x/10 ;
        }
        return flag ? -ret: ret ;
    }
};

int main(int argc, char *argv[])
{
    Solution slt ;     
    cout<<slt.reverse(123)<<endl ;
    cout<<slt.reverse(0) <<endl ;
    return 0 ;
}
