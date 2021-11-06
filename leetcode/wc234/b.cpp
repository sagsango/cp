class Solution {
	int lcm(int a,int b){
		return a * b / __gcd(a,b);
	}
	public:
	int reinitializePermutation(int n) {
		vector<int>vis(n);
		int l = 1;
		for(int i=0;i<n;++i){
			if( !vis[i] ){
				int len = 0;
				int j = i;
				while( !vis[j] ){
					vis[j] = 1;
					++len;
					int new_j = j % 2 ? n/2 + (j-1)/2 : j / 2;
					j = new_j;
				}
				//cout << len << endl;
				l = lcm(l,len);
			}
		}
		return l;


		/*
			 i % 2 == 0, then arr[i] = perm[i / 2].
			 If i % 2 == 1, then arr[i] = perm[n / 2 + (i - 1) / 2].






			 [0,1,2,3]

			 1 len
			 0 <- 0

			 2 ln
			 1 <- 2
			 2 <- 1


			 3 len


			 1 len 
			 3 <- 3
		 */

	}
};
