#include<iostream>
#include<queue>
#include<bits/stdc++.h>
using namespace std;

struct node{
    char letter;
    int freq;
    node *left;
    node *right;
    node(char letter, int freq)
    {
        this->letter=letter;
        this->freq=freq;
        left = NULL;
        right = NULL;
    }
};

struct compare
{
    bool operator()(node *l, node*r)
    {
        return (l->freq>r->freq);
    }
};

void printCodes(node *root, string s)
{
    if(root!=NULL)
    {
        if(root->letter !='*')
        {
            cout<<root->letter<<":"<<s<<" ";
        }
        printCodes(root->left,s+"0");
        printCodes(root->right,s+"1");
    }
}

void decode(node *root, string s)
{
    node *temp = root;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='0')
        {
            temp = temp->left;
        }
        else
        {
            temp = temp->right;
        }
        if(temp->left==NULL && temp->right==NULL)
        {
            cout<<temp->letter;
            temp = root; // Reset temp to the root after decoding a character
        }
    }
}

void hoffman(char data[], int freq[], int n)
{
    struct node *lchild, *rchild;
    priority_queue<node*, vector<node*>,compare> pq;
    for(int i=0;i<n;i++)
    {
        pq.push(new node(data[i],freq[i]));
    }
    while(pq.size()>1)
    {
        lchild = pq.top();
        pq.pop();
        rchild = pq.top();
        pq.pop();
        struct node *temp;
        temp = new node('*',lchild->freq+rchild->freq);
        temp->left=lchild;
        temp->right=rchild;
        pq.push(temp);
    }
    printCodes(pq.top(),"");
    cout << endl;
    decode(pq.top(), "10010011010010"); // Sample decoded string to test
}

int main()
{
    char A[] =  {'A','B','D','E','F'};
    int freq[] = {3,4,5,6,4};
    hoffman(A,freq,5);
    return 0;
}
