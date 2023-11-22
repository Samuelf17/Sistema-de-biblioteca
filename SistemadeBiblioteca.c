#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct Autor{
    char nomeA[100],instituicao[100];   
    struct Autor *proximoAutor;
}Autor; //?????

typedef struct Lista_Autor{
    Autor *inicioautor;
    int tam;

}Lista_Autor;
typedef struct Livro{
    int idlivro, ano, edicao;
    char tituloLivro[100], editora[100];
    struct Livro *proximoLivro;
}Livro;

typedef struct Lista_Livros{
    struct Livro *primeiroLivro;
    int tam;
}Lista_Livros;

typedef struct Usuario{
    int idUser;
    char nomeUser[100],endereco[200],telefone[15];
    struct Usuario *proximoUsuario;
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
    struct Reserva *primeiraReserva;
    int tam;
}Lista_Reservas;

void IncluirLivro(Lista_Livros *biblioteca, int idLivro, int ano, int edicao, char titulo[], char editora[]){
    Livro *novolivro, *aux; // ele � ponteiro pra usarmos aloca��o dinamica
    novolivro = malloc(sizeof(Livro));

    novolivro->idlivro = idLivro;
    novolivro->ano = ano;
    novolivro->edicao = edicao;
    strcpy(novolivro->tituloLivro,titulo);
    strcpy(novolivro->tituloLivro,titulo);
    novolivro->proximoLivro=NULL;

    if(biblioteca->primeiroLivro==NULL){
        biblioteca->primeiroLivro=novolivro;
    }else{
        aux = biblioteca->primeiroLivro;

        while(aux->proximoLivro!=NULL){
            aux = aux->proximoLivro;
        }
        aux->proximoLivro = novolivro;
    }
    biblioteca->tam++;
}   

void iniciarListaUsuario(Lista_Usuarios *caderno){
    caderno->primeiro_usuario = NULL;
    caderno->tam = 0;
}

void IncluirUsuario(Lista_Usuarios *caderno, int idUser, char telefone[], char NomeUser[],char endereco[] ){
    Usuario *novousuario , *usuario;
    novousuario=malloc(sizeof(Usuario));
    if(novousuario){
        novousuario->idUser = idUser;
        strcpy(novousuario->telefone,telefone);
        strcpy(novousuario->nomeUser,NomeUser);
        strcpy(novousuario->endereco,endereco);

        novousuario->proximoUsuario=NULL; // quando cria um usuario, eu tenho  certeza que ele � o ultimo ate ent�o, por isso o proximo � nulo;

    if(caderno->primeiro_usuario == NULL){
            caderno->primeiro_usuario = novousuario;
        }else{
            usuario = caderno->primeiro_usuario;
            while(usuario->proximoUsuario !=NULL){
                usuario=usuario->proximoUsuario;
            }
            usuario->proximoUsuario = novousuario; // agora que eu sei que o proximo usuario est� vazio por conta do loop eu posso escrever um novo;
        }
        caderno->tam++;
        printf("\nUsuario cadastrado com sucesso!\n");
    }else{
        printf("\nErro ao alocar mem�ria!\n");
    }
}

void RelatorioUsuario(Lista_Usuarios caderno){
    Usuario *usuario;
    usuario = caderno.primeiro_usuario;
    printf("Relat�rio de Usu�rios:\n\n");
    while(usuario){
        printf(" | Id: %d", usuario->idUser);
        printf(" | Nome: %s", usuario->nomeUser);
        printf(" | Endere�o: %s", usuario->endereco);
        printf(" | Telefone: %s\n", usuario->telefone);
        usuario=usuario->proximoUsuario;
    }
}

void AlterarUsuario(Lista_Usuarios *cadernoUsuario){
    int resposta;
    Usuario *novousuario;
    Usuario *aux;
    novousuario = cadernoUsuario->primeiro_usuario;

    int idAltera;
    printf("Digite a ID do usuario que deseja alterar");
    scanf("%d", &idAltera);

    while(novousuario->idUser != idAltera){
        novousuario = novousuario->proximoUsuario;
    }

    printf("O que deseja alterar? 1)Nome \n 2) Telefone \n 3)Endere�o");
    scanf("%d", &resposta);
    switch (resposta){
    case 1: 
        printf("Digite o novo nome\n");
        scanf(" %[^\n]", novousuario->nomeUser);
        break;
    case 2:
        printf("Digite o numero do novo telefone");
        scanf(" %[^\n]", novousuario->telefone);
        break;
    case 3:
        printf("Digite o novo endere�o");
        scanf(" %[^\n]", novousuario->endereco);

        break;
    default:
        printf("\nA op��o digitada n�o existe.\nPor favor digite uma das op��es do menu.");
    }
}

