 #include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Lista_Livros{
    struct Lista_Livros *inicio;
    int tam;
}Lista_Livros;

typedef struct Lista_Usuarios{
    struct Lista_Usuarios *primeiro_usuario;
    int tam;
}Lista_Usuarios;

typedef struct Lista_Reservas{
    struct Lista_Reservas *inicio;
    int tam;
}Lista_Reservas;

typedef struct Autor{
    char nomeA[100],instituicao[100];   
}Autor; //?????

typedef struct Livro{
    int idlivro, ano, edicao;
    char tituloLivro[100], editora[100];
    struct Livro *proximoLivro;
    Autor nome;
}Livro;
typedef struct Usuario{
    int idUser, telefone;
    char nomeUser[100],endereco[200];
    struct Usuario *proximoUsuario; // 
}Usuario;

typedef struct Reserva{
    int dataInicio, dataFim;
    Usuario idUser;
    Livro idLivro;
    struct Reserva *proximoReserva;
}Reserva;

void IncluirLivro(Lista_Livros *biblioteca, int idLivro, int ano, int edicao, char titulo[], char editora[]){
    Livro *novolivro, *aux; // ele é ponteiro pra usarmos alocação dinamica
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

    novousuario->proximoUsuario=NULL; // quando cria um usuario, eu tenho  certeza que ele é o ultimo ate então, por isso o proximo é nulo;


   if(caderno->primeiro_usuario == NULL){
        caderno->primeiro_usuario = novousuario;
    }else{
        usuario = caderno->primeiro_usuario;
        while(usuario->proximoUsuario !=NULL){
            usuario=usuario->proximoUsuario;
        }
        usuario->proximoUsuario = novousuario; // agora qu eu sei que o proximo usuario está vazio por conta do loop eu posso escrever um novo;
    }
    caderno->tam++;
}

/*for(int i=1; i<biblioteca->tam; i++){ TESTAR DEPOIS
            biblioteca+=i;
        }
        biblioteca->inicio->*/

int main(){
    
    int *num;

    return 0;
}