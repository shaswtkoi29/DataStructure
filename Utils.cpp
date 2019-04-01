//
//  Utils.cpp
//
//
//  Created by cami on 7/19/18.
//
//

#include "Utils.hpp"
using namespace std;
Utils::Utils(){
    
}

Utils::~Utils(){
    
}
struct compare{
    bool operator()(HuffNode* l, HuffNode* r)
    {
        return (l->freq > r->freq);
    }
};

void Utils:: printCodes(struct HuffNode* root, string str)
{
    if (!root)
        return;
    if (root->data != NULL)
        //   if (root->data)
        cout << root->data << ": " << str << "\n";
    printCodes(root->left, str + "0");
    printCodes(root->right, str + "1");
}

// utility function to store characters along with
// there huffman value in a hash table, here we
// have C++ STL map
void Utils:: storeCodes(struct HuffNode* root, string str)
{
    if (root==NULL)
        return;
    if (root->data != NULL)
        //   if (root->data)
        codes[root->data]=str;
    storeCodes(root->left, str + "0");
    storeCodes(root->right, str + "1");
}

// STL priority queue to store heap tree, with respect
// to their heap root node value
priority_queue<HuffNode*, vector<HuffNode*>, compare> minHeap;

// function to build the Huffman tree and store it
// in minHeap
void Utils::  HuffmanCodes(int size)
{
    struct HuffNode *left, *right, *top;
    for (map<char, int>::iterator v=freq.begin(); v!=freq.end(); v++)
        minHeap.push(new HuffNode(v->first, v->second));
    while (minHeap.size() != 1)
    {
        left = minHeap.top();
        minHeap.pop();
        right = minHeap.top();
        minHeap.pop();
        top = new HuffNode(NULL, left->freq + right->freq);
        top->left = left;
        top->right = right;
        minHeap.push(top);
    }
    storeCodes(minHeap.top(), "");
}

// utility function to store map each character with its
// frequency in input string
void Utils:: computeFrequency(string str, int n)
{
    for (int i=0; i<str.size(); i++)
        freq[str[i]]++;
}

// function iterates through the encoded string s
// if s[i]=='1' then move to node->right
// if s[i]=='0' then move to node->left
// if leaf node append the node->data to our output string
string Utils:: decode_file(struct HuffNode* root, string s)
{
    string ans = "";
    struct HuffNode* curr = root;
    for (int i=0;i<s.size();i++)
    {
        if (s[i] == '0')
            curr = curr->left;
        else
            curr = curr->right;
        
        // reached leaf node
        if (curr->left==NULL and curr->right==NULL)
        {
            ans += curr->data;
            curr = root;
        }
    }
    // cout<<ans<<endl;
    return ans+'\0';
}



