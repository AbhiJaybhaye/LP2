//1.	Implement depth first search algorithm and Breadth First Search algorithm, Use an undirected graph
//      and develop a recursive algorithm for searching all the vertices of a graph or tree data structure.

#include <bits/stdc++.h>
#define Size 40
using namespace std;

class Queue
{
private:
    int front, rear;
    int item[Size];

public:
    Queue()
    {
        front = -1;
        rear = -1;
    }
    bool isfull()
    {
        if (rear == Size - 1)
        {
            return true;
        }
        return false;
    }
    bool isempty()
    {
        if (rear == -1 || front > rear)
        {
            return true;
        }
        return false;
    }
    void enqueue(int id)
    {

        if (isfull())
        {
            return;
        }
        if (front == -1)
        {
            front = 0;
        }
        rear++;
        item[rear] = id;
    }
    int dequeue()
    {
        if (isempty())
        {
            return -1;
        }

        int dd = item[front];
        front++;
        return dd;
    }
};

class Stack
{
private:
    int top;
    int stacklist[Size];

public:
    Stack()
    {
        top = -1;
    }
    bool stackempty()
    {
        if (top < 0)
        {
            return true;
        }
        return false;
    }
    bool stackfull()
    {
        if (top >= Size - 1)
        {
            return true;
        }
        return false;
    }
    void push(int st)
    {
        if (stackfull())
        {
            return;
        }
        top++;
        stacklist[top] = st;
    }
    int pop()
    {
        if (stackempty())
        {
            return -1;
        }
        int popeditem = stacklist[top];
        top--;
        return popeditem;
    }
};

class Graph
{
    int v, e;
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
        for (int i = 0; i < v; i++)
        {
            for (int j = 0; j < v; j++)
            {
                adjmatrix[i][j] = 0;
            }
        }
    }
    void graphinput();
    void graphdisplay();
    void BFS();
    void DFS();
};

void Graph::graphinput()
{
    int s, d;
    for (int i = 0; i < e; i++)
    {
        cout << "enter details of edge : " << i + 1 << endl;
        cout << "enter source vertex : ";
        cin >> s;
        cout << "enter destination vertex : ";
        cin >> d;
        adjmatrix[s][d] = 1;
        adjmatrix[d][s] = 1;
    }
}

void Graph::graphdisplay()
{
    cout << "\nThe enter graph's adjancy matrix is : \n"
         << endl;
    for (int i = 0; i < v; i++)
    {
        cout << i << " : ";
        for (int j = 0; j < v; j++)
        {
            cout << adjmatrix[i][j] << " ";
        }
        cout << endl;
    }
}

void Graph::BFS()
{
    cout << "\nBFS result : ";
    int visited[v];
    for (int i = 0; i < v; i++)
    {
        visited[i] = 0;
    }

    bool exit = 0;
    Queue qobj;
    qobj.enqueue(0);
    visited[0] = 1;

    while (!exit)
    {
        int poped = qobj.dequeue();
        //cout << "poped" << poped << endl;
        if (poped != -1)
        {
            for (int i = 0; i < v; i++)
            {
                if (adjmatrix[poped][i] == 1 && visited[i] == 0)
                {
                    //cout << "enque" << i << endl;
                    qobj.enqueue(i);
                    visited[i] = 1;
                }
            }

            cout << poped << " ";
        }

        bool flag = 1;
        for (int i = 0; i < v; i++)
        {
            if (visited[i] == 0)
            {
                flag = 0;
            }
        }
        //cout << "flag" << flag << endl;
        if (flag == 1)
        {
            exit = 1;
        }
    }
    while (!qobj.isempty())
    {
        int poped = qobj.dequeue();
        cout << poped << " ";
    }
}

void Graph::DFS()
{
    Stack sobj;
    cout << "\nDFS result : ";
    int visited[v];
    for (int i = 0; i < v; i++)
    {
        visited[i] = 0;
    }

    bool exit = 0;
    sobj.push(0);
    visited[0] = 1;

    while (!sobj.stackempty())
    {
        int poped = sobj.pop();
        cout << " " << poped;
        //cout << "poped" << poped << endl;

        for (int i = 0; i < v; i++)
        {
            if (adjmatrix[poped][i] == 1 && visited[i] == 0)
            {
                //cout << "enque" << i << endl;
                sobj.push(i);
                visited[i] = 1;
            }
        }
    }
};

int main()
{
    int v, e;
    cout << "enter vertices count : ";
    cin >> v;
    cout << "Vertices will be from 0 to " << v - 1 << endl;
    cout << "enter Edge count : ";
    cin >> e;
    Graph obj(v, e);
    obj.graphinput();
    obj.graphdisplay();

    obj.BFS();
    obj.DFS();
    return 0;
}