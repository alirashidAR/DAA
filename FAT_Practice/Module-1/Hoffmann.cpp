#include<iostream>
#include<queue>
using namespace std;

struct node
{
    char letter;
    int frequency;
    node *left;
    node *right;
    node(char letter, int frequency){
        this->letter=letter;
        this->frequency=frequency;
        left= NULL;
        right=NULL;
    }
};

struct compare
{
    bool operator()(node* l, node *r)
    {
        return (l->frequency>r->frequency);
    }
};


void printCodes(node *root, string str)
{
    if(root!=NULL)
    {
        if(root->letter!='*')
        {
            cout<<root->letter<<":"<<str<<endl;
        }
        printCodes(root->left,str+"0");
        printCodes(root->right,str+"1");
    }
}


void hoffmann(char data[], int frequency[], int n)
{
    struct node * lchild, *rchild;
    priority_queue<node*, vector<node*>, compare> pq;
    for(int i=0;i<n;i++)
    {
        pq.push(new node(data[i],frequency[i]));
    }

    while(pq.size()>1)
    {
        lchild=pq.top();
        pq.pop();
        rchild=pq.top();
        pq.pop();
        struct node * temp;
        temp = new node('*',lchild->frequency+rchild->frequency);
        temp->left=lchild;
        temp->right=rchild;
        pq.push(temp);
    }
    printCodes(pq.top()," ");
}

int main()
{
    char data [] = {'A','C','F','D','E'};
    int freq [] = {41,5,6,12,1};
    hoffmann(data,freq,5);
}