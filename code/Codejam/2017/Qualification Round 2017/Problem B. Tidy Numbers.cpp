#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int32_t main(){
	IOS
	int T;cin>>T;
	for(int tc=1;tc<=T;tc++){
		int n;cin>>n;
		string s = to_string(n);
		string ans;
		int l = s.length();
		int x = -1;
		for(int i=0;i+1<l;i++){
			if( s[i] > s[i+1]){
				x =  i;
				break;
			}
		}
		if( x != -1 ){
			int curr = s[x]-'0' -1; // curr always be >= 0
			
			if( curr == 0 ){
				for(int i=0;i+1<l;i++)
				ans+='9';
			}
			else{
				int y = x;
				while( y >= 0 && s[y]-'0' > curr ){
					s[y]=curr+'0';
					y--;
				}

				for(int i=y+2;i<l;i++)
				s[i]='9';
				ans = s;
				
			}
		}
		else ans = s;
		cout <<"Case #"<<tc<<": "<< ans << endl;
	}	
}
