//https://leetcode.com/problems/snapshot-array/
class SnapshotArray {
public:
    int snapId;
    unordered_map<int, unordered_map<int, int> > mp;
    unordered_map<int, int> curMap;

    SnapshotArray(int length) {
        snapId = 0;
        mp.clear();
        curMap.clear();
    }

    void set(int index, int val) {
        curMap[index] = val;
    }

    int snap() {
        mp[snapId] = curMap;
        ++snapId;
        return snapId - 1;
    }

    int get(int index, int snap_id) {
        if (mp[snap_id].find(index) == mp[snap_id].end()) {
            return 0;
        }

        return mp[snap_id][index];
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
