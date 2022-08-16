#include <iostream>
#include <string>
#include <queue>
#include <unordered_set>
using namespace std;
#define TERMINAL "atcoder"
#define LEN 7
int main(){
  string s; cin >> s;
  queue<pair<string,int>>q;
  unordered_set<string> vis;
  q.push({s,0});
  vis.insert(s);
  while( q.size() ){
    string u = q.front().first;
    int w = q.front().second;
    q.pop();
    if( u == TERMINAL ){
      cout << w << endl;
      return 0;
    }
    for(int i=0;i+1<LEN;++i){
      string v = u;
      swap(v[i],v[i+1]);
      if( vis.count(v) )
        continue;
      q.push({v,w+1});
      vis.insert(v);
    }
  }
  cout << -1 << endl;
}
