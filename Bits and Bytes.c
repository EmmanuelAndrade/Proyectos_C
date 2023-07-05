#include <stdio.h>

void printb( unsigned char byte );
unsigned char ShiftBitRight(unsigned char byte, unsigned char shift);
unsigned char ShiftBitLeft(unsigned char byte, unsigned char shift);
unsigned char SetBitMask(unsigned char byte, unsigned char shift);
unsigned char ClearBitMask(unsigned char byte, unsigned char mask);
unsigned char ToggleBitMask(unsigned char byte, unsigned char mask);
unsigned char SetBit(unsigned char byte, unsigned char bit);
unsigned char ClearBit(unsigned char byte, unsigned char bit);
unsigned char ToggleBit(unsigned char byte, unsigned char bit);
unsigned char GetBit(unsigned char byte, unsigned char bit);


int main()
{


/*El valor de la variable "var" unicamente puede ser de 8 bits*/
    unsigned char var = 0x40;
    unsigned char mask = 0x0A;
/*Impresion de la funcion 0*/    
    printb(var);
    printb(mask);
/*Impresion de la funcion 1*/  
    //var=ShiftBitRight(var,1);
    //printb(var);
/*Impresion de la funcion 2*/  
    //var=ShiftBitLeft(var,2);
    //printb(var);
/*Impresion de la funcion 3*/  
    //var=SetBitMask(var,mask); 
    //printb(var); 
/*Impresion de la funcion 4*/  
    //var=ClearBitMask(var,mask);
    //printb(var);  
/*Impresion de la funcion 5*/  
    //var=ToggleBitMask(var,mask);
    //printb(var);
/*Impresion de la funcion 6*/
/*El valor entero debe estar en rango de 0 a 7*/  
    //var=SetBit(var, 7);  
    //printb(var);  
/*Impresion de la funcion 7*/  
    //var=ClearBit(var,6);
    //printb(var);
/*Impresion de la funcion 8*/  
    //var=ToggleBit(var,6);
    //printb(var);
/*Impresion de la funcion 9*/  
    var=GetBit(var,7);
    printb(var);

    return 0;
} 
/* 0.- Funcion que recibe un numero de 8 bits y regresa su velor en binario*/
void printb( unsigned char byte )
{
    char binario[8]={0,0,0,0,0,0,0,0};
    int i=0;
    while (byte>0)
    {
       binario[i]= byte%2;
       i++;
       byte = byte/2;
    }
    printf("0b");
    for (int i = 7; i >= 0; i--)
    {
        printf("%d", binario[i]);
    }
    printf("\n");

}
/*1.-Funcion que rota a la derecha los bits de una variable*/
unsigned char ShiftBitRight(unsigned char byte, unsigned char shift)
{
    char binario[8]={0,0,0,0,0,0,0,0};
    unsigned char Memoria=byte;
    int rango=0;
    int i=7;
    while (byte>0)
    {
       binario[i]= byte%2;
       if(binario[i]==1){
        byte=0;
       }else{
        rango++; 
       }
       i--;
       byte = byte/2;

    }
    
    if(shift<=rango)
    {
        Memoria = Memoria>>shift;
        return Memoria;
    }else{
        return Memoria;
    }
}

/*2.-Funcion que rota a la izquierda los bits de una variable*/
unsigned char ShiftBitLeft(unsigned char byte, unsigned char shift)
{
    char binario[8]={0,0,0,0,0,0,0,0};
    unsigned char Memoria=byte;
    int rango=0;
    int j=0;
    int i=7;
    while (byte>0)
    {
       binario[i]= byte%2;
       i--;
       byte = byte/2;
    }
    while (j<=7)
    {
        if(binario[j]==1){
            j=8;
        }else{
            rango++; 
        }
        j++;
    }
    
    
    if(shift<=rango)
    {
        Memoria = Memoria<<shift;
        return Memoria;
    }else{
        return Memoria;
    }
}
/*3.-Funcion que coloca en 1 los bits deacuerdo a la mascara*/
unsigned char SetBitMask(unsigned char byte, unsigned char mask)
{
    unsigned char New_Var = byte|mask;
    return New_Var;
} 
/*4.-Funcion que coloca en 0 los bits deacuerdo a la mascara*/
unsigned char ClearBitMask(unsigned char byte, unsigned char mask)
{
    unsigned char New_Var = ~byte | mask;
    New_Var=~New_Var;
    return New_Var;
} 
/*5.-Funcion que invierte los bits deacuerdo a la mascara*/
unsigned char ToggleBitMask(unsigned char byte, unsigned char mask)
{
    unsigned char New_Var = byte ^ mask;
    return New_Var;
} 
/*6.-Funcion que pone en 1 un determinado bit deacuerdo a una constante entre 0 y 7*/
unsigned char SetBit(unsigned char byte, unsigned char bit)
{
    char mask=0x01;
    if (bit>=0 && bit<=7)
    {
        byte = byte | (mask<<bit);
        return byte;
    }else{
        return byte;
    }   
}
/*7.-Funcion que pone en 0 un determinado bit deacuerdo a una constante entre 0 y 7*/
unsigned char ClearBit(unsigned char byte, unsigned char bit)
{
    char mask=0x01;
    if (bit>=0 && bit<=7)
    {
        byte = byte & ~(mask<<bit);
        return byte;
    }else{
        return byte;
    }   
}
/*8.-Funcion que pone invierte un determinado bit deacuerdo a una constante entre 0 y 7*/
unsigned char ToggleBit(unsigned char byte, unsigned char bit)
{
    char mask=0x01;
    if (bit>=0 && bit<=7)
    {
        byte = byte ^ (mask<<bit);
        return byte;
    }else{
        return byte;
    }   
}
/*9.-Funcion que pone regresa el valor de un determinado bit deacuerdo a una constante entre 0 y 7*/
unsigned char GetBit(unsigned char byte, unsigned char bit)
{
    char binario[8]={0,0,0,0,0,0,0,0};
    char Memoria= byte;
    int i=0;
    while (byte>0)
    {
       binario[i]= byte%2;
       i++;
       byte = byte/2;
    }
    if (bit>=0 && bit<=7)
    {
        return binario[bit];
    }else{
        return Memoria;
    }   
}