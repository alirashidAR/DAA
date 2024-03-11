#include<iostream>
#include<queue>
using namespace std;

struct node
{
    char letter;
    int frequency;
    node *left;
    node *right;
    node(char l, int f)
    {
        letter =l;
        frequency=f;
        left=NULL;
        right=NULL;
    }
};

struct compare
{
    bool operator()(node* left, node *right)
    {
        return (left->frequency>right->frequency);
    }
};


void printCodes(node *root, string str)
{
    if(root!=NULL)
    {
        if(root->letter!='*')
        {
            cout<<root->letter<<": "<<str<<endl;
        }
        printCodes(root->left,str+"0");
        printCodes(root->right,str+"1");
    }

}


void hoffman(char data[],int freq[],int n)
{
    struct node *lchild, *rchild;
    priority_queue<node*, vector<node*>,compare> pq;
    for(int i=0;i<n;i++)
    {
        pq.push(new node(data[i],freq[i]));
    }
    while(pq.size()>1)
    {
        lchild=pq.top();
        pq.pop();
        rchild=pq.top();
        pq.pop();
        struct node *temp;
        temp = new node('*',lchild->frequency+rchild->frequency);
        temp->left=lchild;
        temp->right=rchild;
        pq.push(temp);
    }
    printCodes(pq.top()," ");
}

int main()
{
    char A[] =  {'A','B','D','E','F'};
    int freq[] = {3,4,5,6,4};
    hoffman(A,freq,5);
}