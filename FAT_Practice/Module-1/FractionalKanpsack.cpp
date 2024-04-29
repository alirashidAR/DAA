#include<iostream>
#include<algorithm>
using namespace std;

struct Item
{
    int val;
    int weight;
};


bool compare(Item &a, Item &b)
{
    double r1 = (double)a.val/a.weight;
    double r2 = (double)b.val/b.weight;
    return r1>r2;
}

double fractionalKnapsack(int W, Item arr[], int n)
{
    sort(arr,arr+n,compare);
    int curWeight = 0;
    double finalValue =0;
    for(int i=0;i<n;i++)
    {
        if(curWeight+arr[i].weight<=W)
        {
            curWeight += arr[i].weight;
            finalValue += arr[i].val;
        }
        else
        {
            finalValue += arr[i].val*((double)(W-curWeight)/arr[i].weight);
            break;
        }
    }
    return finalValue;
}



int main()
{
    Item arr [] ={{120,50},{100,40},{60,10}};
    int W = 50;
    cout<<fractionalKnapsack(W,arr,3);
}