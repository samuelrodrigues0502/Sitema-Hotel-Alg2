/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Importacao_exportacao.h
 * Author: User
 *
 * Created on 4 de Abril de 2021, 10:30
 */

#ifndef IMPORTACAO_EXPORTACAO_H
#define IMPORTACAO_EXPORTACAO_H

#ifdef __cplusplus
extern "C" {
#endif

void ExportarDados(char *numTab, int totHosp, int countAc, int countCat, int countPro, int countFornec, hospede *hospedes, acomodacoes *acomod, categoriaAcomod *cat, produtos *prod, fornecedores *fornec);
    
int ImportarDados(int op, int *totHosp, int *totCat, int *totAc, int *totPro, int *totFor, hospede *hosp, acomodacoes *acomod, categoriaAcomod *cat, produtos *prod, fornecedores *fornec);

#ifdef __cplusplus
}
#endif

#endif /* IMPORTACAO_EXPORTACAO_H */

