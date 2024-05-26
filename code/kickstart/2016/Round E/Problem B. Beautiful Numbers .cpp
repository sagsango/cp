#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int32_t main()
{
	IOS
	int T ; cin >> T;
	for(int t=1;t<=T;t++)
	{
		int x;cin>>x;
		int found=0;
		int ans=0;
		for(int i = 60 ;i >= 1 && !found ;i--)
		{
		     int l = 2 , r = 1e18-1;
		     while( l <= r )
		     {
			     //cout << l << " "<<r<<endl;
			     int mid = (l+r)/2;
			     long double base = 1 , sum = 0;
			     for(int j=0;j<=i;j++)
			     {
					 sum +=base;
					 base*=mid;
				 }
			    
			     if( sum == x ){
				   ans=mid;
				   found=1;
				   break;
			     }
			     if( sum < x )l=mid+1;
			     else r=mid-1;
		     }
	    }
	    cout <<"Case #"<< t<<": "<<(found ? ans : x-1)<<endl;
   }
}

