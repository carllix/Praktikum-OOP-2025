#include <iostream>
#include "Kompleks.hpp"
using namespace std;

// Nilai default 0 + 0i
Kompleks::Kompleks(){
    this->real = 0;
    this->imag = 0;
}

// r + i*i
Kompleks::Kompleks(double r, double i){
    this->real = r;
    this->imag = i;
}

Kompleks::Kompleks(const Kompleks& other){
    this->real = other.real;
    this->imag = other.imag;
}

double Kompleks::getReal() const{
    return this->real;
}

double Kompleks::getImag() const{
    return this->imag;
}

double Kompleks::setReal(double r){
    this->real = r;
    return this->real;
}

double Kompleks::setImag(double i){
    this->imag = i;
    return this->imag;
}

// Menambahkan dua bilangan kompleks
    // Misal: a = 1 + 2i, b = 3 + 4i;
    // a + b = (1+3) + (2+4)i = 4 + 6i
Kompleks Kompleks::operator+(const Kompleks& other) const{
    Kompleks res(this->real+other.real,this->imag + other.imag);
    return res;
}

// Mengurangi dua bilangan kompleks
    // Misal: a = 1 + 2i, b = 3 + 4i;
    // a - b = (1-3) + (2-4)i = -2 - 2i
Kompleks Kompleks::operator-(const Kompleks& other) const{
    Kompleks res(this->real-other.real,this->imag-other.imag);
    return res;
}

// Mengalikan dua bilangan kompleks
    // Misal: a = 1 + 2i, b = 3 + 4i;
    // a * b = 1*3 + 1*4i + 2i*3 + 2i*4i = 3 + 4i + 6i - 8 = -5 + 10i
Kompleks Kompleks::operator*(const Kompleks& other) const{
    double real = this->real * other.real - this->imag * other.imag;
    double imag = this->real * other.imag + this->imag * other.real;
    Kompleks res(real,imag);

    return res;
}

// Membandingkan dua bilangan kompleks
    // Misal: a = 1 + 2i, b = 3 + 4i;
    // a == b = (1==3) && (2==4) = false
    // Misal: a = 1 + 2i, b = 1 + 2i;
    // a == b = (1==1) && (2==2) = true
bool Kompleks::operator==(const Kompleks& other) const{
    return (this->imag == other.imag && this->real == other.real);
}

// Menyalin dua bilangan kompleks
Kompleks& Kompleks::operator=(const Kompleks& other){
    this->imag = other.imag;
    this->real = other.real;
    return *this;
}

// Menampilkan bilangan kompleks
    // Note: Tidak menggunakan endl
    // Misal: Kompleks(1, 2)
    // cout << a << endl; // Output: 1 + 2i
    // Jika imajiner < 0; Misal: Kompleks(1, -2)
    // cout << a << endl; // Output: 1 - 2i
    // Jika nilai imajiner 0, jangan tampilkan i; Misal: Kompleks(1, 0)
    // cout << a << endl; // Output: 1
ostream& operator<<(ostream& os, const Kompleks& c){
    os << c.getReal();
    if (c.getImag() > 0) {
        os << " + " << c.getImag() << "i";
    } else if (c.getImag() < 0) {
        os << " - " << -c.getImag() << "i";
    }
    return os;
}