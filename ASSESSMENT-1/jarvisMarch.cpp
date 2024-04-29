#include<iostream>
#include<vector>
using namespace std;


struct Point
{
    int x, y;
};

//Function to find orientation of the triplet
int orientation(Point p, Point q, Point r)
{
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0)
        return 0;
    return (val > 0) ? 1 : 2;
}

//Function to find the convex hull
void hull(Point points[],int n)
{
    if (n<3) return;

    vector<Point> hull;

    // Find the leftmost point
    int l=0;
    for(int i=1;i<n;i++)
        if(points[i].x<points[l].x)
            l=i;
    
    int p=l,q;

    // Traverse the points in the anti-clockwise direction
    do
    {
        hull.push_back(points[p]);
        q=(p+1)%n;
        
        //Finding the next point in the hull
        for(int i=0;i<n;i++){
            if(orientation(points[p],points[i],points[q])==2)
                q=i;
        }
        p=q;
    }while(p!=l);


    //Printing the points in the hull
    for(auto i:hull)
        cout<<"("<<i.x<<","<<i.y<<")"<<endl;
}


int main()
{
    Point points[] = {{0, 3}, {1, 1}, {2, 2}, {4, 4},
                       {0, 0}, {1, 2}, {3, 1}, {3, 3}};
    int n = sizeof(points) / sizeof(points[0]);
    hull(points, n);
    return 0;
}





/*
The time complexity of the code can be analyzed as follows:

Finding the leftmost point: This step takes O(n) time because we iterate through all the points to find the leftmost point.

Finding the next point in the hull: This step also takes O(n) time because we iterate through all the points to find the next point in the hull.

Constructing the convex hull: The do-while loop runs h times, where h is the number of points on the convex hull. In each iteration, we perform constant time operations like pushing a point to the hull vector. Therefore, constructing the convex hull takes O(h) time.

Overall, the time complexity of the code is O(h * n), where h is the number of points on the convex hull and n is the total number of points. In the worst case, h can be equal to n, resulting in a time complexity of O(n^2). However, in practice, the number of points on the convex hull is usually much smaller than the total number of points, leading to an average-case time complexity of O(n).
*/