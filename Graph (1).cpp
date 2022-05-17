#include<bits/stdc++.h>
#define MAX 20
using namespace std;

template <class T>
class Stack
{
	T data[MAX];
	int top;
	
	public:
		Stack()
		{
			top=-1;
		}
		int full()
		{
			if(top==MAX-1)
			{
				return 1;
			}
			return 0;
		}
		int empty()
		{
			if(top==-1)
			{
				return 1;
			}
			return 0;
		}
		void push(T p)
		{
			if(!full())
			{
				top++;
				data[top]=p;
			}
			else
			{
				cout<<"\nStack is full\n";
			}
		}
		T pop()
		{
			if(!empty())
			{
				T p=data[top];
				top--;
				return p;
			}
			else
			{
				return 0;
			}
		}
};
template<class DT>
class Queue
{
	DT data[MAX];
	int front,rear;
	
	public:
		Queue()
		{
			front=rear=-1;
		}
		void init()
		{
			front=rear=-1;
		}
		int empty()
		{
			if(front==-1)
			{
				return 1;
			}
			return 0;
		}
		int full()
		{
			if(rear==MAX-1)
			{
				return 1;
			}
			return 0;
		}
		void enqueue(DT T)
		{
			if(!full())
			{
				if(front==-1)
				{
					front++;
				}
				rear++;
				data[rear]=T;
			}
			else
			{
				cout<<"\nQueue is full\n";
			}
		}
		DT dequeue()
		{
			if(!empty())
			{
				DT T=data[front];
				if(front==rear)
				{
					front=rear=-1;
					return T;
				}
				front++;
				
				return T;
			}
			else
			{
				cout<<"\nQueue is empty\n";
				return 0;
			}
		}
};
struct Edge
{
	public:
		int u,v,w;
};
class Graph
{
	int **G;
	int n;
	int dir;
	int wt;
	int *vertex;
	friend class ColorGraph;
	public:
		Graph()
		{
			cout<<"\nIs your graph directed?..\nEnter \n1-Yes\n0-No\n";
			cin>>dir;
			
			cout<<"\nIs your graph weighted?..\nEnter \n1-Yes\n0-No\n";
			cin>>wt;
			
			
			cout<<"\nEnter no. of vertices\n";
			cin>>n;
			
			int i,j;
			vertex=new int[n];
			cout<<"\nEnter vertices of graph\n";
			
			for(i=0;i<n;i++)
			{
				cin>>vertex[i];
			}
			
			G=new int*[n];
			
			for(i=0;i<n;i++)
			{
				G[i]=new int[n];
			}
			
			for(i=0;i<n;i++)
			{
				for(j=0;j<n;j++)
				{
					G[i][j]=0;
				}
			}
		}
		void readGraph_vertices();
		void showGraph_vertices();
		void degree()
		{
			outdegree();
			
			if(dir)
				indegree();
		}
		void outdegree();
		void indegree();
		void readGraph_edge();
		void insert(int,int,int w=1);
		void traversal()
		{
			int *visited=new int[n];
			
			int i,start;
			
			for(i=0;i<n;i++)
			{
				visited[i]=0;
			}
			cout<<"\nEnter starting vertex\n";
			cin>>start;
//			DFS(visited,vertex[0]);
//			DFS_nonrec(visited,0);
			BFS(visited,start-vertex[0]);
		}
		void BFS(int*,int);
		void DFS(int*,int);
		void DFS_nonrec(int*,int);
		void isConnected();
		void WarshallAlgo();
		void PrimsAlgo();
		void KruskalAlgo();
		void DijkstraAlgo();
		void Topological_sort();
};
void Graph::BFS(int visited[],int start)
{
	Queue<int> Q; 
	int v,i,k,check,m=0,flag=0;
	
	cout<<vertex[start]<<" ";
	Q.enqueue(start);
	visited[start]=1;
	
	while(!Q.empty())
	{
		v=Q.dequeue();
		
		if(G[v][v]!=0)
		{
			flag++;
			break;
		}
		while(!Q.empty())
		{
			k=Q.dequeue();
//			cout<<"k="<<vertex[k]<<" ";
			if(G[v][k]!=0)
			{
				while(m<check && visited[m]!=0)
				{
					if(G[m][v]!=0 || G[m][k]!=0)
					{
						check=m;
						flag++;
						break;
					}
					m++;
				}
			}
			else
			{
				Q.enqueue(k);
				break;
			}
				
		}
		
		for(i=0;i<n;i++)
		{
			if(G[v][i]!=0 && visited[i]==0)
			{
				Q.enqueue(i);
				visited[i]=1;
				cout<<vertex[i]<<" ";
				check=i;
			}
		}
	}
	
	if(flag==1)
	{
		cout<<vertex[check];
		cout<<"\nUndirected cyclic";
	}
	else
		cout<<"\nUndirected acyclic";
}
void Graph::Topological_sort()
{
	int *indegree,*visited;
	
	indegree=new int[n];
	visited=new int[n];
	
	int i,j,k,count=0;
	
	for(i=0;i<n;i++)
	{
		visited[i]=0;
	}
	
	for(j=0;j<n;j++)
	{
		count=0;
		for(i=0;i<n;i++)
		{
			if(G[i][j])
				count++;
		}
		indegree[j]=count;
	}
	
	for(i=0;i<n;i++)
	{
		j=0;
		while(j<n)
		{
			if(indegree[j]==0 && visited[j]==0 )
			{
				visited[j]=1;
				cout<<j<<" visited"<<endl;
				
				for(k=0;k<n;k++)
				{
					if(G[j][k]!=0)
						indegree[k]--;
				}
				break;
			}
			j++;
		}
		if(j==n)
		{
			cout<<"\nCyclic Graph\n";
			break;
		}
	}
}
void Graph::DijkstraAlgo()
{
	int **cost;
	int *visited,*distance,*from;
	int i,j;
	cost=new int*[n];
	
	visited=new int[n];
	distance=new int[n];
	from=new int[n];
	
	for(i=0;i<n;i++)
	{
		cost[i]=new int[n];
		visited[i]=0;
	}
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(G[i][j]==0)
			{
				cost[i][j]=INT_MAX;
			}
			else
			{
				cost[i][j]=G[i][j];
			}
		}
	}
	
	int source,ne,min,next,v;
	cout<<"\nEnter source of path : ";
	cin>>source;
	
	source=vertex[source];
	for(i=0;i<n;i++)
	{
		visited[source]=0;
		distance[i]=cost[source][i];
		from[i]=source;
	}
	
	visited[source]=1;
	ne=n-1; //no. of edges
	
	while(ne>0)
	{
		min=INT_MAX;
		
		for(i=0;i<n;i++)
		{
			if(visited[i]==0 && min>distance[i])
			{
				min=distance[i];
				v=i;
			}
		}
		visited[v]=1;
		for(i=0;i<n;i++)
		{
			if(visited[i]==0 && G[v][i]!=0 && distance[i]>distance[v]+cost[v][i])
			{
				distance[i]=distance[v]+cost[v][i];
				from[i]=v;
			}
		}
		ne--;
	}
	
	cout<<"\nShortest paths :\n";
	for(i=0;i<n;i++)
	{
		next=i;
		
		while(source!=next)
		{
			cout<<vertex[next]<<"->";
			next=from[next];
		}
		cout<<vertex[source]<<endl;
	}
	delete cost;
}
void Graph::KruskalAlgo()
{
	int *component=new int[n];
	int i,j,cu,cv,ne,k=0,mincost=0,edgeInd=0;//cu-component of u and cv-component of v 
	Edge edge,edgelist[30];
	Edge Spanlist[30];
	
	int **tempG;
	tempG=new int*[n];

	for(i=0;i<n;i++)
	{
		tempG[i]=new int[n];
	}
	
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(G[i][j]==0)
				tempG[i][j]=INT_MAX;
			else
				tempG[i][j]=G[i][j];
		}
	}
	
	while(1)
	{
		edge.w=INT_MAX;
	
		for(i=0;edgeInd!=0 && i<=edgeInd;i++)
		{
			tempG[edgelist[i].u][edgelist[i].v]=INT_MAX;
			tempG[edgelist[i].v][edgelist[i].u]=INT_MAX;
		}
	
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(edge.w>tempG[i][j])
				{
					edge.w=tempG[i][j];
					edge.u=i;
					edge.v=j;
					edgelist[edgeInd]=edge;
				}
			}
		}
		if(edge.w==INT_MAX)
			break;
		edgeInd++;	
	}
	for(i=0;i<n;i++)
	{
		component[i]=i;
	}
	
	ne=n-1;//no of edges
	
	j=0;
	while(k<ne)
	{
		edge=edgelist[j];
		
		cu=component[edge.u];
		cv=component[edge.v];
		
		if(cu!=cv)
		{
			for(i=0;i<n;i++) //replace every cv by cu 
			{
				if(component[i]==cv)
				{
					component[i]=cu;
				}
			}
			mincost+=edge.w;
			Spanlist[k]=edge;
//			cout<<edge.w<<" ";
			k++;
		}
		j++;
	}
	cout<<"\nMinimum cost of spanning tree : "<<mincost;
	delete tempG;
}
void Graph::PrimsAlgo()
{
	int **cost, **spanning;
	int i,j;
	
	cost=new int*[n];
	spanning=new int*[n];
	
	for(i=0;i<n;i++)
	{
		cost[i]=new int[n];
		spanning[i]=new int[n];
	}
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(G[i][j]==0)
			{
				cost[i][j]=INT_MAX;
			}
			else
			{
				cost[i][j]=G[i][j];
			}
		}
	}
	
	int *visited,*distance,*from;
	
	visited=new int[n];
	distance=new int[n];
	from=new int[n];
	
	int start;
	cout<<"\nEnter start of spanning tree\n";
	cin>>start;
	
	for(i=0;i<n;i++)//visit starting vertex
	{
		visited[i]=0;
		distance[i]=cost[start][i];
		from[i]=start;
	}
	visited[start]=1;
	
	int ne;//no. of edges
	ne=n-1;//no.of vertices-1
	
	int min,u,v,mincost=0;//min:-min distance between two vertices ,mincost:-min cost of spanning tree
	
	while(ne>0)
	{
		min=INT_MAX;
		
		for(i=0;i<n;i++)
		{
			if(visited[i]==0 && min>distance[i])
			{
				min=distance[i];
				v=i;
			}
		}
		visited[v]=1;
		u=from[v];//u is to be visited from v;
		
		//add edge(u,v) to spanning tree
		spanning[u][v]=cost[u][v];
		spanning[v][u]=cost[u][v];
		
		mincost=mincost+cost[u][v];
	
		for(i=0;i<n;i++)
		{
			if(visited[i]==0 && distance[i]>cost[v][i])
			{
				distance[i]=cost[v][i];
				from[i]=v;
			}
		}
		ne--;
	}
	cout<<"\nMinimum cost of spanning tree : "<<mincost;
	delete cost;
}
void Graph::WarshallAlgo()
{
	int i,j,k;
	int **TC;
	
	TC=new int*[n];
	
	for(i=0;i<n;i++)
	{
		TC[i]=new int[n];
	}
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			TC[i][j]=G[i][j];
		}
	}
	
	for(k=0;k<n;k++)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(TC[i][j]==0)
				{
					if(TC[i][k]==1 && TC[k][j]==1)
					{
						TC[i][j]=1;
					}
				}
			}
		}
	}
	
	cout<<"\nTransitive closure : \n";
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cout<<TC[i][j]<<" ";
		}
		cout<<endl;
	}
}
void Graph::isConnected()
{
	int *visited=new int[n];
			
	int i;

	for(i=0;i<n;i++)
	{
		visited[i]=0;
	}
	DFS_nonrec(visited,0);
	
	for(i=0;i<n;i++)
	{
		if(visited[i]==0)
		{
			cout<<"\nDisconnected graph\n";
			break;
		}
	}
	if(i==n)
	{
		cout<<"\nConnected graph\n";
	}
}
void Graph::DFS_nonrec(int* visited,int v)
{
	Stack<int> S;
	S.push(v);
	
	while(!S.empty())
	{
		v=S.pop();
		
		if(visited[v]==0)
		{
			visited[v]=1;
			cout<<vertex[v]<<" ";
		}
		for(int i=0;i<n;i++)
		{
			if(G[v][i] && visited[i]==0)
			{
				S.push(i);
			}
		}
	}
}
void Graph::DFS(int *visited,int v)
{
	int i;
	
	visited[v-vertex[0]]=1;
	cout<<vertex[v-vertex[0]]<<" ";
	
	for(i=0;i<n;i++)
	{
		if(G[v-vertex[0]][i] && visited[i]==0)
			DFS(visited,i+vertex[0]);
	}
}
void Graph::readGraph_edge()
{
	int u,v,w;
	if(wt==0)
	{
		cout<<"\nKeep entering edge of graph (u,v)\n";
		while(1)
		{
			cin>>u>>v;
			if(u==-1 && v==-1)
			{
				return ;
			}
			insert(u-vertex[0],v-vertex[0]);
		}
	}
	else if(wt==1)
	{
		cout<<"\nKeep entering edge of graph (u,v,w)\n";
		while(1)
		{
			cin>>u>>v>>w;
			if(u==-1 && v==-1)
				return ;
			insert(u-vertex[0],v-vertex[0],w);
		}
	}
}
void Graph::insert(int u,int v,int w)
{
	G[u][v]=w;
	
	if(dir==0)
	{
		G[v][u]=w;
	}
}
void Graph::outdegree()
{
	int i,j,count=0;
	
	for(i=0;i<n;i++)
	{
		count=0;
		for(j=0;j<n;j++)
		{
			if(G[i][j])
				count++;
		}
		cout<<"\nDegree of "<<vertex[i]<<" : "<<count;
	}
}
void Graph::indegree()
{
	int i,j,count=0;
	
	for(j=0;j<n;j++)
	{
		count=0;
		for(i=0;i<n;i++)
		{
			if(G[i][j])
				count++;
		}
		cout<<"\nIndegree of "<<vertex[i]<<" : "<<count;
	}
}
void Graph::readGraph_vertices()
{
	cout<<"\nEnter vertices\n";
			
	int i,j;
			
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cin>>G[i][j];
		}
	}
}
void Graph::showGraph_vertices()
{
	int i,j;
			
	for(i=0;i<n;i++)
	{
		cout<<"  "<<vertex[i];
	}
	cout<<endl;
	for(i=0;i<n;i++)
	{
		cout<<vertex[i];
		for(j=0;j<n;j++)
		{
			cout<<" "<<G[i][j]<<" ";
		}
		cout<<endl;
	}
}
class ColorGraph
{
	Graph Gph;
	int m;//no. of colors
	int *color_pattern;//color pattern for graph
	
