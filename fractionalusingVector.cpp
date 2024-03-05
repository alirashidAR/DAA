#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Item
{
    int value;
    int weight;
};

bool cmp(Item &a, Item &b)
{
    return (1.0*a.value/a.weight) > (1.0*b.value/b.weight);
}


double fractionalKnapsack(int W, vector<Item> &arr, int n)
{
    sort(arr.begin(),arr.end(),cmp);
    int currentWeight=0;
    double finalValue=0.0;
    for(int i=0;i<n;i++)
    {
        if(currentWeight+arr[i].weight<=W)
        {
            currentWeight += arr[i].weight;
            finalValue += arr[i].value;
        }
        else
        {
            int leftWeight = W-currentWeight;
            finalValue += arr[i].value * ((double)leftWeight/arr[i].weight);
        }
    }
    return finalValue;
}


int main()
{
    int W = 60; // Weight of knapsack
    int w[5];
    for(int i=0;i<5;i++)
    {
        w[i]=i+10;
    }
    int v[5];
    for(int i=0;i<5;i++)
    {
        v[i]=i*10;
    }
    vector<Item> arr;
    for(int i=0;i<5;i++)
    {
        Item obj;
        obj.value = v[i];
        obj.weight = w[i];
        arr.push_back(obj);
    }
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Maximum value we can obtain = " << fractionalKnapsack(W, arr, n);
    return 0;
}




