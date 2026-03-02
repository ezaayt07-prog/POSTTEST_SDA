#include <iostream>
using namespace std;

int main() {
    int A[8] = {1, 1, 2, 3, 5, 8, 13, 21};
    int n = 8;

    int min = A[0];
    int index = 0;

    for (int i = 1; i < n; i++) {
        if (A[i] < min) {
            min = A[i];
            index = i;
        }
    }

    cout << "Nilai minimum: " << min << endl;
    cout << "Indeks minimum: " << index << endl;

    return 0;
}

/*
Analisis Kompleksitas Waktu FindMin

Pseudocode:
1. min ← A[0]                  // 1 operasi
2. for i = 1 to n-1             // n-1 kali
3.    if A[i] < min             // n-1 kali (perbandingan)
4.       min ← A[i]             // bisa 0 s.d n-1 kali
5. return min                   // 1 operasi

-----------------------------------
Best Case (Tmin):
- Array sudah terurut naik
- Kondisi A[i] < min SELALU salah
Tmin(n) = 1 + (n-1) + (n-1) + 1
Tmin(n) = 2n

Big-O Best Case = O(n)

-----------------------------------
Worst Case (Tmax):
- Array terurut menurun
- Kondisi A[i] < min SELALU benar
Tmax(n) = 1 + (n-1) + (n-1) + (n-1) + 1
Tmax(n) = 3n - 1

Big-O Worst Case = O(n)
-----------------------------------
*/