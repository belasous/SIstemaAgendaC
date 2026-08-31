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

void cadastrarContatos(contatos *p, int quantidade, int totalcadastrado){

        //iniciando o loop a partir do total de contatos já cadastrados
        //totalcadastrado + quantidade é o total de contatos que serão cadastrados


   for (int i = totalcadastrado; i < totalcadastrado + quantidade; i++){ 
    printf("Insira o nome do contato [%d]: ", i + 1);
    scanf("%49s", p[i].nome);
    printf("Insira o telefone do contato [%d]: ", i + 1);
    scanf("%d", &p[i].telefone);
    
    }
}


void listarContatos(contatos *p, int totalcadastrado){

     for (int i = 0; i < totalcadastrado; i++){
        printf("nome [%d]: %s ,telefone [%d]: %d\n", i + 1, p[i].nome, i + 1, p[i].telefone);
    }
}

int buscarContatos(contatos *p, int quantidade, int totalcadastrado, char *nomebusca){

    for(int i = 0; i < totalcadastrado; i++){
        if(strcmp(p[i].nome, nomebusca) == 0){
            return i; //retorna o índice do contato encontrado
        }
    }

}

int main() {
   int opcao, quantidade, totalcadastrado = 0, indicebusca = 0;
   contatos *p  = malloc(sizeof(contatos));
   char nomebusca[50];

  do{
   menu();
   scanf("%d", &opcao);


   switch(opcao){
    case 1:
        printf("\n---CADASTRO DE CONTATOS---\n");
        printf("Insira quantos contatos deseja cadastrar: ");
        scanf("%d", &quantidade);

        p = realloc(p, (totalcadastrado + quantidade) * sizeof(contatos)); //realocando memória para o vetor de contatos

        cadastrarContatos(p, quantidade,totalcadastrado);
        totalcadastrado += quantidade; //atualizando o total de contatos cadastrados
        break;

    case 2:
        printf("\n---BUSCAR CONTATOS---\n");

        printf("Insira o nome do contato que deseja buscar: ");
        scanf("%49s", nomebusca); 

        indicebusca = buscarContatos(p, quantidade, totalcadastrado, nomebusca);

        if(indicebusca != -1){
            printf("Contato encontrado: nome: %s, telefone: %d\n", p[indicebusca].nome, p[indicebusca].telefone);
        }
        break;

    case 4:
        printf("\n---LISTAR DE CONTATOS---\n");
        listarContatos(p, totalcadastrado);
        break;

   }

 }while(opcao != 5);

    return 0;
}