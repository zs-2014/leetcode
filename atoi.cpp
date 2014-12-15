/*
Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.

Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.

spoilers alert... click to show requirements for atoi.

Requirements for atoi:
The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.

The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.

If no valid conversion could be performed, a zero value is returned. If the correct value is out of the range of representable values, INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.
*/

#include <cstring>
#include <string>
#include <cstdio>
using namespace std ;
class Solution 
{
public:

#define INT_MIN 2147483648
#define INT_MAX 2147483647

    int atoi(const char *str)
    {
        if(str == NULL || *str == '\0')    
        {
            return 0 ;
        }
        while(*str != '\0' && *str == ' ')
        {
            str++ ;
        }
        int flag = 0 ;
        if(*str == '-')
        {
           flag = 1 ; 
           str++ ;
        }
        else if(*str == '+')
        {
           str++ ; 
        }
        int err_flag = 1 ;
        long long num = 0 ;
        while(*str != '\0' && *str >= '0' && *str <= '9')
        {
            num = num*10 + *str - '0' ;
            if((flag == 0 && num > INT_MAX) || (flag == 1 && num > (long long)INT_MIN)) 
            {
                return flag == 1?INT_MIN:INT_MAX ;
            }
            err_flag = 0 ;
            str++ ;
        }
        return err_flag == 0? (flag == 1? -(int)num:(int)num):0 ;
    }
};

int main(int argc, char *argv[])
{
    Solution slt ;
    printf("%d\n", slt.atoi("1234")) ; 
    printf("%d\n", slt.atoi("-1234")) ; 
    printf("%d\n", slt.atoi("    -1234")) ; 
    printf("%d\n", slt.atoi("-1234xxxx")) ; 
    printf("%d\n", slt.atoi("-12xxx34xxxx")) ; 
    printf("%d\n", slt.atoi("-012xxx34xxxx")) ; 
    printf("%d\n", slt.atoi("-21474836480")) ; 
    printf("%d\n", slt.atoi("2147483647")) ; 
    return 0 ; 
}
