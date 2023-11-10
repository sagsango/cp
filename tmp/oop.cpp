//
//  blank.cpp
//  
//
//  Created by Sagar Singh on 17/12/20.
//
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <numeric>
#include <sstream>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <cstdlib>
#include <cstdio>
#include <iterator>
#include <functional>
#include <bitset>
#include <unordered_map>
#include <unordered_set>
#define bug1( x )                   { cerr << (#x) <<"="<< x << endl; }
#define bug2( x , y )               { cerr << (#x) <<"="<< (x) << "    " << (#y) << "="<< (y) << endl; }
#define bug3( x , y , z )           { cerr << (#x) <<"="<<(x) << "    " << (#y) <<"="<< (y) << "    " << (#z) <<"="<< (z) << endl; }
#define bug4( x , y , z , w)        { cerr << (#x) <<"="<<(x) << "    " << (#y) <<"="<< (y) << "    " << (#z) <<"="<< (z) << "    " << (#w) <<"="<< w << endl; }
#define bug5( x , y , z , w ,p)     { cerr << (#x) <<"="<<(x) << "    " << (#y) <<"="<< (y) << "    " << (#z) <<"="<< (z) << "    " << (#w) <<"="<< w << "    " << (#p) <<"="<< p << endl; }
#define bug6( x , y , z , w ,p , q) { cerr << (#x) <<"="<<(x) << "    " << (#y) <<"="<< (y) << "    " << (#z) <<"="<< (z) << "    " << (#w) <<"="<< w << "    " << (#p) <<"="<< p << "    " << (#q) <<"="<< q << endl; }
#define bugn( x , n )               { cerr<<(#x)<<":";for(int i=0;i<n;i++)cout<<(#x)<<"["<<i<<"]:"<< x[i] << "    "; cout<<endl; }
#define bugnm( x , n , m )          { cerr<<(#x)<<endl;for(int i=0;i<n;i++){ cout<<"Row #"<<i<<":"; for(int j=0;j<m;j++) cout<<x[i][j]<<"     "; cout << endl;} }
typedef unsigned long long ul;
typedef long double ld;
typedef long long ll;
using namespace std;

/*
	 C++ opps
	 1. Fried Function
	 2. Virtual function and pure virtual function
	 3. Interface ( using pure virual function )
 */


// friend function
class classForFriendFunctionDemo{
	private:
		string msg;
	public:
		classForFriendFunctionDemo(){
			msg = "Im a privae member";
		}
		friend void tmpFunction(classForFriendFunctionDemo&);
};

void tmpFunction(classForFriendFunctionDemo &ob){
	cout << ob.msg << endl;
}
void demoFriend(){
	classForFriendFunctionDemo ob;
	tmpFunction(ob);
}



// Interface for multiple inharitance
class A{
	public :
		void a(){
			cout << "base a" << endl;
		}
		virtual void tmp() = 0; // pure virtual function
};
class B{
	public :
		void b(){
			cout << "base b" << endl;
		}
		virtual void tmp() = 0; // pure virtual function
};
class C : public A, public B{ // multiple inharitance
	public :
		void c(){
			cout << "devived c" << endl;

		}
		void tmp(){
			cout << "derived c" << endl;
		}
};
void multipleInharitance(){ // or interface
	C ob;
	ob.a();
	ob.b();
	ob.c();
	ob.tmp();
}




// pointers
class Pointers{
	private :
		int *n;
		int *m;
		int * a;
		int **b;
	public:
		Pointers(){
			cout << "Constructor : " <<  endl;
			n = new int(10);
			m = new int;
			*m = 20;

			a = new int[*n];
			b = new int*[*n];
			for(int i=0;i<*m;++i)
				b[i] = new int[*m];

			for(int i=0;i<*n;++i){
				for(int j=0;j<*m;++j)
					b[i][j] = i * (*m) + j;
				a[i] = i;
			}
		}
		~Pointers(){
			cout << "Distructor : " << endl;
			for(int i=0;i<*n;++i){
				delete [] b[i];
			}
			delete [] a;
			delete [] b;
			delete n;
			delete m;
		}
		void show(){
			cout << "n:" << *n << endl;
			cout << "m:" << *m << endl;
			for(int i=0;i<*n;++i)
				cout << a[i] <<" ";
			cout << endl << endl;
			for(int i=0;i<*n;++i){
				for(int j=0;j<*m;++j){
					cout << b[i][j] << " ";
				}
				cout << endl;
			}
		}
};
void demoPointer(){
	Pointers ob1;
	Pointers *p = new Pointers();
	ob1.show();
	p->show();
	delete p; // now distructore of p referace object will be called

}

int main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//demoFriend();
	//multipleInharitance();
	demoPointer();
}

