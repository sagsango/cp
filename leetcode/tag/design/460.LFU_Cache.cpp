// https://leetcode.com/problems/lfu-cache/
// See LFU_Cache.pdf


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
