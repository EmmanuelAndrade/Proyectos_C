#include <stdio.h>

unsigned char average(unsigned char *array, unsigned char size);
void arrayCopy(unsigned char *arrayA, unsigned char *arrayB, unsigned char size);
unsigned char arrayCompare(unsigned char *arrayA, unsigned char *arrayB, unsigned char size);
unsigned short largest (unsigned short *array, unsigned char size);
void sortArra(unsigned short *array, unsigned char size);
void TimeString(char *string, unsigned char hours, unsigned char minutes, unsigned char seconds);
void DateString(char *string_Date, unsigned char month, unsigned char day, unsigned short year,unsigned char weekday);

int main()
{
//Variables de prueba rapida    
    unsigned char array[5] = {1,2,3,8,0};
    unsigned char size = (sizeof array) / (sizeof array[0]);
    unsigned char arrayB[size];
    unsigned char arrayC[5] = {1,2,3,4,5};
    unsigned short arrayD[5] = {4,2,8,1,7};
    unsigned char size_short = (sizeof arrayD) / (sizeof arrayD[0]);
//Variables de prueba (Casio_Hora)
    char string[9] = {NULL,NULL,':',NULL,NULL,':',NULL,NULL,NULL};
    unsigned char hours=23;
    unsigned char minutes=59;
    unsigned char seconds=59;
//Variables de prueba (Casio_Fecha)
    char string_Date[15] ={NULL,NULL,NULL,' ',NULL,NULL,',',NULL,NULL,NULL,NULL,' ',NULL,NULL,NULL};
    unsigned char month = 2; 
    unsigned char day = 29; 
    unsigned short year = 1996;
    unsigned char weekday = 3;

//1.- Funcion que regresa el promedio de un arreglosize_t
    //char promedio = average(array,size);
    //printf("%d \n",promedio);
//2.- Function that copies an array to another array    
    //arrayCopy(array,arrayB,size);
//3.- Function to compare two arrays
    //unsigned char Diferentes = arrayCompare(array,arrayC,size);  
    //printf("%d \n",Diferentes);
//4.-Function to get the lasrgest number in a given array
    //unsigned char Numero_Mayor = largest(arrayD,size_short);
    //printf("%d \n",Numero_Mayor);   
//5.-Function to sort an array of a given size
    //sortArra(arrayD,size_short);   
//6.-Function to convert time to a string representation
    //TimeString(string,hours,minutes,seconds);
//7.-Function to convert Date to a string representation    
DateString(string_Date, month, day, year, weekday);
    
    return 0;
}
//1.- Funcion que regresa el promedio de un arreglo
unsigned char average(unsigned char *array, unsigned char size)
{
    char Suma = 0;
    char Promedio = 0;
    for (int i = 0; i < size; i++)
    {
       Suma = Suma + array[i]; 
    }
    Promedio = Suma/size;
    return Promedio;
}

//2.- Function that copies an array to another array
void arrayCopy(unsigned char *arrayA, unsigned char *arrayB, unsigned char size)
{
    for (int i = 0; i < size; i++)
    {
        arrayB[i] = arrayA[i];
    }
    
    for (int i = 0; i < size; i++)
    {
        printf("%d",arrayA[i]);
    }
    printf("\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d",arrayB[i]);
    }    
}

//3.- Function to compare two arrays
unsigned char arrayCompare(unsigned char *arrayA, unsigned char *arrayB, unsigned char size)
{
    int distintos = 0;
    for (int i = 0; i < size; i++)
    {
        if (arrayA[i]!=arrayB[i])
        {
            i=size;
            distintos = 1;
        }      
    }
    return distintos;
}

//4.-Function to get the lasrgest number in a given array
unsigned short largest (unsigned short *array, unsigned char size)
{
    unsigned char Mayor = 0;
    unsigned char memory;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (array[i]<array[j])
            {
                memory = array[j];
                array[j] = array[i];
                array[i] = memory;
            }
        }    
    }
    Mayor = array[size-1];
    return Mayor;
}

//5.-Function to sort an array
void sortArra(unsigned short *array, unsigned char size)
{
    unsigned char memory;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (array[i]<array[j])
            {
                memory = array[j];
                array[j] = array[i];
                array[i] = memory;
            }
        }    
    }
    for (int i = 0; i < size; i++)
    {
        printf("%d", array[i]);
    }
    printf("\n");
}

