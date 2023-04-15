#include <iostream>
#include <algorithm>
typedef long long ll;
const int nax = 1e5+10;
int arr[nax], n;
void input();
void solve();
int main(){
	int t;
	scanf("%d",&t);
	while( t-- ){
		input();
		solve();
	}
}
void input(){
	scanf("%d",&n);
	for(int i=0;i<n;++i){
		scanf("%d",&arr[i]);
	}
}
void solve(){
	std::sort(arr,arr+n);
	ll sum = 0, ans = 0;
	for(int i=0;i<n;++i){
		ans += sum - 1LL*i*arr[i];
		sum += arr[i];
	}
	ans += arr[n-1];
	printf("%lld\n",ans);
}

	

