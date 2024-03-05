#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

struct MinHeapNode
{
    char data;
    unsigned freq;
    struct MinHeapNode *left, *right;
};

struct MinHeap
{
    unsigned size;
    unsigned capacity;
    struct MinHeapNode **array;
};

struct MinHeapNode *newNode(char data, unsigned freq)
{
    struct MinHeapNode *temp = (struct MinHeapNode *)malloc(sizeof(struct MinHeapNode));

    temp->left = temp->right = NULL;
    temp->data = data;
    temp->freq = freq;

    return temp;
}

struct MinHeap *createMinHeap(unsigned capacity)
{
    struct MinHeap *minHeap = (struct MinHeap *)malloc(sizeof(struct MinHeap));

    minHeap->size = 0;
    minHeap->capacity = capacity;

    minHeap->array = (struct MinHeapNode **)malloc(minHeap->capacity * sizeof(struct MinHeapNode *));
    return minHeap;
}

void swapMinHeapNode(struct MinHeapNode **a, struct MinHeapNode **b)
{
    struct MinHeapNode *t = *a;
    *a = *b;
    *b = t;
}

void minHeapify(struct MinHeap *minHeap, int idx)
{
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minHeap->size && minHeap->array[left]->freq < minHeap->array[smallest]->freq)
        smallest = left;

    if (right < minHeap->size && minHeap->array[right]->freq < minHeap->array[smallest]->freq)
        smallest = right;

    if (smallest != idx)
    {
        swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

int isSizeOne(struct MinHeap *minHeap)
{
    return (minHeap->size == 1);
}

struct MinHeapNode *extract(struct MinHeap *minHeap)
{
    struct MinHeapNode *temp = minHeap->array[0];

    minHeap->array[0] = minHeap->array[minHeap->size - 1];

    --minHeap->size;
    minHeapify(minHeap, 0);

    return temp;
}

void insertMinHeap(struct MinHeap *minHeap, struct MinHeapNode *minHeapNode)
{
    ++minHeap->size;
    int i = minHeap->size - 1;

    while (i && minHeapNode->freq < minHeap->array[(i - 1) / 2]->freq)
    {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }

    minHeap->array[i] = minHeapNode;
}

void buildMinHeap(struct MinHeap *minHeap)
{
    int n = minHeap->size - 1;
    int i;

    for (int i = (n - 1) / 2; i >= 0; --i)
        minHeapify(minHeap, i);
}

void printArr(int arr[], int n)
{
    int i;
    for (i = 0; i < n; ++i)
        cout << arr[i];

    cout << "\n";
}

int isLeaf(struct MinHeapNode *root)
{
    return !(root->left) && !(root->right);
}

struct MinHeap *createAndBuildMinHeap(char data[], int freq[], int size)
{
    struct MinHeap *minHeap = createMinHeap(size);

    for (int i = 0; i < size; ++i)
        minHeap->array[i] = newNode(data[i], freq[i]);

    minHeap->size = size;
    buildMinHeap(minHeap);

    return minHeap;
}

struct MinHeapNode *buildHuffmanTree(char data[], int freq[], int size)
{
    struct MinHeapNode *left, *right, *top;

    struct MinHeap *minHeap = createAndBuildMinHeap(data, freq, size);

    while (!isSizeOne(minHeap))
    {
        left = extract(minHeap);
        right = extract(minHeap);

        top = newNode('$', left->freq + right->freq);

        top->left = left;
        top->right = right;

        insertMinHeap(minHeap, top);
    }

    return extract(minHeap);
}

void printCodes(struct MinHeapNode *root, int arr[], int top)
{
    if (root->left)
    {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }

    if (root->right)
    {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }

    if (isLeaf(root))
    {
        cout << root->data << ": ";
        printArr(arr, top);
    }
}


void HuffmanCodes(char data[], int freq[], int size)
{
    struct MinHeapNode *root = buildHuffmanTree(data, freq, size);

    int arr[100], top = 0;

    printCodes(root, arr, top);
}

// Decoding function
void HuffmanDecode(struct MinHeapNode *root, string encodedData)
{
    struct MinHeapNode *currentNode = root;
    string decodedData = "";

    for (char bit : encodedData)
    {
        if (bit == '0')
            currentNode = currentNode->left;
        else
            currentNode = currentNode->right;

        if (isLeaf(currentNode))
        {
            decodedData += currentNode->data;
            currentNode = root;
        }
    }

    cout << "Decoded data: " << decodedData << endl;
}

int calculateBits(struct MinHeapNode *root, int depth) {
    if (root == NULL)
        return 0;

    if (isLeaf(root))
        return root->freq * depth;

    return calculateBits(root->left, depth + 1) + calculateBits(root->right, depth + 1);
}


int totalCodeBits(struct MinHeapNode *root,int depth)
{
    if (root == NULL)
        return 0;

    if (isLeaf(root))
        return depth;

    return totalCodeBits(root->left, depth + 1) + totalCodeBits(root->right, depth + 1);
}


int calculateAsciiBits(int freq[], int size) {
    int totalBits = 0;
    for (int i = 0; i < size; ++i) {
        // Each character in ASCII requires 8 bits (1 byte)
        totalBits += 8;
    }
    return totalBits;
}




int main() 
{
    char arr[] = {'c', 'd', 'g', 'u', 'm', 'a'};
    int freq[] = {34, 9, 35, 2, 2, 100};

    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Huffman Codes:\n";
    HuffmanCodes(arr, freq, size);

    // Calculate total bits
    int totalBits = calculateBits(buildHuffmanTree(arr, freq, size), 0);
    cout << "Total bits required for encoding: " << totalBits << endl;

    int asciiBits = calculateAsciiBits(freq, size);
    cout << "Total bits required for ASCII: " << asciiBits << endl;

    int bits = totalCodeBits(buildHuffmanTree(arr, freq, size), 0);
    cout << "Total bits required for codes: " << bits << endl;

    cout<<"Sum of bits required for encoding and table:"<<totalBits+asciiBits+bits<<endl;   


    // Sample encoded data
    string encodedData = "0101101101001";

    // Decoding
    HuffmanDecode(buildHuffmanTree(arr, freq, size), encodedData);

    return 0;
}
