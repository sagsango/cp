#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define bug1( x ) cout << (#x) <<"="<< x << endl;
#define bug2( x , y ) cout << (#x) <<"="<< (x) << "    " << (#y) << "="<< (y) << endl;
#define bug3( x , y , z ) cout << (#x) <<"="<<(x) << "    " << (#y) <<"="<< (y) << "    " << (#z) <<"="<< (z) << endl;
#define bug4( x , y , z , w) cout << (#x) <<"="<<(x) << "    " << (#y) <<"="<< (y) << "    " << (#z) <<"="<< (z) << "    " << (#w) <<"="<< w << endl;
#define bugn( x , n ){ cout<<(#x)<<":";for(int i=0;i<n;i++)cout<<(#x)<<"["<<i<<"]:"<< x[i] << "    "; cout<<endl;}
#define bugnm( x , n , m ){ cout<<(#x)<<endl;for(int i=0;i<n;i++){ cout<<"Row #"<<i<<":"; for(int j=0;j<m;j++) cout<<x[i][j]<<"     "; cout << endl;}}
using namespace std;	


struct box{
	int  h , val ,ldp , rdp;
	bool operator <(const box other){
		return h < other.h;
	}
};
vector<vector<box>>a;
int n,m;


int32_t main(){
	IOS
	cin>>n>>m;
	a=vector<vector<box>>(n,vector<box>(m));
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>a[i][j].h;
			a[i][j].val=0;
			a[i][j].ldp=0;
			a[i][j].rdp=0;
		}
		sort(a[i].begin(),a[i].end());
	}
	
	for(int j=0;j<m;j++){
		a[0][j].ldp = - a[0][j].h;
		if( j-1 >=0 ){
			a[0][j].ldp=min(a[0][j].ldp,a[0][j-1].ldp);
		}
	}
	
	for(int j=m-1;j>=0;j--){
		a[0][j].rdp= a[0][j].h;
		if( j+1 < m ){
			a[0][j].rdp=min(a[0][j].rdp,a[0][j+1].rdp);
		}
	}
	
	for(int i=1;i<n;i++){
		for(int j=0;j<m;j++){
			int l,r,idx;
			a[i][j].val=1e15;
			
			l=0,r=m-1;
			idx=-1;
			while( l<=r ){
				int mid = (l+r)/2;
				if( a[i-1][mid].h <= a[i][j].h ){
					idx = max( idx , mid);
					l=mid+1;
				}
				else{
					r=mid-1;
				}
			}
			if( idx != -1 ){
				a[i][j].val=min(a[i][j].val,a[i-1][idx].ldp+a[i][j].h);
			}
			
			
			l=0,r=m-1;
			idx=m;
			while( l<=r ){
				int mid = (l+r)/2;
				if( a[i-1][mid].h >= a[i][j].h){
					idx=min(idx,mid);
					r=mid-1;
				}
				else{
					l=mid+1;
				}
			}
			if( idx!=m ){
				a[i][j].val=min(a[i][j].val,a[i-1][idx].rdp-a[i][j].h);
			}
		}
		for(int j=0;j<m;j++){
			a[i][j].ldp=a[i][j].val-a[i][j].h;
			if( j-1 >=0 ){
				a[i][j].ldp=min(a[i][j].ldp,a[i][j-1].ldp);
			}
		}
			
		for(int j=m-1;j>=0;j--){
			a[i][j].rdp=a[i][j].val+a[i][j].h;
			if( j+1 < m){
				a[i][j].rdp=min(a[i][j].rdp,a[i][j+1].rdp);
			}
		}	
	}

	int ans = 1e15;
	for(int j=0;j<m;j++){
		ans=min(ans,a[n-1][j].val);
	}
	cout << ans << endl;
					
	
	
}
	
	
	
	

	

	

	
		
