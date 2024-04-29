#include<iostream>
#include<stack>
#include<climits>

using namespace std;

struct Point
{
    int x;
    int y;
};

Point p0;

int orientation(Point p, Point q, Point r)
{
    int val = (q.y-p.y)*(r.x-q.x)-(q.x-p.x)*(r.y-q.y);
    if(val==0) return 0;
    return (val>0)?1:2;
}

void swap(Point &a, Point &b)
{
    Point temp = a;
    a=b;
    b= temp;
}

int distance(Point q,Point p)
{
    return (p.y-q.y)*(p.y-q.y)+(p.x-q.x)*(p.x-q.x);
}

Point nextToTop(stack<Point> &s)
{
    Point p = s.top();
    s.pop();
    Point res = s.top();
    s.push(p);

    return res;
}


int compare(const void *vp1,const void *vp2 )
{
    Point *p1 =(Point *)vp1;
    Point *p2 = (Point *)vp2;
    int o = orientation(p0,*p1,*p2);
    if(o==0)
    {
        return (distance(p0,*p2)>distance(p0,*p1))?-1:1;
    }
    return (o==2)?-1:1;
}


void convexHull(Point points[], int n)
{
    int ymin = points[0].y, min=0;
    for(int i=1;i<n;i++)
    {
        int y = points[i].y;
        if((ymin<y)||(y==ymin && points[i].x<points[min].x))
        {
            ymin=y;
            min=i;
        }
    }

    //swampping;
    swap(points[0],points[min]);

    p0 = points[0];
    qsort(&points[1],n-1,sizeof(Point),compare);

    int m=1;
    for(int i=1;i<n;i++)
    {
        while(i<n-1 && orientation(p0,points[i],points[i+1])==0)
            i++;
        points[m]=points[i];
        m++;
    }

    if(m<3) return;

    stack<Point> s;
    s.push(points[0]);
    s.push(points[1]);
    s.push(points[2]);

    for(int i=3;i<m;i++)
    {
        if(s.size()>1 &&orientation(nextToTop(s),s.top(),points[i])!=2)
            s.pop();
        s.push(points[i]);
    }

    while (!s.empty())
{
	Point p = s.top();
	cout << "(" << p.x << ", " << p.y <<")" << endl;
	s.pop();
}

}


int main()
{
	Point points[] = {{0, 3}, {1, 1}, {2, 2}, {4, 4},
					{0, 0}, {1, 2}, {3, 1}, {3, 3}};
	int n = sizeof(points)/sizeof(points[0]);
	convexHull(points, n);
	return 0;
}

