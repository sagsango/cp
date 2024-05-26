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
public:
    int firstDayBeenInAllRooms(vector<int>& arr) {
        int n = arr.size();
        vector<int>dp(n);
        dp[0] =  2;
        for(int i=1;i+1<n;++i){
            dp[i] = add(dp[i-1],sub(dp[i-1], arr[i] ? dp[arr[i]-1] : 0 ) );
            dp[i] = add(dp[i],2);
        }
        return dp[n-2];
    }
};
