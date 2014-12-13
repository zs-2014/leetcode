class Solution {
public:
    int find(int idx, const string &word, multimap<int, pair<string, bool> > &mmap)
    {
        pair <multimap<int, pair<string, bool> >::iterator, multimap<int, pair<string, bool> >::iterator > ret ;
        ret = mmap.equal_range(idx) ;
        multimap<int, pair<string, bool> >::iterator it = ret.first ;
        for(; it != ret.second; ++it)
        {
            if(it ->second.first == word)
            {
                return it ->second.second == true ? 1:0 ;
            }
        }
        return -1 ;
        
    }
    bool do_word_break(const string &s, int start_idx, unordered_set<string> &dict, multimap<int, pair<string, bool> > &mmap)
    {
        if(start_idx >= s.size())
        {
            return true ;
        }
        string word ;
        while(start_idx < s.size())
        {
            word += s[start_idx] ;
            int ret = find(start_idx, word, mmap) ;
            //曾经已经查找过了，那么直接返回即可
            if(ret != -1)
            {
                return ret == 1 ?true:false ;
            }
            if(dict.find(word) != dict.end())
            {
                ret = do_word_break(s, start_idx+1, dict, mmap) ;
                mmap.insert(pair<int, pair<string, bool> >(start_idx, pair<string, bool>(word, ret == 1 ? true:false))) ;
                if(ret == true)
                {
                    return true ;
                }
            }
            start_idx++ ;
        }
        return false ;
    }
    bool wordBreak(string s, unordered_set<string> &dict) 
    {
        multimap<int, pair<string, bool> > mmap ;
        return do_word_break(s, 0, dict, mmap) ;
    }
};
