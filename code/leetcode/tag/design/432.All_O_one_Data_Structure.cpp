// https://leetcode.com/problems/all-oone-data-structure/
/*
Design a data structure to store the strings' count with the ability to return the strings with minimum and maximum counts.

Implement the AllOne class:
	AllOne() Initializes the object of the data structure.
	inc(String key) Increments the count of the string key by 1. If key does not exist in the data structure, insert it with count 1.
	dec(String key) Decrements the count of the string key by 1. If the count of key is 0 after the decrement, remove it from the data structure. It is guaranteed that key exists in the data structure before the decrement.
	getMaxKey() Returns one of the keys with the maximal count. If no element exists, return an empty string "".
	getMinKey() Returns one of the keys with the minimum count. If no element exists, return an empty string "".
*/



// TODO: complete it, or see second solution
class AllOne {
    typedef list<string>::iterator in_iterator;
    typedef list<pair<int,list<string>> out_iterator;
    list<pair<int,list<string>>m_list;
    unordered_map<string,in_iterator> m_inHashMap;
    unordered_map<string,out_iterator> m_outHashMap;

public:
    AllOne() {

    }

    void inc(string key) {
        in_iterator inIt = m_inHashMap[string];
        out_iterator outIt =  m_outHashMap[string];
        int Frequency = 1;
        if( inIt != m_inHashMap.end() ){
            Frequency = outIt->first + 1;
            outIt->second.erase(inIt);
            ++outIt;
            if( outIt == m_list.end() ){
                m_list.push_back({Frequency,{}});
                outIt = --m_list.end();
            }
            outIt->second.push_back(string);
            inIt = --(outIt->second.end());
        }else{
            if( m_list.empty() ){
                m_list.push_back({Frequency,{}});
            }
            outIt = m_list.begin();
            outIt->second.push_back(string);
            inIt = --(outIt->second.end());

        }
        m_inHashMap[string] = inIt;
        m_outHashMap[string]= outIt;
    }

    void dec(string key) {
        in_iterator inIt = m_inHashMap[string];
        out_iterator outIt =  m_outHashMap[string];
    }

    string getMaxKey() {

    }

    string getMinKey() {

    }
};





// https://leetcode.com/problems/all-oone-data-structure/discuss/1514673/C%2B%2B-map-solution
class AllOne {
	private:
		unordered_map<string, int> m_count;
		unordered_map<int, unordered_set<string>> m_keys;
	public:
		AllOne() {

		}

		void inc(string key) {
			++m_count[key];
			int new_cnt = m_count[key];
			if (new_cnt == 1)
				m_keys[1].insert(key);
			else
			{
				m_keys[new_cnt - 1].erase(key);
				if (m_keys[new_cnt - 1].empty())
					m_keys.erase(new_cnt - 1);
				m_keys[new_cnt].insert(key);
			}
		}

		void dec(string key) {
			--m_count[key];
			int new_cnt = m_count[key];
			if (new_cnt == 0)
				m_count.erase(key);
			m_keys[new_cnt + 1].erase(key);
			if (m_keys[new_cnt + 1].empty())
				m_keys.erase(new_cnt + 1);
			if (new_cnt)
				m_keys[new_cnt].insert(key);
		}

		string getMaxKey() {
			return m_keys.empty()? "": *(*m_keys.rbegin()).second.begin();
		}

		string getMinKey() {
			return m_keys.empty()? "": *(*m_keys.begin()).second.begin();
		}
};


