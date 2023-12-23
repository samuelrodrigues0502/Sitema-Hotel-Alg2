#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Arquivos.h"
#include "Transacoes.h"
#include "Reservas.h"
#include "GestaoDeDados.h"
#include <time.h>
#include <locale.h>

void CheckinRes(int *k, int *x, int *n, reservas *res, int *totRes, categoriaAcomod *categoria, int countCat, contHosp *cont, int *j, caixa *caixaHotel, contReceber *cont2, int TipoArq, int *pCountHosp, hospede *hospedes, diariaAcomod *diariaAc){

    time_t t1;
    time_t t2;
    time_t dataAtual = time(NULL); //Valor de retorno é a quantidade de segundos passados desde 1 de Janeiro de 1970
    struct tm *tm;
    int ano, mes;
    char NomeResponsavel[50];
    int aux=0, diaria, i=0, count = -1, difDias, op, op2, cod=0;
    float totDias;

    tm = localtime(&dataAtual); //O ponteiro "tm" é setado para a data atual
    bzero(tm, sizeof(*tm));
    
    printf(" Insira o nome do responsável pela reserva: ");
    fgets(NomeResponsavel, sizeof(NomeResponsavel), stdin);

    NomeResponsavel[strcspn(NomeResponsavel, "\n")] = 0;

    for(i=0; i<*totRes; i++){
        if(strcmp(res[i].nomePessoa, NomeResponsavel) == 0){ //Compara o nome de uma reserva com o nome pesquisado
            count = i;
        }
    }
    
    sscanf(res[count].strDataIni, "%d/%d/%d", &tm->tm_mday, &mes, &ano);
    setbuf(stdin, NULL);
    
    t1 = mktime(tm);
    
    sscanf(res[count].strDataFinal, "%d/%d/%d", &tm->tm_mday, &mes, &ano);
    setbuf(stdin, NULL);
    
    t2 = mktime(tm);
    
    if(count != -1){
        for(i=0; i<countCat; i++){
            if(strcmp(res[count].catReserva, categoria[i].descricaoCat) == 0){
                diaria = categoria[i].valorDiaria;
                
            }
        }
        
   
       /*Se a variável count é diferente de "-1",
       o laço for compara a categoria de acomodação da reserva
       com uma categoria existente e reserva o valor da diária
       da categoria compatível na variável diária */

        difDias = difftime(t2, t1); //A função diffTime retorna a diferença entre duas datas
        difDias = (difDias / (60 * 60 * 24)) + 1;
        
        printf("\n Deseja realizar o pagamento no check-in(1-Sim 2-Não): ");
        printf("\n Digite a opção desejada: ");
        scanf("%d", &op);
        setbuf(stdin, NULL);
        totDias = diaria * difDias;
        
        for(i=0; i<*n; i++){
            if(res[count].codAcomodRes == diariaAc[i].codAcomod){
                aux = 1;
                strcpy(diariaAc[i].facilidades, res[count].faciRes);
                strcpy(diariaAc[i].categoria, res[count].catReserva);
                diariaAc[i].totalDia += difDias;
                diariaAc[i].totDiaria += totDias;
                break; 
            } else{
                aux = 0;
            }
        }
        
        if(aux == 0){
            strcpy(diariaAc[i].facilidades, res[count].faciRes);
            strcpy(diariaAc[i].categoria, res[count].catReserva);
            diariaAc[*n].totalDia += difDias;
            diariaAc[*n].codAcomod = res[count].codAcomodRes;
            diariaAc[*n].totDiaria += totDias;
            ++*n;
        }
        
        switch(op){
            case 1:
                strcpy(cont[*j].nomeCont, NomeResponsavel);
                cont[*j].valorTot = 0.00;
                ++*j;
            break;

            case 2:
                strcpy(cont[*j].nomeCont, NomeResponsavel);
                cont[*j].valorTot = difDias * diaria;
                ++*j;
            break;
        }
    }
}

