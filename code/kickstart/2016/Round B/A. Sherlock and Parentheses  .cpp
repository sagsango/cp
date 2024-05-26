
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
 

int32_t main() {
    IOS
    int T;cin>>T;
    for(int t=1;t<=T;t++)
    {
		int ans=0;
		int l,r;cin>>l>>r;
		int n=min(l,r);
		ans=(n*(n+1))/2;
		cout<< "Case #"<<t<<": "<<ans<<endl;
	}
    
    
		
	
	
  
}
 
 
