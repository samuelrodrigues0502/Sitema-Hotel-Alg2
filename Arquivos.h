#include <stdio.h>
#include "GestaoDeDados.h"
#include "Reservas.h"
#include "Transacoes.h"

#ifndef ARQUIVOS_H
#define ARQUIVOS_H

#ifdef __cplusplus
extern "C" {
#endif

void GravarDadosHotel(hotel *hot, int TipoArq);

void GravarDadosHospedes(int totHosp, hospede *hospedes, int TipoArq);

void GravarDadosCategoria(int totCat, categoriaAcomod *categorias, int TipoArq);

void GravarDadosAcomodacoes(int totAcomod, acomodacoes *acomodacoes, int TipoArq);

void GravarDadosProdutos(int totProd, produtos *produto, int TipoArq);

void GravarDadosFornecedores(int totFornec, fornecedores *fornecs, int TipoArq);

void GravarDadosReservas(int totalRes, reservas *reserv, int TipoArq);

int LerDadosTxtHotel(hotel *hot);

int LerDadosTxtHospedes(hospede *hospedes);

int LerDadosTxtCategorias(categoriaAcomod *categorias);

int LerDadosTxtAcomodacoes(acomodacoes *acomodacoes);

int LerDadosTxtProdutos(produtos *produto);

int LerDadosTxtFornecedores(fornecedores *fornecs);

int LerDadosTxtReservas(reservas *reserv);

int LerDadosBinHotel(hotel *hot);

int LerDadosBinFornecedores(fornecedores *fornecs);

int LerDadosBinProdutos(produtos *produto);

int LerDadosBinHospedes(hospede *hospedes);

int LerDadosBinCategorias(categoriaAcomod *categorias);

int LerDadosBinAcomodacoes(acomodacoes *acomodacoes);

int LerDadosBinReservas(reservas *reserv);

void GravarDadosContHosp(int *k, contHosp *cont, int TipoArq);

void GravarDadosContFornec(int *k, itensInd *prodComp, int TipoArq);

void GravarDadosCaixa(int *k, caixa *caixaHotel, int TipoArq);

int LerDadosTxtCaixa(caixa *caixaHotel);

int LerDadosBinCaixa(caixa *caixaHotel);

int LerContasTxtHospedes(contHosp *cont);

int LerContasBinHospedes(contHosp *cont);

int LerContasTxtFornec(itensInd *prodComp);

int LerContasBinFornec(itensInd *prodComp);

#ifdef __cplusplus
}
#endif

#endif /* ARQUIVOS_H */



