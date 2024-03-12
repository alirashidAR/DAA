#include<iostream>
#include<bits/stdc++.h>

using namespace std;


int LCS(string X, string Y, int &index)
{
    int m= X.length();
    int n= Y.length();

    int P[m+1][n+1];
    int result=0;


    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i==0 |j ==0)
            {
                P[i][j]=0;
            }
            else if(X[i-1]==Y[j-1])
            {
                P[i][j]=P[i-1][j-1]+1;
                if(result<P[i][j])
                {
                    result=P[i][j];
                    index=i-1;
                }
            }
            else   
                P[i][j]=0;
        }
    }
    return result;
}


int main()
{
    string X = "OldSite:GeeksforGeeks.org";
    string Y = "NewSite:GeeksQuiz.com";


    int endIndex;
    int length = LCS(X, Y, endIndex);
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