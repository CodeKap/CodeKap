/* Name : Kapil Rajesh Dharao
cmds to run in terminal:
g++ CSci114_P2.cpp 
patron@MacBook-Pro Downloads % mv (filename).pdf data.in
patron@MacBook-Pro Downloads % mv data.in data.out
patron@MacBook-Pro Downloads % mv data.out (new_filename).pdf
*/


#include <iostream>
#include <unistd.h>                                         /* Symbolic Constants */
#include <sys/types.h>                                      /* Primitive System Data Types */
#include <fstream>                                          //Include file stream

using namespace std;                                        

int main()
{ 
  int A_to_B[2];                                            // [2] declared for read and write operation in pipe
  bool isDone = true;
  
  ifstream readfile;

  
  readfile.open("data.in", ios::in | ios::binary);          
  pipe(A_to_B);                                             // Pipe A_to_B is being declared
  if(fork() == 0)                                           // Parent process 
  {  readfile.close();
     close(A_to_B[0]);                                      // Close the read operation from pipe
     ofstream outfile;
     outfile.open("data.out", ios::out | ios::binary);
     char c;
     while(true)                                            // Loop runs till everything is copied 
       {
          sleep(1);
          read(A_to_B[0], (void *)&c, sizeof(c));
         
          if(isDone)
          {break;
          outfile.write((char*)&c, sizeof(c));
            }
        else {
          char c;
          while (!readfile.eof())
            readfile.read((char*)&c, sizeof(c));
            write(A_to_B[1], (void *)&c, sizeof(c));        // write operation in pipe
            sleep(1);
          }
       }
  close(A_to_B[1]);                                         // close the write pipe 
  readfile.close();
  outfile.close();
  cout<<"File is copied to the destination.";               // File is copied in destination
    return 0;
}
}