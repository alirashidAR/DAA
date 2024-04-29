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
    int prod=1;
    int left_prod= INT_MIN;
    for(int i=m;i>=l;i--)
    {
        prod*=arr[i];
        if(prod>left_prod)
        {
            left_prod=prod;
        }
    }

    prod=1;
    int right_prod= INT_MIN;
    for(int i=m;i<=h;i++)
    {
        prod*=arr[i];
        if(prod>right_prod)
        {
            right_prod=prod;
        }
    }

    return maximum((left_prod*right_prod)/arr[m],left_prod,right_prod);
}


int maximumSubArray(int arr[], int l, int h)
{
    if(l>h)
    {
        return 1;
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
    int arr[]={6,-4,-5,8,0,7};
    int n=sizeof(arr)/sizeof(arr[0]);
    int max_sum=maximumSubArray(arr,0,n-1);
    cout<<max_sum;
    return 0;
}