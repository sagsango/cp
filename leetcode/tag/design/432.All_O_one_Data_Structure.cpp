// https://leetcode.com/problems/all-oone-data-structure/




// https://leetcode.com/problems/all-oone-data-structure/discuss/1514673/C%2B%2B-map-solution
class AllOne {
	private:
		unordered_map<string, int> m_count;
		map<int, unordered_set<string>> m_keys;
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
