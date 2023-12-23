#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "GestaoDeDados.h"
#include "Arquivos.h"

void CadastrarProdutos(int *countPro, produtos *prod, int TipoArq){

    printf("\n Informe o código do produto: ");
    scanf("%d", &prod[*countPro].codigoProduto);
    setbuf(stdin, NULL);
    printf(" Informe a descrição do produto: ");
    fgets(prod[*countPro].descricao, sizeof(prod[*countPro].descricao), stdin);

    prod[*countPro].descricao[strcspn(prod[*countPro].descricao, "\n")] = 0;

    printf(" Informe a quantidade em estoque do produto: ");
    scanf("%d", &prod[*countPro].estoque);
    setbuf(stdin, NULL);
    printf(" Informe o estoque mínimo do produto: ");
    scanf("%d", &prod[*countPro].estoqueMin);
    setbuf(stdin, NULL);
    ++*countPro;
    
    GravarDadosProdutos(*countPro, prod, TipoArq);
}

void CadastrarHospedes(int *countHosp, hospede *hospedes, int TipoArq){

    printf("\n Cadastro de Hóspedes \n");

    printf("\n Informe o código do hóspede: ");
    scanf("%d", &hospedes[*countHosp].codigoHospede);
    setbuf(stdin, NULL);
    printf(" Informe o nome do hóspede: ");
    fgets(hospedes[*countHosp].nomeHospede, sizeof(hospedes[*countHosp].nomeHospede), stdin);
    printf(" Informe o cpf do hóspede: ");
    fgets(hospedes[*countHosp].cpf, sizeof(hospedes[*countHosp].cpf), stdin);
    printf(" Informe telefone do hóspede: ");
    fgets(hospedes[*countHosp].telHospede, sizeof(hospedes[*countHosp].telHospede), stdin);
    printf(" Informe email do hóspede: ");
    fgets(hospedes[*countHosp].emailHospede, sizeof(hospedes[*countHosp].emailHospede), stdin);
    printf(" Informe sexo do hóspede: ");
    fgets(hospedes[*countHosp].sexo, sizeof(hospedes[*countHosp].sexo), stdin);
    printf(" Informe estado civil do hóspede: ");
    fgets(hospedes[*countHosp].estCivHospede, sizeof(hospedes[*countHosp].estCivHospede), stdin);
    printf(" Informe a data de nascimento do hóspede: ");
    fgets(hospedes[*countHosp].dataNasci, sizeof(hospedes[*countHosp].dataNasci), stdin);
    printf("\n Endereço do Hóspede \n");
    printf("\n Informe o número do hóspede: ");
    fgets(hospedes[*countHosp].enderHosp.num, sizeof(hospedes[*countHosp].enderHosp.num), stdin);
    printf(" Informe a rua do hóspede: ");
    fgets(hospedes[*countHosp].enderHosp.rua, sizeof(hospedes[*countHosp].enderHosp.rua), stdin);
    printf(" Informe o bairro do hóspede: ");
    fgets(hospedes[*countHosp].enderHosp.bairro, sizeof(hospedes[*countHosp].enderHosp.bairro), stdin);
    printf(" Informe a cidade do hóspede: ");
    fgets(hospedes[*countHosp].enderHosp.cidade, sizeof(hospedes[*countHosp].enderHosp.cidade), stdin);
    printf(" Informe o estado do hóspede: ");
    fgets(hospedes[*countHosp].enderHosp.estado, sizeof(hospedes[*countHosp].enderHosp.estado), stdin);
    printf(" Informe o país do hóspede: ");
    fgets(hospedes[*countHosp].enderHosp.pais, sizeof(hospedes[*countHosp].enderHosp.pais), stdin);

    hospedes[*countHosp].nomeHospede[strcspn(hospedes[*countHosp].nomeHospede, "\n")] = 0;
    hospedes[*countHosp].cpf[strcspn(hospedes[*countHosp].cpf, "\n")] = 0;
    hospedes[*countHosp].telHospede[strcspn(hospedes[*countHosp].telHospede, "\n")] = 0;
    hospedes[*countHosp].emailHospede[strcspn(hospedes[*countHosp].emailHospede, "\n")] = 0;
    hospedes[*countHosp].sexo[strcspn(hospedes[*countHosp].sexo, "\n")] = 0;
    hospedes[*countHosp].estCivHospede[strcspn(hospedes[*countHosp].estCivHospede, "\n")] = 0;
    hospedes[*countHosp].dataNasci[strcspn(hospedes[*countHosp].dataNasci, "\n")] = 0;
    hospedes[*countHosp].enderHosp.num[strcspn(hospedes[*countHosp].enderHosp.num, "\n")] = 0;
    hospedes[*countHosp].enderHosp.rua[strcspn(hospedes[*countHosp].enderHosp.rua, "\n")] = 0;
    hospedes[*countHosp].enderHosp.bairro[strcspn(hospedes[*countHosp].enderHosp.bairro, "\n")] = 0;
    hospedes[*countHosp].enderHosp.cidade[strcspn(hospedes[*countHosp].enderHosp.cidade, "\n")] = 0;
    hospedes[*countHosp].enderHosp.estado[strcspn(hospedes[*countHosp].enderHosp.estado, "\n")] = 0;
    hospedes[*countHosp].enderHosp.pais[strcspn(hospedes[*countHosp].enderHosp.pais, "\n")] = 0;

    GravarDadosHospedes(*countHosp, hospedes, TipoArq);

    ++*countHosp;

}