void SaidaDeProdutos(int *count, int *k, produtos *prod, reservas *res, contHosp *cont, caixa *caixaHotel, int TipoArq){

    int i, j, cod = 0, cod2, op, cod3, qtdProd;
    char pesqProd[50];
    char pesqHosp[50];
    printf("Informe o nome do hóspede que deseja realizar a compra: ");
    fgets(pesqHosp, sizeof(pesqHosp), stdin);

    printf("Informe o nome do produto a ser vendido: ");
    fgets(pesqProd, sizeof(pesqProd), stdin);

    pesqHosp[strcspn(pesqHosp, "\n")] = 0;

    printf("Informe a quantidade a ser vendida: ");
    scanf("%d", &qtdProd);
    setbuf(stdin, NULL);

    for(i=0; i<*count; i++){
        if(strcmp(cont[i].nomeCont, pesqHosp) == 0){
            cod = i;
            break;
        }
    }

    for(i=0; i<10; i++){
        if(strcmp(prod[i].descricao, pesqProd) == 0){
            cod2 = i;
        }
    }

    printf("\n Deseja realizar o pagamento dos produtos à vista?(1-Sim 2-Não): ");
    printf("\n Digite a opção desejada: ");
    scanf("%d", &op);
    setbuf(stdin, NULL);
    
    if(op == 1){
        caixaHotel->totCaixa += prod[cod2].precoVenda * qtdProd; //Modifica o valor no caixa do hotel
        strcpy(caixaHotel[*k].tipoTransacao, pesqHosp);
        caixaHotel[*k].valorTransacao = prod[cod2].precoVenda * qtdProd;
        ++*k;
        GravarDadosCaixa(k, caixaHotel, TipoArq);
    } else if(op == 2){
        cod3 = cont[cod].qtdPrdsComp; //Iguala a variável cod3 com a quantidade de produtos na conta do hóspede
        cont[cod].totalPag += prod[cod2].precoVenda * qtdProd;
        strcpy(cont[cod].dadosPro[cod3].prodComp, prod[cod2].descricao);
        cont[cod].dadosPro[cod3].qtdProd = qtdProd;
        cod3++;
        cont[cod].qtdPrdsComp = cod3; //Iguala a quantidade de produtos com a variável cod3 incrementada de 1

        GravarDadosContHosp(count, cont, TipoArq);
    }
        
    
}

void GerarNota(int *count, contHosp *cont){
    int i, cod = 0;
    char pesqHosp[50];

    printf("%s", cont[cod].nomeCont);
    printf("%5.2f", cont[cod].totalPag);
    printf("%d", cont[cod].qtdPrdsComp);
    printf("%s", cont[cod].dadosPro[cod].prodComp);
    printf("%d", cont[cod].dadosPro[cod].qtdProd);

    printf("Informe o nome do hóspede que deseja imprimir a nota: ");
    fgets(pesqHosp, sizeof(pesqHosp), stdin);

    pesqHosp[strcspn(pesqHosp, "\n")] = 0;

    for(i=0; i<*count; i++){
        if(strcmp(cont[i].nomeCont, pesqHosp) == 0){
            cod = i;
            printf("%s", cont[i].nomeCont);
            printf("%d", cod);
        }
    }

    FILE *arqCont;

    arqCont = fopen("Nota.txt", "w"); //Gera a nota para o cliente assinar

    if(arqCont == NULL){
        printf("\n Erro ao gravar o arquivo");
    }else {
        fprintf(arqCont, " Nome do Hóspede: %s", cont[cod].nomeCont);
        for(i=0; i<cont[cod].qtdPrdsComp; i++){
            fprintf(arqCont, "\n Produto: %s ||", cont[cod].dadosPro[i].prodComp);
            fprintf(arqCont, " Quantidade: %d", cont[cod].dadosPro[i].qtdProd);
        }
        fprintf(arqCont, "\n Valor Total: R$ %5.2f", cont[cod].totalPag);
        fprintf(arqCont, "\n\n Assinatura: ");
    }
    fclose(arqCont);
}

