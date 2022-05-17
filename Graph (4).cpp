#include<iostream>
#include<stack>
#include"Queue.h"
#include<vector>
#include<set>
#define INF 2147483647
using namespace std;
//Do not forget graph is set of V and E
struct edge
{
	int u;//initial variable
	int v;//end var
	int w;//weight
	bool operator<(edge e)
	{
		return (this->w<e.w);
	}
};
class Graph
{
	int** G;
	int n;
	int dir;
	int wt;
	int* vertex;
		int getInd(int v)
		{
			for(int i=0; i<n; i++)
			{
				if(vertex[i]==v)
					return i;	
			}
		}
	public:
		Graph()
		{
			//creating 2D matrix
			cout<<"\nHow many vertices in G ";cin>>n;
			G = new int*[n];
			vertex = new int[n];
			cout<<"\nis Directed: Press 1 for Yes and 0 for No ";cin>>dir;
			cout<<"\nis Weighted: Press 1 for Yes and 0 for No ";cin>>wt;
			for(int i=0; i<n; i++)
			{
				cout<<"\nEnter "<<i+1<<"th vertex: ";cin>>vertex[i];
				G[i]= new int[n];
			}
			for(int i=0; i<n; i++)
			{
				for(int j=0; j<n; j++)
				{
					G[i][j]=0;
				}
			}
		}
		void readgraph_matrix()
		{
			cout<<"\nIf vertices are adjacent enter weight else '0' ";
			for(int i=0;i<n;i++)
			{
				for(int j=0; j<n; j++)
				{
					cout<<"\nFor "<<vertex[i]<<" and "<<vertex[j]<<" ";
					cin>>G[i][j];	
				}	
			}	
		}
		void showgraph()
		{
			cout<<"\nG ";
			for(int i=0; i<n; i++)
			{
				cout<<vertex[i]<<" ";
			}
			cout<<endl;
			for(int i=0; i<n; i++)
			{
				cout<<vertex[i]<<" ";
				for(int j=0; j<n; j++)
				{
					cout<<G[i][j]<<" ";
				}
				cout<<endl;
			}
		}
		void Degree()
		{
			int counti;
			int counto;
			if(dir=='1')
			{
				for(int i=0; i<n; i++)
				{
					counti=0;
					counto=1;
					for(int j=0; j<n; j++)
					{
						if(G[i][j]==1)
							counti=counti+1;
						if(G[j][i]==1)
							counto=counto+1;
					}
					cout<<"\nOut Degree of "<<vertex[i]<<" is "<<counti;
					cout<<"\nIn Degree of "<<vertex[i]<<" is "<<counto;
				}
			}
			if(dir=='0')
			{
				for(int i=0; i<n; i++)
				{
					counti=0;
					for(int j=0; j<n; j++)
					{
						if(G[i][j]==1)
							counti=counti+1;
					}
					cout<<"\nDegree of "<<vertex[i]<<" is "<<counti;
				}
			}
		}
		void readgraph_edges()
		{
			int u,v,w,i=0;
			while(1)
			{
				cout<<"\nEnter edge (u,v): ";cin>>u>>v;
				if(getInd(u)==-1 || getInd(v)==-1)
					cout<<"\nGiven edge is not present!";
				if(u==-1 && v==-1)
					break;	
				if(wt==1)
				{
					cout<<"\nenter weight: ";cin>>w;
					insert(getInd(u),getInd(v),w);
					continue;	
				}	
				insert(getInd(u),getInd(v));
			}	
		}
		void insert(int u, int v, int w=1)
		{
			G[u][v] = w;
			if(dir==0)
				G[v][u]=w;
		}
		void traversal_DFS()
		{
			int* visit = new int[n];
			for(int i=0; i<n; i++){
				visit[i]=0;
			}
			cout<<"\nEnter Start vertex: ";int v;
			cin>>v;
			//DFS_rec(visit,0);
			DFS_nonrec(visit,getInd(v));
		}
		void DFS_rec(int visit[],int v)
		{
			visit[v] = 1;
			cout<<vertex[v]<<" ";
			for(int j=0; j<n; j++)
			{
				if(G[v][j]!=0 && visit[j]==0)
					DFS_rec(visit,j);
			}
		}
		void DFS_nonrec(int visit[],int v)
		{
			stack<int> s;
			int j;
			s.push(v);
			while(!s.empty())
			{
				v = s.top();
				s.pop();
				if(visit[v]==0)
				{
					cout<<vertex[v]<<" ";
					visit[v]=1;
				}
				for(int i=0; i<n; i++)
				{
					if(G[v][i]!=0 && visit[i]==0)
						s.push(i);
				}
			}
		}
		void DFS_connectivity(int visit[],int v)
		{
			stack<int> s;
			int j;
			s.push(v);
			while(!s.empty())
			{
				v = s.top();
				s.pop();
				if(visit[v]==0)
				{
					visit[v]=1;
				}
				for(int i=0; i<n; i++)
				{
					if(G[v][i]!=0 && visit[i]==0)
						s.push(i);
				}
			}
		}
		void isConnected()
		{
			int* visit = new int[n];
			for(int i=0; i<n; i++)
			{
				visit[i]=0;
			}
			DFS_connectivity(visit,0);
			int i;
			for(i=0; i<n; i++)
			{
				if(visit[i]==0)
				{
					cout<<"\nDisconnected!"<<endl;
					break;
				}
			}
			if(i==n)
				cout<<"\nConnected!"<<endl;
		}
		void BFS()
		{
			SQ<int> Q;int v;
			int* visit = new int[n];
			for(int i=0; i<n; i++)
				visit[i] = 0;
			cout<<"\nEnter start vertex: ";cin>>v;
			v = getInd(v);
			Q.enqueue(v);
			cout<<vertex[v];
			visit[v]=1;
			while(!Q.empty())
			{
				v = Q.dequeue();
				for(int i=0; i<n; i++)
				{
					if(G[v][i]!=0 && visit[i]==0)
					{
						Q.enqueue(i);
						cout<<vertex[i]<<" ";
						visit[i]=1;
					}
				}
			}
			
		}
		bool isCyclicBFS()
		{
			SQ<int> Q;int v;
			int* visit = new int[n];
			int* parent = new int[n];
			for(int i=0; i<n; i++)
			{
				visit[i] = 0;
				parent[i]=-1;
			}
			Q.enqueue(0);
			visit[0]=1;
			while(!Q.empty())
			{
				v = Q.dequeue();
				for(int i=0; i<n; i++)
				{
					if(G[v][i]!=0)
					{
						if(visit[i]==0)
						{
							Q.enqueue(i);
							parent[i]=v;
							visit[i]=1;	
						}
						else if(parent[v]!=i)
							return true;
					}
				}
			}
			return false;
		}
		bool isCyclicDFS()
		{
			int* visit = new int[n];
			int* parent = new int[n];
			for(int i=0; i<n; i++)
			{
				visit[i] = 0;
				parent[i]=-1;
			}
			stack<int> s;
			int v;
			s.push(0);
			while(!s.empty())
			{
				v = s.top();
				s.pop();
				if(visit[v]==0)
				{
					visit[v]=1;
				}
				for(int i=0; i<n; i++)
				{
					if(G[v][i]!=0)
					{
						if(visit[i]==0)
						{
							s.push(i);
							parent[i]=v;
						}
						else if(parent[v]!=i)
							return true;
					}
						
				}
			}
			return false;
		}
		void prim_algo()//for minimal cost spanning tree from undirected,connected,weighted graphs
		{
			int v;cout<<"\nenter vertex from which you want to start: ";cin>>v;
			int** cost = new int*[n];
			int** spanning = new int*[n];
			for(int i=0; i<n; i++)
			{
				cost[i]=new int[n];	
				spanning[i]=new int[n];
			}
			for(int i=0; i<n; i++)
			{
				for(int j=0;j<n;j++)
				{
					if(G[i][j]==0)
						cost[i][j]=INF;
					else
						cost[i][j]=G[i][j];
					spanning[i][j] = 0;
				}
			}
			//created cost matrix by replacing '0' from adj mat. by INF
			//now create visit,distance,from
			int *visit = new int[n];
			int *distance = new int[n];
			int *from = new int[n];
			//now initialise visit array by '0'
			int ind = this->getInd(v);
			for(int i=0; i<n; i++)
			{
				visit[i] = 0;	
			//update distances of all unvisited vertices w.r.t v.
			//so that intialise from array by 'v'
				from[i] = ind;
				distance[i] = cost[ind][i];
			}
			visit[ind] = 1;	
			//thus basic preparation is done now go for that loop 
			int ne = n-1;int u;int mincost=0;int min;
			//prim's algo says find the vertex with min cost and update 
			//distacne of unvisited vertices w.r.t that vertex if
			// cur. distance > distance from latest visited vertex
			while(ne)
			{
				//ind = this->find_min(distance,visit);
				min = distance[0];ind=0;
				for(int i=0; i<n; i++)
				{
					if(visit[i]==0 and distance[i]<min)
					{
						min = distance[i];
						ind = i;	
					}	
				}
				visit[ind] = 1;
				u = from[ind];
				//now we have edge vertex[u] and vertex[ind] add it to spanning tree
				spanning[ind][u] = cost[u][ind];
				spanning[u][ind] = cost[u][ind];
				cout<<cost[u][ind]<<endl;
				mincost = mincost + cost[u][ind];
				//now update distances of unvisited vertices w.r.t vertex[ind]
				for(int i=0; i<n; i++)
				{
					if(visit[i]==0)
					{
						if(distance[i]>cost[ind][i])
						{
							distance[i] = cost[ind][i];
							from[i] = ind;	
						}
					}
				}
				ne--;
			}
			cout<<"minimun cost is: "<<mincost<<endl;
			for(int i=0; i<n; i++)
			{
				for(int j=0; j<n; j++)
				{
					cout<<spanning[i][j]<<" ";
				}
				cout<<endl;
			}
		}
		int check_vertex(int v)//checks whether the given vertex is presnt or not
		{
			for(int i=0; i<n; i++)
			{
				if(vertex[i]==v)
					return i;
			}
			return -1;
		}
		void kruskal_algo()//undirected,weighted graphs
		{
			//create edgelist 
			//sort edgelist in asc. order of weight
			vector<edge> edgelist;//to replace vector we must know no. of edges
			//1.maintain count while scanning or
			//2.traverse G for nonzero values
			edge e;
			for(int i=0; i<n; i++)
			{
				for(int j=0; j<n; j++)
				{
					if( G[i][j]!=0)
					{
						e.u = i;
						e.v = j;
						e.w = G[i][j];
						edgelist.push_back(e);
					}
				}
			}
			for(int i=0; i<edgelist.size(); i++)
			{
				for(int j=i+1; j<edgelist.size(); j++)
				{
					if(edgelist[i].w > edgelist[j].w)
					{
						e =  edgelist[i];
						edgelist[i] = edgelist[j];
						edgelist[j] = e; 
					}
					
				}
			}
			//create spanlist
			edge* spanlist = new edge[n-1];
			e.u = -1; e.v = -1; e.w = 0;
			for(int i=0; i<n-1; i++)
				spanlist[i] = e;
			//create component and initialise all three arrays.
			int* component = new int[n];
			for(int i=0;i<n; i++)
				component[i] = i;
			//now traverse edgelist array and go on adding edges from
			int k=0; int i=0; int ne = n-1;int cu,cv;
			while(k<ne)
			{
				cu = component[edgelist[i].u];
				cv = component[edgelist[i].v];
				if(cu!=cv)
				{
					spanlist[k] = edgelist[i];
					k++;
					for(int i=0;i<n; i++)
					{
						if(component[i]==cv)
							component[i] = cu;
					}
				}
				i++;
			}
			cout<<endl;
			for(int i=0; i<ne; i++)
			{
				cout<<vertex[spanlist[i].u]<<" "<<vertex[spanlist[i].v]<<" "<<spanlist[i].w<<endl;
			//	cout<<spanlist[i].u<<" "<<spanlist[i].v<<" "<<spanlist[i].w<<endl;
			}
		}
		void dijkstra_algo()//for getting shortest distance from single source
		//works for both dir and undir graph 
		//does not work for negative edge weight
		//options are bellamn-ford algo and floyd-warshal algo
		{
			int v;cout<<"\nenter source vertex: ";cin>>v;
			if(check_vertex(v)==-1)
			{
				cout<<"\nGiven vertex is not present !";
				return;
			}
			int** cost = new int*[n];
			for(int i=0; i<n; i++)
				cost[i]=new int[n];	
			for(int i=0; i<n; i++)
			{
				for(int j=0;j<n;j++)
				{
					if(G[i][j]==0)
						cost[i][j]=INF;
					else
						cost[i][j]=G[i][j];
				}
			}
			//created cost matrix by replacing '0' from adj mat. by INF
			//now create visit,distance,from
			int *visit = new int[n];
			int *distance = new int[n];
			int *from = new int[n];
			//now initialise visit array by '0'
			int ind = this->getInd(v);
			for(int i=0; i<n; i++)
			{
				visit[i] = 0;	
			//update distances of all unvisited vertices w.r.t v.
			//so that intialise from array by 'v'
				from[i] = ind;
				distance[i] = cost[ind][i];
			}
			visit[ind] = 1;
			int ne = n-1;int min;
			while(ne)
			{
				//ind = this->find_min(distance,visit);
				min = distance[0];ind=0;
				for(int i=0; i<n; i++)
				{
					if(visit[i]==0 and distance[i]<min)
					{
						min = distance[i];
						ind = i;	
					}	
				}
				visit[ind] = 1;
				for(int i=0; i<n; i++)
				{
					//or use distance cost[ind][i] != INF
					if(visit[i]==0 && G[ind][i]!=0 && distance[i]>distance[ind]+cost[ind][i])
					{
						distance[i]=distance[ind]+cost[ind][i];
						from[i]=ind;
					}
				}
				ne--;
			}
			int next;
			for(int i=0; i<n; i++)
			{
				stack<int> s;
				next = vertex[i];
				cout<<v<<"->";
				while(next!=v)
				{
					s.push(next);
					next = vertex[from[getInd(next)]];
				}
				while(!s.empty())
				{
					cout<<s.top()<<"->";
					s.pop();
				}	
				cout<<" (path ends)"<<endl;	
			}
		}
		void Topology()
		{
			int count;
			int* indegree = new int[n];
			int* visit = new int[n];
			for(int i=0; i<n; i++)
				visit[i]=0;
			for(int i=0; i<n; i++)
			{
				count = 0;
				for(int j=0; j<n; j++)
				{
					if(G[j][i]!=0)
						count++;
				}
				indegree[i] = count;
			}
			/*int i,j;
			for(i=0; i<n; i++)
			{
				j=0;
				while(j<n)
				{
					if(indegree[j]==0 && visit[j]==0)
					{
						cout<<vertex[j]<<" ";
						visit[j]=1;
						for(int k=0; k<n; k++)
						{
							if(G[j][k] !=0 )
							{
								indegree[k]--;
							}
						}
						break;
					}
					j++;
				}
				if(j==n)
				{
					cout<<"\ncyclic directed graph";
					break;
				}
				if(j==n-1)
					cout<<"\nacyclic directed graph";		
			}*/
			int i,j=0,flag;
			for(i=0; i<n; i++)
			{
				flag = 0;
				if(indegree[j]==0 && visit[j]==0)
				{
					cout<<vertex[j]<<" ";
					visit[j]=1;
					for(int k=0; k<n; k++)
					{
						if(G[j][k] !=0 )
						{
							indegree[k]--;
							if(indegree[k]==0 && visit[k] ==0 && flag==0)//only check for fisrt occurence of indegree 0
							{
								
								j = k;
								flag = 1;
								break;                                          
							}	
						}
					}
					if(flag==0)
					{
						int k;
						for(k=0; k<n; k++)
						{
							if(visit[k]==0 && indegree[k]==0 )
							{
								j = k;
								break;
							}		
						}
						//cout<<"\nk= "<<k;
						if(k==n)
							break;
					}
				}
			}
			if(i==n-1)//if iterations equals no. of vertices acylic
				cout<<"\nacyclic directed graph";
			else
				cout<<"\ncyclic directed graph";		
		}
		void warshal_algo()//to get path matrix of directed graph
		{
			int** TC = new int*[n];
			for(int i=0; i<n; i++)
				TC[i] = new int[n];
				
			for(int i=0; i<n; i++)
			{
				for(int j=0; j<n; j++)
					TC[i][j] = G[i][j];
			}
			
			for(int k=0; k<n; k++)
			{
				for(int i=0; i<n; i++)
				{
					for(int j=0; j<n; j++)
					{
						if(TC[i][j]==0 && (TC[i][k]!=0 && TC[k][j]!=0))//olny check dependent path via k if there is no path
						{
							TC[i][j]=1;
						}
					}
				}
			}
			
			cout<<"\nP ";
			for(int i=0; i<n; i++)
			{
				cout<<vertex[i]<<" ";
			}
			cout<<endl;
			for(int i=0; i<n; i++)
			{
				cout<<vertex[i]<<" ";
				for(int j=0; j<n; j++)
				{
					cout<<TC[i][j]<<" ";
				}
				cout<<endl;
			}
		}
		void floy_warshal_algo()//for directed weighted with negative values 
		//but no negative weight cycle
		{
			int** TC = new int*[n];
			for(int i=0; i<n; i++)
				TC[i] = new int[n];
				
			for(int i=0; i<n; i++)
			{
				for(int j=0; j<n; j++)
				{
					if(G[i][j]==0)
						TC[i][j] = INF;
					else
						TC[i][j] = G[i][j];
				}
			}
			for(int k=0; k<n; k++)
			{
				for(int i=0; i<n; i++)
				{
					for(int j=0; j<n; j++)
					{
						if(TC[i][j]>(TC[i][k] + TC[k][j]) && (TC[i][k]!=INF && TC[k][j]!=INF))//olny check dependent path via k if there is no path
							TC[i][j]=TC[i][k] + TC[k][j];
					}
				}
			}
			cout<<"\nP ";
			for(int i=0; i<n; i++)
			{
				cout<<vertex[i]<<" ";
			}
			cout<<endl;
			for(int i=0; i<n; i++)
			{
				cout<<vertex[i]<<" ";
				for(int j=0; j<n; j++)
				{
					if(TC[i][j]==INF)
						cout<<"I ";
					else
						cout<<TC[i][j]<<" ";
				}
				cout<<endl;
			}
		}
		friend class Color;
};
class Color
{
	Graph Gph;
	int nc;
	int* color;
	int* given;
		int check_all_colored()
		{
			for(int i=0; i<Gph.n; i++)
			{
				if(given[i]==-1)
					return i;
			}
			return -1;
		}
		void colormygraph(int ind)
		{
			int next;
			if(ind==Gph.n)
			{
				for(int i=0; i<Gph.n; i++)
				{
					cout<<given[i]<<" ";
				}
				cout<<endl;
			}
			else
			{
				for(int i=0; i<nc; i++)
				{
					next = -1;
					if(canicolor(ind,color[i]))
					{
						given[ind] = color[i];
						for(int i=0; i<Gph.n; i++)
						{
							if(given[i]==-1)
							{
								next = i;break;
							}		
						}
						if(next==-1)
							colormygraph(Gph.n);
						else
							colormygraph(next);
						given[ind]=-1;
					}
				}	
			}
		}
		bool colormygraph1(int ind)
		{
			int next;
			if(ind==Gph.n)
			{
				return true;
			}
			else
			{
				for(int i=0; i<nc; i++)
				{
					next = -1;
					if(canicolor(ind,color[i]))
					{
						given[ind] = color[i];
						//next = this->check_all_colored();
						for(int i=0; i<Gph.n; i++)
						{
							if(given[i]==-1)
							{
								next = i;break;
							}		
						}
						if(next==-1)
							return colormygraph1(Gph.n);
						else
							return colormygraph1(next);
					}
				}
				return false;	
			}
		}
		bool canicolor(int ind,int c)
		{
			for(int i=0; i<Gph.n; i++)
			{
				if(Gph.G[ind][i]!=0)
				{
					if(given[i] == c)
						return false;  
				}		
			}
			return true;
		}
		void colormygraph2(int ind)
		{
			int next;
			if(ind==Gph.n)
			{
				return;
			}
			else
			{
				for(int i=0; i<nc; i++)
				{	next = -1;
					if(canicolor(ind,color[i]))
					{
						given[ind] = color[i];
					//	next = this->check_all_colored();
						for(int i=0; i<Gph.n; i++)
						{
							if(given[i]==-1)
							{
								next = i;break;
							}		
						}
						if(next==-1)
						{
							colormygraph2(Gph.n);
							return;
						}
						else
						{
							colormygraph2(next);
							return;
						}		 					
					}
				}
				nc++;
				color[nc-1] = nc;
			}
		}
	public:
		Color()
		{
			Gph.readgraph_edges();
			//Gph.showgraph();
			cout<<"\nEnter Number of Colors: ";cin>>nc;
			color = new int[nc];
			given = new int[Gph.n];
			if(nc!=0)
				cout<<"\nEnter color codes: ";
			for(int i=0; i<nc; i++)
				cin>>color[i];
			for(int i=0; i<Gph.n; i++)
				given[i]=-1;	
		}
		
