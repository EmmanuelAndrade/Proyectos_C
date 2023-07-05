#include <stdio.h>
//1.-Estructura "inventario"
struct inventory
{
    char partName[30];
    int partNumber;
    float price;
    int stock;
    int reorder;
};

//2.- Union "Data"
union Data
{
    char c;
    short s;
    long b;
    float f;
    double d;
};

//3.-Estructura "Address"
struct Address
{
    char streetAddress[25];
    char city[20];
    char state[3];
    char zipCode[6];
};

//4.-Estructura "Student"
struct Student
{
    char firstName[15];
    char lastName[15];
    struct Address HomeAddress;
};
//5.-Estructura "test"
struct test
{
    // Se declara ": 1 para declarar el ancho de la varable"
    unsigned char a : 1;
    unsigned char b : 1;
    unsigned char c : 1;
    unsigned char d : 1;
    unsigned char f : 1;
    unsigned char g : 1;
    unsigned char h : 1;
    unsigned char i : 1;
    unsigned char j : 1;
    unsigned char k : 1;
    unsigned char l : 1;
    unsigned char m : 1;
    unsigned char n : 1;
    unsigned char o : 1;
    unsigned char p : 1;
};

//Parte 2.- Escribir una expecion que permita el acceso a los miembros de la siguiente estructura

struct customer
{
    char lastName[15];
    char firstName[15];
    int customerNumber;
    struct {
        char phoneNumber[11];
        char address[50]; 
        char city[15];
        char state[3];
        char zipCode[6];
    }personal;
    
}customerRecord, *customerPtr;


// Un-packing bytes to serialize messages
struct UnStructPack
{
    unsigned long word;
    unsigned char byte;
    unsigned short hword;
};

struct StructPack
{
    unsigned long word1;
    unsigned long word2;
    unsigned char byte;
    unsigned short hword1;
};


void UnpackingkBytes(struct UnStructPack *message, unsigned char *array);
void PackingBytes(unsigned char *array, struct StructPack *messege);

int main()
{
    //Accesos para obtener informacion de la structura
    //customerPtr = &customerRecord;
    /*
    //A
    customerRecord.lastName;
    //B
    customerPtr->lastName;
    //C
    customerRecord.firstName;
    //D
    customerPtr->firstName;
    //E
    customerRecord.customerNumber;
    //F
    customerPtr->customerNumber;
    //G
    customerRecord.personal.phoneNumber;
    //H
    customerPtr->personal.phoneNumber;
    //I
    customerRecord.personal.address;
    //J
    customerPtr->personal.address;
    //K
    customerRecord.personal.city;
    //L
    customerPtr->personal.city;
    //M
    customerRecord.personal.state;
    //N
    customerPtr->personal.state;
    //O
    customerRecord.personal.zipCode;
    //P
    customerPtr->personal.zipCode;
    */

    //UnpackingBytes
    //unsigned char Bytes[7];   
    //PackingBytes
    //unsigned char array[11];

}

    //UnpackingBytes
void UnpackingkBytes(struct UnStructPack *message, unsigned char *array){
    array[0] = (unsigned char)(message->word); //Guarda los primero 8 bits de la varable word en la primera posicion del array
    array[1] = (unsigned char)(message->word >> 8); // Desplazo 8,16,24 bits para obtener los nuevos bit menos significativos
    array[2] = (unsigned char)(message->word >> 16);
    array[3] = (unsigned char)(message->word >> 24);
    array[4] = message->byte;
    array[5] = (unsigned char)(message->hword);
    array[6] = (unsigned char)(message->hword >> 8);
}

void PackingBytes(unsigned char *array, struct StructPack *message)
{
    //Hago una or con cada uno de los bytes del array (desplazando su pocision) para convinarlos
    message->word1 = (unsigned long)array[0] | ((unsigned long)array[1] << 8) | ((unsigned long)array[2] << 16) | ((unsigned long)array[3] << 24);
    message->byte = array[4];
    message->hword1 = (unsigned long)array[5] | ((unsigned long)array[6] << 8);
    message->word2 = (unsigned long)array[7] | ((unsigned long)array[8] << 8) | ((unsigned long)array[9] << 16) | ((unsigned long)array[10] << 24);
}