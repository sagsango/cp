// https://leetcode.com/problems/fancy-sequence/

class Fancy {
    static const int mod = 1e9+7;
    vector<int>m_vNums, m_vAdd, m_vMul;
    int m_iAdd, m_iMul, m_iSize;
    int add(int a,int b){
        int c = a + b;
        if( c >= mod )
            c -= mod;
        return c;
    }
    int sub(int a,int b){
        int c = a - b;
        if( c < 0 )
            c += mod;
        return c;
    }
    int mul(int a,int b){
        int c = ( 1ll * a * b ) % mod;
        return c;
    }
    int binpow(int a,long long p){
        int r = 1;
        while( p ){
            if( p & 1 )
                r = mul(r,a);
            a = mul(a,a), p >>= 1;
        }
        return r;
    }
    int div(int a,int b){
        return mul(a,binpow(b,mod-2));
    }
public:
    Fancy() {
        m_iAdd = 0;
        m_iMul = 1;
        m_iSize = 0;
    }

    void append(int val) {
        m_vNums.push_back(val);
        m_vAdd.push_back(m_iAdd);
        m_vMul.push_back(m_iMul);
        m_iSize += 1;
    }

    void addAll(int inc) {
        m_iAdd = add( m_iAdd,inc );
    }

    void multAll(int m) {
        m_iAdd = mul(m_iAdd,m);
        m_iMul = mul(m_iMul,m);
    }

    int getIndex(int idx) {
        if( idx < m_iSize ){
            int net_Mul = div(m_iMul, m_vMul[idx]);
            int net_Add = sub(m_iAdd,mul(m_vAdd[idx],net_Mul));

            return add(mul(m_vNums[idx],net_Mul),net_Add);
        }
        return -1;
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */

/*
Add = 0, Mul = 1
add a1
Add = a1, Mul = 1
mul b1
Add = a1*b1, Mul = b1
add a2
add = a1*b1 + a2, Mul = b1
mul b2
add = (a1*b1+a2)*b2, Mul = b1 * b2
mul b3
add a4
mul b4

((x + a1)*b1 + a2)*b2
  x * b1 *b2 + (a1*b1+a2)*b2

*/

