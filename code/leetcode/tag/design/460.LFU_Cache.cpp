// https://leetcode.com/problems/lfu-cache/
// See LFU_Cache.pdf

/*
	Design and implement a data structure for a Least Frequently Used (LFU) cache.

	Implement the LFUCache class:
		LFUCache(int capacity) Initializes the object with the capacity of the data structure.
		int get(int key) Gets the value of the key if the key exists in the cache. Otherwise, returns -1.
		void put(int key, int value) Update the value of the key if present, or inserts the key if not already present. When the cache reaches its capacity, it should invalidate 
			and remove the least frequently used key before inserting a new item. For this problem, when there is a tie (i.e., two 
			or more keys with the same frequency), the least recently used key would be invalidated.

		To determine the least frequently used key, a use counter is maintained for each key in the cache. The key with the smallest use counter is the least frequently used key.

		When a key is first inserted into the cache, its use counter is set to 1 (due to the put operation). The use counter for a key in the cache is incremented either 
		a get or put operation is called on it.

		The functions get and put must each run in O(1) average time complexity.
*/



class LFUCache {
	list<pair<int,list<pair<int,int>>>> l_List; // list<frequency, list<Key,value> > list
	unordered_map<int,list<pair<int,int>>::iterator>mp_KeyValListPtr; // map<key,list<pair<key,value>::iterator>
	unordered_map<int,list<pair<int,list<pair<int,int>>>>::iterator> mp_KeyValListHeadPtr;//map<key,list<frequency,list<pair<key,value>>::iterator>>
	int m_capacity;
	public:
	LFUCache(int capacity) {
		m_capacity = capacity;
	}

	int get(int key) {
		int return_val = -1;
		if( mp_KeyValListPtr.find(key) != mp_KeyValListPtr.end() ){

			list<pair<int,list<pair<int,int>>>>::iterator oldHeadPtr = mp_KeyValListHeadPtr[key];
			list<pair<int,list<pair<int,int>>>>::iterator newHeadPtr = oldHeadPtr; ++newHeadPtr;
			list<pair<int,int>>::iterator oldListPtr = mp_KeyValListPtr[key];

			int old_freq = oldHeadPtr->first;
			int new_freq = old_freq + 1;
			int val = oldListPtr->second;
			return_val = val;


			// make a list if next one is not present
			if( newHeadPtr ==  l_List.end() ||
					newHeadPtr->first != new_freq ){

				l_List.insert(newHeadPtr,{new_freq,{}});
				newHeadPtr = oldHeadPtr; ++newHeadPtr;
			}


			// put in new list
			newHeadPtr->second.push_back({key,val});
			list<pair<int,int>>::iterator newListPtr = --(newHeadPtr->second.end());


			// erase from old list
			oldHeadPtr->second.erase(oldListPtr);
			if( oldHeadPtr->second.empty() ){
				l_List.erase(oldHeadPtr); // always clean the space which is not being used.
			}


			// update new info for key
			mp_KeyValListHeadPtr[key] = newHeadPtr;
			mp_KeyValListPtr[key] = newListPtr;
		}
		return return_val;
	}



	void put(int key, int new_value){
		if( mp_KeyValListPtr.find(key) != mp_KeyValListPtr.end() ){

			list<pair<int,list<pair<int,int>>>>::iterator oldHeadPtr = mp_KeyValListHeadPtr[key];
			list<pair<int,list<pair<int,int>>>>::iterator newHeadPtr = oldHeadPtr; ++newHeadPtr;
			list<pair<int,int>>::iterator oldListPtr = mp_KeyValListPtr[key];


			int old_freq = oldHeadPtr->first;
			int new_freq = old_freq + 1;
			int val = oldListPtr->second;


			// make a list if next one is not present
			if( newHeadPtr ==  l_List.end() ||
					newHeadPtr->first != new_freq ){

				l_List.insert(newHeadPtr,{new_freq,{}});
				newHeadPtr = oldHeadPtr; ++newHeadPtr;
			}


			// put in new list
			newHeadPtr->second.push_back({key,new_value});
			list<pair<int,int>>::iterator newListPtr = --(newHeadPtr->second.end());


			// erase from old list
			oldHeadPtr->second.erase(oldListPtr);
			if( oldHeadPtr->second.empty() ){
				l_List.erase(oldHeadPtr); // always clean the space which is not being used.
			}


			// update new info for key
			mp_KeyValListHeadPtr[key] = newHeadPtr;
			mp_KeyValListPtr[key] = newListPtr;
		}else{
			// capacity = 0, and if we can erase something.
			if( m_capacity == 0 && !l_List.empty() ){


				// remove from LRU
				list<pair<int,list<pair<int,int>>>>::iterator HeadPtr = l_List.begin();
				list<pair<int,int>>::iterator ListPtr = HeadPtr->second.begin();
				int key = ListPtr->first;

				HeadPtr->second.erase(ListPtr);

				if( HeadPtr->second.empty() ){
					l_List.erase(HeadPtr);
				}


				// remove key info.
				mp_KeyValListHeadPtr.erase(key);
				mp_KeyValListPtr.erase(key);
				m_capacity += 1;

			}
			// If capacity is nonzero insert into LRU.
			if( m_capacity ){
				// insert into LRU
				int frequency = 1;
				list<pair<int,list<pair<int,int>>>>::iterator HeadPtr = l_List.begin();
				if( HeadPtr->first != frequency ){
					l_List.insert(HeadPtr,{frequency,{}});
					HeadPtr = l_List.begin();
				}
				HeadPtr->second.push_back({key,new_value});
				list<pair<int,int>>::iterator ListPtr = --(HeadPtr->second.end());

				mp_KeyValListHeadPtr[key] = HeadPtr;
				mp_KeyValListPtr[key] = ListPtr;

				m_capacity -= 1;
			}
		}

	}
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
