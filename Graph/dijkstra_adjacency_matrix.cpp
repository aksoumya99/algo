typedef pair<int,int > pii;
void dijkstra(vector<vector<int>> graph, int src, int n)
{
    vector<int > dist(n,10000000);
    vector<int > vis(n,0);
    int i;
    priority_queue<pii,vector<pii >,greater<pii > > pq;
    dist[src]=0;
    pq.push(make_pair(0,src));
    int u;
    while(!pq.empty())
    {
        pii temp=pq.top();
        pq.pop();
        u=temp.second;
        if(vis[u])
        continue;
        vis[u]=1;
        for(i=0;i<n;i++)
        {
            if(graph[u][i]!=0)
            {
                if(dist[i]>dist[u]+graph[u][i])
                {
                    dist[i]=dist[u]+graph[u][i];
                    pq.push(make_pair(dist[i],i));
                }
            }
        }
    }
    for(i=0;i<n;i++)
    {
        cout<<dist[i]<<" ";
    }
}
//Complexity-O(V^2)
