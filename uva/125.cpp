#include<bits/stdc++.h>
#define int long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

const int N = 30;
int d[N][N];
int n,m,u,v,t=-1;
int32_t main()
{
	while( ++t,cin >> m )
	{
		n=0;
		for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
		d[i][j]=0;
		
		for(int i=0;i<m;i++)
		{
			cin>>u>>v;n=max({n,u,v});
			d[u][v]+=1;
		}
		for(int i=0;i<=n;i++)
		for(int j=0;j<=n;j++)
		for(int k=0;k<=n;k++)
		{
			d[j][k]=(d[j][k]+d[j][i]*d[i][k]);
		}
		
		 for (int k = 0; k <= n; ++k)
            // If k -> k is a cycle, then i -> k -> j must have infinite paths.
            if (d[k][k])
                for (int i = 0; i <= n; ++i)
                    for (int j = 0; j <= n; ++j)
                        if (d[i][k] && d[k][j])
                             d[i][j] = -1;
                            
		cout << "matrix for city "<<t<<endl;
		for(int i=0;i<=n;i++)
		{
			for(int j=0;j<=n;j++)
			{
				if(j)cout<<" ";
				cout<< d[i][j];
			}
			cout<<endl;
		}
	}
			
			
	

	
}
