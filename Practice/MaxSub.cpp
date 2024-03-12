#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int maximum(int a, int b)
{
    return max(a,b);
}

int maximum(int a, int b, int c)
{
    return max(a,max(b,c));
}

int LCR(int arr[], int l, int m, int h)
{
    int sum=0;
    int left_sum= INT_MIN;
    for(int i=m;i>=l;i--)
    {
        sum+=arr[i];
        if(sum>left_sum)
        {
            left_sum=sum;
        }
    }

    sum=0;
    int right_sum= INT_MIN;
    for(int i=m;i<=h;i++)
    {
        sum+=arr[i];
        if(sum>right_sum)
        {
            right_sum=sum;
        }
    }

    return maximum(left_sum+right_sum-arr[m],left_sum,right_sum);
}


int maximumSubArray(int arr[], int l, int h)
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

    return maximum(maximumSubArray(arr,l,m-1),maximumSubArray(arr,m+1,h),LCR(arr,l,m,h));
}


int main()
{
    int arr[]={-2,-3,4,-1,-2,1,5,-3};
    int n=sizeof(arr)/sizeof(arr[0]);
    int max_sum=maximumSubArray(arr,0,n-1);
    cout<<max_sum;
    return 0;
}