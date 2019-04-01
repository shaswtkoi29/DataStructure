#include <vector>
#include <string>
#include <stdlib.h>
#include <iostream>
#include <climits>
#include "HashTable.hpp"
#include <stack>
using namespace std;

template <int ARRAY_LEN>
HashTable<ARRAY_LEN>::HashTable() {
    //  for(int i = 0; i< ARRAY_LEN; i++){
    //    lookupTable[i] = new ZippedBookNode("empty",NULL,NULL,NULL);
    //  }
    tableSize = ARRAY_LEN;
    //  lookupTable[ARRAY_LEN];
    // lookupTable= new ZippedBookNode*[tableSize];
    for(int j = 0; j < tableSize; j++){
        lookupTable[j] = NULL;
    }
}


template <int ARRAY_LEN>
HashTable<ARRAY_LEN>::~HashTable() {
    stack <ZippedBookNode*> wordItemStack;
    for(int i = 0; i<ARRAY_LEN; i++){
        ZippedBookNode* c;
        for(ZippedBookNode*c=lookupTable[i]; c; c=c->next) wordItemStack.push(c);
        while(!wordItemStack.empty()){
            c=wordItemStack.top();
            delete c;
            wordItemStack.pop();
        }
    }
}

template <int ARRAY_LEN>
int HashTable<ARRAY_LEN>::getTableSize() {
    if(ARRAY_LEN <= 0){
        return -1;
    }
    else{
        tableSize = ARRAY_LEN;
        return tableSize;
    }
}

template <int ARRAY_LEN>
void HashTable<ARRAY_LEN>::insertNode(ZippedBookNode* node) {
    //int index=hashSum(node->title,ARRAY_LEN)
    int sum = hashSum(node->title);
    //ZippedBookNode *newNode=new ZippedBookNode("empty",nullptr,nullptr,node);
    if(!lookupTable[sum]){
        lookupTable[sum]=node;
    }
    else{
        ZippedBookNode* tmp=lookupTable[sum];
        while(tmp->next){
            tmp=tmp->next;
        }
        tmp->next=node;
    }

    
}



template <int ARRAY_LEN>
void HashTable<ARRAY_LEN>::printTitles() {
    
    ZippedBookNode *current = new ZippedBookNode;
    for (int i = 0; i < ARRAY_LEN; i++)
    {
        if (lookupTable[i] != NULL){
            current = lookupTable[i];
            cout <<current->title<<endl;
            while(current -> next != NULL)
            {
                current = current -> next;
                cout<<current->title<<endl;
            }
        }
    }
}

    
    // TODO: print out all the titles. Give the following output format:
    // 1) if the title is at the index it should be preceeded by '#'
    // 2) if the title is chained it should be precede by '->'
    // 3) items at the same index should be on the same line
    // example
    //          # test->test6->test12
    //          # test4->test5
    //          # test1->test11

