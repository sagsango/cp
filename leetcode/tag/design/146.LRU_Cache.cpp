// https://leetcode.com/problems/lru-cache/
class LRUCache {
	private:
		typedef list<pair<int,int>>::iterator LRU_ptr;
		list<pair<int,int>>LRU;
		unordered_map<int,LRU_ptr>HashMap;
		int size;
	public:
		LRUCache(int capacity) {
			size = capacity;
		}

		int get(int key) {
			if( HashMap.find(key) != HashMap.end() ){
				int val = HashMap[key]->second;
				LRU.erase(HashMap[key]);
				LRU.push_front({key,val});
				HashMap[key] = LRU.begin();
				return val;
			}
			return -1;
		}

		void put(int key, int value){
			if( HashMap.find(key) == HashMap.end() ){
				if( size == 0 ){
					int key = LRU.back().first;
					LRU.pop_back();
					HashMap.erase(key);
					++size;
				}

			}else{
				LRU_ptr ptr = HashMap[key];
				LRU.erase(ptr);
				++size;
			}
			LRU.push_front({key,value});
			HashMap[key] = LRU.begin();
			--size;
		}
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
