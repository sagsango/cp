// https://leetcode.com/problems/insert-delete-getrandom-o1-duplicates-allowed/

class RandomizedCollection {
	int *m_arr, m_size;
	unordered_map<int,unordered_set<int> > m_hashMap;
	public:
	RandomizedCollection() {
		m_arr = new int[1000000];
		m_size = 0;
	}
	~RandomizedCollection() {
		delete [] m_arr;
	}

	bool insert(int val) {
		m_arr[ m_size ] = val;
		m_hashMap[val].insert( m_size );
		++m_size;
		return m_hashMap[val].size() == 1;

	}

	bool remove(int val) {
		if( m_hashMap.find(val) != m_hashMap.end() ){
			int index = *m_hashMap[val].begin();
			m_hashMap[val].erase(index);
			if( m_hashMap[val].empty() ){
				m_hashMap.erase(val);
			}
			if( index + 1 != m_size ){
				m_hashMap[ m_arr[ m_size -1 ]].erase( m_size -1 );
				m_arr[ index ] = m_arr[ m_size -1 ];
				m_hashMap[ m_arr[ index ] ].insert( index );
			}
			--m_size;
			return true;
		}
		return false;

	}

	int getRandom() {
		return m_arr[ rand() % m_size ];
	}
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
