class Solution {
	map<string,string>key_val;
	public:

	string evaluate(string s, vector<vector<string>>& knowledge) {
		key_val.clear();
		int n = s.length(), i = 0;
		while( i < n ){
			if( s[i] == '(' ){
				int j = i + 1;
				string key;
				while( s[j] != ')' ){
					key += s[j];
					++j;
				}
				key_val[key] = "?";
				i = j;
			}
			++i;
		}
		for(auto it:knowledge){
			string key = it[0], val = it[1];
			key_val[key] = val;
		}
		string ans = "";
		i = 0;
		while( i < n ){
			if( s[i] == '(' ){
				int j = i + 1;
				string key;
				while( s[j] != ')' ){
					key += s[j];
					++j;
				}
				ans += key_val[key];
				i = j +1;
			}else{
				ans += s[i];
				++i;
			}
		}
		return ans;

	}
};
