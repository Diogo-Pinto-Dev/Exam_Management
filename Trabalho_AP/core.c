#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>

#define MAX_LINHA_FICHEIRO 150
typedef char LinhaTexto[MAX_LINHA_FICHEIRO];
LinhaTexto LT;

void limpar()
{
	fputs("\x1b[H\x1b[2J\x1b[3J", stdout);
}

int VerificarNumero(int menor, int maior)
{
	int num;
	do
	{
		scanf("%d", &num);
		if (num < menor && num > maior)
		{
			puts("Opcao invalida! Por favor volte a introduzir");
		}
		fflush(stdin);
	} while (num < menor && num > maior);
	return num;
}

//________________________ Structures _______________________

struct
{
	int numero;
	char ocup;
} ADMIN[100000];

struct
{
	int numero;
	char nome[100], ocup;
} PROFESSORES[100000];

struct
{
	int numero, ano;
	char nome[100], curso[100], regime[50], ocup;
} ALUNOS[100000];

struct
{
	int numero, ano, uc;
	int alunos[150];
	char descricao[50], epoca[50], ocup;
} EXAMES[100000];

typedef struct{
    int hora,minuto;
}HORA;

typedef struct
{
	char designacao[50];
	int lotacao;
	// DATA ocupado[];
} SALA;

struct
{
	char nome[50], docente[200], ocup;
	int codigo, ano, semestre;
} UC[200];

//____________________________________________________________

//________________________ Logins ____________________________

int VerrificarLoginAdmin()
{
	int conf = 100, numero_meccanografico, i, encontrou = 0;
	for (i = 0; i < 100000; i++)
	{
		if (ADMIN[i].ocup == 's')
		{
			encontrou = 1;
			break;
		}
	}

	if (encontrou)
	{
		do
		{
			printf("Qual e o numero mecanografico?\n");
			numero_meccanografico = VerificarNumero(0, 99999);

			if (ADMIN[numero_meccanografico - 1].ocup == 's')
			{
				return conf;
			}
		} while (ADMIN[numero_meccanografico - 1].ocup == 'n' && numero_meccanografico != 0);
	}
}

int VerrificarLoginProfessor()
{
	int conf = 100, numero_meccanografico, i, encontrou = 0;
	for (i = 0; i < 100000; i++)
	{
		if (PROFESSORES[i].ocup == 's')
		{
			encontrou = 1;
			break;
		}
	}

	if (encontrou)
	{
		do
		{
			printf("Qual e o numero mecanografico?\n");
			numero_meccanografico = VerificarNumero(0, 99999);

			if (PROFESSORES[numero_meccanografico - 1].ocup == 's')
			{
				return conf;
			}
		} while (PROFESSORES[numero_meccanografico - 1].ocup == 'n' && numero_meccanografico != 0);
	}
}

int VerrificarLoginAluno()
{
	int conf = 100, numero_meccanografico, i, encontrou = 0;
	for (i = 0; i < 100000; i++)
	{
		if (ALUNOS[i].ocup == 's')
		{
			encontrou = 1;
			break;
		}
	}

	if (encontrou)
	{
		do
		{
			printf("Qual e o numero mecanografico?\n");
			numero_meccanografico = VerificarNumero(0, 99999);

			if (ALUNOS[numero_meccanografico - 1].ocup == 's')
			{
				return conf;
			}
		} while (ALUNOS[numero_meccanografico - 1].ocup == 'n' && numero_meccanografico != 0);
	}
}

//____________________________________________________________

// __________________________ Métodos __________________________________

// Metodo para mostrar cadeiras ate um certo ano, UC cadeiras, ano
void UcMenu(char UC[3][8][50], int ano)
{
	int i, j, cont = 0;
	for (i = 0; i < ano; i++)
	{
		for (j = 0; j < 8; j++)
		{
			if (UC[i][j][i] != 0)
			{
				printf("%d - %s\n", ++cont, UC[i][j]);
			}
		}
	}
};

