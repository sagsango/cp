// https://leetcode.com/problems/product-of-the-last-k-numbers/

class ProductOfNumbers {
    vector<int>m_vProduct;
    vector<int>m_vZeros;
    int m_iProduct, m_iZeros, m_iSize;
public:
    ProductOfNumbers(){
        m_iSize = m_iProduct = 1, m_iZeros = 0;
        m_vProduct.push_back(m_iProduct);
        m_vZeros.push_back(m_iZeros);
    }

    void add(int num) {
        ++m_iSize;
        if( num == 0 ){
            m_iProduct = 1;
            m_iZeros += 1;
        }else{
            m_iProduct *= num;
        }
        m_vProduct.push_back(m_iProduct);
        m_vZeros.push_back(m_iZeros);
    }

    int getProduct(int k){
        int product = 0;
        if( m_vZeros[m_iSize-1] == m_vZeros[m_iSize-k-1] ){
            product = m_vProduct[m_iSize-1] / m_vProduct[m_iSize-k-1];
        }
        return product;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
