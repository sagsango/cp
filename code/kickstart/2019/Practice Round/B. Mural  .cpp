#include<bits/stdc++.h>
#define LL long long int 
#define LD long double
#define PI 3.14159265358979323846
#define MOD ((LL)1e9+7)
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int main()
{
	LL T;cin>>T;
	for(LL t=1;t<=T;t++)
	{
		LL n;cin>>n;
		string s;cin>>s;
		vector<LL>A(n+1);
		LL ans=0,k=(n+1)/2;
		for(LL i=0;i<n;i++)A[i+1]=s[i]-'0';
		for(LL i=1;i<=n;i++)A[i]+=A[i-1];
		for(LL i=0;i<=n-k;i++)
		ans=max(ans,A[i+k]-A[i]);
		cout<<"Case #"<<t<<":"<<" "<<ans<<endl;
	}	
}
		