// Metodo para validar Inteiros
int validarInt(int menor, int maior)
{
	int num;
	do
	{
		printf("Introduza um valor entre %d e %d\n", menor, maior);
		scanf("%d", &num);
		if (num < menor || num > maior)
		{
			puts("Valor invalido, por favor volte a introduzir");
		}
		fflush(stdin);
	} while (num < menor || num > maior);
	return num;
}

//(normal, trabalhador-estudante, atleta, dirigente associativo ou aluno de Erasmus)
void validarRegime(char *regime)
{
	int op;
	printf("\n");
	printf("***************************************************\n");
	printf("**          Introduza o regime do aluno:         **\n");
	printf("***************************************************\n");
	printf("**       [1] -> Normal                           **\n");
	printf("**       [2] -> Trabalhador-estudante            **\n");
	printf("**       [3] -> Dirigente associativo            **\n");
	printf("**       [4] -> Aluno de Erasmus                 **\n");
	printf("**       [5] -> Atleta                           **\n");
	printf("***************************************************\n");
	op = validarInt(1, 5);
	switch (op)
	{
	case 1:
		strcpy(regime, "Normal");
		break;
	case 2:
		strcpy(regime, "Trabalhador-estudante");
		break;
	case 3:
		strcpy(regime, "Dirigente associativo");
		break;
	case 4:
		strcpy(regime, "Aluno de Erasmus");
		break;
	case 5:
		strcpy(regime, "Atleta");
		break;
	}
}

void criarAluno()
{
	int i, numero, disponivel = -1;
	char nome[100], curso[100], regime;
	FILE *f = fopen("Alunos.txt", "a");

	puts("\nDigite o numero do Aluno(1-99999):");
	numero = validarInt(1, 99999);

	for (i = 0; i < 100000; i++)
	{
		if (ALUNOS[numero - 1].ocup == 'n')
		{
			ALUNOS[numero - 1].numero = numero;
			puts("\nDigite o nome do Aluno:");
			gets(ALUNOS[numero - 1].nome);

			puts("\nDigite o ano do Aluno (1-3):");
			ALUNOS[numero - 1].ano = validarInt(1, 3);

			puts("\nDigite o curso do Aluno:");
			gets(ALUNOS[numero - 1].curso);

			validarRegime(ALUNOS[numero - 1].regime);

			ALUNOS[numero - 1].ocup = 's';
			fprintf(f, "%d;%s;%d;%s;%s\n", ALUNOS[numero - 1].numero, ALUNOS[numero - 1].nome, ALUNOS[numero - 1].ano, ALUNOS[numero - 1].curso, ALUNOS[numero - 1].regime);
			break;
		}
		else
		{
			if (ALUNOS[i].ocup == 'n' && disponivel == -1)
			{
				disponivel = i;
			}
			printf("Esse numero esta ocupado mas o numero %d esta disponivel\n", (disponivel + 1));
			numero = validarInt(1, 99999);
		}
	}
	fclose(f);
}

void mostrarAlunos()
{
	int i, encontrou = 0;
	for (i = 0; i < 100000; i++)
	{
		if (ALUNOS[i].ocup == 's')
		{
			encontrou = 1;
			printf("********************************************************\n");
			printf("**    Numero do Aluno: %d\n", ALUNOS[i].numero);
			printf("**    Nome do Aluno: %s\n", ALUNOS[i].nome);
			printf("**    Ano do Aluno: %d\n", ALUNOS[i].ano);
			printf("**    Curso do Aluno: %s\n", ALUNOS[i].curso);
			printf("**    Regime do Aluno: %s\n", ALUNOS[i].regime);
		}
	}
	if (!encontrou)
	{
		printf("O ficheiro esta vazio");
	}
}

