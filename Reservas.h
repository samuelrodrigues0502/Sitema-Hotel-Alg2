#include "GestaoDeDados.h"
#ifndef RESERVAS_H
#define RESERVAS_H

#ifdef __cplusplus
extern "C" {
#endif

struct Reserva{
    char nomePessoa[50];
    int codAcomodRes;
    char faciRes[50];
    char catReserva[50];
    char sexo[50];
    long long int dataIni;
    long long int dataFinal;
    char strDataIni[20];
    char strDataFinal[20];
};
typedef struct Reserva reservas;

struct DiariaAcomod{
    int codAcomod;
    char descricao[50];
    char facilidades[50];
    char categoria[50];
    float totDiaria;
    int totalDia;
};

typedef struct DiariaAcomod diariaAcomod;

int *AgendarReserva(int *count, int totAcomod, reservas *res, acomodacoes *ageAcomod);

void CancelarReserva(int *x, struct Reserva *res);

#ifdef __cplusplus
}
#endif

#endif /* RESERVAS_H */
