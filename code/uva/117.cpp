// More general :    https://codeforces.com/gym/258375/my
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

string s;
int u , v ,cnt;
vector<vector<pair<int,int>>>g;
void addedge(string s)
{
	cnt+=s.length();
	u=s.front()-'a';
	v=s.back()-'a';
	g[u].push_back({v,s.length()});
	g[v].push_back({u,s.length()});
}
int32_t main()
{
	//IOS
	while(cin>>s)
	{
		cnt =0;
		g=vector<vector<pair<int,int>>>(26);
		addedge(s);
		while( cin>>s && s!="deadend")
		{
			addedge(s);
		}
		int source = -1 , terminal = -1;
		for(int i=0;i<26;i++)
		{
			if(g[i].size()&1)
			{
				if(source==-1)source=i;
				else terminal=i;
			}
		}
		if( source==-1 )cout << cnt << endl;
		else
		{
			/*SPFA*/
			vector<int>d(26,1e15);
			vector<int>inq(26);
			queue<int>q;
			d[source]=0;
			q.push(source);
			inq[source]=1;
			while(q.size())
			{
				int u=q.front();q.pop();
				inq[u]=0;
				for(auto it:g[u])
				{
					int v=it.first;
					int w=it.second;
					if( d[v] > d[u]+w )
					{
						d[v]=d[u]+w;
						if(!inq[v])
						{
							q.push(v);
							inq[v]=1;
						}
					}
				}
			}
			cout << cnt + d[terminal] <<endl;
		
		}
					
				
	}
	
	
}
