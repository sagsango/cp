// https://leetcode.com/problems/sequentially-ordinal-rank-tracker/
/*
	 A scenic location is represented by its name and attractiveness score, where name is a unique string among all locations and score is an integer.
	 Locations can be ranked from the best to the worst. The higher the score, the better the location. If the scores of two locations are equal, 
	 then the location with the lexicographically smaller name is better.

	 You are building a system that tracks the ranking of locations with the system initially starting with no locations. It supports:

	 Adding scenic locations, one at a time.
	 Querying the ith best location of all locations already added, where i is the number of times the system has been queried (including the current query).
	 For example, when the system is queried for the 4th time, it returns the 4th best location of all locations already added.
	 Note that the test data are generated so that at any time, the number of queries does not exceed the number of locations added to the system.

	 Implement the SORTracker class:

	 SORTracker() Initializes the tracker system.
	 void add(string name, int score) Adds a scenic location with name and score to the system.
	 string get() Queries and returns the ith best location, where i is the number of times this method has been invoked (including this invocation).
 */



/*
// TODO: Using set
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
*/


// using 2 heaps
class SORTracker {
public:
    SORTracker() : number_of_get(0) {}

    void add(string name, int score) {
        min_heap.push(make_pair(score, name));
        while (min_heap.size() > number_of_get) {
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
    }

    string get() {
        auto p = max_heap.top();
        min_heap.push(p);
        max_heap.pop();
        ++number_of_get;
        return p.second;
    }

private:
    struct Compare1 { // comparator for min_heap
        bool operator()(const pair<int, string>& a, const pair<int, string>& b)
        {
            if (a.first != b.first) {
                return a.first > b.first;
            } else {
                return a.second < b.second;
            }
        }
    };

    struct Compare2 { // comparator for max_heap
        bool operator()(const pair<int, string>& a, const pair<int, string>& b)
        {
            if (a.first != b.first) {
                return a.first < b.first;
            } else {
                return a.second > b.second;
            }
        }
    };

    priority_queue<pair<int, string>, vector<pair<int, string>>, Compare1> min_heap; // store number_of_get lowest-ranked locations
    priority_queue<pair<int, string>, vector<pair<int, string>>, Compare2> max_heap; // store the rest of the locations
    int number_of_get; // number of get() requests so far
};

/**
 * Your SORTracker object will be instantiated and called as such:
 * SORTracker* obj = new SORTracker();
 * obj->add(name,score);
 * string param_2 = obj->get();
 */
