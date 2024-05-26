#include <iostream>
#include <string>
#include <cstring>
#include <memory>
#define int long long
using namespace std;	
		
const int maxx = 300 , maxy = 300 , maxstep = 30 , maxdepth = 5 , direction = 8;
bool dp[maxx][maxy][maxstep][maxdepth][direction];
/*      300 * 300 * 30 * 5 * 8            */
bool vis[maxx][maxy];
int a[maxstep];
int n;


/*
      7 0 1
      6   2
      5 4 3
*/
 
void dfs(int x,int y,int step,int depth,int dir){
	if( step == n )return;
	if( dp[x][y][step][depth][dir] )return;
	vis[x][y]=1;
	dp[x][y][step][depth][dir]=1;
	
	switch(dir){
/*
		
      7 0 1
      6   2
      5 4 3
*/
		case 0 : if( a[step] == depth +1 ){
					dfs(x-1,y+1,step+1,0,1);
					dfs(x-1,y-1,step+1,0,7);
				 }
				 else{
					dfs(x-1,y,step,depth+1,0);
				 }
				 break;
				
		case 1 : if( a[step] == depth +1 ){
					dfs(x-1,y,step+1,0,0);
					dfs(x,y+1,step+1,0,2);
				 }
				 else{
					dfs(x-1,y+1,step,depth+1,1);
				 }
				 break;
/*
		
      7 0 1
      6   2
      5 4 3
*/		
		case 2 : if( a[step] == depth +1 ){
					dfs(x-1,y+1,step+1,0,1);
					dfs(x+1,y+1,step+1,0,3);
				 }
				 else{
					dfs(x,y+1,step,depth+1,2);
				 }
				 break;
		case 3 : if( a[step] == depth +1 ){
					dfs(x,y+1,step+1,0,2);
					dfs(x+1,y,step+1,0,4);
				 }
				 else{
					dfs(x+1,y+1,step,depth+1,3);
				 }
				 break;
/*
		
      7 0 1
      6   2
      5 4 3
*/
		case 4 : if( a[step] == depth +1 ){
					dfs(x+1,y+1,step+1,0,3);
					dfs(x+1,y-1,step+1,0,5);
				 }
				 else{
					dfs(x+1,y,step,depth+1,4);
				 }
				 break;
		case 5 : if( a[step] == depth +1 ){
					dfs(x,y-1,step+1,0,6);
					dfs(x+1,y,step+1,0,4);
				 }
				 else{
					dfs(x+1,y-1,step,depth+1,5);
				 }
				 break;
/*
		
      7 0 1
      6   2
      5 4 3
*/
		case 6 : if( a[step] == depth +1 ){
					dfs(x-1,y-1,step+1,0,7);
					dfs(x+1,y-1,step+1,0,5);
				 }
				 else{
					dfs(x,y-1,step,depth+1,6);
				 }
				 break;
				 
		case 7 : if( a[step] == depth +1 ){
					dfs(x,y-1,step+1,0,6);
					dfs(x-1,y,step+1,0,0);
				 }
				 else{
					dfs(x-1,y-1,step,depth+1,7);
				 }
				 break;
	}
}
int32_t main(){
	memset(dp,0,sizeof(dp));
	memset(vis,0,sizeof(vis));
	cin >> n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	
	dfs(150,150,0,0,0);
	
	int cnt = 0;
	for(int i=0;i<maxx;i++){
		for(int j=0;j<maxy;j++){
			cnt+=vis[i][j];
		}
	}
	cout<<cnt<<endl;
}



