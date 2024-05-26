typedef long long ll;
const int mod = 1e9+7;
int add(int x,int y){
	int z = x + y;
	if( z >= mod ){
		z -= mod;
	}
	return z;
}
int sub(int x,int y){
	int z = x - y;
	if( z < 0 ){
		z += mod;
	}
	return z;
}
int mul(int x,int y){
	ll z = 1ll * x * y;
	if( z >= mod ){
		z %= mod;
	}
	return z;
}
int binpow(int a,ll p){
	int r = 1;
	while( p ){
		if( p & 1 )
			r = mul(r,a);
		a = mul(a,a), p >>= 1;
	}
	return r;
}

class Solution {
    vector<int> prime = {2,3,5,7,11,13,17,19,23,29};
    int N = 10;
public:
    bool mask(int n,int &msk){
        for(int i=0;i<N;++i){
            while( n % prime[i] == 0 ){
                if( msk >> i & 1 )
                    return 0;
                msk ^= 1 << i;
                n /= prime[i];
            }
        }
        return 1;
    }
    int numberOfGoodSubsets(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(1<<N);
        dp[0] = 1;
        
        vector<int>cnt(31);
        for(auto x:nums){
            cnt[x] += 1;
        }
        
        for(int i=2;i<=30;++i){
            int msk = 0;
            if( mask(i,msk) ){
                vector<int>tdp = dp;
                for(int j=0;j<1<<N;++j){
                    if( ( j & msk ) == 0 ){
                        tdp[j|msk] = add(tdp[j|msk], mul(dp[j],cnt[i]));
                    }
                }
                dp = tdp;
            }
        }
        
        int ans = 0;
        for(int i=1;i<1<<N;++i){
            ans = add(ans,dp[i]);
        }
        int p = 1;
        for(int i=1;i<=cnt[1];++i){
            p = mul(p,2);
        }
        
        return mul(ans,p);
    }
};
