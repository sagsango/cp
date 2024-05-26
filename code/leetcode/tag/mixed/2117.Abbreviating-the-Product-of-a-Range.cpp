typedef long long ll;

class Solution {
    string ToString(int n){
        string ans;
        while( n ){
            ans += n % 10 + '0';
            n /= 10;
        }
        while( ans.length() < 5u ){
            ans += '0';
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
public:
    string abbreviateProduct(int left, int right) {
        int x=0,y=0;
        vector<int>a;
        for(int i=left;i<=right;i++) {
            int j=i;
            while(j%2==0) {
                x++;j/=2;
            }
            while(j%5==0) {
                y++;
                j/=5;
            }
            a.push_back(j);
        }
        for(int i=1;i<=abs(x-y);i++) a.push_back(x>y?2:5);
        
        ll k=1;
        for(int i:a) {
            k=k*i;
            if(k>=1e10) {
                break;
            }
        }
        if(k<1e10) {
            return to_string(k)+"e"+to_string(min(x,y));
        }
        
        ll p=1,s=1;
        for(int i:a) {
            s=s*i;
            s%=100000;
            p=p*i;
            while(p>1e12) p/=10;
        }
        while(p>1e5) p/=10;
        return to_string(p)+"..."+ ToString(s)+"e"+to_string(min(x,y));
    }
};

