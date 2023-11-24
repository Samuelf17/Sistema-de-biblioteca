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
    Autor *primeiroautor;
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

void IniciaAutor(Lista_Autor *cadernoAutor){
    cadernoAutor->inicioautor=NULL;
    cadernoAutor->tam=0;
}

void IncluirAutor(Lista_Autor *cadernoAutor, char nomeAutor[], char instituicao[]){
    Autor *novoAutor;
    novoAutor = malloc(sizeof(Autor));
    Autor *aux;

    strcpy(novoAutor->nomeA,nomeAutor);
    strcpy(novoAutor->instituicao,instituicao);
    novoAutor->proximoAutor=NULL;
    if(cadernoAutor->inicioautor==NULL){
        cadernoAutor->inicioautor=novoAutor;
    }else{
        aux = cadernoAutor->inicioautor;
        while(aux->proximoAutor!=NULL){
            aux=aux->proximoAutor;
        }

        aux->proximoAutor=novoAutor;
        cadernoAutor->tam++;
    }

}

void IniciaListaLivro(Lista_Livros *biblioteca){
    biblioteca->primeiroLivro=NULL;
    biblioteca->tam=0;
}

void IncluirLivro(Lista_Livros *biblioteca, int idLivro, int ano, int edicao, char titulo[], char editora[]){
   int resp;
   char autor[100], instituicao[100];
    Livro *novolivro, *aux; // ele é ponteiro pra usarmos alocação dinamica
    Lista_Autor cadernoautor;
    IniciaAutor(&cadernoautor);

    novolivro = malloc(sizeof(Livro));

    do{
        printf("Digite o nome do autor: ");
        scanf(" %[^\n]", autor);
        printf("Digite o nome da Instituição: ");
        scanf(" %[^\n]", instituicao);
        IncluirAutor(&cadernoautor,autor,instituicao);

        printf("Deseja adicionar mais autores? \n1) - Sim \n2)- Não \n\n");
        scanf("%d",&resp);
        if(resp != 2){
            system("cls");
        }
    }while(resp!=2);

    novolivro->idlivro = idLivro;
    novolivro->ano = ano;
    novolivro->edicao = edicao;
    strcpy(novolivro->tituloLivro,titulo);
    strcpy(novolivro->editora,editora);
    novolivro->primeiroautor = cadernoautor.inicioautor;
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
    printf("\nLivro incluido com sucesso!\n");
}   

void RelatorioLivros(Lista_Livros *biblioteca){
    Livro *livros;
    livros = biblioteca->primeiroLivro;
    Autor *autores;
    autores = livros->primeiroautor;
    if(livros){
        while(livros){
            autores = livros->primeiroautor;
            printf("Id: %d |", livros->idlivro);
            printf(" Nome: %s|", livros->tituloLivro);
            printf(" Edição: %d  |", livros->edicao);
            printf(" Editora: %s |", livros->editora);
            printf(" Ano: %d |", livros->ano);
            while(autores){
                printf(" Autor: %s |", autores->nomeA);
                printf(" Instituição: %s |", autores->instituicao);
                autores=autores->proximoAutor;
            }
            printf("\n\n");
            livros=livros->proximoLivro;
        }
    }else{
        printf("\nBiblioteca vazia\n");
    }
}

void AlterarLivro(Lista_Livros *biblioteca){
    Livro *livroAlterado;
    int idAlteraLivro;
    livroAlterado = biblioteca->primeiroLivro;
    RelatorioLivros(biblioteca);
    printf("Digite o ID do livro que deseja fazer alteraçoes\n");
    scanf(" %d", &idAlteraLivro);
    system("cls");
    if(livroAlterado->idlivro == idAlteraLivro){
        printf("Usuario selecionado:\n | ID: %d | Nome: %s | Edição: %d | Editora: %s | Ano: %d\n",livroAlterado->idlivro ,livroAlterado->tituloLivro , livroAlterado->edicao, livroAlterado->editora, livroAlterado->ano);
        system("pause");

        printf("O que deseja alterar?\n1)Titulo \n2)Edição \n3)Ano \n4)Editora\n");
    }else{
        while(livroAlterado->idlivro!=idAlteraLivro && livroAlterado->proximoLivro != NULL){
            livroAlterado=livroAlterado->proximoLivro;
        }
        if(livroAlterado->idlivro == idAlteraLivro){
            printf("Usuario selecionado:\n | ID: %d | Nome: %s | Edição: %d | Editora: %s | Ano: %d\n",livroAlterado->idlivro ,livroAlterado->tituloLivro , livroAlterado->edicao, livroAlterado->editora, livroAlterado->ano);
            system("pause");

            printf("O que deseja alterar?\n1)Titulo \n2)Edição \n3)Ano \n4)Editora\n");
        }else{
            printf("\nO livro não existe\n");
        }
    }
}

void iniciarListaUsuario(Lista_Usuarios *caderno){
    caderno->primeiro_usuario = NULL;
    caderno->tam = 0;
}

void IncluirUsuario(Lista_Usuarios *caderno, int idUser, char telefone[], char NomeUser[], char endereco[]){
    Usuario *novousuario , *usuario;
    novousuario=malloc(sizeof(Usuario));
    if(novousuario){
        novousuario->idUser = idUser;
        strcpy(novousuario->telefone,telefone);
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
            usuario->proximoUsuario = novousuario; // agora que eu sei que o proximo usuario está vazio por conta do loop eu posso escrever um novo;
        }
        caderno->tam++;
        printf("\nUsuario cadastrado com sucesso!\n");
    }else{
        printf("\nErro ao alocar memória!\n");
    }
}

void RelatorioUsuario(Lista_Usuarios *caderno){
    Usuario *usuario;
    usuario = caderno->primeiro_usuario;
    if(usuario){
        while(usuario){
            printf(" | Id: %d", usuario->idUser);
            printf(" | Nome: %s", usuario->nomeUser);
            printf(" | Endereço: %s", usuario->endereco);
            printf(" | Telefone: %s\n", usuario->telefone);
            usuario=usuario->proximoUsuario;
        }
    }else{
        printf("\nSem usuários cadastrados\n");
    }
}

void AlterarUsuario(Lista_Usuarios *cadernoUsuario){
    int resposta;
    Usuario *novousuario;
    novousuario = cadernoUsuario->primeiro_usuario;

    int idAltera;
    RelatorioUsuario(cadernoUsuario);
    printf("Digite a ID do usuario que deseja alterar\n");

    scanf("%d", &idAltera);
    system("cls");

    if(novousuario->idUser == idAltera){
        printf("Usuario Selecionado:\n | ID: %d | Nome: %s | Telefone: %s | Endereço: %s \n",novousuario->idUser ,novousuario->nomeUser , novousuario->telefone, novousuario->endereco);
        printf("\n O que deseja alterar? \n 1)Nome \n 2) Telefone \n 3)Endereço \n\n");
        scanf("%d", &resposta);
        switch (resposta){
        case 1: 
            printf("Digite o novo nome: ");
            scanf(" %[^\n]", novousuario->nomeUser);
            break;
        case 2:
            printf("Digite o numero do novo telefone: ");
            scanf(" %[^\n]", novousuario->telefone);
            break;
        case 3:
            printf("Digite o novo endereço: ");
            scanf(" %[^\n]", novousuario->endereco);

            break;
        default:
            printf("\nA opção digitada não existe.\nPor favor digite uma das opções do menu.");
        }
    }else{
        while(novousuario->idUser != idAltera && novousuario->proximoUsuario != NULL){
            novousuario = novousuario->proximoUsuario;
        }
        if(novousuario->idUser == idAltera){
            printf("Usuario Selecionado:\n | ID: %d | Nome: %s | Telefone: %s | Endereço: %s \n",novousuario->idUser ,novousuario->nomeUser , novousuario->telefone, novousuario->endereco);
            printf("\n O que deseja alterar? \n 1)Nome \n 2) Telefone \n 3)Endereço \n\n");
            scanf("%d", &resposta);
            switch (resposta){
            case 1: 
                printf("Digite o novo nome: ");
                scanf(" %[^\n]", novousuario->nomeUser);
                break;
            case 2:
                printf("Digite o numero do novo telefone: ");
                scanf(" %[^\n]", novousuario->telefone);
                break;
            case 3:
                printf("Digite o novo endereço: ");
                scanf(" %[^\n]", novousuario->endereco);

                break;
            default:
                printf("\nA opção digitada não existe.\nPor favor digite uma das opções do menu.");
            }
        }else{
            printf("\nO usuário não existe\n");
        }
    }
}

void ExcluirUsuario(Lista_Usuarios *cadernoUsuario){
    Usuario *usuarioremovido;
    Usuario *aux;
    int idExcluido;
    aux =cadernoUsuario->primeiro_usuario;
    usuarioremovido = cadernoUsuario->primeiro_usuario;
    if(cadernoUsuario->primeiro_usuario){

    RelatorioUsuario(cadernoUsuario);
    printf("Digite a ID do usuario que deseja apagar\n");
    
    scanf("%d", &idExcluido);
    
    if(aux->idUser == idExcluido){
        
        cadernoUsuario->primeiro_usuario= aux->proximoUsuario;
        usuarioremovido=aux;

    }else{
    
    while(aux->proximoUsuario->idUser!=idExcluido && aux->proximoUsuario != NULL){
        aux = aux->proximoUsuario;
    }

    usuarioremovido = aux->proximoUsuario;
    aux->proximoUsuario = usuarioremovido->proximoUsuario;
    }

    printf("O seguinte usuario foi apagado:\n | ID: %d | Nome: %s | Telefone: %s | Endereço: %s \n",usuarioremovido->idUser ,usuarioremovido->nomeUser , usuarioremovido->telefone, usuarioremovido->endereco);
        
    free(usuarioremovido);
    }else{
        printf("\n Não há usuarios cadastrados \n");
    }
}

int main(){
    setlocale(LC_ALL,"Portuguese");
    int resMenu=1, resSubMenu, idUser=1, idLivro=1, edicaoLivro, anoLivro;
    char nomeUSer[50], endereco[100], nomeLivro[100], editora[50], telefone[15];
    Lista_Usuarios cadernoUsuarios;
    Lista_Livros biblioteca;
    Lista_Autor cadernoAutores;

    iniciarListaUsuario(&cadernoUsuarios);
    IniciaListaLivro(&biblioteca);
    IniciaAutor(&cadernoAutores);

    while(resMenu != 5){
        printf("Menu:\n");
        printf("1.Usuário\n");
        printf("2.Livro\n");
        printf("3.Reserva\n");
        printf("4.Relatórios\n");
        printf("5.Sair\n");
        printf("Digite a opção que você deseja: ");
        scanf(" %d", &resMenu);
        switch(resMenu){
            case 1:
                system("cls");

                printf("Menu:\n");
                printf("1.Incluir usuario\n");
                printf("2.Alterar usuario\n");
                printf("3.Excluir usuario\n");
                printf("4.Voltar\n");
                printf("Digite a opção que você deseja: ");
                scanf(" %d", &resSubMenu);
                
                switch(resSubMenu){
                    case 1:
                        system("cls");
                        printf("Digite o nome do usuário: ");
                        scanf(" %[^\n]", nomeUSer);
                        printf("Digite o endereço do usuário: ");
                        scanf(" %[^\n]", endereco);
                        printf("Digite o telefone do usuario: ");
                        scanf(" %[^\n]", telefone);
                        IncluirUsuario(&cadernoUsuarios, idUser++, telefone, nomeUSer, endereco);
                        system("pause");
                        break;
                    case 2:
                        system("cls");
                        AlterarUsuario(&cadernoUsuarios);
                        system("pause");
                        break;
                    case 3:
                        system("cls");
                        ExcluirUsuario(&cadernoUsuarios);
                        system("pause");
                        break;
                    case 4:
                        break;
                    default:
                        printf("\nA opção digitada não existe.\nPor favor digite uma das opções do menu.");
                }
                break;

            case 2:
                system("cls");

                printf("Menu:\n");
                printf("1.Incluir Livro\n");
                printf("2.Alterar Livro\n");
                printf("3.Excluir Livro\n");
                printf("4.Voltar\n");
                printf("Digite a opção que você deseja: ");
                scanf(" %d", &resSubMenu);

                switch(resSubMenu){
                    case 1:
                        system("cls");
                        printf("Digite o titulo do livro: ");
                        scanf(" %[^\n]", nomeLivro);
                        printf("Digite o numero de edição do livro: ");
                        scanf(" %d", &edicaoLivro);
                        printf("Digite o nome da editora do livro: ");
                        scanf(" %[^\n]", editora);
                        printf("Digite o ano de lançamento do livro: ");
                        scanf(" %d", &anoLivro);
                        IncluirLivro(&biblioteca, idLivro++, anoLivro, edicaoLivro, nomeLivro,editora);
                        system("pause");
                        break;
                    case 2:
                    system("cls");
                    AlterarLivro(&biblioteca);
                    system("pause");
                        break;
                    case 3:
                        break;
                    case 4:
                        break;
                    default:
                        printf("\nA opção digitada não existe.\nPor favor digite uma das opções do menu.");
                }
                break;
                
            case 3:
                system("cls");
                break;
            case 4:
                system("cls");
                
                printf("1. Relatório de Usuários\n");
                printf("2. Relatório de Livros\n");
                printf("3. Relatório de Reservas\n");
                printf("4. Voltar\n");
                printf("Digite a opção que você deseja: ");
                scanf(" %d", &resSubMenu);

                switch(resSubMenu){
                    case 1:
                        system("cls");
                        printf("Relatório de Usuários:\n");
                        RelatorioUsuario(&cadernoUsuarios);
                        system("pause");
                        break;
                    case 2:
                        system("cls");
                        printf("Relatório de livros:\n");
                        RelatorioLivros(&biblioteca);
                        system("pause");
                        break;
                    case 3:
                        break;
                    case 4:
                        break;
                    default:
                        printf("\nA opção digitada não existe.\nPor favor digite uma das opções do menu.");
                }
                system("cls");
                break;
            case 5:
                printf("\nObrigado por usar o programa\n");
                break;
            default:
                printf("\nA opção digitada não existe.\nPor favor digite uma das opções do menu.");
        }
        system("cls");
    }

    return 0;
}