void CheckOut(int op, int *n, int *k, int *count, int *j, contHosp *cont, contReceber *cont2, caixa *caixaHotel, int TipoArq){

    int cod=0, i;
    char pesqHosp[50];

    printf("Informe o nome do hóspede que deseja realizar o pagamento: ");
    fgets(pesqHosp, sizeof(pesqHosp), stdin);

    pesqHosp[strcspn(pesqHosp, "\n")] = 0;

    for(i=0; i<*n; i++){
        if(strcmp(cont[i].nomeCont, pesqHosp) == 0){
            cod = i;
        }
    }

    switch(op){
        case 1:
            cont2[*k].codCont = cod;
            caixaHotel->totCaixa += cont[cod].totalPag + cont[cod].valorTot; //Modifica o valor no caixa do hotel
            strcpy(caixaHotel[*k].tipoTransacao, pesqHosp);
            caixaHotel[*k].valorTransacao = cont[cod].totalPag + cont[cod].valorTot;
            ++*k;
            GravarDadosCaixa(k, caixaHotel, TipoArq);
            ExcluirContaHospede(pesqHosp, n, cont);
        break;

        case 2:
            strcpy(cont2[*j].nomeHosp, pesqHosp);
            cont2[*j].totalPag = cont[cod].totalPag + cont[cod].valorTot;
            printf("Informe a dia de vencimento do cartão do hóspede: "); //Pega o dia de vencimento do cartão do hóspede
            scanf("%d", &cont2[*j].venciCart);
            ++*j;
        break;
    }
}

void RecebimentoCartao(int *k, int *j, int *totContas, caixa *caixaHotel, contHosp *cont, contReceber *cont2, int TipoArq){
    int i;
    time_t dataAtual;
    struct tm *tm;
    time(&dataAtual);
    tm = localtime(&dataAtual); //O ponteiro "tm" é setado para a data atual
   
    for(i=0; i<*totContas; i++){
        if(cont2[i].venciCart == tm->tm_mday){
            strftime(cont2[i].dataReceb, 20, "%d/%m/%Y", tm);
            printf("\n %s", cont2[i].dataReceb);
            cont2[i].totalPag += caixaHotel->totCaixa;
            strcpy(caixaHotel[*k].tipoTransacao, cont2[i].nomeHosp);
            caixaHotel[*k].valorTransacao = cont2[i].totalPag;
            ++*k;
            GravarDadosCaixa(k, caixaHotel, TipoArq);
            ExcluirContaHospede(cont[i].nomeCont, j, cont);
        }
    }

}

void MostrarTransacoes(int *totTran, caixa *caixaHotel){
    int i;

    for(i=0; i<*totTran; i++){
        printf("Tipo de transação: %s", caixaHotel[i].tipoTransacao);
        printf("Valor: R$ %5.2f", caixaHotel[i].valorTransacao);
    }
}

void EntradaProdutosInd(int *k, itensInd *prodInd){
    int op;

    printf("\n Informe o nome do fornecedor vendendo o produto: ");
    fgets(prodInd[*k].nomeFornec, sizeof(prodInd[*k].nomeFornec), stdin);

    printf("\n Informe o preço do frete: ");
    scanf("%f", &prodInd[*k].precFrete);
    setbuf(stdin, NULL);

    printf("\n Informe o preço do imposto cobrado: ");
    scanf("%f", &prodInd[*k].imp);
    setbuf(stdin, NULL);

    ++*k;
}

