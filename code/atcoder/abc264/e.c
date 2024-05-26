#include <stdio.h>
const int nax = 5e5;
struct Edg{
  int u, v;
  int broke;
};
int par[nax], pwr[nax], cnt[nax], brk[nax], tot[nax];
struct Edg edg[nax];
int n, m, e, q, x, ans;
void swap(int *x,int *y){
  *x ^= *y;
  *y ^= *x;
  *x ^= *y;
}
int root(int u){ return par[u] < 0 ? u : (par[u] = root(par[u])); } 
void merge(int u,int v){
  if ( (u=root(u)) == (v=root(v)) )
    return;

  if( par[u] > par[v] )
    swap(&u,&v);
  par[u] += par[v];
  cnt[u] += cnt[v];
  pwr[u] |= pwr[v];
  par[v] = u;
}

int main(){
  scanf("%d %d %d", &n, &m, &e);
  for(int i=0;i<n+m;++i){
    par[i] = -1;
    pwr[i] = i >= n;
    cnt[i] = i < n;
  }
  for(int i=0;i<e;++i){
    scanf("%d %d", &edg[i].u, &edg[i].v);
    edg[i].u -=1;
    edg[i].v -=1;
  }
  scanf("%d",&q);
  for(int i=0;i<q;++i){
    scanf("%d",&x);
    edg[x-1].broke = 1;
    brk[i] = x -1;
  }
  for(int i=0;i<e;++i){
    if( ! edg[i].broke ){
      merge(edg[i].u, edg[i].v);
    }
  }
  for(int i=0;i<n;++i){
    if( pwr[root(i)] ){
      ++ans;
    }
  }
  for(int i=q-1;i>=0;--i){

    tot[i] = ans;
    
    int x = root(edg[brk[i]].u);
    int y = root(edg[brk[i]].v);


    if( x == y )
      continue;

    ans -= cnt[x] * pwr[x];

    ans -= cnt[y] * pwr[y];


    merge(edg[brk[i]].u, edg[brk[i]].v);

    int z = root(edg[brk[i]].u);

    ans += cnt[z] * pwr[z];

  }
  
  for(int i=0;i<q;++i){
    printf("%d\n", tot[i]);
  }
}
