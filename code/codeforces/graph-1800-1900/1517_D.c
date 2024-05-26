#include <stdio.h>
#include <limits.h>

int dp[500][500][21], x[500][500], y[500][500], n, m, k;

int main() {
	scanf("%d %d %d", &n, &m, &k);
	for (int i=0; i<n; ++i) {
		for (int j=0; j<m-1; ++j) {
			scanf("%d", &y[i][j]); /* edge (i,j) - (i,j+1) */
		}
	}
	for (int i=0; i<n-1; ++i) {
		for (int j=0; j<m; ++j) {
			scanf("%d", &x[i][j]); /* edge (i,j) - (i+1,j) */
		}
	}

	for (int t=2; t<=k; t+=2) {
		for (int i=0; i<n; ++i) {
			for (int j=0; j<m; ++j) {
				dp[i][j][t] = INT_MAX;
				
				if (i!=0) {
					if (dp[i][j][t] > dp[i][j][t-2] + x[i-1][j] * 2) {
						dp[i][j][t] = dp[i][j][t-2] + x[i-1][j] * 2;
					}
					if (dp[i][j][t] > dp[i-1][j][t-2] + x[i-1][j] * 2) {
						dp[i][j][t] = dp[i-1][j][t-2] + x[i-1][j] * 2;
					}
				}

				if (i!=n-1) {
					if (dp[i][j][t] > dp[i][j][t-2] + x[i][j] * 2) {
						dp[i][j][t] = dp[i][j][t-2] + x[i][j] * 2;
					}
					if (dp[i][j][t] > dp[i+1][j][t-2] + x[i][j] * 2) {
						dp[i][j][t] = dp[i+1][j][t-2] + x[i][j] * 2;
					}
				}

				if (j!=0) {
					if (dp[i][j][t] > dp[i][j][t-2] + y[i][j-1] * 2) {
						dp[i][j][t] = dp[i][j][t-2] + y[i][j-1] * 2;
					}
					if (dp[i][j][t] > dp[i][j-1][t-2] + y[i][j-1] * 2) {
						dp[i][j][t] = dp[i][j-1][t-2] + y[i][j-1] * 2;
					}
				}

				if (j!=m-1) {
					if (dp[i][j][t] > dp[i][j][t-2] + y[i][j] * 2) {
						dp[i][j][t] = dp[i][j][t-2] + y[i][j] * 2;
					}
					if (dp[i][j][t] > dp[i][j+1][t-2] + y[i][j] * 2) {
						dp[i][j][t] = dp[i][j+1][t-2] + y[i][j] * 2;
					}
				}
			}
		}
	}
	for (int i=0; i<n; ++i) {
		for (int j=0; j<m; ++j) {
			printf("%d%c", (k&1 ? -1 : dp[i][j][k]), j == m-1 ? '\n' : ' ');
		}
	}
}