		void all_possible_colors()
		{	
			this->colormygraph(0);
		}
		void isColorSufficient()//coloring decision
		{
			if(colormygraph1(0))
				cout<<"\ncolors are sufficient to color the graph";
			else
				cout<<"\ncolors are not sufficient";
		}
		void findmcolors()
		{
			for(int i=0; i<Gph.n; i++)
				colormygraph2(0);
			cout<<"\nmin number of colors needed are: "<<nc;
		}
};
int main()
{
	Graph G;
//	G.readgraph_matrix();
//	G.showgraph();
	G.readgraph_edges();
	G.showgraph();
//	G.traversal_DFS();
//	G.isConnected();
//	G.DFS_nonrec();
//	int v;
//	if(G.check_vertex(v)!=-1)
//		G.prims_algo(v);
//	else
//		cout<<"\nvertex not present!";
//	G.kruskal_algo();
//	G.dijkstra_algo();
//	Color Cg;
//	Cg.all_possible_colors();
//	Cg.findmcolors();	
//	Cg.isColorSufficient();
	//G.Topology();
	/*G.BFS();
	bool i=G.isCyclicDFS();
	if(i==true)
		cout<<"cylic";
	else
		cout<<"acylic";
	i=G.isCyclicBFS();
	if(i==true)
		cout<<"cylic";
	else
		cout<<"acylic";*/ 
//	G.warshal_algo();
	G.floy_warshal_algo();	
	return 0;
}

