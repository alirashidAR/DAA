#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int n=4;

int distan[10][10] = {                
                    {0, 10, 15, 20},
                    {10, 0, 35, 25},
                    {15, 35, 0, 30},
                    {20, 25, 30, 0}
};

int done_visit =(1<<n)-1;

int DP[16][4];


int TSP(int mark,int position){
    if(mark==done_visit){
        return distan[position][0];
    }
    if(DP[mark][position]!=-1)
    {
        return DP[mark][position];
    }
    int answer = INT_MAX;

    for(int c=0;c<n;c++){
        if((mark&(1<<c))==0){
            int new_answer = distan[position][c]+TSP(mark|(1<<c),c);
            answer = min(answer,new_answer);
        }
    }
    return DP[mark][position] = answer;
}


int main(){
    /* initialize the DP array */
    for(int i=0;i<(1<<n);i++){
        for(int j=0;j<n;j++){
            DP[i][j] = -1;
        }
    }
  cout<<"Minimum Distance Travelled by you is "<<TSP(2,0);
return 0;
}