#include<bits/stdc++.h>
#include<iostream>
using namespace std;


int maximum(int a,int b){
    return a>b?a:b;
}

int maximum(int a,int b,int c){
    return(max(max(a,b),c));
}

int maxLCR(int arr[], int l, int m,int h){
    // Calculate the Left Sum 
    int sum=0;
    int left_sum = INT_MIN;
    for(int i=m;i>=l;i--)
    {
        sum= sum+arr[i];
        if(sum>left_sum){
            left_sum=sum;
        }
    }

    // Calculate the Right Sum

    sum=0;
    int right_sum =INT_MIN;
    for(int i=m;i<=h;i++)
    {
        sum=sum+arr[i];
        if(sum>right_sum)
        {
            right_sum=sum;
        }
    }

    return maximum(left_sum+right_sum-arr[m],left_sum,right_sum);
}

int maxSumSubArray(int arr[], int l, int h)
{
    if(l>h)
    {
        return 0;
    }
    if(l==h)
    {
        return arr[l];
    }

    int m= (l+h)/2;

    return maximum(maxSumSubArray(arr,l,m-1),maxSumSubArray(arr,m+1,h),maxLCR(arr,l,m,h));
}


int main() { 
    int arr[] = { -2, 3, 4, 5, 7 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    int max_sum = maxSumSubArray(arr, 0, n - 1); 
    cout << "Maximum contiguous sum is " << max_sum; 
    return 0; 
} 