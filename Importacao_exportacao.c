#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Arquivos.h"
#include "Transacoes.h"
#include "Reservas.h"
#include "GestaoDeDados.h"
#include "Feedback.h"

void ExportarDados(char *numTab, int totHosp, int countAc, int countCat, int countPro, int countFornec, hospede *hospedes, acomodacoes *acomod, categoriaAcomod *cat, produtos *prod, fornecedores *fornec){
    int i, j=0, k, op;
    long int vetNum[7];
    int n1;
    char *numStr;
    long int p;
    const char s[2] = ",";
    FILE *arqHosp;
    
    numStr = malloc(100 * sizeof(char));
    
    arqHosp = fopen("Dados.xml", "w");
    
    numStr = strtok(numTab, ",");
    
    while(numStr != NULL){
        p = atoi(numStr);
        vetNum[j] = p;
        j++; 
        numStr = strtok(NULL, s); //cada string é armazenadaem umaposição de um vetor
    }
    
    fprintf(arqHosp, "<dados>");
    
    for(i=0; i<j; i++){ 
                         
        if(vetNum[i] == 1){
            fprintf(arqHosp, "\n       <tabelas=hospede>");
            for(k=0; k<totHosp; k++){
                fprintf(arqHosp, "\n                <registro>", hospedes[k].codigoHospede);

                fprintf(arqHosp, "\n                      <codigo>%d<\\codigo>", hospedes[k].codigoHospede);

                fprintf(arqHosp, "\n                      <nome>%s<\\nome>", hospedes[k].nomeHospede);
                hospedes[k].nomeHospede[strcspn(hospedes[k].nomeHospede, "\n")] = 0;

                fprintf(arqHosp, "\n                      <cpf>%s<\\cpf>", hospedes[k].cpf);
                hospedes[k].cpf[strcspn(hospedes[k].cpf, "\n")] = 0;

                hospedes[k].telHospede[strcspn(hospedes[k].telHospede, "\n")] = 0;
                fprintf(arqHosp, "\n                      <telefone>%s<\\telefone>", hospedes[k].telHospede);

                hospedes[k].emailHospede[strcspn(hospedes[k].emailHospede, "\n")] = 0;
                fprintf(arqHosp, "\n                      <email>%s<\\email>", hospedes[k].emailHospede);

                hospedes[k].sexo[strcspn(hospedes[k].sexo, "\n")] = 0;
                fprintf(arqHosp, "\n                      <sexo>%s<\\sexo>", hospedes[k].sexo);

                hospedes[k].estCivHospede[strcspn(hospedes[k].estCivHospede, "\n")] = 0;
                fprintf(arqHosp, "\n                      <est_civil>%s<\\est_civil>", hospedes[k].estCivHospede);

                hospedes[k].dataNasci[strcspn(hospedes[k].dataNasci, "\n")] = 0;
                fprintf(arqHosp, "\n                      <data_nasci>%s<\\data_nasci>", hospedes[k].dataNasci);

                hospedes[k].enderHosp.num[strcspn(hospedes[k].enderHosp.num, "\n")] = 0;
                fprintf(arqHosp, "\n                      <numero>%s<\\numeor>", hospedes[k].enderHosp.num);

                hospedes[k].enderHosp.rua[strcspn(hospedes[k].enderHosp.rua, "\n")] = 0;
                fprintf(arqHosp, "\n                      <rua>%s<\\rua>", hospedes[k].enderHosp.rua);

                hospedes[k].enderHosp.bairro[strcspn(hospedes[k].enderHosp.bairro, "\n")] = 0;
                fprintf(arqHosp, "\n                      <bairro>%s<\\bairoo>", hospedes[k].enderHosp.bairro);

                hospedes[k].enderHosp.cidade[strcspn(hospedes[k].enderHosp.cidade, "\n")] = 0;
                fprintf(arqHosp, "\n                      <cidade>%s<\\cidade>", hospedes[k].enderHosp.cidade);

                hospedes[k].enderHosp.estado[strcspn(hospedes[k].enderHosp.estado, "\n")] = 0;
                fprintf(arqHosp, "\n                      <estado>%s<\\estado>", hospedes[k].enderHosp.estado);

                hospedes[k].enderHosp.pais[strcspn(hospedes[k].enderHosp.pais, "\n")] = 0;
                fprintf(arqHosp, "\n                      <pais>%s<\\pais>", hospedes[k].enderHosp.pais);

                fprintf(arqHosp, "\n                <\\registro>", hospedes[k].codigoHospede);

            }
            fprintf(arqHosp, "\n       </tabelas=hospede>", hospedes[k].codigoHospede);
        }
        if(vetNum[i] == 2){
            fprintf(arqHosp, "\n       <tabelas=categoriaAcomod>");
            for(k=0; k<countCat; k++){
                fprintf(arqHosp, "\n                <registro>");

                fprintf(arqHosp, "\n                      <codigo>%d<\\codigo>", cat[k].codigoCategoriaAcomod);

                fprintf(arqHosp, "\n                      <descricao>%s<\\descricao>", cat[k].descricaoCat);

                fprintf(arqHosp, "\n                      <diaria>%f<\\diaria>", cat[k].valorDiaria);

                fprintf(arqHosp, "\n                      <qtd_criancas>%d<\\qtd_criancas>", cat[k].QuantCriancas);

                fprintf(arqHosp, "\n                      <qtd_adultos>%d<\\qtd_adultos>", cat[k].QuantAdultos);

                fprintf(arqHosp, "\n                <\\registro>");
            }
            fprintf(arqHosp, "\n       </tabelas=categoriaAcomod>");
        }
        if(vetNum[i] == 3){
            fprintf(arqHosp, "\n       <tabelas=acomod>", acomod[k].codigoAcomod);
                for(k=0; k<countAc; k++){
                    fprintf(arqHosp, "\n                <registro>");

                    fprintf(arqHosp, "\n                      <codigo>%d<\\codigo>", acomod[k].codigoAcomod);

                    acomod[k].descricaoAcomod[strcspn(acomod[k].descricaoAcomod, "\n")] = 0;
                    fprintf(arqHosp, "\n                      <descricao>%s<\\descricao>", acomod[k].descricaoAcomod);

                    acomod[k].facilidades[strcspn(acomod[k].facilidades, "\n")] = 0;
                    fprintf(arqHosp, "\n                      <facilidades>%s<\\facilidades>", acomod[k].facilidades);

                    acomod[k].categoria.descricaoCat[strcspn(acomod[k].categoria.descricaoCat, "\n")] = 0;
                    fprintf(arqHosp, "\n                      <categoria>%s<\\categoria>", acomod[k].categoria.descricaoCat);

                    fprintf(arqHosp, "\n                <\\registro>");
                }
        
            fprintf(arqHosp, "\n       </tabelas=acomod>");
        }
        if(vetNum[i] == 4){
            fprintf(arqHosp, "\n       <tabelas=produtos>", acomod[k].codigoAcomod);
                for(k=0; k<countPro; k++){
                    fprintf(arqHosp, "\n                <registro>");

                    fprintf(arqHosp, "\n                      <codigo>%d</codigo>", prod[k].codigoProduto);

                    fprintf(arqHosp, "\n                      <descricao>%s</descricao>", prod[k].descricao);

                    fprintf(arqHosp, "\n                      <estoque>%d</estoque>", prod[k].estoque);

                    fprintf(arqHosp, "\n                      <estoque_min>%d</estoque_min>", prod[k].estoqueMin);

                    fprintf(arqHosp, "\n                      <preco>%f</preco>", prod[k].precoVenda);

                    fprintf(arqHosp, "\n                </registro>");
                }
        
            fprintf(arqHosp, "\n       </tabelas=produtos>");
        }
        if(vetNum[i] == 5){
            fprintf(arqHosp, "\n       <tabelas=fornecedores>", acomod[k].codigoAcomod);
                for(k=0; k<countFornec; k++){
                    fprintf(arqHosp, "\n                <registro>");

                    fprintf(arqHosp, "\n                      <codigo>%d</codigo>", fornec[k].codigoFornec);

                    fprintf(arqHosp, "\n                      <nome>%s</nome>", fornec[k].nomeFornec);

                    fprintf(arqHosp, "\n                      <razao>%s</razao>", fornec[k].razaoSocialFornec);

                    fprintf(arqHosp, "\n                      <inscricao>%s</inscricao>", fornec[k].inscricaoEstFornec);

                    fprintf(arqHosp, "\n                      <cnpj>%s</cnpj>", fornec[k].cnpj);
                    
                    fprintf(arqHosp, "\n                      <telefone>%s</telefone>", fornec[k].telefoneFornec);
                    
                    fprintf(arqHosp, "\n                      <email>%s</email>", fornec[k].email);
                    
                    fprintf(arqHosp, "\n                      <numero>%s</numero>", fornec[k].enderFornec.numFornec);
                    
                    fprintf(arqHosp, "\n                      <rua>%s</rua>", fornec[k].enderFornec.ruaFornec);
                    
                    fprintf(arqHosp, "\n                      <bairro>%s</bairro>", fornec[k].enderFornec.bairroFornec);
                    
                    fprintf(arqHosp, "\n                      <cidade>%s</cidade>", fornec[k].enderFornec.cidadeFornec);
                    
                    fprintf(arqHosp, "\n                      <estado>%s</estado>", fornec[k].enderFornec.estadoFornec);
                    
                    fprintf(arqHosp, "\n                      <pais>%s</pais>", fornec[k].enderFornec.paisFornec);

                    fprintf(arqHosp, "\n                </registro>");
                }
        
            fprintf(arqHosp, "\n       </tabelas=fornecedores>");

        }
        if(vetNum[i] == 6){
            
        }
    }
    fprintf(arqHosp, "\n<\\dados>");
   
    if(ferror(arqHosp)){
        printf("\n Erro ao gravar arquivo");
    } else {
        printf("\n Gravação realizada com sucesso");
    }

    fclose(arqHosp);
}

