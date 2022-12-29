//
//  main.cpp
//  matrix-mult

//#include <iostream>
//#include <sstream>
#include "ui.h"






int main(){
    UI master;

    master.master();

}




//#include <iostream>
//int main(){
//    bool hello = 0;
//    bool bye = 1;
//    if (hello)
//        std::cout << "hello";
//    else if (bye)
//        std::cout << "bye";
//}

//
//#include <iostream>
//#include <stdio.h>
//#include <sstream>
//#include <vector>
//using namespace std;

//int main(){
//
//    vector<vector<double>> A;
//    vector<double> row1 = {200.3, 100.7, 400.89};
//    vector<double> row2 = {-323.34, 416.85, 123.345};
//    vector<double> row3 = {43.3, 5, 6};
//    A.push_back(std::move(row1));
//    A.push_back(std::move(row2));
//    A.push_back(std::move(row3));
//
//    size_t rows = A.size();
//    size_t cols = A[0].size();
//    for (int i = 0 ; i < rows ; i ++){
//        for (int j = 0 ; j < cols ; j ++){
//            printf("%-15.3f ", A[i][j]);      // the most beautiful output
//
//            // X (total length it can best format) = Y (decimal precision) + . <- guaranteed to exist
//            //                                      + # of digits or -     <- variable
//            // so 7.3f can rep 7 total chars, 4 of which are guaranteed to exist
//            // %X.Yf
//        }
//        cout << std::endl;
//    }
//
////    printf ("Right align: %7d\n", 5);
////    printf ("Left align : %-7d\n", 5);
//
//}

//int main(){
//    double i = 0.3;
//    std::cout << i;
//}











//int main(){
//    vector<vector<int>> matrix;
//    if (true){
//        vector<int> a = {1, 2, 3};
//        vector<int> b = {4, 5, 6};
//        cout << a.capacity() << " " << a.size() << endl;
//        matrix.push_back(std::move(a));
//        matrix.push_back(std::move(b));
//        cout << a.capacity() << " " << a.size() << endl;
//    }
//    cout << matrix[0].size() << endl;
//    cout << matrix[1].size() << endl;
//    for (int i = 0 ; i < 2; i++){
//        for (int j = 0 ; j < 3 ; j++){
//            cout << matrix[i][j] << " ";
//        }
//        cout << endl;
//    }
////    matrix.clear();
////    cout << matrix.capacity() << " " << matrix.size() << endl;  // doesn't actually clear :/
//
//    matrix = vector<vector<int>>(); // this does :)
//        cout << matrix.capacity() << " " << matrix.size() << endl;
//}

/*
 what a = std::move(b), could also use a.swap(b) instead (b doesnt' clear) -> since contents are heaps, swaps internal representations (
 moving (b) clears(b) -> b now has empty internal rep. clear() is function to do this. let's see.
 move is very fast ;) -> just leads to multi-level array, but not an issue really b/c of my algorithms
https://stackoverflow.com/questions/12613428/stl-vector-moving-all-elements-of-a-vector
*/

// vector.clear() for outer vector causes all inner references out of scope -> destructed :)
// however, the capacity maybe still be there let's test this
// allocated in memory as I expected -> liek a multi-level a rray


// ****************************
// PRINTING RAW VECTOR CONTENTS
// ****************************
//
//#include <vector>
//
//struct my_vector {
//    int *begin;
//    int *end;
//    int *end_capacity;
//};
//
//int main() {
//    union vecunion {
//        std::vector<int> stdvec;
//        my_vector           myvec;
//        ~vecunion() { /* do nothing */ }
//    } vec = { std::vector<int>() };
//    union veciterator {
//        std::vector<int>::iterator stditer;
//        int                       *myiter;
//        ~veciterator() { /* do nothing */ }
//    };
//
//    vec.stdvec.push_back(1); // Add something so we don't have an empty vector
//
//    std::cout
//      << "vec.begin          = " << vec.myvec.begin << "\n"
//      << "vec.end            = " << vec.myvec.end << "\n"
//      << "vec.end_capacity   = " << vec.myvec.end_capacity << "\n"
//      << "vec's size         = " << vec.myvec.end - vec.myvec.begin << "\n"
//      << "vec's capacity     = " << vec.myvec.end_capacity - vec.myvec.begin << "\n"
//      << "vector::begin()    = " << (veciterator { vec.stdvec.begin() }).myiter << "\n"
//      << "vector::end()      = " << (veciterator { vec.stdvec.end()   }).myiter << "\n"
//      << "vector::size()     = " << vec.stdvec.size() << "\n"
//      << "vector::capacity() = " << vec.stdvec.capacity() << "\n"
//      ;
//}

// ****************
// ESCAPE SEQUENCES
//*****************
//#include <iostream>
//#define ESC_PREV_LINE "\033[A"
//#define ESC_CLEAR_TO_END "\033[2K"    // exactly what I want
//int main(){
//    int i;
//    std::cerr << "Some input to clear: " << std::flush;
//    std:: cin >> i;
//    std::cerr << ESC_PREV_LINE ESC_CLEAR_TO_END << std::flush;
//}   // correct functionality in terminal (honestly, may be a good thing.)

//#define ESC_PREV_LINE "\e[F" // \033[A
//#define ESC_CLEAR_TO_END "\e[K" // \33[2K
//  \r for carraige return


// ***********
// EXPERIMENTS
// **********

