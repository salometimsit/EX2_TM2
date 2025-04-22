//Email: timsitmelosa@gmail.com
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Squaremat.hpp"
using namespace std;
using namespace square;
Squaremat initialise_test(){
    Squaremat A(2);
    A.getmat()[0][0] = 1.5;
    A.getmat()[0][1] = 2;
    A.getmat()[1][0] = 4;
    A.getmat()[1][1] = 5;
    return A;
}

TEST_CASE("test operator: = "){
    Squaremat B(2);
    B=initialise_test();
    CHECK(B.getmat()[0][0] == 1.5);
    CHECK(B.getmat()[0][1] == 2);
    CHECK(B.getmat()[1][0] == 4);
    CHECK(B.getmat()[1][1] == 5);
}
TEST_CASE("test operators + and +=:"){
    Squaremat B(2);
    B.getmat()[0][0] = 1;
    B.getmat()[0][1] = 2;
    B.getmat()[1][0] = 3;
    B.getmat()[1][1] = 5;
    B=B+initialise_test();
    CHECK(B.getmat()[0][0] == 2.5);
    CHECK(B.getmat()[0][1] == 4);
    CHECK(B.getmat()[1][0] == 7);
    CHECK(B.getmat()[1][1] == 10);
    Squaremat C(3);
    CHECK_THROWS_AS(initialise_test() + C, std::invalid_argument);
    B+=initialise_test();
    CHECK(B.getmat()[0][0] == 4);
    CHECK(B.getmat()[0][1] == 6);
    CHECK(B.getmat()[1][0] == 11);
    CHECK(B.getmat()[1][1] == 15);
}
TEST_CASE("test operators - and -=:"){
    Squaremat B(2);
    B.getmat()[0][0] = 1;
    B.getmat()[0][1] = 2;
    B.getmat()[1][0] = 3;
    B.getmat()[1][1] = 5;
    B=B-initialise_test();
    CHECK(B.getmat()[0][0] == -0.5);
    CHECK(B.getmat()[0][1] == 0);
    CHECK(B.getmat()[1][0] == -1);
    CHECK(B.getmat()[1][1] == 0);
    Squaremat C(3);
    CHECK_THROWS_AS(initialise_test() - C, std::invalid_argument);
    B-=initialise_test();
    CHECK(B.getmat()[0][0] == -2);
    CHECK(B.getmat()[0][1] == -2);
    CHECK(B.getmat()[1][0] == -5);
    CHECK(B.getmat()[1][1] == -5);
}
TEST_CASE("test operators % and %=:"){
    Squaremat B(2);
    B.getmat()[0][0] = 1;
    B.getmat()[0][1] = 2;
    B.getmat()[1][0] = 3;
    B.getmat()[1][1] = 5;
    B=B-initialise_test();
    CHECK(B.getmat()[0][0] == -0.5);
    CHECK(B.getmat()[0][1] == 0);
    CHECK(B.getmat()[1][0] == -1);
    CHECK(B.getmat()[1][1] == 0);
    Squaremat C(3);
    CHECK_THROWS_AS(initialise_test() - C, std::invalid_argument);
    B-=initialise_test();
    CHECK(B.getmat()[0][0] == -2);
    CHECK(B.getmat()[0][1] == -2);
    CHECK(B.getmat()[1][0] == -5);
    CHECK(B.getmat()[1][1] == -5);
}