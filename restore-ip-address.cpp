/*
Given a string containing only digits, restore it by returning all possible valid IP address combinations.

For example:
Given "25525511135",

return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
 */

/*
 *section1.section2.section3.section4
dfs搜索所有的可能性 3*3*3*3 = 81种可能 
检查ip的合理性可以放到section == 4的时候，
但是这样的话，等于是前面很多种即使不合法
的IP section 也能执行到section == 4,只不过
在section == 4的时候不合法的被排除掉了
将ip的合法性检测放到每个section，那么可以减少
一些不必要的执行
 */
#include <cstdlib>
#include <string>
#include <vector>
#include <iostream>
using namespace std ;

class Solution 
{
public:
    void restore_ip_list(const string &s, string &ret, vector<string>& ip_vec, int start_idx, int section)
    {
       int ret_size = ret.size();
       if(section == 4) 
       {
            //ip不能以0开头，如果ip不止一个数字的话
            if(s.size() - start_idx > 3 || s.size() == start_idx || (s.size() - start_idx > 1 && s[start_idx] == '0')) 
            {
                return ;
            }
            int sec_num = atoi(s.c_str() + start_idx) ;
            if(sec_num < 0 || sec_num > 255)
            {
                return ; 
            }
            ret.append(s, start_idx, s.size() - start_idx) ;
            ip_vec.push_back(ret) ;
            if(ret_size < ret.size())
            {
                ret.erase(ret_size) ;
            }
       }
       else
       {
            int i = 0 ;
            int num = 0 ;
            for(i=0; i<3; i++)
            {
                if(i + start_idx < s.size()) 
                {
                    //ip不能以0开头
                    if(i != 0 && s[start_idx] == '0')
                    {
                        break ;
                    }
                    num = num *10 + s[i+start_idx] - '0' ;
                    //如果数字不合法，则不再进行下去
                    if(num > 255 || num < 0)
                    {
                        break;
                    }
                    //添加到缓冲区中
                    ret.append(1, s[i+start_idx]) ;
                    ret.append(1, '.') ;
                    restore_ip_list(s, ret, ip_vec, start_idx + i + 1, section+1) ;
                    //当进行下一轮循环之前，得先把后缀'.'给擦除掉
                    ret.erase(ret.size()-1, 1) ;
                }
                //如果已经超过整个字符串了，那么不能够再循环下去了
                else
                {
                    break;
                }
            }
            //删除这次调用所产生的数据
            if(ret_size < ret.size())
            {    
                ret.erase(ret_size) ;
            }
       }
    }

    vector<string> restoreIpAddresses(string s) 
    {
        vector<string> ip_vec ;
        if(s.size() < 4 || s.size() > 12) 
        {
            return ip_vec ; 
        }
        //检查数字的合法性
        int i=0;
        for(i=0; i<s.size(); i++)
        {
            if(s[i] > '9' || s[i] < '0')
            {
                return ip_vec ;
            }
        }
        string ret ;
        ret.reserve(s.size()) ;
        restore_ip_list(s, ret, ip_vec, 0, 1) ;
        return ip_vec ;
    }
};

int main(int argc, char *argv[])
{
    Solution slt ;
    vector<string> ip_vec = slt.restoreIpAddresses("010010");  
    int i = 0 ;
    for(i=0; i<ip_vec.size() ;i++)
    {
        cout<<ip_vec[i]<<endl ;
    }
    return 0 ; 
}
