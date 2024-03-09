#include<iostream>
using namespace std;



int check(string s, string p)
{
    int s_len= s.length();
    int p_len=  p.length();
    for(int i=0;i<s_len-p_len+1;i++)
    {
        bool flag = true;
        for(int j=0;j<p_len && flag==true;j++)
        {
            if(p[j]!=s[j+i-1])
            {
                flag = false;
            }
        }
        if(flag==true)
        {
            return i;
        }
    }

    return -1;
}

int main()
{
    string s = "aaabbbbaaaa";
    string p = "bbb";
    cout<<check(s,p);
    return 0;
}