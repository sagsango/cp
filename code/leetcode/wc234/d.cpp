const int mod = 1e9+7;
int pow(int a,int p){
	int r = 1;
	while( p ){
		if ( p & 1 )
			r = ( 1ll * r * a ) % mod;
		a = ( 1ll * a * a ) % mod;
		p >>= 1;
	}
	return r;

	// 2 2 2 2 2 2 2 3 3 3 3 3 3 3 3 3 3
}
class Solution {
	/*long long solve(int m, int n){
		int k = n / m;
		int r = n % m;
		return 1ll * pow(k,m-r) * pow(k+1,r) % mod;
		}*/
	public:
		int maxNiceDivisors(int n) {

			/*
Input: primeFactors = 8
Output: 18

(2,2) *  (3,3,3) * (5,5,5)

2 * 3 * 3 = 18

x1 + x2 + .... xn = primeFactors , xi > 1

max(x1*x2*..xn) 



(2,2) *  (3,3,3)

2 * 3 

2 3
2 3 3
2 3 3 3

2 2 3
2 2 3 3 
2 2 3 3 3
			 */

			/* long long ans = 1;
				 for(int i = 1; i <= min(1e6,1.0*n) ; i++ ){
				 ans = max(ans,solve(i,n));
				 if( 1 ){
				 cout <<i<< "#"<< solve(i,n) <<" "<< (solve(i,n) % mod == 572712676ll) << endl;
				 }
				 }*/
			if( n  <= 3 ){
				return n;
			}
			int rem = n % 3;
			if( rem == 0 )
				return pow(3,n/3);
			if( rem == 1 )
				return ( 4ll * pow(3,(n-4)/3)) % mod;
			return (2ll * pow(3,(n-2)/3)) % mod;

			/*     
						 18
						 3*3 * 3*3 3*3
						 (222) (333), (555), (777), (11,11,11)


Input:
73
Output:
429534507
Expected:
572712676


			 */







		}
};
