/*
Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and set.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
set(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.
*/
#include <stdio.h>
#include <list>
#include <map>
#include <algorithm>

using namespace std ;

class LRUCacheItem
{
public:
	LRUCacheItem(int key, int val)
	{
		this ->key = key ;
		this ->val = val ;
	}
public:
	int key ;
	int val ;
};

class LRUCache
{
public:
	LRUCache(int capacity) 
	{
		this ->m_capacity = capacity ;	
		this ->m_currsize = 0 ;
	}
	int get(int key) 
	{
		map<int, list<LRUCacheItem>::iterator>::iterator iter = this ->m_mp.find(key) ; 
		if(iter == this ->m_mp.end())
		{
			return -1 ;
		}
		LRUCacheItem itm = *(iter ->second) ;
		this ->m_cache.erase(iter ->second) ;
		iter ->second = this ->m_cache.insert(this ->m_cache.end(), itm) ;
		return itm.val;
	}

	void set(int key, int val)
	{
		map<int, list<LRUCacheItem>::iterator>::iterator iter = this ->m_mp.find(key) ; 
		if(iter == this ->m_mp.end())
		{
			//cache满了
			if(this ->m_currsize >= this ->m_capacity)	
			{	
				//删除栈底的元素
				//从map表中删除
				this ->m_mp.erase(this ->m_cache.begin() ->key) ;
				//从链表中删除
				this ->m_cache.erase(this ->m_cache.begin()) ;
			}
			//cache未满
			else
			{
				this ->m_currsize += 1 ;	
			}
			this ->m_mp[key] = this ->m_cache.insert(this ->m_cache.end(), LRUCacheItem(key, val)) ;
		}
		else
		{
			LRUCacheItem itm = *(iter ->second) ;
			this ->m_cache.erase(iter ->second) ;
			itm.val = val ; 
			iter ->second = this ->m_cache.insert(this ->m_cache.end(), itm) ;
		}
	}
private:
	int m_capacity ;	
	int m_currsize ; 
	map<int, list<LRUCacheItem>::iterator> m_mp ;
	list<LRUCacheItem> m_cache ;

};

int main(int argc, char *argv[])
{
	LRUCache cache(2) ;
	cache.set(2, 1) ;
	cache.set(2, 2) ;
	//cache.set(5, 6) ;
	printf("get(2) =%d\n", cache.get(2)) ;
	printf("get(3) = %d\n", cache.get(3)) ;
	cache.set(7, 8) ;
	printf("get(5) = %d\n", cache.get(5)) ;
	return 0 ;
}
