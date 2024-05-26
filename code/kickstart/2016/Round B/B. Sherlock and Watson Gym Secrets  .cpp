#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
 

const int MOD=1e9+7;
int rem(int a,int n,int m)
{
	////////////////////////////////
	////////    Corner  ////////////
	////////////////////////////////
	if( m==1 )return 0;
	
	int r=1;
	while( n )
	{
		if( n&1 )
		{
			r*=a;
			r%=m;
		}
		a*=a;
		a%=m;
		n>>=1;
	}
	return r;
}
int32_t main() {
    IOS
    int T;cin>>T;
    for(int t=1;t<=T;t++)
    {
		int a,b,n,k;cin>>a>>b>>n>>k;
		int ans=0;
		vector<int>ra(k),rb(k);
		int extra=0;
		for(int i=1;i<=k;i++)
		{
			int rema=rem(i,a,k);
			int remb=rem(i,b,k);
			ra[ rema ]+=n/k+(i<=n%k);
			rb[ remb ]+=n/k+(i<=n%k);
			ra[ rema ]%=MOD;
			rb[ remb ]%=MOD;
			if( (rema+remb)%k==0 )
			{
				extra += (n/k+(i<=n%k));
				extra %= MOD;
			}
		}
		for(int i=0;i<k;i++)
		{
			ans+=(ra[i] * rb[(k-i)%k])%MOD;
			ans%=MOD;
		}
		cout<< "Case #"<<t<<": "<<(ans-extra+MOD)%MOD<<endl;
	}
    
    
		
	
	
  
}
 
 
