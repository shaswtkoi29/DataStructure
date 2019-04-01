//
//  FinalProject.cpp
//
//
//  STUDENT NAME: Shaswat Koirala
//
//  DUE DATE: FRIDAY 7/27

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <iostream>
#include "HashTable.cpp"
//#include "HashTable.hpp"
#include "Utils.cpp"

using namespace std;

// TODO: modify it accordingly as of the write up instruction
// Your main should have parameters as the program will run with command line
// arguments (correct the current behavior!)

int main(int argc,char *argv[]) {
    string filename;
    const string END_OF_BOOK_DATA = "***************";
    string title, body, line;
    filename=argv[1];
    
    ifstream infile(filename.c_str());
    if(infile.fail()){
        cout << "ERROR: could not open input file " << filename << endl;
        return 1;
    }
    // HashTable  blist;
    ZippedBookNode *here=new ZippedBookNode;
    Utils *here2;
    HashTable<20> myHashTable;
    while(getline(infile, title)){
        title = title.substr(1);
        body = "";
        while(getline(infile, line)){
            if(line == END_OF_BOOK_DATA)
                break;
            body += line + "\n";
        }
        string encodedString;
        here2->computeFrequency(body, body.length());
        here2->HuffmanCodes(body.length());
        for (auto i: body) encodedString+=codes[i];
        here->title=title;
        here->c_excerpt=encodedString;
       // here->huff_root=here2->root;
        here->next=NULL;
        cout<<here->title<<endl;
        // myHashTable.insertNode(here);
        
    }
    cout<<"1"<<endl;
    infile.close();
    myHashTable.insertNode(here);
    myHashTable.printTitles();
    cout<<"2"<<endl;
    
    return 0;
    
}


































