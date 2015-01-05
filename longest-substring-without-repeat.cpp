/*
Given a string, find the length of the longest substring without repeating characters. For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
*/

#include <cstdio>
#include <string>
#include <cstdlib>
using namespace std ;

class Solution 
{
public:
    int lengthOfLongestSubstring(string s) 
    { 
        int pre_cnt = 0 ;
        int curr_cnt = 0 ;
        int i = 0 ;
        int ch_map[128] = {0} ;
        for(i=0; i<sizeof(ch_map)/sizeof(int) ; i++)
        {
            ch_map[i] = -1 ;
        }
        i = 0 ;
        //区间开始的索引
        int start_idx = -1 ;
        while(i < s.size())
        {
            if(ch_map[s[i]] == -1 ||ch_map[s[i]] <= start_idx)  
            {
                curr_cnt++;
                ch_map[s[i]] = i ;
            }
            //说明前面已经有重复的了
            else
            {
                //printf("mismatch : %c pre_idx = %d curr_idx = %d\n", s[i], ch_map[s[i]], i) ;
                //这个比上一个还要长
                if(curr_cnt > pre_cnt)              
                {
                    pre_cnt = curr_cnt ;
                }
                curr_cnt = i - ch_map[s[i]] ;
                start_idx = ch_map[s[i]] ;
                //重新置为当前的索引
                ch_map[s[i]] = i ;
            }
            i++ ;
        }
        return curr_cnt > pre_cnt ? curr_cnt : pre_cnt ;
    }
};

int main(int argc, char *argv[])
{
    string s("wlrbbmqbhcdarzowkkyhiddqscdxrjmowfrxsjybldbefsarcbynecdyggxxpklorellnmpapqfwkhopkmco") ;
    printf("s.size = %d\n", s.size()) ;
    Solution slt ;
    printf("max length = %d\n", slt.lengthOfLongestSubstring(s)) ; 
    s="abcade" ;
    printf("max length = %d\n", slt.lengthOfLongestSubstring(s)) ; 
    return 0 ;
}
