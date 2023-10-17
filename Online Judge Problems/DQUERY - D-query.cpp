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
int ar[mx],nxt_right[mx];
vector<int>tree[mx*4];

void Merge(int v)
{
	int len1=tree[v*2].size();
	int len2=tree[v*2+1].size();
	int idx1=0,idx2=0;
	while(idx1<len1 && idx2<len2){
		if(tree[2*v][idx1]<=tree[v*2+1][idx2]){
			tree[v].push_back(tree[v*2][idx1]);
			idx1++;
		}else{
			tree[v].PB(tree[v*2+1][idx2]);
			idx2++;
		}
	}

	while(idx1<len1){
		tree[v].PB(tree[v*2][idx1]);
		idx1++;
	}

	while(idx2<len2){
		tree[v].PB(tree[v*2+1][idx2]);
		idx2++;
	}
}

int query(int v,int tl,int tr,int l,int r)
{
	if(r<tl || l>tr)	return 0;
	else if(tl>=l && tr<=r){
		return tree[v].end()-upper_bound(tree[v].begin(),tree[v].end(),r);
	}
	int tm=(tl+tr)/2;
	int ret=0;
	ret+=query(v*2,tl,tm,l,r);
	ret+=query(v*2+1,tm+1,tr,l,r);
	return ret;
}
void build(int v,int tl,int tr)
{
	if(tl==tr){
		tree[v].PB(nxt_right[tl]);
		return;
	}else{
		int tm=(tl+tr)/2;
		build(v*2,tl,tm);
		build(v*2+1,tm+1,tr);
		Merge(v);
	}
}

signed main()
{
    optimize();
    #ifndef ONLINE_JUDGE
    file();
    #endif

    int n,q,l,r;
    cin>>n;
    for(int i=1;i<=n;i++)	cin>>ar[i];
    map<int,int>mp;

	for(int i=n;i>=1;i--){
		if(mp[ar[i]]==0){
			nxt_right[i]=n+1;
			mp[ar[i]]=i;
		}else{
			nxt_right[i]=mp[ar[i]];
			mp[ar[i]]=i;
		}
	}

	build(1,1,n);

	cin>>q;
	while(q--){
		cin>>l>>r;
		cout<<query(1,1,n,l,r)<<endl;
	}
    return 0;
}
