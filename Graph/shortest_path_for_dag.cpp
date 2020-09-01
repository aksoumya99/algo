typedef long long ll;
typedef pair<ll,ll > pll;
#define fi first
#define se second
const ll inf=1e7;
stack<ll >stk;
void topo(ll u,vector<vector<ll > > &adj,vector<ll > &vis){
    vis[u]=1;
    for(ll v:adj[u]){
        if(!vis[v]){
            topo(v,adj,vis);
        }
    }
    stk.push(u);
}
ll dagshortestpath(vector<vector<ll > > &adj,ll src,ll dest){
    ll n=adj.size();
    vector<ll > vis(n,0);
    for(i=0;i<n;i++){
        if(!vis[i]){
            topo(i,adj,vis);
        }
    }
    vector<ll > dist(n,inf);
    dist[src]=0;
    while(!stk.empty()){
        ll u=stk.top();
        stk.pop();
        if(dist[u]!=inf){
            for(auto pr:adj[u]){
                ll v=pr.fi,w=pr.se;
                if(dist[v]>dist[u]+w){
                    dist[v]=dist[u]+w;
                }
            }
        }
    }
    return dist[dest];
}
