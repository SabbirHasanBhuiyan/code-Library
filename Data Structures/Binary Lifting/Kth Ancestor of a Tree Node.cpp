https://leetcode.com/problems/kth-ancestor-of-a-tree-node/
class TreeAncestor {
    vector<vector<int> >up,adj;
    vector<int>depth;
    vector<bool>vis;
    int LOG;
public:

    void dfs(int u, vector<int>& parent){
        vis[u]=1;
        up[u][0]=parent[u];
        for(int j=1;j<LOG;j++){
            up[u][j]=up[up[u][j-1]][j-1];
        }
        for(auto &v: adj[u]){
            if(!vis[v]){
                depth[v]=depth[u]+1;
                dfs(v,parent);
            }
        }
    }
    TreeAncestor(int n, vector<int>& parent) {
        LOG=0;
        while((1<<(LOG)) <= n ){
            LOG++;
        }
        up=vector<vector<int> >(n,vector<int>(LOG));
        depth=vector<int>(n);
        vis=vector<bool>(n,0);
        adj=vector<vector<int> >(n);
        for(int v=1;v<n;v++){
            adj[parent[v]].push_back(v);
        }

        parent[0]=0;
        dfs(0,parent);
    }

    int getKthAncestor(int node, int k) {
        if(depth[node]<k)   return -1;
        else{
            for(int j=LOG;j>=0;j--){
                if((1<<j)<=k){
                    node=up[node][j];
                    k-=(1<<j);
                }
            }
            return node;
        }
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */
