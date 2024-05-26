// https://codingcompetitions.withgoogle.com/codejam/round/000000000019fd27/0000000000209a9e

#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

class B10solver{
	public :
	void print(vector<int>&a)
	{
		string s;
		for(int i=0;i<10;i++)
		s+=a[i]+'0';
		cout<<s<<endl;
		fflush(stdout);
	}
	void solve()
	{
		int x,y,z,w;
		vector<int>a(10);

		for(int i=0;i<10;i++)
		{
			cout<<i+1<<endl;
			fflush(stdout);
			cin>>x;
			a[i]=x;
		}

		vector<int>b=a;
		vector<int>c=a;
		vector<int>d=a;
		reverse(c.begin(),c.end());
		reverse(d.begin(),d.end());
		for(int i=0;i<10;i++)
		{
			b[i]^=1;
			d[i]^=1;
		}

		int xi = -1 , yi = -1;
		for(int i=0;i<10;i++)
		{
			if( a[i] != a[10-i-1] )
			{
				xi=i;
				yi=10-i-1;
			}
		}

		if( xi == -1 ){
			xi=0;
			yi=9;
		}

		int zi=-1,wi=-1;
		for(int i=0;i<10;i++)
		{
			if( a[i]==a[10-i-1] )
			{
				zi=i;
				wi=10-i-1;
			}
		}
		if( zi == -1 ){
			zi=1;
			wi=8;
		}


		cout << xi+1 << endl;
		fflush(stdout);
		cin >>  x;

		cout << yi+1 << endl;
		fflush(stdout);
		cin >> y;

		cout << zi+1 << endl;
		fflush(stdout);
		cin >>  z;

		cout << wi+1 << endl;
		fflush(stdout);
		cin >> w;

		if( a[xi] == x && a[yi] == y && a[zi]==z && a[wi]==w )print(a);
		else if( b[xi] ==x && b[yi] == y && b[zi]==z && b[wi]==w )print(b);
		else if( c[xi] ==x && c[yi] == y && c[zi]==z && c[wi]==w )print(c);
		else print(d);

		char status;cin>>status;
		if(status=='N')exit(-1);
	}

};