void criarProf()
{
	int i, numero, disponivel = -1;
	char nome[100];

	FILE *f = fopen("Professores.txt", "a");
	puts("\nDigite o numero do Professor(1-99999):");

	numero = validarInt(1, 99999);

	for (i = 0; i < 100000; i++)
	{
		if (PROFESSORES[numero - 1].ocup == 'n')
		{
			PROFESSORES[numero - 1].numero = numero;

			puts("\nDigite o nome do Professor:");
			gets(PROFESSORES[numero - 1].nome);

			PROFESSORES[numero - 1].ocup = 's';
			fprintf(f, "%d;%s\n", PROFESSORES[numero - 1].numero, PROFESSORES[numero - 1].nome);
			break;
		}
		else
		{
			if (PROFESSORES[i].ocup == 'n' && disponivel == -1)
			{
				disponivel = i;
			}
			// printf("Esse numero esta ocupado mas o numero %d esta disponivel\n", (disponivel + 1));
			printf("Esse numero esta ocupado");
			numero = validarInt(1, 99999);
		}
	}
	fclose(f);
}

void mostrarProf()
{
	int i, encontrou = 0;
	for (i = 0; i < 100000; i++)
	{
		if (PROFESSORES[i].ocup == 's')
		{
			encontrou = 1;
			printf("********************************************************\n");
			printf("**    Numero do Professor: %d\n", PROFESSORES[i].numero);
			printf("**    Nome do Professor: %s\n", PROFESSORES[i].nome);
		}
	}
	if (!encontrou)
	{
		printf("O ficheiro esta vazio");
	}
}

void criarExames()
{
	int i, numero, ano, disponivel = -1;
	char descricao[50], epoca[50];
	FILE *f = fopen("Exames.txt", "a");

	puts("\nDigite o numero do exame(1-99999):");
	numero = validarInt(1, 99999);

	for (i = 0; i < 100000; i++)
	{
		if (EXAMES[numero - 1].ocup == 'n')
		{
			EXAMES[numero - 1].numero = numero;

			puts("\nDigite o ano (1-3):");
			EXAMES[numero - 1].ano = validarInt(1, 3);

			puts("\nDigite a disciplina:");
			gets(EXAMES[numero - 1].descricao);

			int op;
			printf("\n");
			printf("*******************************\n");
			printf("**  Digite a epoca do exame  **\n");
			printf("*******************************\n");
			printf("**	  [1] Normal         **\n");
			printf("**	  [2] Recurso        **\n");
			printf("**	  [3] Especial       **\n");
			printf("*******************************\n");
			op = validarInt(1, 3);

			switch (op)
			{
			case 1:
				strcpy(epoca, "Normal");
				break;
			case 2:
				strcpy(epoca, "Recurso");
				break;
			case 3:
				strcpy(epoca, "Especial");
				break;

			default:
				break;
			}

			EXAMES[numero - 1].ocup = 's';
			fprintf(f, "%d;%d;%s;%s\n", EXAMES[numero - 1].numero, EXAMES[numero - 1].ano, EXAMES[numero - 1].descricao, EXAMES[numero - 1].epoca);
			break;
		}
		else
		{
			if (EXAMES[i].ocup == 'n' && disponivel == -1)
			{
				disponivel = i;
			}
			printf("\nEsse numero esta ocupado mas o numero %d esta disponivel\n", (disponivel + 1));
			numero = validarInt(1, 99999);
		}
	}
	fclose(f);
}

void mostrarExames()
{
	int i, encontrou = 0;
	for (i = 0; i < 100000; i++)
	{
		if (EXAMES[i].ocup == 's')
		{
			encontrou = 1;
			printf("********************************************************\n");
			printf("**   Numero do exame: %d\n", EXAMES[i].numero);
			printf("**   Ano de curso do exame: %d ano\n", EXAMES[i].ano);
			printf("**   Disciplina do exame: %s\n", EXAMES[i].descricao);
			printf("**   Epoca do exame: %s\n", EXAMES[i].epoca);
		}
	}
	if (!encontrou)
	{
		printf("O ficheiro esta vazio");
	}
}

