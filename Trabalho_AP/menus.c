#include <stdio.h>
#include <stdlib.h>

void Menu_do_Inicio()
{
    printf("\n");
    printf("****************************************************\n");
    printf("************      App desenvolvida por      ********\n");
    printf("****************************************************\n");
    printf("**********   Diogo               26357      ********\n");
    printf("**********   Rodrigo Santos      24993      ********\n");
    printf("**********   Wang Bin            20414      ********\n");
    printf("****************************************************\n");
    printf("\n");
    printf("****************************************************\n");
    printf("**        [0] -> Sair                             **\n");
    printf("**        [1] -> Entrar                           **\n");
    printf("****************************************************\n");
    printf("->");
}

void menu_login()
{
    printf("\n");
    printf("****************************************************\n");
    printf("******************   Login  ************************\n");
    printf("****************************************************\n");
    printf("**        [0] -> Voltar                           **\n");
    printf("**        [1] -> Admin                            **\n");
    printf("**        [2] -> Professor                        **\n");
    printf("**        [3] -> Aluno                            **\n");
    printf("****************************************************\n");
    printf("->");
}



//________________________ MENUS ADMINISTRADOR ________________________
void Admin_Principal()
{
    printf("****************************************************\n");
    printf("**        Escolha uma das seguintes opcoes        **\n");
    printf("****************************************************\n");
    printf("**        [0] -> Voltar                           **\n");
    printf("**        [1] -> Aluno                            **\n");
    printf("**        [2] -> Professores                      **\n");
    printf("**        [3] -> Calendário de Exames             **\n");
    printf("**        [4] -> Unidade Curricular               **\n");
    printf("****************************************************\n");
    printf("->");
}

void Admin_Aluno()
{
    printf("****************************************************\n");
    printf("**        Escolha uma das seguintes opcoes        **\n");
    printf("****************************************************\n");
    printf("**        [0] -> Voltar                           **\n");
    printf("**        [1] -> Criar Aluno                      **\n");
    printf("**        [2] -> Mostrar Alunos                   **\n");
    printf("**        [3] -> Alterar Dados de Alunos          **\n");
    printf("**        [4] -> Apagar Aluno                     **\n");
    printf("****************************************************\n");
    printf("->");
}

void Admin_Prof()
{
    printf("****************************************************\n");
    printf("**        Escolha uma das seguintes opcoes        **\n");
    printf("****************************************************\n");
    printf("**        [0] -> Voltar                           **\n");
    printf("**        [1] -> Criar Professor                  **\n");
    printf("**        [2] -> Mostrar Professor                **\n");
    printf("**        [3] -> Alterar Dados de Professores     **\n");
    printf("**        [4] -> Apagar Professor                 **\n");
    printf("****************************************************\n");
    printf("->");
}

void Admin_UC()
{
    printf("****************************************************\n");
    printf("**        Escolha uma das seguintes opcoes        **\n");
    printf("****************************************************\n");
    printf("**        [0] -> Voltar                           **\n");
    printf("**        [1] -> Criar UC                         **\n");
    printf("**        [2] -> Mostrar UC                       **\n");
    printf("**        [3] -> Alterar UC                       **\n");
    printf("**        [4] -> Apagar UC                        **\n");
    printf("****************************************************\n");
    printf("->");
}
//_____________________________________________________________________



//___________________________ MENUS PROFESSOR _________________________
void Prof_Principal()
{
    printf("****************************************************\n");
    printf("******************   Professor  ********************\n");
    printf("****************************************************\n");
    printf("**        [0] -> Sair                             **\n");
    printf("**        [1] -> Exames                           **\n");
    printf("**        [2] -> Calendário de Exames             **\n");
    printf("****************************************************\n");
    printf("->");
}

void MENU_PROF_exame()
{
    printf("****************************************************\n");
    printf("*******************   Exames   *********************\n");
    printf("****************************************************\n");
    printf("**        [0] -> Voltar                           **\n");
    printf("**        [1] -> Criar                            **\n");
    printf("**        [2] -> Alterar                          **\n");
    printf("****************************************************\n");
    printf("->");
}

void MENU_PROF_criar_exame()
{
    printf("****************************************************\n");
    printf("****************    Criar Exame  *******************\n");
    printf("****************************************************\n");
    printf("**        [0] -> Voltar                           **\n");
    printf("**        [1] -> Epoca Normal                     **\n");
    printf("**        [2] -> Epoca de Recurso                 **\n");
    printf("**        [3] -> Epoca Especial                   **\n");
    printf("****************************************************\n");
    printf("->");
}

void MENU_PROF_alterar_exame()
{
    printf("****************************************************\n");
    printf("***************   Alterar Exame    *****************\n");
    printf("***************   NAO ESTA FEITO   *****************\n");
    printf("****************************************************\n");
    printf("**        [0] -> Voltar                           **\n");
    printf("**        [1] -> Introduza o número do exame      **\n");
    printf("****************************************************\n");
    printf("->");
}
void MENU_PROF_eliminar_exame()
{
    printf("****************************************************\n");
    printf("***************   Eliminar Exame    ****************\n");
    printf("***************   NAO ESTA FEITO   *****************\n");
    printf("****************************************************\n");
    printf("**        [0] -> Voltar                           **\n");
    printf("**        [1] -> Introduza o número do exame      **\n");
    printf("****************************************************\n");
    printf("->");
}
//_____________________________________________________________________


//_____________________________ MENUS ALUNOS __________________________
void Aluno_Principal()
{
    printf("****************************************************\n");
    printf("******************    Aluno     ********************\n");
    printf("****************************************************\n");
    printf("**        [0] -> Sair                             **\n");
    printf("**        [1] -> Inscrever Exames                 **\n");
    printf("**        [2] -> Calendário de Exames             **\n");
    printf("****************************************************\n");
    printf("->");
}
//_____________________________________________________________________
