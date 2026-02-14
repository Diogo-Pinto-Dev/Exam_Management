#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include "Z_Menus.c"
#include "Z_Funcoes.c"

#define MAX_LINHA_FICHEIRO 150
typedef char LinhaTexto[MAX_LINHA_FICHEIRO];

void limpar();

//__________________________ FUNÇÕES ________________________
int VerificarNumero();
int VerrificarLoginAdmin();
int VerificarLoginProfessor();
int VerificarLoginAluno();

void criarAluno();
void mostrarAlunos();
void alterarDadoAluno();
void apagarAluno();

void criarProf();
void mostrarProf();
void alterarDadoProf();
void apagarProf();

void criarExames();
void mostrarExames();
void alterarDadoExames();

void criarUC();
void mostrarUC();
void alterarDadoUC();
void gravarUC();
void apagar();
//____________________________________________________________

int main()
{
    int op_principal, op_login;                                                                              // Opções para os menus principais
    int op_admin_1, op_prof_1, op_prof_2, op_prof_3, op_aluno_1, op_admin_aluno, op_admin_prof, op_admin_uc; // Opções para Switches
    int Login_Admin = 0;                                                                                     // Colocar tudo relacionado com admins
    int Login_Prof = 0;                                                                                      // Colocar tudo relacionado com professores
    int Login_Aluno = 0;                                                                                     // Colocar tudo relacionado com alunos

    inicializarAdmin();
    inicializarProfessores();
    inicializarAlunos();
    inicializarExame();
    do
    {
        limpar();
        Menu_do_Inicio();
        op_principal = VerificarNumero(0, 1);

        switch (op_principal)
        {
        case 0:
            break;

        case 1:
            do
            {
                limpar();
                menu_login();
                op_login = VerificarNumero(0, 3);
                switch (op_login)
                {
                case 0:
                    break;

                case 1: // Login Admin
                    Login_Admin = VerrificarLoginAdmin();
                    if (Login_Admin != 100)
                    {
                        printf("\n Numero mecanografico incorreto!\n");
                        printf("Pressione uma tecla para continuar!");
                        getch();
                        printf("\n");
                    }
                    else
                    {
                        //_________________________________________
                        do
                        {
                            limpar();
                            Admin_Principal();
                            op_admin_1 = validarInt(0, 4);

                            switch (op_admin_1)
                            {
                            case 0:
                                break;

                            case 1: // Gestão Alunos

                                do
                                {
                                    limpar();
                                    Admin_Aluno();
                                    op_admin_aluno = validarInt(0, 4);

                                    switch (op_admin_aluno)
                                    {
                                    case 0:
                                        break;

                                    case 1:
                                        limpar();
                                        criarAluno();
                                        break;

                                    case 2:
                                        limpar();
                                        mostrarAlunos();
                                        getch();
                                        break;

                                    case 3:
                                        limpar();
                                        alterarDadoAluno();
                                        break;
                                    case 4:
                                        limpar();
                                        apagarAluno();
                                        break;

                                    default:
                                        printf("Escolha invalida!\n");
                                        printf("Pressione uma tecla para continuar!");
                                        getch();
                                        break;
                                    }

                                } while (op_admin_aluno != 0);

                                break;

                            case 2: // Gestão Professores

                                do
                                {
                                    limpar();
                                    Admin_Prof();
                                    op_admin_prof = validarInt(0, 4);

                                    switch (op_admin_prof)
                                    {
                                    case 0:
                                        break;

                                    case 1:
                                        limpar();
                                        criarProf();
                                        break;

                                    case 2:
                                        limpar();
                                        mostrarProf();
                                        getch();
                                        break;

                                    case 3:
                                        limpar();
                                        alterarDadoProf();
                                        break;
                                    case 4:
                                        limpar();
                                        apagarProf();
                                        break;

                                    default:
                                        printf("Escolha invalida!\n");
                                        printf("Pressione uma tecla para continuar!");
                                        getch();
                                        break;
                                    }

                                } while (op_admin_prof != 0);

                                break;

                            case 3: // Calendario Exames
                                limpar();
                                mostrarExames();
                                getch();
                                break;

                            case 4: // UC
                                do
                                {
                                    limpar();
                                    Admin_UC();
                                    op_admin_uc = validarInt(0, 4);

                                    switch (op_admin_uc)
                                    {
                                    case 0:
                                        break;

                                    case 1: // Criar UC
                                        limpar();
                                        criarUC();
                                        break;

                                    case 2: // Mostrar UC
                                        limpar();
                                        mostrarUC();
                                        getch();
                                        break;

                                    case 3: // Alterar UC
                                        limpar();
                                        alterarDadoUC();
                                        break;

                                    case 4: // Apagar UC
                                        limpar();
                                        apagar();
                                        break;

                                    default:
                                        break;
                                    }

                                } while (op_admin_uc != 0);

                                break;

                            default:
                                printf("Escolha invalida!\n");
                                printf("Pressione uma tecla para continuar!");
                                getch();
                                break;
                            }
                        } while (op_admin_1 != 0);
                        //_________________________________________
                    }
                    break;

                case 2: // Login Professor
                    Login_Prof = VerrificarLoginProfessor();
                    if (Login_Prof != 100)
                    {
                        printf("\n Numero mecanografico incorreto!\n");
                        printf("Pressione uma tecla para continuar!");
                        getch();
                        printf("\n");
                    }
                    else
                    {
                        //_________________________________________
                        do
                        {
                            limpar();
                            Prof_Principal();
                            op_prof_1 = validarInt(0, 2);

                            switch (op_prof_1)
                            {
                            case 0:
                                // Volta
                                break;

                            case 1: // Exames

                                do
                                {
                                    limpar();
                                    MENU_PROF_exame();
                                    op_prof_2 = validarInt(0, 2);

                                    switch (op_prof_2)
                                    {
                                    case 0:
                                        break;

                                    case 1: // Criar Exame
                                        limpar();
                                        criarExames();
                                        break;

                                    case 2: // Alterar Exame
                                        limpar();
                                        alterarDadoExames();
                                        break;

                                    default:
                                        break;
                                    }

                                } while (op_prof_2 != 0);

                                break;

                            case 2: // Calendario Exames
                                limpar();
                                mostrarExames();
                                getch();
                                break;

                            default:
                                printf("Escolha invalida!\n");
                                printf("Pressione uma tecla para continuar!");
                                getch();
                                break;
                            }

                        } while (op_prof_1 != 0);
                        //_________________________________________
                    }
                    break;

                case 3: // Login Aluno
                    Login_Aluno = VerrificarLoginAluno();
                    if (Login_Aluno != 100)
                    {
                        printf("\n Numero mecanografico incorreto!\n");
                        printf("Pressione uma tecla para continuar!");
                        getch();
                        printf("\n");
                    }
                    else
                    {
                        do
                        {
                            limpar();
                            Aluno_Principal();
                            op_aluno_1 = validarInt(0, 2);

                            switch (op_aluno_1)
                            {
                            case 0: // Volta
                                break;

                            case 1: // Inscrever Exame
                                printf("Em desenvolvimento");
                                getch();
                                break;

                            case 2: // Calendario Exame
                                printf("Em desenvolvimento");
                                getch();
                                break;

                            default:
                                printf("Escolha invalida!\n");
                                printf("Pressione uma tecla para continuar!");
                                getch();
                                break;
                            }

                        } while (op_aluno_1 != 0);
                    }
                    break;

                default:
                    printf("Escolha invalida!\n");
                    printf("Pressione uma tecla para continuar!");
                    getch();
                    break;
                }
            } while (op_login != 0);
            break;

        default:
            printf("Escolha invalida!\n");
            printf("Pressione uma tecla para continuar!");
            getch();
            printf("\n");
            break;
        }
    } while (op_principal != 0);
    return 0;
}