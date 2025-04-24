#include "Squaremat.hpp"
using namespace square;
using namespace std;
void displayMenu() {
    cout << "\n========== Matrix Calculator ==========\n";
    cout << "1. Addition \n";
    cout << "2. Subtraction \n";
    cout << "3. Matrix Multiplication \n";
    cout << "4. Scalar Multiplication\n";
    cout << "5. Matrix Division \n";
    cout << "6. Scalar Division\n";
    cout << "7. Modulo \n";
    cout << "8. Transpose \n";
    cout << "9. Determinant\n";
    cout << "10. Matrix Power \n";
    cout << "11. Increment (++)\n";
    cout << "12. Decrement (--)\n";
    cout << "13. unariminus (-)\n";
    cout << "========================================\n";
    cout << "Enter your choice: ";
}
int main() {
    Squaremat A(2);
    A.getmat()[0][0] = 3;
    A.getmat()[0][1] = 2.32;
    A.getmat()[1][0] = 4.5;
    A.getmat()[1][1] = 12;
    Squaremat B(2);
    B.getmat()[0][0] = 1;
    B.getmat()[0][1] = 2.5;
    B.getmat()[1][0] = 10;
    B.getmat()[1][1] = 4;
    Squaremat C(3);
    displayMenu();
    int x;
    cin>> x;
    cout<<"Matrix A:"<<endl<<A<<endl;;
    cout<<"Matrix B:"<<endl<<B<<endl;
    switch (x) {
        case 1: {     
            Squaremat result = A + B;
            cout << "A+B:" <<endl<< result << endl;
            break;
        }
        case 2: { 
            Squaremat result = A - B;
            cout << "A-B:" <<endl<<result << endl;
            break;
        }
        case 3: {
            Squaremat result = A * B;
            cout << "A*B:" <<endl<< result << endl;
            break;
        }
        case 4: { 
            double scalar = 3;
            Squaremat result = A * scalar;
            cout << "Result A * 3 " <<endl<< result << endl;
            break;
        }
        case 5: { 
            Squaremat result = A / B;
            cout << "\nResult (A / B):\n" << endl<<result << endl;
            break;
        }
        case 6: { 
            double scalar= 3;        
            Squaremat result = A / scalar;
            cout << "\nResult A / 3" << endl<<result << endl;
            break;
        }
        case 7: { 
            double x= 2;
            Squaremat result = A %2;
            cout << "\nResult A %2" << endl<<result << endl;
            break;
            
        }
        case 8: { 
            Squaremat result = ~A;
            cout << "\nTranspose (~A):\n" <<endl<< result << endl;
            break;
        }
        case 9: { 
            double det = !A;
            cout << "\nDeterminant (!A): " << endl<<det << endl;
            break;
        }
        case 10: { 
            int power=2;
            Squaremat result = A ^ power;
            cout << "\nResult (A^" << power << ")" << endl<<result << endl;
            break;
        }
        case 11: { 
            Squaremat result = A++;
            cout << "\nResult A++" <<endl<< result << endl;
            break;
       
        }
        case 12: { 
            Squaremat result = A--;
            cout << "\nResult A--" << endl<<result << endl;
            break;
        }
        case 13: { 
            Squaremat result = -A;
            cout << "\nResult (-A):\n" << endl<<result << endl;
            break;
        }
        default:
            cout << "Invalid choice. Please enter a number between 0 and 13.\n";
    
    }


  
}