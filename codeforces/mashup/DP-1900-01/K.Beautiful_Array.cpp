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

#define __builtin_popcount __builtin_popcountll
#define sqrt sqrtl
#define cbrt cbrtl

using namespace std;

typedef unsigned long long ul;
typedef long double ld;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector <vi> vvi;
typedef vector<vvi> vvvi;



int32_t main(){
	IOS
	
	/*
	x x x x x x x x x x x x x x x x x x x x x x
	    |     |       |             |
	          i       j
	max_pos_start_at[j+1] + max_pos_end_at[i] + (psum[j]-psum[i])*x
	(max_pos_end_at[i] - psum[i]*x) + ( max_pos_start_at[j+1] + psum[j]*x)
	A + B
	find max A
	*/
	
	int n,x;cin>>n>>x;
	vector<int>a(n+1);
	vector<int>posl(n+2),posr(n+2),dp(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		dp[i]+=dp[i-1]+a[i];
	}
	
	int max_pos , curr_sum  ,  ans = 0;
	
	curr_sum = 0;
	max_pos  = 0;
	for(int i=1;i<=n;i++){
		curr_sum+=a[i];
		max_pos = max( max_pos , curr_sum );
		posl[i]= curr_sum;
		ans=max({ans,posl[i],posl[i]*x});
		if( curr_sum  < 0 ){
			curr_sum = 0;
		}
	}
	
	curr_sum = 0;
	max_pos  = 0;
	for(int i=n;i>=1;i--){
		curr_sum+=a[i];
		max_pos = max( max_pos , curr_sum );
		posr[i]= curr_sum;
		ans=max({ans,posr[i],posr[i]*x});
		if( curr_sum  < 0 ){
			curr_sum = 0;
		}
	}
	
	int mn = 0;
	for(int i=1;i<=n;i++){
		ans=max(ans,x * dp[i] - mn  + posr[i+1]);
		mn = min( mn , x * dp[i] - posl[i] );
	}
	cout << ans << endl;
	
	
	
	
}

/*
 * long long or int?
 * index out of bound? 
 * Tested on own test case?corner?
 * Make more general solution.
 * Read Read Read Read ....
 */

