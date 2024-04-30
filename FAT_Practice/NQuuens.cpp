#include<iostream>
#include<vector>

using namespace std;

bool Place(int k, int col, vector<int> & chessboard);
bool Nqueens(int k,int n,vector<int> & chessboard);


bool Nqueens(int k,int n, vector<int> & chessboard)
{
    if(k==n+1)
    {
        return true;
    }
    for(int col=1;col<=n;col++)
    {
        if(Place(k,col,chessboard))
        {
            chessboard[k-1]=col;
            if(Nqueens(k+1,n,chessboard))
            {
                return true;
            }
            chessboard[k-1]=0;
        }
    }
    return false;
}


bool Place(int k,int col,vector<int> & chessboard)
{
    for(int i=1;i<k;i++)
    {
        if(chessboard[i-1]==col || abs(i-k)==abs(chessboard[i-1]-col))
        {
            return false;
        }
    }
}


void printCode(vector<int>& chessboard,int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(chessboard[i]==j+1)
            {
                cout<<"Q ";
            }
            else
            {
                cout<<"* ";
            }
        }
        cout<<endl;
    }
}

int main()
{
    int n=16;
    vector<int> chessboard(n,0);
    if(Nqueens(1,n,chessboard))
    {
        printCode(chessboard,n);
    }
    else
    {
        cout<<"No solution exists";
    }
    return 0;
}