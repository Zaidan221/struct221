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
