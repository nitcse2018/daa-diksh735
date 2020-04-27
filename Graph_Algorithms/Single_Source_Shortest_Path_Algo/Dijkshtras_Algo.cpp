#include<iostream>
#include<vector>


using namespace std;

int min_distance(int distance[], bool visited[], int n)
{
	int min = 999999999, min_index;
	for(int i=0;i<n;++i)
	{
		if(visited[i]==false && distance[i]<=min)
		{
			min = distance[i];
			min_index = i;
		}
	}
	return min_index;
}

int main()
{
		int src,dst,cost,i,j,k,root;
        int n=5;  //number of vertices
        int m=5;  // number of edges

		int mat[5][5]={},distance[n];
		vector <vector<int> > v1(n);
		bool visited[n];
		for(i=0;i<n;++i)
		{
			distance[i] = 9999999;
			visited[i] = false;
		}

     cout<<"Enter the edges from a to b and its weight "<<endl;
		for(i=0;i<m;++i)
		{
			cin>>src>>dst>>cost;
			if(mat[src-1][dst-1]==0)
			{
				mat[src-1][dst-1] = cost;
				mat[dst-1][src-1] = cost;
				v1[src-1].push_back(dst-1);
				v1[dst-1].push_back(src-1);
			}
			else
			{
				mat[src-1][dst-1] = min(mat[src-1][dst-1],cost);
				mat[dst-1][src-1] = min(mat[dst-1][src-1],cost);
			}
		}
        cout<<"Enter the root vertex: "<<endl;
		cin>>root;
		distance[root-1]=0;
		for(i=0;i<n-1;++i)
		{
			j = min_distance(distance,visited,n);
			visited[j] = true;
			for(k=0;k<n;++k)
			{
				if(!visited[k] && mat[j][k] && distance[j]!=99999999 && distance[j] + mat[j][k] < distance[k])
				{
					distance[k] = distance[j] + mat[j][k];
				}
			}
		}
		for(i=0;i<n;++i)
		{
			if(i==root-1)
			{
				continue;
			}
			if(distance[i]==99999999)
			{
				cout<<-1<<" ";
			}
			else
			{
				cout<<distance[i]<<" ";
			}
		}
		cout<<endl;

	return 0;
}
