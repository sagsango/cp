#include <stdio.h>
#include <string.h>
#include <stdlib.h>
const int nax = 5000+10;
int dp[nax][nax], n, A[nax], B[nax], a, b, x, mn, ans;
void min(int *a,int b){ *a = ( *a < b ? *a : b ); }
int main(){
	memset(dp,0b01111111,sizeof(dp));
	scanf("%d",&n);
	for(int i=0;i<n;++i){
		scanf("%d",&x);
		if( x ){
			A[a++] = i;
		}else{
			B[b++] = i;
		}
	}
	if( a == 0 ){
		printf("0\n");
		return 0;
	}
	for(int i=0;i<b;++i){
		dp[0][i] = abs(A[0]-B[i]);
	}
	for(int i=1;i<a;++i){
		mn = dp[i-1][i-1];
		for(int j=i;j<b;++j){
			min( &dp[i][j], mn + abs(A[i]-B[j]));
			min( &mn, dp[i-1][j]);
		}
	}
	ans = 1e9;
	for(int i=a-1;i<b;++i){
		min(&ans, dp[a-1][i]);
	}
	printf("%d\n",ans);
}
		
