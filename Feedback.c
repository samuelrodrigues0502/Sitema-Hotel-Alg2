#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Arquivos.h"
#include "Transacoes.h"
#include "Reservas.h"
#include "GestaoDeDados.h"
#include "Feedback.h"
#include <time.h>

void RelatorioHospedes(char *sexoHosp, int codIni, int codFin, hospede *hosp){

    int i;

    printf("%s", sexoHosp);
    printf("%d", codIni);
    printf("%d", codFin);

    FILE *arqHosp = fopen("Relatório de Hóspedes.txt", "w");



            for(i=codIni; i<=codFin; i++){
                if(strcmp(hosp[i-1].sexo, sexoHosp) == 0){
                    fprintf(arqHosp, "%d;", hosp[i-1].codigoHospede);

                    fprintf(arqHosp, "%s;", hosp[i-1].nomeHospede);
                    hosp[i-1].nomeHospede[strcspn(hosp[i-1].nomeHospede, "\n")] = 0;

                    fprintf(arqHosp, "%s;", hosp[i-1].cpf);
                    hosp[i-1].cpf[strcspn(hosp[i-1].cpf, "\n")] = 0;

                    hosp[i-1].telHospede[strcspn(hosp[i-1].telHospede, "\n")] = 0;
                    fprintf(arqHosp, "%s;", hosp[i-1].telHospede);

                    hosp[i-1].emailHospede[strcspn(hosp[i-1].emailHospede, "\n")] = 0;
                    fprintf(arqHosp, "%s;", hosp[i-1].emailHospede);

                    hosp[i-1].sexo[strcspn(hosp[i-1].sexo, "\n")] = 0;
                    fprintf(arqHosp, "%s;", hosp[i-1].sexo);

                    hosp[i-1].estCivHospede[strcspn(hosp[i-1].estCivHospede, "\n")] = 0;
                    fprintf(arqHosp, "%s;", hosp[i-1].estCivHospede);

                    hosp[i-1].dataNasci[strcspn(hosp[i-1].dataNasci, "\n")] = 0;
                    fprintf(arqHosp, "%s;", hosp[i-1].dataNasci);

                    hosp[i-1].enderHosp.num[strcspn(hosp[i-1].enderHosp.num, "\n")] = 0;
                    fprintf(arqHosp, "%s;", hosp[i-1].enderHosp.num);

                    hosp[i-1].enderHosp.rua[strcspn(hosp[i-1].enderHosp.rua, "\n")] = 0;
                    fprintf(arqHosp, "%s;", hosp[i-1].enderHosp.rua);

                    hosp[i-1].enderHosp.bairro[strcspn(hosp[i-1].enderHosp.bairro, "\n")] = 0;
                    fprintf(arqHosp, "%s;", hosp[i-1].enderHosp.bairro);

                    hosp[i-1].enderHosp.cidade[strcspn(hosp[i-1].enderHosp.cidade, "\n")] = 0;
                    fprintf(arqHosp, "%s;", hosp[i-1].enderHosp.cidade);

                    hosp[i-1].enderHosp.estado[strcspn(hosp[i-1].enderHosp.estado, "\n")] = 0;
                    fprintf(arqHosp, "%s;", hosp[i-1].enderHosp.estado);

                    hosp[i-1].enderHosp.pais[strcspn(hosp[i-1].enderHosp.pais, "\n")] = 0;
                    fprintf(arqHosp, "%s;", hosp[i-1].enderHosp.pais);
                }
            }
            fclose(arqHosp);
}

