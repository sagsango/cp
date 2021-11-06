// https://leetcode.com/problems/implement-trie-prefix-tree/
struct TriNode{
	bool word_end;
	TriNode * c[26];
	TriNode(){
		word_end = false;
		for(int i=0;i<26;++i){
			c[i] = NULL;
		}
	}
};

class Trie {
	TriNode * root;
	public:
	Trie() {
		root = new TriNode();
	}

	~Trie(){
		dfs_and_delete(root);
	}

	void dfs_and_delete(TriNode*root){
		if( root ){
			for(int i=0;i<26;++i){
				dfs_and_delete(root->c[i]);
				root->c[i] = NULL;
			}
			delete root;
		}
	}

	void insert(string word) {
		TriNode * cur_node = root;
		for(auto x:word){
			if( !cur_node->c[ x -'a' ] )
				cur_node->c[ x -'a'] = new TriNode();
			cur_node = cur_node->c[ x - 'a'];
		}
		cur_node->word_end = 1;

	}

	bool search(string word) {
		TriNode * cur_node = root;
		for(auto x:word){
			if( !cur_node->c[ x -'a' ] )
				return false;
			cur_node = cur_node->c[ x - 'a'];
		}
		return cur_node->word_end;

	}

	bool startsWith(string prefix) {
		TriNode * cur_node = root;
		for(auto x:prefix){
			if( !cur_node->c[ x -'a' ] )
				return false;
			cur_node = cur_node->c[ x - 'a'];
		}
		return true;
	}
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
