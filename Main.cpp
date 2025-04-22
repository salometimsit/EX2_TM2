#include "Squaremat.hpp"
using namespace square;
using namespace std;
int main() {
    
    Squaremat A(2);
    // A.getmat()[0][0] = 1;
    // A.getmat()[0][1] = 2;
    // A.getmat()[0][2] = 3;
    // A.getmat()[1][0] = 4;
    // A.getmat()[1][1] = 5;
    // A.getmat()[1][2] = 6;
    // A.getmat()[2][0] = 7;
    // A.getmat()[2][1] = 8;
    // A.getmat()[2][2] = 9;
    A.getmat()[0][0] = 1.5;
    A.getmat()[0][1] = 2;
    A.getmat()[1][0] = 4;
    A.getmat()[1][1] = 5;
    Squaremat B(2);
    B.getmat()[0][0] = 1;
    B.getmat()[0][1] = 2;
    B.getmat()[1][0] = 3;
    B.getmat()[1][1] = 5;
    Squaremat C(2);
    cout << "Matrix a:" << endl << A;
    C=A;
    cout << "Matrix C:" << endl << C;
    // bool t= (A<B);
    // cout<<t;
   // Squaremat C =A^2 ;
    //C.printmat();
    //A.printmat();
    // cout << "Matrix A before:" << endl << A;
    // ++A;
    // cout << "Matrix A after pre increment:" << endl << A;
    // A++;
    // cout << "Matrix A after post increment:" << endl << A;

  
}