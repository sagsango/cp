// https://leetcode.com/problems/range-sum-query-mutable/


// point update and range query tree
struct SegTree{
	struct Node{
		int val, sum; // TODO: here max, min, sum, anything can be added. ( val was not needed here).
	};
	Node * m_arr;
	SegTree(vector<int>&nums){
		int n = nums.size();
		m_arr = new Node[4*n]; // TODO: 4 * n ?, ( n leafs + n non leafs + when on leaf, right child = leaf_index (2*n) * 2 = 4 * n )
		BuildTree(1,1,n,nums);
	}
	~SegTree(){ // TODO: delete what you have allocated
		delete [] m_arr;
	}
	void BuildTree(int root,int tLeft,int tRight,vector<int>&nums){
		if( tLeft == tRight ){
			m_arr[root].val = m_arr[root].sum = nums[tLeft-1];
			return;
		}
		int left_child = root * 2;
		int right_child= root * 2 + 1;
		int tMid = (tLeft+tRight) /2;

		BuildTree(left_child,tLeft,tMid,nums);
		BuildTree(right_child,tMid+1,tRight,nums);
		m_arr[root].sum = m_arr[left_child].sum + m_arr[right_child].sum;
	}

	void UpdateNode(int root,int tLeft,int tRight,int node_index, int node_val){
		if( tLeft == tRight ){
			m_arr[root].val = m_arr[root].sum = node_val;
			return;
		}
		int left_child = root * 2;
		int right_child= root * 2 + 1;
		int tMid = (tLeft+tRight) / 2;

		if( node_index <= tMid ){
			UpdateNode(left_child,tLeft,tMid,node_index,node_val);
		}else{
			UpdateNode(right_child,tMid+1,tRight,node_index,node_val);
		}
		m_arr[root].sum = m_arr[left_child].sum + m_arr[right_child].sum;
	}

	int RangeSum(int root, int tLeft, int tRight, int qLeft, int qRight){
		if( qLeft > qRight ){ // TODO: Take Care here also
			return 0;
		}
		if( tLeft == qLeft && tRight == qRight ){
			return m_arr[root].sum;
		}
		int left_child = root * 2;
		int right_child= root * 2 + 1;
		int tMid = (tLeft+tRight) / 2;

		return RangeSum(left_child,tLeft,tMid,qLeft,min(tMid,qRight)) +
			RangeSum(right_child,tMid+1,tRight,max(tMid+1,qLeft),qRight);
	}
};



class NumArray {
	SegTree *tree;
	int size;
	public:
	NumArray(vector<int>& nums) {
		tree = new SegTree(nums);
		size = nums.size();
	}
	~NumArray(){
		delete tree; // TODO: delete what you allocated
	}

	void update(int index, int val) {
		tree->UpdateNode(1,1,size,index+1,val);
	}

	int sumRange(int left, int right) {
		return tree->RangeSum(1,1,size,left+1,right+1);

	}
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