void RelatorioAcomodacoes(int op, char *categoria, int codIni, int codFin, acomodacoes *acomodacoes, char *dataDisp, reservas *reserv, int *pTotRes){

    int i, mes, ano, j;
    time_t t1;
    time_t dataAtual = time(NULL);
    struct tm *tm;
    tm = localtime(&dataAtual);

    printf(" %s", categoria);
    printf(" %s", dataDisp);
    printf(" %d\n", codIni);
    printf(" %d\n", codFin);

    sscanf(dataDisp, "%d/%d/%d", &tm->tm_mday, &mes, &ano);
    tm->tm_isdst = 0; //Regula a data de acordo com o horário de verão

    tm->tm_year = ano - 1900;
    tm->tm_mon = mes - 1;

    t1 = mktime(tm);

    FILE *arqAcomod = fopen("Relatório de Acomodações.txt", "w");

    switch(op){
        case 1:
            for(i=codIni; i<=codFin; i++){
                if(strcmp(acomodacoes[i-1].categoria.descricaoCat, categoria) == 0){
                    for(j=0; j<=*pTotRes; j++){
                        if(acomodacoes[i-1].codigoAcomod == reserv[j].codAcomodRes){
                            if(reserv[j].dataFinal<=t1 || reserv[j].dataIni>=t1){
                                fprintf(arqAcomod, "%d;", acomodacoes[i-1].codigoAcomod);

                                fprintf(arqAcomod, "%s;", acomodacoes[i-1].descricaoAcomod);
                                acomodacoes[i-1].descricaoAcomod[strcspn(acomodacoes[i-1].descricaoAcomod, "\n")] = 0;

                                fprintf(arqAcomod, "%s;", acomodacoes[i-1].facilidades);
                                acomodacoes[i-1].facilidades[strcspn(acomodacoes[i-1].facilidades, "\n")] = 0;

                                acomodacoes[i-1].categoria.descricaoCat[strcspn(acomodacoes[i-1].categoria.descricaoCat, "\n")] = 0;
                                fprintf(arqAcomod, "%s;", acomodacoes[i-1].categoria.descricaoCat);
                            }
                        }
                    }
                }
            }
            fclose(arqAcomod);
        break;

        case 2:
            for(i=codIni; i<=codFin; i++){
                if(strcmp(acomodacoes[i-1].categoria.descricaoCat, categoria) == 0){
                    for(j=0; j<=*pTotRes; j++){
                        if(acomodacoes[i-1].codigoAcomod == reserv[j].codAcomodRes){
                            if(reserv[j].dataFinal<=t1 || reserv[j].dataIni>=t1){
                                printf("\n Código da acomodação: %d", acomodacoes[i-1].codigoAcomod);
                                printf("\n Descrição da acomodação : %s", acomodacoes[i-1].descricaoAcomod);
                                printf("\n Facilidades da acomodação: %s", acomodacoes[i-1].facilidades);
                                printf("\n Categoria da acomodação: %s", acomodacoes[i-1].categoria.descricaoCat);
                            }
                        }
                    }
                }
            }
        break;
    }
}

