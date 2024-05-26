//small test cases
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
 

const int N = 2000;
vector<long double>fact(2*N+1);
vector<vector<long double>>dp;
vector<vector<bool>>vis;
int A , B ;
long double solve( int a ,int b )
{
	if( a > A || b > B )return 0;
	if( a == A && b == B )return 1;
	if( vis[a][b] )return dp[a][b];
	vis[a][b]=1;
	dp[a][b]=solve(a+1,b);
	if(b+1 < a)dp[a][b]+=solve(a,b+1);
	return dp[a][b];
}

int32_t main()
{
	IOS
	fact[0]=1;
	for(int i=1;i<=2*N;i++)
	fact[i]=i*fact[i-1];
	int T ; cin >> T;
	for(int t=1;t<=T;t++)
	{
		cin>>A>>B;
		dp=vector<vector<long double>>(A+1,vector<long double>(B+1));
		vis=vector<vector<bool>>(A+1,vector<bool>(B+1));
		long double r = solve(0,0);
		long double ans = r * fact[A] * fact[B] / fact[A+B];
		cout <<"Case #"<< t<<": "<<fixed << setprecision(10) << ans<<endl;
	}
}




//large test cases
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

const int N = 2000;
vector<vector<long double>>dp;
vector<vector<bool>>vis;
int A , B ;
long double solve( int a ,int b )
{
	if( a > A || b > B )return 0;
	if( a == A && b == B )return 1.00;
	if( vis[a][b] )return dp[a][b];
	vis[a][b]=1;
	dp[a][b]=solve(a+1,b)*(A-a)/(A-a + B-b);
	if(b+1 < a)dp[a][b]+=solve(a,b+1)*(B-b)/(A-a+B-b);
	return dp[a][b];
}

int32_t main()
{
	IOS
	int T ; cin >> T;
	for(int t=1;t<=T;t++)
	{
		cin>>A>>B;
		dp=vector<vector<long double>>(A+1,vector<long double>(B+1));
		vis=vector<vector<bool>>(A+1,vector<bool>(B+1));
		long double ans = solve(0,0);
		cout <<"Case #"<< t<<": "<<fixed << setprecision(10) << ans<<endl;
	}
}






#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;


int n , m ;
long double solve(int a,int b,vector<vector<long double>>&dp,vector<vector<int>>&vis)
{
	if( a > n || b > m || ( (a || b) && a <= b) ) return 0;
	if( a == n  && b == m ) return 1.00;
	if( vis[a][b] )return dp[a][b];
	vis[a][b]=1;
	dp[a][b]+=(1.00*(n-a)/(1.00*(n-a+m-b)))*solve(a+1,b,dp,vis);
	dp[a][b]+=(1.00*(m-b)/(1.00*(n-a+m-b)))*solve(a,b+1,dp,vis);
	return dp[a][b];
}
int32_t main()
{
	IOS
	int T ; cin >> T ;
	for(int t = 1 ; t <= T ; t++ )
	{
		cin >> n >> m;
		vector<vector<long double>>dp(n+1,vector<long double>(m+1));
		vector<vector<int>>vis(n+1,vector<int>(m+1));
		
		long double ans = solve(0,0,dp,vis);
		cout <<"Case #"<<t<<": "<< fixed << setprecision(10) << ans <<endl;
	}
}





 

 
