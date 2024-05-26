#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
 
const int MOD = 1e9 + 7;

int32_t main() {
   IOS
   int m,x,n;cin>>m>>n;
   int sum=0;
   vector<int>v(n+2);
   vector<int>d(n+2);
   for(int i=1;i<=n;i++)
   {
	   cin>>v[i];
	   sum+=v[i];
   }
   for(int i=n;i>=1;i--)
   {
	   d[i]+=d[i+1]+v[i];
   }
   int optimum=0;
   for(int i=n;i>=1;i--)
   {
	   if(d[i] > 9833203)
	   {
		   optimum=d[i+1];
           cout<<sum << ": "<<n-i<<" "<< optimum <<"|"<<v[i]<< endl;
           break;
	   }
   }
   
   // start from here 
   cout<< "Total sum :"<<sum<<endl;
   int lused;
   for(int i=n;i>=1;i--)
   {
	   if( sum - v[i] >= m ){
		   sum-=v[i];
		   lused =i;
	   }
   }
   cout<<"Reduced SUm:"<< sum <<endl;
   cout<< "for Reduction lused  total values from back"<<n-lused+1<<" And Index of lused :"<<lused<<"And value that  lused:"<<v[lused]<< endl;
   
   // 82360 + 6 = 82366
   
   vector<int>dp(82366+1);
   dp[0]=1;
   for(int i=1;i<=100;i++)
   {
	   vector<int>dp2=dp;
	   for(int j=0;j+v[i]<=82366;j++)
	   dp2[j+v[i]]|=dp[j];
	   dp=dp2;
   }
   for(int i=82366;i>=1;i--)
   {
	   if( dp[i]){
		   cout<< "found" << i << endl;
		   break;
	   }
   }
   
	   
	
  
}
 
 