	public:
		ColorGraph()
		{
			Gph.readGraph_edge();
			cout<<"\nYour vertices matrix\n";
			Gph.showGraph_vertices();
			
			cout<<"\nEnter no. of colors : ";
			cin>>m;
			
			int i;
			
			color_pattern=new int[Gph.n];
			
			for(i=0;i<Gph.n;i++)
				color_pattern[i]=0;
		}
		void colorGraph()
		{
			bool ans=colorMy_graph(0);
			
			if(ans)
			{
				cout<<endl<<m<<" minimum colors are sufficient to color graph.\n";
				return ;
			}
			else
				cout<<endl<<m<<" colors ain't sufficient to color graph.\n";
			
			int i;
			while(1)
			{
				m++;
				for(i=0;i<Gph.n;i++)
					color_pattern[i]=0;
				ans=colorMy_graph(Gph.vertex[0]);
				if(ans)
					break;
			}
			cout<<endl<<m<<" minimum colors are required to color graph.\n";
		}
		bool colorMy_graph(int v)
		{
			if(v==Gph.n)
			{
				int i;
				cout<<"\nValid pattern : ";
				for(i=0;i<Gph.n;i++)
					cout<<color_pattern[i]<<" ";
				
				return true;
			}
			else
			{
				int c;
				bool ans;
				
				for(c=1;c<=m;c++)
				{
					if(canIcolor(v,c))
					{
						color_pattern[v]=c;
						ans=colorMy_graph(v+1);
						return ans;
					}
				}
				return false;
			}
		}
		bool canIcolor(int v,int c)
		{
			int i;
			for(i=0;i<Gph.n;i++)
			{
				if(Gph.G[v][i]!=0)
				{
					if(color_pattern[i]==c)
						return false;
				}
			}
			return true;
		}
};
int main()
{
	Graph G;
	G.readGraph_edge();
	cout<<"\nYour vertices matrix\n";
	G.showGraph_vertices();
//	G.degree();
//	cout<<"\nDFS traversal\n";
	G.traversal();
//	G.isConnected();
//	G.WarshallAlgo();
//	G.PrimsAlgo();
//	G.KruskalAlgo();
//	G.DijkstraAlgo();
//	ColorGraph CG;
//	CG.colorGraph();
//	G.Topological_sort();
	return 0;
}