void criarUC()
{
	int codigo, ano, i, semestre;
	char nome[50], docente[200];

	FILE *f = fopen("UC.txt", "a");
	puts("Digite o codigo da UC: ");

	codigo = validarInt(1, 200);
	for (i = 0; i < 200; i++)
	{
		if (UC[codigo - 1].ocup != 's')
		{
			UC[codigo - 1].codigo = codigo;
			puts("\nDigite o nome da Unidade Curricular: ");
			gets(UC[codigo - 1].nome);

			puts("\nDigite o nome do docente responsavel por esta unidade curricular: ");
			gets(UC[codigo - 1].docente);

			puts("\nDigite o ano da Unidade Curricular: ");
			UC[codigo - 1].ano = validarInt(1, 3);

			puts("\nDigite o semestre da Unidade Curricular: ");
			UC[codigo - 1].semestre = validarInt(1, 2);

			UC[codigo - 1].ocup = 's';
			fprintf(f, "%d;%s;%s;%d;%d\n", UC[codigo - 1].codigo, UC[codigo - 1].nome, UC[codigo - 1].docente, UC[codigo - 1].ano, UC[codigo - 1].semestre);
			break;
		}
		else
		{
			if (UC[i].ocup != 's')
			{
				// printf("Esse codigo esta ocupado mas o codigo %d esta disponivel\n", (i + 1));
				printf("Esse codigo esta ocupado!");
				puts("Qual e o codigo da UC(1-100)?: ");
				codigo = validarInt(1, 99999);
			}
		}
	}
	fclose(f);
}

void mostrarUC()
{
	int i, encontrou = 0;
	for (i = 0; i < 200; i++)
	{
		if (UC[i].ocup == 's')
		{
			encontrou = 1;
			printf("********************************************************\n");
			printf("**  Codigo da UC: %d\n", UC[i].codigo);
			printf("**  Nome da UC: %s\n", UC[i].nome);
			printf("**  Docente Responsavel pela UC: %s\n", UC[i].docente);
			printf("**  Ano da Uc: %d\n", UC[i].ano);
			printf("**  Semestre da UC: %d\n", UC[i].semestre);
		}
	}
	if (!encontrou)
		printf("O ficheiro esta vazio\n");
}

//____________________________________________

FILE *lerAdmin()
{
	FILE *f;
	f = fopen("Admin.txt", "r");
	char linha[1000];
	if (f)
	{
		if (fgets(linha, 100000, f) != NULL)
		{
			while (!feof(f))
			{
				char *ptr;
				int numero = strtol(strtok(linha, ";"), &ptr, 10);
				ADMIN[numero - 1].numero = numero; // Número Mecanográfico
				ADMIN[numero - 1].ocup = 's';
				fgets(linha, 100000, f);
			}
		}
		else
		{
			printf("Ficheiro Vazio\n");
		}
	}
	else
	{
		printf("Ficheiro nao existe");
	}
	fclose(f);
	return f;
}

FILE *lerProf()
{
	FILE *f;
	f = fopen("Professores.txt", "r");
	char linha[1000];
	if (f)
	{
		if (fgets(linha, 100000, f) != NULL)
		{
			while (!feof(f))
			{
				char *ptr;
				int numero = strtol(strtok(linha, ";"), &ptr, 10);
				PROFESSORES[numero - 1].numero = numero; // Número Mecanográfico
				PROFESSORES[numero - 1].ocup = 's';
				fgets(linha, 100000, f);
			}
		}
		else
		{
			printf("Ficheiro Vazio\n");
		}
	}
	else
	{
		printf("Ficheiro nao existe");
	}
	fclose(f);
	return f;
}

FILE *lerAlunos()
{
	FILE *f;
	f = fopen("Alunos.txt", "r");
	char linha[1000];
	if (f)
	{
		if (fgets(linha, 100000, f) != NULL)
		{
			while (!feof(f))
			{
				char *ptr;
				int numero = strtol(strtok(linha, ";"), &ptr, 10);
				ALUNOS[numero - 1].numero = numero;							  // Número Mecanográfico
				strcpy(ALUNOS[numero - 1].nome, strtok(NULL, ";"));			  // Nome
				ALUNOS[numero - 1].ano = strtol(strtok(NULL, ";"), &ptr, 10); // Ano
				strcpy(ALUNOS[numero - 1].curso, strtok(NULL, ";"));		  // Curso
				strcpy(ALUNOS[numero - 1].regime, strtok(NULL, ";"));		  // Regime
				ALUNOS[numero - 1].ocup = 's';
				fgets(linha, 100000, f);
			}
		}
		else
		{
			printf("Ficheiro Vazio\n");
		}
	}
	else
	{
		printf("Ficheiro nao existe");
	}
	fclose(f);
	return f;
}

