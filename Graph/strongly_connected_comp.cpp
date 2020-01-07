stack<int > stk;
int vis[101];
void dfs(int u,vector<int > adj[])
{
    vis[u]=1;
    for(int v:adj[u])
    {
        if(!vis[v])
        {
            dfs(v,adj);
        }
    }
    stk.push(u);
}
void dfs2(int u,vector<int > adj2[])
{
    vis[u]=1;
    for(int v:adj2[u])
    {
        if(!vis[v])
        {
            dfs2(v,adj2);
        }
    }
}
int kosaraju(int n, vector<int> adj[])
{
    memset(vis,0,sizeof(vis));
    int i;
    for(i=0;i<n;i++)
    {
        if(!vis[i])
        {
            dfs(i,adj);
        }
    }
    vector<int> adj2[n];
    int j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<adj[i].size();j++)
        {
            adj2[adj[i][j]].push_back(i);
        }
    }
    int ans=0;
    memset(vis,0,sizeof(vis));
    while(!stk.empty())
    {
        int u=stk.top();
        stk.pop();
        if(!vis[u])
        {
            dfs2(u,adj2);
            ans++;
        }
    }
    return ans;
}
