#include <stdio.h>
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

int main(){

    return 0;
}