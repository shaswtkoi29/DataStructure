#include <fstream>
#include <iostream>
#include <cstdlib>
using namespace std;


struct book_node{
    string title;
    string body;
    book_node *next;
};

class book_list{
private:
    book_node *head, *tail;
    int count;
public:
    
    book_list(){
        head = nullptr;
        tail = nullptr;
        count = 0;
    }
    void add(string title, string body){
        book_node *b = new book_node;
        b->title = title;
        b->body = body;
        b->next = nullptr;
        
        if(empty()){
            head = tail = b;
        }
        else{
            tail->next = b;
            tail = b;
        }
        count++;
    }
    
    bool empty(){
        return head == nullptr;
    }
    
    int size(){
        return count;
    }
    
    book_node* get(int index){
        if(index < 0 || index >= size())
            return nullptr;
        else {
            book_node* current = head;
            for(int i = 0; i < index; i++)
                current = current->next;
            return current;
        }
    }
    
    void printTitles(){
        book_node *current = head;
        cout << "List of titles" << endl;
        cout << "--------------" << endl;
        for(int i = 1; i <= count; i++){
            cout << i << ". " << current->title << endl;
            current = current->next;
        }
        cout << endl;
    }
    
    ~book_list(){
        book_node *temp;
        while(head != nullptr){
            temp = head->next;
            delete head;
            head = temp;
        }
        head = nullptr;
        tail = nullptr;
    }
    
};

int main(){
    string filename;
    const string END_OF_BOOK_DATA = "***************";
    string title, body, line;
    
    cout << "Enter input filename: ";
    cin >> filename;
    
    ifstream infile(filename.c_str());
    if(infile.fail()){
        cout << "ERROR: could not open input file " << filename << endl;
        return 1;
    }
    
    book_list blist;
    
    while(getline(infile, title)){
        title = title.substr(1); //discard 1st char and keep rest
        body = "";
        while(getline(infile, line)){
            if(line == END_OF_BOOK_DATA)
                break;
            body += line + "\n";
        }
        
        blist.add(title, body);
    }
    
    infile.close();
    
    int choice = -1;
    while(choice != 0){
        blist.printTitles();
        cout << "Enter title number (type 0 to quit): ";
        cin >> choice;
        if(choice != 0){
            book_node *b = blist.get(choice-1);
            if(b == nullptr){
                cout << "Non existing title!" << endl;
            }
            else
                cout << b->body << endl << endl;
            
        }
    }
}

















#include <string>
#include <iostream>
#include <stack>

#define ARRAY_LEN 10
using namespace std;


struct ZippedBookNode{
    
    string title;
    
    string body;
    
    hoffnode* huff_root;
    
    ZippedBookNode *next;
    
    
    ZippedBookNode()
    
    {
        
    }
    
    ZippedBookNode(std::string name, string e, HuffNode* hr, ZippedBookNode* n)
    
    {
        
        title=name;
        
        c_excerpt=e;
        
        huff_root=hr;
        
        next=n;
        
    }
    
};

class HashTable{
    int tableSize;
    ZippedBookNode* lookupTable[10];
};

template

HashTable::HashTable() {
    tableSize = ARRAY_LEN;
    for(int j = 0; j < tableSize; j++){
        
        lookupTable[j] = NULL;
        
    }
    
}

template

HashTable::~HashTable() {
    
    stack<ZippedBookNode*> wordItemStack;
    
    for(int i = 0; i<10;i++){
        
        ZippedBookNode* c;
        
        for(ZippedBookNode*c=lookupTable[i]; c; c=c->next) wordItemStack.push(c);
        
        while(!wordItemStack.empty()){
            
            c=wordItemStack.top();
            
            delete c;
            
            wordItemStack.pop();
            
        }
        
    }
    
}

template

int HashTable::getTableSize() {
    
    if(ARRAY_LEN <= 0){
        
        return -1;
        
    }
    
    else{
        
        tableSize = ARRAY_LEN;
        
        return tableSize;
        
    }
    
}

template

void HashTable::insertNode(ZippedBookNode* node) {
    
    
    int sum = hashSum(node->title);
    
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

template

void HashTable::printTitles() {
    
    ZippedBookNode *current = new ZippedBookNode;
    
    for (int i = 0; i < ARRAY_LEN; i++)
        
    {
        
        if (lookupTable[i] != NULL){
            
            current = lookupTable[i];
            
            cout <<"title"<<endl;
            
            while(current -> next != NULL)
                
            {
                
                current = current -> next;
                
                cout<<"title"<<endl;
                
            }
            
        }
        
    }
    
}

























