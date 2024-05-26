#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

string s;
int n,k;

int32_t main(){
	IOS
	int T;cin>>T;
	for(int tc=1;tc<=T;tc++){
		cin >> s;
		cin >> k;
		n = s.length();
		for(int i=0;i<n;i++)
		s[i]=(s[i]=='-'?'0': '1');
		
		int i = 0;
		int ans = 0;
		while( i <= n-k ){
			if( s[i]=='0' ){
				ans+=1;
				for(int j=i;j<i+k;j++)
				s[j]=( s[j]=='0' ? '1' : '0');
			}
			i++;
		}
		for(int i=n-k+1;i<n;i++){
			if( s[i]=='0' )ans=1e18;
		}

		cout <<"Case #"<<tc<<": ";
		if( ans < 1e18 ) cout << ans << endl;
		else cout << "IMPOSSIBLE" << endl;
	}	
}
