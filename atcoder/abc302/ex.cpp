#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;
/*

   Lets connect A[i] and B[i]
   Now graph will contains multiple components
   Lets say size of component = n
   			count of edges    = m

   if (m == n-1) {   Tree 
   		can take only n-1 nodes;
   } else {    Non-Tree or Tree with atleast one loop
   		can take all n nodes;
   }

   so extra edges are making the diff
   and also this extra edge will create loop
*/


/* 
   We will be using link - cut tree type data structure
*/

const int nax = 2e5+10;
vector <int> par(nax), sz(nax), loop(nax), dp(nax);
vector <int> g[nax];
int A[nax], B[nax], n, tot = 0;

int root(int u) { 
	return par[u] == u ? u : par[u] = root(par[u]); 
}

void dfs(int u, int p) {
	int a = root(A[u]), b = root(B[u]);
	if (sz[a] < sz[b])
		swap(a,b);
	/* link  */
	if (a == b) {
		loop[a] += 1;
		if (loop[a] == 1) {
			tot += 1;
		}
	} else {
		tot += 1;
		if (loop[a] && loop[b]) {
			tot -= 1;
		}
		sz[a] += sz[b];
		loop[a] += loop[b];
		par[b] = a;
	}
	
	dp[u] = tot; 

	for (auto v:g[u]) {
		if (v != p) {
			dfs(v, u);
		}
	}
	
	/* unlink */
	if (a==b) {
		if (loop[a] == 1) {
			tot -= 1;
		}
		loop[a] -= 1;
	} else {
		tot -= 1;
		sz[a] -= sz[b];
		loop[a] -= loop[b];
		par[b] = b; /* How this magic works, means all the subtree root has to be updated see root() func carefully */
		if (loop[a] && loop[b]) {
			tot -= 1;
		}
	}
}




int main() {
	cin >> n;
	for (int i=1; i<=n; ++i) {
		cin >> A[i] >> B[i];
	}
	for (int i=1; i<n; ++i) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	for (int u=1; u<=n; ++u) {
		par[u] = u;
		sz[u] = 1;
		loop[u] = 0;
		dp[u] = 0;
	}
	dfs(1,0);
	for (int i=2; i<=n; ++i) {
		cout << dp[i] << " ";
	}

}