void ModificarDadosHotel(int y, struct Hotel *x){

    int novoMargemLucro, novoCapHotel, novoTamEst, novoQtdFornec, novoQtdOpe;
    char novoNomeHotel[50], novoRazaoSocial[50], novoInscriEstadual[50], novoCNPJ[50];
    char novoNumHotel[50], novoEmailHotel[50], novoRuaHotel[50], novoBairroHotel[50], novoCidadeHotel[50];
    char novoEstadoHotel[50], novoTelHotel[50], novoRespHotel[50];
    char novoTelRespHotel[50], novoCheckInHotel[50], novoCheckOutHotel[50];

    switch (y){
        case 1:
            printf("Digite o novo nome do hotel: ");
            fgets(novoNomeHotel, sizeof(novoNomeHotel), stdin);
            strcpy(x->nomeHotel, novoNomeHotel);
        break;

        case 2:
            printf("Digite a nova razão social do hotel: ");
            fgets(novoRazaoSocial, sizeof(novoRazaoSocial), stdin);
            strcpy(x->razaoSocialHotel, novoRazaoSocial);
        break;

        case 3:
            printf("Digite a nova inscrição estadual do hotel: ");
            fgets(novoInscriEstadual, sizeof(novoInscriEstadual), stdin);
            strcpy(x->inscriEstadualHotel, novoInscriEstadual);
        break;

        case 4:
            printf("Digite o novo CNPJ do hotel: ");
            fgets(novoCNPJ, sizeof(novoCNPJ), stdin);
            strcpy(x->cnpjHotel, novoCNPJ);
        break;

        case 5:
           printf("Digite o novo telefone do hotel: ");
           fgets(novoTelHotel, sizeof(novoTelHotel), stdin);
           strcpy(x->telefoneHotel, novoTelHotel);
        break;

        case 6:
            printf("Digite o novo nome do hotel: ");
            fgets(novoEmailHotel, sizeof(novoEmailHotel), stdin);
            strcpy(x->emailHotel, novoEmailHotel);
        break;

        case 7:
            printf("Digite o novo nome do responsável pelo hotel: ");
            fgets(novoRespHotel, sizeof(novoRespHotel), stdin);
            strcpy(x->responsavelHotel, novoRespHotel);
        break;

        case 8:
            printf("Digite o novo telefone do responsável pelo hotel: ");
            fgets(novoTelRespHotel, sizeof(novoTelRespHotel), stdin);
            strcpy(x->telResponsavelHotel, novoTelRespHotel);
        break;

        case 9:
            printf("Digite o novo nome do hotel: ");
            fgets(novoCheckInHotel, sizeof(novoCheckInHotel), stdin);
            strcpy(x->horaCheckInHotel, novoCheckInHotel);
        break;

        case 10:
            printf("Digite o novo nome do hotel: ");
            fgets(novoCheckOutHotel, sizeof(novoCheckOutHotel), stdin);
            strcpy(x->horaCheckOutHotel, novoCheckOutHotel);
        break;

        case 11:
            printf("Digite a nova quantidade de forrnecedores do hotel: ");
            scanf("%li", &novoMargemLucro);
            x->margemLucroHotel = novoMargemLucro;
        break;

        case 12:
            printf("Digite a nova capacidade do hotel: ");
            scanf("%d", &novoCapHotel);
            x->capacidadeHotel = novoCapHotel;
        break;

        case 13:
            printf("Digite a novo tamanho do estoque do hotel: ");
            scanf("%d", &novoTamEst);
            x->tamEstoque = novoTamEst;
        break;

        case 14:
            printf("Digite a nova quantidade de forrnecedores do hotel: ");
            scanf("%d", &novoQtdFornec);
            x->quantFornec = novoQtdFornec;
        break;

        case 15:
            printf("Digite a nova capacidade do hotel: ");
            scanf("%d", &novoQtdOpe);
            x->quantOpe = novoQtdOpe;
        break;

        case 16:
            printf("Digite a nova rua do hotel: ");
            fgets(novoNumHotel, sizeof(novoNumHotel), stdin);
            strcpy(x->ender.ruaHotel, novoNumHotel);
        break;

        case 17:
            printf("Digite a nova rua do hotel: ");
            fgets(novoRuaHotel, sizeof(novoRuaHotel), stdin);
            strcpy(x->ender.ruaHotel, novoRuaHotel);
        break;

        case 18:
            printf("Digite o novo bairro: ");
            fgets(novoBairroHotel, sizeof(novoBairroHotel), stdin);
            strcpy(x->ender.bairroHotel, novoBairroHotel);
        break;

        case 19:
            printf("Digite a nova cidade do hotel: ");
            fgets(novoCidadeHotel, sizeof(novoCidadeHotel), stdin);
            strcpy(x->ender.cidadeHotel, novoCidadeHotel);
        break;

        case 20:
            printf("Digite o novo estado do hotel: ");
            fgets(novoEstadoHotel, sizeof(novoEstadoHotel), stdin);
            strcpy(x->ender.estadoHotel, novoEstadoHotel);
        break;
    }
}

