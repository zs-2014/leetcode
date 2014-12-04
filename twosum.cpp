/*
Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2
 */

#include <vector>
#include <algorithm>
#include <map>
#include <iostream>
using namespace std ;

class Solution 
{
public:
    vector<int> two_sum(vector<int> &numbers, int target)
    {
        vector<int> res(2) ; 
        multimap<int, int> mp ;
        int i = 0 ;
        int sz = numbers.size() ;
        for(i=0 ;i < sz ;i++)
        {    
            multimap<int, int>::iterator it = mp.find(target - numbers[i]) ;
            if(it != mp.end())
            {  
                if(it ->second > i+1)
                {
                    res[0] = i+1;
                    res[1] = it ->second ;
                }
                else
                {
                   res[0] = it ->second; 
                   res[1] = i+1 ;
                }
                break ; 
            }
            mp.insert(std::pair<int, int>(numbers[i], i+1)) ; 
        }
       return res ; 
    }
    vector<int> twoSum(vector<int> &numbers, int target) 
    {
       vector<int> tmp(numbers) ;
       sort(tmp.begin(), tmp.end()) ; 
       int count = tmp.size() > 0 ? tmp.size()-1:0 ;
       int i = 0 ;
       vector<int> res(2) ;
       res.push_back(-1) ;
       res.push_back(-1) ;
       while(i < count)
       { 
           if(tmp[i] + tmp[count] > target)
           {
                count -= 1 ;
           }
           else if(tmp[i] + tmp[count] < target)
           {
                i += 1 ;
           }
           else
           {
              vector<int>::iterator it = find(numbers.begin(), numbers.end(), tmp[i])  ;
              int idx1 = it - numbers.begin() + 1;
              int idx2 = find((tmp[i]==tmp[count]?it+1:numbers.begin()), numbers.end(), tmp[count]) - numbers.begin() + 1 ;
              //sort the index
              if(idx1 < idx2)
              {
                  res[0] = idx1 ;
                  res[1] = idx2 ;
              }
              else
              {
                  res[0] = idx2 ; 
                  res[1] = idx1 ;
              }
              break ;
           }
       }
       return res ;
    }
};

int main(int argc, char *argv[])
{
    vector<int> numbers ;
    numbers.push_back(0) ;
    numbers.push_back(4) ;
    numbers.push_back(3) ;
    numbers.push_back(0) ;
    Solution slt ;
    vector<int> ret = slt.two_sum(numbers, 0) ;
    cout<<"index1="<<ret[0] <<" index2=" << ret[1] <<endl ;
    ret = slt.twoSum(numbers, 0) ;
    ret = slt.two_sum(numbers, 0) ;
    cout<<"index1="<<ret[0] <<" index2=" << ret[1] <<endl ;
    return 0 ;
}
