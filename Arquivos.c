#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Arquivos.h"
#include "Transacoes.h"

void GravarDadosHotel(hotel *hot, int TipoArq){

    FILE *arqHotel;

    switch(TipoArq){

        case 1:
            arqHotel = fopen("Hotel.txt", "w");

            if(arqHotel == NULL){
                printf("\n Erro ao gravar o arquivo");
            }else{
                fprintf(arqHotel, "%s;", hot->nomeHotel);
                hot->nomeHotel[strcspn(hot->nomeHotel, "\n")] = 0;
                fprintf(arqHotel, "%s;", hot->razaoSocialHotel);
                hot->razaoSocialHotel[strcspn(hot->razaoSocialHotel, "\n")] = 0;
                fprintf(arqHotel, "%s;", hot->inscriEstadualHotel);
                hot->inscriEstadualHotel[strcspn(hot->inscriEstadualHotel, "\n")] = 0;
                fprintf(arqHotel, "%s;", hot->cnpjHotel);
                hot->cnpjHotel[strcspn(hot->cnpjHotel, "\n")] = 0;
                fprintf(arqHotel, "%s;", hot->telefoneHotel);
                hot->telefoneHotel[strcspn(hot->telefoneHotel, "\n")] = 0;
                fprintf(arqHotel, "%s;", hot->emailHotel);
                hot->emailHotel[strcspn(hot->emailHotel, "\n")] = 0;
                fprintf(arqHotel, "%s;", hot->responsavelHotel);
                hot->responsavelHotel[strcspn(hot->responsavelHotel, "\n")] = 0;
                fprintf(arqHotel, "%s;", hot->telResponsavelHotel);
                hot->telResponsavelHotel[strcspn(hot->telResponsavelHotel, "\n")] = 0;
                fprintf(arqHotel, "%s;", hot->horaCheckInHotel);
                hot->horaCheckInHotel[strcspn(hot->horaCheckInHotel, "\n")] = 0;
                fprintf(arqHotel, "%s;", hot->horaCheckOutHotel);
                hot->horaCheckOutHotel[strcspn(hot->horaCheckOutHotel, "\n")] = 0;
                fprintf(arqHotel, "%ld;", hot->margemLucroHotel);
                fprintf(arqHotel, "%d;", hot->capacidadeHotel);
                fprintf(arqHotel, "%d;", hot->qtdAcomod);
                fprintf(arqHotel, "%d;", hot->tamEstoque);
                fprintf(arqHotel, "%d;", hot->quantFornec);
                fprintf(arqHotel, "%d;", hot->quantOpe);
                fprintf(arqHotel, "%s;", hot->ender.numHotel);
                hot->ender.numHotel[strcspn(hot->ender.numHotel, "\n")] = 0;
                fprintf(arqHotel, "%s;", hot->ender.ruaHotel);
                hot->ender.ruaHotel[strcspn(hot->ender.ruaHotel, "\n")] = 0;
                fprintf(arqHotel, "%s;", hot->ender.bairroHotel);
                hot->ender.bairroHotel[strcspn(hot->ender.bairroHotel, "\n")] = 0;
                fprintf(arqHotel, "%s;", hot->ender.cidadeHotel);
                hot->ender.cidadeHotel[strcspn(hot->ender.cidadeHotel, "\n")] = 0;
                fprintf(arqHotel, "%s;", hot->ender.estadoHotel);
                hot->ender.estadoHotel[strcspn(hot->ender.estadoHotel, "\n")] = 0;

                if(ferror(arqHotel)){
                    printf("\n Erro ao gravar arquivo");
                } else {
                    printf("\n Gravação realizada com sucesso");
                }
            }
        fclose(arqHotel);
        break;

        case 2:

            arqHotel = fopen("Hotel.bin", "wb");
            if(arqHotel == NULL){
                printf("\n Erro ao gravar o arquivo");
            }else{

                fwrite(&hot, sizeof(hotel), 1, arqHotel);

                if(ferror(arqHotel)){
                    printf("\n Erro ao gravar arquivo");
                } else {
                    printf("\n Gravação realizada com sucesso");
                }
            }
        fclose(arqHotel);
        break;
    }
}

