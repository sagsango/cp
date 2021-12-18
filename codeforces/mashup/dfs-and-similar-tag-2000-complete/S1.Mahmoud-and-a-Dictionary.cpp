/* One day there will be end of the darkness
 * Every place will be full of happiness and joy.
 */
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

const int maxn = 5e5 + 10;
vector<int>par(maxn,-1);
int root(int u){return par[u] < 0 ? u : par[u] = root(par[u]);}
void merge(int u,int v){
	if( (u=root(u)) == (v=root(v)) )return ;
	if( par[u] > par[v] )swap(u,v);
	par[u]+=par[v];
	par[v]=u;
}
int32_t main()
{
    IOS
    int n,m,q;cin>>n>>m>>q;
    vector<string>nodes(n);
    map<string,int>mp;
    for(int i=0;i<n;i++){
		cin>>nodes[i];
		mp[nodes[i]]=i;
	}
	for(int i=0;i<m;i++){
		int t;cin>>t;
		string a,b;cin>>a>>b;
		int A1 = 2*mp[a];
		int B1 = 2*mp[b];
		int A0 = 2*mp[a]+1;
		int B0 = 2*mp[b]+1;
		
		if( t== 1 ){
			if( root(A0) == root(B1) || root(A1) == root(B0) ){
				cout<<"NO"<<endl;
			}
			else{
				cout<<"YES"<<endl;
				merge(A0,B0);
				merge(A1,B1);
			}
		}
		else
		{
			if( root(A0) == root(B0) || root(A1) == root(B1) ){
				cout<<"NO"<<endl;
			}
			else{
				cout<<"YES"<<endl;
				merge(A0,B1);
				merge(A1,B0);
			}
		}
	}
	for(int i=0;i<q;i++){
		string a,b;cin>>a>>b;
		int A1 = 2*mp[a];
		int B1 = 2*mp[b];
		int A0 = 2*mp[a]+1;
		int B0 = 2*mp[b]+1;
		
		if( root(A1) == root(B1) && root(A0) == root(B0) ){
			cout<<1<<endl;
		}
		else if( root(A1)==root(B0) && root(A0)==root(B1)){
			cout<<2<<endl;
		}
		else cout<<3<<endl;
	}
   
}

				
			
	

	
			
	
	
	
	
	

	

	

	
		

