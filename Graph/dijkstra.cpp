typedef long long ll;
typedef pair<ll,ll > pll;
#define fi first
#define se second
void dijkstra(vector<vector<pll > > &adj,int src,int dest){
    priority_queue<pll,vector<pll >, greater<pll > > pq;
    ll n=adj.size();
    vector<ll > vis(n,0);
    vector<ll > dist(n,inf);
    pq.push({0,src});
    dist[src]=0;
    while(!pq.empty()){
        auto pr=pq.top();
        pq.pop();
        ll u=pr.se;
        //if(u==dest){return dist[dest];}
        if(vis[u]){
            continue;
        }
        vis[u]=1;
        for(auto temp:adj[u]){
            ll w=temp.se,v=temp.fi;
            if(dist[v]>dist[u]+w){
                dist[v]=dist[u]+w;
                pq.push({dist[v],v});
            }
        }
    }
    return dist[dest];
}
//complexity-O(V+Elog(V))
