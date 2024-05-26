#include<bits/stdc++.h>
#define LL long long int 
#define LD long double
#define PI 3.14159265358979323846
#define MOD ((LL)1e9+7)
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int main()
{
    IOS
	LL q;cin>>q;
	while(q--)
	{
		LL l,r;cin>>l>>r;
		LL n;cin>>n;
		while(l<=r)
		{
			LL m=(l+r)/2;
			cout<<m<<endl;
			fflush(stdout);
			string s;cin>>s;
			fflush(stdin);
			if(s=="CORRECT")break;
			else if(s=="TOO_SMALL")l=m+1;
			else if(s=="TOO_BIG")r=m-1;
		}
	}
			
		
		
}
		
