
#include<iostream>
#include<memory>

// Init bagian data
using itemType = int;
const size_t MAXSTACK = 10;

struct dataStack
{
  itemType item[MAXSTACK];
  int count;
};
// Menggunakan unique ptr ke dataStack
using myPtr = std::unique_ptr<dataStack>;

// Init fungsi dari stack
namespace stack
{
  void init(myPtr &S);
  bool isEmpty(const myPtr &S);
  bool isFull(const myPtr &S);
  void pop(myPtr &S);
  void push(myPtr &S, itemType x);
  void display(myPtr &S);
};


int main()
{
  // Init myPtr
  myPtr ptrStack = std::make_unique<dataStack>();
  
  // Program stack
  stack::init(ptrStack);
  stack::push(ptrStack, 5);
  stack::push(ptrStack, 7);
  stack::push(ptrStack, 10);
  stack::push(ptrStack, 35);
  stack::pop(ptrStack);
  stack::display(ptrStack);
  
  return 0;
}

/* Logika fungsi untuk stack */
inline void stack::init(myPtr &S) {S -> count = 0;}

inline bool stack::isEmpty(const myPtr &S) {return S -> count == 0;}

inline bool stack::isFull(const myPtr &S) {return S -> count == MAXSTACK;}


void stack::push(myPtr &S, itemType x)
{
  /* 
  Fungsi untuk push data ke stack. Dimana ada safety untuk cek apakah stacknya full atau tidak.
  Logika yang dipakai yaitu dengan mengguankan count sebagai head dari stack.
     */

  if(stack::isFull(S)){
    std::cout << "Stack penuh, data tidak bisa dimasukkan!" << std::endl;
    return;
  }

  S -> item[S -> count] = x;
  ++(S -> count);
  std::cout << "Push data " << x << " berhasil!" << std::endl;
}


void stack::pop(myPtr &S)
{
  /*
  Fungsi untuk pop data dari stack. Mempunyai safety untuk cek apakah stacknya kosong atau tidak.
  Logika yang dipakai tidak secara langsung menghapus data dari head sebelumnya.
  Akan tetapi mengurangi count ke stack sebelumnya.
  */

  if (stack::isEmpty(S)){
    std::cout << "Stack masih kosong!" << std::endl;
    return;
  }

  --(S -> count);
  itemType dataPopped = S -> item[S -> count];
  std::cout << "Pop data " << dataPopped << " berhasil!" << std::endl;
}


void stack::display(myPtr &S)
{
  // Menampilkan semua isi dari item di stack
  std::cout << "Menampilkan Data:\n";
  for(int i = (S -> count) - 1; i >= 0; --i){
    std::cout << S -> item[i] << std::endl;
  }
}
