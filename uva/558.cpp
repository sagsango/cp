// Has weak test cases : if check only  cycle rechable from 0  we will get AC
// See comment of test case provider : https://www.udebug.com/UVa/558

// https://cp-algorithms.com/graph/bellman_ford.html

/*  O( n*m )  : Diected and Undirected */
/*  check cycles only reachable from source */
#include<bits/stdc++.h>
#define int long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

vector<vector<pair<int,int>>>g;
int n,m;
bool isNegtiveCycle(int s=1)
{
      vector<int>d(n+1,1e15);
      vector<int>inq(n+1);
      vector<int>cnt(n+1);
      queue<int>q;
      d[s]=0;
      inq[s]=1;
      q.push(s);
      while( q.size() )
      {
            int u=q.front();q.pop();
            inq[u]=0;
            for(auto it:g[u])
            {
                  int v=it.first;
                  int w=it.second;
                  if( d[v] > d[u] + w )
                  {
                        d[v]=d[u]+w;
                        cnt[v]++;
                        if(cnt[v]>=n)return 1;
                        if(!inq[v])
                        {
                              q.push(v);
                              inq[v]=1;
                        }
                  }
            }
      }
      return 0;
}
int32_t main()
{
	IOS
	int q;cin>>q;
	while(q--)
	{
		cin>>n>>m;
		g=vector<vector<pair<int,int>>>(n+1);
		for(int i=0;i<m;i++)
		{
			int u,v,w;cin>>u>>v>>w;
			u++;
			v++;
			g[u].push_back({v,w});
		}
		if( isNegtiveCycle() )cout<<"possible"<<endl;
		else cout << "not possible" << endl;
	}
}
