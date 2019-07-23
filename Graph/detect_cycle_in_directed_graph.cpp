{
#include <bits/stdc++.h>
using namespace std;
//Position this line where user code will be pasted.
int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int v, e;
	    cin >> v >> e;
	    
	    vector<int> adj[v];
	    
	    for(int i =0;i<e;i++){
	        int u, v;
	        cin >> u >> v;
	        adj[u].push_back(v);
	    }
	    
	    cout << isCyclic(v, adj) << endl;
	    
	}
	
	return 0;
}
}
/*This is a function problem.You only need to complete the function given below*/
/*  Function to check if the given graph contains cycle
*   V: number of vertices
*   adj[]: representation of graph
*/
typedef long long ll;
ll vis[101];
bool fun(ll u,vector<int> adj[])
{
    vis[u]=1;
    bool ans;
    for(int val:adj[u])
    {
        if(vis[val]==1)
        {
            return true;
        }
        if(vis[val]==0)
        {
            ans=fun(val,adj);
            if(ans==true)
            {
                return true;
            }
        }
    }
    vis[u]=2;
    return false;
}
bool isCyclic(int V, vector<int> adj[])
{
    memset(vis,0,sizeof(vis));
    ll i;
    bool ans;
    for(i=0;i<V;i++)
    {
        if(!vis[V])
        {
            ans=fun(i,adj);
            if(ans==true)
            {
                return ans;
            }
        }
    }
    return false;
}