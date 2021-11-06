struct tri{
    int cnt;
    tri * c[10];
    tri(){
        cnt = 0;
        for(int i=0;i<10;++i){
            c[i] = nullptr;
        }
    }
};

tri * head;
void insert(vector<int>num){
    tri * cur = head;
    for(int i=0;i<100;++i){
        if( !cur->c[num[i]] ) cur->c[num[i]] = new tri();
        cur = cur->c[num[i]];
        cur->cnt += 1;
    }
}

vector<int> solve(int k){
    cout << k << endl;
    vector<int>num(100);
    tri * cur = head;
    for(int i=0;i<100;++i){
        int prv = 0;
        for(int j=0;j<10;++j){
            if( !cur->c[j] )
                continue;
            //if( i == 99 )
                //cout <<j <<" "<< prv + cur->c[j]->cnt <<" "<< k << endl;
            if(prv + cur->c[j]->cnt >= k ){
                k -= prv;
                cur = cur->c[j];
                num[i] = j;
                //cout << j <<" ";
                break;
            }
            prv += cur->c[j]->cnt;
        }
    }
    return num;
}

class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        head = new tri();
        for(auto s:nums){
            //10
            reverse(s.begin(),s.end()); // 01
            vector<int>num(100);
            for(int i=0;i<s.length();++i){
                num[100-i-1] = s[i] - '0';
                // 10
            }
            insert(num);
        }
        //cout << head->c[0]->cnt << endl;
        vector<int>num = solve(nums.size()-k+1);
        //return "";
        int i = 0;
        while( i < 100 && num[i] == 0 )
            ++i;
        //return "";
        string ans;
        while( i < 100 ){
            ans = ans + (char)( num[i] + '0' ) ;
            ++i;
        }
        return ans.empty() ? "0" : ans;
        
    }
};