void GravarDadosHospedes(int totHosp, hospede *hospedes, int TipoArq){
    int i;

    FILE *arqHosp;

        switch(TipoArq){

            case 1:

                arqHosp = fopen("Hospedes.txt", "w");

                if(arqHosp == NULL){
                    printf("\n Erro ao gravar o arquivo");
                }else{
                    for(i=0; i<=totHosp; i++){
                        fprintf(arqHosp, "%d;", hospedes[i].codigoHospede);

                        fprintf(arqHosp, "%s;", hospedes[i].nomeHospede);
                        hospedes[i].nomeHospede[strcspn(hospedes[i].nomeHospede, "\n")] = 0;
                        
                        fprintf(arqHosp, "%s;", hospedes[i].cpf);
                        hospedes[i].cpf[strcspn(hospedes[i].cpf, "\n")] = 0;

                        hospedes[i].telHospede[strcspn(hospedes[i].telHospede, "\n")] = 0;
                        fprintf(arqHosp, "%s;", hospedes[i].telHospede);

                        hospedes[i].emailHospede[strcspn(hospedes[i].emailHospede, "\n")] = 0;
                        fprintf(arqHosp, "%s;", hospedes[i].emailHospede);

                        hospedes[i].sexo[strcspn(hospedes[i].sexo, "\n")] = 0;
                        fprintf(arqHosp, "%s;", hospedes[i].sexo);

                        hospedes[i].estCivHospede[strcspn(hospedes[i].estCivHospede, "\n")] = 0;
                        fprintf(arqHosp, "%s;", hospedes[i].estCivHospede);

                        hospedes[i].dataNasci[strcspn(hospedes[i].dataNasci, "\n")] = 0;
                        fprintf(arqHosp, "%s;", hospedes[i].dataNasci);

                        hospedes[i].enderHosp.num[strcspn(hospedes[i].enderHosp.num, "\n")] = 0;
                        fprintf(arqHosp, "%s;", hospedes[i].enderHosp.num);

                        hospedes[i].enderHosp.rua[strcspn(hospedes[i].enderHosp.rua, "\n")] = 0;
                        fprintf(arqHosp, "%s;", hospedes[i].enderHosp.rua);

                        hospedes[i].enderHosp.bairro[strcspn(hospedes[i].enderHosp.bairro, "\n")] = 0;
                        fprintf(arqHosp, "%s;", hospedes[i].enderHosp.bairro);

                        hospedes[i].enderHosp.cidade[strcspn(hospedes[i].enderHosp.cidade, "\n")] = 0;
                        fprintf(arqHosp, "%s;", hospedes[i].enderHosp.cidade);

                        hospedes[i].enderHosp.estado[strcspn(hospedes[i].enderHosp.estado, "\n")] = 0;
                        fprintf(arqHosp, "%s;", hospedes[i].enderHosp.estado);

                        hospedes[i].enderHosp.pais[strcspn(hospedes[i].enderHosp.pais, "\n")] = 0;
                        fprintf(arqHosp, "%s;", hospedes[i].enderHosp.pais);

                    }
                    if(ferror(arqHosp)){
                        printf("\n Erro ao gravar arquivo");
                    } else {
                        printf("\n Gravação realizada com sucesso");
                    }
                }
                fclose(arqHosp);
            break;

            case 2:

                arqHosp = fopen("Hospedes.bin", "wb");
                if(arqHosp == NULL){
                    printf("\n Erro ao gravar o arquivo");
                }else{
                    for(i=0; i<totHosp; i++){
                        fwrite(&hospedes[i], sizeof(hospede), 1, arqHosp);
                    }
                    if(ferror(arqHosp)){
                        printf("\n Erro ao gravar arquivo");
                    } else {
                        printf("\n Gravação realizada com sucesso");
                    }
                }
                fclose(arqHosp);
            break;
        }
}

void GravarDadosCategoria(int totCat, categoriaAcomod *categorias, int TipoArq){
    int i;

    FILE *arqCat;

        switch(TipoArq){

            case 1:

                arqCat = fopen("Categorias De Acomodação.txt", "w");

                if(arqCat == NULL){
                    printf("\n Erro ao gravar o arquivo");
                }else{
                    for(i=0; i<totCat; i++){
                        fprintf(arqCat, "%d;", categorias[i].codigoCategoriaAcomod);
                        categorias[i].descricaoCat[strcspn(categorias[i].descricaoCat, "\n")] = 0;
                        fprintf(arqCat, "%s;", categorias[i].descricaoCat);
                        fprintf(arqCat, "%f;", categorias[i].valorDiaria);
                        fprintf(arqCat, "%d;", categorias[i].QuantCriancas);
                        fprintf(arqCat, "%d;", categorias[i].QuantAdultos);
                    }
                    if(ferror(arqCat)){
                        printf("\n Erro ao gravar arquivo");
                    } else {
                        printf("\n Gravação realizada com sucesso");
                    }
                }
                fclose(arqCat);
            break;

            case 2:

                arqCat = fopen("Categorias De Acomodação.bin", "wb");
                if(arqCat == NULL){
                    printf("\n Erro ao gravar o arquivo");
                }else{
                    for(i=0; i<totCat; i++){
                        fwrite(&categorias[i], sizeof(categoriaAcomod), 1, arqCat);
                    }
                    if(ferror(arqCat)){
                        printf("\n Erro ao gravar arquivo");
                    } else {
                        printf("\n Gravação realizada com sucesso");
                    }
                }
                fclose(arqCat);
            break;
        }
}

