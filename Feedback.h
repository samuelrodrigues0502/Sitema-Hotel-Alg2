
#ifndef FEEDBACK_H
#define FEEDBACK_H

#ifdef __cplusplus
extern "C" {
#endif

struct RelatEnderHosp {
    char relatRua[50];
    char relatBairro[50];
    char relatNum[50];
    char relatCidade[50];
    char relatEstado[50];
    char relatPais[30];
};

struct RelatorioAcomodacoes{

    int relatCodAcomod;
    char relatDescAcomod[50];
    char relatFaciAcomod[50];
    char relatCategAcomod[50];

};

typedef struct RelatorioAcomodacoes relatAcomod;

struct RelatorioReservas{

    char relatNmPessoa[50];
    char relatSexo[20];
    int relatCodAcomodRes;
    char relatCatRes[50];
    char relatDataIni[20];
    char relatDataFinal[20];

};

typedef struct RelatorioReservas relatRes;

struct RelatorioHospedes{
    int relatCodHosp;
    char relatNmHosp[50];
    char relatCpf[20];
    char relatTelHosp[20];
    char relatEmailHosp[30];
    char relatSexo[30];
    char relatEstCivHosp[30];
    char relatDataNasci[20];

    struct RelatEnderHosp relEnderHosp;
};

typedef struct RelatorioHospedes relatHosp;
        
struct RelatorioProdutos{

    int relatCodProd;
    char relatDescProd[50];
    int relatEstProd;
    int relatEstMinProd;
    float relatPreCusto;
    float relatPreVenda;

};

typedef struct RelatorioProdutos relatProd;

void RelatorioHospedes(char *sexoHosp, int codIni, int codFin, hospede *hosp);

void RelatorioAcomodacoes(int op, char *categoria, int codIni, int codFin, acomodacoes *acomodacoes, char *dataDisp, reservas *reserv, int *pTotRes);

void RelatorioReservas(int opHosp, int opAcomod, char *nomeHosp, char *sexoHosp, char *categoria, int codAcomod, int *pTotRes, reservas *reserv);

void MovAcomodacoes(int op, int codIni, char *catAcomod, int diasCup, int *totDiaAc, float redAcomod, diariaAcomod *diaAc);

void RelatorioProdutos(int codIni, int codFin, produtos *produto);

void RelatorioProdutosEstMin(int codIni, int codFin, produtos *produto);

void RelatorioContReceber(int codIni, int codFin, char *data, contReceber *cont);

#ifdef __cplusplus
}
#endif

#endif /* FEEDBACK_H */

