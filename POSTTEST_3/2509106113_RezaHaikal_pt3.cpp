#include <iostream>
using namespace std;

#define MAX 5

struct Hewan {
    int id;
    string nama;
};

struct Queue {
    Hewan data[MAX];
    int front, rear;
};

struct Stack {
    Hewan data[MAX];
    int top;
};

void initQueue(Queue *q) {
    q->front = q->rear = -1;
}

void initStack(Stack *s) {
    s->top = -1;
}

bool isFullQueue(Queue *q) {
    return q->rear == MAX - 1;
}

bool isEmptyQueue(Queue *q) {
    return q->front == -1;
}

bool isFullStack(Stack *s) {
    return s->top == MAX - 1;
}

bool isEmptyStack(Stack *s) {
    return s->top == -1;
}

void enqueue(Queue *q, Hewan h) {
    if (isFullQueue(q)) {
        cout << "Antrian penuh!\n";
    } else {
        if (isEmptyQueue(q)) {
            q->front = 0;
        }
        q->rear++;
        *(q->data + q->rear) = h;
        cout << "Hewan masuk antrian\n";
    }
}

Hewan dequeue(Queue *q) {
    Hewan h;
    if (isEmptyQueue(q)) {
        cout << "Antrian kosong!\n";
        return h;
    } else {
        h = *(q->data + q->front);

        for (int i = q->front; i < q->rear; i++) {
            *(q->data + i) = *(q->data + i + 1);
        }

        q->rear--;

        if (q->rear < q->front) {
            q->front = q->rear = -1;
        }

        return h;
    }
}

void push(Stack *s, Hewan h) {
    if (isFullStack(s)) {
        cout << "Riwayat penuh!\n";
    } else {
        s->top++;
        *(s->data + s->top) = h; 
        cout << "Masuk ke riwayat\n";
    }
}

void pop(Stack *s) {
    if (isEmptyStack(s)) {
        cout << "Riwayat kosong!\n";
    } else {
        cout << "Menghapus riwayat: " << (s->data + s->top)->nama << endl;
        s->top--;
    }
}

void peek(Queue *q, Stack *s) {
    if (!isEmptyQueue(q)) {
        cout << "Pasien depan: " << (q->data + q->front)->nama << endl;
    } else {
        cout << "Antrian kosong\n";
    }

    if (!isEmptyStack(s)) {
        cout << "Riwayat terakhir: " << (s->data + s->top)->nama << endl;
    } else {
        cout << "Riwayat kosong\n";
    }
}

void tampilQueue(Queue *q) {
    if (isEmptyQueue(q)) {
        cout << "Antrian kosong\n";
    } else {
        cout << "Daftar Antrian:\n";
        for (Hewan *p = q->data + q->front; p <= q->data + q->rear; p++) {
            cout << "ID: " << p->id << " Nama: " << p->nama << endl;
        }
    }
}

void tampilStack(Stack *s) {
    if (isEmptyStack(s)) {
        cout << "Riwayat kosong\n";
    } else {
        cout << "Riwayat Tindakan:\n";
        for (Hewan *p = s->data; p <= s->data + s->top; p++) {
            cout << "ID: " << p->id << " Nama: " << p->nama << endl;
        }
    }
}

int main() {
    Queue q;
    Stack s;

    initQueue(&q);
    initStack(&s);

    int pilih;
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
            cin >> h.id;
            cout << "Nama: ";
            cin >> h.nama;
            enqueue(&q, h);
            break;

        case 2:
            h = dequeue(&q);
            cout << "Dipanggil: " << h.nama << " (" << h.id << ")\n";
            push(&s, h);
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