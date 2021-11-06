#include <iostream>
#include <string>
#include <vector>
using namespace std;
class tri{
	private:
		tri * c[2];
		int cnt;
	public:
		tri(){
			c[0] = c[1] = nullptr;
			cnt = 0;
		}
		static void insert(tri*head,int x,int cnt);
		static int query(tri*head,int x);
};
void tri::insert(tri*head,int x,int cnt){
	tri * cur = head;
	for(int i=30;i>=0;--i){
		if( cur->c[x >> i & 1] == nullptr )  cur->c[x >> i & 1] = new tri();
		cur = cur->c[ x >> i & 1];
		cur->cnt += cnt;
	}
}
int tri::query(tri * head,int x){
	tri * cur = head;
	int xmx = 0;
	for(int i=30;i>=0;--i){
		int b = x >> i & 1;
		if( cur->c[ b ^ 1 ] != nullptr  && cur->c[ b ^ 1 ]->cnt ){
			xmx |= 1<<i;
			cur = cur->c[ b ^ 1];
		}else{
			cur = cur->c[ b ^ 0];
		}
	}
	return xmx;
}


class Solution {
	private:
		vector<vector<int>>g;
		vector<vector<pair<int,int>>>q;
		vector<int>ans;
		tri * head;
		int root, n;

		void dfs(int u){
			tri::insert(head,u,+1);
			for(auto [val,i]:q[u]){
				ans[i] = tri::query(head,val);
			}
			for(auto v:g[u]){
				dfs(v);
			}
			tri::insert(head,u,-1);
		}

	public:
		vector<int> maxGeneticDifference(vector<int>& parents, vector<vector<int>>& queries) {
			n = parents.size();
			g =  vector<vector<int>>(n);
			q = vector<vector<pair<int,int>>>(n);
			ans = vector<int>(queries.size());
			head = new tri();

			for(int i=0;i<n;++i){
				if( parents[i] == -1 ){
					root = i;
					continue;
				}
				g[parents[i]].push_back(i);
			}
			for(int i=0;i<queries.size();++i){
				q[queries[i][0]].push_back({queries[i][1],i});
			}
			dfs(root);
			return ans;
		}
};
int main(){
}