FILE *lerExame()
{
	FILE *f;
	f = fopen("Exames.txt", "r");
	char linha[1000];
	if (f)
	{
		if (fgets(linha, 100000, f) != NULL)
		{
			while (!feof(f))
			{
				char *ptr;
				int numero = strtol(strtok(linha, ";"), &ptr, 10);
				EXAMES[numero - 1].numero = numero;							  // Número
				EXAMES[numero - 1].ano = strtol(strtok(NULL, ";"), &ptr, 10); // Ano
				strcpy(EXAMES[numero - 1].descricao, strtok(NULL, ";"));	  // Descrição
				strcpy(EXAMES[numero - 1].epoca, strtok(NULL, ";"));		  // Epoca
				EXAMES[numero - 1].ocup = 's';
				fgets(linha, 100000, f);
			}
		}
		else
		{
			printf("Ficheiro Vazio\n");
		}
	}
	else
	{
		printf("Ficheiro nao existe");
	}
	fclose(f);
	return f;
}

FILE *lerUC()
{
	FILE *f;
	f = fopen("UC.txt", "r");
	char linha[10000];
	if (f)
	{
		if (fgets(linha, 100000, f) != NULL)
		{
			while (!feof(f))
			{
				char *ptr;
				int codigo = strtol(strtok(linha, ";"), &ptr, 10);
				UC[codigo - 1].codigo = codigo;
				strcpy(UC[codigo - 1].nome, strtok(NULL, ";"));
				strcpy(UC[codigo - 1].docente, strtok(NULL, ";"));
				UC[codigo - 1].ano = strtol(strtok(NULL, ";"), &ptr, 10);
				UC[codigo - 1].semestre = strtol(strtok(NULL, ";"), &ptr, 10);
				UC[codigo - 1].ocup = 's';
				fgets(linha, 100000, f);
			}
		}
		else
		{
			printf("Ficheiro Vazio\n");
		}
	}
	else
	{
		printf("Nao existem ficheiro com Dados\n");
	}
	fclose(f);
	return f;
}

//____________________________________________

void inicializarAdmin()
{
	int i;
	for (i = 0; i < 100000; i++)
	{
		ADMIN[i].ocup = 'n';
	}
	lerAdmin();
}

void inicializarProfessores()
{
	int i;
	for (i = 0; i < 100000; i++)
	{
		PROFESSORES[i].ocup = 'n';
	}
	lerProf();
}

void inicializarAlunos()
{
	int i;
	for (i = 0; i < 100000; i++)
	{
		ALUNOS[i].ocup = 'n';
	}
	lerAlunos();
}

int inicializarExame()
{
	int i;
	for (i = 0; i < 100000; i++)
	{
		EXAMES[i].ocup = 'n';
	}
	lerExame();
}

//____________________________________________

