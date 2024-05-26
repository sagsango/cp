

#Have to upgrade exactly 8 cards given.

/* Works on small test cases */
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
		int m,n;cin>>m>>n;
		map<int,int>dp;
		dp[0]=0;// dp[money]=maxpower;
		int ans=0;
		for(int i=1;i<=n;i++){
			int maxl,l;cin>>maxl>>l;
			vector<int>lcost(maxl+1);
			vector<int>power(maxl+1);
			for(int j=1;j<=maxl;j++){
				cin>>power[j];
			}
			for(int j=2;j<=maxl;j++){
				cin>>lcost[j];
				lcost[j]+=lcost[j-1];
			}
			map<int,int>dp2=dp;
			for(int j=l;j<=maxl;j++){
				for(auto [f,s]:dp){
					if(f+lcost[j]-lcost[l] <= m)dp2[f+lcost[j]-lcost[l]]=max(dp2[f+lcost[j]-lcost[l]],dp[f]+power[j]);
				}
			}
			dp=dp2;
		}
		for(auto [f,s]:dp)ans=max(ans,s);
		cout<<"Case #"<<t<<": "<< fixed << setprecision(15) << ans <<endl;
	}
}
 


/* If all cards were allowed [ 8, 9, 10, 11, or 12 ] : also work on small test cases */
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
		int m,n;cin>>m>>n;
		map<int,int>dpl;
		dpl[0]=0;// dp[money]=maxpower;
		for(int i=1;i<=n/2;i++){
			int maxl,l;cin>>maxl>>l;
			vector<int>lcost(maxl+1);
			vector<int>power(maxl+1);
			for(int j=1;j<=maxl;j++){
				cin>>power[j];
			}
			for(int j=2;j<=maxl;j++){
				cin>>lcost[j];
				lcost[j]+=lcost[j-1];
			}
			map<int,int>dp2=dpl;
			for(int j=l;j<=maxl;j++){
				for(auto [f,s]:dpl){
					if(f+lcost[j]-lcost[l] <= m)dp2[f+lcost[j]-lcost[l]]=max(dp2[f+lcost[j]-lcost[l]],dpl[f]+power[j]);
				}
			}
			dpl=dp2;
		}
		
		map<int,int>dpr;
		dpr[0]=0;// dp[money]=maxpower;
		for(int i=n/2+1;i<=n;i++){
			int maxl,l;cin>>maxl>>l;
			vector<int>lcost(maxl+1);
			vector<int>power(maxl+1);
			for(int j=1;j<=maxl;j++){
				cin>>power[j];
			}
			for(int j=2;j<=maxl;j++){
				cin>>lcost[j];
				lcost[j]+=lcost[j-1];
			}
			map<int,int>dp2=dpr;
			for(int j=l;j<=maxl;j++){
				for(auto [f,s]:dpr){
					if(f+lcost[j]-lcost[l] <= m)dp2[f+lcost[j]-lcost[l]]=max(dp2[f+lcost[j]-lcost[l]],dpr[f]+power[j]);
				}
			}
			dpr=dp2;
		}
		
		vector<int>cost;
		vector<int>maxpower;
		
		for(auto [f,s]:dpr){
			cost.push_back(f);
			maxpower.push_back(s);
		}
		for(int i=1;i<maxpower.size();i++){
			maxpower[i]=max(maxpower[i-1],maxpower[i]);
		}
		
		int ans=0;
		for(auto [c,p]:dpl){
			int I=upper_bound(cost.begin(),cost.end(),m-c)-cost.begin()-1;
			ans=max(ans,p+maxpower[I]);
		}
		cout<<"Case #"<<t<<": "<< fixed << setprecision(15) << ans <<endl;
	}
}
 


/* O( 495  * 1e4 * log(1e4) )  for large testcases */
#include<bits/stdc++.h>
#define int long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
map<int,int> brute(vector<int>&box,int m,int n,vector<int>&l,vector<int>&maxl,vector<int>cost[],vector<int>power[]){
	map<int,int>dp;
	dp[0]=0;   
	for(int i=0;i<4;i++){
		int I=box[i];
		map<int,int>dp2=dp;
		for(int j=l[I];j<=maxl[I];j++){
			for(auto [c,p]:dp){
				if( c + cost[I][j] - cost[I][l[I]] <= m ) dp2[c+cost[I][j]-cost[I][l[I]]]=max(dp2[c+cost[I][j]-cost[I][l[I]]],dp[c]+power[I][j]);
			}
		}
		dp=dp2;
	}
	return dp;
}
int solve(vector<int>&box1,vector<int>&box2,int m,int n,vector<int>&l,vector<int>&maxl,vector<int>lcost[],vector<int>power[]){
	map<int,int>dpl = brute(box1,m,n,l,maxl,lcost,power);
	map<int,int>dpr = brute(box2,m,n,l,maxl,lcost,power);
	vector<int>cost;
	vector<int>maxpower;
	for(auto [c,p]:dpr){
		cost.push_back(c);
		maxpower.push_back(p);
	}
	for(int i=1;i<maxpower.size();i++){
		maxpower[i]=max(maxpower[i-1],maxpower[i]);
	}
	int ans=0;
	for(auto [c,p]:dpl){
		int I=upper_bound(cost.begin(),cost.end(),m-c)-cost.begin()-1;
		ans=max(ans,p+maxpower[I]);
	}
	return ans;
}
int32_t main()
{
	IOS
	int T;cin>>T;
	for(int t=1;t<=T;t++){
		int m,n;cin>>m>>n;
		vector<int>l(n);
		vector<int>maxl(n);
		vector<int>lcost[n];
		vector<int>power[n];
		
		for(int i=0;i<n;i++){
			cin>>maxl[i]>>l[i];
			lcost[i]=vector<int>(maxl[i]+1);
			power[i]=vector<int>(maxl[i]+1);
			for(int j=1;j<=maxl[i];j++){
				cin>>power[i][j];
			}
			for(int j=2;j<=maxl[i];j++){
				cin>>lcost[i][j];
				lcost[i][j]+=lcost[i][j-1];
			}
		}
		int ans=0;
		for(int bit=0;bit<(1LL<<n);bit++){
			if( __builtin_popcount(bit) == 8 ){
				vector<int>box1,box2;
				for(int i=0;i<n;i++){
					if((bit>>i)&1){
						if(box1.size() < 4)box1.push_back(i);
						else box2.push_back(i);
					}
				}
				ans=max(ans,solve(box1,box2,m,n,l,maxl,lcost,power));
			}
		}
		cout<<"Case #"<<t<<": "<< ans <<endl;
	}
}
 




