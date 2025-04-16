#ifndef SQUAREMAT_HPP
#define SQUAREMAT_HPP
#include <iostream>

#include <stdexcept>  
namespace square{
    class Squaremat{
        private: 
            int size;
            int **mat;
        
        public: 
            int **getmat()const;
            int getsize()const;
            Squaremat(int s);
            Squaremat(const Squaremat& other);
            ~Squaremat();
            Squaremat& operator=(const Squaremat& other);
            Squaremat operator+(const Squaremat& other)const;
            Squaremat& operator+=(const Squaremat& other);
            Squaremat operator-(const Squaremat& other)const;
            Squaremat& operator-=(const Squaremat& other);
            Squaremat operator%(const Squaremat& other)const;
            Squaremat operator++()const;
            Squaremat operator--()const;
            Squaremat operator/(int n)const;
            //Squaremat& operator/=(const Squaremat& other);
            bool operator==(const Squaremat& other)const;
            bool operator!=(const Squaremat& other)const;
            bool operator<(const Squaremat& other)const;
            bool operator<=(const Squaremat& other)const;
            bool operator>(const Squaremat& other)const;
            bool operator>=(const Squaremat& other)const;
            Squaremat operator%(int n)const;
            Squaremat operator*(int n)const;
            Squaremat& operator*=(const Squaremat& other) ;
            Squaremat operator~()const;
            Squaremat operator-() const;
            Squaremat operator*(const Squaremat& other)const;
            Squaremat operator^(int n)const;
            int* operator[](int x);
            const int* operator[](int x) const;
            int operator!()const;
            Squaremat deletee(const Squaremat& m,int row,int col)const;
            Squaremat operator/=(int n) const;
            friend std::ostream& operator<<(std::ostream& os, const Squaremat& mat);
            //void swap(int*p,int*q);
    };
}

#endif