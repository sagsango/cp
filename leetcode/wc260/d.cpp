class Solution {
public:
    string to_postfix(string infix){
        string postfix;
        stack<char>st;
        for(auto x:infix){
            if( '0' <= x && x <= '9' ){
                postfix += x;
            }else{
                if( ! st.empty() && st.top() == '*' && x == '+' ){
                    while( !st.empty() ){
                        postfix += st.top();
                        st.pop();
                    }
                }
                st.push(x);
            }
        }
         while( !st.empty() ){
            postfix += st.top();
            st.pop();
        }
        return postfix;
    }
    int solve(string infix){
        // 1+2*3+4
        // 1+(23*)+4
        // 123*+4+
        string postfix = to_postfix(infix);
        stack<int>st;
        for(auto x:postfix){
            if( '0' <= x && x <= '9' )
                st.push(x-'0');
            else{
                int op2 = st.top(); st.pop();
                int op1 = st.top(); st.pop();
                if( x == '*')
                    st.push(op1 * op2);
                else
                    st.push(op1 + op2 );
            }
        }
        return st.top();
        
    }
    int scoreOfStudents(string s, vector<int>& answers) {
        int n = s.length();
        int correct_ans = solve(s);
        
        set<int>dp[n][n];
        for(int i=0;i<n;i+=2){
            dp[i][i].insert(s[i]-'0');
        }
        for(int len=2;len<=n;++len){
            for(int l=0;l+len<=n;++l){
                int r = l + len -1;
                for(int i=l;i<r;i+=2){
                    for(auto x:dp[l][i]){
                        for(auto y:dp[i+2][r]){
                            int val = 0;
                            if(s[i+1]=='*')
                                 val = (x*y);   
                            else
                                val = (x+y);
                            
                            if( val <= 1000 ){
                                dp[l][r].insert(val);
                            }
                        }
                    }
                }
            }
        }
        int grades = 0;
        for(auto x:answers){
            if( x == correct_ans ){
                grades += (5);
            }else if( dp[0][n-1].count(x)){
                grades += (2);
            }else{
                grades += (0);
            }
        }
        return grades;
    }
};
