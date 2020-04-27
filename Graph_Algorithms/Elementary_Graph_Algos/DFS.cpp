#include<bits/stdc++.h>
using namespace std;
int k=0;
    int arr[4];
class Graph
{
    int V;
    list<int>*adj;
    void DFS_helper(int s ,bool *visited);
public:
    Graph (int v); //constructor
    void addEdge(int v,int w);
       void DFS(int s);
};

Graph :: Graph(int v)
{
    V=v;
    adj = new list<int>[v]; //creating an array for every vertex
}

void Graph :: addEdge(int v,int w)
{
    adj[v].push_back(w);
}

void DFS_helper(int s,int *visited)
{
    cout<<"Visiting node "<<s<<endl;
    visited[s]=true;
    arr[k++]= s;
    list<int>::iterator i;

    for(i = adj[s].begin();i != adj[s].end();i++)
        {
            if(!visited[*i])
        {
            cout<<"Going to vertex "<<*i<<" from vertex "<<s<<endl;
            DFS_helper(*i, visited);
        }
        }
}

void Graph :: DFS(int s)
{
    bool *visited=new bool[V];
    for(int i=0;i<V;i++)
    {
        visited[i]=false;
    }
    DFS_helper(s, visited);
}

int main()
{

    Graph g(4);
     g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    g.DFS(2);
    cout<<"Graph traversal is "<<endl;
    for(int i=0;i<4;i++)
    cout<<arr[i] <<" ";
}

