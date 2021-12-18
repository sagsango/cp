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
#define bug5( x , y , z , w , k) cout << (#x) <<"="<<(x) << "    " << (#y) <<"="<< (y) << "    " << (#z) <<"="<< (z) << "    " << (#w) <<"="<< w  << "    " << (#k) <<"="<< k <<endl;
#define bugn( x , n ){ cout<<(#x)<<":";for(int i=0;i<n;i++)cout<<(#x)<<"["<<i<<"]:"<< x[i] << "    "; cout<<endl;}
#define bugnm( x , n , m ){ cout<<(#x)<<endl;for(int i=0;i<n;i++){ cout<<"Row #"<<i<<":"; for(int j=0;j<m;j++) cout<<x[i][j]<<"     "; cout << endl;}}
using namespace std;	


const int maxn = 5000+5;
vector<string>s(maxn);
vector<int>par(maxn,-1);
vector<int>clr(maxn);
int n;
void dfs(int u,int p){
	clr[u]=1;
	par[u]=p;
	for(int v=0;v<n;v++){
		if(s[u][v]=='0')continue;
		if(!clr[v]){
			dfs(v,u);
		}
		else if( clr[v]==1 && par[u]!=-1 && s[v][par[u]]=='1'){
			cout<<v+1<<" "<<par[u]+1<<" "<<u+1<<endl;
			exit(0);
		}
	}
	clr[u]=2;
}
int32_t main()
{
    IOS
    cin>>n;
    for(int i=0;i<n;i++){
		cin>>s[i];
	}
	for(int i=0;i<n;i++){
		if( clr[i]==0  ){
			dfs(i,-1);
		}
	}
	cout << -1 << endl;
}

				
			
	

	
			
	
	
	
	
	

	

	

	
		

