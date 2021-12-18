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
    list<pair<int,list<int>>>m_list;
    unordered_map<int,list<pair<int,list<int>>>::iterator> m_mpFrequencyIt; // Frequency list
    unordered_map<int,list<int>::iterator>m_mpKeyIt; // LRU list
    unordered_map<int,int>m_mpKeyFrequency;
    int size;
public:
    LFUCache(int capacity) {
        size = 0;
    }

    int get(int key) {
        if(  m_mpKeyFrequency.find(key) != m_mpKeyFrequency.end() ){
            list<int>::iterator LRUList_it = m_mpKeyIt[key];
            list<pair<int,list<int>>>::iterator FrequencyList_it = m_mpFrequencyIt[key];
            int frequency = m_mpKeyFrequency[key];
            int value = *LRUList_it;

            int new_frequency = frequency + 1;
            list<pair<int,list<int>>>::iterator new_FrequencyList_it = FrequencyList_it; ++new_FrequencyList_it;
            if( new_FrequencyList_it == m_list.end() || new_FrequencyList_it->first > new_frequency ){
                m_list.insert(new_FrequencyList_it,{new_frequency,{}});
                --new_FrequencyList_it;
            }
            new_FrequencyList_it->second.push_front(value);
            list<int>::iterator new_LRUList_it = new_FrequencyList_it->second.begin();

						// TODO: Complete it.

        }
        return -1;
    }

    void put(int key, int value) {
			//TODO: Complete it.

    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
