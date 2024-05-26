#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
 

unordered_map<string,int>mp;
const int MOD = 1e9 + 7;
vector<int>dp(4000+1);
int n;
int solve(string &s,int i)
{
	if(i==n)return 1;
	if(dp[i]!=-1)return dp[i];
	dp[i]=0;
	string r;
	for(int j=i;j<min(n,i+20);j++)
	{
		r+=s[j];
		sort(r.begin(),r.end());
		if(mp.find(r)!=mp.end())
		{
			dp[i]+=mp[r]*solve(s,j+1);
			dp[i]%=MOD;
		}
	}
	return dp[i];
}
int32_t main()
{
	IOS
	int T ; cin >> T;
	for(int t=1;t<=T;t++)
	{
		int N,M;cin>>N>>M;
		mp.clear();
		for(int i=0;i<N;i++)
		{
			string s;cin>>s;
			sort(s.begin(),s.end());
			mp[s]++;
		}
		cout <<"Case #"<< t<<": ";
		for(int i=0;i<M;i++)
		{
			string s;cin>>s;
			n=s.length();
			fill(dp.begin(),dp.begin()+n,-1);
			int ans = solve(s,0);
			cout << ans << " ";
		}
		cout << endl;
	}
}

