
class MirrorNumber{
    private:
    string odd_index, even_index, odd_number, even_number;
    int base;
    long long odd_base, even_base;
    string addOne(string s){
        reverse(s.begin(),s.end());
        int carry = 1, sum = 0, d = 0;
        string ans;
        for(int i=0;i<s.length();++i){
            sum = (s[i]-'0' + carry);
            d = sum % base;
            carry = sum / base;
            
            ans += (char)(d+'0');
        }
        if( carry ){
            ans += (char)(carry+'0');
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    long long base10(string s){
        long long num = 0;
        for(int i=0;i<s.length();++i){
            num = num * base + (s[i]-'0');
        }
        return num;
    }
    string OddNumber(string s){
        string ans = s;
        int n = s.length();
        for(int i=0;i+1<n;++i){
            ans += s[n-i-2];
        }
        return ans;
    }
     string EvenNumber(string s){
        string ans = s;
        int n = s.length();
        for(int i=0;i<n;++i){
            ans += s[n-i-1];
        }
        return ans;
    }
    public:
    MirrorNumber(long long base):base(base),odd_index("1"),even_index("1"),odd_number("1"),even_number("11"),odd_base(0),even_base(0){
        even_base = base10(even_number);
        odd_base = base10(odd_number);
    }
    long long give(){
        return min(odd_base,even_base);
    }
    void next(){
        if( odd_base < even_base){
            odd_index = addOne(odd_index);
            odd_number = OddNumber(odd_index);
            odd_base = base10(odd_number);
        }else if( even_base < odd_base){
            even_index = addOne(even_index);
            even_number = EvenNumber(even_index);
            even_base = base10(even_number);
        }
    } 
};
class Solution {
public:
    long long kMirror(int k, int n) {
        MirrorNumber a(k), b(10);
        long long sum = 0;
        while( n  ){
            if( a.give() == b.give() ){
                sum += a.give();
                a.next();
                b.next();
                --n;
            }else if( a.give() < b.give() ){
                a.next();
            }else{
                b.next();
            }
        }
        return sum;
        
    }
};
