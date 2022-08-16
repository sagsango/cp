#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int nax = 3e5+10;
int max_len_till_node[nax], tmp_len_till_node[nax], n, m;
struct Edg{
  int u, v, w;
  bool operator<(const Edg & other)const{
    return  w < other.w;
  }
};
Edg edg[nax];
int main(){
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n >> m;
  for(int i=0;i<m;++i){
    cin >> edg[i].u >> edg[i].v >> edg[i].w;
  }
  sort(edg,edg+m);
  int i = 0, j;
  while( i < m ){
    j = i;
    while( j < m && edg[j].w == edg[i].w ){
      int u = edg[j].u;
      int v = edg[j].v;
      if( tmp_len_till_node[v] < max_len_till_node[u] + 1 ){
        tmp_len_till_node[v] = max_len_till_node[u] + 1;
      }
      ++j;
    }
    while( i != j ){
      int u = edg[i].u;
      int v = edg[i].v;
      if( max_len_till_node[v] < tmp_len_till_node[v] ){
        max_len_till_node[v] = tmp_len_till_node[v];
      }
      ++i;
    }
  }
  int max_len = 0;
  for(int i=1;i<=n;++i){
    if( max_len < max_len_till_node[i] ){
      max_len = max_len_till_node[i];
    }
  }
  cout << max_len << endl;
}


