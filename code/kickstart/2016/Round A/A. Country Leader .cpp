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
		int n;cin>>n;
		cin.ignore();
		vector<string>s(n);
		vector< set<char> >st(n);
		for(int i=0;i<n;i++)
		getline(cin,s[i]);
		
		sort(s.begin(),s.end());
		int mxchar=0;
		string ans;
		for(int i=0;i<n;i++){
			int l=s[i].length();
			for(int j=0;j<l;j++)
			if(s[i][j]!=' ')st[i].insert(s[i][j]);
			int charcnt = st[i].size();
			if( mxchar < charcnt ){
				mxchar = charcnt;
				ans= s[i];
			}
		}
		cout<<"Case #"<<t<<": "<<ans<<endl;
		
		
		
		
			
	}
}
 
