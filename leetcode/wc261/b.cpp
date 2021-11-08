class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        
        // total_sum = mean * (n+m)
        // m_sum = can calculate
        // n_sum = total_sum - m_sum
        
        // n_sum < n || n_sum > n * 6 
        // return empty
        
        // int div = n_sum / n
        // int rem = n_sum % n
        
        int m = rolls.size(), m_sum = 0;
        for(auto x:rolls){
            m_sum += x;
        }
        
        int total_sum = mean * ( n + m );
        int n_sum = total_sum - m_sum;
        if( n_sum < n || n_sum > n * 6 )
            return {};
        int div = n_sum / n;
        int rem = n_sum % n;
        
        vector<int>ans(n);
        for(int i=0;i<n;++i){
            ans[i] = div;
            if( i < rem )
                ans[i] += 1;
        }
        return ans;
        
    }
};
