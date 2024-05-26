// https://leetcode.com/problems/design-add-and-search-words-data-structure/
/*
	 Design a data structure that supports adding new words and finding if a string matches any previously added string.

	 Implement the WordDictionary class:

	 WordDictionary() Initializes the object.
	 void addWord(word) Adds word to the data structure, it can be matched later.
	 bool search(word) Returns true if there is any string in the data structure that matches word or false otherwise.
	 									word may contain dots '.' where dots can be matched with any letter.


	 Example

	 Input
	 ["WordDictionary","addWord","addWord","addWord","search","search","search","search"]
	 [[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]
	 Output
	 [null,null,null,null,false,true,true,true]

	 Explanation
	 WordDictionary wordDictionary = new WordDictionary();
	 wordDictionary.addWord("bad");
	 wordDictionary.addWord("dad");
	 wordDictionary.addWord("mad");
	 wordDictionary.search("pad"); // return False
	 wordDictionary.search("bad"); // return True
	 wordDictionary.search(".ad"); // return True
	 wordDictionary.search("b.."); // return True


	 Constraints

	 1 <= word.length <= 500
	 word in addWord consists lower-case English letters.
	 word in search consist of  '.' or lower-case English letters.
	 At most 50000 calls will be made to addWord and search.
 */
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
