#include<iostream>
#include<vector>
using namespace std;

const int INF = 99999 ;
int n,m; // n is number of vertices and m is number of edges
int graph[405][405];

void floydWarshall ()
{
    int i, j, k;
    for (k = 1; k <=n; k++)
    {
        for (i = 1; i <=n; i++)
        {
            for (j = 1; j <=n; j++)
            {
                if (graph[i][k] + graph[k][j] < graph[i][j])
                    graph[i][j] = graph[i][k] + graph[k][j];
            }
        }
    }

    int q;
    cout<<"Enter number of pairs of vertices of which you need the shortest distance"<<endl;
     cin>>q;
	while(q--)
	{
        cout<<"Enter the pair: "<<endl;
		int x,y;  cin>>x>>y;
		if(graph[x][y]!=INF)
		cout<<graph[x][y]<<endl;
		else
		cout<<"-1"<<endl;
	}
}

int main()
{
    cout<<"Enter number of vertices and edges in the graph "<<endl;
	  cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j)
		{
            if(i!=j)
			graph[i][j] = INF;
            else
            graph[i][j] = 0;
		}
	}

    cout<<"Enter the edges from a vertex a to vertex b and having weight w"<<endl;

	for(int i=0;i<m;++i)
	{
		int x,y,w;  cin>>x>>y>>w;
		graph[x][y] = w;
	}

	floydWarshall();
}
