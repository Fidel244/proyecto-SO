#include<stdio.h>
#include<stdlib.h>


unsigned short int verificar_salir(char comando[]){
    char string_salir[] = "salir";
    unsigned short int i;
    for(i=0; comando[i]==string_salir[i]; i++){}
    return i;
}

void capturar_comando(){
    char x, linea[100];
    int i;
    i=0;
    while(1){
        x=getc(stdin);
        if(x==EOF) {
            puts("Hasta luego amigo...");
            break;
        }else if(x=='\n'){
            if(i == 5 && verificar_salir(linea)==5){
                puts("Hasta luego amigo..."); break;
            } 
            printf("%s se han leido %hi caracteres\n", linea, verificar_salir(linea));
        }
        linea[i]=x;
        i++;
    }
}


int main(){
    capturar_comando();
    return 0;
}