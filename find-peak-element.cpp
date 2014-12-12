/*A peak element is an element that is greater than its neighbors.
Given an input array where num[i] ≠ num[i+1], find a peak element and return its index.
The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.
You may imagine that num[-1] = num[n] = -∞.
For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.
click to show spoilers.
Note:
Your solution should be in logarithmic complexity.*/

#include <iostream>
#include <vector>
using namespace std ;
class Solution 
{
public:
    //这种查找方法在leetcode也能通过，但是性能明显不如find_binary
    int find(const vector<int> &num, vector<int>::size_type l, vector<int>::size_type h)
    {
        if(l >= h)
        {
            int count = 0 ;
            if(l == 0)
            {
                count++ ;
            }
            else if(num[l] > num[l-1])
            {
                count++ ;
            }
            if(l == num.size() - 1) 
            {
               count++ ; 
            }
            else if(num[l] > num[l+1])
            {
                count++ ;
            }
            if(count == 2) 
            {
                return l ;
            }
            return -1 ;
        }
        vector<int>::size_type mid = l + (h-l)/2 ;
        int idx = find(num, l, mid) ;
        if(idx == -1)
        {
            return find(num, mid+1, h) ;
        }
        else
        {
            return idx ;
        }
        //应该不会运行到这的
        return -1 ;
    }
    /*
     *这个主要是规律，在有序的数组中查找时用二分查找
     *在这里采用的也是二分查找的思想
     *[mid] < mid[mid-1]则在[0, mid-1]中查找符合的数据 
     *[mid] < mid[mid+1]则在[mid+1, n]中查找符合的数据
     *解释：
     *假设 [mid] < [mid-1] 
     *则可以保证的是已经找到了[mid-1]的一个neighbour [mid] 已经满足了要求，接下来在[0, mid-1]这个区间内
     *找即可，可能在[mid+1, n]这个区间也有，但是不能够保证而在[0, mid-1]这个区间一定能够找的到，只要相邻
     *值不相等.因为在[0, mid-1]这个区间查找时，要么就是一点一点的远离[mid-1], 这个时候是持续递增的，到了
     *第一个元素，则就是要找的元素，要么就是一点一点的靠近[mid-1]这个是持续递减的，因为持续递减，则表明在
     *这个递减的过程中，值一直都小于[mid-1]的，一旦到了持续递减，则会到了[mid-1]
     */
    int find_binary(const vector<int> &num, vector<int>::size_type l, vector<int>::size_type h)
    {
        if(h == l)
        {
            return l ;
        }
        else if(h - l == 1)
        {
            return num[h]>num[l] ?h:l ;
        }
        vector<int>::size_type mid = l + (h - l)/2 ;  
        if(num[mid] > num[mid-1] && num[mid] > num[mid+1])
        {
            return mid ;
        }
        else if(num[mid] < num[mid-1])
        {
           return find_binary(num, l, mid-1);
        }
        else
        {
            return find_binary(num, mid+1, h) ;
        }
        return -1 ;
    }
    //要考虑[-1] = [n] 等于负无穷大的情况
    int findPeakElement(const vector<int> &num) 
    {
        if(num.size() == 0)
        {
            return -1 ;
        }
        //return find(num, 0, num.size() -1) ;    
        return find_binary(num, 0, num.size() - 1) ;
    }
};

int main(int argc, char *argv[])
{
    Solution slt ;
    vector<int> num ;
    num.push_back(1) ;
    num.push_back(2) ;
    num.push_back(1) ;
    num.push_back(3) ;
    num.push_back(4) ;
    cout<<"idx = "<<slt.findPeakElement(num)<<endl ;
    return 0 ;
}
