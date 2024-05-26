// https://leetcode.com/problems/fancy-sequence/
/*
	 Write an API that generates fancy sequences using the append, addAll, and multAll operations.

Implement the Fancy class:

Fancy() Initializes the object with an empty sequence.
void append(val) Appends an integer val to the end of the sequence.
void addAll(inc) Increments all existing values in the sequence by an integer inc.
void multAll(m) Multiplies all existing values in the sequence by an integer m.
int getIndex(idx) Gets the current value at index idx (0-indexed) of the sequence modulo 109 + 7. 
									If the index is greater or equal than the length of the sequence, return -1.


Example 1:

Input
["Fancy", "append", "addAll", "append", "multAll", "getIndex", "addAll", "append", "multAll", "getIndex", "getIndex", "getIndex"]
[[], [2], [3], [7], [2], [0], [3], [10], [2], [0], [1], [2]]
Output
[null, null, null, null, null, 10, null, null, null, 26, 34, 20]

Explanation
Fancy fancy = new Fancy();
fancy.append(2);   // fancy sequence: [2]
fancy.addAll(3);   // fancy sequence: [2+3] -> [5]
fancy.append(7);   // fancy sequence: [5, 7]
fancy.multAll(2);  // fancy sequence: [5*2, 7*2] -> [10, 14]
fancy.getIndex(0); // return 10
fancy.addAll(3);   // fancy sequence: [10+3, 14+3] -> [13, 17]
fancy.append(10);  // fancy sequence: [13, 17, 10]
fancy.multAll(2);  // fancy sequence: [13*2, 17*2, 10*2] -> [26, 34, 20]
fancy.getIndex(0); // return 26
fancy.getIndex(1); // return 34
fancy.getIndex(2); // return 20


Constraints:

1 <= val, inc, m <= 100
0 <= idx <= 105
At most 105 calls total will be made to append, addAll, multAll, and getIndex.
*/

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
	->x*b1 + a1*b1
add a2
add = a1*b1 + a2, Mul = b1
mul b2
add = (a1*b1+a2)*b2, Mul = b1 * b2
	->((x + a1)*b1 + a2)*b2 = x * b1 *b2 + (a1*b1+a2)*b2
.
.
mul b3
add a4
mul b4

((x + a1)*b1 + a2)*b2
  x * b1 *b2 + (a1*b1+a2)*b2

*/

