// https://codeforces.com/gym/276043/problem/X2
// https://titanwolf.org/Network/Articles/Article?AID=76599b47-0656-4fe0-a007-03154a0f6950

/*
	 The meaning of problems
	 Each node is black or white, a node will change through its color, at a start node. Seeking a path such that all points black.

	 Answer
	 When dfs children of each node processed at this time if the color is white, then come back to the father node to come back, it becomes a black.
	 If No. 1 o'clock, then go to its child nodes, and then come back, go to it by children.
 */

#include <cstdio>
#define N 200005
struct edge{
    int to,next;
}e[N<<1];
int head[N],cnt;
int n,a[N];
void add(int u,int v){
    e[++cnt]=(edge){v,head[u]};
    head[u]=cnt;
}
int ans[N<<1],top;
void dfs(int x,int fa){
    ans[++top]=x;
    a[x]*=-1;
    for(int i=head[x];i;i=e[i].next){
        int v=e[i].to;
        if(v==fa)continue;
        dfs(v,x);
        ans[++top]=x;
        a[x]*=-1;
    }
    if(a[x]==-1){
        if(x!=1){
            ans[++top]=fa;
            a[fa]*=-1;
            ans[++top]=x;
            a[x]=1;
        }else{
            ans[++top]=e[head[1]].to;
            ans[++top]=1;
            ans[++top]=e[head[1]].to;
        }
    }
}
int main(){
    scanf("%d",&n);
    bool ex=0;
    for(int i=1;i<=n;++i){
        scanf("%d",&a[i]);
        if(a[i]==-1)
            ex=1;
    }
    for(int i=1,u,v;i<n;++i){
        scanf("%d%d",&u,&v);
        add(u,v);add(v,u);
    }
    if(!ex)printf("1");
    else{
        a[1]*=-1;
        dfs(1,0);
        for(int i=1;i<=top;++i)
            printf("%d ",ans[i]); 
    }
    return 0;
}
