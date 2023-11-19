#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
typedef struct Lista_Livros{
    struct Lista_Livros *inicio;
    int tam;
}Lista_Livros;

typedef struct Lista_Usuarios{
    struct Lista_Usuarios *inicio;
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
    Autor nome;
}Livro;
typedef struct Usuario{
    int idUser, telefone;
    char nomeUser[100],endereco[200];

}Usuario;

typedef struct Reserva{
    int dataInicio, dataFim;
    Usuario idUser;
    Livro idLivro;
}Reserva;

void IncluirLivro(Lista_Livros *livro, int idLivro, int ano, int edicao, char titulo[], char editora[]){
    Livro *novolivro; // ele é ponteiro pra usarmos alocação dinamica
    novolivro = malloc(sizeof(Livro));

    novolivro->idlivro = idLivro;
    novolivro->ano = ano;
    novolivro->edicao = edicao;
    strcpy(novolivro->tituloLivro,titulo);
    strcpy(novolivro->tituloLivro,titulo);
    
}   

int main(){

    return 0;
}