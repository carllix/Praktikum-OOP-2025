#include <iostream>

using namespace std;

template<class T>
void func(T param1, T param2){
    cout << "Masukan Anda: " << param1 << " dan " << param2 << ", memiliki tipe yang sama" << endl;
}

template<class T, class S>
void func(T param1, S param2){
    cout << "Masukan Anda: " << param1 << " dan " << param2 << ", mungkin memiliki tipe yang berbeda" << endl;
}

template<>
void func<char,int>(char param1, int param2){
    for (int i = 0; i<param2; i++){
        cout << param1 << endl;
    }
}

// int main(){
//     func(1,2);
//     func('B','A');
//     func('B',2);
//     func(2,'B');
//     return 0;
// }