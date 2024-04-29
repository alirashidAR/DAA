#include<iostream>
#include<stack>
#include<vector>
using namespace std;

struct Point{
    int x;
    int y;
};

Point p0;

//Function to find the orientation of the triplet
int orientation(Point p,Point q, Point r){
    int val = (q.y - p.y)*(r.x - q.x) - (q.x - p.x)*(r.y - q.y);
    if(val == 0) return 0;
    return (val > 0)? 1: 2;
}


//Function to swap two points
void swap(Point &p1, Point &p2){
    Point temp = p1;
    p1 = p2;
    p2 = temp;
}

//Function to find the point next to top in the stack
Point nextToTop(stack<Point> &s){
    Point p = s.top();
    s.pop();
    Point res = s.top();
    s.push(p);
    return res;
}


//Function to calculate distance
int distance(Point p, Point q)
{
    return ((q.x-p.x)*(q.x-p.x)+(q.y-p.y)*(q.y-p.y));
}


//Here we make a function for the sort() function to sort the points in the order of the polar angle, if collinear then the one which is closer to the point p0 comes first
int compare(const void *vp1, const void *vp2){
    Point *p1 = (Point *)vp1;
    Point *p2 = (Point *)vp2;
    int o = orientation(p0, *p1, *p2);
    if(o==0)
        return (distance(p0, *p2) >= distance(p0, *p1))? -1 : 1;
    return (o==2)? -1: 1;
}


void convex(Point points[],int n)
{   
    //Finding the point with the least y coordinate
    int ymin = points[0].y, min = 0;
    for(int i=1;i<n;i++)
    {
        int y = points[i].y;
        if((y<min)|| (y==min && points[i].x < points[min].x))
        {
            ymin = points[i].y;
            min = i;
        }
    }

    //swapping the minimum point with the first point
    swap(points[0], points[min]);

    //sort the points in the order of the polar angle
    p0=points[0];
    qsort(&points[1], n-1, sizeof(Point), compare);

    //Removing the points which have the same polar angle
    int m = 1;
    for(int i=1;i<n;i++)
    {
        while(i<n-1 && orientation(p0, points[i], points[i+1])==0)
            i++;
        points[m] = points[i];
        m++;
    }

    if(m<3) return;

    //initilaise the stack as first three points are always in the convex hull
    stack<Point> s;
    s.push(points[0]);
    s.push(points[1]);
    s.push(points[2]);

    // check for the remaining points with the top of the stack and the next to top of the stack and remove the points which are not in the convex hull
    for(int i=3;i<m;i++)
    {
        while(s.size()>1 && orientation(nextToTop(s),s.top(),points[i])!=2)
            s.pop();
        s.push(points[i]);
    }

    //printing the points in the convex hull
    while(!s.empty())
    {
        Point p = s.top();
        cout<<"("<<p.x<<", "<<p.y<<")"<<endl;
        s.pop();
    }
}


int main()
{
    Point points [] = {{0, 3}, {1, 1}, {2, 2}, {4, 4}, {0, 0}, {1, 2}, {3, 1}, {3, 3}};
    int n = sizeof(points)/sizeof(points[0]);
    convex(points, n);
    return 0;
}




// Time Complexity analysis
/*
The time complexity of this program can be analyzed as follows:

1. Finding the point with the least y-coordinate: This step requires iterating through all the points once, resulting in a time complexity of O(n).

2. Swapping the minimum point with the first point: This step takes constant time, O(1).

3. Sorting the points in the order of the polar angle: The sorting algorithm used is `qsort`, which has an average time complexity of O(n log n).

4. Removing the points with the same polar angle: This step requires iterating through all the points once, resulting in a time complexity of O(n).

5. Constructing the convex hull using a stack: This step requires iterating through all the points once, resulting in a time complexity of O(n).

Overall, the time complexity of this program is dominated by the sorting step, which is O(n log n). Therefore, the time complexity of the Graham Scan algorithm for finding the convex hull of a set of points is O(n log n).
*/
