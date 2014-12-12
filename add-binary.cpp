/*
Given two binary strings, return their sum (also a binary string).
For example,
a = "11"
b = "1"
Return "100"
 */
#include <iostream>
#include <string>
using namespace std ;

class Solution 
{
public:
    string addBinary(string a, string b) 
    {
        if(a.size() == 0)
        {
            return b ;
        }
        if(b.size() == 0)
        {
            return a ;
        }
        string ret ;
        int carry_val = 0 ;  
        int cnt_a = a.size() ;
        int cnt_b = b.size() ;
        int val = 0 ;
        while(cnt_a > 0 || cnt_b > 0)
        {
           val = 0 ;
           if(--cnt_a >= 0 && a[cnt_a] == '1') 
           { 
              val++;
           }
           if(--cnt_b >= 0 && b[cnt_b] == '1')
           {
              val++ ;
           }
           ret.insert(0, 1, ((val+carry_val)%2) + '0') ;
           carry_val = (val+carry_val)/2 ;
        }
        while(carry_val)
        {
            ret.insert(0, 1, (carry_val%2) + '0') ;
            carry_val /= 2 ;
        }
        return ret ;
    }
};

int main(int argc, char *argv[])
{
   Solution slt ;
   cout<<"11 + 1 = "<<slt.addBinary("11", "1") <<endl ;
   cout<<"10 + 1 = "<<slt.addBinary("10", "1") <<endl ;
   cout<<"111 + 10 = "<<slt.addBinary("111", "10") <<endl ;
   return 0 ;
}
