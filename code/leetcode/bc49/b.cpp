/*
struct tri{
    tri * c[26*2];
    int end;
    tri(){
        end = 0;
        for(int i=0;i<26*2;++i){
            c[i] = NULL;
        }
    }
};
tri * head;

int idx(char c){
    if( c >= 'A' && c <= 'Z' )
        return c - 'A';
    return c - 'a' + 26;
}

void insert(string s){
    tri * cur = head;
    for(auto c:s){
        if( cur->c[idx(c)] == NULL ) cur->c[idx(c)] = new tri();
        cur = cur->c[idx(c)];
    }
    cur->end += 1;
}

bool present(string s){
    tri * cur = head;
    for(auto c:s){
        if( cur->c[idx(c)] == NULL )
            return 0;
        cur = cur->c[idx(c)];
    }
    if( cur == NULL || cur->end == 0 )
        return 0;
    cur->end -= 1;
    return 1;
}

bool solve(string s1, string s2){
    head = new tri();
    stringstream A(s1);
    string s;
    while( A >> s ){
        insert(s);
    }

    stringstream B(s2);

    while( B >> s ){
        if( !present(s) )
            return 0;
    }
    return 1;
}*/

vector<string> to_str_vec(string S){
    vector<string>arr;
    stringstream ss(S);
    string s;
    while( ss >> s ){
        arr.push_back(s);
    }
    /*for(auto s:arr){
        cout << s << " ";
    }*/
    cout << endl;
    return arr;
}

bool solve(string s1, string s2){
    vector<string> a = to_str_vec(s1);
    vector<string> b = to_str_vec(s2);
    
    int n = a.size();
    int m = b.size();
    
    
    //sdasd asdasdasd dfdfwf asfasf
    
    int l = 0;
    for(int i = 0; i < n && l < m; ++i, ++l){
        if( a[i] != b[l] )
            break;
    }
    int r = m-1;
    for(int i=n-1;i>=0 && r >= 0; --i, --r){
        if( a[i] != b[r] )
            break;
    }
    return r < l;
}
class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {
       if( s1 == s2 )
           return 1;
        
        if( s1.length() < s2.length() )
            swap(s1,s2);
        return solve(s1,s2);
        
        
    }
};
