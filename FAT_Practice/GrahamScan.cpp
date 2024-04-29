#include<iostream>
#include<vector>
#include<stack>

using namespace std;

struct Point
{
    int x;
    int y;
};

Point p0;

int orientation(Point p,Point q,Point r)
{
    int val = (q.y-p.y)*(r.x-q.x) - (q.x-p.x)*(r.y-q.y);
    if(val==0) return 0;
    return (val>0)?1:2;
}

int swap(Point &p1,Point &p2)
{
    Point temp =p1;
    p1=p2;
    p2= temp;
}

Point nextToTop(stack<Point>& stack)
{
    Point p = stack.top();
    stack.pop();
    Point res = stack.top();
    stack.push(p);
    return res;
}

int distance(Point p, Point q)
{
    return ((q.x-p.x)*(q.x-p.x)+(q.y-p.y)*(q.y-p.y));
}

int compare(const void *p1, const void *p2)
{
    Point *p1 = (Point *)p1;
    
}