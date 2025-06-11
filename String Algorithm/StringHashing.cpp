//https://www.spoj.com/problems/NHAY/

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define PB push_back
#define F first
#define S second
#define endl '\n'

#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define file() freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

 
int bigMOD(int a,int n,int mod)
{
    int ans=1;
    a%=mod;
    if(a<0) a+=mod;
    while(n){
        if(n&1) ans=((ll)ans*a)%mod;
        a=((ll)a*a)%mod;
        n>>=1;
    }
    return ans;
}
const int N=1e6+1;
const int MOD1=1e9+7,MOD2=1e9+9;
const int base1=137,base2=277;
int ip1,ip2;
pair<int,int> pw[N],ipw[N];
void preCompute(){//computes pw^{i} and ipw^{i}
    pw[0]={1,1};
    for(int i=1;i<N;i++){
        pw[i].F=((ll)pw[i-1].F*base1)%MOD1;
        pw[i].S=((ll)pw[i-1].S*base2)%MOD2;
    }
    ip1=bigMOD(base1,MOD1-2,MOD1);
    ip2=bigMOD(base2,MOD2-2,MOD2);
    ipw[0]={1,1};
    for(int i=1;i<N;i++){
        ipw[i].first=((ll)ipw[i-1].first*ip1)%MOD1;
        ipw[i].second=((ll)ipw[i-1].second*ip2)%MOD2;
    }
}
struct Hashing {
    string s;
    int n;
    vector<pair<int,int> > hs;//1-indexed
    Hashing() {}
    Hashing(string _s)//s: 0-indexed
    {
        n=_s.size();s=_s;
        hs.PB({0,0});
        pair<int,int>p;
        for(int i=0;i<n;i++){
            p.F=(hs[i].F+(1LL*pw[i].F*s[i])%MOD1)%MOD1;
            p.S=(hs[i].S+(1LL*pw[i].S*s[i])%MOD2)%MOD2;
            hs.push_back(p);
        }
    }
    pair<int,int>get_hash(int l,int r)//1-indexed
    {
        pair<int,int>ans;
        ans.F=((hs[r].F-hs[l-1].F+MOD1)*1LL*ipw[l-1].F)%MOD1;
        ans.S=((hs[r].S-hs[l-1].S+MOD2)*1LL*ipw[l-1].S)%MOD2;
        return ans;
    }
};
signed main()
{
    optimize();
    #ifndef ONLINE_JUDGE
    file();
    #endif

    preCompute();
    int n;
    string pattern,st;

    while(cin>>n){
        cin>>pattern>>st;
        pair<int,int>ret=Hashing(pattern).get_hash(1,n);
        Hashing h(st);
        for(int i=1;(i+n-1)<=(st.size());i++){
            if(h.get_hash(i,i+n-1)==ret) cout<<i-1<<endl;
        }
        cout<<endl;
    }


    return 0;
}
    
