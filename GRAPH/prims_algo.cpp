/********************PRIMS_____ALGORITHM*************************************/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    
    vector<pair<int,int>> adj[n];
    for(int i=0;i<m;i++)
    {
        int u,v,wt;
        cin>>u>>v>>wt;  //u->src,v->dest,wt->costofpath(u,v)
        adj[u].push_back(make_pair(v,wt));
        adj[v].push_back(make_pair(u,wt));
    }
    vector<bool> mst(n,false);
    vector<int> prnt(n,-1);
    vector<int> dist(n,INT_MAX);
    prnt[0]=0;
    dist[0]=0;
    
    for(int i=0;i<n-1;i++)
    {
        int x;
        int minpath=INT_MAX;
        
        for(int i=0;i<n;i++)
        {
           if(!mst[i] and minpath>dist[i])
           {
               minpath=dist[i];
               x=i;
           }
        }
        mst[x]=true;
        for(auto it:adj[x])
        {
            int m=it.first;
            int c=it.second;
            if(!mst[i] and c<dist[m])
            {
               dist[m]=c;
               prnt[m]=x;
            }
        }
    }
    
    for(int i=0;i<n;i++)
     cout<<dist[i]<<" ";

    return 0;
}
