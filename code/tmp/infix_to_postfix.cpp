#include <iostream>
#include <stack>
#include <string>

using namespace std;

int priority(char c){
	switch(c) {
		case '%': return 1;
		case '*': return 1;
		case '/': return 1;
		case '+': return 0;
		case '-': return 0;
	}
	return -1;
}

int main() {
	string infix; cin >> infix;

	stack<char>st;
	string postfix;
	
	/* We want always brackets the whole expression */
	infix = '(' + infix + ')'; 

	for(auto c: infix) {
		switch(c) {
			case '(':
				st.push(c);
				break;
			case ')':
				while(st.top() != '(') {
					postfix.push_back(st.top());
					st.pop();
				}
				st.pop();
				break;
			case '+':
			case '-':
			case '*':
			case '%':
			case '/':
				/*
						4+8/2 -> 482/+
						8/2+4 -> 82/4+
				*/
				while ( st.top() != '(' && priority(st.top())  >  priority(c)) {
					postfix.push_back(st.top());
					st.pop();
				}
				st.push(c);
				break;
			default: /* operand */
				postfix.push_back(c);
		}
	}
	cout << postfix << endl;
}

