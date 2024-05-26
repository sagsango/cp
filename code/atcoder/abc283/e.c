#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define min(a,b) (a<b ? a : b)
#define max(a,b) (a>b ? a : b)

const int nax = 1000, INF = 1e9;
int arr[nax][nax], dp[nax][nax][2][2][2], n, m;

// dp[ith row][jth col][cur elmnt clr][left elmnt clr][upper elmnt clr]= min cost
int main() {
	scanf("%d %d", &n, &m);
	for (int i=0; i<n; ++i) {
		for (int j=0; j<m; ++j) {
			scanf("%d", &arr[i][j]);
			for (int x=0; x<2; ++x) {
				for (int y=0; y<2; ++y) {
					for (int z=0; z<2; ++z) {
						dp[i][j][x][y][z] = INF;
					}
				}
			}
		}
	}

	// dp[0][0]
	for (int x=0; x<2; ++x) {
		for (int y=0; y<2; ++y) {
			for (int z=0; z<2; ++z) {
				dp[0][0][x][y][z] = arr[0][0] ^ x;
			}
		}
	}

	// dp[0][j]
	for (int j=1; j<m; ++j) {
		for (int x=0; x<2; ++x) {
			for (int z=0; z<2; ++z) {
				for (int _y=0; _y<2; ++_y) {
					for (int _z=0; _z<2; ++_z) {
						dp[0][j][x][x][z] = min(dp[0][j][x][x][z], dp[0][j-1][x][_y][_z] + (arr[0][j]^x));
					}
				}
			}
		}
	}


	// dp[i][0]
	for (int i=1; i<n; ++i) {
		for (int x=0; x<2; ++x) {
			for (int y=0; y<2; ++y) {
				for (int _y=0; _y<2; ++_y) {
					for (int _z=0; _z<2; ++_z) {
						dp[i][0][x][_y][x] = min(dp[i][0][x][_y][x], dp[i-1][0][x][_y][_z] + (arr[i][0]^x));
					}
				}
			}
		}
	}

	for (int i=0; i<n; ++i) {
		for (int j=0; j<m; ++j){
			int tmp = INF;
			for (int x=0; x<2; ++x) {
				for (int y=0; y<2; ++y) {
					for (int z=0; z<2; ++z) {
						tmp = min(tmp, dp[i][j][x][y][z]);
					}
				}
			}
			if ( i == 0 || j == 0 ) {
				printf("dp[%d][%d]=%d\n", i, j, tmp);
			}
		}
	}

	// dp[i][j] 
	for (int i=1; i<n; ++i) {
		for (int j=1; j<m; ++j) {
			for (int x=0; x<2; ++x) {
				for (int c_clr = 0; c_clr < 2; ++c_clr) {
					for (int l_l_clr = 0; l_l_clr < 2; ++l_l_clr) {
						for (int u_u_clr = 0; u_u_clr <2; ++u_u_clr) {
							for (int l_clr = 0; l_clr <2; ++l_clr) {
								for (int u_clr = 0; u_clr < 2;  ++u_clr) {
									if (l_clr == x || u_clr == x) {
										dp[i][j][x][l_clr][u_clr] = min(dp[i][j][x][l_clr][u_clr],
												dp[i][j-1][l_clr][l_l_clr][c_clr] + dp[i-1][j][u_clr][c_clr][u_u_clr] + (arr[i][j] ^ x));
									}
								}
							}
						}
					}
				}
			}
		}
	}

	int ans = INF;
	for (int x=0; x<2; ++x) {
		for (int y=0; y<2; ++y) {
			for (int z=0; z<2; ++z) {
				ans = min(ans, dp[n-1][m-1][x][y][z]);
			}
		}
	}

	printf("%d\n", ans); 
}