void ModificarDadosHospede(int z, int x, hospede *hosp){
    int cod, i, novoCodHosp;
    char novoCpfHosp[50], novoTelHosp[50], novoEmailHosp[50], novoEstHosp[50];
    char novoNumHosp[50], novoRuaHosp[50], novoBairroHosp[50], novoCidHosp[50];
    char novoEstadoHosp[50], novoPaisHosp[50];

    printf("%d", x);

    char pesqNomeHosp[50];
    printf("Informe o nome que deseja pesquisar:");
    fgets(pesqNomeHosp, sizeof(pesqNomeHosp), stdin);

    pesqNomeHosp[strcspn(pesqNomeHosp, "\n")] = 0;

    for(i=0; i<x; i++){
        if(strcmp(pesqNomeHosp, hosp[i].nomeHospede) == 0){
            cod = i;
        }
    }

    switch(z){
        case 1:
            printf("\n Digite o novo código do hóspede: ");
            scanf("%d", &novoCodHosp);
            setbuf(stdin, NULL);

            hosp[cod].codigoHospede = novoCodHosp;
        break;

        case 2:
            printf("\n Digite o novo CPF do hóspede: ");
            fgets(novoCpfHosp, sizeof(novoCpfHosp), stdin);
            strcpy(hosp[cod].cpf, novoCpfHosp);
        break;

        case 3:
            printf("\n Digite o novo telefone do hóspede: ");
            fgets(novoTelHosp, sizeof(novoTelHosp), stdin);
            strcpy(hosp[cod].telHospede, novoTelHosp);
        break;

        case 4:
            printf("\n Digite o novo email do hóspede: ");
            fgets(novoEmailHosp, sizeof(novoEmailHosp), stdin);
            strcpy(hosp[cod].emailHospede, novoEmailHosp);
        break;

        case 5:
            printf("\n Digite o novo estado civil do hóspede: ");
            fgets(novoEstHosp, sizeof(novoEstHosp), stdin);
            strcpy(hosp[cod].estCivHospede, novoEstHosp);
        break;

        case 6:
            printf("\n Digite o novo número da casa do hóspede: ");
            fgets(novoNumHosp, sizeof(novoNumHosp), stdin);
            strcpy(hosp[cod].enderHosp.num, novoNumHosp);
        break;

        case 7:
            printf("\n Digite a nova rua do hóspede: ");
            fgets(novoRuaHosp, sizeof(novoRuaHosp), stdin);
            strcpy(hosp[cod].enderHosp.rua, novoRuaHosp);
        break;

        case 8:
            printf("\n Digite o novo bairro hóspede: ");
            fgets(novoBairroHosp, sizeof(novoBairroHosp), stdin);
            strcpy(hosp[cod].enderHosp.bairro, novoBairroHosp);
        break;

        case 9:
            printf("\n Digite a novo cidade do hóspede: ");
            fgets(novoCidHosp, sizeof(novoCidHosp), stdin);
            strcpy(hosp[cod].enderHosp.cidade, novoCidHosp);
        break;

        case 10:
            printf("\n Digite o novo estado do hóspede: ");
            fgets(novoEstadoHosp, sizeof(novoEstadoHosp), stdin);
            strcpy(hosp[cod].enderHosp.estado, novoEstadoHosp);
        break;

        case 11:
            printf("\n Digite o novo país do hóspede: ");
            fgets(novoPaisHosp, sizeof(novoPaisHosp), stdin);
            strcpy(hosp[cod].enderHosp.pais, novoPaisHosp);
        break;
    }
}

void ModificarDadosCat(int z, int x, struct CategoriaAcomodacao *y){

    int i, cod, op, codMod, op2, valDiaCat, quantCri, quantAdult;
    char pesqDescCat[50], novoDescCat[50];

    printf("\n Digite a descrição da categoria de acomodação que deseja pesquisar: ");
    fgets(pesqDescCat, sizeof(pesqDescCat), stdin);

    pesqDescCat[strcspn(pesqDescCat, "\n")] = 0;

    for(i=0; i<x; i++){
        if(strcmp(y[i].descricaoCat, pesqDescCat) == 0){
            cod = i;
        }
    }

    switch(z){
        case 1:
            printf("\n Informe o novo código da categoria de acomodação: ");
            scanf("%d", &codMod);
            setbuf(stdin, NULL);
            y[cod].codigoCategoriaAcomod = codMod;
        break;

        case 2:
            printf("\n Informe a nova descrição da categoria de acomodação: ");
            fgets(novoDescCat, sizeof(novoDescCat), stdin);
            strcpy(y[cod].descricaoCat, novoDescCat);
        break;

        case 3:
            printf("\n Informe o valor da diária da categoria de acomodação: ");
            scanf("%d", &valDiaCat);
            setbuf(stdin, NULL);
            y[cod].valorDiaria = valDiaCat;
        break;

        case 4:
            printf("\n Informe a quantidade de crianças que categoria de acomodação comporta: ");
            scanf("%d", &quantCri);
            setbuf(stdin, NULL);
            y[cod].QuantCriancas = quantCri;
        break;

        case 5:
            printf("\n Informe a quantidade de adultos que a categoria de acomodação comporta: ");
            scanf("%d", &quantAdult);
            y[cod].QuantCriancas = quantCri;
            setbuf(stdin, NULL);
        break;

        y[cod].capacidadeAcomod = y[cod].QuantCriancas + y[cod].QuantAdultos;
    }
}

void ModificarDadosAcomod(int z, int x, struct Acomodacoes *y){
    int pesqCodAcomod, cod, codMod, op2;
    char novoDescAcomod[50], novoFacAcomod[50], novoCatAcomod[50];

    printf("\n Digite o código da acomodação que deseja modificar: ");
    scanf("%d", &pesqCodAcomod);


    for(int i=0; i<x; i++){
        if(y[i].codigoAcomod == pesqCodAcomod){
            cod = i;
        }
    }

    switch(z){
        case 1:
            printf("\n Informe o novo código da acomodação: ");
            scanf("%d", &codMod);
            y[cod].codigoAcomod = codMod;break;
        break;

        case 2:
            printf("\n Informe a nova descrição da acomodação: ");
            fgets(novoDescAcomod, sizeof(novoDescAcomod), stdin);
            strcpy(y[cod].descricaoAcomod, novoDescAcomod);
        break;

        case 3:
            printf("\n Informe as novas facilidades da acomodação: ");
            fgets(novoFacAcomod, sizeof(novoFacAcomod), stdin);
            strcpy(y[cod].facilidades, novoFacAcomod);
        break;

        case 4:
            printf("\n Informe a nova categoria da acomodação: ");
            fgets(novoCatAcomod, sizeof(novoCatAcomod), stdin);
            strcpy(y[cod].categoria.descricaoCat, novoCatAcomod);
        break;


    }
}

