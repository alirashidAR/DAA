#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector<int>prefix_function(string s)
{
    int n = s.length();
    vector<int> pi(n);
    for(int i=1; i<n; i++)
    {
        int j = pi[i-1];
        while(j>0 && s[i]!=s[j])
            j = pi[j-1];
        if(s[i]==s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

int main()
{
    string t="abababca";
    string n="ab";
    vector<int> pi = prefix_function(n);
    int i=0, j=0;
    int pos=-1;
    while(i<t.length())
    {
        if(t[i]==n[j])
        {
            i++;
            j++;
        }
        else
        {
            if(j!=0)
                j = pi[j-1];
            else
                i++;
        }
        if(j==n.length())  
        {
            pos = i-j;
            break;
        }
    }
    cout<<pos;
}