//Function to convert time to a string representation
void TimeString(char *string, unsigned char hours, unsigned char minutes, unsigned char seconds)
{ 
    int Error=0;
    //hours to strings
    if (hours>=0 && hours<=23)
    {
        string[0]= (hours/10)+48;
        string[1]= (hours%10)+48;
    }else{
        Error=1;
    }
    //minutes to strings
    if (minutes>=0 && minutes<=59)
    {
        string[3]= (minutes/10)+48;
        string[4]= (minutes%10)+48;
    }else{
        Error=1;
    }
    //minutes to strings
    if (seconds>=0 && seconds<=59)
    {
        string[6]= (seconds/10)+48;
        string[7]= (seconds%10)+48;
    }else{
        Error=1;
    }

    if (Error==1)
    {
        printf("Formato de Hora no valido");
    }else{
    for (int i = 0; i < 9; i++)
    {   
        printf("%c",string[i]);
    }        
    }    
}
//7.-Funtion to conver date to a string representation
void DateString(char *string_Date, unsigned char month, unsigned char day, unsigned short year,unsigned char weekday){
        int Error=0;
        int N_dias=0; // 0 = 31, 1=30, 2 = Febrero
        int F=0;
    //Year to strings
    if (year>=0 && year<=9999 && year%4==0)
    {
        F=1;
        string_Date[7]= (year/1000)+48;
        year = year-((year/1000)*1000);
        string_Date[8]= ((year/100)+48);
        year = year-((year/100)*100);
        string_Date[9]= (year/10)+48;
        string_Date[10]= (year%10)+48;
    }else
    {
        F=0;
        string_Date[7]= (year/1000)+48;
        year = year-((year/1000)*1000);
        string_Date[8]= ((year/100)+48);
        year = year-((year/100)*100);
        string_Date[9]= (year/10)+48;
        string_Date[10]= (year%10)+48;
    }

    //month to strings
    if (month>=1 && month<=12)
    {
        switch (month)
        {
        case 1:
            string_Date[0] ='J';
            string_Date[1] ='a';
            string_Date[2] ='n';
            N_dias=0;
            break;
        case 2:
            string_Date[0] ='F';
            string_Date[1] ='e';
            string_Date[2] ='b';
            N_dias=2;
            break;
        case 3:
            string_Date[0] ='M';
            string_Date[1] ='a';
            string_Date[2] ='r';
            N_dias=0;
            break;
        case 4:
            string_Date[0] ='A';
            string_Date[1] ='p';
            string_Date[2] ='r';
            N_dias=1;
            break;
        case 5:
            string_Date[0] ='M';
            string_Date[1] ='a';
            string_Date[2] ='y';
            N_dias=0;
            break;
        case 6:
            string_Date[0] ='J';
            string_Date[1] ='u';
            string_Date[2] ='n';
            N_dias=1;
            break;
        case 7:
            string_Date[0] ='J';
            string_Date[1] ='u';
            string_Date[2] ='l';
            N_dias=0;
            break;
        case 8:
            string_Date[0] ='A';
            string_Date[1] ='u';
            string_Date[2] ='g';
            N_dias=0;
            break;
        case 9:
            string_Date[0] ='S';
            string_Date[1] ='e';
            string_Date[2] ='p';
            N_dias=1;
            break;
        case 10:
            string_Date[0] ='O';
            string_Date[1] ='c';
            string_Date[2] ='t';
            N_dias=0;
            break;
        case 11:
            string_Date[0] ='N';
            string_Date[1] ='o';
            string_Date[2] ='v';
            N_dias=1;
            break;
        case 12:
            string_Date[0] ='D';
            string_Date[1] ='e';
            string_Date[2] ='c';
            N_dias=0;
            break;       
        }
    }else{
        Error=1;
    }

    //Day to strings
    switch (N_dias)
    {
    case 0:
        //31 days
        if (day>=1 && day<=31)
        {
            string_Date[4]= (day/10)+48;
            string_Date[5]= (day%10)+48;
        }else{
            Error=1;
        }
        break;
    case 1:
    //30 days
        if (day>=1 && day<=30)
        {
            string_Date[4]= (day/10)+48;
            string_Date[5]= (day%10)+48;
        }else{
            Error=1;
        }
        break;
    case 2:
        //Febrary 
        if (F==0)
        {   
            if (day>=1 && day<=28)
            {
                string_Date[4]= (day/10)+48;
                string_Date[5]= (day%10)+48;
            }else{
                Error=1;
            }
        }
        //Febrary B
        if (F==1)
        {   
            if (day>=1 && day<=29)
            {
                string_Date[4]= (day/10)+48;
                string_Date[5]= (day%10)+48;
            }else{
                Error=1;
            }
        }

        break;
    }

    //Weekday
    if (weekday>=1 && weekday<=7)
    {
        switch (weekday)
        {
        case 1:
            string_Date[12] ='L';
            string_Date[13] ='u';
            break;
        case 2:
            string_Date[12] ='M';
            string_Date[13] ='a';
            break;
        case 3:
            string_Date[12] ='M';
            string_Date[13] ='i';
            break;
        case 4:
            string_Date[12] ='J';
            string_Date[13] ='u';
            break;
        case 5:
            string_Date[12] ='V';
            string_Date[13] ='i';
            break;
        case 6:
            string_Date[12] ='S';
            string_Date[13] ='a';
            break;
        case 7:
            string_Date[12] ='D';
            string_Date[13] ='o';
            break;       
        }
    }else{
        Error=1;
    }
//Printf
    if (Error==1)
    {
        printf("Formato de Fecha no valido");
    }else{
    for (int i = 0; i < 15; i++)
    {   
        printf("%c",string_Date[i]);
    }        
    } 
}