int main(){
    setlocale(LC_ALL,"Portuguese");
    int resMenu=1, resSubMenu, idUser=1, idLivro=1, edicaoLivro;
    char nomeUSer[50], endereco[100], nomeLivro[100], editora[50], telefone[15];
    Lista_Usuarios cadernoUsuarios;
    Lista_Livros biblioteca;

    iniciarListaUsuario(&cadernoUsuarios);

    while(resMenu != 5){
        printf("Menu:\n");
        printf("1.Usu�rio\n");
        printf("2.Livro\n");
        printf("3.Reserva\n");
        printf("4.Relat�rios\n");
        printf("5.Sair\n");
        printf("Digite a op��o que voc� deseja: ");
        scanf(" %d", &resMenu);
        switch(resMenu){
            case 1:
                system("cls");

                printf("Menu:\n");
                printf("1.Incluir usuario\n");
                printf("2.Alterar usuario\n");
                printf("3.Excluir usuario\n");
                printf("4.Voltar\n");
                printf("Digite a op��o que voc� deseja: ");
                scanf(" %d", &resSubMenu);
                
                switch(resSubMenu){
                    case 1:
                        system("cls");
                        printf("Digite o nome do usu�rio: ");
                        scanf(" %[^\n]", nomeUSer);
                        printf("Digite o endere�o do usu�rio: ");
                        scanf(" %[^\n]", endereco);
                        printf("Digite o telefone do usuario: ");
                        scanf(" %[^\n]", telefone);
                        IncluirUsuario(&cadernoUsuarios, idUser++, telefone, nomeUSer, endereco);
                        system("pause");
                        break;
                    case 2:
                        AlterarUsuario(&cadernoUsuarios);
                        system("pause");
                        break;
                    case 3:
                        break;
                    case 4:
                        break;
                    default:
                        printf("\nA op��o digitada n�o existe.\nPor favor digite uma das op��es do menu.");
                }
                break;

            case 2:
                system("cls");

                printf("Menu:\n");
                printf("1.Incluir Livro\n");
                printf("2.Alterar Livro\n");
                printf("3.Excluir Livro\n");
                printf("4.Voltar\n");
                printf("Digite a op��o que voc� deseja: ");
                scanf(" %d", &resSubMenu);

                switch(resSubMenu){
                    case 1:
                        system("cls");
                        printf("Digite o titulo do livro: ");
                        scanf(" %[^\n]", nomeLivro);

                        printf("Digite o autor do livro: "); // Ser� possivel adicionar mais de um autor;
                        
                        scanf(" %d", &telefone);
                        printf("Digite o numero de edi��o do livro ");
                        scanf(" %d", &edicaoLivro);
                        printf("Digite o nome da editoria do livro: ");
                        scanf("%[^\n]", editora);
                      //  IncluirLivro(&cadernoLivros, idLivro++, nomeLivro, edicaoLivro, editora);
                        system("pause");
                        break;
                    case 2:
                        break;
                    case 3:
                        break;
                    case 4:
                        break;
                    default:
                        printf("\nA op��o digitada n�o existe.\nPor favor digite uma das op��es do menu.");
                }
                break;
                
            case 3:
                system("cls");
                break;
            case 4:
                system("cls");

                printf("1. Relat�rio de Usu�rios\n");
                printf("2. Relat�rio de Livros\n");
                printf("3. Relat�rio de Reservas\n");
                printf("4. Voltar\n");
                printf("Digite a op��o que voc� deseja: ");
                scanf(" %d", &resSubMenu);

                switch(resSubMenu){
                    case 1:
                        system("cls");
                        RelatorioUsuario(cadernoUsuarios);
                        system("pause");
                        break;
                    case 2:
                        break;
                    case 3:
                        break;
                    case 4:
                        break;
                    default:
                        printf("\nA op��o digitada n�o existe.\nPor favor digite uma das op��es do menu.");
                }
                system("cls");
                break;
            case 5:
                printf("\nObrigado por usar o programa\n");
                break;
            default:
                printf("\nA op��o digitada n�o existe.\nPor favor digite uma das op��es do menu.");
        }
        system("cls");
    }

    return 0;
}