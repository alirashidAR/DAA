#include<iostream>
#include<algorithm>
using namespace std;

struct Item{
    int value;
    int weight;
};



bool cmp(Item &a, Item &b){
    return (1.0*a.value/a.weight) > (1.0*b.value/b.weight);
}


//Function to get the maximum total value in the knapsack.
double fractionalKnapsack(int W, Item arr[], int n)
{
    sort(arr,arr+n,cmp);
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
             int remainWeight = W-currentWeight;
            finalValue += arr[i].value * ((double)remainWeight/arr[i].weight);
            break;
        }
    }
    return finalValue;
}
        
int main()
{
    int W = 50; // Weight of knapsack
    Item arr[] = {{60, 10}, {100, 20}, {120, 30}};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Maximum value we can obtain = " << fractionalKnapsack(W, arr, n);
    return 0;
}