#include <cstdio>
#include <string>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std ;

class Solution 
{
public:
	int find(vector<int> &vec, int num)
	{
		int l = 0 ;
		int h = vec.size() ;
		while(l < h)
		{
			int mid = l + (h-l)/2 ;
			if(vec[mid] > num)
			{
				h = mid ;
			}
			else if(vec[mid] < num)
			{
				l = mid + 1 ;
			}
			else
			{
				return mid ;
			}
		}
		return -1 ;
	}
    vector<vector<int> > threeSum(vector<int> &num) 
	{
		vector<vector<int> > ret ;
		vector<int> ret_vec ;
   		if(num.size() < 3)     
		{
			return  ret ;
		}
		sort(num.begin(), num.end()) ;
		vector<int> cnt_vec ;
		vector<int> uniq_num ;
		uniq_num.push_back(num[0]) ;
		int cnt = 1 ;
		int i = 1 ;
		for(i=1; i< num.size(); i++)
		{
			if(num[i-1] != num[i])
			{
				uniq_num.push_back(num[i]) ;
				cnt_vec.push_back(cnt) ;
				cnt = 1 ;
			}
			else
			{
				cnt++ ;
			}
		}
		cnt_vec.push_back(cnt) ;
		for(i=0; i < uniq_num.size(); i++)
		{
			printf("%d ", uniq_num[i]) ;
		}
		printf("\n") ;
		for(i=0; i < uniq_num.size(); i++)
		{
			int l = i+1 ;
			int h = uniq_num.size() -1 ;
			while(l < h)
			{
				int tmp = uniq_num[i] + uniq_num[l] + uniq_num[h] ;
				if(tmp == 0)	
				{
					ret_vec.push_back(uniq_num[i]) ;
					ret_vec.push_back(uniq_num[l]) ;
					ret_vec.push_back(uniq_num[h]) ;
					ret.push_back(ret_vec) ;
					ret_vec.clear() ;
					l++;
					break ;
				}
				else if(tmp < 0)
				{
					l++;	
				}
				else
				{
					h-- ;
				}
			}
		}
		for(i=0; i< cnt_vec.size(); i++)
		{
			if(uniq_num[i] == 0 && cnt_vec[i] >= 3)
			{
				ret.push_back(vector<int>(3, 0)) ;
			}
			else if(cnt_vec[i] >= 2)
			{
				int tmp = 0 - uniq_num[i] - uniq_num[i] ;
				int idx = find(uniq_num, tmp) ;
				if(idx != -1 && idx != i)
				{
					if(uniq_num[i] < uniq_num[idx])
					{
						ret_vec.push_back(uniq_num[i]) ;	
						ret_vec.push_back(uniq_num[i]) ;
						ret_vec.push_back(uniq_num[idx]) ;
					}
					else
					{
						ret_vec.push_back(uniq_num[idx]) ;
						ret_vec.push_back(uniq_num[i]) ;	
						ret_vec.push_back(uniq_num[i]) ;
					}
					ret.push_back(ret_vec) ;
					ret_vec.clear() ; 
				}
			}
		}
		return ret ;
    }
};
int main(int argc, char *argv[])
{
	Solution slt ;
	vector<int> num ;
	//3,0,-2,-1,1,2
	num.push_back(3) ;
	num.push_back(0) ;
	num.push_back(-2) ;
	num.push_back(-1) ;
	num.push_back(1) ;
	num.push_back(2) ;
	vector<vector<int> > ret = slt.threeSum(num) ;
	int i=0 ;
	for(i=0; i< ret.size(); i++)
	{
		int j = 0; 
		for(j=0; j<ret[i].size(); j++)
		{
			printf("%d ", ret[i][j]) ;
		}
		printf("\n") ;
	}
	return 0 ;
}
