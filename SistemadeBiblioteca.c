#include <stdio.h>
typedef struct{
    
}Biblioteca;

typedef struct Autor{
    char nomeA[100],instituicao[100];   
}Autor;

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

void IncluirLivro(){
    int inclusao;
}

int main(){

    return 0;
}