void alterarDadoAluno()
{
	int op, i, novoNumero, numero, encontrou = 0;
	for (i = 0; i < 100000; i++)
	{
		if (ALUNOS[i].ocup == 's')
		{
			encontrou = 1;
			break;
		}
	}
	if (encontrou)
	{
		do
		{
			printf("Qual e o numero do aluno que deseja alterar?\n");
			numero = validarInt(0, 99999);

			if (ALUNOS[numero - 1].ocup == 's')
			{
				printf("\n");
				printf("****************************************\n");
				printf("**    O que e que deseja alterar?     **\n");
				printf("****************************************\n");
				printf("**      [1] -> Nome                   **\n");
				printf("**      [2] -> Ano                    **\n");
				printf("**      [3] -> Curso                  **\n");
				printf("**      [4] -> Regime                 **\n");
				printf("****************************************\n");
				op = validarInt(1, 4);

				switch (op)
				{
				case 1:
					printf("Digite o novo nome: ");
					gets(ALUNOS[numero - 1].nome);
					break;

				case 2:
					puts("Digite o novo ano: ");
					ALUNOS[numero - 1].ano = validarInt(1, 3);
					break;

				case 3:
					puts("Digite o novo curso: ");
					gets(ALUNOS[numero - 1].curso);
					break;

				case 4:
					validarRegime(ALUNOS[numero - 1].regime);
					break;
				}
			}
			else
			{
				printf("Aluno nao existe! Se deseja sair do ciclo digite 0\n");
			}
		} while (ALUNOS[numero - 1].ocup == 'n' && numero != 0);
		gravarAlunos();
	}
	else
	{
		printf("Nao ha alunos para alterar\n");
	}
}

void alterarDadoProf()
{
	int op, i, novoNumero, numero, encontrou = 0;
	for (i = 0; i < 100000; i++)
	{
		if (PROFESSORES[i].ocup == 's')
		{
			encontrou = 1;
			break;
		}
	}
	if (encontrou)
	{
		do
		{
			printf("Qual e o numero do professor que deseja alterar?\n");
			numero = validarInt(0, 99999);

			if (PROFESSORES[numero - 1].ocup == 's')
			{
				printf("Digite o novo nome: ");
				gets(PROFESSORES[numero - 1].nome);
			}
			else
			{
				printf("Professor nao existe! Se deseja sair do ciclo digite 0\n");
			}
		} while (PROFESSORES[numero - 1].ocup == 'n' && numero != 0);
		gravarProf();
	}
	else
	{
		printf("Nao ha professores para alterar\n");
	}
}

void alterarDadoExames()
{
	int op, i, novoNumero, numero, encontrou = 0;
	char descricao[50], epoca[50];
	for (i = 0; i < 100000; i++)
	{
		if (EXAMES[i].ocup == 's')
		{
			encontrou = 1;
			break;
		}
	}
	if (encontrou)
	{
		do
		{
			printf("Qual e o numero do exame que deseja alterar?\n");
			numero = validarInt(0, 99999);

			if (EXAMES[numero - 1].ocup == 's')
			{
				printf("\n*****************************************\n");
				printf("**    O que e que deseja alterar?      **\n");
				printf("\n*****************************************\n");
				printf("**      [1] -> Descricao               **\n");
				printf("**      [2] -> Epoca                   **\n");
				printf("**      [3] -> Ano                     **\n");
				printf("*****************************************\n");
				op = validarInt(1, 3);

				switch (op)
				{
				case 1:
					printf("Digite a nova descricao: ");
					gets(EXAMES[numero - 1].descricao);
					break;

				case 2:
					printf("\n");
					printf("*******************************\n");
					printf("**  Digite a epoca do exame  **\n");
					printf("*******************************\n");
					printf("**	[1] - Normal             **\n");
					printf("**	[2] - Recurso            **\n");
					printf("**	[3] - Especial           **\n");
					printf("*******************************\n");
					op = validarInt(1, 3);

					switch (op)
					{
					case 1:
						strcpy(epoca, "Normal");
						break;
					case 2:
						strcpy(epoca, "Recurso");
						break;
					case 3:
						strcpy(epoca, "Especial");
						break;

					default:
						break;
					}
					break;

				case 3:
					puts("Digite o novo ano (1-3): ");
					gets(EXAMES[numero - 1].ano);
					break;
				}
			}
			else
			{
				printf("Exame nao existe! Se deseja sair do ciclo digite 0\n");
			}
		} while (EXAMES[numero - 1].ocup == 'n' && numero != 0);
		gravarAlunos();
	}
	else
	{
		printf("Nao ha exames para alterar\n");
	}
}

