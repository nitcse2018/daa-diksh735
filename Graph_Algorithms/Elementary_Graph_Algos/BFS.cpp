#include<bits/stdc++.h>
#include<list>
using namespace std;
int k=0;
    int arr[4];
class Graph
{
    int V;
    list<int> *adj;
public:
    Graph (int v); //constructor
    void addEdge(int v,int w);
    void BFS(int s);
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

void Graph :: BFS(int s)
{
    bool *visited=new bool[V];
    for(int i=0;i<V;i++)
    {
        visited[i]=false;
    }
    list<int> queue;
    visited[s]=true;
    queue.push_back(s);
    list<int>::iterator i;
    while(!queue.empty())
    {
        s=queue.front();
        arr[k++]= s;
        queue.pop_front();
        cout<<"Checking adjacent vertices to vertex "<<s<<endl;
        for(i=adj[s].begin();i!=adj[s].end();i++)
        {
            if(!visited[*i])
            {
                cout<<"Visit and Enque "<<*i<<endl;
                visited[*i]=true;
                queue.push_back(*i);
            }
        }
    }

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
    g.BFS(2);
    cout<<"Graph traversal is "<<endl;
    for(int i=0;i<4;i++)
    cout<<arr[i] <<" ";
}

