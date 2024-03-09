#include<iostream>

#define NUM_STATION 4
#define NUM_LINE 2

using namespace std;

int minimum(int a, int b)
{
    return min(a,b);
}


int als(int a[][NUM_STATION],int t[][NUM_STATION],int *E, int *X){
    int T1[NUM_STATION], T2[NUM_STATION],i;
    T1[0] = E[0] + a[0][0];
    T2[0] = E[1] + a[1][0];

    for(i=1;i<NUM_STATION;i++)
    {
        T1[i]=minimum(T1[i-1]+a[0][i],T2[i-1]+t[1][i]+a[0][i]);
        T2[i]=minimum(T2[i-1]+a[1][i],T1[i-1]+t[0][i]+a[1][i]);
    }

    return minimum(T1[NUM_STATION-1]+X[0],T2[NUM_STATION-1]+X[1]);
}


int main()
{
    int a[][NUM_STATION] = {{4, 5, 3, 2},  
                            {2, 10, 1, 4}};  
    int t[][NUM_STATION] = {{0, 7, 4, 5},  
                            {0, 9, 2, 8}};  
    int e[] = {10, 12}, x[] = {18, 7};  
  
    cout << "The minimum time is " << als(a, t, e, x) << " minutes\n";
  
    return 0;  
}