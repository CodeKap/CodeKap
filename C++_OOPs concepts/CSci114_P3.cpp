// Name: Kapil Rajesh Dharao 
// Std ID: 300709956          // Programming Assisngment 3
// I am running this file in MAC Environment

// Command to run in Terminal : g++ CSci114_P3.cpp -o P4
// Command to run in Terminal : ./P4 4 5 6

#include<stdio.h> 
#include<pthread.h> 
#include<unistd.h> 
#include<stdlib.h> 
#include<iostream>
#include<fstream>
#include<string.h>

using namespace std;
int i,j,k;

void *mult(void* arg)                                               // Each thread will compute for each value in Matrix C
{ 
    int *data = (int *)arg; 
    int k = 0, i = 0; 
      
    int x = data[0]; 
    for (i = 1; i <= x; i++) 
           k += data[i]*data[i+x]; 
      
    int *p = (int*)malloc(sizeof(int)); 
         *p = k; 
      
    pthread_exit(p);                                                //Used to terminate a thread and the return value is passed as a pointer 

} 

int main(int argc, char* argv[])
{   
    int r1;
    int c1;
    int r2;
    int c2;

//  Will take 4 elements as an argument    for example : ./P4 4 5 6                                      
    if(argc == 4)                               
        {

        for(int i = 0; i < argc; i++){
            r1 = atoi(argv[1]);
            c1 = atoi(argv[2]);
            r2 = c1;
            c2 = atoi(argv[3]);

        }
        cout << "Row1 of MatrixA is = " << r1 << endl;
        cout << "Col1 of MatrixA and Row2 of MatrixB is = " << c1 << endl;
        cout << "Col2 of MatrixB is = " << c2 << endl;

    
    }

    int myArray[r1][c1];

    //Opening the file
    ifstream inputfile("A.txt");
    
    if (!inputfile.is_open()) 
    cout<<"Error opening file" ;                                           // If file not open it will give error

    //Defining the loop for getting input from the file
    
    for (int i = 0; i < r1; i++)                                          //Outer loop for rows
    {
        for (int j = 0; j < c1; j++)                                      //inner loop for columns
        {
          inputfile >> myArray[i][j];                                     //Take input from file and put into myArray
        }
    }
    cout << "Matrix A is: " << endl;
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c1; j++)
        {
            cout << myArray[i][j] << " ";
        }
        cout<<endl;
        inputfile.close();                                                 // Closing a file
    }

    int myArray1[r2][c2];

    //Opening the file
    ifstream inputfile1("B.txt");
    
    if (!inputfile1.is_open()) 
    cout<<"Error opening file" ;                                        // If file not open it will give error

    //Defining the loop for getting input from the file
    for (int i = 0; i < r2; i++)                                        //Outer loop for rows
    {
        for (int j = 0; j < c2; j++)                                    //inner loop for columns
        {
          inputfile1 >> myArray1[i][j];                                 //Take input from file and put into myArray1
        }
    }
    cout << "Matrix B is: " << endl;
    for (int i = 0; i < r2; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            cout << myArray1[i][j] << " ";
        }
        cout<<endl;
        inputfile1.close();
    }

    
//  MAX is the Maximum number of Rows or Columns a Matrix C can have
    int MAX = r1*c2;

//  Declaring array of threads of size r1*c2 (one thread to compute each value)         
    pthread_t *threads; 
    threads = (pthread_t*)malloc(MAX*sizeof(pthread_t)); 
      
    int count = 0; 
    int* data = NULL; 
    for (i = 0; i < r1; i++) 
        for (j = 0; j < c2; j++) 
               { 
                 
            //storing row and column elements in data  
            data = (int *)malloc((20)*sizeof(int)); 
            data[0] = c1; 
      
            for (k = 0; k < c1; k++) 
                data[k+1] = myArray[i][k]; 
      
            for (k = 0; k < r2; k++) 
                data[k+c1+1] = myArray1[k][j]; 
               
                //creating threads 
                pthread_create(&threads[count++], NULL, mult, (void*)(data)); 
                  
                    } 
cout << endl;                    
cout << "Matrix A is of row " << r1 << " and column " << c1 << endl; 
cout << "Matrix B is of row " << r2 << " and column " << c2 << endl; 
cout << "Therefore Matrix C is of row " << r1 << " and column " << c2 << endl;
cout << endl; 

//  It would print the final Matrix C
    for (i = 0; i < MAX; i++)  
    { 
      void *k; 
        
      //Joining all threads and collecting return value  
      pthread_join(threads[i], &k); 
             
            
        int *p = (int *)k; 
        cout << *p << "  "; 
        if ((i + 1) % c2 == 0) 
        cout << "\n"; 
    } 
  return 0;
}