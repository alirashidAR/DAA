#include <iostream>
#include <string.h>
using namespace std;

/* Returns length of longest 
common substring of X[0..m-1]
and Y[0..n-1] */
int LCSubStr(char* X, char* Y, int m, int n, int& endIndex)
{
    // Create a table to store 
    // lengths of longest
    // common suffixes of substrings. 
    // Note that LCSuff[i][j] contains 
    // length of longest common suffix 
    // of X[0..i-1] and Y[0..j-1].
  
    int LCSuff[m + 1][n + 1];
    int result = 0; // To store length of the
                    // longest common substring
    endIndex = -1; // To store the ending index of the longest common substring

    /* Following steps build LCSuff[m+1][n+1] in
        bottom up fashion. */
    for (int i = 0; i <= m; i++) 
    {
        for (int j = 0; j <= n; j++) 
        {
            // The first row and first column
            // entries have no logical meaning,
            // they are used only for simplicity
            // of program
            if (i == 0 || j == 0)
                LCSuff[i][j] = 0;

            else if (X[i - 1] == Y[j - 1]) {
                LCSuff[i][j] = LCSuff[i - 1][j - 1] + 1;
                if (LCSuff[i][j] > result) {
                    result = LCSuff[i][j];
                    endIndex = i - 1; // Update ending index of the longest common substring
                }
            }
            else
                LCSuff[i][j] = 0;
        }
    }
    return result;
}

// Driver code
int main()
{
    char X[] = "OldSite:GeeksforGeeks.org";
    char Y[] = "NewSite:GeeksQuiz.com";

    int m = strlen(X);
    int n = strlen(Y);

    int endIndex;
    int length = LCSubStr(X, Y, m, n, endIndex);
    if (length > 0) {
        cout << "Length of Longest Common Substring is " << length << endl;
        cout << "Longest Common Substring is: ";
        for (int i = endIndex - length + 1; i <= endIndex; i++) {
            cout << X[i];
        }
    }
    else {
        cout << "No common substring found.";
    }
    return 0;
}
