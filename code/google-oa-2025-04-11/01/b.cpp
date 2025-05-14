#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <numeric>
#include <sstream>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <cstdlib>
#include <cstdio>
#include <iterator>
#include <functional>
#include <bitset>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int solution(vector<int> A) {
  //cerr << "Tip: Use cerr to write debug messages on the output tab.";


  auto B = A;
  sort (B.begin(), B.end());
  int bad = 0, ans = 0;
  map<int, int> mp;
  int n = A.size();
  for (int i=0; i<n; ++i) {


    // before
    if (mp[A[i]] != 0) {
      bad -= 1;
    }
if (B[i] != A[i] && mp[B[i]] != 0) {
      bad -= 1;
    }

	cout << "Before:" << bad << endl;    
    mp[A[i]] += 1;
    mp[B[i]] -= 1;
    
    if (mp[A[i]] != 0) {
      bad += 1;
    }
if (B[i] != A[i] && mp[B[i]] != 0) {
      bad += 1;
    }

	cout << "After:" << bad << endl;
	int cnt = 0;
  	for (auto it: mp) {
		cnt += it.second !=0;
	}

	if (cnt != bad) {

		for (int j=0; j<=i; ++j) {
			cout << j <<" "<< A[j] <<" "<< B[j] << endl;
		}
		cout << cnt <<" "<< bad << endl;
		exit(1);
	}
	 
    if (bad == 0) {
      ans += 1;
    }
  }
cout << bad << endl;
  assert (bad == 0);
  return ans-1;


/*
  auto B = A;
  sort (B.begin(), B.end());
  int bad = 0, ans = 0;
  map<int, int> mp;
  int n = A.size();
  for (int i=0; i<n; ++i) {
    // before
    if (mp[A[i]] != 0) {
      bad -= 1;
    }else if (B[i] != A[i] && mp[B[i]] != 0) {
      bad -= 1;
    }
    
    mp[A[i]] += 1;
    mp[B[i]] -= 1;
    
    if (mp[A[i]] != 0) {
      bad += 1;
    }else if (B[i] != A[i] && mp[B[i]] != 0) {
      bad += 1;
    }
    
    if (bad == 0) {
      ans += 1;
    }
  }
  assert (bad == 0);
  return ans;
*/
}

int main() {
vector<int> arr = {-658, -388, 930, -327, 858, -20, -302, -558, -522, 339, -68, -500, -695, -543, -787, 38, 810, -224, -44, 865, 865, 204, 723, 4};

	solution(arr);
}

