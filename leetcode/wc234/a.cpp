struct tri{
	tri * c[10];
	int leaf;
	tri(){
		for(int i=0;i<10;++i){
			c[i] = NULL;
		}
		leaf = 0;
	}
};

tri * head;

void insert(string s){
	int i = 0, n = s.length();
	while( i < n && s[i] == '0' )
		++i;
	tri * cur = head;
	while( i < n ){
		if( cur->c[ s[i] -'0'] == NULL ) cur->c[ s[i] -'0' ] = new tri();
		cur = cur->c[ s[i] -'0' ];
		++i;
	}
	cur->leaf = 1;
}

int count(tri * head ){
	if( head == NULL )
		return 0;
	int cnt = head->leaf;
	for(int i=0;i<10;++i){
		cnt += count(head->c[i]);
	}
	return cnt;
}


class Solution {
	public:
		int numDifferentIntegers(string word){
			head = new tri();
			int i = 0, n = word.length();
			while( i < n ){
				if( word[i] <= '9' && word[i] >= '0'){
					string s;
					int j = i;
					while( j < n && word[j] <= '9' && word[j] >= '0'){
						s += word[j];
						++j;
					}
					insert(s);
					i = j;
				}else
					i++;
			}
			return count(head);

		}
};
