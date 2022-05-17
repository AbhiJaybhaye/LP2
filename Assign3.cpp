#include<iostream>
#define MAX 100
#include<limits.h>
using namespace std;
class stack 
{
	public:
    int data[MAX];
    int top;
  
    stack()
    {
        top = -1;
    }
    int empty()
    {
        if(top==-1)
        {
            return 1;
        }
        return 0;
    }
    int full()
    {
        if(top==MAX-1)
        {
            return 1;
        }
        return 0;
    }
    void push(int x)
    {
        if(full())
        {
            cout<<"Satck Is FULL Can't PUSH : ";
        }
        else
        {
            top++;
            data[top] = x;
        }
    }
    int pop()
    {
        if(empty())
        {
            cout<<"Satck Is EMPTY Can't POP : ";
            return -1;
        }
        else
        {
            int x = data[top];
            top--;
            return x;
        }
    }
};
class Edge
{
	public:
		int u,v,w;
};
class Graph
{
	public:
	int **G;
	int *vertex;
	int dir,wt,n,start;
	Graph()
	{
		cout<<"Enter number of vertices. "<<endl;
		cin>>n;
		
		vertex = new int[n];
		cout<<"Enter vertices of your graph. "<<endl;
		for(int i=0;i<n;i++)
		{
			cin>>vertex[i];
		}
		
		cout<<"Enter start of graph. "<<endl;
		cin>>start;
		 
		cout<<"Is your graph directed Type 1 for YES and 0  for NO. "<<endl;
		cin>>dir;
		
		cout<<"Is your graph weighted Type 1 for YES and 0  for NO. "<<endl;
		cin>>wt;
				
		G = new int*[n];
		for(int i=0;i<n;i++)
		{
			G[i] = new int[n];	
		}	
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				G[i][j] = 0;
			}
		}
	}
	void readgraph()
	{
		cout<<"Enter your "<<n<<"*"<<n<<" matrix. "<<endl;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				cin>>G[i][j];
			}
		}	
	}
	void readgraphedges()
	{
		int u,v,w;
		if(wt==0)
		{
			cout<<"Keep entering edges of the form(u,v) "<<endl;
			while(1)
			{
				cin>>u>>v;
				if(u==-1||v==-1)
				{
					return;
				}
				insert(u-start,v-start);
			}
		}
		else if(wt==1)
		{
			cout<<"Keep entering edges of the form(u,v,w) "<<endl;
			while(1)
			{
				cin>>u>>v>>w;
				if(u==-1||v==-1||w==-1)
				{
					return;
				}
				insert(u-start,v-start,w);
			}			
		}	
	}	
	void insert(int u, int v, int w=1)
	{
		G[u][v] = w;
		if(dir==0)
		{
			G[v][u] = w;
		}
	}
	void showgraph()
	{
		cout<<"Printing your Graph. "<<endl;
		for(int i=0;i<n;i++)
		{
			cout<<"  "<<start+i;
		}
		cout<<"\n";
		for(int i=0;i<n;i++)
		{
			cout<<start+i;
			for(int j=0;j<n;j++)
			{
				cout<<" "<<G[i][j]<<" ";
			}
			cout<<"\n";
		}
	}
	void degree()
	{
		if(dir==1)
		{
			outdegree();
			indegree();	
		}	
		outdegree();
	}
	void outdegree()
	{
		int count = 0;
		for(int i=0;i<n;i++)
		{
			count = 0;
			for(int j=0;j<n;j++)
			{
				if(G[i][j]!=0)
				{
					count++;
				}
			}
			cout<<"The degree of "<<i<<" vertex is = "<<count<<endl;
		}		
	}
	void indegree()
	{
		int count = 0;
		for(int i=0;i<n;i++)
		{
			count = 0;
			for(int j=0;j<n;j++)
			{
				if(G[j][i]!=0)
				{
					count++;
				}
			}
			cout<<"The degree of "<<i<<" vertex is = "<<count<<endl;
		}
	}
	void traversal()
	{
		int* visited = new int[n];
		for(int i=0;i<n;i++)
		{
			visited[i]=0;
		}
		cout<<"Traversal is "<<endl;
		rec_BFS(visited,start);
		rec_DFS(visited,vertex[0]);
		nonrec_DFS(visited,0);
	}
	void rec_BFS(int* visited,int v)
	{
		visited[v-start] = 1;
		cout<<v<<" ";
		for(int i=0;i<n;i++)
		{
			if(G[v-start][i]!=0&& visited[i]==0)
			{
				rec_BFS(visited,start+i);
			}
		}
	}
	void rec_DFS(int *visited,int v)
	{
		visited[v-vertex[0]]=1;
		cout<<vertex[v-vertex[0]]<<" ";
	
		for(int i=0;i<n;i++)
		{
			if(G[v-vertex[0]][i] && visited[i]==0)
			{
				rec_DFS(visited,i+vertex[0]);
			}
		}
	}
	void nonrec_DFS(int visited[],int v)
	{
		stack s;
		s.push(v);
		if(visited[v]==0)
		{
			visited[v]=1;
			cout<<vertex[v]<<" ";
		}
		for(int i=0;i<n;i++)
		{
			if(G[v][i]==0&&visited[i]==0)
			{
				s.push(i);
			}
		}
	}
	void PrimsAlgo()
	{
		int **cost, **spanning;
		int i, j;
		cost = new int *[n];
		spanning = new int *[n];

		for (i = 0; i < n; i++)
		{
			cost[i] = new int[n];
			spanning[i] = new int[n];
		}

		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				if (G[i][j] == 0)
				{
					cost[i][j] = INT_MAX;
				}
				else
				{
					cost[i][j] = G[i][j];
					spanning[i][j]=0;
				}
			}
		}

		int *visited, *distance, *from;

		visited = new int[n];
		distance = new int[n];
		from = new int[n];

		for (i = 0; i < n; i++)	//visit starting vertex
		{
			visited[i] = 0;
			distance[i] = cost[start][i];
			from[i] = start;
		}

		visited[start] = 1;

		int ne;	
		ne = n-1;	

		int min,u,v,mincost=0;	//min:-min distance between two vertices ,mincost:-min cost of spanning tree

		while (ne > 0)
		{
			min = INT_MAX;
			for (i = 0; i < n; i++)
			{
				if (visited[i] == 0 && min > distance[i])
				{
					min = distance[i];
					v = i;
				}
			}
			visited[v] = 1;
			u = from[v];	//v is to be visited from u;
			//add edge(u,v) to spanning tree
			spanning[u][v] = cost[u][v];
			spanning[v][u] = cost[u][v];
			mincost = mincost + cost[u][v];
			for (i = 0; i < n; i++)
			{
				if (visited[i] == 0 && distance[i] > cost[v][i])
				{
					distance[i] = cost[v][i];
					from[i] = v;
				}
			}
			ne--;
		}
		cout << "\nMinimum cost of spanning tree : " << mincost<<endl;
	}
	void KruskalsAlgo()
	{
		int u,v,w,i,j,k,cu,cv;
		Edge elist[n];
		int* component;
		cout<<"Keep entering edges like u v w "<<endl;
		i=0;
		while(1)
		{
			cin>>u>>v>>w;
			if(u==-1||v==-1||w==-1)
			{
				break;
			}
			elist[i].u = u;
			elist[i].v = v;
			elist[i].w = w;
			i++;
		}
		int T = i;
		for(i=0;i<=T;i++)
		{
			for(j=i+1;j<=T;j++)
			{
				if(elist[i].w>elist[j].w)
				{
					
					Edge temp = elist[i];
					elist[i] = elist[j];
					elist[j] = temp;
				}
			}
		}
		Edge spanlist[n];
		component = new int[n];
		for(i=0;i<n;i++)
		{
			component[i]=i;
		}
		int ne = n-1;
		k = 0;
		while(k<ne)
		{
			u = elist[i].u;
			v = elist[i].v;
			w = elist[i].w;
			cu = component[u];
			cv = component[v];
			if(cu!=cv)
			{
				spanlist[k].u = u;
				spanlist[k].v = v;
				spanlist[k].w = w;
				k++;
				for(i=0;i<n;i++)
				{
					if(component[i]==cv)
					{
						component[i]=cu;
					}
				}
			}
			i++;
		}
		int cost=0;
		for(i=0;i<k;i++)
		{
			cost+=spanlist[i].w;
		}
		cout<<cost<<" ";
	}
	void DijkstraAlgo()
	{
		int** cost = new int*[n];;
		int *visited, *distance, *via;
		int i,j,k,u,v,min,source;
		visited = new int[n];
		distance = new int[n];
		via = new int[n];
		for(i = 0; i < n; i++)
		{
			cost[i] = new int[n];
			visited[i] = 0;
		}
		for(i = 0; i < n; i++)
		{
			for(j = 0; j < n; j++)
			{
				if(cost[i][j]==0)
				{
					cost[i][j] = INT_MAX;
				}
				else
				{
					cost[i][j] = G[i][j];
				}
			}
		}
		for(i = 0; i < n; i++)
		{
			visited[i]=0;
			distance[i]=cost[start][i];
			via[i]=start;
		}
		visited[start]=1;
		int ne=n-1;
		while (ne > 0)
		{
			min = INT_MAX;
			for (i = 0; i < n; i++)
			{
				if (visited[i] == 0)
				{
					if(distance[i]<min)
					{
						min = distance[i];
						v = i;
					}
				}
			}
			visited[v] = 1;	
			for (i = 0; i < n; i++)
			{
				if (visited[i] == 0)
				{
					if(G[v][i]!=0&&distance[i]>distance[v]+cost[v][i])
					{
						distance[i] = distance[v]+cost[v][i];
						via[i] = v;
					}
				}
			}
			ne--;
		}
		for(i = 0; i < n; i++)
		{
			k = i;
			while(k!=start)
			{
				cout<<k<<"->";
				k = via[k];
			}
			cout<<start<<"\n";
		}		
	}

};
int main()
{
	Graph G;
	G.readgraphedges();
	G.showgraph();
	G.traversal();
	G.PrimsAlgo();

	return 0;
}