void PrecoProdutosInd(int *k, int *n, int *j, int *totProd, itensInd *prodComp, produtos *prod, hotel *hot, int TipoArq){

    int i, cod=-1, qtdProd, aux;
    float valorProd;
    char pesqProd[50];
    float freProd, impProd;

    printf("Informe o produto a ser comprado: ");
    fgets(pesqProd, sizeof(pesqProd), stdin);

    pesqProd[strcspn(pesqProd, "\n")] = 0;

    printf("Informe a quantidade comprada do produto: ");
    scanf("%d", &qtdProd);
    setbuf(stdin, NULL);

    printf("Informe o preço de custo do produto: ");
    scanf("%f", &valorProd);
    setbuf(stdin, NULL);

    for(i=0; i<*n; i++){
        if(strcmp(prod[i].descricao, pesqProd) == 0){
            cod = i;
        }
    }

    if(cod == -1){
        cod = *n;
        CadastrarProdutos(n, prod, TipoArq);
        strcpy(prodComp[*k-1].prodInd[*j].prodComp, pesqProd);
        prodComp[*k-1].prodInd[*j].valorProd = valorProd;
        prodComp[*k-1].prodInd[*j].qtdProd = qtdProd;
        ++*j;
    } else {
        prod[cod].estoque += qtdProd;
        strcpy(prodComp[*k-1].prodInd[*j].prodComp, pesqProd);
        prodComp[*k-1].prodInd[*j].valorProd = valorProd;
        prodComp[*k-1].prodInd[*j].qtdProd = qtdProd;
        ++*j;
    }

    *totProd += qtdProd;
    aux = *totProd;

    freProd = prodComp[*k-1].precFrete/aux;
    impProd = prodComp[*k-1].imp/aux;
    prod[cod].precoVenda = valorProd + freProd + impProd + ((valorProd + freProd + impProd) * hot->margemLucroHotel);
    prodComp[*k-1].preVenda = prod[cod].precoVenda;
    prodComp[*k-1].totPag += aux * qtdProd;
    prodComp[*k-1].qtdProdComp = *j;

    GravarDadosContFornec(k, prodComp, TipoArq);
}

void PagamentoFornecedorAVista(int *n, int *j, int *k, itensInd *prodComp, caixa *caixaHotel, contPag *cont3, int TipoArq){

    caixaHotel->totCaixa -= prodComp[*k-1].totPag ;
    strcpy(caixaHotel[*n].tipoTransacao, prodComp[*k-1].nomeFornec);
    caixaHotel[*n].totCaixa -= prodComp[*k-1].totPag;
    caixaHotel[*n].valorTransacao = prodComp[*k-1].totPag;
    GravarDadosCaixa(n, caixaHotel, TipoArq);
    ++*n;
}

void PagamentoFornecedorAPrazo(int *n, float valEnt, float parc, int *j, int *k, itensInd *prodComp, caixa *caixaHotel, contPag *cont3){
    float vlrFinal;

    caixaHotel->totCaixa -= valEnt;
    vlrFinal = prodComp[*k-1].totPag - valEnt;
    vlrFinal = vlrFinal/parc;
    cont3[*j].totalPag = vlrFinal;
    strcpy(cont3[*j].nomeFornec, prodComp[*k-1].nomeFornec);
    ++*j;
}

void PagarFornecedor(int *k, int *j, caixa *caixaHotel, contPag *cont3, int TipoArq){
    int i, cod;
    char pesqFornec[100];

    printf("\n Informe o nome do fornecedor para realizar o pagamento: ");
    fgets(pesqFornec, sizeof(pesqFornec), stdin);

    pesqFornec[strcspn(pesqFornec, "\n")] = 0;

    for(i=0; i<*j; i++){
        if(strcmp(cont3[i].nomeFornec, pesqFornec) == 0){
            cod = i;
        }
    }
    strcpy(caixaHotel[*k].tipoTransacao, cont3[cod].nomeFornec);
    caixaHotel->totCaixa -= cont3[cod].totalPag;
    caixaHotel[*k].valorTransacao = cont3[cod].totalPag;
    ++*k;
    GravarDadosCaixa(k, caixaHotel, TipoArq);
    ExcluirContaFornecedor(cont3[cod].nomeFornec, j, cont3);
}

void MostrarContasHospede(int *k, contHosp *cont){
    int i, j, cod;

    for(i=0; i<*k; i++){
        printf("\n Nome do Hóspede: %s", cont[i].nomeCont);
        printf("\n Valor devido: %5.2f", cont[i].totalPag + cont[i].valorTot);
        cod = i;
        printf("\n Produtos comprados: ");
        for(j=0; j<cont[cod].qtdPrdsComp; j++){
            printf("\n Produto: %s", cont[cod].dadosPro[j].prodComp);
            printf("\n Valor: %d", cont[cod].dadosPro[j].qtdProd);
        }
    }
}

