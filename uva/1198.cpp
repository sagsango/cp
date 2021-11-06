#include<bits/stdc++.h>
#define int long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

const int N = 40;
int d[N+1][N+1];
int32_t main()
{
	int n,q,v;
	string s;
	while( cin >> n )
	{
		for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		d[i][j]=(i==j?0:1e15);
		
		cin.ignore();
		for(int i=1;i<=n;i++)
		{
			getline(cin,s);
			stringstream strm(s);
			while( strm >>v )
			{
				d[i][v]=1;
				d[v][i]=1;
			}
		}
		for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		for(int k=1;k<=n;k++)
		d[j][k]=min(d[j][k],d[j][i]+d[i][k]);
		cin>>q;
		cin.ignore();
		while(q--)
		{
			getline(cin,s);
			stringstream strm(s);
			vector<int>a;
			while( strm >> v)
			{
				a.push_back(v);
			}
			set<int>st;
			for(size_t i=0;i<a.size();i++)
			{
				int u=a[i];
				for(size_t j=0;j<a.size();j++)
				{
					int v=a[j];
					for(int k=1;k<=n;k++)
					{
						if( d[u][v] == d[u][k] + d[k][v] )
						{
							st.insert(k);
						}
					}
				}
			}
			cout << (st.size()==n?"yes":"no") << endl;
		}
	}

	
}
