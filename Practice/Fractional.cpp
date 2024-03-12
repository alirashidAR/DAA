#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Item
{
    int weight;
    int value;
};

bool cmp(Item &a, Item &b)
{
    return 1.0*(a.value/a.weight) > 1.0*(b.value/b.weight);
}


int frac(Item arr[], int n, int W)
{
    sort(arr,arr+n,cmp);
    int curWeight = 0;
    double finalValue = 0.0;
    for(int i=0;i<n;i++)
    {
        if(curWeight+arr[i].weight<=W)
        {
            curWeight += arr[i].weight;
            finalValue += arr[i].value;
        }
        else
        {
            int remain = W - curWeight;
            finalValue += arr[i].value * ((double)remain/arr[i].weight);
            break;
        }
    }
    return finalValue;
}


int main()
{
    int n=3;
    int W=240;
    Item arr[]={{60,10},{100,20},{120,30}}; // 240
    cout<<frac(arr,n,W);
    return 0;
}