void RelatorioReservas(int opHosp, int opAcomod, char *nomeHosp, char *sexoHosp, char *categoria, int codAcomod, int *pTotRes, reservas *reserv){
    int i;

    FILE *arqReserva = fopen("Relatório de Reservas.txt", "w");

            if(opHosp == 1 && opAcomod == 1){
                for(i=0; i<*pTotRes; i++){
                    if(strcmp(reserv[i].catReserva, categoria) == 0){
                        if(strcmp(reserv[i].nomePessoa, nomeHosp) == 0){
                            reserv[i].nomePessoa[strcspn(reserv[i].nomePessoa, "\n")] = 0;
                            fprintf(arqReserva, "%s;", reserv[i].nomePessoa);
                            reserv[i].sexo[strcspn(reserv[i].sexo, "\n")] = 0;
                            fprintf(arqReserva, "%s;", reserv[i].sexo);
                            fprintf(arqReserva, "%d;", reserv[i].codAcomodRes);
                            reserv[i].catReserva[strcspn(reserv[i].catReserva, "\n")] = 0;
                            fprintf(arqReserva, "%s;", reserv[i].catReserva);
                            reserv[i].strDataIni[strcspn(reserv[i].strDataIni, "\n")] = 0;
                            fprintf(arqReserva, "%s;", reserv[i].strDataIni);
                            reserv[i].strDataFinal[strcspn(reserv[i].strDataFinal, "\n")] = 0;
                            fprintf(arqReserva, "%s;", reserv[i].strDataFinal);
                        }
                    }
                }
            }
            if(opHosp == 1 && opAcomod == 2){
                for(i=0; i<*pTotRes; i++){
                    if(reserv[i].codAcomodRes == codAcomod){
                        if(strcmp(reserv[i].nomePessoa, nomeHosp) == 0){
                            reserv[i].nomePessoa[strcspn(reserv[i].nomePessoa, "\n")] = 0;
                            fprintf(arqReserva, "%s;", reserv[i].nomePessoa);
                            reserv[i].sexo[strcspn(reserv[i].sexo, "\n")] = 0;
                            fprintf(arqReserva, "%s;", reserv[i].sexo);
                            fprintf(arqReserva, "%d;", reserv[i].codAcomodRes);
                            reserv[i].catReserva[strcspn(reserv[i].catReserva, "\n")] = 0;
                            fprintf(arqReserva, "%s;", reserv[i].catReserva);
                            reserv[i].strDataIni[strcspn(reserv[i].strDataIni, "\n")] = 0;
                            fprintf(arqReserva, "%s;", reserv[i].strDataIni);
                            reserv[i].strDataFinal[strcspn(reserv[i].strDataFinal, "\n")] = 0;
                            fprintf(arqReserva, "%s;", reserv[i].strDataFinal);
                        }
                    }
                }
            }
            if(opHosp == 2 && opAcomod == 1){
                for(i=0; i<*pTotRes; i++){
                    if(strcmp(reserv[i].catReserva, categoria) == 0){
                        if(strcmp(reserv[i].sexo, sexoHosp) == 0){
                            reserv[i].nomePessoa[strcspn(reserv[i].nomePessoa, "\n")] = 0;
                            fprintf(arqReserva, "%s;", reserv[i].nomePessoa);
                            reserv[i].sexo[strcspn(reserv[i].sexo, "\n")] = 0;
                            fprintf(arqReserva, "%s;", reserv[i].sexo);
                            fprintf(arqReserva, "%d;", reserv[i].codAcomodRes);
                            reserv[i].catReserva[strcspn(reserv[i].catReserva, "\n")] = 0;
                            fprintf(arqReserva, "%s;", reserv[i].catReserva);
                            reserv[i].strDataIni[strcspn(reserv[i].strDataIni, "\n")] = 0;
                            fprintf(arqReserva, "%s;", reserv[i].strDataIni);
                            reserv[i].strDataFinal[strcspn(reserv[i].strDataFinal, "\n")] = 0;
                            fprintf(arqReserva, "%s;", reserv[i].strDataFinal);
                        }
                    }
                }
            }
            if(opHosp == 2 && opAcomod == 2){
                for(i=0; i<*pTotRes; i++){
                    if(reserv[i].codAcomodRes == codAcomod){
                        if(strcmp(reserv[i].sexo, sexoHosp) == 0){
                            reserv[i].nomePessoa[strcspn(reserv[i].nomePessoa, "\n")] = 0;
                            fprintf(arqReserva, "%s;", reserv[i].nomePessoa);
                            reserv[i].sexo[strcspn(reserv[i].sexo, "\n")] = 0;
                            fprintf(arqReserva, "%s;", reserv[i].sexo);
                            fprintf(arqReserva, "%d;", reserv[i].codAcomodRes);
                            reserv[i].catReserva[strcspn(reserv[i].catReserva, "\n")] = 0;
                            fprintf(arqReserva, "%s;", reserv[i].catReserva);
                            reserv[i].strDataIni[strcspn(reserv[i].strDataIni, "\n")] = 0;
                            fprintf(arqReserva, "%s;", reserv[i].strDataIni);
                            reserv[i].strDataFinal[strcspn(reserv[i].strDataFinal, "\n")] = 0;
                            fprintf(arqReserva, "%s;", reserv[i].strDataFinal);
                        }
                    }
                }
            }

    fclose(arqReserva);
}

