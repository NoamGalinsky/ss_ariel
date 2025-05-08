/*    noamgal46@gmail.com    */


#include "SquareMat.hpp"

using namespace matrix;

SquareMat::SquareMat(){
    size = 1;
    matrix = new double*[size];
    matrix[0] = new double[size];
    matrix[0][0] = 0;
}
SquareMat::SquareMat(int size){
    if (size < 1){
        throw invalid_argument("invalid num of size: negative or zero size");
    }
    this->size = size;
    matrix = new double*[size];
    for (int i = 0; i < size; i++){
        matrix[i] = new double[size];
        for (int j = 0; j < size; j++){
            matrix[i][j] = 0;
        }
    }
}
SquareMat::SquareMat(const SquareMat& other){
    size = other.size;
    matrix = new double*[size];
    for (int i = 0; i < size; i++){
        matrix[i] = new double[size];
        for (int j = 0; j < size; j++){
            matrix[i][j] = other[i][j];
        }
    }
}
SquareMat::~SquareMat(){
    for(int i = 0; i < size; i++){
        delete[] matrix[i];
    }
    delete[] matrix;
}
void SquareMat::helper(double* arr){
    int index = 0;
    for (int i = 0; i < size; i++){
        for( int j = 0; j < size; j++){
            matrix[i][j] = arr[index++];
        }
    }
}

double* SquareMat::operator[] (int index)const{
    if (index < 0 || index >= size){
        throw std::out_of_range("Index out of range");
    }
    return matrix[index];
}

bool SquareMat::operator== (const SquareMat& other)const{
    double sumCurent = 0;
    double sumOther = 0;
    for (int i = 0; i < other.size; i++){
        for (int j = 0; j < other.size; j++){
            sumOther += other[i][j];
        }
    }
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            sumCurent += matrix[i][j];
        }
    }
    return sumCurent == sumOther;
}

bool SquareMat::operator!= (const SquareMat& other)const{
    return !(*this == other);
}


SquareMat& SquareMat::operator= (const SquareMat& other){
    if (size != other.size){
        for (int i = 0; i < size; i++){
            delete[] matrix[i];
        }
        delete[] matrix;
        size = other.size;
        matrix = new double*[size];
        for (int i = 0; i < size; i++){
            matrix[i] = new double[size];
        }
    }
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            matrix[i][j] = other[i][j];
        }
    }
    return *this;
}


SquareMat SquareMat::operator+ (const SquareMat& other)const{
    if (size != other.size){
        throw invalid_argument("invalid argument: the matrix is not in the same size");
    }
    SquareMat ans(size);
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            ans[i][j] = matrix[i][j] + other[i][j];
        }
    }    
    return ans;
}

SquareMat SquareMat::operator- (const SquareMat& other)const{
    if (size != other.size){
        throw invalid_argument("invalid argument: the matrix is not in the same size");
    }
    SquareMat ans(size);
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            ans[i][j] = matrix[i][j] - other[i][j];
        }
    }    
    return ans;
}
SquareMat SquareMat::operator% (const SquareMat& other)const{
    if (size != other.size){
        throw invalid_argument("invalid argument: the matrix is not in the same size");
    }
    SquareMat ans(size);
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            ans[i][j] = matrix[i][j] * other[i][j];
        }
    }    
    return ans;
}
SquareMat SquareMat::operator% (int modulu)const{
    if (modulu < 0){
        throw invalid_argument("invalid argument: modulu is negative");
    }
    SquareMat ans(size);
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            ans[i][j] = fmod(matrix[i][j], modulu);
        }
    }    
    return ans;
}
SquareMat SquareMat::operator* (const SquareMat& other)const{
    if (size != other.size){
        throw invalid_argument("invalid argument: the matrix is not in the same size");
    }
    SquareMat ans(size);
    double sum = 0;
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            for (int h = 0; h < size; h++){
                sum += matrix[i][h] * other[h][j];
            }
            ans[i][j] = sum;
            sum = 0;
        }
    }    
    return ans;
}
namespace matrix{
    ostream& operator<<(ostream& os, const SquareMat& mat) {
        for (int i = 0; i < mat.size; i++) {
            os << "[ ";
            for (int j = 0; j < mat.size; j++) {
                os << setw(7) << mat.matrix[i][j] << " ";
            }
            os << "]" <<endl;
        }
        return os;
    }

