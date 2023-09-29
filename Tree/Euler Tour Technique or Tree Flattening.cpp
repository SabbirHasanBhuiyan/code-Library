//Bismillah

#include<bits/stdc++.h>
using namespace std;

#define int long long
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

#define PB push_back
#define F first
#define S second
#define endl '\n'
#define all(a) (a).begin(),(a).end()
#define sz(x) (int)x.size()
#define mx_int_prime 999999937

const double PI = acos(-1);
const double eps = 1e-9;
const int inf = 2000000000;
const ll infLL = 9000000000000000000;
#define MOD 1000000007

#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define file() freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

const int mx=1e5+1;
vector<int> adj[mx];
int timer=1,FT[mx*4],startTime[mx],terminatingTime[mx];

void dfs(int u,int par)
{
    startTime[u]=timer;
    FT[timer]=u;
    timer++;

    for(auto &v: adj[u]){
        if(v!=par){
            dfs(v,u);
        }
    }

    terminatingTime[u]=timer;
    FT[timer]=u;
    timer++;
}

signed main()
{
    optimize();
    #ifndef ONLINE_JUDGE
    file();
    #endif

    int n,a,b;
    cin>>n;

    for(int i=1;i<n;i++){
        cin>>a>>b;
        adj[a].PB(b);
        adj[b].PB(a);
    }

    dfs(1,-1);
    return 0;
}
