#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define bug1( x ) cerr << (#x) <<"="<< x << endl;
#define bug2( x , y ) cerr << (#x) <<"="<< (x) << "    " << (#y) << "="<< (y) << endl;
#define bug3( x , y , z ) cerr << (#x) <<"="<<(x) << "    " << (#y) <<"="<< (y) << "    " << (#z) <<"="<< (z) << endl;
#define bug4( x , y , z , w) cerr << (#x) <<"="<<(x) << "    " << (#y) <<"="<< (y) << "    " << (#z) <<"="<< (z) << "    " << (#w) <<"="<< w << endl;
#define bug5( x , y , z , w ,p) cerr << (#x) <<"="<<(x) << "    " << (#y) <<"="<< (y) << "    " << (#z) <<"="<< (z) << "    " << (#w) <<"="<< w << "    " << (#p) <<"="<< p << endl;
#define bug6( x , y , z , w ,p , q) cerr << (#x) <<"="<<(x) << "    " << (#y) <<"="<< (y) << "    " << (#z) <<"="<< (z) << "    " << (#w) <<"="<< w << "    " << (#p) <<"="<< p << "    " << (#q) <<"="<< q << endl;
#define bugn( x , n ){ cerr<<(#x)<<":";for(int i=0;i<n;i++)cout<<(#x)<<"["<<i<<"]:"<< x[i] << "    "; cout<<endl;}
#define bugnm( x , n , m ){ cerr<<(#x)<<endl;for(int i=0;i<n;i++){ cout<<"Row #"<<i<<":"; for(int j=0;j<m;j++) cout<<x[i][j]<<"     "; cout << endl;}}
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

map<int,int>dp;
vector<int>lg(1000000+1);
vector<vector<int>>st(1000000+1,vector<int>(20+1));
int solve(int x){
	if( x == 1 )return dp[1]=1;
	if( dp.count(x) )return dp[x];
	if( x % 2 ==  0 )return dp[x] = 1 + solve(x/2);
	return dp[x] = 1 + solve(3*x+1);
}
int32_t main(){
	IOS
	lg[1]=0;
	for(int i=2;i<=1000000;i++)
		lg[i]=lg[i>>1]+1;
	st[1][0]=dp[1]=1;
	for(int i=2;i<=1000000;i++)
		st[i][0]=solve(i);
	for(int i=1000000;i>=1;i--)
		for(int j=1;i+(1<<j)-1<=1000000;j++)
			st[i][j]=max(st[i][j-1],st[i+(1ll<<(j-1))][j-1]);
	int l,r;
	while( cin >> l >> r ){
		int L=l,R=r;
		if( l > r )swap(l,r);
		int k=lg[r-l+1];
		int mx = max(st[l][k],st[r-(1ll<<k)+1][k]);
		cout<<L<<" "<<R<<" "<<mx<<endl;
	}
}