void MostrarContasFornec(int op, int *k, int *n, itensInd *prodComp, contPag *cont3){
    int i, j, cod, codFor;
    char pesqFornec[100];

    switch(op){

        case 1:
            for(i=0; i<*k; i++){
                printf("\n Nome do fornecedor: %s", prodComp[i].nomeFornec);
                printf("\n Preço do frete: %f", prodComp[i].precFrete);
                printf("\n Preco do imposto: %f", prodComp[i].imp);
                printf("\n Total a pagar: %f", prodComp[i].totPag);
                cod = i;
                for(j=0; j<prodComp[cod].qtdProdComp; j++){
                    printf("\n Produto comprado: %s", prodComp[cod].prodInd[j].prodComp);
                    printf("\n Produto quantidade: %d", prodComp[cod].prodInd[j].qtdProd);
                    printf("\n Produto valor: %f", prodComp[cod].prodInd[j].valorProd);
                }
            }
        break;

        case 2:
            printf("\n Informe o nome do fornecedor que deseja vizualizar os dados: ");
            fgets(pesqFornec, sizeof(pesqFornec), stdin);

            pesqFornec[strcspn(pesqFornec, "\n")] = 0;

            for(i=0; i<*k; i++){
                if(strcmp(prodComp[i].nomeFornec, pesqFornec) == 0){
                    codFor = i;
                }
            }

            printf("\n Nome do fornecedor: %s", prodComp[codFor].nomeFornec);
            printf("\n Preço do frete: %f", prodComp[codFor].precFrete);
            printf("\n Preco do imposto: %f", prodComp[codFor].imp);
            printf("\n Total a pagar: %f", prodComp[codFor].totPag);
            cod = i;
            for(j=0; j<prodComp[codFor].qtdProdComp; j++){
                printf("\n Produto comprado: %s", prodComp[codFor].prodInd[j].prodComp);
                printf("\n Produto quantidade: %d", prodComp[codFor].prodInd[j].qtdProd);
                printf("\n Produto valor: %f", prodComp[codFor].prodInd[j].valorProd);
            }
        break;

        case 3:
            for(i=0; i<*n; i++){
                printf("\n Fornecedor: %s", cont3[i].nomeFornec);
                printf("\n Total a pagar: %5.2f", cont3[i].totalPag);
            }

    }
}

void ExcluirContaHospede(char *nomeHosp, int *k, contHosp *cont){
    int i, codHosp;

    for(i=0; i<*k; i++){
        if(strcmp(cont[i].nomeCont, nomeHosp) == 0){
            codHosp = i;
        }
    }
    while(codHosp < *k){ // Função para canelar a reserva.
        cont[codHosp] = cont[codHosp+1];
        codHosp++;
    }
    --*k;
}

void ExcluirContaFornecedor(char *nomeFornec, int *k, contPag *cont3){
    int i, codFor;

    for(i=0; i<*k; i++){ // Laço para verificar o nome informado dentre as reservas.
        if(strcmp(cont3[i].nomeFornec, nomeFornec) == 0){
            codFor = i;
        }
    }
    while(codFor < *k){ // Função para canelar a reserva.
        cont3[codFor] = cont3[codFor+1];
        codFor++;
    }
    --*k;
}

int ContAPagarFornecArquivo(int *k, itensInd *prodComp, contPag *cont3){

    int i, j=0;

    for(i=0; i<*k; i++){
        strcpy(cont3[j].nomeFornec, prodComp[i].nomeFornec);
        cont3[j].totalPag = prodComp[i].totPag;
        j++;
    }

    return j;
}

void ParcelarContFornec(float valEnt2, float parc2, int *k, caixa *caixaHotel, contPag *cont3){
    int i, cod=0;
    float vlrFinal;
    char pesqFornec[100];

    printf("Informe o nome do fornecedor que deseja parcelar o pagamento: ");
    fgets(pesqFornec, sizeof(pesqFornec), stdin);

    pesqFornec[strcspn(pesqFornec, "\n")] = 0;

    for(i=0; i<*k; i++){
        if(strcmp(cont3[i].nomeFornec, pesqFornec) == 0){
            cod = i;
        }
    }

    caixaHotel->totCaixa -= valEnt2;
    vlrFinal = cont3[cod].totalPag - valEnt2;
    vlrFinal = vlrFinal/parc2;
    cont3[cod].totalPag = vlrFinal;
}