void GravarDadosAcomodacoes(int totAcomod, acomodacoes *acomodacoes, int TipoArq){
    int i;

    FILE *arqAcomod;

        switch(TipoArq){

            case 1:

                arqAcomod = fopen("Acomodações.txt", "w");

                if(arqAcomod == NULL){
                    printf("\n Erro ao gravar o arquivo");
                }else{
                    for(i=0; i<totAcomod; i++){
                        fprintf(arqAcomod, "%d;", acomodacoes[i].codigoAcomod);
                        acomodacoes[i].descricaoAcomod[strcspn(acomodacoes[i].descricaoAcomod, "\n")] = 0;
                        fprintf(arqAcomod, "%s;", acomodacoes[i].descricaoAcomod);
                        acomodacoes[i].facilidades[strcspn(acomodacoes[i].facilidades, "\n")] = 0;
                        fprintf(arqAcomod, "%s;", acomodacoes[i].facilidades);
                        acomodacoes[i].categoria.descricaoCat[strcspn(acomodacoes[i].categoria.descricaoCat, "\n")] = 0;
                        fprintf(arqAcomod, "%s;", acomodacoes[i].categoria.descricaoCat);
                    }
                    if(ferror(arqAcomod)){
                        printf("\n Erro ao gravar arquivo");
                    } else {
                        printf("\n Gravação realizada com sucesso");
                    }
                }
                fclose(arqAcomod);
            break;

            case 2:

                arqAcomod = fopen("Acomodações.bin", "wb");
                if(arqAcomod == NULL){
                    printf("\n Erro ao gravar o arquivo");
                }else{
                    for(i=0; i<totAcomod; i++){
                        fwrite(&acomodacoes[i], sizeof(acomodacoes), 1, arqAcomod);
                    }
                    if(ferror(arqAcomod)){
                        printf("\n Erro ao gravar arquivo");
                    } else {
                        printf("\n Gravação realizada com sucesso");
                    }
                }
                fclose(arqAcomod);
            break;

        }
}

void GravarDadosProdutos(int totProd, produtos *produto, int TipoArq){
    int i;

    FILE *arqProd;

        switch(TipoArq){

            case 1:

                arqProd = fopen("Produtos.txt", "w");

                if(arqProd == NULL){
                    printf("\n Erro ao gravar o arquivo");
                }else{
                    for(i=0; i<totProd; i++){
                        fprintf(arqProd, "%d;", produto[i].codigoProduto);
                        fprintf(arqProd, "%s;", produto[i].descricao);
                        produto[i].descricao[strcspn(produto[i].descricao, "\n")] = 0;
                        fprintf(arqProd, "%d;", produto[i].estoque);
                        fprintf(arqProd, "%d;", produto[i].estoqueMin);
                        fprintf(arqProd, "%d;", produto[i].precoCusto);
                        fprintf(arqProd, "%d;", produto[i].precoVenda);
                    }
                    if(ferror(arqProd)){
                        printf("\n Erro ao gravar arquivo");
                    } else {
                        printf("\n Gravação realizada com sucesso");
                    }
                }
                fclose(arqProd);
            break;

            case 2:

                arqProd = fopen("Produtos.bin", "wb");
                if(arqProd == NULL){
                    printf("\n Erro ao gravar o arquivo");
                }else{
                    for(i=0; i<totProd; i++){
                        fwrite(&produto[i], sizeof(produtos), 1, arqProd);
                    }
                    if(ferror(arqProd)){
                        printf("\n Erro ao gravar arquivo");
                    } else {
                        printf("\n Gravação realizada com sucesso");
                    }
                }
                fclose(arqProd);
            break;
        }

}

void GravarDadosFornecedores(int totFornec, fornecedores *fornecs, int TipoArq){
    int i;

    FILE *arqFornec;

        switch(TipoArq){

            case 1:

                arqFornec = fopen("Fornecedores.txt", "w");

                if(arqFornec == NULL){
                    printf("\n Erro ao gravar o arquivo");
                }else{
                    for(i=0; i<totFornec; i++){
                        fprintf(arqFornec, "%d;", fornecs[i].codigoFornec);
                        fprintf(arqFornec, "%s;", fornecs[i].nomeFornec);
                        fornecs[i].nomeFornec[strcspn(fornecs[i].nomeFornec, "\n")] = 0;
                        fprintf(arqFornec, "%s;", fornecs[i].razaoSocialFornec);
                        fornecs[i].razaoSocialFornec[strcspn(fornecs[i].razaoSocialFornec, "\n")] = 0;
                        fprintf(arqFornec, "%s;", fornecs[i].inscricaoEstFornec);
                        fornecs[i].inscricaoEstFornec[strcspn(fornecs[i].inscricaoEstFornec, "\n")] = 0;
                        fprintf(arqFornec, "%s;", fornecs[i].cnpj);
                        fornecs[i].cnpj[strcspn(fornecs[i].cnpj, "\n")] = 0;
                        fprintf(arqFornec, "%s;", fornecs[i].telefoneFornec);
                        fornecs[i].telefoneFornec[strcspn(fornecs[i].telefoneFornec, "\n")] = 0;
                        fprintf(arqFornec, "%s;", fornecs[i].email);
                        fornecs[i].email[strcspn(fornecs[i].email, "\n")] = 0;
                        fprintf(arqFornec, "%s;", fornecs[i].enderFornec.numFornec);
                        fornecs[i].enderFornec.numFornec[strcspn(fornecs[i].enderFornec.numFornec, "\n")] = 0;
                        fprintf(arqFornec, "%s;", fornecs[i].enderFornec.ruaFornec);
                        fornecs[i].enderFornec.ruaFornec[strcspn(fornecs[i].enderFornec.ruaFornec, "\n")] = 0;
                        fprintf(arqFornec, "%s;", fornecs[i].enderFornec.bairroFornec);
                        fornecs[i].enderFornec.bairroFornec[strcspn(fornecs[i].enderFornec.bairroFornec, "\n")] = 0;
                        fprintf(arqFornec, "%s;", fornecs[i].enderFornec.cidadeFornec);
                        fornecs[i].enderFornec.cidadeFornec[strcspn(fornecs[i].enderFornec.cidadeFornec, "\n")] = 0;
                        fprintf(arqFornec, "%s;", fornecs[i].enderFornec.estadoFornec);
                        fornecs[i].enderFornec.estadoFornec[strcspn(fornecs[i].enderFornec.estadoFornec, "\n")] = 0;
                        fprintf(arqFornec, "%s;", fornecs[i].enderFornec.paisFornec);
                        fornecs[i].enderFornec.paisFornec[strcspn(fornecs[i].enderFornec.paisFornec, "\n")] = 0;
                    }
                    if(ferror(arqFornec)){
                        printf("\n Erro ao gravar arquivo");
                    } else {
                        printf("\n Gravação realizada com sucesso");
                    }
                }
                fclose(arqFornec);
            break;

            case 2:

                arqFornec = fopen("Fornecedores.bin", "wb");
                if(arqFornec == NULL){
                    printf("\n Erro ao gravar o arquivo");
                }else{
                    for(i=0; i<totFornec; i++){
                        fwrite(&fornecs[i], sizeof(fornecedores), 1, arqFornec);
                    }
                    if(ferror(arqFornec)){
                        printf("\n Erro ao gravar arquivo");
                    } else {
                        printf("\n Gravação realizada com sucesso");
                    }
                }
                fclose(arqFornec);
            break;
        }
}