class B20solver{
	public:
	int  px , py , pz , pw , x , y , z , w , B0 , B1 ;   
	int range;
	vector<int>a,b,c,d;
	vector<int>A,B,C,D;
	B20solver()
	{
		range = 20;/**************  Should Change    *******************/
		a=vector<int>(range);
		b=vector<int>(range);
		c=vector<int>(range);
		d=vector<int>(range);
		
		A=vector<int>(range);
		B=vector<int>(range);
		C=vector<int>(range);
		D=vector<int>(range);
	}
	void HalfRangeSolver(int base1,int base2)
	{
		
		B0=base1;  // [0,5)
		B1=base2;  // [5,10)
		px=py=pz=pw=-1;
		for(int i=B0;i<B0+5;i++){
			if( a[i] == a[(range-i-1)] )px=i;
			if( a[i] != a[(range-i-1)] )py=i;
		}
		for(int i=B1;i<B1+5;i++){
			if( a[i] == a[(range-i-1)] )pz=i;
			if( a[i] != a[(range-i-1)] )pw=i;
		}
		if(px==-1)px=B0;
		if(py==-1)py=B0+1;
		if(pz==-1)pz=B1;
		if(pw==-1)pw=B1+1;
		
		cout<<px+1<<endl;fflush(stdout);cin>>x;
		cout<<py+1<<endl;fflush(stdout);cin>>y;
		cout<<pz+1<<endl;fflush(stdout);cin>>z;
		cout<<pw+1<<endl;fflush(stdout);cin>>w;
		
		if( (A[px]==x && A[py]==y && a[pz]==z && a[pw]==w)|| 
			(B[px]==x && B[py]==y && b[pz]==z && b[pw]==w)|| 
			(C[px]==x && C[py]==y && c[pz]==z && c[pw]==w)|| 
			(D[px]==x && D[py]==y && d[pz]==z && d[pw]==w) )
			
			for(int i=B1;i<B1+5;i++){
				A[i]=a[i];A[(range-i-1)]=a[(range-i-1)];
				B[i]=b[i];B[(range-i-1)]=b[(range-i-1)];
				C[i]=c[i];C[(range-i-1)]=c[(range-i-1)];
				D[i]=d[i];D[(range-i-1)]=d[(range-i-1)];
			}
			
		else if( (A[px]==x && A[py]==y && b[pz]==z && b[pw]==w)||
				 (B[px]==x && B[py]==y && a[pz]==z && a[pw]==w)||
				 (C[px]==x && C[py]==y && d[pz]==z && d[pw]==w)||
				 (D[px]==x && D[py]==y && c[pz]==z && c[pw]==w) )
				 
			 for(int i=B1;i<B1+5;i++){
				A[i]=b[i];A[(range-i-1)]=b[(range-i-1)];
				B[i]=a[i];B[(range-i-1)]=a[(range-i-1)];
				C[i]=d[i];C[(range-i-1)]=d[(range-i-1)];
				D[i]=c[i];D[(range-i-1)]=c[(range-i-1)];
			}
			
		else if( (A[px]==x && A[py]==y && c[pz]==z && c[pw]==w )||
		         (C[px]==x && C[py]==y && a[pz]==z && a[pw]==w )||
		         (B[px]==x && B[py]==y && d[pz]==z && d[pw]==w )||
		         (D[px]==x && D[py]==y && b[pz]==z && b[pw]==w ) )
		         
			for(int i=B1;i<B1+5;i++){
				A[i]=c[i];A[(range-i-1)]=c[(range-i-1)];
				B[i]=d[i];B[(range-i-1)]=d[(range-i-1)];
				C[i]=a[i];C[(range-i-1)]=a[(range-i-1)];
				D[i]=b[i];D[(range-i-1)]=b[(range-i-1)];
			}

		else {
			 /*if((A[px]==x && A[py]==y && d[pz]==z && d[pw]==w )||
		          (B[px]==x && B[py]==y && c[pz]==z && c[pw]==w )||
		          (C[px]==x && C[py]==y && b[pz]==z && b[pw]==w )||
		          (D[px]==x && D[py]==y && a[pz]==z && a[pw]==w ) )*/
		          
			for(int i=B1;i<B1+5;i++){
				A[i]=d[i];A[(range-i-1)]=d[(range-i-1)];
				B[i]=c[i];B[(range-i-1)]=c[(range-i-1)];
				C[i]=b[i];C[(range-i-1)]=b[(range-i-1)];
				D[i]=a[i];D[(range-i-1)]=a[(range-i-1)];
			}
		}
	}
	void solve()
	{
		for(int i=0;i<range/2;i++)
		{
			cout << i+1 << endl;
			fflush(stdout);
			cin >> x;
			a[i]=x;
			cout << (range-i-1) + 1 << endl;
			fflush(stdout);
			cin >> x;
			a[(range-i-1)]=x;
		}
		
		b=a;
		c=a;
		d=a;
		reverse(c.begin(),c.end());
		reverse(d.begin(),d.end());
		
		for(int i=0;i<range;i++)
		b[i]^=1,d[i]^=1;
		
		
		A=a;
		B=b;
		C=c;
		D=d;
		
		/************************  Should rewrite  *********************/
		HalfRangeSolver(0,5);
		
		
		string ans;
		px=py=-1;
		for(int i=0;i<range/2;i++)
		{
			if( A[i] == A[(range-i-1)] )px=i;
			if( A[i] != A[(range-i-1)] )py=i;
		}
		if( px==-1 )px=0;
		if( py==-1 )py=0;
		
		cout<<px+1<<endl;fflush(stdout); cin >> x;
		cout<<py+1<<endl;fflush(stdout); cin >> y;
		
		if( A[px] == x &&  A[py] == y ){
			for(int i=0;i<range;i++)
			ans+=A[i]+'0';
		}
		else if( B[px] == x && B[py]==y){
			for(int i=0;i<range;i++)
			ans+=B[i]+'0';
		}
		else if( C[px] == x && C[py]==y){
			for(int i=0;i<range;i++)
			ans+=C[i]+'0';
		}
		else {
			for(int i=0;i<range;i++)
			ans+=D[i]+'0';
		}
		cout << ans << endl;
		char status;cin>>status;
		if(status=='N')exit(-1);
	}
};

