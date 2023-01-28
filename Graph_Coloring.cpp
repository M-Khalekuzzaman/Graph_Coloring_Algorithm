#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
vector<int>adj_list[N];
int visited[N];
int color[N];

bool DFS(int node)
{

    visited[node] = 1;
    for(int adj_node:adj_list[node])
    {
        if(visited[adj_node] == 0)
        {
            if(color[node] == 1)color[adj_node] = 2;
            else color[adj_node] = 1;
            bool is_bicolorable = DFS(adj_node);
            if(!is_bicolorable)
            {
                return false;
            }
        }
        else
        {
            if(color[node] == color[adj_node])
            {
                return false;
            }
        }
    }
    return true;
}
int main()
{
    int nodes,edges;
    cin>>nodes>>edges;

    for(int i = 0; i<edges; i++)
    {
        int u,v;
        cin>>u>>v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);

    }
    bool is_bicolorable = true;
    for(int i = 1; i<=nodes; i++)
    {
        if(visited[i] == 0)
        {
            color[i] = 1;
            bool ok = DFS(i);
            if(!ok)
            {
                is_bicolorable = false;
                break;
            }
        }
    }
    if(!is_bicolorable)
    {
        cout<<"Impossible"<<endl;
    }
    else
    {
        for(int i = 1; i<=nodes; i++)
        {
            cout<<color[i]<<" ";
        }
    }
    /*
    5 4
    1 2
    1 3
    2 3
    4 5
    */



    return 0;
}
