#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include<bits/stdc++.h>
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
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
typedef unsigned long long ul;
typedef long double ld;
typedef long long ll;
typedef vector<int> vi;
typedef vector <vi> vvi;
typedef vector<vvi> vvvi;
 
const int nax = 1e6+10, M[2] ={ (int)(1e9+7), (int)(1e9+9) }, P[2] = {29, 31};
string s;
int h[nax][2], coef[nax][2],n;
void compute(){
	coef[0][0] = coef[0][1] = 1;
	for(int i=1;i<nax;++i)
		for(int j=0;j<2;++j)
			coef[i][j]=coef[i-1][j]*P[j]%M[j];
	
	for(int i=1;i<=n;++i)
		for(int j=0;j<2;++j)
			h[i][j] = ( h[i-1][j] + ( s[i-1] - 'a' + 1 ) * coef[i-1][j] % M[j] ) % M[j];
}
int compare(int i,int j,int l){
	int ok = 1;
	for(int k=0;k<2;++k)
		ok &=  ( h[i+l-1][k] - h[i-1][k] + M[k] ) % M[k] * coef[n-i][k] % M[k] == ( h[j+l-1][k] - h[j-1][k] + M[k] ) % M[k] * coef[n-j][k] % M[k];
	return ok;
}
	
	
int32_t main(){
	IOS
	cin >> s, n = s.length();
	compute();
	for(int l=1;l<=n;++l){
		int ok = 1;
		for(int i=1;i<=n;i+=l){
			int x = min(l, n - i + 1);
			if( !compare(1,i,x) ){
				ok = 0;
				break;
			}
		}
		if( ok )
			cout << l << endl;
	}
}
		
	