void GravarDadosReservas(int totalRes, reservas *reserv, int TipoArq){
    int i;

    FILE *arqRes;

        switch(TipoArq){

            case 1:

                arqRes = fopen("Reservas.txt", "w");

                if(arqRes == NULL){
                    printf("\n Erro ao gravar o arquivo");
                }else{
                    for(i=0; i<totalRes; i++){

                        fprintf(arqRes, "%d;", reserv[i].codAcomodRes);
                        fprintf(arqRes, "%s;", reserv[i].nomePessoa);
                        reserv[i].nomePessoa[strcspn(reserv[i].nomePessoa, "\n")] = 0;
                        fprintf(arqRes, "%s;", reserv[i].catReserva);
                        reserv[i].catReserva[strcspn(reserv[i].catReserva, "\n")] = 0;
                        fprintf(arqRes, "%s;", reserv[i].strDataIni);
                        reserv[i].strDataIni[strcspn(reserv[i].strDataIni, "\n")] = 0;
                        fprintf(arqRes, "%s;", reserv[i].strDataFinal);
                        reserv[i].strDataFinal[strcspn(reserv[i].strDataFinal, "\n")] = 0;
                    }
                    if(ferror(arqRes)){
                        printf("\n Erro ao gravar arquivo");
                    } else {
                        printf("\n Gravação realizada com sucesso");
                    }
                }
                fclose(arqRes);
            break;

            case 2:

                arqRes = fopen("Reservas.bin", "wb");
                if(arqRes == NULL){
                    printf("\n Erro ao gravar o arquivo");
                }else{
                    for(i=0; i<totalRes; i++){
                        fwrite(&reserv[i], sizeof(reservas), 1, arqRes);
                    }
                    if(ferror(arqRes)){
                        printf("\n Erro ao gravar arquivo");
                    } else {
                        printf("\n Gravação realizada com sucesso");
                    }
                }
                fclose(arqRes);
            break;
        }
}

int LerDadosBinHotel(hotel *hot){
    int i;
    FILE *arqHotel = fopen("Hotel.bin", "rb");

    if(arqHotel == NULL){
        printf("\n Erro na leitura do arquivo");
    } else {
    i = 1;
    fread(&hot, sizeof(hotel), 1, arqHotel);

        if(ferror(arqHotel)){
            printf("\n Erro na leitura do arquivo");
        } else {
            printf("\n Arquivo lido com sucesso");
        }
    }
    fclose(arqHotel);
    return i;
}

int LerDadosTxtHospedes(hospede *hospedes){
    int i=0;
    FILE *arqHosp = fopen("Hospedes.txt", "r");

    if(arqHosp == NULL){
        printf("\n Erro na leitura do arquivo");
    } else {
        while(feof(arqHosp) == 0){
            if(fscanf(arqHosp, "%d;%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];",
                &hospedes[i].codigoHospede, hospedes[i].nomeHospede,
                hospedes[i].cpf, hospedes[i].telHospede, hospedes[i].emailHospede,
                hospedes[i].sexo, hospedes[i].estCivHospede,
                hospedes[i].dataNasci, hospedes[i].enderHosp.num,
                hospedes[i].enderHosp.rua, hospedes[i].enderHosp.bairro,
                hospedes[i].enderHosp.cidade, hospedes[i].enderHosp.estado, hospedes[i].enderHosp.pais) == 14){
                i++;
        }
        }

        if(ferror(arqHosp)){
            printf("\n Erro na leitura do arquivo");
        } else {
            printf("\n Arquivo lido com sucesso");
        }
    }
    fclose(arqHosp);

    return i;
}

