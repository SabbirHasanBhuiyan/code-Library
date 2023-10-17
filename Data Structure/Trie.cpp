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

const int SIZE=26;
struct  node
{
    int count;
    bool endOFWord;

    node *ptr[SIZE]; //each node need pointer to atmost k child
};

node* getNode()
{
    node* tempNodePtr=new node;
    tempNodePtr->endOFWord=false;

    tempNodePtr->count=0;
    for(int i=0;i<SIZE;i++) tempNodePtr->ptr[i]=NULL;
    return tempNodePtr;
}

void insert(node *root,string &st){
    node *tempNodePtr=root;

    for(int i=0;i<(int)st.size();i++){
        int idx=st[i]-'a';

        if(tempNodePtr->ptr[idx]==NULL){
            tempNodePtr->ptr[idx]=getNode();
        }
        tempNodePtr=tempNodePtr->ptr[idx];
    }

    tempNodePtr->endOFWord=true;
}

bool search(node* root,string &st )
{
    node* tempNodePtr=root;
    for(int i=0;i<(int)st.size();i++){
        int idx=st[i]-'a';
        if(tempNodePtr->ptr[idx]==NULL) return false;
        else tempNodePtr=tempNodePtr->ptr[idx];
    }
    return true;
}

signed main()
{
    optimize();
    #ifndef ONLINE_JUDGE
    file();
    #endif

    return 0;
}
