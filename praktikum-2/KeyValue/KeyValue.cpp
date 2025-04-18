#include <iostream>
#include <string>
using namespace std;

template <class T, class P>
class KeyValue
{
private:
    T *keys;
    P *values;
    int count;

public:
    KeyValue()
    {
        this->keys = new T[10];
        this->values = new P[10];
        this->count = 0;
    }

    KeyValue(const KeyValue<T, P> &other)
    {
        this->keys = new T[10];
        this->values = new P[10];
        this->count = other.count;

        for (int i = 0; i < other.count; i++)
        {
            this->keys[i] = other.keys[i];
            this->values[i] = other.values[i];
        }
    }

    ~KeyValue()
    {
        delete[] this->keys;
        delete[] this->values;
    }

    void set(T key, P value)
    {
        bool isExistKey = false;
        for (int i = 0; i < this->count; i++)
        {
            if (key == this->keys[i])
            {
                values[i] = value;
                isExistKey = true;
            }
        }

        if (isExistKey == false)
        {
            if (count < 10)
            {
                keys[count] = key;
                values[count] = value;
                this->count++;
            }
            else
            {
                cout << "KeyValue penuh! Tidak bisa menambahkan KeyValue lagi." << endl;
            }
        }
    }

    void display(T key)
    {
        bool isExistKey = false;
        for (int i = 0; i < count; i++)
        {
            if (key == keys[i])
            {
                cout << values[i] << endl;
                isExistKey = true;
            }
        }

        if (isExistKey == false)
        {
            cout << "Key tidak ditemukan!" << endl;
        }
    }
};

template <class P>
class KeyValue<double, P>
{
private:
    double *keys;
    P *values;
    int count;

public:
    KeyValue()
    {
        this->keys = new double[10];
        this->values = new P[10];
        this->count = 0;
    }

    KeyValue(const KeyValue<double, P> &other)
    {
        this->keys = new double[10];
        this->values = new P[10];
        this->count = other.count;
        for (int i = 0; i < other.count; i++)
        {
            this->keys[i] = other.keys[i];
            this->values[i] = other.values[i];
        }
    }

    ~KeyValue()
    {
        delete[] this->keys;
        delete[] this->values;
    }

    void set(double key, P value)
    {
        bool isExistKey = false;
        for (int i = 0; i < this->count; i++)
        {
            double diff = key - this->keys[i];
            if (diff < 0)
                diff = -diff;
            if (diff < 0.01)
            {
                values[i] = value;
                isExistKey = true;
            }
        }
        if (isExistKey == false)
        {
            if (count < 10)
            {
                keys[count] = key;
                values[count] = value;
                this->count++;
            }
            else
            {
                cout << "KeyValue penuh! Tidak bisa menambahkan KeyValue lagi." << endl;
            }
        }
    }

    void display(double key)
    {
        bool isExistKey = false;
        for (int i = 0; i < count; i++)
        {
            double diff = key - keys[i];
            if (diff < 0)
                diff = -diff;
            if (diff < 0.01)
            {
                cout << values[i] << endl;
                isExistKey = true;
            }
        }
        if (isExistKey == false)
        {
            cout << "Key tidak ditemukan!" << endl;
        }
    }
};

// int main(){

//     KeyValue<int, string> kv;
//     kv.set(1, "Alice");
//     kv.set(2, "Bob");
//     kv.set(3, "Charlie");
//     kv.display(1); // Output: "Alice"
//     kv.display(2); // Output: "Bob"
//     kv.display(3); // Output: "Charlie"
//     return 0;
// }