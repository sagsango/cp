/*



	 if( a == 1 ){
	 		x = 1 + k * b 
			x - 1 = k * b

			if( ( x - 1 ) % b == 0  )
				ok = 1
	}
	if( a != 1 ){
			
			auto solve = [&](int x){
				if( x == 1 )return 1;
				if( x % a == 0 && solve(x/a) )return 1;
				if( x > b && solve(x-b) )return 1;
				return 0;
			};

			if( solve(x) ){
				ok = 1;
			}
	}
*/

t=(int)(input())
for i in range(t):
    w=input().split()
    n=(int)(w[0])
    a=(int)(w[1])
    b=(int)(w[2])
    if a==1 :
    	if (n-1)%b==0 :
    		print("Yes")
    	else :
    		print("No")

    else :
    	t=1
    	flag=0
    	while t<=n :
    		if t%b==n%b:
    			flag=1
    			break
    		t=t*a
    	if flag==1:
    		print("Yes")
    	else :
    		print("No")
