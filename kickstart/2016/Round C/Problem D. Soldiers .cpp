//This complexity can be optimised for N = 1e6 also but given constrain are only for N = 4000
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
		int n;cin>>n;
		vector<int>x(n);
		vector<int>y(n);
		int ok=2;
		for(int i=0;i<n;i++)
		cin>>x[i]>>y[i];
		
		while( x.size() || y.size() )
		{
			int mxi=0,myi=0;
			for(int i=0;i<n;i++)
			{
				if( x[i] > x[mxi] )mxi=i;
				if( y[i] > y[myi] )myi=i;
			}
			for(int i=0;i<n;i++)
			{
				if( x[i]==x[mxi] && y[i]==y[myi])
				{
					ok=1;break;
				}
			}
			vector<int>x2,y2;
			for(int i=0;i<n;i++)
			{
				if( x[i]!=x[mxi] && y[i]!=y[myi])
				{
					x2.push_back(x[i]);
					y2.push_back(y[i]);
				}
			}
			x=x2;
			y=y2;
			n=x2.size();
		}
		cout <<"Case #"<<t<<": "<<(ok==2?"NO":"YES")<<endl;
	}
}
 
