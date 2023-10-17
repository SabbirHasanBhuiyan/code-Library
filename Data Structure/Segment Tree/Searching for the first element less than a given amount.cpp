/*
https://lightoj.com/problem/histogram
*/

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
const int inf=1e9;

#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int mx=50001;
int ar[mx];
int t[mx*4];


void build(int i,int tl,int tr)
{
    if(tl==tr)  t[i]=ar[tl];
    else{
        int tm=(tl+tr)/2;
        build(i*2,tl,tm);
        build(i*2+1,tm+1,tr);
        t[i]=min(t[i*2],t[i*2+1]);
    }
}

///returns the idx first element smaller than h within the the given range
int get_first(int v,int tl,int tr,int l,int r,int h)
{
    if(l>tr || r<tl)    return -1;
    if(tl>=l && tr<=r){
        if(t[v]>=h) return -1;
        while(tl!=tr){
            int tm=(tl+tr)/2;
            if(t[v*2]>=h){
                tl=tm+1;
                v=v*2+1;
            }else{
                tr=tm;
                v=v*2;
            }
        }
        return tl;
    }

    int tm=(tl+tr)/2;
    int rs=get_first(2*v,tl,tm,l,r,h);
    if(rs!=-1) return rs;
    else return get_first(v*2+1,tm+1,tr,l,r,h);
}

///returns the idx of last element smaller than h within the the given range
int get_last(int v,int tl,int tr,int l,int r,int h)
{
    if(l>tr || r<tl)    return -1;
    if(tl>=l && tr<=r){
        if(t[v]>=h) return -1;
        while(tl!=tr){
            int tm=(tl+tr)/2;
            if(t[v*2+1]>=h){
                tr=tm;
                v=v*2;
            }else{
                tl=tm+1;
                v=v*2+1;
            }
        }
        return tl;
    }

    int tm=(tl+tr)/2;
    int rs=get_last(v*2+1,tm+1,tr,l,r,h);
    if(rs!=-1) return rs;
    else return get_last(2*v,tl,tm,l,r,h);
}

int solve(int n)
{
    int ans=0,l,r;
    for(int i=1;i<=n;i++){
        r=get_first(1,1,n,i,n,ar[i]);
        if(r==-1){ // no such element
            r=n;
        }else r--;
        l=get_last(1,1,n,1,i,ar[i]);
        if(l==-1){ // no such element
            l=1;
        }else l++;
        ans=max(ans,(r-l+1)*ar[i]);
    }
    return ans;
}
int main()
{
    optimize();

    int t,n;
    cin>>t;
    for(int tc=1;tc<=t;tc++){
        cin>>n;
        for(int i=1;i<=n;i++)   cin>>ar[i];
        build(1,1,n);

        int ans=solve(n);

        cout<<"Case "<<tc<<": "<<ans<<endl;

    }

    return 0;
}

