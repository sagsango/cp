// https://leetcode.com/problems/maximum-frequency-stack/
/*
	 Design a stack-like data structure to push elements to the stack and pop the most frequent element from the stack.

Implement the FreqStack class:

FreqStack() constructs an empty frequency stack.
void push(int val) pushes an integer val onto the top of the stack.
int pop() removes and returns the most frequent element in the stack.
If there is a tie for the most frequent element, the element closest to the stack's top is removed and returned.

*/




// see editorial


/*
	 O(1)
	 list<pair<int,stack<int>>m_listFrequencyStack
	 unorderd_map<int,int>m_mapKeyFrequency

	 //TODO: see second solution, from line 74.
*/

class FreqStack {
    list<pair<int,stack<int>>>m_listFrequencyStack; // TODO: list<stack<int>> will be sufficient.
		unordered_map<int,list<pair<int,stack<int>>>::iterator>m_mapKeyListptr;
public:
    FreqStack() {
    }
    
    void push(int val) {
        list<pair<int,stack<int>>>::iterator it;
        if( m_mapKeyListptr.find(val) == m_mapKeyListptr.end() ){
            if(m_listFrequencyStack.empty()){
                m_listFrequencyStack.push_front({1,{}});
            }
            it = m_listFrequencyStack.begin();
        }else{
            it = m_mapKeyListptr[val];
            int old_freq = it->first;
            int new_freq = it->first + 1;
            ++it;
            if( it == m_listFrequencyStack.end() ){
                m_listFrequencyStack.insert(it,{new_freq,{}});
                --it;
            }
        }
        m_mapKeyListptr[val] = it;
        it->second.push(val);
    }

    int pop() {
        int val = -1;
        if( ! m_listFrequencyStack.empty() ){
            list<pair<int,stack<int>>>::iterator it = --m_listFrequencyStack.end();
            val = it->second.top();
            it->second.pop();
            
            m_mapKeyListptr.erase(val);
            
            if( it != m_listFrequencyStack.begin() ){
                 m_mapKeyListptr[val] = --it;
            }
            
            if( m_listFrequencyStack.back().second.empty() ){
                m_listFrequencyStack.pop_back();
            }
            
        }
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */




class FreqStack {
public:
    unordered_map<int,stack<int>>ms;
    unordered_map<int,int>freq;
    int maxfreq=INT_MIN;
    FreqStack() {
          freq.clear();
         ms.clear();
         maxfreq=INT_MIN;
    }

    void push(int val) {
        freq[val]++;
        maxfreq=max(maxfreq,freq[val]);
        ms[freq[val]].push(val);
    }

    int pop() {
        int x=ms[maxfreq].top();
        ms[maxfreq].pop();
        freq[x]--;

        if(ms[maxfreq].size()==0)
        {
            maxfreq--;
        }
        return x;
    }
};