void ModificarDadosProd(int z, int x, struct ProdutosHospedes *y){
    int codProd, estProd, cod;
    int estMin, preCusto, preVenda, codMod, op2;
    char pesDescProd[50], novoDescProd[50];

    printf("\n Digite a descrição do produto que deseja modificar: ");
    fgets(pesDescProd, sizeof(pesDescProd), stdin);

    pesDescProd[strcspn(pesDescProd, "\n")] = 0;

    for(int i=0; i<x; i++){
        if(strcmp(y[i].descricao, pesDescProd) == 0){
            cod = i;
        }
    }

    switch(z){
        case 1:
            printf("\n Informe o novo código do produto: ");
            scanf("%d", &codProd);
            setbuf(stdin, NULL);
            y[cod].codigoProduto = codMod;
        break;

        case 2:
            printf("\n Informe a nova descrição do produto: ");
            fgets(novoDescProd, sizeof(novoDescProd), stdin);
            strcpy(y[cod].descricao, novoDescProd);
        break;

        case 3:
            printf("\n Informe o novo estoque do produto: ");
            scanf("%d", &estProd);
            setbuf(stdin, NULL);
            y[cod].estoque = estProd;
        break;

        case 4:
            printf("\n Informe o novo estoque mínimo do produto: ");
            scanf("%d", &estMin);
            setbuf(stdin, NULL);
            y[cod].estoqueMin = estMin;
        break;

        case 5:
            printf("\n Informe o novo preço de custo do produto: ");
            scanf("%d", &preCusto);
            setbuf(stdin, NULL);
            y[cod].precoCusto = preCusto;
        break;

        case 6:
            printf("\n Informe o novo preço de venda do do produto: ");
            scanf("%d", &preVenda);
            setbuf(stdin, NULL);
            y[cod].precoVenda = preVenda;
        break;

        printf("\n 1. Modificar outro dado do produto");
        printf("\n 2. Sair");
        printf("\n Digite a opção desejada");
        scanf("%d", &op2);
        setbuf(stdin, NULL);
    }
}

void ModificarDadosFornec(int z, int x, struct Fornecedores *y){
    int cod, novoCodFornec;
    char pesqNomeForcec[50];
    char novoNomeFornec[50], novoRazaoFornec[50], novoInscriFornec[50], novoCnpjFornec[50];
    char novoTelFornec[50], novoEmailFornec[50], novoNumFornec[50], novoRuaFornec[50];
    char novoBairroFornec[50], novoCidadeFornec[50], novoEstadoFornec[50], novoPaisFornec[50];

    printf("\n Digite o nome do fornecedor que deseja modificar: ");
    fgets(pesqNomeForcec, sizeof(pesqNomeForcec), stdin);

    pesqNomeForcec[strcspn(pesqNomeForcec, "\n")] = 0;

    for(int i=0; i<x; i++){
        if(strcmp(y[i].nomeFornec, pesqNomeForcec) == 0){
            cod = i;
        }
    }

    switch(z){
        case 1:
            printf("Informe o novo código do fornecedor: ");
            scanf("%d", &novoCodFornec);
            y[cod].codigoFornec = novoCodFornec;
        break;

        case 2:
            printf("Informe o novo nome do fornecedor");
            fgets(novoNomeFornec, sizeof(novoNomeFornec), stdin);
            strcpy(y[cod].nomeFornec, novoNomeFornec);
        break;

        case 3:
            printf("Informe a nova razão social do fornecedor");
            fgets(novoRazaoFornec, sizeof(novoRazaoFornec), stdin);
            strcpy(y[cod].razaoSocialFornec, novoRazaoFornec);
        break;

        case 4:
            printf("Informe a nova inscrição estadual do fornecedor");
            fgets(novoInscriFornec, sizeof(novoInscriFornec), stdin);
            strcpy(y[cod].inscricaoEstFornec, novoInscriFornec);
        break;

        case 5:
            printf("Informe o novo CNPJ do fornecedor");
            fgets(novoCnpjFornec, sizeof(novoCnpjFornec), stdin);
            strcpy(y[cod].cnpj, novoCnpjFornec);
        break;

        case 6:
            printf("Informe o novo telefone do fornecedor");
            fgets(novoTelFornec, sizeof(novoTelFornec), stdin);
            strcpy(y[cod].telefoneFornec, novoTelFornec);
        break;

        case 7:
            printf("Informe o novo email do fornecedor");
            fgets(novoEmailFornec, sizeof(novoEmailFornec), stdin);
            strcpy(y[cod].email, novoEmailFornec);
        break;

        case 8:
            printf("Informe o novo número do fornecedor");
            fgets(novoNumFornec, sizeof(novoNumFornec), stdin);
            strcpy(y[cod].enderFornec.numFornec, novoNumFornec);
        break;

        case 9:
            printf("Informe a nova rua do fornecedor");
            fgets(novoRuaFornec, sizeof(novoRuaFornec), stdin);
            strcpy(y[cod].enderFornec.ruaFornec, novoRuaFornec);
        break;

        case 10:
            printf("Informe o novo bairro do fornecedor");
            fgets(novoBairroFornec, sizeof(novoBairroFornec), stdin);
            strcpy(y[cod].enderFornec.bairroFornec, novoBairroFornec);
        break;

        case 11:
            printf("Informe o nova cidade do fornecedor");
            fgets(novoCidadeFornec, sizeof(novoCidadeFornec), stdin);
            strcpy(y[cod].enderFornec.cidadeFornec, novoCidadeFornec);
        break;

        case 12:
            printf("Informe a novo estado do fornecedor");
            fgets(novoEstadoFornec, sizeof(novoEstadoFornec), stdin);
            strcpy(y[cod].enderFornec.estadoFornec, novoEstadoFornec);
        break;

        case 13:
            printf("Informe novo país do fornecedor");
            fgets(novoPaisFornec, sizeof(novoPaisFornec), stdin);
            strcpy(y[cod].enderFornec.paisFornec, novoPaisFornec);
        break;
    }
}

