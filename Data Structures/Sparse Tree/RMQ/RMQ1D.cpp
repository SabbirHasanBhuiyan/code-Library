//Bismillah

#include<bits/stdc++.h>
using namespace std;

#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int mx=1e5+1;
const int LOG=log2(mx)+1;
int table[mx][LOG],mnTable[mx][LOG],ar[mx],log_2[mx];
void buildSparseTable(int n)
{
    int k=log2(n)+1;
    for(int i=1;i<=n;i++)   table[i][0]=ar[i]; //2^0=1

    for(int j=1;j<k;j++){
        for(int i=1;(i+(1<<j)-1)<=n;i++){
            table[i][j]=min(table[i][j-1],table[i+(1<<(j-1))][j-1]);
        }
    }
}

int query(int l,int r)
{
    int len=r-l+1;
    //int k=log2(len);
    int k=log_2[len];
    return min(table[l][k],table[r-(1<<k)+1][k]);
}
int main()
{
    optimize();

    int n;
    cin>>n;

    log_2[1]=0;
    for(int i=2;i<=n;i++){
        log_2[i]=log_2[i/2]+1;
    }

    for(int i=1;i<=n;i++)   cin>>ar[i];
    buildSparseTable(n);

    int q,l,r;
    cin>>q;
    while(q--){
        cin>>l>>r;
        l++ , r++; ///0 based indexing to 1 based indexing
        cout<<query(l,r)<<endl;
    }

    return 0;
}

