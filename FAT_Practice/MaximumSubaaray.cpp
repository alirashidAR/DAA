#include <iostream>
#include <climits>
using namespace std;

int max(int a, int b) {
    return (a > b) ? a : b;
}

int max(int a, int b, int c) {
    return max(a, max(b, c));
}

int maxCrossingSum(int arr[], int l, int m, int h) {
    int prod = 1;
    int left_prod = INT_MIN;
    for (int i = m; i >= l; i--) {
        prod *= arr[i];
        if (left_prod < prod) {
            left_prod = prod;
        }
    }

    prod = 1;
    int right_prod = INT_MIN;
    for (int i = m + 1; i <= h; i++) {
        prod *= arr[i];
        if (right_prod < prod) {
            right_prod = prod;
        }
    }

    return max(left_prod * right_prod, left_prod, right_prod);
}

int maxArray(int arr[], int l, int h) {
    if (l == h) {
        return arr[l];
    }

    int m = (l + h) / 2;
    return max(maxArray(arr, l, m), maxArray(arr, m + 1, h), maxCrossingSum(arr, l, m, h));
}

int main() {
    int arr[] = {2, -1, -1, 0,0};
    int n = sizeof(arr) / sizeof(arr[0]);

    int maxProduct = maxArray(arr, 0, n - 1);
    cout << "The maximum product subarray is: " << maxProduct << endl;

    return 0;
}