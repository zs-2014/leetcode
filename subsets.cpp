/*
Given a set of distinct integers, S, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If S = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std ;

class Solution 
{
public:
	void subsets(vector<vector<int> > & vec, vector<int>& s, vector<int>& ret_vec, int idx)	
	{
		while(idx < s.size())		
		{
			ret_vec.push_back(s[idx]) ;	
			subsets(vec, s, ret_vec, idx+1) ;
			ret_vec.pop_back() ;	
			idx++ ;
		}
		vec.push_back(ret_vec) ;		
	}
    vector<vector<int> > subsets(vector<int> &s) 
	{
		vector<vector<int> > vec ;
		if(s.empty())
		{
			return vec ;
		}
		sort(s.begin(), s.end()) ;  
		vector<int> ret_vec ;
	    this ->subsets(vec, s, ret_vec, 0) ;	
		return vec ;
    }
};

int main(int argc, char *argv[])
{
	vector<vector<int> > vec ;
	Solution slt ;
	vector<int> s ;
	s.push_back(2) ;
	s.push_back(3) ;
	s.push_back(4) ;
	//s.push_back(5) ;
	vec = slt.subsets(s) ;
	int i = 0 ;
	for(i=0; i< vec.size(); i++)
	{
		int j = 0 ;
		for(j=0; j < vec[i].size(); j++)
		{
			printf("%d,", vec[i][j]) ;
		}
		printf("\n") ;
	}
	return 0 ;
}
