#include "bits/stdc++.h"
using namespace std;

#ifndef ONLINE_JUDGE
#include "E:\debug.h"
#define debug(...)                                                  \
    cerr << "Line:" << __LINE__ << " [" << #__VA_ARGS__ << "] = ["; \
    _print(__VA_ARGS__)
#else
#define debug(...)
#endif
#define int long long
#define endl '\n'


class dsu{
    
    public:
    
    vector<int> par;
    vector<int> sz;
    int N;
    
    
        
    dsu(int n){
        par.resize(n);
        sz.resize(n,1);
        N=0;
        for(int i=0;i<n;i++) par[i]=i;
    }
    
    int find(int a){
        if(par[a]==a) return a;
        return par[a]=find(par[a]);
    }
    
    void merge(int a,int b){
        a=find(a),b=find(b);
        
        if(a!=b){
            N++;
            if(sz[a]<sz[b]) swap(a,b);
            par[b]=a;
            sz[a]+=sz[b];
        }
    }
    
};

void Excuse_Me(int TC)
{
   int n,q;
   cin>>n>>q;
   
   vector<dsu> v;
   
   for(int i=0;i<=10;i++) v.emplace_back(n);
      
   for(int i=0;i<n-1;i++){
        int a,b,c;
        cin>>a>>b>>c;
        --a;--b;
        for(int j=c;j<=10;j++) v[j].merge(a,b);
   }

   
    
   for(int i=0;i<q;i++){
        int a,b,w;
        cin>>a>>b>>w;
        --a;--b;
        for(int j=w;j<=10;j++) v[j].merge(a,b);
        int ans=0;
        int req=n-1;
        for(int j=1;j<=10;j++){
            ans+=min(req,v[j].N-v[j-1].N)*j;
            req-=min(req,v[j].N-v[j-1].N);
        }
        cout<<ans<<endl;     
   } 
   
   
   
   
   
   
   
   
   
}
 
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("error.txt","w",stderr);
    int Tc=1;
    // cin>>Tc;
 
    for(int tc=1;tc<=Tc;tc++)
    {
        Excuse_Me(tc);
    }
   
    return 0;
}
