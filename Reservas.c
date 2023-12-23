#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "Reservas.h"
#include "GestaoDeDados.h"

int *AgendarReserva(int *count, int totAcomod, reservas *res, acomodacoes *ageAcomod){
    time_t t1;
    time_t t2;
    time_t dataAtual = time(NULL); //Valor de retorno é a quantidade de segundos passados desde 1 de Janeiro de 1970
    struct tm *tm;
    int ano, mes;
    char data1[20];
    char data2[20];
    char pesqCatAcomod[50], facAcomod[100];
    int i, j, qtdCriRes, qtdAdultRes;
    int ageCodRes;
    int verifRes;
    int *x;
    int y = 0;
    x = calloc(7 , sizeof(int));
    x[0] = 0;

    tm = localtime(&dataAtual); //O ponteiro "tm" é setado para a data atual
    bzero(tm, sizeof(*tm));

    printf("Digite a data inicial da reserva (DD/MM/AAAA): ");
    fgets(data1, sizeof(data1), stdin);
    sscanf(data1, "%d/%d/%d", &tm->tm_mday, &mes, &ano);
    setbuf(stdin, NULL);

    tm->tm_isdst = 0; //Regula a data de acordo com o horário de verão

    tm->tm_year = ano - 1900;
    tm->tm_mon = mes - 1;

    t1 = mktime(tm);

    printf("Digite a data final da reserva (DD/MM/AAAA): ");
    fgets(data2, sizeof(data2), stdin);
    sscanf(data2, "%d/%d/%d", &tm->tm_mday, &mes, &ano); /*Transforma a string em formato de data em 3 inteiros,
                                                         passando para a struct tm*/
    setbuf(stdin, NULL);

    tm->tm_year = ano - 1900;
    tm->tm_mon = mes - 1;

    t2 = mktime(tm); //transforma os valores da struct tm no valor dos segundos passados desde 1 de Janeiro de 1970

    printf("Informe o código da acomodação que deseja agendar: ");
    scanf("%d", &ageCodRes);
    setbuf(stdin, NULL);

    printf("Digite a categoria de acomodoção que deseja agendar: ");
    fgets(pesqCatAcomod, sizeof(pesqCatAcomod), stdin);

    pesqCatAcomod[strcspn(pesqCatAcomod, "\n")] = 0;

    printf("Digite as facilidade da acomodação que deseja reservar : ");
    fgets(facAcomod, sizeof(facAcomod), stdin);


    facAcomod[strcspn(facAcomod, "\n")] = 0;
    
    printf("Digite a quantidade de crianças que deseja acomodar: ");
    scanf("%d", &qtdCriRes);
    setbuf(stdin, NULL);

    printf("Digite a quantidade de adultos que deseja acomodar: ");
    scanf("%d", &qtdAdultRes);
    setbuf(stdin, NULL);

    for(i=0; i<totAcomod; i++){ // Laço para verificar se o código informado na reserva existe dentre as acomodações.
        if(ageCodRes != ageAcomod[i].codigoAcomod){
            x[0] = 1;
        }else{
            x[0] = 0;
            break;
        }
    }

    for(i=0; i<*count; i++){ // Laço para verificar se a data está dísponível para reserva.
        if(ageCodRes == res[i].codAcomodRes){
            if((t2 <= res[i].dataFinal && t1 >= res[i].dataIni) ||
                (t2 >= res[i].dataIni && t1 <= res[i].dataIni) ||
                (t1 <= res[i].dataFinal && t2 >= res[i].dataFinal)){
                x[1] = 1;
            }
        }
    }

    for(i=0; i<6; i++){ // Laço para verificar se o restante dos campos estão disponíveis para reserva.
        if(ageCodRes == ageAcomod[i].codigoAcomod){
            if(strcmp(ageAcomod[i].categoria.descricaoCat, pesqCatAcomod) != 0){
                x[2] = 1;
            }

            if(strstr(ageAcomod[i].facilidades, facAcomod) == NULL){
                x[3] = 1;
            }

            if(ageAcomod[i].categoria.QuantCriancas < qtdCriRes){
                x[4] = 1;
            }
            if(ageAcomod[i].categoria.QuantAdultos < qtdAdultRes){
                x[5] = 1;
            }
        }
    }

    for(i=0; i<7; i++){ // Laço para realizar o somatório das verificações.
        y += x[i];
    }

    x[6] = y;

    if(x[6] == 0){ // Agendamento da reserva.
        printf("Digite o nome do responsável pela reserva que deseja agendar: ");
        fgets(res[*count].nomePessoa, sizeof(res[*count].nomePessoa), stdin);
        printf("Digite o sexo do responsável: ");
        fgets(res[*count].sexo, sizeof(res[*count].sexo), stdin);
        res[*count].nomePessoa[strcspn(res[*count].nomePessoa, "\n")] = 0;
        res[*count].sexo[strcspn(res[*count].sexo, "\n")] = 0;
        res[*count].codAcomodRes = ageCodRes;
        strcpy(res[*count].faciRes, facAcomod);
        strcpy(res[*count].catReserva, pesqCatAcomod);
        strcpy(res[*count].strDataIni, data1);
        strcpy(res[*count].strDataFinal, data2);
        res[*count].dataIni = t1;
        res[*count].dataFinal = t2;
        ++*count;
        }
    return x;
}

void CancelarReserva(int *x, struct Reserva *res){
    int i, codRes;
    char pesqNomeRes[50];

    printf("Digite o nome do responsável pela reserva que deseja cancelar: ");
    fgets(pesqNomeRes, sizeof(pesqNomeRes), stdin);

    for(i=0; i<*x; i++){ // Laço para verificar o nome informado dentre as reservas.
        if(strcmp(res[i].nomePessoa, pesqNomeRes) == 0){
            codRes = i;
        }
    }
    while(codRes < *x){ // Função para canelar a reserva.
        res[codRes] = res[codRes+1];
        codRes++;
    }
    --*x;
}
