#include<bits/stdc++.h>
#define int long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

const int N = 26;
int d1[26][26],d2[26][26];
int T,t , m1, m2;
char u,v;
int32_t main()
{
	IOS
	cin>>T;
	for(int t=0;t<T;t++)
	{
		for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
		d1[i][j]=d2[i][j]=0;
		
		cin>>m1;
		for(int i=0;i<m1;i++)
		{
			cin>>u>>v;
			d1[u-'A'][v-'A']=1;
		}
		
		cin>>m2;
		for(int i=0;i<m2;i++)
		{
			cin>>u>>v;
			d2[u-'A'][v-'A']=1;
		}
		
		for(int k=0;k<N;k++)
		for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
		{
			d1[i][j]|=(d1[i][k]&& d1[k][j]);
			d2[i][j]|=(d2[i][k]&& d2[k][j]);
		}
		
		int ok=1;
		for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
		if(d1[i][j]!=d2[i][j])ok=0;
		
		if(t)cout<<endl;
		cout<< ( ok ? "YES" : "NO" ) << endl;
	}
		
	
		
		
		
	
	
}
	

