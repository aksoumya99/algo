typedef long long ll;
typedef pair<ll,ll > pll;
#define fi first
#define se second
const ll inf=1e7;
ll bellman_ford(vector<pair<ll,pll > > &edges,ll dest,ll src,ll v,ll e){
    ll i,j,k;
    vector<ll > dist(v,inf);
    for(i=1;i<=v-1;i++){
        for(j=0;j<e;j++){
            ll u=edges[j].fi,v=edges[j].se.fi,w=edges[j].se.se;
            if(dist[u]!=inf&&dist[v]>dist[u]+w){
                dist[v]=dist[u]+w;
            }
        }
    }
    //check for negative cycles
    for(j=0;j<e;j++){
        ll u=edges[j].fi,v=edges[j].se.fi,w=edges[j].se.se;
        if(dist[u]!=inf&&dist[v]>dist[u]+w){
            cout<<"Negative cycle\n";
            return -1;
        }
    }
    return dist[dest];
}
//Complexity-O(VE)
//Can be used for both directed and undirected graph