void alterarDadoUC()
{
	int op, i, novoCodigo, codigo, encontrou = 0, disponivel = -1;
	for (i = 0; i < 200; i++)
	{
		if (UC[i].ocup == 's')
		{
			encontrou = 1;
			break;
		}
	}
	if (encontrou)
	{
		do
		{
			printf("Qual e o codigo da UC que deseja alterar?\n");
			codigo = validarInt(1, 200);
			if (UC[codigo - 1].ocup == 's')
			{
				printf("\n");
				printf("***************************************************\n");
				printf("**          O que deseja alterar?                **\n");
				printf("***************************************************\n");
				printf("**      1 -> Codigo                              **\n");
				printf("**      2 -> Nome da UC                          **\n");
				printf("**      3 -> Docente Responsavel pela UC         **\n");
				printf("**      4 -> Ano da UC                           **\n");
				printf("**      5 -> Semestre                            **\n");
				printf("***************************************************\n");
				op = validarInt(1, 5);

				switch (op)
				{
				case 1:
					printf("Coloque o novo codigo: ");
					novoCodigo = validarInt(1, 200);
					for (i = 0; i < 200; i++)
					{
						if (UC[novoCodigo - 1].ocup != 's')
						{
							UC[novoCodigo - 1].codigo = novoCodigo;
							strcpy(UC[novoCodigo - 1].nome, UC[codigo - 1].nome);
							strcpy(UC[novoCodigo - 1].docente, UC[codigo - 1].docente);
							UC[novoCodigo - 1].ano = UC[codigo - 1].ano;
							UC[novoCodigo - 1].semestre = UC[codigo - 1].semestre;
							UC[novoCodigo - 1].ocup = 's';
							UC[codigo - 1].ocup = 'n';
							mostrarUC();
							break;
						}
						else
						{
							if (UC[i].ocup != 's')
							{
								if (UC[i].ocup != 's' && disponivel == -1)
									disponivel = i;
								// printf("Esse codigo esta ocupado mas o codigo %d esta disponivel", (i + 1));
								printf("Coloque o novo codigo: ");
								novoCodigo = validarInt(1, 200);
							}
						}
					}
					codigo = 0;
					break;
				case 2:
					puts("Digite o nome da UC:");
					gets(UC[codigo - 1].nome);
					break;
				case 3:
					puts("Digite o nome do docente responsavel pela UC:");
					gets(UC[codigo - 1].docente);
					break;
				case 4:
					puts("Digite o ano daa UC(1-3): ");
					UC[codigo - 1].ano = validarInt(1, 3);
					break;
				case 5:
					puts("Digite o semestre da UC: ");
					UC[codigo - 1].semestre = validarInt(1, 2);
					break;
				}
			}
			else
			{
				printf("UC nao existe, Se deseja sair do ciclo coloque 0\n");
			}
		} while (UC[codigo - 1].ocup != 's' && codigo != 0);
		gravarUC();
	}
	else
	{
		printf("Nao ha UC por alterar\n");
	}
}

void gravarUC()
{
	int i;
	FILE *f = fopen("UC.txt", "w");
	for (i = 0; i < 200; i++)
	{
		if (UC[i].ocup == 's')
		{
			fflush(NULL);
			printf("%d;%s;%s;%d;%d\n", UC[i].codigo, UC[i].nome, UC[i].docente, UC[i].ano, UC[i].semestre);
			fprintf(f, "%d;%s;%s;%d;%d\n", UC[i].codigo, UC[i].nome, UC[i].docente, UC[i].ano, UC[i].semestre);
			puts("do");
		}
	}
	puts("do1");
	fclose(f);
	puts("do2");
}

int gravarAlunos()
{
	int i;
	FILE *f = fopen("Alunos.txt", "w");
	for (i = 0; i < 100000; i++)
	{
		if (ALUNOS[i].ocup == 's')
		{
			printf("\n");
			fflush(NULL);
			fprintf(f, "%d;%s;%d;%s;%s", ALUNOS[i].numero, ALUNOS[i].nome, ALUNOS[i].ano, ALUNOS[i].curso, ALUNOS[i].regime);
		}
	}
	fclose(f);
}

