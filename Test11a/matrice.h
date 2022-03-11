#include "complex.h"
#include<iostream>
#include <fstream>
using namespace std;

#define z 5

template<class T>
class mat
{
    int dim;
    T m[z][z];
public:
    void creare();
    void afisare();
    void salvare(ofstream& out);
    void restaurare(ifstream& in);
    mat<T> operator+(mat<T>);
    mat<T> operator-(mat<T>);
    mat<T> operator*(mat<T>);
    friend mat<T> operator^(mat<T> B, int dim) {
        mat<T> C = B;
        for (int i = 0;i < dim - 1;i++) {
            C = C * B;
        }
        return C;
    }
};

template<class T>
void mat<T>::creare()
{
    cout << "Dimensiunea:";
    cin >> dim;
    for (int i = 0;i < dim;i++) {
        for (int j = 0;j < dim;j++)
        {
            cout << "Elementul:" << i << j << " : ";
            cin >> m[i][j];
        }
    }
}

template<class T>
void mat<T>::afisare()
{
    for (int i = 0;i < dim;i++)
    {
        for (int j = 0;j < dim;j++) {
            cout << m[i][j] << "\t";
        }
        cout << endl;
    }
}

template <class T>
void mat<T>::salvare(ofstream& out) {
    out.open("dataout.txt");
    for (int i = 0;i < dim;i++)
    {
        for (int j = 0;j < dim;j++) {
            out << m[i][j] << "\t";
        }
        out << "\n";
    }
    out.close();
}

template <class T>
void mat<T>::restaurare(ifstream& fin) {
    fin.open("datain.txt");
    int x;
    fin >> x;
    if (dim == x) {
        int v[5];
        for (int i = 0;i < dim;i++)
        {
            for (int j = 0;j < dim;j++) {
                fin >> v[i];
                m[i][j] = v[i];
            }
        }
    }
    else {
        cout << "Dimensiune diferita" << endl;
    }
    fin.close();
}

template<class T>
mat<T> mat<T>::operator+(mat<T> B)
{
    mat<T> C;
    C.dim = dim;
    for (int i = 0;i < dim;i++) {
        for (int j = 0;j < dim;j++) {
            C.m[i][j] = m[i][j] + B.m[i][j];
        }
    }
    return C;
}

template<class T>
mat<T> mat<T>::operator-(mat<T> B)
{
    mat C;
    C.dim = dim;
    for (int i = 0;i < dim;i++) {
        for (int j = 0;j < dim;j++) {
            C.m[i][j] = m[i][j] - B.m[i][j];
        }
    }
    return C;
}

template<class T>
mat<T> mat<T>::operator*(mat<T> B)
{
    mat C;
    C.dim = dim;

    for (int i = 0;i < dim;i++)
    {
        for (int j = 0;j < B.dim;j++)
        {
            C.m[i][j] = 0;
            for (int k = 0;k < dim;k++)
            {
                C.m[i][j] = C.m[i][j] + (m[i][k] * B.m[k][j]);
            }
        }
    }
    return C;
}

