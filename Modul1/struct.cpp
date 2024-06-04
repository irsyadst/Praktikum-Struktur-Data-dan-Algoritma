#include<stdio.h>

using namespace std;

struct Mahasiswa
{
    char *name;
    char *address;
    int age;
};

int main(){
    struct Mahasiswa mhs1,mhs2;

    mhs1.name = "Dian";
    mhs1.address = "Mataram";
    mhs1.age = 22;

    mhs2.name = "Bambang";
    mhs2.address = "Mataram";
    mhs2.age = 23;

    printf("Mahasiswa 1 \n");
    printf("Nama: %s \n",mhs1.name);
    printf("Alamat: %s \n",mhs1.address);
    printf("Umur : %s \n",mhs1.age);

    return 0;
}
