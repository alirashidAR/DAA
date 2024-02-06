#include<iostream>
#include<cmath>
using namespace std;
int getSize(long);
long karatsuba(long, long);

long karatsuba(long X,long Y){

    if(X<10 && Y<10){
        return X*Y;
    }

    int size = max(getSize(X),getSize(Y));
    if(size<10)
        return X*Y;

    size = (size/2)+ (size%2);
    long multiplier = pow(10,size);
    long a = X/multiplier;
    long b = X -(b*multiplier);
    long c = Y/multiplier;
    long d = Y -(c*multiplier);
    long U = karatsuba(a,c);
    long V = karatsuba(b,d);
    long W = karatsuba(a+b,c+d)-U-V;
    return U * (long)pow(10,2*size) + W *(long)pow(10,size) + V;
}

int getSize(long value)
{
    int count=0;
    while(value>0){
        count++;
        value/=10;
    }
    return count;
}


int main(){
    cout<<"The product of the two numbers is: "<<karatsuba(345,3453343)<<endl;
    return 0;
}