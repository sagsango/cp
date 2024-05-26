// https://codeforces.com/gym/276491/problem/M1 
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define bug1( x ) cout << (#x) <<"="<< x << endl;
#define bug2( x , y ) cout << (#x) <<"="<< (x) << "    " << (#y) << "="<< (y) << endl;
#define bug3( x , y , z ) cout << (#x) <<"="<<(x) << "    " << (#y) <<"="<< (y) << "    " << (#z) <<"="<< (z) << endl;
#define bug4( x , y , z , w) cout << (#x) <<"="<<(x) << "    " << (#y) <<"="<< (y) << "    " << (#z) <<"="<< (z) << "    " << (#w) <<"="<< w << endl;
#define bugn( x , n ){ cout<<(#x)<<":";for(int i=0;i<n;i++)cout<<(#x)<<"["<<i<<"]:"<< x[i] << "    "; cout<<endl;}
#define bugnm( x , n , m ){ cout<<(#x)<<endl;for(int i=0;i<n;i++){ cout<<"Row #"<<i<<":"; for(int j=0;j<m;j++) cout<<x[i][j]<<"     "; cout << endl;}}
using namespace std;	

const int maxn = 2005;
int n,root;
vector<int>C(maxn);
vector<int>subtree_size(maxn);
vector<int>g[maxn];

void dfs(int u){
	subtree_size[u]=1;
	for(auto v:g[u]){
		dfs(v);
		subtree_size[u]+=subtree_size[v];
	}
}

vector<int> build_ordering(int u){
	vector<int>order;
	for(auto v:g[u]){
		vector<int>child_ordering = build_ordering(v);
		order.insert(order.end(),child_ordering.begin(),child_ordering.end());
	}
	order.insert(order.begin()+C[u],u);
	return order;
}
int32_t main()
{
    IOS
    cin >> n;
    for(int i=1;i<=n;i++){
		int p;cin>>p>>C[i];
		if(!p) {
			root = i;
		}
		else {
			g[p].push_back(i);
		}
	}
	dfs(root);
	for(int i=1;i<=n;i++){
		if( subtree_size[i]-1 < C[i] || C[i] < 0 ){
			cout<<"NO"<<endl;return 0;
		}
	}

	vector<int>order = build_ordering(root);
	vector<int>ans(maxn);
	for(int i=0;i<n;i++){
		ans[ order[i] ]=i+1;
	}
	cout<<"YES" <<endl;
	for(int i=1;i<=n;i++){
		cout<<ans[i]<<(i < n ? ' ' : '\n' );
	}
}

				
			
	

	
			
	
	
	
	
	

	

	

	
		

