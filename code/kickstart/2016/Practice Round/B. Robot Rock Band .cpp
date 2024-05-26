#include<bits/stdc++.h>
#define int long long 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int32_t main()
{
	IOS
	int T;cin>>T;
	for(int t=1;t<=T;t++)
	{
		int ans=0;
		int n,k;cin>>n>>k;
		int a[4][n];
		map<int,int>M;
		for(int i=0;i<4;i++)
		for(int j=0;j<n;j++)
		cin>>a[i][j];
		
		for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		M[a[0][i]^a[1][j]]++;
		
		for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		ans+=(M.find( a[2][i] ^ a[3][j] ^ k )!=M.end() ? M[a[2][i]^a[3][j]^k] : 0);
		cout<<"Case #"<<t<<":"<<" "<< ans <<endl;
	}
		
}

	
