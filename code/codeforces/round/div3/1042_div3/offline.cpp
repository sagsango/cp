// -------------------------------------------------------------------------------------------------------------------------------------
n + n/2 + n/3 + n/4 + n/5 + ........n/n =>n*log(n)
n + n/3 + n/5 + n/7 + n/11+.............=>n*log(log(n))
1 , 3 , 5 , 7 , 9 , 11 , 13 , 15 .......=>gcd( a[i] , a[i+1] , a[i+2] )=1;
2 , 3 , 5 , 7 , 11 , 13 , 17 , 19 ......=>upto 1e6 max diff a[i], a[i+1] ~ 150
no of divisores of n = cbrt(n)
form 1 to 1e5 : max divisors one number have = 128
form 1 to 1e6 : max divisors one number have = 240
N ~ 1e9 , have maximum 30 unique prime factors 2^30 ~ 1e9 , even much less than that
for n >= 3 there is a prime numner in interval [ n , (3/2)*n ].
Every even integer greater than 2 can be expressed as the sum of two primes.[1]  : https://en.wikipedia.org/wiki/Goldbach%27s_conjecture


Prime Number List =>   http://compoasso.free.fr/primelistweb/page/prime/liste_online_en.php
29    31    37    41    43
47    53    59    61    67    71    73    79    83    89
1000000007    1000000009    1000000021    1000000033    1000000087    1000000093
1000000097    1000000103    1000000123    1000000181    1000000207    1000000223    1000000241    1000000271    1000000289    1000000297
// -------------------------------------------------------------------------------------------------------------------------------------

// -------------------------------------------------------------------------------------------------------------------------------------

TODO: TOP OF THE CODE PUT THESE LINES FOR OPTIMIZATION
#pragma GCC target("popcnt")
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native"


typedef pair<ii,int> iii;
#define e1 first.first
#define e2 first.second
#define e3 second

const long double PI = 3.14159265358979323846264338327950288419716939937510;

ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);

cout << fixed << setprecision(10) << M_PI <<endl;

memset(array, 0, sizeof(array[0][0]) * m * n);
memset(array, 0, sizeof(array))

bool valid(int x,int y,int n,int m){
    return x >=0 && x < n && y >=0 && y < m;
}

bool valid(int x,int y){
    return x >=0 && x < n && y >=0 && y < m;
}
 
int dx[8]={0,1,1,1,0,-1,-1,-1};
int dy[8]={1,1,0,-1,-1,-1,0,1};

int dx[6]={1,-1,0,0,0,0};
int dy[6]={0,0,1,-1,0,0};
int dz[6]={0,0,0,0,1,-1};
 
const int dx[4] = {+1,-1,+0,-0};
const int dy[4] = {+0,-0,+1,-1};


// Knight Moves
const vector<int>dx={-1,-1,+1,+1,-2,-2,+2,+2};
const vector<int>dy={+2,-2,+2,-2,+1,-1,+1,-1};

int lowbit(int n){return n&(-n);}
toggle least set bit  n=n&(n-1); // becomes zero if power of 2
__builtin_popcountl(x); //return number of 1 in binary representation of x
builtin_ctz (count trailing zeros)
builtin_clz (count leading zeros)


https://gcc.gnu.org/onlinedocs/gcc/Integer-Overflow-Builtins.html
 __builtin_add_overflow(a,b,&sum); // { sum = a + b ; return  overflow(sum) : 1 : 0 }
 __builtin_sub_overflow(a,b,&sub); // { sub = a - b ; return  overflow(sub) : 1 : 0 }
 __builtin_mul_overflow(a,b,&mul); // { mul = a * b ; return  overflow(mul) : 1 : 0 }
 __builtin_popcount(x);

printf("%03d\n",k);
scanf("%d/%d/%d",&d,&m,&y);
// -------------------------------------------------------------------------------------------------------------------------------------

// -------------------------------------------------------------------------------------------------------------------------------------
// array or vector
struct box{
    int x , y ;
    bool operator <(const box other)const{
         // have to provide total ordering
        return  x < other.x; // front will be smaller
    }
};
vector<box>a;
sort(a.begin(),a.end());


struct box{
    int x,y,i;
};
vector<box>a;
sort(a.begin(),a.end(),
    [&](const box A,const box B){
        return A.x < B.x;
    }
);

struct marks{
    int m1,m2;
};
bool compare(marks a,marks b)
{
    if( a.m1 > b.m1); // non increasing : 3 3 2 2 1 0 -1
}
sort(a.begin(),a.end(),compare);
// -------------------------------------------------------------------------------------------------------------------------------------

