#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// estrutura de dados 
typedef struct
{
    int valor_arabico;
    const char *simbolo_romano;
} MapeamentoRomano;

// tabela com os algarismos  romanos validos
MapeamentoRomano tabela[] = {
    {1000, "M"},
    {500, "D"},
    {100, "C"},
    {50, "L"},
    {10, "X"},
    {5, "V"},
    {1, "I"}};
const int Tamanho_Tabela = sizeof(tabela) / sizeof(tabela[0]);

// funcao que obtem um valor mapeado da tabela
int Obter_Valor(char c)
{
    for (int i = 0; i < Tamanho_Tabela; i++)
    {
        if (tabela[i].simbolo_romano[0] == c)
        {
            return tabela[i].valor_arabico;
        }
    }
    return 0; // retorna 0 em caso de o alagarismo ser invalido
}

// funcao que faz a conversao do numero romano em numero decimal
int Conver_Romano_Decimal(const char *c) {
    int total = 0;
    int n = strlen(c);

    for (int i = 0; i < n; i++)
    {
        int atual = Obter_Valor(c[i]);

        if (i + 1 < n)
        {
            int proximo = Obter_Valor(c[i + 1]);

            if (atual < proximo)
            {

                total += (proximo - atual);
                i++;
            }
            else
            {
                total += atual;
            }
        }
        else
        {
            total += atual;
        }
    }
    return total;
}

// funcao de validacao - verifica se o algarismo é um algarismo romano valido
int Algarismo_Valido(const char *c)
{
    switch (*c)
    {
    case 'I':
    case 'V':
    case 'X':
    case 'L':
    case 'C':
    case 'D':
    case 'M':
        return 1;
    default:
        return 0;
    }
}

// funcao de validacao - em caso de nao passar na primeira validacao, a funcao diz onde o algarismo errado esta na string
int Validar_String(const char *c) {
    if (strlen(c) == 0) return 0;

    for (int i = 0; i < strlen(c); i++) {
        if (!Algarismo_Valido(&c[i])) {
            printf("ERRO: O caractere '%c' na posicao %d nao e um algarismo romano valido!\n", c[i], i + 1);
            return 0; 
        }
    }
    return 1;
}


void Verifica_Input(const char *romano) {

    int Validacao = Validar_String(romano); 
    
    if (Validacao == 1) {
        int numero_convertido = Conver_Romano_Decimal(romano);
        printf("ALgarismo convertido: %d", numero_convertido);
    }
}

int main() {
    char romano[16];
    printf("Digite um numero romano: ");
    scanf("%s", romano);
    Verifica_Input(romano);
}