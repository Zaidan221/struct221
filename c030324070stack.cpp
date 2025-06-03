#include <iostream>
using namespace std;
#include <string>

// Tipe data item pada stack
typedef string ItemType;  

// Ukuran maksimum stack
#define MAXSTACK 5

// Struktur stack berbasis pointer
typedef struct {
    ItemType Item[MAXSTACK];
    int Count;
} Stack;

// Inisialisasi stack
void InitializeStack(Stack *S) {
    S->Count = 0;
}

// Cek apakah stack kosong
int Empty(Stack *S) {
    return (S->Count == 0);
}

// Cek apakah stack penuh
int Full(Stack *S) {
    return (S->Count == MAXSTACK);
}

// Fungsi Push
void Push(ItemType x, Stack *S) {
    if (Full(S))
        cout << "Stack penuh! Data tidak dapat masuk!" << endl;
    else {
        S->Item[S->Count] = x;
        ++(S->Count);
    }
}

// Fungsi Pop
void Pop(Stack *S, ItemType *x) {
    if (Empty(S))
        cout << "Stack masih kosong!" << endl;
    else {
        --(S->Count);
        *x = S->Item[S->Count];
    }
}

// Menampilkan isi stack
void Display(Stack *S) {
    if (Empty(S)) {
        cout << "Data tidak tersedia." << endl;
    } else {
        cout << "Data tersimpan:" << endl;
        for (int i = 0; i < S->Count; i++) {
            cout << i + 1 << ". " << S->Item[i] << endl;
        }
    }

    if (Full(S)) {
        cout << "Stack Penuh." << endl;
    }

    cout << endl;
}

int main() {
    Stack s;
    InitializeStack(&s);

    int pil;
    ItemType data;

    do {
        system("cls"); 
        Display(&s);
        cout << "Menu Utama\n1. Push\n2. Pop\n3. Keluar\nPilih: ";
        cin >> pil;
        cin.ignore(); // membersihkan newline di buffer