int LerDadosTxtCategorias(categoriaAcomod *categorias){
    int i=0;
    FILE *arqCat = fopen("Categorias De Acomodação.txt", "r");

    if(arqCat == NULL){
        printf("\n Erro na leitura do arquivo");
    } else {
        while(feof(arqCat) == 0){
            if(fscanf(arqCat, "%d;%[^;];%f;%d;%d;",
                &categorias[i].codigoCategoriaAcomod, categorias[i].descricaoCat,
                &categorias[i].valorDiaria, &categorias[i].QuantCriancas,
                &categorias[i].QuantAdultos) == 5){
            i++;
        }
        }
        if(ferror(arqCat)){
            printf("\n Erro na leitura do arquivo");
        } else {
            printf("\n Arquivo lido com sucesso");
        }
    }
    fclose(arqCat);

    return i;
}

int LerDadosTxtAcomodacoes(acomodacoes *acomodacoes){
   FILE *arqAcomod = fopen("Acomodações.txt", "r");
   int i=0;

   if(arqAcomod == NULL){
        printf("\n Erro na leitura do arquivo");
    } else {
        while(feof(arqAcomod) == 0){
            if(fscanf(arqAcomod, "%d;%[^;];%[^;];%[^;];",
                &acomodacoes[i].codigoAcomod, acomodacoes[i].descricaoAcomod,
                acomodacoes[i].facilidades, acomodacoes[i].categoria.descricaoCat) == 4){
            i++;
            }
        }

        if(ferror(arqAcomod)){
            printf("\n Erro na leitura do arquivo");
        } else {
            printf("\n Arquivo lido com sucesso");
        }
    }
    fclose(arqAcomod);

    return i;
}

int LerDadosTxtProdutos(produtos *produto){
    FILE *arqProd = fopen("Produtos.txt", "r");
    int i=0;


    if(arqProd == NULL){
        printf("\n Erro na leitura do arquivo");
    } else{
            if(fscanf(arqProd, "%d;%[^;];%d;%d;%d;%d;",
                &produto[i].codigoProduto, produto[i].descricao,
                &produto[i].estoque, &produto[i].estoqueMin,
                &produto[i].precoCusto, &produto[i].precoVenda) == 6){
                i++;
            }
        }

        if(ferror(arqProd)){
            printf("\n Erro na leitura do arquivo");
        } else {
            printf("\n Arquivo lido com sucesso");
        }

    fclose(arqProd);

    return i;
}

int LerDadosTxtFornecedores(fornecedores *fornecs){
    int i=0;
    FILE *arqFornec = fopen("Fornecedores.txt", "r");


    if(arqFornec == NULL){
        printf("\n Erro na leitura do arquivo");
    } else {
        while(fscanf(arqFornec, "%d;%[^;];%[^;];%[^;];%[^;];%50[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];",
                &fornecs[i].codigoFornec, fornecs[i].nomeFornec,
                fornecs[i].razaoSocialFornec, fornecs[i].inscricaoEstFornec,
                fornecs[i].cnpj, fornecs[i].telefoneFornec,
                fornecs[i].email, fornecs[i].enderFornec.numFornec,
                fornecs[i].enderFornec.ruaFornec, fornecs[i].enderFornec.bairroFornec,
                fornecs[i].enderFornec.cidadeFornec, fornecs[i].enderFornec.estadoFornec, fornecs[i].enderFornec.paisFornec) == 13){
            i++;
        }
        if(ferror(arqFornec)){
            printf("\n Erro na leitura do arquivo");
        } else {
            printf("\n Arquivo lido com sucesso");
        }
    }
    fclose(arqFornec);

    return i;
}

int LerDadosTxtReservas(reservas *reserv){
    int i=0;
    FILE *arqRes = fopen("Reservas.txt", "r");

    if(arqRes == NULL){
        printf("\n Erro na leitura do arquivo");
    } else {
        while(fscanf(arqRes, "%d;%[^;];%[^;];%[^;];%[^;];",
                &reserv[i].codAcomodRes, reserv[i].nomePessoa, reserv[i].catReserva,
                reserv[i].strDataIni, reserv[i].strDataFinal) == 5){
            i++;
        }
        if(ferror(arqRes)){
            printf("\n Erro na leitura do arquivo");
        } else {
            printf("\n Arquivo lido com sucesso");
        }
    }
    fclose(arqRes);

    return i;
}

