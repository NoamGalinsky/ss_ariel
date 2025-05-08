/*    noamgal46@gmail.com    */


#include "SquareMat.hpp"

using namespace matrix;

int main() {
    cout << "enter size of your matrix: ";
    int size;
    cin >> size;
    SquareMat mat1(size);
    SquareMat ans(size);

    cout << "enter the sum of the matirx cell after cell: " << endl;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++){
            double sum;
            cin >> sum;
            mat1[i][j] = sum;
        }
    }
    cout << mat1 << endl;
    SquareMat mat2(size);
    cout << "now put in  the sum of matrix number 2 " << endl;

    cout << "enter the sum of the matirx cell after cell: " << endl;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++){
            double sum;
            cin >> sum;
            mat2[i][j] = sum;
        }
    }
    cout << mat2 << endl;
    double scalar;
    int power;
    cout << "enter scalar value: " << endl;
    cin >> scalar;

    cout << "enter integer for power: " << endl;
    cin >> power;

    cout << "mat1 - mat2 = " << endl;
    ans = mat1 - mat2;
    cout << ans << endl;

    cout << "mat1 + mat2 = " << endl;
    ans = mat1 + mat2;
    cout << ans << endl;

    cout << "-mat1 = " << endl;
    ans = -mat1;
    cout << ans << endl;

    cout << "mat1 * mat2 = " << endl;
    ans = mat1 * mat2;
    cout << ans << endl;


    cout << "mat1 * " << scalar << " = " << endl;
    ans = mat1 * scalar;
    cout << ans << endl;


    cout << "mat1 % mat2 = " << endl;
    ans = mat1 % mat2;
    cout << ans << endl;

    cout << "mat1 % " << scalar << " = " << endl;
    ans = mat1 % scalar;
    cout << ans << endl;

    cout << "mat1 / " << scalar << " = " << endl;
    ans = mat1 / scalar;
    cout << ans << endl;

    cout << "mat1 ^ " << power << " = " << endl;
    ans = mat1 ^ power;
    cout << ans << endl;

    cout << "mat1++ = " << endl;
    ans = mat1;
    ans++;
    cout << ans << endl;

    cout << "mat1-- = " << endl;
    ans = mat1;
    ans--;
    cout << ans << endl;

    cout << "~mat1 = " << endl;
    ans = ~mat1;
    cout << ans << endl;

    double det = !mat1;
    cout << "!mat1 = " << det << endl;

    return 0;
}