void ModificarDadosOpe(int z, int x, struct OperadoresSistema *y){
    int cod, novoCodOpe;
    char pesqNomeOpe[50], novoNomeOpe[50], novoUsuario[50], novoSenha[50], novoPermissao[50];

    printf("\n Digite o nome do operador que deseja modificar: ");
    fgets(pesqNomeOpe, sizeof(pesqNomeOpe), stdin);

    pesqNomeOpe[strcspn(pesqNomeOpe, "\n")] = 0;

    for(int i=0; i<x; i++){
        if(strcmp(y[i].nomeOpe, pesqNomeOpe) == 0){
            cod = i;
        }
    }
    switch(z){
        case 1:
            printf("Digite o novo código do operador: ");
            scanf("%d", &novoCodOpe);
            setbuf(stdin, NULL);
            y[cod].codigoOpe = novoCodOpe;
        break;

        case 2:
            printf("Digite o novo nome do operador");
            fgets(novoNomeOpe, sizeof(novoNomeOpe), stdin);
            strcpy(y[cod].nomeOpe, novoNomeOpe);
        break;

        case 3:
            printf("Digite o novo nome do operador");
            fgets(novoUsuario, sizeof(novoUsuario), stdin);
            strcpy(y[cod].usuario, novoUsuario);
        break;

        case 4:
            printf("Digite a nova senha do operador");
            fgets(novoSenha, sizeof(novoSenha), stdin);
            strcpy(y[cod].senha, novoSenha);
        break;

        case 5:
            printf("Digite a nova permissão de acesso do operador");
            fgets(novoPermissao, sizeof(novoPermissao), stdin);
            strcpy(y[cod].permissoesAcess, novoPermissao);
        break;
    }
}

int ExcluirDadosHospedes(int x, struct Hospede *y){
    int i;

    int codExc;
    char pesqNomeHosp[50];

    printf("\n Informe o nome do hóspede que deseja excluir: ");
    fgets(pesqNomeHosp, sizeof(pesqNomeHosp), stdin);

    pesqNomeHosp[strcspn(pesqNomeHosp, "\n")] = 0;

    for(i=0; i<x; i++){
        if(strcmp(pesqNomeHosp, y[i].nomeHospede) == 0){
            codExc = i;
        }
    }
    while(codExc < x){
        y[codExc] = y[codExc+1];
        codExc++;
    }

    for(i=0; i<x-1; i++){
        printf("%s", y[i].nomeHospede);
    }
    x--;

    return x;
}

int ExcluirDadosCat(int x, struct CategoriaAcomodacao *y){

    int i, codExc;

    char pesqDescCat[50];

    printf("\nInforme a categoria de acomodação que deseja excluir:");
    fgets(pesqDescCat, sizeof(pesqDescCat), stdin);

    pesqDescCat[strcspn(pesqDescCat, "\n")] = 0;

    for(i=0; i<x; i++){
        if(strcmp(pesqDescCat, y[i].descricaoCat) == 0){
            codExc = i;
        }
    }
    while(codExc < x){
        y[codExc] = y[codExc+1];
        codExc++;
    }

    x--;

    return x;
}

int ExcluirDadosAcomod(int x, struct Acomodacoes *y){
    int i, codExc;

    char pesqExcAcomod[50];

    printf("\nInforme o código da acomodação que deseja excluir: ");
    fgets(pesqExcAcomod, sizeof(pesqExcAcomod), stdin);

    pesqExcAcomod[strcspn(pesqExcAcomod, "\n")] = 0;

    for(i=0; i<x; i++){
        if(strcmp(pesqExcAcomod, y[i].descricaoAcomod) == 0){
            codExc = i;
        }
    }
    while(codExc < x){
        y[codExc] = y[codExc+1];
        codExc++;
    }

    x--;

    return x;
}

int ExcluirDadosProd(int x, struct ProdutosHospedes *y){
    int i, codExc;

    char pesqExcProd[50];

    printf("\nInforme a descrição do produto que deseja excluir:");
    fgets(pesqExcProd, sizeof(pesqExcProd), stdin);

    pesqExcProd[strcspn(pesqExcProd, "\n")] = 0;

    for(i=0; i<x; i++){
        if(strcmp(pesqExcProd, y[i].descricao) == 0){
            codExc = i;
        }
    }
    while(codExc < x){
        y[codExc] = y[codExc+1];
        codExc++;
    }

    x--;

    return x;
}

int ExcluirDadosFornec(int x, struct Fornecedores *y){
    int i, codExc;

        char pesqExcFornec[50];

        printf("\n Informe o nome do hóspede que deseja excluir:");
        fgets(pesqExcFornec, sizeof(pesqExcFornec), stdin);

        pesqExcFornec[strcspn(pesqExcFornec, "\n")] = 0;

        for(i=0; i<x; i++){
            if(strcmp(pesqExcFornec, y[i].nomeFornec) == 0){
                codExc = i;
            }
        }
        while(codExc < x){
            y[codExc] = y[codExc+1];
            codExc++;
        }

        x--;
    return x;
}

int ExcluirDadosOpe(int x, struct OperadoresSistema *y){
    int i, codExc;

        char pesqExcOpe[50];

        printf("\n Informe o nome do operador que deseja excluir:");
        fgets(pesqExcOpe, sizeof(pesqExcOpe), stdin);

        pesqExcOpe[strcspn(pesqExcOpe, "\n")] = 0;

        for(i=0; i<x; i++){
            if(strcmp(pesqExcOpe, y[i].nomeOpe) == 0){
                codExc = i;
            }
        }
        while(codExc < x){
            y[codExc] = y[codExc+1];
            codExc++;
        }

        x--;


    return x;
}

