#include<bits/stdc++.h>
#define MAX 20
using namespace std;

class Graph
{
    int vertices;
    int edges;
    vector<int> adj_list[MAX];
    bool visited[MAX];
    Graph();
    public:
        Graph(int vertices, int edges)
        {
            this->vertices = vertices;
            this->edges = edges;
            memset(visited, false, sizeof(visited));
        }
        void create_graph();
        void depth_first_search(int index);
};
        
void Graph ::create_graph()
{
    pair<int, int> p;
    for (int i=0; i<edges; i++)
    {
        cout<<"Enter the vertices used to construct edge number" <<i+1<<": -\n";
        cin>>p.first>>p.second;
        adj_list[p.first].push_back(p.second); 
        adj_list[p.second].push_back(p.first); 
    }
}

void Graph::depth_first_search(int index)
{
    if (visited[index])
    {
        return;
    }
    visited[index] = true;
    cout<<index<<" ";
    for (int i=0; i<static_cast<int>(adj_list[index].size());i++)
    {
        int a = adj_list[index][i];
        depth_first_search(a);
    }
}

int main()
{
    int vertices;
    int edges;

    cout<<"Enter the number of vertices in the graph: -\n";
    cin>>vertices;
    cout<<"Enter the number of edges in the graph: -\n";
    cin>>edges;

    Graph graph(vertices, edges);
    graph.create_graph();
    cout<<"Depth first search: -\n";
    graph.depth_first_search(0);
    
    return 0;
}