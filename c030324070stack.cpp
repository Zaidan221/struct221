#include <iostream>
using namespace std;
#include <string>

typedef string ItemType;  
#define MAXSTACK 5

typedef struct {
    ItemType Item[MAXSTACK];
    int Count;
} Stack;

// Deklarasi fungsi
void InitializeStack(Stack *S);
int Empty(Stack *S);
int Full(Stack *S);
void Push(ItemType x, Stack *S);
void Pop(Stack *S, ItemType *x);
void Display(Stack *S);
