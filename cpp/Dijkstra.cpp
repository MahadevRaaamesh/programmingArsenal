#include <bits/stdc++.h>

using namespace std;

vector<int> dijkstra1(vector<vector<pair<int,int>>> & adj,int src)
{
    int n=adj.size();
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<int> distance(n,INT_MAX);
    pq.push({0,src});
    distance[src]=0;

    while(!pq.empty()){
        auto p = pq.top();
        pq.pop();
        int cost=p.first;
        int node=p.second;

        if(cost>distance[node])continue;
       
        for(auto &x : adj[node])
        {
            int child=x.first;
            int path_cost=x.second;

            if(distance[node] != INT_MAX && distance[node]+path_cost<distance[child]){
                distance[child]=distance[node]+path_cost;
                pq.push({distance[child],child});
            }
        }

    }
    return distance;
}

vector<int> dijkstra0(vector<vector<pair<int,int>>> & adj,int src)
{
    int n=adj.size();
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<int> distance(n,INT_MAX);
    pq.push({0,src});
    distance[src]=0;

    while(!pq.empty()){
        auto p = pq.top();
        pq.pop();
        int cost=p.first;
        int node=p.second;

        if(cost>distance[node])continue;
       
        for(auto &x : adj[node])
        {
            int child=x.first;
            int path_cost=x.second;

            if(distance[node] != INT_MAX && distance[node]+path_cost<distance[child]){
                distance[child]=distance[node]+path_cost;
                pq.push({distance[child],child});
            }
        }

    }
    return distance;
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>> adj(n+1);
    for(int i=0 ; i<m ; i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
    }
    vector<int> answer=dijkstra0(adj,0);
    for(auto & x:answer){
        cout<<x<<endl;
    }
}

