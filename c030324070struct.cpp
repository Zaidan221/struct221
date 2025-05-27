#include <iostream>
using namespace std;

struct mahasiswa{
    string nim;
    string nama;
    string alamat;
    float ipk;
};

int main(){
mahasiswa Zaidan;

Zaidan.nim = "c030324070";
Zaidan.nama = "Zaidan Saputra";
Zaidan.alamat = "Jl.sungai andai no 4";
Zaidan.ipk = 3.9;

cout << Zaidan.nim << "\n";
cout << Zaidan.nama << "\n";
cout << Zaidan.alamat << "\n";
cout << Zaidan.ipk << "\n";
}

