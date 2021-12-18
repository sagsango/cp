// https://leetcode.com/problems/implement-trie-prefix-tree/
/*
	 A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and retrieve keys in a dataset of strings. 
	 There are various applications of this data structure, such as autocomplete and spellchecker.

	 Implement the Trie class:

	 Trie() Initializes the trie object.
	 void insert(String word) Inserts the string word into the trie.
	 boolean search(String word) Returns true if the string word is in the trie (i.e., was inserted before), and false otherwise.
	 boolean startsWith(String prefix) Returns true if there is a previously inserted string word that has the prefix prefix, and false otherwise.


	 Example 1:

	 Input
	 ["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
	 [[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
	 Output
	 [null, null, true, false, true, null, true]

	 Explanation
	 Trie trie = new Trie();
	 trie.insert("apple");
	 trie.search("apple");   // return True
	 trie.search("app");     // return False
	 trie.startsWith("app"); // return True
	 trie.insert("app");
	 trie.search("app");     // return True


Constraints:

1 <= word.length, prefix.length <= 2000
word and prefix consist only of lowercase English letters.
At most 3 * 104 calls in total will be made to insert, search, and startsWith.
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
