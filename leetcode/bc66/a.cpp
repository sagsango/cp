struct tri{
    tri * c[26];
    int  acnt, bcnt;
    tri(){
        acnt = bcnt = 0;
        for(int i=0;i<26;++i){
            c[i] = NULL;
        }
    }
};

tri * head;

void insert(string &s,int a,int b){
    tri * cur = head;
    for(int i=0;i<s.length();++i){
        if( cur->c[s[i]-'a'] == NULL ) cur->c[s[i]-'a'] = new tri();
        cur = cur->c[s[i]-'a'];
    }
    cur->acnt += a;
    cur->bcnt += b;
}

int count(tri*root){
    int cnt = 0;
    if( root){
        cnt += (root->acnt == 1 && root->bcnt == 1);
        for(int i=0;i<26;++i){
            cnt += count(root->c[i]);
        }
        delete root;
    }
    return cnt;
}

class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        head = new tri();
        for(auto &it:words1){
            insert(it,1,0);
        }
        for(auto &it:words2){
            insert(it,0,1);
        }
        return count(head);
    }
};