int LerDadosTxtHotel(hotel *hot){
    int i=0;
    FILE *arqHotel = fopen("Hotel.txt", "r");

    if(arqHotel == NULL){
        printf("\n Erro na leitura do arquivo");
    } else {

        fscanf(arqHotel, "%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%;[^;];%ld;%d;%d;%d;%d;%d;%[^;];%[^;];%[^;]%[^;];%[^;];",
        hot->nomeHotel, hot->razaoSocialHotel,
        hot->inscriEstadualHotel, hot->cnpjHotel,
        hot->telefoneHotel, hot->emailHotel,
        hot->responsavelHotel, hot->telResponsavelHotel,
        hot->horaCheckInHotel, hot->horaCheckOutHotel,
        &hot->margemLucroHotel, &hot->capacidadeHotel, &hot->qtdAcomod,
        &hot->tamEstoque, &hot->quantFornec, &hot->quantOpe,
        hot->ender.numHotel, hot->ender.ruaHotel, hot->ender.bairroHotel,
        hot->ender.cidadeHotel, hot->ender.estadoHotel);

        i = 1;

        if(ferror(arqHotel)){
            printf("\n Erro na leitura do arquivo");
        } else {
            printf("\n Arquivo lido com sucesso");
        }
    }
    fclose(arqHotel);
    return i;
}

int LerDadosBinProdutos(produtos *produto){
    int i=0;
    FILE *arqProd = fopen("Produtos.bin", "rb");

    if(arqProd == NULL){
        printf("\n Erro na leitura do arquivo");
    } else {

    fread(&produto[i], sizeof(produtos), 1, arqProd);
    while(!feof(arqProd)){
        printf("\n Código do produto %d", produto[i].codigoProduto);
        printf("\n Descrição do produto %s", produto[i].descricao);
        printf(" Estoque do produto %d", produto[i].estoque);
        printf("\n Estoque Mínimo do produto %d", produto[i].estoqueMin);
        printf("\n Preço de Custo do produto %d", produto[i].precoCusto);
        printf("\n Preço de Venda do produto %f", produto[i].precoVenda);
        i++;
        fread(&produto[i], sizeof(produtos), 1, arqProd);
    }
    if(ferror(arqProd)){
            printf("\n Erro na leitura do arquivo");
        } else {
            printf("\n Arquivo lido com sucesso");
        }
    }
    fclose(arqProd);
    return i;
}

int LerDadosBinFornecedores(fornecedores *fornecs){
    int i=0;
    FILE *arqFornec = fopen("Fornecedores.bin", "rb");

    if(arqFornec == NULL){
        printf("\n Erro na leitura do arquivo");
    } else {

    fread(&fornecs[i], sizeof(fornecedores), 1, arqFornec);
    while(!feof(arqFornec)){
        fread(&fornecs[i], sizeof(fornecedores), 1, arqFornec);
    }
    if(ferror(arqFornec)){
            printf("\n Erro na leitura do arquivo");
        } else {
            printf("\n Arquivo lido com sucesso");
        }
    }
    fclose(arqFornec);
    return i;
}


int LerDadosBinHospedes(hospede *hospedes){
    int i=0;

    FILE *arqHosp = fopen("Hospedes.bin", "rb");

    if(arqHosp == NULL){
        printf("\n Erro na leitura do arquivo");
    } else {

    fread(&hospedes[i], sizeof(hospede), 1, arqHosp);
    while(!feof(arqHosp)){

        i++;
        fread(&hospedes[i], sizeof(hospede), 1, arqHosp);
    }
    if(ferror(arqHosp)){
            printf("\n Erro na leitura do arquivo");
        } else {
            printf("\n Arquivo lido com sucesso");
        }
    }
    fclose(arqHosp);

    return i;
}


int LerDadosBinCategorias(categoriaAcomod *categorias){
    int i=0;

    FILE *arqCat = fopen("Categorias De Acomodação.bin", "rb");

    if(arqCat == NULL){
        printf("\n Erro na leitura do arquivo");
    } else {

    fread(&categorias[i], sizeof(categoriaAcomod), 1, arqCat);
    while(!feof(arqCat)){

        i++;
        fread(&categorias[i], sizeof(categoriaAcomod), 1, arqCat);
    }
    if(ferror(arqCat)){
            printf("\n Erro na leitura do arquivo");
        } else {
            printf("\n Arquivo lido com sucesso");
        }
    }
    fclose(arqCat);

    return i;
}


int LerDadosBinAcomodacoes(acomodacoes *acomodacoes){
    int i=0;

    FILE *arqAc = fopen("Acomodacoes.bin", "rb");

    if(arqAc == NULL){
        printf("\n Erro na leitura do arquivo");
    } else {

    fread(&acomodacoes[i], sizeof(acomodacoes), 1, arqAc);
    while(!feof(arqAc)){

        i++;
        fread(&acomodacoes[i], sizeof(acomodacoes), 1, arqAc);
    }
    if(ferror(arqAc)){
            printf("\n Erro na leitura do arquivo");
        } else {
            printf("\n Arquivo lido com sucesso");
        }
    }
    fclose(arqAc);

    return i;
}

int LerDadosBinReservas(reservas *reserv){
    int i=0;

    FILE *arqRes = fopen("Reservas.bin", "rb");

    if(arqRes == NULL){
        printf("\n Erro na leitura do arquivo");
    } else {

    fread(&reserv[i], sizeof(reservas), 1, arqRes);
    while(!feof(arqRes)){

        i++;
        fread(&reserv[i], sizeof(reservas), 1, arqRes);
    }
    if(ferror(arqRes)){
            printf("\n Erro na leitura do arquivo");
        } else {
            printf("\n Arquivo lido com sucesso");
        }
    }
    fclose(arqRes);

    return i;
}


