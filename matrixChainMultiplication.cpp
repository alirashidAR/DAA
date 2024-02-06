#include<iostream>
#include<bits/stdc++.h>
#include<cmath>

using namespace std;

int matrixChainMultiplication(int arr[], int i, int j){
    if(i==j)
    {
        return 0;
    }
    int k, count;
    int mini = INT_MAX;
    for(k=i;k<j;k++)
    {
        count = matrixChainMultiplication(arr,i,k)+ matrixChainMultiplication(arr,k+1,j)+arr[i-1]*arr[k]*arr[j];
        mini = min(mini,count);
    }

    return mini;
}


int main(){
    int arr[] = {1, 2, 3, 4, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Minimum number of multiplications is " << matrixChainMultiplication(arr, 1, n-1);
    return 0;   
}