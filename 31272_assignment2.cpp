#include <bits/stdc++.h>
using namespace std;
#define ROW 8
#define COL 5

class Pair
{
public:
    int x;
    int y;
    Pair(int a, int b)
    {
        x = a;
        y = b;
    }
};

bool isValid(int grid[ROW][COL], Pair *val)
{
    if (val->x >= 0 && val->x < ROW && val->y >= 0 && val->y < COL && grid[val->x][val->y] == 1)
    {
        return true;
    };
    return false;
};

double calculateHValue(Pair *a, Pair *b)
{
    return ((double)sqrt((a->x - b->x) * (a->x - b->x) + (a->y - b->y) * (a->y - b->y)));
}

Pair *minNearby(int grid[ROW][COL], Pair *val, Pair *dest)
{
    Pair *minPoint = new Pair(-1, -1);
    double minDistance = 9999999.0;

    vector<Pair *> nearbyPoints;

    Pair *br = new Pair(val->x + 1, val->y + 1);
    nearbyPoints.push_back(br);
    Pair *b = new Pair(val->x + 1, val->y);
    nearbyPoints.push_back(b);
    Pair *bl = new Pair(val->x, val->y - 1);
    nearbyPoints.push_back(bl);
    Pair *r = new Pair(val->x, val->y + 1);
    nearbyPoints.push_back(r);
    Pair *l = new Pair(val->x, val->y - 1);
    nearbyPoints.push_back(l);
    Pair *tr = new Pair(val->x - 1, val->y + 1);
    nearbyPoints.push_back(tr);
    Pair *tl = new Pair(val->x - 1, val->y - 1);
    nearbyPoints.push_back(tl);
    Pair *t = new Pair(val->x - 1, val->y);
    nearbyPoints.push_back(t);

    for (int i = 0; i < nearbyPoints.size(); i++)
    {
        if (isValid(grid, nearbyPoints[i]))
        {
            double tempDist = calculateHValue(nearbyPoints[i], dest);
            if (tempDist < minDistance)
            {
                minDistance = tempDist;
                minPoint = nearbyPoints[i];
            }
        }
    }

    return minPoint;
}

void calculatePath(int grid[ROW][COL], Pair *src, Pair *dest)
{
    vector<Pair *> pathlist;
    pathlist.push_back(src);

    Pair *last = src;
    bool reached = false;
    while (!reached)
    {
        Pair *next = minNearby(grid, last, dest);
        if (next->x == -1 && next->y == -1)
        {
            cout << "Path doesn't exists after (" << last->x << "," << last->y << ")" << endl;
            return;
        }
        pathlist.push_back(next);
        last = next;
        if (next->x == dest->x && next->y == dest->y)
        {
            reached = true;
        }
    }

    cout << "path is ";
    for (int i = 0; i < pathlist.size(); i++)
    {
        cout << " => (" << pathlist[i]->x << "," << pathlist[i]->y << ")";
    }
}

int main()
{
    //1-not blocked, 0-blocked
    int grid[ROW][COL] = {
        {1, 1, 1, 1, 1},
        {1, 1, 1, 0, 1},
        {0, 0, 1, 0, 1},
        {1, 1, 1, 0, 1},
        {1, 0, 1, 0, 1},
        {1, 0, 1, 1, 1},
        {1, 0, 1, 0, 1},
        {1, 1, 1, 1, 1},
    };

    int srcx, srcy, destx, desty;

    cout<<"Enter src x : ";
    cin>>srcx;
    cout<<"Enter src y : ";
    cin>>srcy;
    cout<<"Enter dest x : ";
    cin>>destx;
    cout<<"Enter dest y : ";
    cin>>desty;
    Pair *src = new Pair(srcx, srcy);
    Pair *dest = new Pair(destx, desty);

    //Pair *src = new Pair(7, 0);
    //Pair *dest = new Pair(0, 0);

    if (!isValid(grid, src))
    {
        cout << "src is not valid" << endl;
        return 0;
    }
    else if (!isValid(grid, dest))
    {
        cout << "dest is not valid" << endl;
        return 0;
    }
    else if (src->x == dest->x && src->y == dest->y)
    {
        cout << "src & dest are same" << endl;
        return 0;
    }
    else
    {
        calculatePath(grid, src, dest);
    }

    return 0;
}