#include "LRUCache.h"
#include <algorithm>

using namespace std;

LRUCache::LRUCache(int capacity)
{
    this->capacity=capacity;
    size=0;
}

vector<int> LRUCache::processRequests(vector<int> requestsNo)
{
	for(vector<int>::iterator it = requestsNo.begin(); it != requestsNo.end(); ++it)
    {
		vector<int>::iterator iter=find(lru.begin(), lru.end(), *it);
	    if(size<capacity)
        {
			if(iter!=lru.end())
			{
				lru.erase(iter);
				size--;
			}
	        lru.insert(lru.begin(), *it);
	        size++;
        }
	    else
        {
			if(iter!=lru.end())
			{
				lru.erase(iter);
				lru.insert(lru.begin(), *it);
			}
			else
			{
				lru.erase(lru.end()-1);
				lru.insert(lru.begin(), *it);
			}
        }
    }
	return lru;
}

int LRUCache::getCapacity()
{
	return capacity;
}

int LRUCache::getSize()
{
	return size;
}

vector<int> LRUCache::getLRU()
{
	return lru;
}

int LRUCache::getLRUCapacity()
{
	return lru.capacity();
}

void LRUCache::setCapacity(int capacity)
{
	this->capacity=capacity;
}

void LRUCache::setLRU(vector<int> aux)
{
	lru=aux;
}
