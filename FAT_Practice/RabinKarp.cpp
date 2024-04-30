#include<iostream>
#include<string>

using namespace std;

#define d 256

int rabinKarp(string pat, string text,int q)
{
    int M = pat.size();
    int N = text.size();
    int i,j;
    int p=0;
    int t=0;
    int h=1;

    for(int i=0;i<M-1;i++)
    {
        h=(h*d)%q;
    }

    // Calculating the pattern and text value for the first window

    for(i=0;i<M;i++)
    {
        p=(p*d+pat[i])%q;
        t=(t*d+text[i])%q;
    }

    //Now going through the text;
    for(i=0;i<=N-M;i++)
    {
        if(p==t)
        {
            for(j=0;j<M;j++)
            {
                if(text[i+j]!=pat[j])
                {
                    break;
                }
            }
             if(j==M)
                {   
            cout<<"Pattern Found at:"<<i<<endl;
                }
        }
        if(i<N-M)
        {
            t=(d*(t-text[i]*h)+text[i+M])%q;

            if(t<0)
            {
                t=t+q;
            }
        }
    }
}

int main()
{
    char txt[] = "GEEKS FOR GEEKS";
    char pat[] = "GEEK";
 
    // we mod to avoid overflowing of value but we should
    // take as big q as possible to avoid the collison
    int q = 17;
 
    // Function Call
    rabinKarp(pat, txt, q);
    return 0;
}