void GravarDadosCaixa(int *k, caixa *caixaHotel, int TipoArq){
    int i;

    FILE *arqCaixa = fopen("Caixa.txt", "w");

        switch(TipoArq){

            case 1:
                arqCaixa = fopen("Caixa.txt", "w");

                if(arqCaixa == NULL){
                    printf("\n Erro na leitura do arquivo");
                } else {
                    for(i=0; i<*k;i++){
                        fprintf(arqCaixa, "%f;", caixaHotel[i].valorTransacao);
                        caixaHotel[i].tipoTransacao[strcspn(caixaHotel[i].tipoTransacao, "\n")] = 0;
                        fprintf(arqCaixa, "%s;", caixaHotel[i].tipoTransacao);
                        fprintf(arqCaixa, "%f;", caixaHotel->totCaixa);
                    }
                }
                if(ferror(arqCaixa)){
                    printf("\n Erro ao gravar arquivo");
                } else {
                    printf("\n Gravação realizada com sucesso");
                }
            break;

            case 2:
                arqCaixa = fopen("Caixa.txt", "wb");

                if(arqCaixa == NULL){
                printf("\n Erro ao gravar o arquivo");
            }else{
                for(i=0; i<*k; i++){
                    fwrite(&caixaHotel[i], sizeof(caixa), 1, arqCaixa);
                }
                    if(ferror(arqCaixa)){
                        printf("\n Erro ao gravar arquivo");
                    } else {
                        printf("\n Gravação realizada com sucesso");
                    }
                }
            break;
        }
    fclose(arqCaixa);
}

void GravarDadosContHosp(int *k, contHosp *cont, int TipoArq){
    int i;
    int j;
    int cod=0;

    FILE *arqContas = arqContas = fopen("Contas.txt", "w");

    switch(TipoArq){

        case 1:
            if(arqContas == NULL){
                printf("\n Erro na leitura do arquivo");
            } else {
                for(i=0; i<*k; i++){
                    cont[i].nomeCont[strcspn(cont[i].nomeCont, "\n")] = 0;
                    fprintf(arqContas, "%s;", cont[i].nomeCont);
                    fprintf(arqContas, "%d;", cont[i].qtdPrdsComp);
                    fprintf(arqContas, "%f;", cont[i].totalPag);
                    fprintf(arqContas, "%f;", cont[i].valorTot);
                    cod = i;
                    for(j=0; j<cont[cod].qtdPrdsComp; j++){
                        cont[cod].dadosPro[j].prodComp[strcspn(cont[cod].dadosPro[j].prodComp, "\n")] = 0;
                        fprintf(arqContas, "%s;", cont[cod].dadosPro[j].prodComp);
                        fprintf(arqContas, "%d;", cont[cod].dadosPro[j].qtdProd);
                    }
                }
            }
        break;

        case 2:
            if(arqContas == NULL){
                printf("\n Erro ao gravar o arquivo");
            }else{
                for(i=0; i<*k;i++){
                    fwrite(&cont[i], sizeof(contHosp), 1, arqContas);
                }
                if(ferror(arqContas)){
                    printf("\n Erro ao gravar arquivo");
                } else {
                    printf("\n Gravação realizada com sucesso");
                }
            }
        break;
    }

    fclose(arqContas);

}

int LerDadosTxtCaixa(caixa *caixaHotel){

    FILE *arqCaixa = fopen("Caixa.txt", "r");

    int i=0, j;

    if(arqCaixa == NULL){
        printf("\n Erro na leitura do arquivo");
    } else {
        while(feof(arqCaixa) == 0){
            if(fscanf(arqCaixa, "%f;%[^;];%f;", &caixaHotel[i].valorTransacao, caixaHotel[i].tipoTransacao, &caixaHotel->totCaixa) == 3){
                i++;
            }
        }
    }

        if(ferror(arqCaixa)){
            printf("\n Erro na leitura do arquivo");
        } else {
            printf("\n Arquivo lido com sucesso");
        }

    fclose(arqCaixa);

    return i;
}

int LerDadosBinCaixa(caixa *caixaHotel){
    int i=0;

    FILE *arqCaixa = fopen("Caixa.bin", "rb");

    if(arqCaixa == NULL){
        printf("\n Erro na leitura do arquivo");
    } else {

    fread(&caixaHotel[i], sizeof(caixa), 1, arqCaixa);
    while(!feof(arqCaixa)){

        i++;
        fread(&caixaHotel[i], sizeof(caixa), 1, arqCaixa);
    }
    if(ferror(arqCaixa)){
            printf("\n Erro na leitura do arquivo");
        } else {
            printf("\n Arquivo lido com sucesso");
        }
    }
    fclose(arqCaixa);

    return i;
}