// -------------------------------------------------------------------------------------------------------------------------------------
// priority queue using costom sort //
struct box {
    int  h , x , y ;
    bool operator < ( const box& other ) const {
        // We do not need to provide total ordering like sorting
        return h < other.h; // top will be bigger
    }
};
priority_queue<box>pq;

class compare{
    public:
    bool operator ()( ii x ,ii y)
    {
        if( x.first != y.first )return x.first > y.first;//non decreasing
        else return x.second < y.second;//non increasing
    }
};
priority_queue< ii , vector<ii> , compare > pq;
// -------------------------------------------------------------------------------------------------------------------------------------

// -------------------------------------------------------------------------------------------------------------------------------------
// set or multiset
struct box{
    int a,b;
    bool operator <(const box &other)const{
        if( a != other.a ) return a <other.a;
        return b < other.b;
    }
};
set<box>st;


https://codeforces.com/blog/entry/80257
struct cmp {
    bool operator() (int a, int b) const {
         return a < b;
    }
};
set<int,cmp>st;
// -------------------------------------------------------------------------------------------------------------------------------------

// -------------------------------------------------------------------------------------------------------------------------------------
// map or multimap
struct box{
    int a,b;
    bool operator <(const box &other)const{
        if( a != other.a ) return a <other.a;
        return b < other.b;
    }
};
map<box,int>mp;


https://codeforces.com/blog/entry/64928
struct Event{
    int d, w, t;
    bool operator < (const Event &e) const {
        return w > e.w || (w == e.w && d > e.d);
    }
};
vector<Event> e[N];
Event a[N];
map<Event, int> cur;
// -------------------------------------------------------------------------------------------------------------------------------------

// -------------------------------------------------------------------------------------------------------------------------------------
// Lembda Expression:
 vector<int>a={1,4,5,2};
 vector<int>b={4,2,3,4};
 vector<int>c={0,1,2,3};
 auto check = [&](int i,int j){
    return a[i] + b[i] < a[j] + b[j];
 };
 sort(c.begin(),c.end(),check);
 
 
 auto Adder = [&](int a,int b){
     return a+b;
 }
 int k = Adder(10,12);
 
 
function<void(int)>dfs =[&](int u){
    vis[u]=1;
    for(auto v:g[u]){
        if(!vis[v]){
            dfs(v);
            d = max( d , dis[u] + dis[v] + 1);
            dis[u] = max(dis[u] , dis[v] + 1);
        }
    }
};
// -------------------------------------------------------------------------------------------------------------------------------------

// -------------------------------------------------------------------------------------------------------------------------------------
// vector
sort(v.begin(),v.end())
sort(v.begin(),v.end()) with - v[i] = sort(v.rbegin(),v.rend())
sort(v.begin()+l_index,v.begin()+r_index+1);

reverse(v.begin(),v.end())

(bool) binary_search(v.begin(),v.end(),key)
(iterator) lower_bound(v.begin(),v.end(),key);
(iterator) upper_bound(v.bein(),v.end(),key);

v.erase(v.begin()+i)
v.erase(unique(v.begin(),v.end()),v.end())
v.erase(v.begin()+i,v.end()-j)  ||    v.erase(v.begin(),v.begin()+j)
v.erase(remove(v.begin(),v.end(),data),v.end())  //erase  all the 'data' from the vector
v.erase(v.begin(),v.upper_bound(data)) //all element lower or equal to data are deleted

(bool)next_premutation(v.begin(),v.end())
(bool)prev_premutation(v.begin(),v.end())

v.insert(it,data) || v.insert(i,data)
v.insert(it,no_of_times,data) || v.insert(i,no_of_times,data)

v.push_back(data)
v.pop_back(data)
(data) v.front()
(data) v.back()
(data) v[index]

(iterator) v.begin()
(iterator) v.end()

vector<vector<int>>v(r,vector<int>(c));
 
set_union (v1.begin(),v1.end(),v2.begin(),v2.end(),back_inserter(v3)) //v1,v2 are sorted and v3 is new container
set_intersection(v1.begin(),v1.end(),v2.begin(),v2.end(),back_inserter(v3)) //v1,v2 are sorted and v3 is new container
set_difference(v1.begin(),v1.end(),v2.begin(),v2.end(),back_inserter(v3)) //v1,v2 are sorted and v3 is new container
set_symmetric_difference(v1.begin(),v1.end(),v2.begin(),v2.end(),back_inserter(v3)) //v1,v2 are sorted and v3 is new container
// -------------------------------------------------------------------------------------------------------------------------------------

