#include <iostream>
using namespace std;

struct Hewan {
    int id;
    string nama;
    Hewan *next;
};

struct Queue {
    Hewan *front;
    Hewan *rear;
};

void initQueue(Queue *q) {
    q->front = q->rear = NULL;
}

bool isEmptyQueue(Queue *q) {
    return q->front == NULL;
}

void enqueue(Queue *q, int id, string nama) {
    Hewan *baru = new Hewan;
    baru->id = id;
    baru->nama = nama;
    baru->next = NULL;

    if (isEmptyQueue(q)) {
        q->front = q->rear = baru;
    } else {
        q->rear->next = baru;
        q->rear = baru;
    }

    cout << "Hewan masuk antrian\n";
}

Hewan dequeue(Queue *q) {
    Hewan kosong;
    kosong.id = -1;
    kosong.nama = "";

    if (isEmptyQueue(q)) {
        cout << "Antrian kosong!\n";
        return kosong;
    }

    Hewan *hapus = q->front;
    Hewan data = *hapus;

    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }

    delete hapus;
    return data;
}

void tampilQueue(Queue *q) {
    if (isEmptyQueue(q)) {
        cout << "Antrian kosong\n";
        return;
    }

    cout << "Daftar Antrian:\n";
    Hewan *p = q->front;
    while (p != NULL) {
        cout << "ID: " << p->id << " Nama: " << p->nama << endl;
        p = p->next;
    }
}

struct Stack {
    Hewan *top;
};

void initStack(Stack *s) {
    s->top = NULL;
}

bool isEmptyStack(Stack *s) {
    return s->top == NULL;
}

void push(Stack *s, Hewan h) {
    Hewan *baru = new Hewan;
    baru->id = h.id;
    baru->nama = h.nama;

    baru->next = s->top;
    s->top = baru;

    cout << "Masuk ke riwayat\n";
}

void pop(Stack *s) {
    if (isEmptyStack(s)) {
        cout << "Riwayat kosong!\n";
        return;
    }

    Hewan *hapus = s->top;
    cout << "Menghapus riwayat: " << hapus->nama << endl;

    s->top = s->top->next;
    delete hapus;
}

void tampilStack(Stack *s) {
    if (isEmptyStack(s)) {
        cout << "Riwayat kosong\n";
        return;
    }

    cout << "Riwayat Tindakan:\n";
    Hewan *p = s->top;
    while (p != NULL) {
        cout << "ID: " << p->id << " Nama: " << p->nama << endl;
        p = p->next;
    }
}

void peek(Queue *q, Stack *s) {
    if (!isEmptyQueue(q)) {
        cout << "Pasien depan: " << q->front->nama << endl;
    } else {
        cout << "Antrian kosong\n";
    }

    if (!isEmptyStack(s)) {
        cout << "Riwayat terakhir: " << s->top->nama << endl;
    } else {
        cout << "Riwayat kosong\n";
    }
}

int main() {
    Queue q;
    Stack s;

    initQueue(&q);
    initStack(&s);

    int pilih, id;
    string nama;
    Hewan h;

    do {
        cout << "\n=== MENU PAWCARE ===\n";
        cout << "1. Tambah Antrian\n";
        cout << "2. Panggil Pasien\n";
        cout << "3. Pop Riwayat\n";
        cout << "4. Peek\n";
        cout << "5. Tampil Antrian\n";
        cout << "6. Tampil Riwayat\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";
        cin >> pilih;

        switch (pilih) {
        case 1:
            cout << "ID: ";
            cin >> id;
            cout << "Nama: ";
            cin >> nama;
            enqueue(&q, id, nama);
            break;

        case 2:
            h = dequeue(&q);
            if (h.id != -1) {
                cout << "Dipanggil: " << h.nama << " (" << h.id << ")\n";
                push(&s, h);
            }
            break;

        case 3:
            pop(&s);
            break;

        case 4:
            peek(&q, &s);
            break;

        case 5:
            tampilQueue(&q);
            break;

        case 6:
            tampilStack(&s);
            break;
        }

    } while (pilih != 0);

    return 0;
}