//Email: timsitmelosa@gmail.com
#ifndef SQUAREMAT_HPP
#define SQUAREMAT_HPP
#include <iostream>

#include <stdexcept>  
namespace square{
    class Squaremat{
        private: 
            int size;
            double **mat;
        
        public: 
            double **getmat()const;
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
            Squaremat& operator%=(const Squaremat& other);
            Squaremat operator%(int n)const;
            Squaremat& operator%=(int n);
            Squaremat& operator++();
            Squaremat operator++(int);
            //Squaremat& operator++()const;
            Squaremat& operator--();
            Squaremat operator--(int);
            Squaremat operator/(double n)const;
            Squaremat& operator/=(const Squaremat& other);
            Squaremat operator/(const Squaremat& other) const;
            Squaremat inversematrix()const;
            bool operator==(const Squaremat& other)const;
            bool operator!=(const Squaremat& other)const;
            bool operator<(const Squaremat& other)const;
            bool operator<=(const Squaremat& other)const;
            bool operator>(const Squaremat& other)const;
            bool operator>=(const Squaremat& other)const;
            Squaremat operator*(double n)const;
            Squaremat& operator*=(double n);
            Squaremat operator~()const;
            Squaremat operator-() const;
            Squaremat operator*(const Squaremat& other)const;
            Squaremat& operator*=(const Squaremat& other) ;
            Squaremat operator^(int n)const;
            double* operator[](int x);
            const double* operator[](int x) const;
            Squaremat deletee(const Squaremat& m,int row,int col)const;
            double operator!()const;
            friend std::ostream& operator<<(std::ostream& os, const Squaremat& mat);
            //void swap(int*p,int*q);
    };
}

#endif