void apagarAluno()
{
	int escolha, numero, i, encontrou = 0;
	for (i = 0; i < 100000; i++)
	{
		if (ALUNOS[i].ocup == 's')
		{
			encontrou = 1;
			break;
		}
	}
	if (encontrou)
	{
		printf("*******************************************\n");
		printf("Tem acerteza que dejesa apagar algum aluno?\n");
		printf("*******************************************\n");
		printf("**   [0] -> Sair                         **\n");
		printf("**   [1] -> Continuar                    **\n");
		printf("*******************************************\n");
		escolha = validarInt(0, 1);

		switch (escolha)
		{
		case 0:
			break;

		case 1:
			limpar();
			printf("Introduza o numero do aluno que deseja apagar:\n");
			numero = validarInt(1, 99999);
			if (ALUNOS[numero - 1].ocup == 's')
			{
				ALUNOS[numero - 1].ocup = 'n';
				puts("Aluno apagado com sucesso");
				gravarAlunos();
				getch();
			}
			else
			{
				puts("O Aluno nao existe");
				getch();
			}
			break;

		default:
			printf("Escolha invalida\n");
			break;
		}
	}
	else
	{
		printf("Nao ha alunos para apagar\n");
		getch();
	}
}

int gravarProf()
{
	int i;
	FILE *f = fopen("Professores.txt", "w");
	for (i = 0; i < 100000; i++)
	{
		if (PROFESSORES[i].ocup == 's')
		{
			printf("\n");
			fflush(NULL);
			fprintf(f, "%d;%s", PROFESSORES[i].numero, PROFESSORES[i].nome);
		}
	}
	fclose(f);
}

void apagarProf()
{
	int escolha, numero, i, encontrou = 0;
	for (i = 0; i < 100000; i++)
	{
		if (PROFESSORES[i].ocup == 's')
		{
			encontrou = 1;
			break;
		}
	}
	if (encontrou)
	{
		printf("***********************************************\n");
		printf("Tem acerteza que dejesa apagar algum professor?\n");
		printf("***********************************************\n");
		printf("**   [0] -> Sair                             **\n");
		printf("**   [1] -> Continuar                        **\n");
		printf("***********************************************\n");
		escolha = validarInt(0, 1);

		switch (escolha)
		{
		case 0:
			break;

		case 1:
			limpar();
			printf("Introduza o numero do professor que deseja apagar:\n");
			numero = validarInt(1, 99999);
			if (PROFESSORES[numero - 1].ocup == 's')
			{
				PROFESSORES[numero - 1].ocup = 'n';
				puts("Professor apagado com sucesso");
				gravarProf();
				getch();
			}
			else
			{
				puts("O professor nao existe");
				getch();
			}
			break;

		default:
			printf("Escolha invalida\n");
			break;
		}
	}
	else
	{
		printf("Nao ha professores para apagar\n");
		getch();
	}
}

// Apagar UC
void apagar()
{
	int codigo, escolha, i, encontrou = 0;
	for (i = 0; i < 100000; i++)
	{
		if (UC[i].ocup == 's')
		{
			encontrou = 1;
			break;
		}
	}
	if (encontrou)
	{

		printf("***********************************************\n");
		printf("**  Tem acerteza que dejesa apagar algum UC? **\n");
		printf("***********************************************\n");
		printf("**   [0] -> Sair                             **\n");
		printf("**   [1] -> Continuar                        **\n");
		printf("***********************************************\n");
		escolha = validarInt(0, 1);

		switch (escolha)
		{
		case 0:
			break;

		case 1:

			printf("Qual e o codigo da UC que deseja apagar?\n");
			codigo = validarInt(1, 99999);
			if (UC[codigo - 1].ocup == 's')
			{
				UC[codigo - 1].ocup = 'n';
				puts("UC apagada com sucesso");
				gravarUC();
			}
			else
			{
				puts("A seguinte UC nao existe");
			}
			break;
			
		default:
			printf("Escolha invalida\n");
			break;
		}
	}
	else
	{
		printf("Nao ha UC por apagar\n");
	}
}
