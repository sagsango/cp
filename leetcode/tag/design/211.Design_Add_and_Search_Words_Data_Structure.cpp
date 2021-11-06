// https://leetcode.com/problems/design-add-and-search-words-data-structure/
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

class WordDictionary {
	TriNode * root;
	public:
	WordDictionary() {
		root = new TriNode();
	}

	~WordDictionary() {
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

	bool dfs_and_search(TriNode*root, int len, string &word){
		if( root ){
			if( len == word.length() )
				return root->word_end;
			if( word[len] == '.' ){
				for(int i=0;i<26;++i){
					if( dfs_and_search(root->c[i],len+1,word) )
						return true;
				}
			}else{
				if( dfs_and_search(root->c[ word[len] - 'a' ],len+1,word) )
					return true;
			}
		}
		return false;
	}

	void addWord(string word) {
		TriNode * cur_node = root;
		for(auto x:word){
			if( !cur_node->c[ x -'a' ] )
				cur_node->c[ x -'a'] = new TriNode();
			cur_node = cur_node->c[ x - 'a'];
		}
		cur_node->word_end = 1;
	}

	bool search(string _word) {
		string word = _word;
		return dfs_and_search(root,0,word);
	}
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
