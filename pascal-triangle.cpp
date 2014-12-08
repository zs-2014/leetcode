/* 
Given numRows, generate the first numRows of Pascal's triangle.
For example, given numRows = 5,
Return
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*/

#include <iostream>
#include <vector>
using namespace std ;

class Solution 
{
public:
    vector<vector<int> > generate(int numRows) 
    {
       vector<vector<int> > result ;
       if(numRows == 0)         
       {
            return result;
       }
       vector<int> col ;
       col.push_back(1) ;
       result.push_back(col) ;
       if(numRows == 1) 
       {
            return result ;
       }
       col.push_back(1) ;
       result.push_back(col);
       if(numRows == 2)
       {
           return result ;
       }
       int i=0 ;
       for(i=2; i< numRows; i++)
       {
            col.clear() ;
            int j=0 ;
            for(j=0; j <=i ;j++)
            {
                if(j == 0 || j == i)
                {
                    col.push_back(1) ;
                }
                else
                {
                    col.push_back(result[i-1][j-1] + result[i-1][j]) ;
                }
            } 
            result.push_back(col) ;
       }
       return result ; 
    }
};

int main(int argc, char *argv[])
{
    Solution slt ;
    vector<vector<int> > ret = slt.generate(5) ;
    int i = 0 ;
    for(i=0; i< ret.size(); i++)
    {
        int j = 0 ;
        for(j=0; j < ret[i].size(); j++)
        {
            cout<<ret[i][j] ;
        }
        cout<<endl ;
    }
    return 0  ;
}