void MostrarDadosHotel(struct Hotel *x){

    printf("\n Nome do Hotel: %s", x->nomeHotel);
    printf("\n Razão Social do Hotel: %s", x->razaoSocialHotel);
    printf("\n Inscrição Estadual Hotel: %s", x->inscriEstadualHotel);
    printf("\n CNPJ do Hotel: %s", x->cnpjHotel);
    printf("\n Email do Hotel: %s", x->emailHotel);
    printf("\n Nome do Responsável pelo Hotel: %s", x->responsavelHotel);
    printf("\n Telefone do Responsável do Hotel: %s", x->telResponsavelHotel);
    printf("\n Hora de Check In do Hotel: %s", x->horaCheckInHotel);
    printf("\n Hora de Check Out do Hotel: %s", x->horaCheckOutHotel);
    printf("\n Margem de lucro do Hotel: R$ %f", x->margemLucroHotel);
    printf("\n Capacidade do Hotel: %d", x->capacidadeHotel);
    printf("\n Tamanho do Estoque do Hotel: %d", x->tamEstoque);
    printf("\n Quantidade de Fornecedores do Hotel: %d", x->quantFornec);
    printf("\n Quantidade de Acomodações do Hotel: %d", x->qtdAcomod);
    printf("\n Endereço do Hotel: ");
    printf("\n Número da Rua do Hotel: %s", x->ender.numHotel);
    printf("\n Rua do Hotel: %s", x->ender.ruaHotel);
    printf("\n Bairro do Hotel: %s", x->ender.bairroHotel);
    printf("\n Cidade do Hotel: %s", x->ender.cidadeHotel);
    printf("\n Estado do Hotel: %s\n", x->ender.estadoHotel);

    getchar();
}

void MostrarDadosHospedes(int x, struct Hospede *y){
    int op, cod = -1, i;
    char pesqNomeHosp[50];

    printf("\n 1. Pesquisa por nome do hóspede: ");
    printf("\n 2. Mostrar todos os hóspedes: ");
    printf("\n Digite a opção desejada: ");
    scanf("%d", &op);
    setbuf(stdin, NULL);

    if(x == 0){
        printf("\n Nenhum hóspede cadastrado");
    }else{
        if(op == 1){

            printf("\n Informe o nome que do hóspede que deseja pesquisar:");
            fgets(pesqNomeHosp, sizeof(pesqNomeHosp), stdin);

            pesqNomeHosp[strcspn(pesqNomeHosp, "\n")] = 0;

            for(i=0; i<x; i++){
                if(strcmp(pesqNomeHosp, y[i].nomeHospede) == 0){
                    cod = i;
                }
            }
            if(cod == -1){
                printf("Nenhum hóspede encontrado");
            }else {
                printf("\n Código do Hóspede: %d", y[cod].codigoHospede);
                printf("\n Nome do Hóspede: %s", y[cod].nomeHospede);
                printf("\n CPF do Hóspede: %s", y[cod].cpf);
                printf("\n Telefone do Hóspede: %s", y[cod].telHospede);
                printf("\n Email do Hóspede: %s", y[cod].emailHospede);
                printf("\n Sexo do Hóspede: %s", y[cod].sexo);
                printf("\n Estado Civil do Hóspede: %s", y[cod].estCivHospede);
                printf("\n Data de Nascimento do Hóspede: %s", y[cod].dataNasci);
                printf("\n Endereço do Hóspede: %s", y[cod].enderHosp.num);
                printf("\n Rua do Hóspede: %s", y[cod].enderHosp.rua);
                printf("\n Bairro do Hóspede: %s", y[cod].enderHosp.bairro);
                printf("\n Cidade do Hóspede: %s", y[cod].enderHosp.cidade);
                printf("\n Estado do Hóspede: %s", y[cod].enderHosp.estado);
                printf("\n País do Hóspede: %s", y[cod].enderHosp.pais);
            }
        } else if(op == 2){
            for(i=0; i<x; i++){
                printf("\n Código do Hóspede: %d", y[i].codigoHospede);
                printf("\n Nome do Hóspede: %s", y[i].nomeHospede);
                printf("\n CPF do Hóspede: %s", y[i].cpf);
                printf("\n Telefone do Hóspede: %s", y[i].telHospede);
                printf("\n Email do Hóspede: %s", y[i].emailHospede);
                printf("\n Sexo do Hóspede: %s", y[i].sexo);
                printf("\n Estado Civil do Hóspede: %s", y[i].estCivHospede);
                printf("\n Data de Nascimento do Hóspede: %s", y[i].dataNasci);
                printf("\n Endereço do Hóspede: %s", y[i].enderHosp.num);
                printf("\n Rua do Hóspede: %s", y[i].enderHosp.rua);
                printf("\n Bairro do Hóspede: %s", y[i].enderHosp.bairro);
                printf("\n Cidade do Hóspede: %s", y[i].enderHosp.cidade);
                printf("\n Estado do Hóspede: %s", y[i].enderHosp.estado);
                printf("\n País do Hóspede: %s\n", y[i].enderHosp.pais);
            }
        } else{
            printf("\n Opção inválida");
        }
    }
}

