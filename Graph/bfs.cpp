void bfs(int s, vector<int> adj[], bool vis[], int N)
{
    queue<int > q;
    q.push(s);
    vis[s]=true;
    cout<<s<<" ";
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int v:adj[u])
        {
            if(!vis[v])
            {
                q.push(v);
                vis[v]=true;
                cout<<v<<" ";
            }
        }
    }
    
}
