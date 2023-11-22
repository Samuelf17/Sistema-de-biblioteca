#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct Autor{
    char nomeA[100],instituicao[100];   
}Autor; //?????

typedef struct Livro{
    int idlivro, ano, edicao;
    char tituloLivro[100], editora[100];
    struct Livro *proximoLivro;
    Autor nome;
}Livro;

typedef struct Lista_Livros{
    struct Livro *inicio;
    int tam;
}Lista_Livros;

typedef struct Usuario{
    int idUser, telefone;
    char nomeUser[100],endereco[200];
    struct Usuario *proximoUsuario; // 
}Usuario;

typedef struct Lista_Usuarios{
    struct Usuario *primeiro_usuario;
    int tam;
}Lista_Usuarios;

typedef struct Reserva{
    int dataInicio, dataFim;
    Usuario idUser;
    Livro idLivro;
    struct Reserva *proximoReserva;
}Reserva;

typedef struct Lista_Reservas{
    struct Reserva *inicio;
    int tam;
}Lista_Reservas;

void IncluirLivro(Lista_Livros *biblioteca, int idLivro, int ano, int edicao, char titulo[], char editora[]){
    Livro *novolivro, *aux; // ele ?? ponteiro pra usarmos aloca????o dinamica
    novolivro = malloc(sizeof(Livro));

    novolivro->idlivro = idLivro;
    novolivro->ano = ano;
    novolivro->edicao = edicao;
    strcpy(novolivro->tituloLivro,titulo);
    strcpy(novolivro->tituloLivro,titulo);
    novolivro->proximoLivro=NULL;

    if(biblioteca->inicio==NULL){
        biblioteca->inicio=novolivro;
    }else{
        aux = biblioteca->inicio;

        while(aux->proximoLivro!=NULL){
            aux = aux->proximoLivro;
        }
        aux->proximoLivro = novolivro;
    }
    biblioteca->tam++;
}   

void IncluirUsuario(Lista_Usuarios *caderno, int idUser, int telefone, char NomeUser[],char endereco[] ){
    Usuario *novousuario , *usuario;
    novousuario=malloc(sizeof(Usuario));

    novousuario->idUser = idUser;
    novousuario->telefone=telefone;
    strcpy(novousuario->nomeUser,NomeUser);
    strcpy(novousuario->endereco,endereco);

    novousuario->proximoUsuario=NULL; // quando cria um usuario, eu tenho  certeza que ele ?? o ultimo ate ent??o, por isso o proximo ?? nulo;


   if(caderno->primeiro_usuario == NULL){
        caderno->primeiro_usuario = novousuario;
    }else{
        usuario = caderno->primeiro_usuario;
        while(usuario->proximoUsuario !=NULL){
            usuario=usuario->proximoUsuario;
        }
        usuario->proximoUsuario = novousuario; // agora qu eu sei que o proximo usuario est?? vazio por conta do loop eu posso escrever um novo;
    }
    caderno->tam++;
}

int main(){
    setlocale(LC_ALL,"Portuguese");
    int num=1;

    while(num != 5){
        printf("Menu:\n");
        printf("1.Usuário\n");
        printf("2.Livro\n");
        printf("3.Reserva\n");
        printf("4.Relatórios\n");
        printf("5.Sair\n");
        printf("Digite a opção que você deseja: ");
        scanf(" %d", &num);
        switch(num){
            case 1:
                system("cls");
                /*IDEIA QUE EU QUERO MELHORAR:
                    Usar outro switch case para as opções de Inclusão, alteração e exclusão de usuário, livros e reservas
                    Obs: Essa ideia não me agrada kkkkkkkkkkkkkk
                */
                break;
            case 2:
                system("cls");
                break;
            case 3:
                system("cls");
                break;
            case 4:
                system("cls");
                break;
            case 5:
                break;
            default:
                printf("A opcao desejada nao existe.\nPor favor digite uma das opcoes do menu.");
        }
    }

    return 0;
}