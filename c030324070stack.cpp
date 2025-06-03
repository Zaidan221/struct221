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

