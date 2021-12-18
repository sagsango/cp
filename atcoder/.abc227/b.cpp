#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <stdio.h>

using namespace std;


int main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	unordered_set<int>s;
	for(int a = 1; a <= 1000; ++a){
		for(int b = 1; 4*a*b + 3*a + 3*b <= 1000; ++b){
			s.insert(4*a*b+3*a+3*b);
		}
	}
	int cnt = 0, n; cin >> n;
	for(int i=0;i<n;++i){
		int x; cin >> x;
		cnt += !s.count(x);
	}
	cout << cnt << endl;
	
}	


