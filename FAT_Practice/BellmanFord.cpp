#include<iostream>
#include<climits>
#include<vector>
const int INF = 1e9;
using namespace std;

vector<int> bellmanFord(int V, int E, vector<vector<int>>& edges,int src)
{
    vector<int> dist(V, INF);
    dist[src]=0;
    for(int i=1;i<V;i++)
    {
        for(auto e:edges)
        {
            int u= e[0];
            int v= e[1];
            int w=e[2];
            dist[v]= min(dist[v],dist[u]+w);
        }
    }
    for(auto e:edges)
    {
        int u= e[0];
        int v= e[1];
        int w=e[2];
        if(dist[u]+w>dist[v])
        {
            cout<<"Negative Cycle present";
            exit(0);
        }
    }
    return dist;

}

int main()
{
    vector<vector<int>> edges;
    int V= 4;
    int E= 5;
    edges.push_back({0,1,1});
    edges.push_back({0,2,4});
    edges.push_back({1,2,4});
    edges.push_back({2,3,3});
    edges.push_back({3,1,-10});
    vector<int> dist= bellmanFord(V,E,edges,0);
    for(int i=0;i<V;i++)
    {
        cout<<dist[i]<<" ";
    }
}