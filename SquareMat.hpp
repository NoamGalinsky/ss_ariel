/*    noamgal46@gmail.com    */


#pragma once
#include <stdexcept>
#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;

namespace matrix{

    class SquareMat{
    private:
        double** matrix;
        int size; 
    public:
        SquareMat();
        SquareMat(int size);
        SquareMat(const SquareMat& other);
        ~SquareMat();
        void helper(double* arr);
        double* operator[] (int index)const;
        bool operator== (const SquareMat& other)const;
        bool operator!= (const SquareMat& other)const;
        SquareMat operator+ (const SquareMat& other)const;
        SquareMat operator- (const SquareMat& other)const;
        SquareMat& operator= (const SquareMat& other);
        SquareMat operator% (const SquareMat& other)const;
        SquareMat operator% (int modulu)const;
        SquareMat operator* (const SquareMat& other)const;
        SquareMat operator- ()const;
        friend ostream& operator<<(ostream& os, const SquareMat& mat);
        SquareMat operator* (double scalar)const;
        SquareMat operator/ (double scalar)const;
        friend SquareMat operator* (double scalar, const SquareMat& other);
        SquareMat& operator++ ();
        SquareMat operator++ (int);
        SquareMat& operator-- ();
        SquareMat operator-- (int);
        bool operator> (const SquareMat& other)const;
        bool operator< (const SquareMat& other)const;
        bool operator<= (const SquareMat& other)const;
        bool operator>= (const SquareMat& other)const;
        SquareMat& operator+= (const SquareMat& other);
        SquareMat& operator-= (const SquareMat& other);
        SquareMat& operator/= (double scalar);
        SquareMat& operator*= (const SquareMat& other);
        SquareMat& operator*= (double scalar);
        SquareMat operator~ ()const;
        double operator! ()const;
        SquareMat operator^ (int num)const;
        bool equal(const SquareMat& other)const;
        SquareMat& operator%= (const SquareMat& other);
        SquareMat& operator%= (int modulu);
    };
}