//#include <unistd.h>
//using namespace std;
//int main(){
//    cout << "Hello, I am not flushed.";
//
//    usleep(100000000);
//
//    cout << "Hello, I am being flushed." << flush;
//}


//int main(){
//    cout << __cplusplus << endl;
//}

// testing basics of how input stream works
// sets 'int' or 'double' to 0 when conversion from buffer fails
// puts it into error state
// subsequent reads fail when in error state

//int main(){
//    int a[5] = {0};
//    int i = 0;
//    while (1){
//        cin >> a[i];
//        cout << cin.tellg() << " ";
//        i++;
//    }
//
//    while (1){
//        cout << "Input: ";
//        string s;
//        getline(cin, s);
//        istringstream buffer(s);
//        for (int i = 0 ; i < 5 ; i++)
//            buffer >> a[i];
//
//        for (int i = 0 ; i < 5 ; i++)
//            cout << a[i] << " ";
//        cout << endl;
//    }
//}
//
//

// can detect when hit EOF with buffer.eof()
// can see if EOF is next with buffer.peek() == EOF
// attempting to read EOF sets buffer.fail() -> failure to convert
// this makes buffer >> i;  unable to perform subsequent reads, use clear() to remove them

//int main(){
//
//    string input1 = "1 2 3 ";    // would not want buffer to fail in this case
//    string input2 = "1 2- 3 ";  // would want buffer to fail in this case
//    istringstream buffer(input2);
//    Entries test = 0.0;
//
//    int n = 5;  // in actual use, this will be based on the user (this is just to prevent infinite loops)
//
//    for (int i = 1; buffer.peek() != EOF && i < n; i++){
//        if (buffer.eof())
//            cout << "Encountered EOF in loop." << endl;
//        else if (buffer.peek() == EOF)
//            cout << "Next element is EOF." << endl;
//        else if (buffer >> test)
//            cout << "Encountered double." << endl;
////        else if (buffer.peek() == ' ')
////            cout << "Next element is space." << endl;
//        else
//            cout << "Encountered incorrect form." << endl;
//
//        cout << "Value of 'test' at end of loop " << i << ": " << test << endl;
//    }
//
//    if (buffer.fail()){
//        cout << "Buffer has failed." << endl;
//    }
//
//    if (buffer.eof()){
//        cout << "Encountered EOF outside of loop." << endl;
//    }
//
//}

// this works for my purposes, just lets some ugly input through (input 1, input5, input7, but is always correct and coherent

// attempting to read EOF always fails buffer -> error state (returns false) and sets fail bit
// fail() sets on conversion//read errors
// bad() sets on BUFFER errors -> no more disk storage or something really weird happened
// get to be less draconian about input :(, would probably have to iterate through if I really wanted to do some stuff with it.
//int main(){
//
//    string input0 = "1 2 3";    // Failed, EOF, 'test' retains correct value -> standard what I want
//
//    string input1 = "1 2 3-";   // Failed, EOF, 'test' set to 0 b/c conversion failed -> why is bad not set?, not what I want -> how do I check for this?
//
//    string input2 = "1 2-3";    // Failed, EOF, 'test', correct values -> weird behavior (would prefer this didn't occur)
//    string input3 = "1 2 -3 "; // Failed, EOF, correct values -> does what I want it to
//    string input4 = ".1 2---3  ";   // Failed, buffer position 4, 'test' set to 0   -> does what I want it to
//    string input5 = ".1        2       3     "; // Failed, EOF, correct values      -> does what I want
//    string input6 = ".1 2 --3 ";    // Failed, buffer position 4, 'test' set to 0 -> does what I want
//    string input7 = ".1 - 2 3";     // Failed, buffer position 2, 'test set to 0 -> does what I want
//
//    istringstream buffer(input1);
//    double test = 0;
//    while (buffer >> test){
//        cout << "In loop" << endl;
//        cout << "Value of test: " << test << endl;
//        cout << "Buffer position: " << buffer.tellg() << endl;
//    }
//    cout << "Out of loop" << endl;
//    cout << test << endl;
//
//    if (buffer.good())          // no error flags set
//        cout << "Good" << endl;
//    if (buffer.bad())           // read/write error on i/o (integrity of stream lost) -> never set?
//        cout << "Bad" << endl;
//    if (buffer.fail())          // logical error on i/o (failure to convert) -> set on EOF
//        cout << "Failed" << endl;
//    if (buffer.eof())           // EOF reached on input op
//        cout << "EOF" << endl;
//
//    // .clear() would clear stream
//
//}


 /*
  m_buffer = istringstream(input);
  Entries test = 0.0;
  
  while (m_buffer.peek() != EOF){   // cool functionality
      if (m_buffer >> test)
          cout << "Encountered correct form." << endl;
      else if (m_buffer.peek() == ' ')
          cout << "Encountered correct form." << endl;
      else
          cout << "Encountered incorrect form." << endl;
  }
  
  if (m_buffer.eof()){
      cout << "Encountered end of file" << endl;
  }
  
  */



// ************
// OLD VERSIONS
// ************

// all code has correct functionality, just refactored, or updated to better fit user interface scheme -> old code did not allow user to omit typing in rows & cols manually

//void UI::readInput(const InputType inputType, const MatrixID matrixID){
//retry:
//    string s;
//    getline(cin, s);
//    if (!isValidInput(s, inputType)){
//        cout << "Invalid input. Try again: ";
//        goto retry;
//    } else if (inputType == matrix){
//        parseInput(s, matrixID);
//    }
//    m_buffer = istringstream(s);
//}
