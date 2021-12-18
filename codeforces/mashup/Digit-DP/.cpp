dp[length][first digit][last digit][equal or less] = ways

dp[0][0][0][1] = 1;
for(int i=0;i<n;++i){
	for(int j=0;j<10;++j){
		for(int k=0;k<10;++k){
			int d;
			for(d=0;d<num[i];++d){
				dp[i+1][(j?j:d)][d][0] += dp[i][j][k][1];
			}
			dp[i+1][(j?j:d)][d][1] += dp[i][j][k][1];
			for(d=0;d<10;++d){
				dp[i+1][(j?j:d)][d][0] += dp[i][j][0];
			}
		}
	}
}

dp[length][no of non-zero digits][equal or less] = ways
for(int i=0;i<n;++i){
	for(int j=0;j<=m;++j){
		int d;
		for(d=0;d<num[i];++d){
			dp[i+1][j+(d!=0)][0] += dp[i][j][1];
		}
		dp[i+1][j+(d!=0)][1] += dp[i][j][1];
		for(d=0;d<10;++d){
			dp[i+1][j+(d!=0)][0] += dp[i][j][0];
		}
	}
}


vector<int>curNum; // number just greater than given number, and having given sum
bool dfs(int length, int sum, int isEqual){
	if( length == n ){
		return !isEqual && sum == givenSum;
	}
	int &ans = dp[length][sum][isEqual];
	if( ans != UNDEFINED ){
		return ans;
	}
	ans = 0;
	if( isEqual ){
		for(int d=num[length];d<10;++d){
			curNum.push_back(d);
			if( solve(length+1,sum+d,num[length] == d) )
				return ans = true;
			curNum.pop_back();
		}
	}else{ // greater
		for(int d=0;d<10;++d){
			curNum.push_back(d);
			if( solve(length+1,sum+d,isEqual) ){
				return ans = true;
			}
			curNum.pop_back();
		}
	}
	return ans = false;
}
