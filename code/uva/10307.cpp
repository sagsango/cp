#include<bits/stdc++.h>
#define int long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
 
const int N = 50 * 50;
vector<int>par(N+1);
vector<int>dis(N+1);
vector<int>vis(N+1);
int root(int v){return par[v] < 0 ? v : (par[v] = root(par[v]));}
void merge(int x,int y){	//	x and y are some tools (vertices)
        if((x = root(x)) == (y = root(y)) )    return ;
	if(par[y] < par[x])	// balancing the height of the tree
		swap(x, y);
	par[x] += par[y];
	par[y] = x;
}

struct Box{
	int u , v , w;
	bool operator <(Box other){
		return w  < other.w ;
	}
};
vector<Box>edges;
int q,m,n;

int dx[4]={+1,-1,+0,-0};
int dy[4]={+0,-0,+1,-1};
vector<string>g(N);

void bfs(int x,int y)
{
	fill(vis.begin(),vis.begin()+n*m,0);
	dis[x*m+y]=0;
	vis[x*m+y]=1;
	
	queue<int>q;
	q.push({x*m+y});
	while( q.size() )
	{
		int u = q.front();q.pop();
		int ux= u/m;
		int uy= u%m;
		if( g[ux][uy] == 'A' || g[ux][uy] == 'S' )
		{
			edges.push_back({x*m+y,ux*m+uy,dis[ux*m+uy]});
		}
		for(int i=0;i<4;i++)
		{
			int vx = ux + dx[i];
			int vy = uy + dy[i];
			if( vx < n && vx >=0 && vy < m && vy >=0 && g[vx][vy]!='#'  && !vis[vx*m+vy] )
			{
				vis[vx*m+vy]=1;
				dis[vx*m+vy]=dis[ux*m+uy]+1;
				q.push(vx*m+vy);
			}
		}
	}
}
	
int kruskals()
{
	    /* Kruskal's */
		fill(par.begin(),par.begin()+n*m,-1);
		sort(edges.begin(),edges.end());
		int cost=0;
		for(size_t i=0;i<edges.size();i++)
		{
			int u = edges[i].u;
			int v = edges[i].v;
			int w = edges[i].w;
			
			if( root(u) != root(v) )
			{
				cost+=w;
				merge(u,v);
			}
		}
		return cost;
}

int32_t main()
{
	IOS	
	cin>>q;
	while(q--)
	{
		cin>>m>>n;
		cin.ignore();
		for(int i=0;i<n;i++)
		{
			getline(cin,g[i]);
		}
			
		edges.clear();
		for(int x=0;x<n;x++)
		for(int y=0;y<m;y++)
		{
			if( g[x][y] == 'S' || g[x][y] == 'A' )
			{
				bfs(x,y);
			}
		}
		cout << kruskals() << endl;
	}
}
					
		
		
		
		
	
	

