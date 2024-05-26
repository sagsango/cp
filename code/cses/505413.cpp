#include<bits/stdc++.h>
//#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define bug1( x ) {cerr << (#x) <<"="<< x << endl;}
#define bug2( x , y ) {cerr << (#x) <<"="<< (x) << "    " << (#y) << "="<< (y) << endl;}
#define bug3( x , y , z ) {cerr << (#x) <<"="<<(x) << "    " << (#y) <<"="<< (y) << "    " << (#z) <<"="<< (z) << endl;}
#define bug4( x , y , z , w) {cerr << (#x) <<"="<<(x) << "    " << (#y) <<"="<< (y) << "    " << (#z) <<"="<< (z) << "    " << (#w) <<"="<< w << endl;}
#define bug5( x , y , z , w ,p) {cerr << (#x) <<"="<<(x) << "    " << (#y) <<"="<< (y) << "    " << (#z) <<"="<< (z) << "    " << (#w) <<"="<< w << "    " << (#p) <<"="<< p << endl;}
#define bug6( x , y , z , w ,p , q) {cerr << (#x) <<"="<<(x) << "    " << (#y) <<"="<< (y) << "    " << (#z) <<"="<< (z) << "    " << (#w) <<"="<< w << "    " << (#p) <<"="<< p << "    " << (#q) <<"="<< q << endl;}
#define bugn( x , n ) {cerr << (#x) <<":";for(int i=0;i<n;i++)cerr << x[i] <<"  "; cerr << endl;}
#define bugnm( x , n , m ) {cerr << (#x)<<endl;for(int i=0;i<n;i++){cerr << "Row #" << i<< ":";for(int j=0;j<m;j++)cerr << x[i][j] << "   ";cerr << endl;}}
typedef long long ll;
typedef long double ld;
using namespace std;
 
 
const int S = 448 , maxn = 2e5+5;
struct box{
	int l,r,i;
	bool operator <(const box other){
		if( l/S != other.l/S )return l/S < other.l/S;
		return  r < other.r;
	}
};
vector<int>a(maxn),ans(maxn),cnt(maxn);
vector<box>q(maxn);
vector<int>mp;
int n,m,tot=0;
void insert(int x){
	if( !cnt[x] )tot++;
	cnt[x]++;
}
void remove(int x){
	cnt[x]--;
	if( !cnt[x]  ){
		tot--;
	}
}
int32_t main(){
	IOS
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];mp.push_back(a[i]);
	}
	for(int i=1;i<=m;i++){
		cin>>q[i].l>>q[i].r;q[i].i=i;
	}
	sort(q.begin()+1,q.begin()+m+1);
	sort(mp.begin(),mp.end());
	mp.erase(unique(mp.begin(),mp.end()),mp.end());
	for(int i=1;i<=n;i++){
		a[i]=lower_bound(mp.begin(),mp.end(),a[i])-mp.begin()+1;
	}
	int l = 1 , r = 1;
	for(int i=1;i<=m;i++){
		while( r <= q[i].r ){
			insert(a[r++]);
		}
		while( l < q[i].l ){
			remove(a[l++]);
		}
		while( l > q[i].l ){
			insert(a[--l]);
		}
		while( r > q[i].r + 1){
			remove(a[--r]);
		}
		ans[q[i].i]=tot;
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<endl;
	}
	
	
}
/*
 * long long or int?
 * index out of bound? 
 * Tested on own test case?corner?
 * Make more general solution.
 * Read Read Read Read ....
 */

