class Solution {
public:
    static string itoa(int num)
    {
        string ret ;
        do
        {
            ret += num%10 + '0' ;
            num = num/10 ;
        }while(num != 0) ;
        reverse(ret.begin(), ret.end()) ;
        return ret ;
    }
    static bool cmp(const string &str1, const string&str2)
    {
        return ! (str1 + str2 <= str2 + str1) ;
    }
    string largestNumber(vector<int> &num) 
    {
        vector<string> num_str ;
        num_str.reserve(num.size()) ;
        int i = 0 ;
        for(i=0; i< num.size(); i++)
        {
            num_str.push_back(Solution::itoa(num[i]));
        }
        sort(num_str.begin(), num_str.end(), Solution::cmp) ;
        string ret_str ;
        for(i=0; i<num_str.size(); i++)
        {
            ret_str += num_str[i] ;
        }
        for(i=0; i< ret_str.size(); i++)
        {
            if(ret_str[i] != '0')
            {
                return ret_str ;
            }
        }
        return "0" ;
    }
};
