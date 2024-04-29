#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int maxSum(int arr[], int n)
{
    int max_end = INT_MIN;
    int max_till =0;
    for(int i=0;i<n;i++)
    {
        max_till +=  arr[i];
        if(max_end<max_till)
        {
            max_end = max_till;
        }
        if(max_till<0)
        {
            max_till = 0;
        }
    }

    return max_end;
}


int main(){
    int arr[] ={-1,2,3,4,5,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<maxSum(arr,n);
}