// -------------------------------------------------------------------------------------------------------------------------------------
// pair<int,int>
vector<pair<data_type,data_type>> vp
vp.push_back(make_pair(key,data))

//sort by first element then second
sort(vp.begin(),vp.end())

//sort by sec element(only by sec)
bool sortbysec(const pair<int,int> &a, const pair<int,int> &b){
    if( a.second != b.second )return (a.second < b.second);
    return a.first < b.first
}
sort(vp.begin(),vp.end(),sortbysec)
(data) vp[i].first
(data) vp[i].second
// -------------------------------------------------------------------------------------------------------------------------------------

// -------------------------------------------------------------------------------------------------------------------------------------
// string
string str2 = str1
string str2=str1.substr(index_1,len)

transform(s1.begin(), s1.end(), s1.begin(), ::toupper);
transform(s2.begin(), s2.end(), s2.begin(), ::toupper);

int (index) = str.find("substr")     //first starting index of substr

s.erase(s.begin()+index)
s.erase(s.begin()+index,s.end()-index)  ||  s.erase(s.begin()+index(),s.begin()+index)
s.erase(unique(s.begin(),s.end()),s.end())  ::adjecent will not be same
str.erase(remove(str.begin(),str.end(),'ch'),str.end()); //erase all the 'ch' from string

sort(s.begin(),s.end());
reverse(s.begin(),s.end())
reverse(s.begin()+i,s.begin()+j+1);  //from index i to j  ,NOT SAME AS VECTOR

str1.insert(6, str2);
str.insert(it,'ch')  ||  str.insert(i,'ch')
str.insert(it,no_of_times,'ch') ||  str.insert(i,no_of_times,'ch')
auto c=count(str.begin(),str.end(),'char') //count all char in the given string

cin.egnore();//add this before getline()
getline(cin,string_name)

stringstream(string_name)>>type1_>>type2_>>type3_.........>>typeN_;
stringstream STREAM_name(string_name)
STREAM_name>>type1_>>type2_>>type3>>type4_>>type5_;
s=to_string(2018)
// -------------------------------------------------------------------------------------------------------------------------------------

// -------------------------------------------------------------------------------------------------------------------------------------
stack<data_type>s
push()              :s.push(data)           :O(1)
pop()               :s.pop()                :O(1)
top()               :s.top()                :O(1)
empty()             :s.empty()              :O(1)
size()              :s.size()               :O(1)
// -------------------------------------------------------------------------------------------------------------------------------------

// -------------------------------------------------------------------------------------------------------------------------------------
queue<data_type>q
push()               :q.push(data)          :O(1)
pop()                :q.pop()               :O(1)
front()              :q.front()             :O(1)
back()               :q.back()              :O(1)
empty()              :q.empty()             :O(1)
size()               :q.size()              :O(1)
data = q[index]
// -------------------------------------------------------------------------------------------------------------------------------------

// -------------------------------------------------------------------------------------------------------------------------------------
deque<data_type>q
push_front()               :q.push(data)          :O(1)
push_back()                :q.push(data)          :O(1)
pop_front()                :q.pop()               :O(1)
pop_back()                 :q.pop()               :O(1)
front()                    :q.front()             :O(1)
back()                     :q.back()              :O(1)
empty()                    :q.empty()             :O(1)
size()                     :q.size()              :O(1)
data = q[index]
// -------------------------------------------------------------------------------------------------------------------------------------

// -------------------------------------------------------------------------------------------------------------------------------------
priority_queue<data_type>pq
priority_queue <int, vector<int>, greater<int> > pq;
push()               :pq.push(data)         :O(log(n))
pop()                :pq.pop()              :O(long(n))
top()                :pq.top()              :O(1)
size()               :pq.size()             :O(1)
empty()              :pq.empty()            :O(1)
// -------------------------------------------------------------------------------------------------------------------------------------

// -------------------------------------------------------------------------------------------------------------------------------------
// set
declare         :set<int>
                :set<int,greater<int>>s
insertion       :s.insert(data)  //insert if it is not present     :O(log(n))
size            :s.size()                                          :O(1)
find            :auto it=s.find(data) //if it!=s.end -> data found :O(log(n))
s.lower_bound() :it=s.lower_bound(data)
s.upper_bound() :it=s.upper_bound(data)
erase()         :erase(it)
erase()         :s.erase(it1,it2)
s.erase()       :s.erase(data)
loop            :for(auto it=s.begin();it!=s.end();it++)
s.rbegin()=*(--s.end())
// -------------------------------------------------------------------------------------------------------------------------------------

