#include<stdio.h>
#include<time.h>
#include <stdlib.h>
#include<math.h>
#include <string.h>



int binario(int nro);
int octal(int nro);
char* hexadecimal(int decimal);
int binarioDecimal(int binario);
int OctalToDecimal(int numero);
int HexadecimalToDecimal(char* hex);
long long HexadecimalDecimal(char* hex);

int main(){
 int i,numero,li=300,ls=999,b,o;
 char* h;
 
 srand(time(NULL));

 puts("");
  for(i=1;i<=10;i++){

  numero = rand()%(ls-li+1) + li;
  
  printf("\n Numero: %d --> %i \n",i,numero);
  b=binario(numero);
  printf("\n --->binario: %d \n",b);
  o=octal(numero);
  printf("\n --->octal: %d \n",o);
  h=hexadecimal(numero);
  printf(" \n ---> numero hexa: %s \n",h);
  
  printf(" \n----- Conversión-----\n");
  
  printf(" \n ---> Binario %d de %i  \n",b,numero);
  binarioDecimal(b);
   printf(" \n ---> Octal %d de %i \n",o,numero);
  OctalToDecimal(o);
   printf(" \n --->Hexadecimal %s de %i \n",h, numero);
  HexadecimalToDecimal(h);
   printf(" \n --->Hexadecimal Alternativo %s de %i \n",h, numero);
  HexadecimalDecimal(h);
  
  } 
  
  

}
int binario(int nro){
int binario = 0,
  position = 1;
 while(nro > 0){
  binario = binario + (nro%2)*position;
  nro /=2;
  position *= 10;
 }
return binario;
}
	 

int octal(int nro){
int octal = 0,
  position = 1;
 while(nro > 0){
  octal = octal + (nro%8)*position;
  nro /=8;
  position *= 10;
 }
return octal;
}

char* hexadecimal(int decimal){
	
	char hexa[8];
	char hex[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
	int i=0;
	while(decimal>16){
		hexa[i]=hex[decimal%16];
		decimal=decimal/16;
		i++;
	}
	
	hexa[i]=hex[decimal];
	int j=0;

	char* aux;
	
	for(j=0;j<=i;j++)
  {
    aux[i-j]=hexa[j];
    
   }
   
  return aux;
	
}
int binarioDecimal(int numero){

int valor = 0, digito, total=0,muestra;
	int temp=numero;
	while (numero > 0)
	{
		digito = numero%10;	
		printf ("\n Residuo:  %d \n", digito);
		numero/=10;	
		printf ("\n Division:  %d \n", numero);
		muestra=digito * (int)pow(2,valor);
		printf ("\n Multiplicación:  %d potencia %d \n", muestra,valor);
		total+=digito * (int)pow(2,valor);
		printf ("\n Total:  %d \n", total);
		valor++;
	}
		printf ("\nEl numero %d(2) es %d(10) \n",temp,total);
	return total;
}

int OctalToDecimal(int numero)
{
	int valor = 0, digito, total=0;
	int temp=numero;
	int muestra;
	while (numero > 0)
	{
		digito = numero%10;	
		printf ("\n Residuo:  %d \n", digito);
		numero/=10;	
		printf ("\n Division:  %d \n", numero);
		muestra=digito * (int)pow(8,valor);
		printf ("\n Multiplicación:  %d potencia %d \n", muestra,valor);
		
		total+=digito * (int)pow(8,valor);
		
		printf ("\n Total:  %d \n", total);
		valor++;
	}
		printf ("\nEl numero %d(8) es %d(10) \n",temp,total);
	return total;

}

int HexadecimalToDecimal(char* hex)
{
	int digito, total=0,i=0,len, muestra;
	
	len = strlen(hex);
	
	int temp=0;
	
	while (i < len){
		
	if(hex[i]=='0')
        {
           digito=0;
            
        }
        
    else if(hex[i]=='1')
        {
           digito=1;
            
        }  
    else if (hex[i]=='2')
        {
           digito=2;
            
        } 
	else if(hex[i]=='3')
        {
           digito=3;
            
        } 
	else if (hex[i]=='4')
        {
           digito=4;
            
        } 
	else if (hex[i]=='5')
        {
           digito=5;
            
        } 
	else if (hex[i]=='6')
        {
           digito=6;
            
        } 	
	else if (hex[i]=='7')
        {
           digito=7;
            
        } 		 	 	    
    else if (hex[i]=='8')
        {
           digito=8;
            
        }   
	else if (hex[i]=='9')
        {
           digito=9;
            
        } 	  
	 else if(hex[i]=='A' || hex[i]=='a')
        {
           digito=10;
        }
    else if(hex[i]=='B' || hex[i]=='b')
        {
           digito=11;
        }
    else if(hex[i]=='C' || hex[i]=='c')
        {
           digito=12;
        } 
	 else if(hex[i]=='D' || hex[i]=='d')
        {
           digito=13;
        }
	else if(hex[i]=='E' || hex[i]=='e')
        {
           digito=14;
        }	
	 else if(hex[i]=='F' || hex[i]=='F')
        {
           digito=15;
        }	   
	
	printf(" \n numero digito: %d \n",digito);
	
	muestra=digito * (int)pow(16,i);
	printf ("\n Multiplicación:  %d potencia %d \n", muestra,i);
	    
	total+= digito * (int)pow(16,i);
	printf(" \n Total: %d \n",total);
	
		i++;
	}
	
	printf ("\nEl numero %s(16) es %d(10) \n",hex,total);

	return total;
	}



long long HexadecimalDecimal(char* hex){

    long long decimal;
    int i = 0, val, len;
 
    decimal = 0;
   
 
 
    len = strlen(hex);
    len--;
 
   
    for(i=0; hex[i]!='\0'; i++)
    {
 
        if(hex[i]>='0' && hex[i]<='9')
        {
            val = hex[i] - 48;
        }
        else if(hex[i]>='a' && hex[i]<='f')
        {
            val = hex[i] - 97 + 10;
        }
        else if(hex[i]>='A' && hex[i]<='F')
        {
            val = hex[i] - 65 + 10;
        }
 
        decimal += val * pow(16, len);
        len--;
    }
 
   
 	printf ("\nEl numero %s(16) es %d(10) \n",hex,decimal);
    return decimal;
}




