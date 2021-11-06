#include<bits/stdc++.h>
#define int long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;


int32_t main()
{
	IOS
	int T;cin>>T;
	for(int t=1;t<=T;t++)
	{
		int m;cin>>m;
		long double tm;cin>>tm;
		vector< long double > v(m);
		for(int i=0;i<m;i++)
		cin>>v[i];
		reverse(v.begin(),v.end());
		
		long double l = -1  , r = 1;
		while( r - l > 1e-19 ){
			long double mid = (l+r)/2;
			long double cal = 0;
			for(int i=0;i<m;i++){
				cal += v[i] * powl(mid+(long double)1,(long double)i);
			}
			cal -= tm * powl(mid+1,m);
			if( cal < 0 ){
				r=mid;
			}
			else {
				l=mid;
			}
		}
		cout<<"Case #"<<t<<": "<< fixed << setprecision(15) << l <<endl;
	}
}
 
