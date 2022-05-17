#include <iostream> 
using namespace std;

class Graph
{
    int v;
    int e;
    int **adjmatrix;

public:
    Graph(int v, int e)
    {
        this->v = v;
        this->e = e;
        adjmatrix = new int *[v];
        for (int i = 0; i < v; i++)
        {
            adjmatrix[i] = new int[v];
        }
        // initialize to 0
        for (int i = 0; i < v; i++)
        {
            for (int j = 0; j < v; j++)
            {
                adjmatrix[i][j] = 0;
            }
        }
    }
    void acceptGraph();
    void display();
    void prims(int v1);
}; 

void Graph::acceptGraph()
{
    int s, d, cost;
    for (int i = 0; i < e; i++)
    {
        cout << "enter " << i + 1 << " edge " << endl;
        cout << "enter first vertex :";
        cin >> s;
        cout << "enter second vertex :";
        cin >> d;
        cout << "enter cost :";
        cin >> cost;
        adjmatrix[s][d] = cost;
        adjmatrix[d][s] = cost;
    }
}
void Graph::display()
{
    cout << "\n displaying adjuncy matrix : " << endl;
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            cout << adjmatrix[i][j] << " ";
        }
        cout << endl;
    }
}
void Graph::prims(int v1)
{    
    int n = v,v2, count1 = 1, count = 0, wt = 0;
    int father[n], A[n+1];
    for (int i = 0; i < n; i++)
    {
        father[i] = -1;
    }
    for (int i = 0; i < n+1; i++)
    {
        A[i] = -1;
    }
    A[count1] = v1;
    count1++;
    int result[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            result[i][j] = 0;
        }
    }
    while (count < n - 1)
    {   
        int t1, t2, min, temp1, temp2, root_temp1, root_temp2;
        min = 9999;
        for (v1=1;v1<count1;v1++){
            for(v2=1;v2<n;v2++){
                if(adjmatrix[A[v1]][v2]!=0 && adjmatrix[A[v1]][v2]<min){
                    min=adjmatrix[A[v1]][v2];
                    t1 = A[v1];
                    t2=v2;
                }
            }
        }
        temp1=t1;
        temp2=t2;
        adjmatrix[t1][t2]=adjmatrix[t1][t2]=0;
        while(t1>=0){
            root_temp1=t1;
            t1=father[t1];
        }
        while(t2>=0){
            root_temp2=t2;
            t2=father[t2];
        }
        if(root_temp1!=root_temp2){
            result[temp1][temp2]=result[temp2][temp1]=min;
            wt = wt + result[temp1][temp2];
            father[root_temp2]=root_temp1;
            count++;
            A[count1]=temp2;
            count1++;
        }
    }
    cout << "\n displaying prims result : " << endl;
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    cout << "\n min weight of path by prims is :" << wt << endl;
    ;
}
int main()
{
    int vertnum, edgenum, choice;
    cout << "enter number of vertices :";
    cin >> vertnum;
    cout << "enter number of edges :";
    cin >> edgenum;
    Graph obj(vertnum, edgenum);
    obj.acceptGraph();
    obj.display();
    obj.prims(0); 

    return 0;
}


