#include "Reservas.h"

#ifndef TRANSACOES_H
#define TRANSACOES_H

#ifdef __cplusplus
extern "C" {
#endif

struct DadosProdutos{
    char prodComp[50];
    int qtdProd;
};

typedef struct DadosProdutos dadosProd;

struct ContaHospede{
    char nomeCont[50];
    float valorTot;
    int qtdPrdsComp;
    float totalPag;
    struct DadosProdutos dadosPro[500];
};

typedef struct ContaHospede contHosp;

struct ContasReceber{
    int codCont;
    char nomeHosp[50];
    float totalPag;
    char dataReceb[30];
    int venciCart;
};

typedef struct ContasReceber contReceber;

struct ContasPagar{
    char nomeFornec[100];
    float totalPag;
};

typedef struct ContasPagar contPag;

struct CaixaHotel{
    float valorTransacao;
    char tipoTransacao[50];
    float totCaixa;
};

typedef struct CaixaHotel caixa;

struct ItensComp{
    char prodComp[50];
    float valorProd;
    int qtdProd;
};
typedef struct ItensComp itensComp;

struct ItensIndustri{
    char nomeFornec[100];
    float precFrete;
    float imp;
    float totPag;
    float preVenda;
    int qtdProdComp;
    struct ItensComp prodInd[500];
};

typedef struct ItensIndustri itensInd;

struct ContFornecProd{
    char prodComp[50];
    float valorProd;
    int qtdProd;
};
typedef struct ContFornecProd contProdFornec;

struct ContasFornec{
    char nomeContFornec[100];
    float PrecContFrete;
    float ImpCont;
    float TotContPag;
    struct ItensComp prodContInd[500];
};

typedef struct ContasFornec contFornec;

void CheckinRes(int *k, int *x, int *n, reservas *res, int *totRes, categoriaAcomod *categoria, int countCat, contHosp *cont, int *j, caixa *caixaHotel, contReceber *cont2, int TipoArq, int *pCountHosp, hospede *hospedes, diariaAcomod *diariaAc);

void SaidaDeProdutos(int *count, int *k, produtos *prod, reservas *res, contHosp *cont, caixa *caixaHotel, int TipoArq);

void GerarNota(int *count, contHosp *cont);

void CheckOut(int op, int *n, int *k, int *count, int *j, contHosp *cont, contReceber *cont2, caixa *caixaHotel, int TipoArq);

void MostrarTransacoes(int *totTran, caixa *caixaHotel);

void EntradaProdutosInd(int *k, itensInd *prodInd);

void PrecoProdutosInd(int *k, int *n, int *j, int *totProd, itensInd *prodInd, produtos *prod, hotel *hot, int TipoArq);

void GerarNotaFiscal(int *totProd, itensInd *prodComp);

void PagamentoFornecedorAVista(int *n, int *j, int *k, itensInd *prodComp, caixa *caixaHotel, contPag *cont3, int TipoArq);

void PagamentoFornecedorAPrazo(int *n, float valEnt, float parc, int *j, int *k, itensInd *prodComp, caixa *caixaHotel, contPag *cont3);

void RecebimentoCartao(int *k, int *j, int *totContas, caixa *caixaHotel, contHosp *cont, contReceber *cont2, int TipoArq);

void PagamentoCartao(int *k, int *totContas, caixa *caixaHotel, contReceber *cont2, int TipoArq);

void PagarFornecedor(int *k, int *j, caixa *caixaHotel, contPag *cont3, int TipoArq);

void ExcluirContaHospede(char *nomeHosp, int *k, contHosp *cont);

void MostrarContasHospede(int *k, contHosp *cont);

void MostrarContasFornec(int op, int *k, int *j, itensInd *prodComp, contPag *cont3);

int ContAPagarFornecArquivo(int *k, itensInd *prodComp, contPag *cont3);

void ParcelarContFornec(float valEnt2, float parc2, int *k, caixa *caixaHotel, contPag *cont3);

void ExcluirContaFornecedor(char *nomeFornec, int *k, contPag *cont3);

#ifdef __cplusplus
}
#endif

#endif /* TRANSACOES_H */

