class Solution {
	public:
		vector<int> canSeePersonsCount(vector<int>& h) {
			int n = h.size();
			vector<int>ans(n);
			stack<int>st;
			for(int i=n-1;i>=0;--i){
				while( st.size() && h[st.top()] < h[i]){
					ans[i] += 1;
					st.pop();
				}
				if( st.size() )
					++ans[i];
				st.push(i);
			}
			return ans;
		}
};
