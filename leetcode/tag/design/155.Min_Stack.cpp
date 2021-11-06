// https://leetcode.com/problems/min-stack/
class MinStack {
    stack<pair<int,int>>m_stack;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        int min_val = val;
        if( m_stack.size() ){
            min_val = min( min_val, m_stack.top().second );
        }
        m_stack.push({val,min_val});
        
    }
    
    void pop() {
        m_stack.pop();
        
        
    }
    
    int top() {
        return m_stack.top().first;
        
    }
    
    int getMin() {
        return m_stack.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
