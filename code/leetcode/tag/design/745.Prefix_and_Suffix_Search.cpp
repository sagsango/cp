// https://leetcode.com/problems/prefix-and-suffix-search/
/*
    TODO: How to approach, find brude force, then see which part will be O(1), 
		or O(logN) or O(N) or O(N*N), try to think diff approaches, diff senarios 
		for comlexities, also for the same problem diff data sets can have diff 
		soluions.

*/


struct Tri{
    int idx;
    Tri * c[27];
    Tri(){
        idx = -1;
        for(int i=0;i<27;++i){ // TODO: 27 not 26, think why?
            c[i] = NULL;
        }
    }
};

void insertWord(Tri * root, string & word,int &idx){
    Tri * cur = root;
    for(auto x:word){
        if( cur->c[x-'a'] == NULL )
            cur->c[x-'a'] = new Tri();
        cur = cur->c[x-'a'];
    }
    cur->idx = idx;
}

void searchWord(Tri *root, string &word,int &idx){
    Tri * cur = root;
    for(auto x:word){
        if( cur->c[x-'a'] == NULL )
            return;
        cur = cur->c[x-'a'];
    }
    idx = cur->idx;
}

void dfs_and_delete(Tri * root){
    if( root ){
        for(int i=0;i<27;++i){
            dfs_and_delete(root->c[i]);
        }
        delete root;
    }
}
class WordFilter {
    Tri * root;
public:
    WordFilter(vector<string>& words) {
        root = new Tri();
        int idx = 0;
        for(auto s:words){
            int n = s.length();
            for(int plen=1;plen<=n;++plen){ // prefix length
                for(int slen=1;slen<=n;++slen){ // suffix length
                    string p_s; // prefix + (char)('a'+26) + suffix
                    for(int i=0;i<plen;++i){
                        p_s += s[i];
                    }
                    p_s += (char)('a'+26);
                    for(int i=0;i<slen;++i){
                        p_s += s[n-slen+i];
                    }
                    insertWord(root,p_s,idx);
                }
            }
            ++idx;
        }

    }
    ~WordFilter(){
        dfs_and_delete(root);
    }

    int f(string prefix, string suffix) {
        int idx = -1;
        string s = prefix + (char)('a'+26)  + suffix;
        searchWord(root,s,idx);
        return idx;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */
