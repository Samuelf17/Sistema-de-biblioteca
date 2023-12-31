#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct Autor{
    char nomeA[100],instituicao[100]; 
    struct Autor *proximoAutor;
}Autor;

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
    char dataInicio[11], dataFim[11];
    int idUser, idLivro;
    struct Reserva *proximoReserva;
}Reserva;

typedef struct Lista_Reservas{
    struct Reserva *primeiraReserva;
    int tam;
}Lista_Reservas;

void IncluirAutor(Livro *livroSelecionado, char nomeAutor[], char instituicao[]){
    Autor *novoAutor;
    novoAutor = malloc(sizeof(Autor));
    Autor *aux;

    strcpy(novoAutor->nomeA,nomeAutor);
    strcpy(novoAutor->instituicao,instituicao);
    novoAutor->proximoAutor=NULL;
    if(livroSelecionado->primeiroautor==NULL){
        livroSelecionado->primeiroautor=novoAutor;
    }else{
        aux = livroSelecionado->primeiroautor;
        while(aux->proximoAutor!=NULL){
            aux=aux->proximoAutor;
        }
        aux->proximoAutor=novoAutor;
    }
}

void ExcluirAutor(Livro *livro, char nomeAutor[]){
    Autor *autores=livro->primeiroautor, *autorRemovido;
    if(strcmp(autores->nomeA, nomeAutor) == 0){
        livro->primeiroautor = autores->proximoAutor;
        autorRemovido = autores;
    }else{
        while(strcmp(autores->proximoAutor->nomeA, nomeAutor) != 0){
            autores = autores->proximoAutor;
        }
        autorRemovido = autores->proximoAutor;
        autores->proximoAutor = autorRemovido->proximoAutor;
    }
    printf("\nO seguinte autor foi apagado:\n | Nome: %s | Institui��o: %s\n", autorRemovido->nomeA, autorRemovido->instituicao); 
    free(autorRemovido);

}

void IniciaListaLivro(Lista_Livros *biblioteca){
    biblioteca->primeiroLivro=NULL;
    biblioteca->tam=0;
}

void IncluirLivro(Lista_Livros *biblioteca, int idLivro, int ano, int edicao, char titulo[], char editora[]){
   int resp;
   char autor[100], instituicao[100];
    Livro *novolivro, *aux; // ele � ponteiro pra usarmos aloca��o dinamica

    novolivro = malloc(sizeof(Livro));
    novolivro->primeiroautor = NULL;
    do{
        printf("Digite o nome do autor: ");
        scanf(" %[^\n]", autor);
        printf("Digite o nome da Institui��o: ");
        scanf(" %[^\n]", instituicao);
        IncluirAutor(novolivro,autor,instituicao);

        printf("Deseja adicionar mais autores? \n1) - Sim \n2)- N�o \n\n");
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
    if(livros != NULL){
        while(livros){
            autores = livros->primeiroautor;
            printf("| Id: %d |", livros->idlivro);
            printf(" Nome: %s |", livros->tituloLivro);
            printf(" Edi��o: %d  |", livros->edicao);
            printf(" Editora: %s |", livros->editora);
            printf(" Ano: %d |", livros->ano);
            while(autores){
                printf(" Autor: %s |", autores->nomeA);
                printf(" Institui��o: %s |", autores->instituicao);
                autores=autores->proximoAutor;
            }
            printf("\n\n");
            livros=livros->proximoLivro;
        }
    }else{
        printf("\nBiblioteca vazia\n\n");
    }
}

void AlterarLivro(Lista_Livros *biblioteca){
    Livro *livroAlterado;
    int idAlteraLivro, resp;
    livroAlterado = biblioteca->primeiroLivro;
    printf("Livros cadastrados:\n");
    RelatorioLivros(biblioteca);
    if(livroAlterado){
        printf("Digite o ID do livro que deseja fazer altera�oes\n");
        scanf(" %d", &idAlteraLivro);
        system("cls");
        if(livroAlterado->idlivro == idAlteraLivro){
            printf("Usuario selecionado:\n | ID: %d | Nome: %s | Edi��o: %d | Editora: %s | Ano: %d\n",livroAlterado->idlivro ,livroAlterado->tituloLivro , livroAlterado->edicao, livroAlterado->editora, livroAlterado->ano);
            printf("O que deseja alterar?\n1)Titulo \n2)Edi��o \n3)Editora \n4)Ano\n");
            scanf(" %d", &resp);
                switch (resp){
                case 1:
                        printf("Digite o novo nome\n");
                        scanf(" %[^\n]",livroAlterado->tituloLivro);
                        break;
                case 2:
                        printf("Reinsira a edi��o\n");
                        scanf(" %d",&livroAlterado->edicao);
                        break;
                case 3:
                        printf("Digite a nova Editora\n");
                        scanf(" %[^\n]",livroAlterado->editora);
                        break;

                case 4: 
                        printf("Reinsira ano\n");
                        scanf(" %d",&livroAlterado->ano);
                        break;

                default:printf("Op��o invalida\n");
                break;
                }
        }else{
            while(livroAlterado->idlivro!=idAlteraLivro && livroAlterado->proximoLivro != NULL){
                livroAlterado=livroAlterado->proximoLivro;
            }
            if(livroAlterado->idlivro == idAlteraLivro){
                printf("Usuario selecionado:\n | ID: %d | Nome: %s | Edi��o: %d | Editora: %s | Ano: %d\n",livroAlterado->idlivro ,livroAlterado->tituloLivro , livroAlterado->edicao, livroAlterado->editora, livroAlterado->ano);
                system("pause");

                printf("O que deseja alterar?\n1)Titulo \n2)Edi��o \n3)Editora \n4)Ano\n");
                scanf(" %d", &resp);
                switch (resp){
                case 1:
                        printf("Digite o novo nome\n");
                        scanf(" %[^\n]",livroAlterado->tituloLivro);
                        break;
                case 2:
                        printf("Reinsira a edi��o\n");
                        scanf(" %d",&livroAlterado->edicao);
                        break;
                case 3:
                        printf("Digite a nova Editora\n");
                        scanf(" %[^\n]",livroAlterado->editora);
                        break;

                case 4: 
                        printf("Reinsira ano\n");
                        scanf(" %d",&livroAlterado->ano);
                        break;

                default:printf("Op��o invalida\n");
                break;
                }
            }else{
                printf("\nO livro n�o existe\n");
            }
        }
    }
}

void ExcluirLivro(Lista_Livros *biblioteca){  
    int idLivroExcluido;
    Livro *livroExcluido, *removido;
    livroExcluido = biblioteca->primeiroLivro;
    printf("Livros cadastrados:\n");
    if(livroExcluido){
        RelatorioLivros(biblioteca);
        printf("Digite a ID do livro que deseja excluir: ");
        scanf(" %d", &idLivroExcluido);
        if(livroExcluido->idlivro == idLivroExcluido){
            removido = livroExcluido;
            biblioteca->primeiroLivro = livroExcluido->proximoLivro;
        }else{
            while(livroExcluido->proximoLivro->idlivro != idLivroExcluido && livroExcluido->proximoLivro != NULL){
                livroExcluido = livroExcluido->proximoLivro;
            }
            removido = livroExcluido->proximoLivro;
            livroExcluido->proximoLivro = removido->proximoLivro;
        }
        printf("\nO seguinte livro foi apagado:\n | ID: %d | Nome: %s | Editora: %s | Lan�amento: %d | Edi��o: %d\n", removido->idlivro, removido->tituloLivro, removido->editora, removido->ano, removido->edicao);
        free(removido);
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

void RelatorioUsuario(Lista_Usuarios *caderno){
    Usuario *usuario;
    usuario = caderno->primeiro_usuario;
    if(usuario){
        while(usuario){
            printf("| Id: %d", usuario->idUser);
            printf(" | Nome: %s", usuario->nomeUser);
            printf(" | Endere�o: %s", usuario->endereco);
            printf(" | Telefone: %s\n", usuario->telefone);
            usuario=usuario->proximoUsuario;
        }
        printf("\n");
    }else{
        printf("\nSem usu�rios cadastrados\n\n");
    }
}

void AlterarUsuario(Lista_Usuarios *cadernoUsuario){
    int resposta;
    Usuario *novousuario;
    novousuario = cadernoUsuario->primeiro_usuario;

    int idAltera;
    printf("Usu�rios cadastrados:\n");
    RelatorioUsuario(cadernoUsuario);
    if(novousuario){
        printf("Digite a ID do usuario que deseja alterar\n");

        scanf("%d", &idAltera);
        system("cls");

        if(novousuario->idUser == idAltera){
            printf("Usuario Selecionado:\n | ID: %d | Nome: %s | Telefone: %s | Endere�o: %s \n",novousuario->idUser ,novousuario->nomeUser , novousuario->telefone, novousuario->endereco);
            printf("\n O que deseja alterar? \n 1)Nome \n 2) Telefone \n 3)Endere�o \n\n");
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
                printf("Digite o novo endere�o: ");
                scanf(" %[^\n]", novousuario->endereco);

                break;
            default:
                printf("\nA op��o digitada n�o existe.\nPor favor digite uma das op��es do menu.");
            }
        }else{
            while(novousuario->idUser != idAltera && novousuario->proximoUsuario != NULL){
                novousuario = novousuario->proximoUsuario;
            }
            if(novousuario->idUser == idAltera){
                printf("Usuario Selecionado:\n | ID: %d | Nome: %s | Telefone: %s | Endere�o: %s \n",novousuario->idUser ,novousuario->nomeUser , novousuario->telefone, novousuario->endereco);
                printf("\n O que deseja alterar? \n 1)Nome \n 2) Telefone \n 3)Endere�o \n\n");
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
                    printf("Digite o novo endere�o: ");
                    scanf(" %[^\n]", novousuario->endereco);

                    break;
                default:
                    printf("\nA op��o digitada n�o existe.\nPor favor digite uma das op��es do menu.");
                }
            }else{
                printf("\nO usu�rio n�o existe\n");
            }
        }
    }
}

void ExcluirUsuario(Lista_Usuarios *cadernoUsuario){
    Usuario *usuarioremovido;
    Usuario *aux;
    int idExcluido;
    aux =cadernoUsuario->primeiro_usuario;
    usuarioremovido = cadernoUsuario->primeiro_usuario;
    printf("Usu�rios cadastrados:\n");
    RelatorioUsuario(cadernoUsuario);
    if(cadernoUsuario->primeiro_usuario){
        printf("Digite a ID do usuario que deseja apagar\n");
        
        scanf("%d", &idExcluido);
        
        if(aux->idUser == idExcluido){
            cadernoUsuario->primeiro_usuario = aux->proximoUsuario;
            usuarioremovido=aux;
        }else{
            while(aux->proximoUsuario->idUser!=idExcluido && aux->proximoUsuario != NULL){
                aux = aux->proximoUsuario;
            }
            usuarioremovido = aux->proximoUsuario;
            aux->proximoUsuario = usuarioremovido->proximoUsuario;
        }
        printf("O seguinte usuario foi apagado:\n | ID: %d | Nome: %s | Telefone: %s | Endere�o: %s \n",usuarioremovido->idUser ,usuarioremovido->nomeUser , usuarioremovido->telefone, usuarioremovido->endereco);
        free(usuarioremovido);
    }
}

void IniciarListaReserva(Lista_Reservas *cadernoReservas){
    cadernoReservas->primeiraReserva = NULL;
    cadernoReservas->tam=0;
}

void IncluirReserva(Lista_Reservas *cadernoReservas, char dataInicio[], char dataFinal[], int idUser, int IdLivro){
    Reserva *novaReserva, *reservas;
    novaReserva=malloc(sizeof(Reserva));
    strcpy(novaReserva->dataInicio, dataInicio);
    strcpy(novaReserva->dataFim, dataFinal);
    novaReserva->idLivro = IdLivro;
    novaReserva->idUser = idUser;
    novaReserva->proximoReserva = NULL;
    if(cadernoReservas->primeiraReserva == NULL){
        cadernoReservas->primeiraReserva = novaReserva;
    }else{
        reservas = cadernoReservas->primeiraReserva;
        while(reservas->proximoReserva != NULL){
            reservas = reservas->proximoReserva;
        }
        reservas->proximoReserva = novaReserva;
    }
    cadernoReservas->tam++;
    printf("\nReserva feita com sucesso\n");
}   

void RelatorioReservas(Lista_Reservas *cadernoReservas, Lista_Livros *biblioteca, Lista_Usuarios *cadernoUsuarios){
    Reserva *reservas = cadernoReservas->primeiraReserva;

    if(reservas){
        while(reservas){
            Usuario *usuario = cadernoUsuarios->primeiro_usuario;
            Livro *livro = biblioteca->primeiroLivro;
            while(livro->idlivro != reservas->idLivro){
                livro=livro->proximoLivro;
            }
            Autor *autores = livro->primeiroautor;
            while(usuario->idUser != reservas->idUser){
                usuario=usuario->proximoUsuario;
            }
            printf("\nUSU�RIO:\n");
            printf("Nome: %s | ", usuario->nomeUser);
            printf("ID: %d | ", reservas->idUser);
            printf("Telefone: %s | ", usuario->telefone);
            printf("Endere�o: %s\n", usuario->endereco);
            printf("LIVRO:\n");
            printf("Nome: %s | ", livro->tituloLivro);
            printf("ID: %d | ", reservas->idLivro);
            printf("Edi��o: %d | ",livro->edicao);
            printf("Editora: %s | ", livro->editora);
            printf("Lan�amento: %d | ", livro->ano);
            while(autores){
                printf("Autor: %s | ", autores->nomeA);
                printf("Institui��o: %s | ", autores->instituicao);
                autores = autores->proximoAutor;
            }
            printf("\n");
            printf("Data de in�cio: %s | ", reservas->dataInicio);
            printf("Data de fim: %s \n\n", reservas->dataFim);
            reservas = reservas->proximoReserva;
        }
    }else{
        printf("\nNenhuma reserva cadastrada\n\n");
    }
}

void AlterarReserva(Lista_Reservas *cadernoReservas, Lista_Livros *biblioteca, Lista_Usuarios *cadernoUsuario){
    int Idresp ,caseresposta;
    Reserva *reservaAlterada;
    Livro *livros = biblioteca->primeiroLivro;
    Usuario *usuarios=cadernoUsuario->primeiro_usuario;
    reservaAlterada = cadernoReservas->primeiraReserva;
    printf("Reservas cadastradas:\n");
    RelatorioReservas(cadernoReservas, biblioteca, cadernoUsuario);
    if(reservaAlterada){
        printf("Para selecionar a reserva que deseja alterar, digite a ID do usuario que reservou\n");
        scanf(" %d", &Idresp);
        system("cls");
        while (reservaAlterada->idUser!=Idresp){
            reservaAlterada = reservaAlterada->proximoReserva;
        }
        while(usuarios->idUser != reservaAlterada->idUser){
            usuarios=usuarios->proximoUsuario;
        }
        while(livros->idlivro != reservaAlterada->idLivro){
            livros=livros->proximoLivro;
        }
        if(reservaAlterada->idUser == Idresp){
            printf("Usu�rio Selecionado:\n\nNome: %s | ID: %d | Telefone: %s | Endere�o: %s \n", usuarios->nomeUser, usuarios->idUser, usuarios->telefone, usuarios->endereco);
            printf("Livro:\nNome: %s | ID: %d\n", livros->tituloLivro, livros->idlivro);
            printf("Data de inicio: %s | Data final: %s\n\n", reservaAlterada->dataInicio, reservaAlterada->dataFim);
            printf("O que deseja alterar?\n 1)ID do Usuario\n 2)ID do Livro\n 3)Data de Inicio\n 4)Data Fim\n");
            scanf(" %d",&caseresposta);
            switch (caseresposta){
            case 1: 
                printf("Digite o novo ID de usuario\n");
                scanf(" %d", &reservaAlterada->idUser);
                break;
            case 2: 
                printf("Digite o novo ID do livro\n");
                scanf(" %d", &reservaAlterada->idLivro);
                break;
            case 3: 
                printf("Digite a nova data de incio\n");
                scanf(" %[^\n]", reservaAlterada->dataInicio);
                break;
            case 4: 
                printf("Digite a nova data final\n");
                scanf(" %[^\n]", reservaAlterada->dataFim);
                break;
            default:
                printf("Opcao invalida!");
                break;
            }
        }else{
            printf("Usu�rio Selecionado:\n | ID: %d | Nome: %s | Telefone: %s | Endere�o: %s \n", usuarios->idUser, usuarios->nomeUser , usuarios->telefone, usuarios->endereco);
            printf("Livro:\nNome: %s | ID: %d", livros->tituloLivro, livros->idlivro);
            printf("O que deseja alterar?\n 1)ID do Usuario\n 2)ID do Livro\n 3)Data de Inicio\n 4)Data Fim\n");
            scanf("%d",&caseresposta);
            switch (caseresposta){
            case 1: 
                printf("Digite o novo ID de usuario\n");
                scanf(" %d", &reservaAlterada->idUser);
                break;
            case 2: 
                printf("Digite o novo ID do livro\n");
                scanf(" %d", &reservaAlterada->idLivro);
                break;
            case 3: 
                printf("Digite a nova data de incio\n");
                scanf(" %[^\n]", reservaAlterada->dataInicio);
                break;
            case 4: 
                printf("Digite a nova data final\n");
                scanf(" %[^\n]", reservaAlterada->dataFim);
                break;
            default:
                printf("Opcao invalida!");
                break;
            }
        }
    }
}

void ExcluirReserva(Lista_Reservas *cadernoReserva, Lista_Livros *biblioteca, Lista_Usuarios *cadernoUsuario){
    Reserva *usuarioexcluido, *aux;
    int Idexcluido;
    printf("Reservas cadastradas:\n");
    RelatorioReservas(cadernoReserva, biblioteca, cadernoUsuario);
    aux = cadernoReserva->primeiraReserva;
    if(aux){
        printf("Digite o ID do usuario que deseja excluir\n");
        scanf(" %d",&Idexcluido);
        if(aux->idUser == Idexcluido){
            cadernoReserva->primeiraReserva = cadernoReserva->primeiraReserva->proximoReserva;
            usuarioexcluido=aux;
        }else{
            while (aux->proximoReserva->idUser != Idexcluido){
                aux= aux->proximoReserva;
            }
            usuarioexcluido = aux->proximoReserva;
            aux->proximoReserva = usuarioexcluido->proximoReserva;
        }

        free(usuarioexcluido);
    }
}

Livro* buscaLivro(Lista_Livros *biblioteca, int idLivro){
    Livro *livros=biblioteca->primeiroLivro;
    while(livros->idlivro != idLivro){
        livros = livros->proximoLivro;
    }
    return livros;
}

Usuario* buscaUsuario(Lista_Usuarios *cadernoUsuarios, int idUsario){
    Usuario *usuario=cadernoUsuarios->primeiro_usuario;
    while(usuario->idUser != idUsario){
        usuario = usuario->proximoUsuario;
    }
    return usuario;
}

int main(){
    setlocale(LC_ALL,"Portuguese");
    int resMenu=1, resSubMenu, idUser=1, idLivro=1, edicaoLivro, anoLivro, idUserReserva, idLivroReserva;
    char nomeUSer[50], endereco[100], nomeLivro[100], editora[50], telefone[15], dataInicioReserva[11], dataFimReserva[11], nomeAutor[50], instituicao[50];
    Lista_Usuarios cadernoUsuarios;
    Lista_Livros biblioteca;
    Lista_Reservas cadernoReservas;
    Livro *livro;
    Usuario *usuario;
    Autor *autores;

    iniciarListaUsuario(&cadernoUsuarios);
    IniciaListaLivro(&biblioteca);
    IniciarListaReserva(&cadernoReservas);

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
                        printf("\nA op��o digitada n�o existe.\nPor favor digite uma das op��es do menu.");
                }
                break;

            case 2:
                system("cls");

                printf("Menu:\n");
                printf("1.Incluir Livro\n");
                printf("2.Alterar Livro\n");
                printf("3.Excluir Livro\n");
                printf("4.Incluir Autor\n");
                printf("5.Excluir Autor\n");
                printf("6.Voltar\n");
                printf("Digite a op��o que voc� deseja: ");
                scanf(" %d", &resSubMenu);

                switch(resSubMenu){
                    case 1:
                        system("cls");
                        printf("Digite o titulo do livro: ");
                        scanf(" %[^\n]", nomeLivro);
                        printf("Digite o numero de edi��o do livro: ");
                        scanf(" %d", &edicaoLivro);
                        printf("Digite o nome da editora do livro: ");
                        scanf(" %[^\n]", editora);
                        printf("Digite o ano de lan�amento do livro: ");
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
                        system("cls");
                        ExcluirLivro(&biblioteca);
                        system("pause");
                        break;
                    case 4:
                        system("cls");
                        RelatorioLivros(&biblioteca);
                        printf("Digite a Id do livro que voc� deseja incluir um autor: ");
                        scanf(" %d", &idLivro);
                        system("cls");
                        livro = buscaLivro(&biblioteca, idLivro);
                        autores = livro->primeiroautor;
                        printf("Livro Selecionado:\n| Id: %d | Nome: %s ", livro->idlivro, livro->tituloLivro);
                        while(autores){
                            printf("| Autor: %s ", autores->nomeA);
                            autores = autores->proximoAutor;
                        }
                        printf("\nDigite o nome do autor que voc� deseja incluir: ");
                        scanf(" %[^\n]", nomeAutor);
                        printf("Digite o nome da institui��o do autor: ");
                        scanf(" %[^\n]", instituicao);
                        IncluirAutor(livro, nomeAutor, instituicao);
                        printf("\nAutor inclu�do com sucesso!\n\n");
                        system("pause");
                        break;
                    case 5:
                        system("cls");
                        RelatorioLivros(&biblioteca);
                        printf("Digite a id do livro que voce deseja excluir o autor: ");
                        scanf("%d", &idLivro);
                        livro = buscaLivro(&biblioteca, idLivro);
                        system("cls");
                        printf("Livro Selecionado:\n| Nome: %s |", livro->tituloLivro);
                        autores = livro->primeiroautor;
                        while(autores){
                            printf("| Autor: %s ", autores->nomeA);
                            autores = autores->proximoAutor;
                        }
                        printf("\nDigite o nome do autor que voc� deseja excluir: ");
                        scanf(" %[^\n]", nomeAutor);
                        ExcluirAutor(livro, nomeAutor);
                        system("pause");
                        break;
                    case 6:
                        break;
                    default:
                        printf("\nA op��o digitada n�o existe.\nPor favor digite uma das op��es do menu.");
                }
                break;
                
            case 3:
                system("cls");
                printf("Menu:\n");
                printf("1.Incluir Reserva\n");
                printf("2.Alterar Reserva\n");
                printf("3.Excluir Reserva\n");
                printf("4.Voltar\n");
                printf("Digite a op��o que voc� deseja: ");
                scanf(" %d", &resSubMenu);
                switch(resSubMenu){
                    case 1:
                        system("cls");
                        printf("Usu�rios cadastrados:\n");
                        RelatorioUsuario(&cadernoUsuarios);
                        printf("\nDigite a ID do usu�rio que ir� fazer a reserva: ");
                        scanf(" %d", &idUserReserva);
                        system("cls");
                        printf("Livros cadastrados:\n");
                        RelatorioLivros(&biblioteca);
                        printf("Digite o livro que ser� reservado: ");
                        scanf(" %d", &idLivroReserva);
                        system("cls");
                        livro = buscaLivro(&biblioteca, idLivroReserva);
                        usuario = buscaUsuario(&cadernoUsuarios, idUserReserva);
                        printf("Usuario selecionado:\n| Id: %d | Nome: %s | Endere�o: %s | Telefone: %s |\n", usuario->idUser, usuario->nomeUser, usuario->endereco, usuario->telefone);
                        printf("Livro selecionado:\n| Id: %d | Nome: %s | Lan�amento: %d | Edi��o: %d | Editora: %s |\n\n", livro->idlivro, livro->tituloLivro, livro->ano, livro->edicao, livro->editora);
                        printf("Digite a data de inicio da reserva: ");
                        scanf(" %[^\n]", dataInicioReserva);
                        printf("Digite a data do fim da reserva: ");
                        scanf(" %[^\n]", dataFimReserva);
                        IncluirReserva(&cadernoReservas, dataInicioReserva, dataFimReserva, idUserReserva, idLivroReserva);
                        system("pause");
                        break;

                    case 2:
                        system("cls"); 
                        AlterarReserva(&cadernoReservas, &biblioteca, &cadernoUsuarios);
                        system("pause");
                        break;

                    case 3:
                        system("cls");
                        ExcluirReserva(&cadernoReservas, &biblioteca, &cadernoUsuarios);
                        system("pause");
                        break;
                }


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
                        printf("Relat�rio de Usu�rios:\n");
                        RelatorioUsuario(&cadernoUsuarios);
                        system("pause");
                        break;
                    case 2:
                        system("cls");
                        printf("Relat�rio de livros:\n");
                        RelatorioLivros(&biblioteca);
                        system("pause");
                        break;
                    case 3:
                        system("cls");
                        printf("Relat�rio de Reservas:\n");
                        RelatorioReservas(&cadernoReservas, &biblioteca, &cadernoUsuarios);
                        system("pause");
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