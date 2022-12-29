//
//  main.cpp
//  matrix-mult

#include <iostream>
#include <sstream>
#include "ui.h"
using namespace std;






int main(){
    UI master;

    while (1){
        master.master();
    }
}




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
