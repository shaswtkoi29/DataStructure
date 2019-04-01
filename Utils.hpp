//
//  Utils.hpp
//
//
//  Created by cami on 7/19/18.
//
//
/*
 
 Huffman findings/research discussion
 
 TODO: write a brief introduction on what you understood from the Huffman encoding. Make sure to explain the algorithm and the steps take for encoding and decoding.
 Huffman coding sounded to be most coolest way to save memory
 
 */

int sum = hashSum(node->title);
if(lookupTable[sum]==NULL){
    lookupTable[sum]=node;
}
else{
    
    ZippedBookNode* tmp=lookupTable[sum];
    while(tmp!=NULL){
        if(tmp->title==node->title) return;
        tmp=tmp->next;
    }
    tmp=lookupTable[sum];
    while(tmp->next!=NULL && node->title > tmp->title){
        tmp=tmp->next;
    }
    node->next=tmp->next;
    tmp->next=node;
}
}













#ifndef Utils_hpp
#define Utils_hpp
#include <stdio.h>
#include <stdio.h>
#include "stdc++.h"
#include <map>
#include <iostream>
#define MAX_TREE_HT 256
using namespace std;
map<char, string> codes;
map<char, int> freq;
struct HuffNode{
    char data;
    int freq;
    HuffNode *left, *right;
    
    HuffNode(char l, int f)
    {
        left = right = NULL;
        data = l;
        freq = f;
    }
};





class Utils {
    
public:
    
    Utils();
    ~Utils();
    void printCodes(struct HuffNode* root, string str);
    void storeCodes(struct HuffNode* root, string str);
    void HuffmanCodes(int size);
    string decode_file(struct HuffNode* root, string s);
    void huffDecode();
    void computeFrequency(string str,int n);
    HuffNode *root;
    
    
};

#endif /* Utils_hpp */