void MostrarDadosCat(int x, struct CategoriaAcomodacao *y){
    int op, cod = -1, i;
    char pesqDescCat[50];

    printf("\n 1. Pesquisar por descrição da categoria de acomodação: ");
    printf("\n 2. Mostrar todos as categorias de acomodação: ");
    printf("\n Digite a opção desejada: ");
    scanf("%d", &op);
    setbuf(stdin, NULL);

    if(x == 0){
        printf("\n Nenhuma categoria de acomodoção cadastrada");
    } else {
        if(op == 1){
            printf("\n Informe o nome que do hóspede que deseja pesquisar:");
            fgets(pesqDescCat, sizeof(pesqDescCat), stdin);

            pesqDescCat[strcspn(pesqDescCat, "\n")] = 0;

            for(i=0; i<x; i++){
                if(strcmp(pesqDescCat, y[i].descricaoCat) == 0){
                    cod = i;
                }
            }
            if(cod = -1){
                printf("\n Categoria de acomodação não encontrada");
            }else {
                printf("\n Código da categoria de acomodação: %d", y[cod].codigoCategoriaAcomod);
                printf("\n Descrição da categoria de acomodação: %s", y[cod].descricaoCat);
                printf(" Valor da diária da categoria de acomodação: %f", y[cod].valorDiaria);
                printf("\n Quantidade de crianças que a categoria de acomodação comporta: %d", y[cod].QuantCriancas);
                printf("\n Quantidade de crianças que a categoria de acomodação comporta: %d", y[cod].QuantCriancas);
                printf("\n Capacidade da categoria de acomodação: %d\n", y[cod].capacidadeAcomod);
            }
        }else if(op == 2){
            for(i=0; i<x; i++){
                printf("\n Código da categoria de acomodação: %d", y[i].codigoCategoriaAcomod);
                printf("\n Descrição da categoria de acomodação: %s", y[i].descricaoCat);
                printf(" Valor da diária da categoria de acomodação: %5.2f", y[i].valorDiaria);
                printf("\n Quantidade de crianças que a categoria de acomodação comporta: %d", y[i].QuantCriancas);
                printf("\n Quantidade de crianças que a categoria de acomodação comporta: %d", y[i].QuantCriancas);
            }
        }else {
            printf("\n Opção inválida");
        }

        getchar();
    }
}

void MostrarDadosAcomod(int x, struct Acomodacoes *y){
    int op, cod = -1, i;
    char pesqDescAcomod[50];

    printf("\n 1. Pesquisar pela descrição da acomodação: ");
    printf("\n 2. Mostrar todas as acomodações: ");
    printf("\n Digite a opção desejada: ");
    scanf("%d", &op);
    setbuf(stdin, NULL);

    if(x == 0){
        printf("\n Nenhuma acomodoção cadastrada");
    }else {
        if(op == 1){
            printf("\n Informe o nome que do hóspede que deseja pesquisar:");
            fgets(pesqDescAcomod, sizeof(pesqDescAcomod), stdin);

            pesqDescAcomod[strcspn(pesqDescAcomod, "\n")] = 0;

            for(i=0; i<=x; i++){
                if(strcmp(pesqDescAcomod, y[i].descricaoAcomod) == 0){
                    cod = i;
                }
            }

            if(cod == -1){
                printf("Nenhum acomodação encontrada");
            } else{
                printf("\n Código da acomodação: %d", y[cod].codigoAcomod);
                printf("\n Descrição da acomodação: %s", y[cod].descricaoAcomod);
                printf(" Facilidades da acomodação: %s", y[cod].facilidades);
                printf(" Categoria da acomodação: %s\n", y[cod].categoria.descricaoCat);
            }
        }else if(op == 2){
            for(i=0; i<x; i++){
            printf("\n Código da acomodação: %d", y[i].codigoAcomod);
            printf("\n Descrição da acomodação: %s", y[i].descricaoAcomod);
            printf(" Facilidades da acomodação: %s", y[i].facilidades);
            printf(" Categoria da acomodação: %s\n", y[i].categoria.descricaoCat);
            }
        } else{
            printf("\n Opção inválida");
        }
    }
}

void MostrarDadosProd(int x, struct ProdutosHospedes *y){
    int op, cod = -1, i;
    char pesqDescProd[50];

    printf("\n 1. Pesquisar pela descrição do produto: ");
    printf("\n 2. Mostrar todos os produtos: ");
    printf("\n Digite a opção desejada: ");
    scanf("%d", &op);
    setbuf(stdin, NULL);

    if(x == 0){
        printf("\n Nenhum produto cadastrado");
    }else {
        if(op == 1){
            printf("\n Informe o nome que do hóspede que deseja pesquisar:");
            fgets(pesqDescProd, sizeof(pesqDescProd), stdin);

            pesqDescProd[strcspn(pesqDescProd, "\n")] = 0;

            for(i=0; i<x; i++){
                if(strcmp(pesqDescProd, y[i].descricao) == 0){
                    cod = i;
                }
            }
            if(cod = -1){
                printf("\n Nenhum produto encontrado");
            } else {
                printf("\n Código do produto: %d", y[cod].codigoProduto);
                printf("\n Descrição do produto: %s", y[cod].descricao);
                printf("\n Estoque do produto: %d", y[cod].estoque);
                printf("\n Estoque mínimo do produto: %d", y[cod].estoqueMin);
                printf("\n Preço de custo do produto: %d", y[cod].precoCusto);
                printf("\n Preço de venda do produto: %f\n", y[cod].precoVenda);
            }
        } else if(op == 2){
            for(i=0; i<x; i++){
                printf("\n Código do produto: %d", y[i].codigoProduto);
                printf("\n Descrição do produto: %s", y[i].descricao);
                printf("\n Estoque do produto: %d", y[i].estoque);
                printf("\n Estoque mínimo do produto: %d", y[i].estoqueMin);
                printf("\n Preço de custo do produto: %d", y[i].precoCusto);
                printf("\n Preço de venda do produto: %f\n", y[i].precoVenda);
            }
        }else {
            printf("\n Opção inválida");
        }
        getchar();
    }
}

