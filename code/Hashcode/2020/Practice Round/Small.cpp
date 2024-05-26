#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
	cerr << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
	const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1 << " | ";__f(comma + 1, args...);
}
#else
#define trace(...)
#endif

const int MOD = 1e9 + 7;
int power(int a,int n){
	int r=1;
	while( n ){
		if( n&1 ){
			r*=a;
			r%=MOD;
		}
		a*=a;
		a%=MOD;
		n>>=1;
	}
	return r;
}

int32_t main()
{
   IOS
   int n,m;cin>>n>>m;
   vector<int>v(m);
   for(int i=0;i<m;i++)
   cin>>v[i];
   int mxsum=0,msk=0;
   for(int i=0;i<(1LL<<m);i++)
   {
	   int sum=0;
	   for(int j=0;j<m;j++)
	   {
		   if((i>>j)&1)sum+=v[j];
	   }
	   if( sum <= n && mxsum < sum)
	   {
		   sum=mxsum;
		   msk=i;
	   }
   }
   cout<<(__builtin_popcount(msk))<<endl;
   for(int i=0;i<m;i++)
   if((msk>>i)&1)cout<<i<<" ";
   cout<<endl;
 
  
}
