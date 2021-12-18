class SORTracker {
    set<pair<int,string>>st;
    set<pair<int,string>>::iterator pos;
public:
    SORTracker() {
        pos = st.end();
    }
    
    void add(string name, int score) {
        st.insert({-score,name});
        if( pos == st.end() || make_pair(-score,name) < *pos ){
            --pos;
        }
        
    }
    
    string get() {
        string name = pos->second;
        ++pos;
        return name;
        
    }
};

/**
 * Your SORTracker object will be instantiated and called as such:
 * SORTracker* obj = new SORTracker();
 * obj->add(name,score);
 * string param_2 = obj->get();
 */
