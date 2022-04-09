class Solution {
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
public:
    int numberOfWays(string corridor) {
        int n = corridor.length(), l = 0, r = n - 1, i = 0, total_seats = 0, cnt;
        while( i < n )
            total_seats += corridor[i++] == 'S';
        if( total_seats % 2 )
            return 0;
        if( total_seats == 0)
            return 0;
        
        while( corridor[l] == 'P' )
            ++l;
        while( corridor[r] == 'P' )
            --r;
        
        int ways = 1;
        while( l <= r ){
            i = l, cnt = 0;
            while( i <= r && cnt != 2 ){
                cnt += corridor[i++] == 'S';
            }
            cnt = 0;
            while( i <=r && corridor[i] != 'S' ){
                cnt ++, ++i;
            }
            ways = mul(ways,cnt+1);
            l = i;
        }
       return ways;
        
    }
};
