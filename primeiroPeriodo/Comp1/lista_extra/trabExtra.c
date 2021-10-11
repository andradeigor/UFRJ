#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 100
typedef struct _ENDERECO
{
    char rua[50];
    int numero;
    char complemento[50];
    char bairro[100];
    char cep[10];
    char cidade[50];
    char estado[50];
    char pais[50];
}endereco;
typedef struct _TELEFONE
{
    int ddd;
    int telefone;
}telefone;
typedef struct ANIVERSARIO
{
    int dia;
    int mes;
    int ano;
}aniversario;

typedef struct _CONTATOS
{
    char nome[50];
    char email[100];
    endereco enderecoContato;
    telefone telefoneContato;
    aniversario aniversarioContato;
    char observacao[200];

}contato;

void adicionaContato(contato *c1, int indice){

    printf("por favor, informe o nome: ");
    fgets((c1+indice)->nome,49,stdin );
    (c1+indice)->nome[strcspn((c1+indice)->nome,"\n")] = 0;

    printf("por favor, informe o email: ");
    fgets((c1+indice)->email,49,stdin );
    (c1+indice)->email[strcspn((c1+indice)->email,"\n")] = 0;

    printf("por favor, informe a rua: ");
    fgets(((c1+indice)->enderecoContato).rua,49,stdin );
   ((c1+indice)->enderecoContato).rua[strcspn(((c1+indice)->enderecoContato).rua,"\n")] = 0;

    printf("por favor, informe o numero: ");
    scanf("%d", &((c1+indice)->enderecoContato).numero);
    while (getchar() != '\n');

    printf("por favor, informe o complemento: ");
    fgets(((c1+indice)->enderecoContato).complemento,49,stdin );
    ((c1+indice)->enderecoContato).complemento[strcspn(((c1+indice)->enderecoContato).complemento,"\n")] = 0;

    printf("por favor, informe o bairro: ");
    fgets(((c1+indice)->enderecoContato).bairro,99,stdin );   
    ((c1+indice)->enderecoContato).bairro[strcspn(((c1+indice)->enderecoContato).bairro,"\n")] = 0;

    printf("por favor, informe o cep ex(10100-100): ");
    fgets(((c1+indice)->enderecoContato).cep,10,stdin );
    ((c1+indice)->enderecoContato).cep[strcspn(((c1+indice)->enderecoContato).cep,"\n")] = 0;

    printf("por favor, informe a cidade: ");
    fgets(((c1+indice)->enderecoContato).cidade,49,stdin );
    ((c1+indice)->enderecoContato).cidade[strcspn(((c1+indice)->enderecoContato).cidade,"\n")] = 0;

    printf("por favor, informe o estado: ");
    fgets(((c1+indice)->enderecoContato).estado,49,stdin );
    ((c1+indice)->enderecoContato).estado[strcspn(((c1+indice)->enderecoContato).estado,"\n")] = 0;

    printf("por favor, informe a pais: ");
    fgets(((c1+indice)->enderecoContato).pais,49,stdin );
    ((c1+indice)->enderecoContato).pais[strcspn(((c1+indice)->enderecoContato).pais,"\n")] = 0;

    printf("por favor, informe o telefone com ddd ex(21 999999999): ");
    scanf("%d %d",&((c1+indice)->telefoneContato).ddd,&((c1+indice)->telefoneContato).telefone );
    while (getchar() != '\n');
    printf("por favor, informe o aniversário do contato ex(01/01/2001): ");
    scanf("%d/%d/%d",&((c1+indice)->aniversarioContato).dia,&((c1+indice)->aniversarioContato).mes,&((c1+indice)->aniversarioContato).ano );
    while (getchar() != '\n');
}

int main(){
    contato *contatos;
    int i;
    contatos = (contato*) malloc(sizeof(contato)*SIZE);
    for(i=0;i<5;i++){
        adicionaContato(contatos, i);
    }
    return 0;
}
