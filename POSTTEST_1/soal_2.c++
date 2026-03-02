#include <iostream>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    float ipk;
};

int main() {
    Mahasiswa mhs[5] = {
        {"gibran",  "2310111", 3.45},
        {"prabowo",  "2310112", 3.60},
        {"anis", "2310113", 3.80},
        {"jokowi",  "2310114", 3.55},
        {"mega wati",   "2310115", 3.70}
    };

    cout << "Data Mahasiswa:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << i + 1 << ". "
             << mhs[i].nama << " | "
             << mhs[i].nim << " | "
             << mhs[i].ipk << endl;
    }


    int indexMax = 0;
    for (int i = 1; i < 5; i++) {
        if (mhs[i].ipk > mhs[indexMax].ipk) {
            indexMax = i;
        }
    }

    cout << endl;
    cout << "Mahasiswa dengan IPK tertinggi adalah:" << endl;
    cout << "Nama : " << mhs[indexMax].nama << endl;
    cout << "NIM  : " << mhs[indexMax].nim << endl;
    cout << "IPK  : " << mhs[indexMax].ipk << endl;

    return 0;
}