    SquareMat operator* (double scalar, const SquareMat& other){
        return other * scalar;
    }

}
bool SquareMat::operator> (const SquareMat& other)const{
    double sumCurent = 0;
    double sumOther = 0;
    for (int i = 0; i < other.size; i++){
        for (int j = 0; j < other.size; j++){
            sumOther += other[i][j];
        }
    }
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            sumCurent += matrix[i][j];
        }
    }
    return sumCurent > sumOther;
}
bool SquareMat::operator< (const SquareMat& other)const{
    return (*this != other) && !(*this > other);
}
bool SquareMat::operator<= (const SquareMat& other)const{
    return (*this == other) || (*this < other);
}
bool SquareMat::operator>= (const SquareMat& other)const{
    return (*this == other) || (*this > other);
}
SquareMat& SquareMat::operator++ (){
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            matrix[i][j]++;
        }
    }
    return *this;
}
SquareMat SquareMat::operator++ (int){
    SquareMat temp(*this);
    ++(*this);
    return temp;
}
SquareMat& SquareMat::operator-- (){
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            matrix[i][j]--;
        }
    }
    return *this;
}
SquareMat SquareMat::operator-- (int){
    SquareMat temp(*this);
    --(*this);
    return temp;
}
SquareMat SquareMat::operator- ()const{
    SquareMat temp(*this);
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            temp[i][j] = -matrix[i][j];
        }
    }
    return temp;
}
SquareMat SquareMat::operator/ (double scalar)const{
    if (scalar == 0){
        throw std::invalid_argument("division by zero");
    }
    SquareMat temp(*this);
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            temp[i][j] = matrix[i][j] / scalar;
        }
    }
    return temp;
}
SquareMat SquareMat::operator* (double scalar)const{
    SquareMat temp(*this);
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            temp[i][j] = matrix[i][j] * scalar;
        }
    }
    return temp;
}

SquareMat SquareMat::operator^ (int num)const{
    SquareMat ans(*this);
    if (num < 0){
        throw std::invalid_argument("num is lower then 0");
    }
    if (num == 0){
        for (int i = 0; i < size; i++){
            for (int j = 0; j < size; j++){
                ans[i][j] = 0;
                if(i == j){
                    ans[i][j] = 1;
                }
            }
        }
    }
    else{
        for (int i = 1; i < num; i++){
            ans = ans * (*this);
        }
    }
    return ans;

}
SquareMat SquareMat::operator~ ()const{
    SquareMat temp(*this);
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            temp[i][j] = matrix[j][i];
        }
    }
    return temp;
}
SquareMat& SquareMat::operator+= (const SquareMat& other){
    *this = *this + other;
    return *this;
}
SquareMat& SquareMat::operator-= (const SquareMat& other){
    *this = *this - other;
    return *this;
}
SquareMat& SquareMat::operator*= (const SquareMat& other){
    *this = *this * other;
    return *this;
}
SquareMat& SquareMat::operator*= (double scalar){
    *this = *this * scalar;
    return *this;
}
SquareMat& SquareMat::operator/= (double scalar){
    *this = *this / scalar;
    return *this;
}
double SquareMat::operator! ()const{
    double det = 0;
    if (size == 1){
        return matrix[0][0];
    }
    if (size == 2){
        det = (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]);
        return det;
    }
    if (size == 3){
        det = matrix[0][0] * (matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1])
            - matrix[0][1] * (matrix[1][0] * matrix[2][2] - matrix[1][2] * matrix[2][0])
            + matrix[0][2] * (matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0]);
        return det;
    }
    int firstNum;
    for (int j = 0; j < size; j++){
        if (j % 2 == 0){
            firstNum = 1;
        }
        else{
            firstNum = -1;
        }
        SquareMat mat(size - 1);
        firstNum *= matrix[0][j];
        for (int i = 1; i < size ; i++){
            int index = 0;
            for(int h = 0; h < size; h++){
                if (h == j){
                    continue;
                }
                mat[i - 1][index++] = matrix[i][h];
            }
        }
        det += firstNum * !mat;
    }
    return det;
}
bool SquareMat::equal(const SquareMat& other)const{
    if (other.size != size){
        return false;
    }
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            if (matrix[i][j] != other[i][j]){
                return false;
            }
        }
    }
    return true;
}
SquareMat& SquareMat::operator%= (const SquareMat& other){
    *this = *this % other;
    return *this;
}
SquareMat& SquareMat::operator%= (int modulu){
    *this = *this % modulu;
    return *this;
}









