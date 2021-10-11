#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 100
#define SIZEACTUAL 5
typedef struct _ENDERECO
{
    char rua[50];
    int numero;
    char complemento[50];
    char bairro[100];
    char cep[20];
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
int buscaNome(char nome[]){
    int i=0;
    while(1){
        if(nome[i] == ' ' ){
            break;
        }
        i++;
    }
    return i;
}
void adicionaContato(contato *c1, int indice){

    printf("por favor, informe o nome: \n");
    fgets((c1+indice)->nome,49,stdin );
    (c1+indice)->nome[strcspn((c1+indice)->nome,"\n")] = 0;
    printf("%s \n",(c1+indice)->nome);

    printf("por favor, informe o email: \n");
    fgets((c1+indice)->email,49,stdin );
    (c1+indice)->email[strcspn((c1+indice)->email,"\n")] = 0;
    printf("%s \n",(c1+indice)->email);

    printf("por favor, informe a rua: \n");
    fgets(((c1+indice)->enderecoContato).rua,49,stdin );
   ((c1+indice)->enderecoContato).rua[strcspn(((c1+indice)->enderecoContato).rua,"\n")] = 0;
    printf("%s \n",((c1+indice)->enderecoContato).rua);

    printf("por favor, informe o numero: \n");
    scanf("%d", &((c1+indice)->enderecoContato).numero);
    while (getchar() != '\n');
    printf("%d \n",((c1+indice)->enderecoContato).numero);

    printf("por favor, informe o complemento: \n");
    fgets(((c1+indice)->enderecoContato).complemento,49,stdin );
    ((c1+indice)->enderecoContato).complemento[strcspn(((c1+indice)->enderecoContato).complemento,"\n")] = 0;
    printf("%s \n",((c1+indice)->enderecoContato).complemento);

    printf("por favor, informe o bairro: \n");
    fgets(((c1+indice)->enderecoContato).bairro,99,stdin );   
    ((c1+indice)->enderecoContato).bairro[strcspn(((c1+indice)->enderecoContato).bairro,"\n")] = 0;
    printf("%s \n",((c1+indice)->enderecoContato).bairro);

    printf("por favor, informe o cep ex(10100-100): \n");
    fgets(((c1+indice)->enderecoContato).cep,20,stdin );
    ((c1+indice)->enderecoContato).cep[strcspn(((c1+indice)->enderecoContato).cep,"\n")] = 0;
    printf("%s \n",((c1+indice)->enderecoContato).cep);

    printf("por favor, informe a cidade: \n");
    fgets(((c1+indice)->enderecoContato).cidade,49,stdin );
    ((c1+indice)->enderecoContato).cidade[strcspn(((c1+indice)->enderecoContato).cidade,"\n")] = 0;
    printf("%s \n",((c1+indice)->enderecoContato).cidade);

    printf("por favor, informe o estado: \n");
    fgets(((c1+indice)->enderecoContato).estado,49,stdin );
    ((c1+indice)->enderecoContato).estado[strcspn(((c1+indice)->enderecoContato).estado,"\n")] = 0;
    printf("%s \n",((c1+indice)->enderecoContato).estado);

    printf("por favor, informe a pais: \n");
    fgets(((c1+indice)->enderecoContato).pais,49,stdin );
    ((c1+indice)->enderecoContato).pais[strcspn(((c1+indice)->enderecoContato).pais,"\n")] = 0;
    printf("%s \n",((c1+indice)->enderecoContato).pais);

    printf("por favor, informe o telefone com ddd ex(21 999999999): \n");
    scanf("%d %d",&((c1+indice)->telefoneContato).ddd,&((c1+indice)->telefoneContato).telefone );
    while (getchar() != '\n');
    printf("%d %d \n",((c1+indice)->telefoneContato).ddd,((c1+indice)->telefoneContato).telefone);

    printf("por favor, informe o aniversário do contato ex(01/01/2001): \n");
    scanf("%d/%d/%d",&((c1+indice)->aniversarioContato).dia,&((c1+indice)->aniversarioContato).mes,&((c1+indice)->aniversarioContato).ano );
    while (getchar() != '\n');
    printf("%d/%d/%d \n",((c1+indice)->aniversarioContato).dia,((c1+indice)->aniversarioContato).mes, ((c1+indice)->aniversarioContato).ano);

    printf("por favor, informe uma observação para o contato: \n");
    fgets((c1+indice)->observacao,49,stdin );
    (c1+indice)->observacao[strcspn((c1+indice)->observacao,"\n")] = 0;
    printf("%s \n",(c1+indice)->observacao);
}


int PrimeiroNome(contato contato, char nome[]){
    int j ,fimNome, verificaNome=1;
    fimNome = buscaNome(contato.nome);
    for(j=0;j<fimNome;j++){
        if(contato.nome[j] != nome[j]){
            verificaNome =0;
        }
    }
    return verificaNome;
    
}
int procuraMes(contato contato, int mes){
    
    if(contato.aniversarioContato.mes == mes ){
        return 1;
    }
    return 0;
}

int procuraDia(contato contato, int dia){
    
    if(contato.aniversarioContato.dia == dia ){
        return 1;
    }
    return 0;
}

void ordenaAgenda(contato *pessoa, int size){
    int i=0, j, ordenei=0;
    contato aux;
    do{
        ordenei = 0;
        for(i=0;i<size-1;i++){
                if(strcmp(pessoa[i].nome,pessoa[i+1].nome) < 0){
                    printf("cheguei aqui\n");
                    aux = pessoa[i];
                    pessoa[i] = pessoa[i+1];
                    pessoa[i+1] = aux;
                    ordenei++;
                }
        }

    }while(ordenei);

}
int main(){
    contato *agenda;
    int i, mesParaProcurar, diaParaProcurar;
    char nomeProcura[50];
    agenda = (contato*) malloc(sizeof(contato)*SIZE);
    for(i=0;i<SIZEACTUAL;i++){
        adicionaContato(agenda, i);
    }
    setbuf(stdin, NULL);
    printf("Por favor, digite o nome que deseja procurar: \n");
    fgets(nomeProcura, 49, stdin);
    printf("%s\n", nomeProcura);
    nomeProcura[strcspn(nomeProcura,"\n")] = 0;
    for (i = 0; i < SIZEACTUAL; i++){
    
        if(PrimeiroNome(agenda[i], nomeProcura)){
            printf("Contato encontrado!\n");
            printf("-----------------------\n");
            printf("Nome:%s\n", agenda[i].nome);
            printf("Email:%s\n", agenda[i].email);
            printf("rua:%s\n", agenda[i].enderecoContato.rua);
            printf("numero:%d\n", agenda[i].enderecoContato.numero);
            printf("complemento:%s\n", agenda[i].enderecoContato.complemento);
            printf("bairro:%s\n", agenda[i].enderecoContato.bairro);
            printf("cep:%s\n", agenda[i].enderecoContato.cep);
            printf("cidade:%s\n", agenda[i].enderecoContato.cidade);
            printf("estado:%s\n", agenda[i].enderecoContato.estado);
            printf("pais:%s\n", agenda[i].enderecoContato.pais);
            printf("telefone:(%d) %d \n", agenda[i].telefoneContato.ddd, agenda[i].telefoneContato.telefone);
            printf("aniversario:%d/%d/%d\n", agenda[i].aniversarioContato.dia, agenda[i].aniversarioContato.mes, agenda[i].aniversarioContato.ano);
            printf("obeservação:%s\n", agenda[i].observacao);
            printf("-----------------------\n");
        }
    }
    printf("Por favor, digite o mes que deseja procurar:ex(05) \n");
    scanf("%d", &mesParaProcurar);
    printf("%d\n", mesParaProcurar);
    for (i = 0; i < SIZEACTUAL; i++){
         if(procuraMes(agenda[i],mesParaProcurar)){
            printf("Contato encontrado!\n");
            printf("-----------------------\n");
            printf("Nome:%s\n", agenda[i].nome);
            printf("aniversario:%d/%d/%d\n", agenda[i].aniversarioContato.dia, agenda[i].aniversarioContato.mes, agenda[i].aniversarioContato.ano);     
            printf("-----------------------\n");
         }
    }
    printf("Por favor, digite o dia e o mes que deseja procurar:ex(05/06) \n");
    scanf("%d/%d", &diaParaProcurar, &mesParaProcurar);
    printf("%d/%d\n", diaParaProcurar, mesParaProcurar);
    for (i = 0; i < SIZEACTUAL; i++){
         if(procuraDia(agenda[i],diaParaProcurar) && procuraMes(agenda[i],mesParaProcurar)){
            printf("Contato encontrado!\n");
            printf("-----------------------\n");
            printf("Nome:%s\n", agenda[i].nome);
            printf("aniversario:%d/%d/%d\n", agenda[i].aniversarioContato.dia, agenda[i].aniversarioContato.mes, agenda[i].aniversarioContato.ano);     
            printf("-----------------------\n");
         }
    }
    ordenaAgenda(agenda, SIZEACTUAL);
    for (i = 0; i < SIZEACTUAL; i++){
        printf("-----------------------\n");
        printf("Nome:%s\n", agenda[i].nome);

        printf("-----------------------\n");
    }
    return 0;
}
