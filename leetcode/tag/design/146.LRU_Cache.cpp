// https://leetcode.com/problems/lru-cache/
class LRUCache {
	private:
		typedef list<pair<int,int>>::iterator Lptr;
		list<pair<int,int>>LRU;
		unordered_map<int,Lptr>HashMap;
		int size;
	public:
		LRUCache(int capacity) {
			size = capacity;
		}

		int get(int key) {
			if( HashMap.find(key) != HashMap.end() ){
				int val = HashMap[key]->second;
				LRU.erase(HashMap[key]);
				LRU.push_back({key,val});
				HashMap[key] = --LRU.end();
				return val;
			}
			return -1;
		}

		void put(int key, int value){
			if( HashMap.find(key) == HashMap.end() ){
				if( size == 0 && !LRU.empty()){
					int key = LRU.begin()->first;
					LRU.pop_front();
					HashMap.erase(key);
					++size;
				}

			}else{
				Lptr ptr = HashMap[key];
				LRU.erase(ptr);
				++size;
			}
			if( size ){
				LRU.push_back({key,value});
				HashMap[key] = --LRU.end();
				--size;
			}
		}
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