int LerContasTxtHospedes(contHosp *cont){

    int i=0, j;

    FILE *arqContas = fopen("Contas.txt", "r");

    if(arqContas == NULL){
        printf("\n Erro na leitura do arquivo");
    } else {
        while(feof(arqContas) == 0){
            if(fscanf(arqContas, "%[^;];%d;%f;%f;", cont[i].nomeCont, &cont[i].qtdPrdsComp,
                &cont[i].totalPag, &cont[i].valorTot) == 4){
                for(j=0; j<cont[i].qtdPrdsComp; j++){
                    fscanf(arqContas, "%[^;];%d;", cont[i].dadosPro[j].prodComp, &cont[i].dadosPro[j].qtdProd);
                }
            i++;
            }
        }

        if(ferror(arqContas)){
            printf("\n Erro na leitura do arquivo");
        } else {
            printf("\n Arquivo lido com sucesso");
        }
    }

    fclose(arqContas);
    return i;
}

int LerContasBinHospedes(contHosp *cont){
    int i=0;

    FILE *arqContas = fopen("Contas.bin", "rb");

    if(arqContas == NULL){
        printf("\n Erro na leitura do arquivo");
    } else {

    fread(&cont[i], sizeof(contHosp), 1, arqContas);
    while(!feof(arqContas)){

        i++;
        fread(&cont[i], sizeof(contHosp), 1, arqContas);
    }
    if(ferror(arqContas)){
            printf("\n Erro na leitura do arquivo");
        } else {
            printf("\n Arquivo lido com sucesso");
        }
    }
    fclose(arqContas);

    return i;
}

void GravarDadosContFornec(int *k, itensInd *prodComp, int TipoArq){
    int i;
    int j;
    int cod=0;

    FILE *arqFornec;

    switch(TipoArq){

        case 1:
            arqFornec = fopen("Produtos Industrializados.txt", "w");

            if(arqFornec == NULL){
                printf("\n Erro ao gravar o arquivo");
            }else{
                for(i=0; i<*k; i++){
                    prodComp[i].nomeFornec[strcspn(prodComp[i].nomeFornec, "\n")] = 0;
                    fprintf(arqFornec, "%s;", prodComp[i].nomeFornec);
                    fprintf(arqFornec, "%f;", prodComp[i].precFrete);
                    fprintf(arqFornec, "%f;", prodComp[i].imp);
                    fprintf(arqFornec, "%f;", prodComp[i].totPag);
                    fprintf(arqFornec, "%d;", prodComp[i].qtdProdComp);
                    fprintf(arqFornec, "%f;", prodComp[i].preVenda);
                    cod = i;
                    for(j=0; j<prodComp[cod].qtdProdComp; j++){
                        prodComp[cod].prodInd[j].prodComp[strcspn(prodComp[cod].prodInd[j].prodComp, "\n")] = 0;
                        fprintf(arqFornec, "%s;", prodComp[cod].prodInd[j].prodComp);
                        fprintf(arqFornec, "%d;", prodComp[cod].prodInd[j].qtdProd);
                        fprintf(arqFornec, "%f;", prodComp[cod].prodInd[j].valorProd);
                    }
                }
            }

        break;

        case 2:
            arqFornec = fopen("Contas.bin", "wb");

            if(arqFornec == NULL){
                printf("\n Erro ao gravar o arquivo");
            }else{
                for(i=0; i<*k;i++){
                    fwrite(&prodComp[i], sizeof(contHosp), 1, arqFornec);
                }
                if(ferror(arqFornec)){
                    printf("\n Erro ao gravar arquivo");
                } else {
                    printf("\n Gravação realizada com sucesso");
                }
            }
        break;
    }

    fclose(arqFornec);

}

int LerContasTxtFornec(itensInd *prodComp){

    int i=0, j;

    FILE *arqPrd = fopen("Produtos Industrializados.txt", "r");

    if(arqPrd == NULL){
        printf("\n Erro na leitura do arquivo");
    } else {
        while(feof(arqPrd) == 0){
            if(fscanf(arqPrd, "%[^;];%f;%f;%f;%d;", prodComp[i].nomeFornec,
                    &prodComp[i].precFrete, &prodComp[i].imp,
                    &prodComp[i].totPag, &prodComp[i].qtdProdComp) == 5){
                for(j=0; j<prodComp[i].qtdProdComp; j++){
                    fscanf(arqPrd, "%[^;];%d;%f;", prodComp[i].prodInd[j].prodComp,
                            &prodComp[i].prodInd[j].qtdProd, &prodComp[i].prodInd[j].valorProd);
                }
            i++;
            }
        }

        if(ferror(arqPrd)){
            printf("\n Erro na leitura do arquivo");
        } else {
            printf("\n Arquivo lido com sucesso");
        }
    }

    fclose(arqPrd);
    return i;
}

int LerContasBinFornec(itensInd *prodComp){
    int i=0;

    FILE *arqFornec = fopen("Contas.bin", "rb");

    if(arqFornec == NULL){
        printf("\n Erro na leitura do arquivo");
    } else {

    fread(&prodComp[i], sizeof(contHosp), 1, arqFornec);
    while(!feof(arqFornec)){

        i++;
        fread(&prodComp[i], sizeof(contHosp), 1, arqFornec);
    }
    if(ferror(arqFornec)){
            printf("\n Erro na leitura do arquivo");
        } else {
            printf("\n Arquivo lido com sucesso");
        }
    }
    fclose(arqFornec);

    return i;
}
