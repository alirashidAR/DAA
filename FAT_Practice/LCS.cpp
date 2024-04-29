#include<iostream>
#include<string>

using namespace std;

int LCS(string s1,string s2,int &index)
{   
    int n= s1.size();
    int m =s2.size();
    int T[n+1][m+1];
    int result =0;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(i==0 || j==0)
            {
                T[i][j]=0;
            }
            else if(s1[i-1]==s2[j-1])
            {
                T[i][j] = T[i-1][j-1]+1;
                if(result<T[i][j])
                {
                    result = T[i][j];
                    index =i-1;
                }
            }
            else
            {
                T[i][j]=0;
            }
        }
    }
    return result;
}


int main()
{
    string X="aaaabbbbb";
    string Y ="zzzzzaaaaa";
    int index =0;
    int result = LCS(X,Y,index);
    cout<<result<<endl;
    for(int i=index-result+1;i<=index;i++)
    {
        cout<<X[i];
    }
    return 0;
}