// https://leetcode.com/problems/insert-delete-getrandom-o1/

class RandomizedSet {
	int * m_arr, size;
	unordered_map<int,int>HashMap;
	public:
	RandomizedSet() {
		m_arr = new int[1000000];
		size = 0;
		HashMap.clear();
	}
	~RandomizedSet(){
		delete [] m_arr;
	}

	bool insert(int val) {
		if( HashMap.find(val) == HashMap.end() ){
			m_arr[size] = val;
			HashMap[val] = size;
			++size;
			return true;
		}
		return false;
	}


	bool remove(int val) {
		if( HashMap.find(val) != HashMap.end() ){
			int index = HashMap[val];
			HashMap.erase(val);
			if( index != size -1 ){
				m_arr[index] = m_arr[size-1];
				HashMap[m_arr[index]] = index;
			}
			--size;
			return true;
		}
		return false;
	}

	int getRandom() {
		int index = rand() % size;
		return m_arr[index];

	}
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
