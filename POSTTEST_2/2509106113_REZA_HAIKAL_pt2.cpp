#include <iostream>
#include <string>
using namespace std;

struct Hewan {
    int id;
    string nama;
    string jenis;
    int harga;
};

int jumlah = 0;

// ================== TAMPIL DATA ==================
void tampilData(Hewan* arr) {
    cout << "\n=== DATA HEWAN ===\n";
    for (int i = 0; i < jumlah; i++) {
        cout << "ID     : " << (arr + i)->id << endl;
        cout << "Nama   : " << (arr + i)->nama << endl;
        cout << "Jenis  : " << (arr + i)->jenis << endl;
        cout << "Harga  : " << (arr + i)->harga << endl;
        cout << "----------------------\n";
    }
}

void tambahData(Hewan* arr) {
    cout << "\nTambah Data Hewan\n";
    cout << "ID     : "; cin >> (arr + jumlah)->id;
    cout << "Nama   : "; cin >> (arr + jumlah)->nama;
    cout << "Jenis  : "; cin >> (arr + jumlah)->jenis;
    cout << "Harga  : "; cin >> (arr + jumlah)->harga;
    jumlah++;
}

void swapHewan(Hewan* a, Hewan* b) {
    Hewan temp = *a;
    *a = *b;
    *b = temp;
}

void linearSearch(Hewan* arr, string cari) {
    bool ketemu = false;

    cout << "\nProses pencarian:\n";
    for (int i = 0; i < jumlah; i++) {
        cout << "Cek index ke-" << i << " (" << (arr+i)->nama << ")\n";

        if ((arr + i)->nama == cari) {
            cout << "\nData ditemukan!\n";
            cout << "ID     : " << (arr + i)->id << endl;
            cout << "Jenis  : " << (arr + i)->jenis << endl;
            cout << "Harga  : " << (arr + i)->harga << endl;
            ketemu = true;
            break;
        }
    }

    if (!ketemu) {
        cout << "Data tidak ditemukan!\n";
    }
}

int min(int x, int y) {
    return (x <= y) ? x : y;
}

void fibonacciSearch(Hewan* arr, int x) {
    int fibMMm2 = 0;
    int fibMMm1 = 1;
    int fibM = fibMMm2 + fibMMm1;

    while (fibM < jumlah) {
        fibMMm2 = fibMMm1;
        fibMMm1 = fibM;
        fibM = fibMMm2 + fibMMm1;
    }

    int offset = -1;

    while (fibM > 1) {
        int i = min(offset + fibMMm2, jumlah - 1);

        if ((arr + i)->id < x) {
            fibM = fibMMm1;
            fibMMm1 = fibMMm2;
            fibMMm2 = fibM - fibMMm1;
            offset = i;
        }
        else if ((arr + i)->id > x) {
            fibM = fibMMm2;
            fibMMm1 = fibMMm1 - fibMMm2;
            fibMMm2 = fibM - fibMMm1;
        }
        else {
            cout << "\nData ditemukan!\n";
            cout << "Nama   : " << (arr + i)->nama << endl;
            cout << "Jenis  : " << (arr + i)->jenis << endl;
            cout << "Harga  : " << (arr + i)->harga << endl;
            return;
        }
    }

    if (fibMMm1 && (arr + offset + 1)->id == x) {
        cout << "\nData ditemukan!\n";
        cout << "Nama   : " << (arr + offset + 1)->nama << endl;
        cout << "Jenis  : " << (arr + offset + 1)->jenis << endl;
        cout << "Harga  : " << (arr + offset + 1)->harga << endl;
        return;
    }

    cout << "Data tidak ditemukan!\n";
}

void bubbleSort(Hewan* arr) {
    for (int i = 0; i < jumlah - 1; i++) {
        for (int j = 0; j < jumlah - i - 1; j++) {
            if ((arr + j)->nama > (arr + j + 1)->nama) {
                swapHewan((arr + j), (arr + j + 1));
            }
        }
    }
    cout << "Data berhasil diurutkan (Nama A-Z)\n";
}

void selectionSort(Hewan*& arr) {
    for (int i = 0; i < jumlah - 1; i++) {
        int minIndex = i;

        for (int j = i + 1; j < jumlah; j++) {
            if ((arr + j)->harga < (arr + minIndex)->harga) {
                minIndex = j;
            }
        }

        swapHewan((arr + i), (arr + minIndex));
    }
    cout << "Data berhasil diurutkan (Harga termurah)\n";
}

int main() {
    Hewan data[100];
    Hewan* ptr = data;

    int pilih;
    string cariNama;
    int cariID;

    do {
        cout << "\n=== PAWCARE PETSHOP ===\n";
        cout << "1. Tampil Data\n";
        cout << "2. Tambah Data\n";
        cout << "3. Cari Nama (Linear)\n";
        cout << "4. Cari ID (Fibonacci)\n";
        cout << "5. Urutkan Nama (Bubble)\n";
        cout << "6. Urutkan Harga (Selection)\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";
        cin >> pilih;

        switch (pilih) {
            case 1:
                tampilData(ptr);
                break;
            case 2:
                tambahData(ptr);
                break;
            case 3:
                cout << "Masukkan nama: ";
                cin >> cariNama;
                linearSearch(ptr, cariNama);
                break;
            case 4:
                cout << "Masukkan ID: ";
                cin >> cariID;
                fibonacciSearch(ptr, cariID);
                break;
            case 5:
                bubbleSort(ptr);
                break;
            case 6:
                selectionSort(ptr);
                break;
        }

    } while (pilih != 0);

    return 0;
}