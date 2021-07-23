#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>
#include<string.h>
#include<sys/wait.h>

// PROYECTO 1 DE SISTEMAS OPERATIVOS  2021-U
// ALUMNO: FIDEL RAFAEL SERPA GONZALEZ      ID: 26476320

void salir(){
    puts("Hasta luego amigo...");
    exit(0);
}


unsigned short int verificar_salir(char comando[]){
    char string_salir[5] = "salir";
    unsigned short int i;
    for(i=0; i<5; i++)
        if(comando[i]!=string_salir[i]) return i;
    return i;
}


void verificacion_y_ejecucion(char *linea){

    //puts("Exito?");
    //aqui se deben hacer algunas validaciones
    pid_t pid;
    pid = fork();
    if(pid < 0) puts("Hubo un fallo al crear el proceso hijo...");
    else if(pid==0){ // ejecucion del proceso hijo
        puts("Soy el proceso hijo...");
        printf("Combroando linea de comandos recibida: %s\n", linea);
        puts("voy a terminar...");
        exit(0);
    }else{ //el proceso padre espera
        wait(NULL);
        puts("Proceso padre: mi hijo termino su ejecucion!");
    }

}

void capturar_comando(){
    char x;
    int i;
    i=0;
    char *linea = malloc(sizeof(char) *256);
    if (signal(SIGINT, &salir) == SIG_ERR) return;
    printf(">");
    while(1){
        x=getc(stdin);
        if(x=='\n'){
            if(i == verificar_salir(linea)){
                puts("Hasta luego amigo...");
                exit(0);
            } 
            printf("%s se han leido %hi caracteres\n", linea, i);
            verificacion_y_ejecucion(linea);
            free(linea);
            char *linea = malloc(sizeof(char) *256);
            i = 0;
            printf(">");
        }else {
        linea[i]=x;
        i++;
        }
        fflush(stdin);
    }
}


int main(void){
    capturar_comando();
    return 0;
}