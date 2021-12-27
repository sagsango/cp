#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
	cerr << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
	const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1 << " | ";__f(comma + 1, args...);
}
#else
#define trace(...)
#endif

const int MOD = 1e9 + 7;
int power(int a,int n){
	int r=1;
	while( n ){
		if( n&1 ){
			r*=a;
			r%=MOD;
		}
		a*=a;
		a%=MOD;
		n>>=1;
	}
	return r;
}
vector<int>path;
void _fill(vector<vector<pair<int,int>>>&par,int x,int y);
void _fill(vector<vector<pair<int,int>>>&par,int x,int y){
	if(x==0 && y==0)return;
	int px=par[x][y].first;
	int py=par[x][y].second;
	if(y!=py && x!=px)
	{
		path.push_back(x-1);
	}
	_fill(par,px,py);
}
int32_t main()
{
   IOS
   int n,m;cin>>n>>m;
   vector<int>a(m);
   for(int i=0;i<m;i++)
   cin>>a[i];
   vector<vector<int>>dp(m+1,vector<int>(n+1));
   vector<vector<pair<int,int>>>par(m+1,vector<pair<int,int>>(n+1));
   dp[0][0]=1;
   for(int i=0;i<m;i++)
   {
	   for(int j=0;j<=n;j++){
		   dp[i+1][j]=dp[i][j];
		   par[i+1][j]={i,j};
	   }
	   for(int j=0;j+a[i]<=n;j++){
		   if(dp[i+1][j+a[i]]==0 && dp[i][j])
		   {
			   dp[i+1][j+a[i]]=1;
			   par[i+1][j+a[i]]={i,j};
		   }
	   }
   }
   for(int i=n;i>=0;i--){
	   if(dp[m][i])
	   {
		 _fill(par,m,i);
		  break;
	   }
   }
   cout<<path.size()<<endl;
   reverse(path.begin(),path.end());
   for(int i=0;i<path.size();i++)
   cout<<path[i]<<" ";
   cout<<endl;
   
 
  
}
