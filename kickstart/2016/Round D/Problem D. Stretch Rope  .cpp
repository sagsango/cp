#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
 

const int N = 10000;
int32_t main()
{
	IOS
	int T ; cin >> T;
	for(int t=1;t<=T;t++)
	{
		int N , M , L;
		cin >> N >> M >> L;
		vector<int>dp(L+1,1e15);
		dp[0]=0;
		for(int i=0;i<N;i++)
		{
			int l,r,p;cin>>l>>r>>p;
			vector<int>dp2=dp;
			multiset<int>st;
			int left = 0 , right = 0;
			//st.insert(dp[0]);
			//for(int j=0;j<=L;j++)
			//cout<<dp[j] <<" ";
			//cout<<endl;
			for(int j=l;j<=L;j++)
			{
				int currl = max(j - r,0LL);
				int currr = max(j - l,0LL);
				while( right < currr + 1 )
				{
					st.insert(dp[right]);
					++right;
				}
				while( left  < currl )
				{
					st.erase(st.find(dp[left]));
					++left;
				}
				//cout << j <<" "<<left<<" "<<right<<endl;
				//cout << j <<" "<<left<<" "<<right<<" "<<*st.begin()<<endl;
				dp2[j]=min(dp2[j],*st.begin()+p);
			}
			dp=dp2;
			//for(int j=0;j<=L;j++)
			//cout<<dp[j] <<" ";
			//cout<<endl<<endl;
		}
		if( dp[L] <= M )
		{
			cout <<"Case #"<< t<<": "<<dp[L]<<endl;
		}
		else cout <<"Case #"<< t<<": "<<"IMPOSSIBLE"<<endl;
		
		cout << endl;
	}
}

