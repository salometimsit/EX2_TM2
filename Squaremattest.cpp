//Email: timsitmelosa@gmail.com
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Squaremat.hpp"
using namespace std;
using namespace square;
Squaremat initialise_testA(){
    Squaremat A(2);
    A.getmat()[0][0] = 1.5;
    A.getmat()[0][1] = 2;
    A.getmat()[1][0] = 4;
    A.getmat()[1][1] = 5;
    return A;
}
Squaremat initialise_testB(){
    Squaremat B(2);
    B.getmat()[0][0] = 1;
    B.getmat()[0][1] = 2;
    B.getmat()[1][0] = 3;
    B.getmat()[1][1] = 5;
    return B;

}

TEST_CASE("test operator: = "){
    Squaremat B(2);
    B=initialise_testA();
    CHECK(B.getmat()[0][0] == 1.5);
    CHECK(B.getmat()[0][1] == 2);
    CHECK(B.getmat()[1][0] == 4);
    CHECK(B.getmat()[1][1] == 5);
}
TEST_CASE("test operators +:"){
    Squaremat B=initialise_testB();
    B=B+initialise_testA();
    CHECK(B.getmat()[0][0] == 2.5);
    CHECK(B.getmat()[0][1] == 4);
    CHECK(B.getmat()[1][0] == 7);
    CHECK(B.getmat()[1][1] == 10);
    Squaremat C(3);
    CHECK_THROWS_AS(initialise_testA() + C, std::invalid_argument);
    
}
TEST_CASE("test operator  +=:"){
    Squaremat B=initialise_testB();
    B+=initialise_testA();
    CHECK(B.getmat()[0][0] == 2.5);
    CHECK(B.getmat()[0][1] == 4);
    CHECK(B.getmat()[1][0] == 7);
    CHECK(B.getmat()[1][1] == 10);
}
TEST_CASE("test operator -:"){
    Squaremat B=initialise_testB();
    B=B-initialise_testA();
    CHECK(B.getmat()[0][0] == -0.5);
    CHECK(B.getmat()[0][1] == 0);
    CHECK(B.getmat()[1][0] == -1);
    CHECK(B.getmat()[1][1] == 0);
    Squaremat C(3);
    CHECK_THROWS_AS(initialise_testA() - C, std::invalid_argument);
}
TEST_CASE("test operator  -=:"){
    Squaremat B=initialise_testB();
    B-=initialise_testA();
    CHECK(B.getmat()[0][0] == -0.5);
    CHECK(B.getmat()[0][1] == 0);
    CHECK(B.getmat()[1][0] == -1);
    CHECK(B.getmat()[1][1] == 0);
}
TEST_CASE("test operators % between matrixs:"){
    Squaremat B=initialise_testB();
    B=B%initialise_testA();
    CHECK(B.getmat()[0][0] == 1);
    CHECK(B.getmat()[0][1] == 0);
    CHECK(B.getmat()[1][0] == 3);
    CHECK(B.getmat()[1][1] == 0);
    Squaremat C(3);
    CHECK_THROWS_AS(initialise_testA() % C, std::invalid_argument);
    
}
TEST_CASE("test operators %= between matrixs:"){
    Squaremat B=initialise_testB();
    B%=initialise_testA();
    CHECK(B.getmat()[0][0] == 1);
    CHECK(B.getmat()[0][1] == 0);
    CHECK(B.getmat()[1][0] == 3);
    CHECK(B.getmat()[1][1] == 0);
    Squaremat C(3);
    CHECK_THROWS_AS(initialise_testA() % C, std::invalid_argument);

}
TEST_CASE("test operators %  between matrix and a number:"){
    int x= 2;
    Squaremat A = initialise_testA();
    A=A%x;
    CHECK(A.getmat()[0][0] == 1.5);
    CHECK(A.getmat()[0][1] == 0);
    CHECK(A.getmat()[1][0] == 0);
    CHECK(A.getmat()[1][1] == 1);
    x=0;
    CHECK_THROWS_AS(initialise_testA() % x, std::invalid_argument);
}
TEST_CASE("test operators %=  between matrix and a number:"){
    int x= 2;
    Squaremat A = initialise_testA();
    A%=x;
    CHECK(A.getmat()[0][0] == 1.5);
    CHECK(A.getmat()[0][1] == 0);
    CHECK(A.getmat()[1][0] == 0);
    CHECK(A.getmat()[1][1] == 1);
    x=0;
    CHECK_THROWS_AS(initialise_testA() % x, std::invalid_argument);
}
TEST_CASE("pre increment ++:"){
    Squaremat A = initialise_testA();
    Squaremat& result = ++A;
    CHECK(A.getmat()[0][0] == 2.5);
    CHECK(A.getmat()[0][1] == 3);
    CHECK(A.getmat()[1][0] == 5);
    CHECK(A.getmat()[1][1] == 6);
    CHECK(&result == &A);
}
TEST_CASE("post increment ++:"){
    Squaremat A = initialise_testA();
    Squaremat result = A++;
    CHECK(A.getmat()[0][0] == 2.5);
    CHECK(A.getmat()[0][1] == 3);
    CHECK(A.getmat()[1][0] == 5);
    CHECK(A.getmat()[1][1] == 6);
    CHECK(result.getmat()[0][0] == 1.5);
    CHECK(result.getmat()[0][1] == 2);
    CHECK(result.getmat()[1][0] == 4);
    CHECK(result.getmat()[1][1] == 5);
}
TEST_CASE("pre increment --:"){
    Squaremat A = initialise_testA();
    Squaremat& result = --A;
    CHECK(A.getmat()[0][0] == 0.5);
    CHECK(A.getmat()[0][1] == 1);
    CHECK(A.getmat()[1][0] == 3);
    CHECK(A.getmat()[1][1] == 4);
    CHECK(&result == &A);
}
TEST_CASE("post increment --:"){
    Squaremat A = initialise_testA();
    Squaremat result = A--;
    CHECK(A.getmat()[0][0] == 0.5);
    CHECK(A.getmat()[0][1] == 1);
    CHECK(A.getmat()[1][0] == 3);
    CHECK(A.getmat()[1][1] == 4);
    CHECK(result.getmat()[0][0] == 1.5);
    CHECK(result.getmat()[0][1] == 2);
    CHECK(result.getmat()[1][0] == 4);
    CHECK(result.getmat()[1][1] == 5);
}
TEST_CASE("test division on a number"){
    int x=2;
    Squaremat A = initialise_testA();
    A=A/x;
    CHECK(A.getmat()[0][0] == 0.75);
    CHECK(A.getmat()[0][1] == 1);
    CHECK(A.getmat()[1][0] == 2);
    CHECK(A.getmat()[1][1] == 2.5);
}
TEST_CASE("test division between 2 matrixs:"){
    Squaremat A = initialise_testA();
    Squaremat B=initialise_testB();
    A=A/B;
    CHECK(A.getmat()[0][0] == -1.5);
    CHECK(A.getmat()[0][1] == 1);
    CHECK(A.getmat()[1][0] == -5);
    CHECK(A.getmat()[1][1] == 3);

}
TEST_CASE("sub matrix"){
    
    Squaremat A = initialise_testA();
    Squaremat C(2);
    C.getmat()[0][0] = 1;
    C.getmat()[0][1] = 1;
    C.getmat()[1][0] = 1;
    C.getmat()[1][1] = 2;
    Squaremat inv= C.inversematrix();
    CHECK(inv.getmat()[0][0] == 2);
    CHECK(inv.getmat()[0][1] ==  -1 );
    CHECK(inv.getmat()[1][0] ==-1);
    CHECK(inv.getmat()[1][1] == 1);
}
TEST_CASE("test operators *"){
    Squaremat B=initialise_testB();
    B=B*2;
    CHECK(B.getmat()[0][0] == 2);
    CHECK(B.getmat()[0][1] == 4);
    CHECK(B.getmat()[1][0] == 6);
    CHECK(B.getmat()[1][1] == 10);
}
TEST_CASE("test operators *="){
    Squaremat B=initialise_testB();
    B*=2;
    CHECK(B.getmat()[0][0] == 2);
    CHECK(B.getmat()[0][1] == 4);
    CHECK(B.getmat()[1][0] == 6);
    CHECK(B.getmat()[1][1] == 10);
}
TEST_CASE("test operators * on 2 matrixs"){
    Squaremat B=initialise_testB();
    Squaremat A=initialise_testA();
    B=B*A;
    CHECK(B.getmat()[0][0] == 9.5);
    CHECK(B.getmat()[0][1] == 12);
    CHECK(B.getmat()[1][0] ==24.5);
    CHECK(B.getmat()[1][1] == 31);
}
TEST_CASE("test operators *= on 2 matrixs"){
    Squaremat B=initialise_testB();
    Squaremat A=initialise_testA();
    B*=A;
    CHECK(B.getmat()[0][0] == 9.5);
    CHECK(B.getmat()[0][1] == 12);
    CHECK(B.getmat()[1][0] ==24.5);
    CHECK(B.getmat()[1][1] == 31);
}
TEST_CASE("test =="){
    Squaremat B=initialise_testA();
    Squaremat C=initialise_testB();
    Squaremat A=initialise_testA();
    CHECK((B==A)==true);
    CHECK((C==A)==false);
    CHECK((C==B)==false);
}
TEST_CASE("test !="){
    Squaremat B=initialise_testA();
    Squaremat C=initialise_testB();
    Squaremat A=initialise_testA();
    CHECK((B!=A)==false);
    CHECK((C!=A)==true);
    CHECK((C!=B)==true);
}
TEST_CASE("test <"){
    Squaremat B=initialise_testA();
    Squaremat C=initialise_testB();
    Squaremat A=initialise_testA();
    CHECK((B<A)==false);
    CHECK((C<A)==true);
    CHECK((C<B)==true);
}
TEST_CASE("test <="){
    Squaremat B=initialise_testA();
    Squaremat C=initialise_testB();
    Squaremat A=initialise_testA();
    CHECK((B<=A)==true);
    CHECK((A<=C)==false);
    CHECK((C<=B)==true);
}
TEST_CASE("test >"){
    Squaremat B=initialise_testA();
    Squaremat C=initialise_testB();
    Squaremat A=initialise_testA();
    CHECK((B>A)==false);
    CHECK((C>A)==false);
    CHECK((C>B)==false);
}
TEST_CASE("test <="){
    Squaremat B=initialise_testA();
    Squaremat C=initialise_testB();
    Squaremat A=initialise_testA();
    CHECK((B>=A)==true);
    CHECK((A>=C)==true);
    CHECK((C>=B)==false);
}
TEST_CASE("~"){
    Squaremat A=initialise_testA();
    A=~A;
    CHECK(A.getmat()[0][0] == 1.5);
    CHECK(A.getmat()[0][1] == 4);
    CHECK(A.getmat()[1][0] == 2);
    CHECK(A.getmat()[1][1] == 5);
}
TEST_CASE("^"){
    Squaremat A=initialise_testA();
    int x= 2; 
    A=A^x;
    CHECK(A.getmat()[0][0] == 10.25);
    CHECK(A.getmat()[0][1] == 13);
    CHECK(A.getmat()[1][0] == 26);
    CHECK(A.getmat()[1][1] == 33);
}
TEST_CASE("[] const"){
    Squaremat A=initialise_testA();
    double* row0 = A[0];
    double* row1 = A[1];
    CHECK(row0[0] == 1.5);
    CHECK(row0[1] == 2);
    CHECK(row1[0] == 4);
    CHECK(row1[1] == 5);
}
TEST_CASE("[] not const"){
    Squaremat A=initialise_testA();
    A[0][0] = 10.0;
    A[0][1] = 20.0;
    A[1][0] = 30.0;
    A[1][1] = 40.0;
    CHECK(A[0][0] == 10);
    CHECK(A[0][1] == 20);
    CHECK(A[1][0] == 30);
    CHECK(A[1][1] == 40);
 }
 TEST_CASE(" det !"){
    Squaremat A=initialise_testA();
    double det = (!A);
    CHECK(det==-0.5);
    Squaremat s(1);
    s.getmat()[0][0]=2;
    double test=!s;
    CHECK(test==2);
 }

