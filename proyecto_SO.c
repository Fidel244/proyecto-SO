#include<stdio.h>
#include<stdlib.h>


unsigned short int verificar_salir(char comando[]){
    char string_salir[5] = "salir";
    unsigned short int i;
    for(i=0; i<5; i++)
        if(comando[i]!=string_salir[i]) return i;
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
            if(i == verificar_salir(linea)){
                puts("Hasta luego amigo..."); break;
            } 
            printf("%s se han leido %hi caracteres\n", linea, i);
        }else {
        linea[i]=x;
        i++;}
    }
}


int main(){
    capturar_comando();
    return 0;
}