void MostrarDadosFornec(int x, struct Fornecedores *y){
    int op, cod = 1, i;
    char pesqNomeFornec[50];

    printf("\n 1. Pesquisar pelo nome do fornecedor: ");
    printf("\n 2. Mostrar todos os Fornecedores: ");
    printf("\n Digite a opção desejada: ");
    scanf("%d", &op);
    setbuf(stdin, NULL);

    if(x == 0){
        printf("\n Nenhum fornecedor cadastrado");
    } else {
        if(op == 1){

        printf("\n Informe o nome que do fornecedor que deseja pesquisar:");
        fgets(pesqNomeFornec, sizeof(pesqNomeFornec), stdin);

        pesqNomeFornec[strcspn(pesqNomeFornec, "\n")] = 0;

        for(i=0; i<x; i++){
            if(strcmp(pesqNomeFornec, y[i].nomeFornec) == 0){
                cod = i;
            }
        }
        if(cod = -1){
            printf("\n Nenhum fornecedor encontrado");
        }else {
            printf("\n Código do fornecedor: %d", y[cod].codigoFornec);
            printf("\n Nome do fornecedor: %s", y[cod].nomeFornec);
            printf("\n Razão social do fornecedor: %s", y[cod].razaoSocialFornec);
            printf("\n Inscrição estadual do fornecedor: %s", y[cod].inscricaoEstFornec);
            printf("\n CNPJ do fornecedor: %s", y[cod].cnpj);
            printf("\n Telefone do fornecedor: %s", y[cod].telefoneFornec);
            printf("\n Email do fornecedor: %s", y[cod].email);
            printf("\nEndereço do Fornecedor\n ");
            printf("\n Número do fornecedor: %s", y[cod].enderFornec.numFornec);
            printf("\n Rua do fornecedor: %s", y[cod].enderFornec.ruaFornec);
            printf("\n Bairro do fornecedor: %s", y[cod].enderFornec.bairroFornec);
            printf("\n Cidadea do fornecedor: %s", y[cod].enderFornec.cidadeFornec);
            printf("\n Estado do fornecedor: %s", y[cod].enderFornec.estadoFornec);
            printf("\n País do fornecedor: %s\n", y[cod].enderFornec.paisFornec);

            getchar();
        }
        }else if(op == 2){
            for(i=0; i<x; i++){
                printf("\n Código do fornecedor: %d", y[i].codigoFornec);
                printf("\n Nome do fornecedor: %s", y[i].nomeFornec);
                printf("\n Razão social do fornecedor: %s", y[i].razaoSocialFornec);
                printf("\n Inscrição estadual do fornecedor: %s", y[i].inscricaoEstFornec);
                printf("\n CNPJ do fornecedor: %s", y[i].cnpj);
                printf("\n Telefone do fornecedor: %s", y[i].telefoneFornec);
                printf("\n Email do fornecedor: %s", y[i].email);
                printf("\nEndereço do Fornecedor:\n ");
                printf("\n Número do fornecedor: %s", y[i].enderFornec.numFornec);
                printf("\n Rua do fornecedor: %s", y[i].enderFornec.ruaFornec);
                printf("\n Bairro do fornecedor: %s", y[i].enderFornec.bairroFornec);
                printf("\n Cidadea do fornecedor: %s", y[i].enderFornec.cidadeFornec);
                printf("\n Estado do fornecedor: %s", y[i].enderFornec.estadoFornec);
                printf("\n País do fornecedor: %s\n", y[i].enderFornec.paisFornec);
            }
        }else {
            printf("\n Opção inválida");
        }
    }
}

void MostrarDadosOpe(int x, struct OperadoresSistema *y){
    int op, cod = -1, i;
    char pesqNomeOpe[50];

    printf("\n 1. Pesquisar pelo nome do operador: ");
    printf("\n 2. Mostrar todos os operadores: ");
    printf("\n Digite a opção desejada: ");
    scanf("%d", &op);
    setbuf(stdin, NULL);

    if(x == 0){
        printf("\n Nenhum operador cadastrado");
    }else {
        if(op == 1){
            printf("\n Informe o nome que do hóspede que deseja pesquisar:");
            fgets(pesqNomeOpe, sizeof(pesqNomeOpe), stdin);

            pesqNomeOpe[strcspn(pesqNomeOpe, "\n")] = 0;

            for(i=0; i<=x; i++){
                if(strcmp(pesqNomeOpe, y[i].nomeOpe) == 0){
                    cod = i;
                }
            }

            if(cod = -1){
                printf("\n Nenhum operador encontrado");
            }else {
                printf("\n Código do operador: %d", y[cod].codigoOpe);
                printf("\n Nome do operador: %s", y[cod].nomeOpe);
                printf("\n Usúario do operador: %s", y[cod].usuario);
                printf("\n Senha do operador: %s", y[cod].senha);
                printf("\n Permissões de acesso do operador: %s", y[cod].permissoesAcess);
                getchar();

            }
        }else if(op == 2){
            for(i=0; i<=x; i++){
                printf("\n Código do operador: %d", y[i].codigoOpe);
                printf("\n Nome do operador: %s", y[i].nomeOpe);
                printf("\n Usúario do operador: %s", y[i].usuario);
                printf("\n Senha do operador: %s", y[i].senha);
                printf("\n Permissões de acesso do operador: %s", y[i].permissoesAcess);
                getchar();
            }
        }else {
            printf("\n Opção inválida");
        }
    }
}

int VerificarCategoria(int countAc, int countCat, struct Acomodacoes *acomod, struct CategoriaAcomodacao *cat){

        int verifCat = 0, i;

        for(i=0; i<countCat; i++){
            if(strcmp(acomod[countAc].categoria.descricaoCat, cat[i].descricaoCat) == 0){
                verifCat = 1;
            }
        }


return verifCat;
}
