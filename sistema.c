#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[50];
    int telefone;
} contatos;

void menu(){
    printf("\n---MENU---\n");
    printf("Escolha uma opção:\n");
    printf("1)Cadastrar contatos\n2)Buscar contatos\n3)Remover contatos\n4)Listar contatos\n5)Sair");

}

void cadastrarContatos(contatos *p, int quantidade, int inicio){

   for (int i = 0; i < quantidade; i++){
    printf("Insira o nome do contato [%d]: ", i + 1);
    scanf("%s", p[i].nome);
    printf("Insira o telefone do contato [%d]: ", i + 1);
    scanf("%d", &p[i].telefone);
    inicio++; 
    }
}

int buscarContato(contatos *p, int quantidade){} //FALTA FAZER

void listarContatos(contatos *p, int quantidade){

     for (int i = 0; i < quantidade; i++){
        printf("nome [%d]: %s ,telefone [%d]: %d\n", i + 1, p[i].nome, i + 1, p[i].telefone);
    }
}



int main() {
   int opcao, quantidade, inicio = 0;
   contatos *p  = malloc(sizeof(contatos));

  do{
   menu();
   scanf("%d", &opcao);


   switch(opcao){
    case 1:
        printf("\n---CADASTRO DE CONTATOS---\n");
        printf("Insira quantos contatos deseja cadastrar: ");
        scanf("%d", &quantidade);

        cadastrarContatos(p, quantidade, inicio);
        break;

    case 4:
        printf("\n---LISTAR DE CONTATOS---\n");
        listarContatos(p, quantidade);
        break;

   }

 }while(opcao != 5);

    return 0;
}