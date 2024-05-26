#include <iostream>
#include <cstring>
#define int long long
using namespace std;	
	
	
	
	
/* Acual problem is on graph detecting cycle in 2*n-2 states */
/* And I'm glad to say that every one solved using recursive DP
 * because it too leldey process to impliment graph solution
 * FYI editorial is nicely written */
 
 
 /* And remember how graph in cycle and be solved by DP nicely */

const int maxn = 2e5+5;
int n;
int a[maxn];
int cache[maxn][2];	


int dp(int x,int sign){
	if( x <=0 || x > n )return 0;
	int &ans = cache[x][sign];
	if( ans != -1 ){
		return ans;
	}
	ans = -1e13; // If cycle found then -1e13 will be returned
	if( !sign ){
		ans=a[x] + dp(x+a[x],sign^1);
	}
	else {
		ans=a[x] + dp(x-a[x],sign^1);
	}
	return ans;
}
int32_t main(){   
	memset(cache,-1,sizeof(cache));
	cin>>n;
	for(int i=2;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n-1;i++){
		int ans = i + dp(i+1,1);
		if( ans < 0 ){
			ans=-1;
		}
		cout<<ans<<endl;
	}
}



