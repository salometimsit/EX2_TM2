#include "Squaremat.hpp"
using namespace square;
using namespace std;
int main() {
    
    Squaremat A(2);
    A.getmat()[0][0] = 1;
    A.getmat()[0][1] = 2;
    A.getmat()[1][0] = 3;
    A.getmat()[1][1] = 4;

    Squaremat B(2);
    B.getmat()[0][0] = 1;
    B.getmat()[0][1] = 2;
    B.getmat()[1][0] = 3;
    B.getmat()[1][1] = 5;
    // bool t= (A<B);
    // cout<<t;
    Squaremat C =A^2 ;
    C.printmat();
  
}