int ImportarDados(int op, int *totHosp, int *totCat, int *totAc, int *totPro, int *totFor, hospede *hosp, acomodacoes *acomod, categoriaAcomod *cat, produtos *prod, fornecedores *fornec){
    int i=0;
    char verifTab[1000];
    char tabHosp[100];
    char tabAcomod[100];
    char tabCat[100];
    char tabProd[100];
    char tabFornec[100];
    
    FILE *arqHosp = fopen("Dados.xml", "r");
    
    if(arqHosp == NULL){
        printf("\n Erro na leitura do arquivo");
    } else {
        
        switch(op){ //cada while verifica a  primeira  identificação  de  uma  tabela  específica
            case 1:
                while(strcmp(verifTab, "hospede") != 0){
                    fscanf(arqHosp, "%[a-z]", verifTab);
                    fseek(arqHosp, 1, SEEK_CUR);
                }  
            break;
            
            case 2:
                while(strcmp(verifTab, "categoriaAcomod") != 0){
                    fscanf(arqHosp, "%[a-z A-Z]", verifTab);
                    fseek(arqHosp, 1, SEEK_CUR);
                }  
            break;
            
            case 3:
                while(strcmp(verifTab, "acomod") != 0){
                    fscanf(arqHosp, "%[a-z]", verifTab);
                    fseek(arqHosp, 1, SEEK_CUR);
                }  
            break;
            
            case 4:
                while(strcmp(verifTab, "produtos") != 0){
                    fscanf(arqHosp, "%[a-z]", verifTab);
                    fseek(arqHosp, 1, SEEK_CUR);
                }  
            break;
            
            case 5:
                while(strcmp(verifTab, "fornecedores") != 0){
                    fscanf(arqHosp, "%[a-z]", verifTab);
                    fseek(arqHosp, 1, SEEK_CUR);
                }  
            break;
            
            case 6:
                while(strcmp(verifTab, "reserva") != 0){
                    fscanf(arqHosp, "%[a-z]", verifTab);
                    fseek(arqHosp, 1, SEEK_CUR);
                }  
            break;
        }
        
        fseek(arqHosp, 58, SEEK_CUR);
        
        switch(op){ //são armazenados todos  os  dados  dos  registros  com  a  função  fseek percorrendo  as  posições  do  documento
            case 1:
                while((strcmp(tabHosp, "registro") == 0) || i==0){
                    fscanf(arqHosp, "%d", &hosp[i].codigoHospede);
                    fseek(arqHosp, 38, SEEK_CUR);
                    fscanf(arqHosp, "%[^<>]", hosp[i].nomeHospede);
                    fseek(arqHosp, 35, SEEK_CUR);
                    fscanf(arqHosp, "%[^<>]", hosp[i].cpf);
                    fseek(arqHosp, 39, SEEK_CUR);
                    fscanf(arqHosp, "%[^<>]", hosp[i].telHospede);
                    fseek(arqHosp, 41, SEEK_CUR);
                    fscanf(arqHosp, "%[^<>]", hosp[i].emailHospede);
                    fseek(arqHosp, 37, SEEK_CUR);
                    fscanf(arqHosp, "%[^<>]", hosp[i].sexo);
                    fseek(arqHosp, 41, SEEK_CUR);
                    fscanf(arqHosp, "%[^<>]", hosp[i].estCivHospede);
                    fseek(arqHosp, 47, SEEK_CUR);
                    fscanf(arqHosp, "%[^<>]", hosp[i].dataNasci);
                    fseek(arqHosp, 44, SEEK_CUR);
                    fscanf(arqHosp, "%[^<>]", hosp[i].enderHosp.num);
                    fseek(arqHosp, 37, SEEK_CUR);
                    fscanf(arqHosp, "%[^<>]", hosp[i].enderHosp.rua);
                    fseek(arqHosp, 37, SEEK_CUR);
                    fscanf(arqHosp, "%[^<>]", hosp[i].enderHosp.bairro);
                    fseek(arqHosp, 40, SEEK_CUR);
                    fscanf(arqHosp, "%[^<>]", hosp[i].enderHosp.cidade);
                    fseek(arqHosp, 40, SEEK_CUR);
                    fscanf(arqHosp, "%[^<>]", hosp[i].enderHosp.estado);
                    fseek(arqHosp, 38, SEEK_CUR);
                    fscanf(arqHosp, "%[^<>]", hosp[i].enderHosp.pais);
                    i++;
                    if(i>0){
                        fseek(arqHosp, 53, SEEK_CUR);
                        fscanf(arqHosp, "%[a-z]", tabHosp);
                        fseek(arqHosp, 32, SEEK_CUR);
                    }
                }
                *totHosp = i;
            break;
            
            case 2:
            
            while((strcmp(tabCat, "registro") == 0) || i==0){
                fscanf(arqHosp, "%d", &cat[i].codigoCategoriaAcomod);
                fseek(arqHosp, 43, SEEK_CUR);
                fscanf(arqHosp, "%[^<>]", cat[i].descricaoCat);
                fseek(arqHosp, 43, SEEK_CUR);
                fscanf(arqHosp, "%f", &cat[i].valorDiaria);
                fseek(arqHosp, 46, SEEK_CUR);
                fscanf(arqHosp, "%d", &cat[i].QuantCriancas);
                fseek(arqHosp, 51, SEEK_CUR);
                fscanf(arqHosp, "%d", &cat[i].QuantAdultos);
                i++;
                fseek(arqHosp, 60, SEEK_CUR);
                fscanf(arqHosp, "%[a-z]", tabCat);
                fseek(arqHosp, 32, SEEK_CUR);
            }
            *totCat = i;
            
            break;
            
            case 3:
                
                while((strcmp(tabAcomod, "registro") == 0) || i==0){
                    fscanf(arqHosp, "%d", &acomod[i].codigoAcomod);
                    fseek(arqHosp, 43, SEEK_CUR);
                    fscanf(arqHosp, "%[^<>]", acomod[i].descricaoAcomod);
                    fseek(arqHosp, 48, SEEK_CUR);
                    fscanf(arqHosp, "%[^<>]", acomod[i].facilidades);
                    fseek(arqHosp, 48, SEEK_CUR);
                    fscanf(arqHosp, "%[^<>]", acomod[i].categoria.descricaoCat);
                    i++;
                    fseek(arqHosp, 58, SEEK_CUR);
                    fscanf(arqHosp, "%[a-z]", tabAcomod);
                    fseek(arqHosp, 32, SEEK_CUR);
                }
            *totAc = i;
            
            break;
            
            case 4:
                while((strcmp(tabProd, "registro") == 0) || i==0){
                    fscanf(arqHosp, "%d", &prod[i].codigoProduto);
                    fseek(arqHosp, 43, SEEK_CUR);
                    fscanf(arqHosp, "%[^<>]", prod[i].descricao);
                    fseek(arqHosp, 44, SEEK_CUR);
                    fscanf(arqHosp, "%d", &prod[i].estoque);
                    fseek(arqHosp, 46, SEEK_CUR);
                    fscanf(arqHosp, "%d", &prod[i].estoqueMin);
                    fseek(arqHosp, 44, SEEK_CUR);
                    fscanf(arqHosp, "%f", &prod[i].precoVenda);
                    i++;
                    fseek(arqHosp, 54, SEEK_CUR);
                    fscanf(arqHosp, "%[a-z]", tabProd);
                    fseek(arqHosp, 32, SEEK_CUR);
                }   
            *totPro = i;
            break;
            
            case 5:
                while((strcmp(tabFornec, "registro") == 0) || i==0){
                    fscanf(arqHosp, "%d", &fornec[i].codigoFornec);
                    fseek(arqHosp, 38, SEEK_CUR);
                    fscanf(arqHosp, "%[^<>]", fornec[i].nomeFornec);
                    fseek(arqHosp, 37, SEEK_CUR);
                    fscanf(arqHosp, "%[^<>]", fornec[i].razaoSocialFornec);
                    fseek(arqHosp, 42, SEEK_CUR);
                    fscanf(arqHosp, "%[^<>]", fornec[i].inscricaoEstFornec);
                    fseek(arqHosp, 41, SEEK_CUR);
                    fscanf(arqHosp, "%[^<>]", fornec[i].cnpj);
                    fseek(arqHosp, 40, SEEK_CUR);
                    fscanf(arqHosp, "%[^<>]", fornec[i].telefoneFornec);
                    fseek(arqHosp, 41, SEEK_CUR);
                    fscanf(arqHosp, "%[^<>]", fornec[i].email);
                    fseek(arqHosp, 39, SEEK_CUR);
                    fscanf(arqHosp, "%[^<>]", fornec[i].enderFornec.numFornec);
                    fseek(arqHosp, 37, SEEK_CUR);
                    fscanf(arqHosp, "%[^<>]", fornec[i].enderFornec.ruaFornec);
                    fseek(arqHosp, 37, SEEK_CUR);
                    fscanf(arqHosp, "%[^<>]", fornec[i].enderFornec.bairroFornec);
                    fseek(arqHosp, 40, SEEK_CUR);
                    fscanf(arqHosp, "%[^<>]", fornec[i].enderFornec.cidadeFornec);
                    fseek(arqHosp, 40, SEEK_CUR);
                    fscanf(arqHosp, "%[^<>]", fornec[i].enderFornec.estadoFornec);
                    fseek(arqHosp, 38, SEEK_CUR);
                    fscanf(arqHosp, "%[^<>]", fornec[i].enderFornec.paisFornec);
                    
                    i++;
                    int c = ftell(arqHosp);
                    printf("\n %d", c);
                    fseek(arqHosp, 53, SEEK_CUR);
                    fscanf(arqHosp, "%[a-z]", tabFornec);
                    printf("%s", tabFornec);
                    int b = ftell(arqHosp);
                    printf("\n %d", b);
                    fseek(arqHosp, 32, SEEK_CUR);
                }   
            *totFor = i;
            break;
        }
    }
        if(ferror(arqHosp)){
            printf("\n Erro na leitura do arquivo");
        } else {
            printf("\n Arquivo lido com sucesso");
        }
    return i;
}

