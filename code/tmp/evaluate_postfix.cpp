#include <iostream>
#include <stack>
#include <string>

using namespace std;

int evaluate(int op1, int op2, char opcode){
	switch(opcode) {
		case '+': return op1 + op2;
		case '-': return op1 - op2;
		case '*': return op1 * op2;
		case '/': return op1 / op2;
		case '%': return op1 % op2;
	}
	return 0;
}

int main() {
	string postfix; cin >> postfix;


	stack<int>st;
	for(auto c:postfix){
		int operand1, operand2;
		switch(c){
			case '+':
			case '-':
			case '*':
			case '/':
			case '%':
				operand2 = st.top(); st.pop();
				operand1 = st.top(); st.pop();
				cout << operand1 << c << operand2 << evaluate(operand1, operand2, c) << endl;
				st.push(evaluate(operand1, operand2, c));
				break;
			default: /* operands */
				st.push(c - '0');
		}
	}
	cout << st.top() << endl;
}