// -------------------------------------------------------------------------------------------------------------------------------------
// map
declaration   :map<key_type,data_type>m
declaration   :map<int,string,greater<int>>M
insert        :m.insert(make_pair(key,data));                     :O(log(n))
              :m.insert(pair<type,type>(key,data))
find          :auto it=m.find(key) //if(it!=m.end)it->first=key   :O(log(n))
[]            :m[key]++      //data=data+1 ,at that key           :O(log(n))
size          :m.size()                                           :O(1)
m.lower_bound :it=m.lower_bound(key)
m.upper_bound :it=m.lower_bound(key)
erase()       :s.erase(it)
              :s.erase(it1,it2)
              :s.erase(key)
loop          :for(auto it=m.begin();it!=s.end();it++)
it->first ,it->second ,
// -------------------------------------------------------------------------------------------------------------------------------------

// -------------------------------------------------------------------------------------------------------------------------------------
// unordered_map
declaration   :unordered_set<lli>s
unordered_set<int,greater<int>>s;
insertion     :s.insert(data)                                     :O(1)
size          :s.size()                                           :O(1)
find          :auto it=s.find(data)//if it!=s.end ->data found    :O(1)     ||  worst case O(n)
loop          :for(auto it=s.begin();it!=s.end();it++)
// -------------------------------------------------------------------------------------------------------------------------------------

// -------------------------------------------------------------------------------------------------------------------------------------
// unordered_set
declaration   :unorderd_map<key_type,data_type> m
unorderded_map<int,string,greater<int>>M
insert        :insert(make_pair(key,data))                        :O(1)
find          :auto it=m.find(key) //if (it!=m.end)it->first=key  :O(1)
[]            :m[key]++      //data=data+1 ,at that key           :O(1)
size          :m.size()                                           :O(1)
loop          :for(auto it=s.begin();it!=s.end();it++)
// -------------------------------------------------------------------------------------------------------------------------------------

// -------------------------------------------------------------------------------------------------------------------------------------
// multiset
multiset<data_type>ms        multiset<int,greater<int>>ms
insert()               :ms.insert(data)         :O(log(n))
find()                 :auto it=ms.find(data)   :O(long(n))
erase()                :ms.erase(it)
                       :ms.erase(data)          : all the data instances will be deleated
                       :ms.erase(ms.find(data)) : 1 instances of data will be deleated
size()                 :ms.size()               :O(1)
// -------------------------------------------------------------------------------------------------------------------------------------

// -------------------------------------------------------------------------------------------------------------------------------------
// multimap
mulimap<key_type,data_type>mm
multimap<int,string,greater<int>>mm

mm.insert(pair<key_type,data_type>(key,data))
it=mm.find(key)  //first it   :O(long(n))
mm.lower_bound(key)->second //data      mm.lower_bound(key)=it  1st elemet having the key  or mm.end()
mm.upper_bound(key)->second //data      mm.upper_bound(key)=it  1st element just after the key or mm.end()
mm.erase(key)         :erase all element of the key value
mp.erase(mp.find(key)):only 1 will be deleted
mm.erase(mm.begin(),mm.find(key))    :remove all having(key) less than the given key
mm.size()
for(auto it=mm.begin();it!=mm.end;it++)     :traversal
// -------------------------------------------------------------------------------------------------------------------------------------

// -------------------------------------------------------------------------------------------------------------------------------------
// list
advantage: quick insertion and deletion ,bigger size
disadvantage: slow traversal
list<data_type>l
(data) l.front()
(data) l.back()
l.push_front(data)
l.push_back(data)
l.pop_front()
l.pop_back()
(it) l.begin()
(it) l.end()
(bool) l.empty()
// -------------------------------------------------------------------------------------------------------------------------------------

// -------------------------------------------------------------------------------------------------------------------------------------
// redBlackTree
ordered_set<int>  s;
    s.insert(1);
    s.insert(3);
    cout << s.order_of_key(2) << endl; // tnumber of items in a set that are strictly smaller than k=2           log(no of elements)
    cout << *s.find_by_order(0) << endl; // returns an iterator to the k=0 [ or index ] largest element (counting from zero), log(no of elements)
// -------------------------------------------------------------------------------------------------------------------------------------

