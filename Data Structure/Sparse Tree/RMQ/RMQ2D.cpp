//Bismillah

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef pair<int,int> pii;
typedef pair<double, double> pdd;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;
typedef vector<pll> vll;
typedef double dl;

#define PB push_back
#define F first
#define S second
#define MP make_pair
#define endl '\n'
#define all(a) (a).begin(),(a).end()
#define sz(x) (int)x.size()
#define mid(l,r) ((r+l)/2)
#define left(node) (node*2)
#define right(node) (node*2+1)
#define mx_int_prime 999999937

const double PI = acos(-1);
const double eps = 1e-9;
const int inf = 2000000000;
const ll infLL = 9000000000000000000;
#define MOD 1000000007

#define mem(a,b) memset(a, b, sizeof(a) )
#define gcd(a,b) __gcd(a,b)
#define sqr(a) ((a) * (a))

#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);
#define file() freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

inline void normal(ll &a) { a %= MOD; (a < 0) && (a += MOD); }
inline ll modMul(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a*b)%MOD; }
inline ll modAdd(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a+b)%MOD; }
inline ll modSub(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); a -= b; normal(a); return a; }
inline ll modPow(ll b, ll p) { ll r = 1; while(p) { if(p&1) r = modMul(r, b); b = modMul(b, b); p >>= 1; } return r; }
inline ll modInverse(ll a) { return modPow(a, MOD-2); }
inline ll modDiv(ll a, ll b) { return modMul(a, modInverse(b)); }

typedef vector<int>::iterator vit;
typedef set<int>::iterator sit;

int dx[] = {0, 0, +1, -1};
int dy[] = {+1, -1, 0, 0};
//int dx[] = {+1, 0, -1, 0, +1, +1, -1, -1};
//int dy[] = {0, +1, 0, -1, +1, -1, +1, -1};



template < typename F, typename S >
ostream& operator << ( ostream& os, const pair< F, S > & p ) {
            return os << "(" << p.first << ", " << p.second << ")";
}

template < typename T >
ostream &operator << ( ostream & os, const vector< T > &v ) {
            os << "{";
                for(auto it = v.begin(); it != v.end(); ++it) {
                                if( it != v.begin() ) os << ", ";
                                        os << *it;
                                            }
                    return os << "}";
}

template < typename T >
ostream &operator << ( ostream & os, const set< T > &v ) {
            os << "[";
                for(auto it = v.begin(); it != v.end(); ++it) {
                                if( it != v.begin() ) os << ", ";
                                        os << *it;
                                            }
                    return os << "]";
}

template < typename T >
ostream &operator << ( ostream & os, const multiset< T > &v ) {
            os << "[";
                for(auto it = v.begin(); it != v.end(); ++it) {
                                if( it != v.begin() ) os << ", ";
                                        os << *it;
                                            }
                    return os << "]";
}

template < typename F, typename S >
ostream &operator << ( ostream & os, const map< F, S > &v ) {
            os << "[";
                for(auto it = v.begin(); it != v.end(); ++it) {
                                if( it != v.begin() ) os << ", ";
                                        os << it -> first << " = " << it -> second ;
                                            }
                    return os << "]";
}

#define dbg(args...) do {cerr << #args << " : "; faltu(args); } while(0)

void faltu () {
            cerr << endl;
}

template <typename T>
void faltu( T a[], int n ) {
            for(int i = 0; i < n; ++i) cerr << a[i] << ' ';
                cerr << endl;
}

template <typename T, typename ... hello>
void faltu( T arg, const hello &... rest) {
            cerr << arg << ' ';
                faltu(rest...);
}

const int mx=1e3+2;
const int LOG=log2(mx)+1;
int table[mx][mx][LOG][LOG],ar[mx][mx];

void buildSparseTable(int n,int m)
{
    int log2m=log2(m),log2n=log2(n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)    table[i][0][j][0]=ar[i][j];

        for(int kc=1;kc<=log2m;kc++){ //kc-> k for column
            for(int j=1;(j+(1<<kc)-1)<=m;j++){ //j-> column of ith row
                table[i][0][j][kc]=max(table[i][0][j][kc-1],table[i][0][j+(1<<(kc-1))][kc-1]);
            }
        }
    }
    //The above step is nothing but computing the sparse table for each row.
    //The complexity for one row is O(m*logm) and so for all rows O(n*m*logm).

    for(int kr=1;kr<=(log2n);kr++){ //kr-> k for row
        for(int i=1;(i+(1<<kr)-1)<=n;i++){
            for(int kc=0;kc<=log2m;kc++){//kc -> k for column
                for(int j=1;(j+(1<<kc)-1)<=m;j++){  //column of ith row
                    table[i][kr][j][kc]=max(table[i][kr-1][j][kc],table[i+(1<<(kr-1))][kr-1][j][kc]);
                }
            }
        }
    }
    //Clearly,the above step is O(n*m*logn*logm)
}

int query(int x1,int y1,int x2,int y2){ //O(1)
    int lenx=(x2-x1+1);
    int leny=(y2-y1+1);
    int kx=log2(lenx),ky=log2(leny);

    int minR1=max(table[x1][kx][y1][ky],table[x1][kx][y2-(1<<ky)+1][ky]);
    int minR2=max(table[x2-(1<<kx)+1][kx][y1][ky],table[x2-(1<<kx)+1][kx][y2-(1<<ky)+1][ky]);
    return max(minR1,minR2);
}

int chk(int x1,int y1,int x2,int y2)
{
    int l=0,r=min(x2-x1+1,y2-y1+1),mid,ret;
    while(l<r){
        mid=(l+r+1)/2;
        ret=query(x1,y1,x2-mid+1,y2-mid+1);
        if(ret>=mid){
            l=mid;
        }else r=mid-1;
    }
    return l;
}

signed main()
{
    optimize();

    int n,m,x1,y1,x2,y2,q;

    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)   cin>>ar[i][j];
    }

    for(int i=n;i>=1;i--){
        for(int j=m;j>=1;j--){
            if(ar[i][j]==1){
                int mn=min(ar[i][j+1],ar[i+1][j]);
                if(ar[i+mn][j+mn]!=0){
                    ar[i][j]=mn+1;
                }else ar[i][j]=mn;
            }
        }
    }


    buildSparseTable(n,m);

    cin>>q;
    while(q--){
        cin>>x1>>y1>>x2>>y2;
        int ret=chk(x1,y1,x2,y2);
        cout<<ret<<endl;
    }


    return 0;
}

