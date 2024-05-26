class Solution {
public:
    long long maximumSumOfHeights(vector<int>& arr) {
        
        typedef long long ll;
        //auto arr = H;
        //arr.insert(arr.begin()+0,0);
        //arr.insert(arr.end()-1,0);
        int n = arr.size();
        
        vector<ll>l(n), r(n), ldp(n), rdp(n);
        stack<int>st;
        for(int i=0;i<n;++i){
            while( !st.empty() && arr[st.top()] > arr[i]){
                r[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        while(st.size()){
            r[st.top()] = -1;
            st.pop();
        }
        
        for(int i=n-1;i>=0;--i){
             while( !st.empty() && arr[st.top()] > arr[i]){
                l[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        while(st.size()){
            l[st.top()] = -1;
            st.pop();
        }
        
        for(int i=0;i<n;++i){
            if(l[i] != -1){
                ldp[i] = ldp[l[i]] + 1ll * (i-l[i]) * arr[i];
            }else{
                ldp[i] = 1ll * (i+1) * arr[i];
            }
        }
        for(int i=n-1;i>=0;--i){
            if(r[i]!=-1){
                rdp[i] = rdp[r[i]] + 1ll * (r[i]-i) * arr[i];
            }else{
                rdp[i] = 1ll * (n-i) * arr[i];
            }
        }
        ll ans = 0;
        for(int i=0;i<n;++i){
            ans = max(ans, ldp[i] + rdp[i] - arr[i]);
        }
        return ans;
        
    }
};
