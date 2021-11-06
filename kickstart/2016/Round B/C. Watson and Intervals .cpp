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
		int n;cin>>n;
		vector<int>l(n),r(n);
		cin>>l[0]>>r[0];
		int a,b,c1,c2,m;cin>>a>>b>>c1>>c2>>m;
		int x=l[0],y=r[0];
		for(int i=1;i<n;i++)
		{
			int newx = (a*x+b*y+c1)%m;
			int newy = (a*y+b*x+c2)%m;
			x=newx;
			y=newy;
			l[i]=min(x,y);
			r[i]=max(x,y);
		}
		set<int>st;
		for(int i=0;i<n;i++)
		{
			st.insert(l[i]);
			st.insert(l[i]-1);
			st.insert(l[i]-2);
			st.insert(l[i]+1);
			st.insert(l[i]+2);
			
			st.insert(r[i]);
			st.insert(r[i]-1);
			st.insert(r[i]-2);
			st.insert(r[i]+1);
			st.insert(r[i]+2);
		}
		map<int,int>Ii,iI;
		int i=1;
		for(auto e:st)
		{
			Ii[e]=i;
			iI[i]=e;
			i++;
		}
		int N=st.size();
		vector<int>dp(N+10);
		for(int i=0;i<n;i++)
		{
			dp[Ii[l[i]]]++;
			dp[Ii[r[i]+1]]--;
			//cout<< l[i]<<"-"<<r[i]<< "|" << Ii[l[i]] <<"-"<<Ii[r[i]] << endl;
		}
		for(int i=1;i<=N;i++)dp[i]+=dp[i-1];
		int tot=0;
		i=0;
		while( i<=N )
		{
			if(!dp[i])i++;
			else
			{
				int j=i;
				while( dp[j] )j++;
				tot+=iI[j-1]-iI[i]+1;
				//cout<<j<<">----<"<<i<<endl;
				i=j;
			}
		}
		//cout<< tot ;
		vector<int>dp1(N+1);
		for(int i=1;i<=N;i++)
		{
			int cnt=0;
			if(dp[i]==1)
			{
				cnt=1;
				if(dp[i-1]==1)cnt=iI[i]-iI[i-1];
			}
			dp1[i]+=dp1[i-1]+cnt;
		}
		int ans=1e18;
		for(int i=0;i<n;i++)
		{
			ans=min(ans,tot-(dp1[Ii[r[i]]]-dp1[Ii[l[i]-1]]));
		}
		cout<< "Case #"<<t<<": "<<ans<<endl;
	}
    
    
		
	
	
  
}
 
 
