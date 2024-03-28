#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 10 //define constante =10

void listar();
void cadastrar();

char descricao[N][100];//linhas qtd de elementos; coluna qtd caract
float preco[N];
int quantidade[N];
int codigo[N];
int cont = 0; //qtd de elementos cadastrados

void main(){
    int menu;
    do{
        system("cls");
        printf("======ESTOQUE======\n\n");
        printf("1 - Cadastrar\n");
        printf("2 - Listar\n");
        printf("0 - Sair\n");
        printf(">>> ");
        scanf("%d", &menu);

        switch (menu){
        case 1:
            cadastrar();
            break;
        case 2:
            listar();
            break;
        case 0:
            break;
        default:
            printf("Opcao Invalida!");
        }
    }while (menu != 0);
    
}//fim do main


void listar(){
    system("cls");
    int i;
    printf("\n-----LISTAGEM DE PRODUTOS-----\n");
    for(i=0;i<cont;i++){
        printf("CODIGO: %d\n", codigo[i]);
        printf("DESCRICAO: %s\n", descricao[i]);
        printf("PRECO: %.2f\n", preco[i]);
        printf("QUANTIDADE: %d\n", quantidade[i]);
        printf("\n--------------------------------\n");
    }
    system("Pause");
}

void cadastrar(){
    system("cls");
    fflush(stdin);//limpa o banco do teclado
    if(cont < N){
        char d[100];
        float p;
        int q;
        printf("DESCRICAO: ");
        gets(d);
        printf("PRECO: ");
        scanf("%f", &p);
        printf("QUANTIDADE: ");
        scanf("%d", &q);

        preco[cont] = p;
        quantidade[cont] = q;
        strcpy(descricao[cont], d);//pega td vetor d e copia para descrição

        codigo[cont] = cont + 1;
        cont++;
        printf("\nCadastrado com Sucesso!\n");
    }else{
        printf("Memoria Cheia!");
    }
    system("pause");
}//fim função cadastrar