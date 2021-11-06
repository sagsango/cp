// https://leetcode.com/problems/serialize-and-deserialize-binary-tree/
// https://www.geeksforgeeks.org/serialize-deserialize-binary-tree/

/*
	 There are many ways to encode,
	 because we have been aksed for
	 a string we should use

	 string dfsAndSerialise( TreeNode * root ){
	    // ((rootValue)(leftSubtree)(rightSubtree))
	 		if( root == NULL )
				return "()"
			return "("  "(" + to_string(root->value) + ")" +  dfsAndSerialise( root->left ) + dfsAndSerialise( root->right ) + ")";
	 }

	 or

	 always represent NULL node = N, othersiwe its value // assuming values are char( digit/alphabets/char )



*/