class B100solver{ // changed name
	public:
	int  px , py , pz , pw , x , y , z , w , B0 , B1 ;   
	int range;
	vector<int>a,b,c,d;
	vector<int>A,B,C,D;
	B100solver() // changed name
	{
		range = 100;/**************  Should Change    *******************/
		a=vector<int>(range);
		b=vector<int>(range);
		c=vector<int>(range);
		d=vector<int>(range);
		
		A=vector<int>(range);
		B=vector<int>(range);
		C=vector<int>(range);
		D=vector<int>(range);
	}
	void Waste_2_quries() // Written The function here
	{
		int wtx1=0 , wtx2=0;
		int wtc1=0 , wtc2=0;
		cout<<wtx1+1<<endl;fflush(stdout);cin>>wtc1;
		cout<<wtx2+1<<endl;fflush(stdout);cin>>wtc2;
	}
	void HalfRangeSolver(int base1,int base2)
	{
		
		B0=base1;  // [0,5)
		B1=base2;  // [5,10)
		px=py=pz=pw=-1;
		for(int i=B0;i<B0+5;i++){
			if( a[i] == a[(range-i-1)] )px=i;
			if( a[i] != a[(range-i-1)] )py=i;
		}
		for(int i=B1;i<B1+5;i++){
			if( a[i] == a[(range-i-1)] )pz=i;
			if( a[i] != a[(range-i-1)] )pw=i;
		}
		if(px==-1)px=B0;
		if(py==-1)py=B0+1;
		if(pz==-1)pz=B1;
		if(pw==-1)pw=B1+1;
		
		cout<<px+1<<endl;fflush(stdout);cin>>x;
		cout<<py+1<<endl;fflush(stdout);cin>>y;
		cout<<pz+1<<endl;fflush(stdout);cin>>z;
		cout<<pw+1<<endl;fflush(stdout);cin>>w;
		
		if( (A[px]==x && A[py]==y && a[pz]==z && a[pw]==w)|| 
			(B[px]==x && B[py]==y && b[pz]==z && b[pw]==w)|| 
			(C[px]==x && C[py]==y && c[pz]==z && c[pw]==w)|| 
			(D[px]==x && D[py]==y && d[pz]==z && d[pw]==w) )
			
			for(int i=B1;i<B1+5;i++){
				A[i]=a[i];A[(range-i-1)]=a[(range-i-1)];
				B[i]=b[i];B[(range-i-1)]=b[(range-i-1)];
				C[i]=c[i];C[(range-i-1)]=c[(range-i-1)];
				D[i]=d[i];D[(range-i-1)]=d[(range-i-1)];
			}
			
		else if( (A[px]==x && A[py]==y && b[pz]==z && b[pw]==w)||
				 (B[px]==x && B[py]==y && a[pz]==z && a[pw]==w)||
				 (C[px]==x && C[py]==y && d[pz]==z && d[pw]==w)||
				 (D[px]==x && D[py]==y && c[pz]==z && c[pw]==w) )
				 
			 for(int i=B1;i<B1+5;i++){
				A[i]=b[i];A[(range-i-1)]=b[(range-i-1)];
				B[i]=a[i];B[(range-i-1)]=a[(range-i-1)];
				C[i]=d[i];C[(range-i-1)]=d[(range-i-1)];
				D[i]=c[i];D[(range-i-1)]=c[(range-i-1)];
			}
			
		else if( (A[px]==x && A[py]==y && c[pz]==z && c[pw]==w )||
		         (C[px]==x && C[py]==y && a[pz]==z && a[pw]==w )||
		         (B[px]==x && B[py]==y && d[pz]==z && d[pw]==w )||
		         (D[px]==x && D[py]==y && b[pz]==z && b[pw]==w ) )
		         
			for(int i=B1;i<B1+5;i++){
				A[i]=c[i];A[(range-i-1)]=c[(range-i-1)];
				B[i]=d[i];B[(range-i-1)]=d[(range-i-1)];
				C[i]=a[i];C[(range-i-1)]=a[(range-i-1)];
				D[i]=b[i];D[(range-i-1)]=b[(range-i-1)];
			}

		else {
			 /*if((A[px]==x && A[py]==y && d[pz]==z && d[pw]==w )||
		          (B[px]==x && B[py]==y && c[pz]==z && c[pw]==w )||
		          (C[px]==x && C[py]==y && b[pz]==z && b[pw]==w )||
		          (D[px]==x && D[py]==y && a[pz]==z && a[pw]==w ) )*/
		          
			for(int i=B1;i<B1+5;i++){
				A[i]=d[i];A[(range-i-1)]=d[(range-i-1)];
				B[i]=c[i];B[(range-i-1)]=c[(range-i-1)];
				C[i]=b[i];C[(range-i-1)]=b[(range-i-1)];
				D[i]=a[i];D[(range-i-1)]=a[(range-i-1)];
			}
		}
	}
	void solve()
	{
		for(int i=0;i<range/2;i++)
		{
			cout << i+1 << endl;
			fflush(stdout);
			cin >> x;
			a[i]=x;
			cout << (range-i-1) + 1 << endl;
			fflush(stdout);
			cin >> x;
			a[(range-i-1)]=x;
		}
		
		b=a;
		c=a;
		d=a;
		reverse(c.begin(),c.end());
		reverse(d.begin(),d.end());
		
		for(int i=0;i<range;i++)
		b[i]^=1,d[i]^=1;
		
		
		A=a;
		B=b;
		C=c;
		D=d;
		
		/************************  Should rewrite  *********************/
		HalfRangeSolver(0,5); // [0 10)
		HalfRangeSolver(0,10);// [0 15)
		Waste_2_quries();
		HalfRangeSolver(0,15);// [0 20)
		HalfRangeSolver(0,20);// [0 25)
		Waste_2_quries();
		HalfRangeSolver(0,25);// [0 30)
		HalfRangeSolver(0,30);// [0 35)
		Waste_2_quries();
		HalfRangeSolver(0,35);// [0 40)
		HalfRangeSolver(0,40);// [0 45)
		Waste_2_quries();
		HalfRangeSolver(0,45);// [0 50)
		
		
		string ans;
		px=py=-1;
		for(int i=0;i<range/2;i++)
		{
			if( A[i] == A[(range-i-1)] )px=i;
			if( A[i] != A[(range-i-1)] )py=i;
		}
		if( px==-1 )px=0;
		if( py==-1 )py=1;
		
		cout<<px+1<<endl;fflush(stdout); cin >> x;
		cout<<py+1<<endl;fflush(stdout); cin >> y;
		
		if( A[px] == x &&  A[py] == y ){
			for(int i=0;i<range;i++)
			ans+=A[i]+'0';
		}
		else if( B[px] == x && B[py]==y){
			for(int i=0;i<range;i++)
			ans+=B[i]+'0';
		}
		else if( C[px] == x && C[py]==y){
			for(int i=0;i<range;i++)
			ans+=C[i]+'0';
		}
		else {
			for(int i=0;i<range;i++)
			ans+=D[i]+'0';
		}
		cout << ans << endl;
		char status;cin>>status;
		if(status=='N')exit(-1);
	}
};
		
int32_t main()
{
	int T,B;cin>>T>>B;
	for(int t=1;t<=T;t++)
	{
		if( B == 10 )
		{
			B10solver s;
			s.solve();
		}
		else if( B == 20 )
		{
			B20solver s;
			s.solve();
		}
		else 
		{
			B100solver s;
			s.solve();
		}
	}
}
