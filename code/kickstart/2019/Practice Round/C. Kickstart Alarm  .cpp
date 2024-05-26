#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
	
#define y1 lkrwer
#define Y1 _____uytu

const int MOD = 1e9 + 7 ;
int power(int a,int n)
{
	int r=1;
	while( n )
	{
		if(n&1)
		{
			r*=a;
			r%=MOD;
		}
		a*=a;
		a%=MOD;
		n>>=1;
	}
	return r;
}
int32_t main()
{
	IOS
	int T ; cin >> T;
	for(int t=1;t<=T;t++)
	{
		int N,K,x1,y1,C,D,E1,E2,F;
		cin>>N>>K>>x1>>y1>>C>>D>>E1>>E2>>F;
		vector<int>X(N),Y(N),A(N);
		X[0]=x1;
		Y[0]=y1;
		for(int i=1;i<N;i++)
		{
			X[i]=(C*X[i-1]%F +D*Y[i-1]%F +E1%F )%F;
			Y[i]=(D*X[i-1]%F +C*Y[i-1]%F +E2%F )%F;
		}
		for(int i=0;i<N;i++)
		{
			A[i]=(X[i]+Y[i])%F;
		}
		
		vector<int>Coff(N);
		Coff[0]=K;
		for(int i=1;i<N;i++)
		{
			int num = i+1 ;
			Coff[i] = (((power(num,K+1) - 1 + MOD )%MOD  * power(num-1,MOD-2))%MOD - 1 + MOD)%MOD;
		}
		int ans = 0 ;
		int psum = 0;
		for(int i=0;i<N;i++)
		{
			psum+=Coff[i];
			psum%=MOD;
			int f = (N-i);
			ans+=((psum*A[i]%MOD)*f)%MOD;
			ans%=MOD;
		}
	    cout <<"Case #"<< t<<": "<< ans <<endl;
   }
}

