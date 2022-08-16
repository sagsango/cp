/*
 * If only cost were needed then this solution
 * NOTE: any path of 3 nodes, should have diff clr in the node
 *     : so we can not clr if degree of vertex is > 2
 */

/*
#include <iostream>
#include <vector>
#define IMPOSSIBLE -1
#define INF ((long long)1e18)
using namespace std;
const int nax = 1e5+10;
vector<int> g[nax];
long long cst[nax][3], dp[nax][3], n;
// dp[ node ][ node_clr ] = min cost
inline long long min(long long x, long long y){
  return x < y ? x : y;
}
void dfs(int u,int p){
  for(int i=0;i<3;++i){
    dp[u][i] = cst[u][i];
  }
  for(auto v:g[u]){
    if( v != p ){
      dfs(v,u);
      long long mn[3] = {INF, INF, INF};
      for(int c1 = 0; c1 < 3; ++c1){
        for(int c2 = 0; c2 < 3; ++c2){
          if( c1 != c2 ){
            mn[c1] = min(mn[c1], dp[v][c2]);
          }
        }
        dp[u][c1] += mn[c1]; 
      }
    } 
  }
}

int main(){
  cin >> n;
  for(int i=0;i<3;++i){
    for(int j=1;j<=n;++j){
      cin >> cst[j][i];
    }
  }
  for(int i=1;i<=n-1;++i){
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  bool impossible = 0;
  for(int i=1;i<=n;++i){
    if( g[i].size() > 2u ){
      impossible = 1;
      break;
    }
  }
  if( impossible ){
    cout << IMPOSSIBLE << endl;
    return 0;
  }
  dfs(1,0);
  long long ans = 1e18;
  for(int i=0;i<3;++i){
    ans = min(ans, dp[1][i]);
  }
  cout << ans << endl;
  return 0;
}
*/



/*
 * TODO:
 *      To find coloring we colud backtrack the above solution
 *      Because, this is a bambu graph, [degree of  node <= 2]
 */


/*
 *
 * NOTE:
 *      Because graph is bambu and any 3 consecultive node should
 *      have diff clr, so clr will be repetion of {0,1,2} clr
 *      permutation.
 */

#include<bits/stdc++.h>
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;

const int maxn = 1e5+10;
vector<int>g[maxn],clr;
int cost[maxn][3],parity[maxn];
int n,sum;

void dfs(int u,int p,int i){
	sum+= cost[u][ clr[i] ];
	parity[u]=i;
	for(auto v:g[u]){
		if( v!= p ){
			dfs(v,u,(i+1)%3);
		}
	}
}
int32_t main(){
	cin>>n;
	for(int j=0;j<3;j++){
		for(int i=1;i<=n;i++){
			cin >> cost[i][j];
		}
	}
	for(int i=1;i<n;i++){
		int u,v;cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	int root = 1;
	for(int i=1;i<=n;i++){
		if( g[i].size() == 1u ){
			root = i;
		}
		if( g[i].size() > 2u ){
			cout << -1 << endl;
			return 0;
		}
	}
	int ans = 1e18;
	vector<int>arr={0,1,2},assign;
	do{
		clr = arr;
		sum = 0;
		dfs(root,0,0);
		if( sum < ans ){
			ans = sum;
			assign = arr;
		}

	}while( next_permutation( arr.begin() , arr.end() ) );
	cout << ans << endl;
	for(int i=1;i<=n;i++){
		cout << assign[ parity[i] ] + 1 << " ";
	}

}


