// Name : Kapil Rajesh Dharao
// Std id: 300709956
// In this program we have included header file fstream, where we take source file called data.in of any
// format using ifstream and also take the destination file called data.out of same type as source file using  ofstream
// In this program bit by bit is copied on to the destination file and then we close the source and destination
// file and print output statement

#include <iostream>
#include <fstream>                                              //Include file stream
using namespace std;

int main() {

    ifstream source("data.jpg", ios::binary);                      // Input file stream source using binary bits
    ofstream dest("data2.jpg", ios::binary);                        // Output file stream destination using binary bits


    istreambuf_iterator<char> begin_source(source);             // Input file stream buffer begin
    istreambuf_iterator<char> end_source;                       // Input file stream buffer end
    ostreambuf_iterator<char> begin_dest(dest);                 // Output file stream buffer begin
    copy(begin_source, end_source, begin_dest);                 // Copying from input file stream buffer to output file stream buffer

    source.close();                                             // Closing the source
    dest.close();                                               // Closing the destination
    cout<<"File is copied to the destination.";
    return 0;
}
