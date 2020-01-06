{
#include<bits/stdc++.h>
using namespace std;
//Position this line where user code will be pasted.
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int V, E;
        cin>>V>>E;
        
        // array of vectors to represent graph
        vector<int> adj[V];
        
        int u, v;
        for(int i=0;i<E;i++)
        {
            cin>>u>>v;
            
            // adding edge to the graph
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        cout << isCyclic(adj, V)<<endl;
    }
}

}
/*This is a function problem.You only need to complete the function given below*/
/* This function is used to detect a cycle in undirected graph
*  adj[]: array of vectors to represent graph
*  V: number of vertices
*/
bool isCyclicUtil(int u,vector<int > adj[],bool vis[],int n,int par)
{
    vis[u]=true;
    for(int v:adj[u])
    {
        if(!vis[v])
        {
            if(isCyclicUtil(v,adj,vis,n,u))
            return true;
        }
        else if(v!=par)
        {
            return true;
        }
        
    }
    return false;
}
bool isCyclic(vector<int> adj[], int n)
{
   bool vis[n];
   memset(vis,false,sizeof(vis));
   int i;
   for(i=0;i<n;i++)
   {
       if(!vis[i])
       {
           if(isCyclicUtil(i,adj,vis,n,-1))
           return true;
       }
   }
   return false;
   
}
