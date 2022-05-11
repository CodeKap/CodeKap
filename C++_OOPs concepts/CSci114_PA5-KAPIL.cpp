// Name : Kapil R Dharao
// Class: CSCI 114 Programming Assignment 5
// Commands to run the file (In MAC environment):
// Cmd to compile -  g++ p5.cpp
// Cmd to execute -  ./a.out


#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;
 
int g = 0, k = 0;
                                           
struct free {                                                           // Structure for 1024 free list
    int tag;
    int size = 1024;
    struct free* next;
}* free_head = NULL, *prev_free = NULL;
 

struct alloc {                                                          // Structure for allocated list
    int block_id;
    int tag;
    int size;
    struct alloc* next;
}* alloc_head = NULL, *prev_alloc = NULL;
 

void create_free(int c)                                             // Function to create free list which prints free blocks with 1024 size
{
    struct free* p = (struct free*)
        malloc(sizeof(struct free));
    p->size = c;
    p->tag = g;
    p->next = NULL;
    if (free_head == NULL)
        free_head = p;
    else
        prev_free->next = p;
    prev_free = p;
    g++;
}
 


void print_free()                                                   // Function to print free list which prints free blocks with 1024 size
{   
    ofstream file;
    file.open("final_size.txt");
    if (file.is_open()) {
        cout <<endl<< "final_size.txt is open now \n";
    }
    
    
    
    struct free* p = free_head;
    while (p != NULL) {
             file << p->size << "\n";
        p = p->next;
    }
    file.close();
}
 
void print_alloc()                                                  // Function to print allocated list
{
    struct alloc* p = alloc_head;
    while (p != NULL) {
       cout<<p->size<<endl;
        p = p->next;
    }
}
 

void create_alloc(int c,int b)                                      // Function to allocate memory to blocks as per Best fit algorithm
{
    struct alloc* q = (struct alloc*)                               // create node for process of given size
        malloc(sizeof(struct alloc));
    q->size = c;
    q->tag = k = b;
    q->next = NULL;
    struct free* p = free_head;
 
    
    
    struct free* r = (struct free*)                                 // Temporary node r of free type to find the best and
        malloc(sizeof(struct free));                                // most suitable free node to allocate space
    r->size = 99999;
 
    
    while (p != NULL) {                                             // Loop to find best choice
        if (q->size <= p->size) {
            if (p->size < r->size)
                r = p;
        }
        p = p->next;
    }
 
    
    
    if (r->size != 99999) {                                         // Node found to allocate space from
        q->block_id = r->tag;                                       // Adding node to allocated list
        r->size -= q->size;
        if (alloc_head == NULL)
            alloc_head = q;
        else {
            prev_alloc = alloc_head;
            while (prev_alloc->next != NULL)
                prev_alloc = prev_alloc->next;
            prev_alloc->next = q;
            
        }
        k++;
    }
 
    
    else                                                            // Node with size not found
        cout << "Block with size "<< c << " can't be allocated\n";

    cout<<c<<" bytes have been allocated at block "<< q->block_id <<" for request "<<b<<endl;
}
 

void delete_alloc(int t)                                            // Function to delete node from allocated list
{
    
    struct alloc *p = alloc_head, *q = NULL;                        // Structure to delete function for linked list
 
    while (p != NULL)                                               // First, find the node according to given tag id
    
    {
        if (p->tag == t)
            break;
        q = p;
        p = p->next;
    }
    if (p == NULL)
        cout << "Tag ID doesn't exist\n";
    else if (p == alloc_head)
        alloc_head = alloc_head->next;
    else
        q->next = p->next;
    struct free* temp = free_head;
    while (temp != NULL) {
        if (temp->tag == p->block_id) {
            temp->size += p->size;
            break;
        }
        temp = temp->next;
    }
cout<<" block "<<p->block_id;
}
 

int main()
{
    int blockSize[1024];
    
    for (int i = 0; i < 1024 ; i++){
        blockSize[i]=1024;
    }
    
    int m = sizeof(blockSize)
            / sizeof(blockSize[0]);
    
            
    for (int i = 0; i < m; i++)
        create_free(blockSize[i]);
 

            
    ifstream f1;
    f1.open("requests-1.txt"); 
    string x[1024];
    string z[1024];
    int i=0;
    while(!f1.eof()) {
        getline(f1,x[i]);
        z[i]=x[i];
        
        i++;
    }
    string start;
    int block,bytes;
    for(int p=0;p<i;p++){
        stringstream iss(z[p]);
        iss >> start;

        if(start=="A"){
            iss>>block;
            iss>>bytes;
            create_alloc(bytes,block);
        }
        else if(start=="R"){
            cout<<"Returned back to ";
            iss>>block;
		 delete_alloc(block);
            cout<<" for request "<<block<<endl;
            
        }
    }
        
    print_free();
 

}