void MovAcomodacoes(int op, int codIni, char *catAcomod, int diasCup, int *totDiaAc, float redAcomod, diariaAcomod *diaAc){
    int i;
    
    FILE *arqMov = fopen("Relatório de Movimentação de Acomodações.txt", "w");
    
    for(i=0; i<*totDiaAc; i++){
        printf("\n %d", diaAc[i].codAcomod);
        printf("\n %f", diaAc[i].totDiaria);
        printf("\n %d", diaAc[i].totalDia);
    }
    printf("%d", op);
    
    switch(op){
        case 1:
            for(i=0; i<*totDiaAc; i++){
                if(diaAc[i].totDiaria > redAcomod && diasCup < diaAc[i].totalDia){
                    if(diaAc[i].codAcomod == codIni){
                        fprintf(arqMov, "%d;", diaAc[i].codAcomod);

                        diaAc[i].categoria[strcspn(diaAc[i].categoria, "\n")] = 0;
                        fprintf(arqMov, "%s;", diaAc[i].categoria);

                        fprintf(arqMov, "%f;", diaAc[i].totDiaria);

                        fprintf(arqMov, "%d;", diaAc[i].totalDia);
                    }
                }
            }
        break;
        
        case 2:
            for(i=0; i<*totDiaAc; i++){
                if(diaAc[i].totDiaria > redAcomod && diasCup < diaAc[i].totalDia){
                    if(strcmp(catAcomod, diaAc[i].categoria) == 0){
                        fprintf(arqMov, "%d;", diaAc[i].codAcomod);

                        diaAc[i].facilidades[strcspn(diaAc[i].facilidades, "\n")] = 0;
                        fprintf(arqMov, "%s;", diaAc[i].facilidades);

                        diaAc[i].categoria[strcspn(diaAc[i].categoria, "\n")] = 0;
                        fprintf(arqMov, "%s;", diaAc[i].categoria);

                        fprintf(arqMov, "%f;", diaAc[i].totDiaria);

                        fprintf(arqMov, "%d;", diaAc[i].totalDia);        
                    }
                }
            }
        break;
    }
    fclose(arqMov);
}

void RelatorioProdutos(int codIni, int codFin, produtos *produto){

    int i;

    FILE *arqProd = fopen("Relatório de Produtos.txt", "w");

            for(i=codIni; i<=codFin; i++){

                    fprintf(arqProd, "%d;", produto[i-1].codigoProduto);
                    produto[i-1].descricao[strcspn(produto[i-1].descricao, "\n")] = 0;
                    fprintf(arqProd, "%s;", produto[i-1].descricao);
                    fprintf(arqProd, "%d;", produto[i-1].estoque);
                    fprintf(arqProd, "%d;", produto[i-1].estoqueMin);
                    fprintf(arqProd, "%f;", produto[i-1].precoCusto);
                    fprintf(arqProd, "%f;", produto[i-1].precoVenda);

            }
            fclose(arqProd);
}


void RelatorioProdutosEstMin(int codIni, int codFin, produtos *produto){

    int i;

    FILE *arqProd = fopen("Relatório de Produtos em Estoque Mínimo.txt", "w");
    
    for(i=codIni; i<=codFin; i++){
        if(produto[i-1].estoque <= produto[i-1].estoqueMin){
            fprintf(arqProd, "%d;", produto[i-1].codigoProduto);
            produto[i-1].descricao[strcspn(produto[i-1].descricao, "\n")] = 0;
            fprintf(arqProd, "%s;", produto[i-1].descricao);
            fprintf(arqProd, "%d;", produto[i-1].estoque);
            fprintf(arqProd, "%d;", produto[i-1].estoqueMin);
            fprintf(arqProd, "%f;", produto[i-1].precoCusto);
            fprintf(arqProd, "%f;", produto[i-1].precoVenda);
        }
    }
    fclose(arqProd);
}

void RelatorioContReceber(int codIni, int codFin, char *data, contReceber *cont){
    int i; 
    
    FILE *arqCont = fopen("Relatório Contas a Receber.txt", "w");
         
    for(i=codIni; i<=codFin; i++){
        if(strcmp(cont[i].dataReceb, data) == 0){
            fprintf(arqCont, "%d;", cont[i-1].codCont);
            fprintf(arqCont, "%s;", cont[i-1].nomeHosp);
            fprintf(arqCont, "%f;", cont[i-1].totalPag);
            fprintf(arqCont, "%d;", cont[i-1].venciCart);
        }
    }
}