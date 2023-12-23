#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "GestaoDeDados.h"
#include "Reservas.h"
#include "Arquivos.h"
#include "Transacoes.h"
#include "Feedback.h"
#include "Importacao_exportacao.h"

void CriarAcomodacao(int x, int totCat, acomodacoes *acomodacao, categoriaAcomod *categoria){//Função responsável pela criação de uma acomodação após a inserção de dados da acomodação
    int i;

    for(i=0; i<totCat; i++){
        if(strcmp(acomodacao[x-1].categoria.descricaoCat, categoria[i].descricaoCat)== 0){
            acomodacao[x-1].categoria.valorDiaria = categoria[i].valorDiaria;
            acomodacao[x-1].categoria.QuantCriancas = categoria[i].QuantCriancas;
            acomodacao[x-1].categoria.QuantAdultos = categoria[i].QuantAdultos;
            acomodacao[x-1].categoria.capacidadeAcomod = categoria[i].capacidadeAcomod;
        }
    }
}

void CriarAcomodacaoArquivos(int x, int totCat, acomodacoes *acomodacao, categoriaAcomod *categoria){ //Função responsável pela criação de uma acomodação após a leitura do arquivo acomodações
    int i, j;

    for(i=0; i<totCat; i++){
        for(j=0; j<x; j++){
            if(strcmp(acomodacao[j].categoria.descricaoCat, categoria[i].descricaoCat)== 0){
                strcpy(acomodacao[j].categoria.descricaoCat, categoria[i].descricaoCat);
                acomodacao[j].categoria.valorDiaria = categoria[i].valorDiaria;
                acomodacao[j].categoria.QuantCriancas = categoria[i].QuantCriancas;
                acomodacao[j].categoria.QuantAdultos = categoria[i].QuantAdultos;
            }
        }
    }

}

int main(int argc, char** argv) {
    
    int opMenu, opCadastro, opMod, opMost, opExc;
    int i, j, op, opHot;
    int opHosp, countHosp=0, op2;
    int opCat, countCat=0, op3, op4;
    int opAc, countAc=0, op5, op6;
    int opProd, countPro=0, totalEstoque=0, op7, op8;
    int opFornec, countFornec=0, op9, op10;
    int opOpe, countOpe=0, op11, op12, verifCat;
    int op13, op14, op15, op16, op17, op18;
    int op19, op20, op21, op22, op23, op24, totRes=0, TipoArq;
    int op25, op26, op27, op28, op29, op30, op31, op32, op33, op34, op35;
    int op36, op37, op38, op39, op40, op41, op42, op43, op44;
    int conta = 0, totContReceb = 0, qtdProdInd = 0;
    int totDiariaAc=0;
    int totPrdFornec=0;
    int totPag = 0, qtdProdComp = 0;
    int freProd=0, impProd=0, totProdComp=0;
    int totContPag = 0;
    int totTran = 0, parc=0, parc2=0;
    int countHot=0; //Contador que verifica se há um hotel cadastrado
    float valEnt=0, valEnt2=0;
    int *verificarRes;
    char pesqNomeHosp[50], sexoHosp[50];
    int codIni, codFin;
    int totRelHosp;
    char numTab[30];
    char facAcomod[50], pesqCatAcomod[30];
    char categoria[50], dataDisp[30];
    char nomeHosp[50];
    int codAcomod;
    verificarRes = calloc(7, sizeof(int));
    int qtdDiaOcup;
    float rendAcomod;
    char dataCont[30];
    
    hotel *hot;
    enderecohotel *enderHot;
    
    hot = malloc(100 * sizeof(hotel));
    enderHot = malloc(100 * sizeof(enderecohotel));
    
    int *pCountHosp = &countHosp;
    int *pCountAc = &countAc;
    int *pCountCat = &countCat;
    int *pCountFornec = &countFornec;
    int *pCountOpe = &countOpe;
    
    int *pTotRes = &totRes;
    int *pTotDiariaAc = &totDiariaAc;
    int *pCont = &conta;
    int *pTotPag = &totPag;
    int *pTotContReceb = &totContReceb;
    int *pProdInd = &qtdProdInd;
    int *pCountPro = &countPro;
    int *pQtdProdComp = &qtdProdComp;
    int *pFreProd = &freProd;
    int *pImpProd = &impProd;
    int *pTotProdComp = &totProdComp;
    int *pTotTran = &totTran;
    int *pTotContPag = &totContPag;
    int *ptotPrdFornec = &totPrdFornec;

    hospede *hosp;

    categoriaAcomod *cat;

    acomodacoes *acomod;

    produtos *prod;

    fornecedores *fornec;

    operadores *ope;

    reservas *reserva;

    diariaAcomod *diariaAc;
    
    contHosp *cont;

    dadosProd *dadosPro;

    itensInd *prodInd;

    contReceber *contReceb;

    itensComp *prodComp;

    caixa *caixaHotel;

    contPag *cont3;

    contProdFornec *contProd;

    contFornec *contFor;
    
    relatHosp *rHosp;
    
    relatAcomod *rAcomod;

    relatRes *rRes;

    relatProd *rProd;

    relatProd *rProdEstMin;

    reserva = (reservas*)malloc(1000 * sizeof(reservas));

    cont = (contHosp*)malloc(1000 * sizeof(contHosp));

    diariaAc = (diariaAcomod*)malloc(1000 * sizeof(diariaAcomod));
    
    cont[0].qtdPrdsComp = 0;

    dadosPro = (dadosProd*)malloc(100 * sizeof(dadosProd));

    contReceb = (contReceber*)malloc(100 * sizeof(contReceber));

    prodInd = (itensInd*)malloc(100 * sizeof(itensInd));

    prodComp = (itensComp*)malloc(100 * sizeof(itensComp));

    caixaHotel = (caixa*)malloc(100 * sizeof(caixa));

    cont3 = (contPag*)malloc(100 * sizeof(contPag));

    contFor = (contFornec*)malloc(100 * sizeof(contFornec));
    
    rHosp = (relatHosp*)malloc(100 * sizeof(relatHosp));
    
    rAcomod = (relatAcomod*)malloc(100 * sizeof(relatAcomod));

    rRes = (relatRes*)malloc(100 * sizeof(relatRes));

    rProd = (relatProd*)malloc(100 * sizeof(relatProd));

    rProdEstMin = (relatProd*)malloc(100 * sizeof(relatProd));

    printf("--------------------- Sistema de Hotel ---------------------\n");

    printf("\nDeseja salvar os dados em qual tipo de arquivo(1-Txt 2-Bin)?:");
    scanf("%d",&TipoArq);

    do{
        printf("\n Menu de Opções.");
        printf("\n 1. Cadastrar Dados");
        printf("\n 2. Modificar Dados");
        printf("\n 3. Excluir Dados");
        printf("\n 4. Mostrar Dados");
        printf("\n 5. Agendar Reservas");
        printf("\n 6. Cancelar Reservas");
        printf("\n 7. Mostrar Reservas Agendadas");
        printf("\n 8. Ler Dados em Arquivo Texto");
        printf("\n 9. Ler Dados em Arquivo Binário");
        printf("\n 10. Transações");
        printf("\n 11. Imprimir Relatórios");
        printf("\n 12. Exportar Dados");
        printf("\n 13. Importar Dados");
        printf("\n 14. Sair");
        printf("\n Digite uma opção: ");
        scanf("%d", &opMenu);
        setbuf(stdin, NULL);

        if(opMenu >= 1 && opMenu <=14){
            switch (opMenu){
                case 1:
                    printf("\n Cadastrar Dados");
                    printf("\n 1. Cadastrar dados do hotel");
                    printf("\n 2. Cadastrar dados de hóspedes");
                    printf("\n 3. Cadastrar dados de categorias de acomodação");
                    printf("\n 4. Cadastrar dados de acomodações");
                    printf("\n 5. Cadastrar dados de produtos para os hóspedes");
                    printf("\n 6. Cadastrar dados de Fornecedores");
                    printf("\n 7. Cadastrar dados de operadores do sistema");

                    printf("\n Digite uma opção de cadastro: ");
                    scanf("%d", &opCadastro);
                    setbuf(stdin, NULL);

                    if(opCadastro >= 1 && opCadastro <=7){
                        switch(opCadastro){

                        case 1: //Cadastramento do Hotel
                            
                            printf("\n Insira os Dados do Hotel");
                            printf("\n Informe o nome do hotel: ");
                            fgets(hot->nomeHotel, sizeof(hot->nomeHotel), stdin);
                            printf(" Informe a razão social do hotel: ");
                            fgets(hot->razaoSocialHotel, sizeof(hot->razaoSocialHotel), stdin);
                            printf(" Informe a inscrição estadual do hotel: ");
                            fgets(hot->inscriEstadualHotel, sizeof(hot->inscriEstadualHotel), stdin);
                            printf(" Informe o CNPJ do hotel: ");
                            fgets(hot->cnpjHotel, sizeof(hot->cnpjHotel), stdin);
                            printf(" Informe o email do hotel: ");
                            fgets(hot->emailHotel, sizeof(hot->emailHotel), stdin);
                            printf(" Informe o telefone do hotel: ");
                            fgets(hot->telefoneHotel, sizeof(hot->emailHotel), stdin);
                            printf(" Informe o nome do responsável do hotel: ");
                            fgets(hot->responsavelHotel, sizeof(hot->responsavelHotel), stdin);
                            printf(" Informe o telefone do resposável do hotel: ");
                            fgets(hot->telResponsavelHotel, sizeof(hot->telResponsavelHotel), stdin);
                            printf(" Informe o horário de check-in do hotel: ");
                            fgets(hot->horaCheckInHotel, sizeof(hot->horaCheckInHotel), stdin);
                            printf(" Informe o horário de check-out do hotel: ");
                            fgets(hot->horaCheckOutHotel, sizeof(hot->horaCheckOutHotel), stdin);
                            printf(" Informe a margem de lucro do hotel: ");
                            scanf("%li", &hot->margemLucroHotel);
                            printf(" Informe a capacidade do hotel: ");
                            scanf("%d", &hot->capacidadeHotel);
                            printf(" Informe a quantidade de acomodações do hotel: ");
                            scanf("%d", &hot->qtdAcomod);
                            printf(" Informe o tamanho do estoque do hotel: ");
                            scanf("%d", &hot->tamEstoque);
                            printf(" Informe a quantidade de Fornecedores do hotel: ");
                            scanf("%d", &hot->quantFornec);
                            printf(" Informe a quantidade de operadores do sistema do hotel: ");
                            scanf("%d", &hot->quantOpe);
                            setbuf(stdin, NULL);
                            
                            printf("\n Endereço do Hotel: \n");
                            printf(" Informe o número do hotel: ");
                            fgets(hot->ender.numHotel, sizeof(hot->ender.numHotel), stdin);
                            printf(" Informe a rua do hotel: ");
                            fgets(hot->ender.ruaHotel, sizeof(hot->ender.ruaHotel), stdin);
                            printf(" Informe o bairro do hotel: ");
                            fgets(hot->ender.bairroHotel, sizeof(hot->ender.bairroHotel), stdin);
                            printf(" Informe o cidade do hotel: ");
                            fgets(hot->ender.cidadeHotel, sizeof(hot->ender.cidadeHotel), stdin);
                            printf(" Informe o estado do hotel: ");
                            fgets(hot->ender.estadoHotel, sizeof(hot->ender.estadoHotel), stdin);
                            
                            hot->nomeHotel[strcspn(hot->nomeHotel, "\n")] = 0;
                            hot->razaoSocialHotel[strcspn(hot->razaoSocialHotel, "\n")] = 0;
                            hot->inscriEstadualHotel[strcspn(hot->inscriEstadualHotel, "\n")] = 0;
                            hot->cnpjHotel[strcspn(hot->cnpjHotel, "\n")] = 0;
                            hot->emailHotel[strcspn(hot->emailHotel, "\n")] = 0;
                            hot->telefoneHotel[strcspn(hot->telefoneHotel, "\n")] = 0;
                            hot->responsavelHotel[strcspn(hot->responsavelHotel, "\n")] = 0;
                            hot->telResponsavelHotel[strcspn(hot->telResponsavelHotel, "\n")] = 0;
                            hot->horaCheckInHotel[strcspn(hot->horaCheckInHotel, "\n")] = 0;
                            hot->horaCheckOutHotel[strcspn(hot->horaCheckOutHotel, "\n")] = 0;
                            hot->ender.numHotel[strcspn(hot->ender.numHotel, "\n")] = 0;
                            hot->ender.ruaHotel[strcspn(hot->ender.ruaHotel, "\n")] = 0;
                            hot->ender.bairroHotel[strcspn(hot->ender.bairroHotel, "\n")] = 0;
                            hot->ender.cidadeHotel[strcspn(hot->ender.cidadeHotel, "\n")] = 0;
                            hot->ender.estadoHotel[strcspn(hot->ender.estadoHotel, "\n")] = 0;
                            
                            hosp = (hospede*)malloc(hot->capacidadeHotel * sizeof(hospede));

                            cat = (categoriaAcomod*)malloc(100 * sizeof(categoriaAcomod));

                            acomod = (acomodacoes*)malloc(hot->qtdAcomod * sizeof(acomodacoes));

                            prod = (produtos*)malloc(hot->tamEstoque * sizeof(produtos));

                            fornec = (fornecedores*)malloc(hot->quantFornec * sizeof(fornecedores));

                            ope = (operadores*)malloc(hot->quantOpe * sizeof(operadores));

                            reserva = (reservas*)malloc(hot->capacidadeHotel * sizeof(reservas));

                            cont = (contHosp*)malloc(hot->capacidadeHotel * sizeof(contHosp));
                            
                            GravarDadosHotel(hot, TipoArq);

                            countHot = 1;

                        break;

                        case 2: //Cadastramento de Hóspedes
                            if(countHot == 1){
                                do{
                                    printf("\n Cadastro de Hóspedes \n");

                                    printf("\n Informe o código do hóspede: ");
                                    scanf("%d", &hosp[countHosp].codigoHospede);
                                    setbuf(stdin, NULL);
                                    printf(" Informe o nome do hóspede: ");
                                    fgets(hosp[countHosp].nomeHospede, sizeof(hosp[countHosp].nomeHospede), stdin);
                                    printf(" Informe o cpf do hóspede: ");
                                    fgets(hosp[countHosp].cpf, sizeof(hosp[countHosp].cpf), stdin);
                                    printf(" Informe telefone do hóspede: ");
                                    fgets(hosp[countHosp].telHospede, sizeof(hosp[countHosp].telHospede), stdin);
                                    printf(" Informe email do hóspede: ");
                                    fgets(hosp[countHosp].emailHospede, sizeof(hosp[countHosp].emailHospede), stdin);
                                    printf(" Informe sexo do hóspede: ");
                                    fgets(hosp[countHosp].sexo, sizeof(hosp[countHosp].sexo), stdin);
                                    printf(" Informe estado civil do hóspede: ");
                                    fgets(hosp[countHosp].estCivHospede, sizeof(hosp[countHosp].estCivHospede), stdin);
                                    printf(" Informe a data de nascimento do hóspede: ");
                                    fgets(hosp[countHosp].dataNasci, sizeof(hosp[countHosp].dataNasci), stdin);
                                    printf("\n Endereço do Hóspede \n");
                                    printf("\n Informe o número do hóspede: ");
                                    fgets(hosp[countHosp].enderHosp.num, sizeof(hosp[countHosp].enderHosp.num), stdin);
                                    printf(" Informe a rua do hóspede: ");
                                    fgets(hosp[countHosp].enderHosp.rua, sizeof(hosp[countHosp].enderHosp.rua), stdin);
                                    printf(" Informe o bairro do hóspede: ");
                                    fgets(hosp[countHosp].enderHosp.bairro, sizeof(hosp[countHosp].enderHosp.bairro), stdin);
                                    printf(" Informe a cidade do hóspede: ");
                                    fgets(hosp[countHosp].enderHosp.cidade, sizeof(hosp[countHosp].enderHosp.cidade), stdin);
                                    printf(" Informe o estado do hóspede: ");
                                    fgets(hosp[countHosp].enderHosp.estado, sizeof(hosp[countHosp].enderHosp.estado), stdin);
                                    printf(" Informe o país do hóspede: ");
                                    fgets(hosp[countHosp].enderHosp.pais, sizeof(hosp[countHosp].enderHosp.pais), stdin);

                                    hosp[countHosp].nomeHospede[strcspn(hosp[countHosp].nomeHospede, "\n")] = 0;
                                    hosp[countHosp].cpf[strcspn(hosp[countHosp].cpf, "\n")] = 0;
                                    hosp[countHosp].telHospede[strcspn(hosp[countHosp].telHospede, "\n")] = 0;
                                    hosp[countHosp].emailHospede[strcspn(hosp[countHosp].emailHospede, "\n")] = 0;
                                    hosp[countHosp].sexo[strcspn(hosp[countHosp].sexo, "\n")] = 0;
                                    hosp[countHosp].estCivHospede[strcspn(hosp[countHosp].estCivHospede, "\n")] = 0;
                                    hosp[countHosp].dataNasci[strcspn(hosp[countHosp].dataNasci, "\n")] = 0;
                                    hosp[countHosp].enderHosp.num[strcspn(hosp[countHosp].enderHosp.num, "\n")] = 0;
                                    hosp[countHosp].enderHosp.rua[strcspn(hosp[countHosp].enderHosp.rua, "\n")] = 0;
                                    hosp[countHosp].enderHosp.bairro[strcspn(hosp[countHosp].enderHosp.bairro, "\n")] = 0;
                                    hosp[countHosp].enderHosp.cidade[strcspn(hosp[countHosp].enderHosp.cidade, "\n")] = 0;
                                    hosp[countHosp].enderHosp.estado[strcspn(hosp[countHosp].enderHosp.estado, "\n")] = 0;
                                    hosp[countHosp].enderHosp.pais[strcspn(hosp[countHosp].enderHosp.pais, "\n")] = 0;

                                    GravarDadosHospedes(countHosp, hosp, TipoArq);

                                    countHosp++;

                                    printf("\n 1. Cadastrar outro hóspede: ");
                                    printf("\n 2. Sair: ");
                                    printf("\n Digite a opção desejada: ");
                                    scanf("%d", &opHosp);
                                    setbuf(stdin, NULL);
                                } while (opHosp != 2);
                            }else{
                                printf("\n É necessário que os dados do hotel estejam cadastrados\n");
                            }

                        break;

                        case 3: //Cadastramento de Categorias de Acomodoção
                            if(countHot == 1){
                                do{
                                    printf("\n Cadastro de Categorias de Acomodoção ");
                                    printf("\n Insira os dados das categorias de acomodação: \n");

                                    printf("\n Informe o código da categoria de acomodação: ");
                                    scanf("%d", &cat[countCat].codigoCategoriaAcomod);
                                    setbuf(stdin, NULL);
                                    printf(" Informe a descrição da categoria de acomodação: ");
                                    fgets(cat[countCat].descricaoCat, sizeof(cat[countCat].descricaoCat), stdin);
                                    printf(" Informe o valor da diária da categoria de acomodação: ");
                                    scanf("%f", &cat[countCat].valorDiaria);
                                    setbuf(stdin, NULL);
                                    printf(" Informe a quantidade de crianças que"
                                           " a categoria de acomodação comporta: ");
                                    scanf("%d", &cat[countCat].QuantCriancas);
                                    setbuf(stdin, NULL);
                                    printf(" Informe quantidade de adultos que"
                                           " a categoria de acomodação comporta: ");
                                    scanf("%d", &cat[countCat].QuantAdultos);
                                    setbuf(stdin, NULL);

                                    cat[countCat].descricaoCat[strcspn(cat[countCat].descricaoCat, "\n")] = 0;

                                    countCat++;

                                    GravarDadosCategoria(countCat, cat, TipoArq);

                                    printf("\n 1. Cadastrar outra categoria de acomodação: ");
                                    printf("\n 2. Voltar ao menu principal: ");
                                    printf("\n Digite a opção desejada: ");
                                    scanf("%d", &opCat);
                                    setbuf(stdin, NULL);
                                }while(opCat != 2);
                            }else{
                                printf("\n É necessário que os dados do hotel estejam cadastrados\n");
                            }
                        break;

                        case 4: //Cadastramento de Acomodoções
                            if(countHot == 1){
                                if(countCat > 0){
                                    do{
                                        printf("\n Cadastro de Acomodoções ");
                                        printf("\n Insira os dados das Acomodações: \n");

                                        printf("\n Informe o código da acomodação: ");
                                        scanf("%d", &acomod[countAc].codigoAcomod);
                                        setbuf(stdin, NULL);
                                        printf(" Informe a descrição da acomodação: ");
                                        fgets(acomod[countAc].descricaoAcomod, sizeof(acomod[countAc].descricaoAcomod), stdin);
                                        printf(" Informe as facilidades acomodação: ");
                                        fgets(acomod[countAc].facilidades, sizeof(acomod[countAc].facilidades), stdin);

                                        printf(" Informe a categoria da acomodação: ");
                                        fgets(acomod[countAc].categoria.descricaoCat, sizeof(acomod[countAc].categoria.descricaoCat), stdin);

                                        acomod[countAc].descricaoAcomod[strcspn(acomod[countAc].descricaoAcomod, "\n")] = 0;
                                        acomod[countAc].facilidades[strcspn(acomod[countAc].facilidades, "\n")] = 0;
                                        acomod[countAc].categoria.descricaoCat[strcspn(acomod[countAc].categoria.descricaoCat, "\n")] = 0;

                                        countAc++;

                                        GravarDadosAcomodacoes(countAc, acomod, TipoArq);

                                        CriarAcomodacao(countAc, countCat, acomod, cat); //Função que registra uma acomodação

                                        printf("\n 1. Cadastrar outra acomodação");
                                        printf("\n 2. Voltar ao menu principal");
                                        printf("\n Digite a opção desejada: ");
                                        scanf("%d", &opAc);
                                        setbuf(stdin, NULL);
                                    }while(opAc != 2 && countAc <= hot->capacidadeHotel);
                                }else{
                                    printf("\n É necessário uma categoria de acomodação cadastrada\n");
                                }
                            }else{
                                printf("\n É necessário que os dados do hotel estejam cadastrados\n");
                            }
                        break;

                        case 5: //Cadastramento de Produtos de Hóspedes
                            if(countHot == 1){
                                do{
                                    printf("\n Cadastro de Produtos de Hóspedes ");
                                    printf("\n Insira os dados dos produtos: \n");

                                    printf("\n Informe o código do produto: ");
                                    scanf("%d", &prod[countPro].codigoProduto);
                                    setbuf(stdin, NULL);
                                    printf(" Informe a descrição do produto: ");
                                    fgets(prod[countPro].descricao, sizeof(prod[countPro].descricao), stdin);
                                    printf(" Informe a quantidade em estoque do produto: ");
                                    scanf("%d", &prod[countPro].estoque);
                                    setbuf(stdin, NULL);
                                    printf(" Informe o estoque mínimo do produto: ");
                                    scanf("%d", &prod[countPro].estoqueMin);
                                    setbuf(stdin, NULL);
                                    printf(" Informe o preço de venda do produto: ");
                                    scanf("%f", &prod[countPro].precoVenda);
                                    setbuf(stdin, NULL);

                                    prod[countPro].descricao[strcspn(prod[countPro].descricao, "\n")] = 0;

                                    ++countPro;

                                    GravarDadosProdutos(countPro, prod, TipoArq);

                                    printf("\n 1. Cadastrar outro produto");
                                    printf("\n 2. Voltar ao menu principal");
                                    printf("\n Digite a opção desejada: ");
                                    scanf("%d", &opProd);
                                    setbuf(stdin, NULL);
                                }while(opProd != 2 && totalEstoque <= hot->tamEstoque);
                            }else{
                                printf("\n É necessário que os dados do hotel estejam cadastrados\n");
                            }

                            break;

                        case 6: //Cadastramento de Fornecedores
                            if(countHot == 1){
                                do{
                                    printf("\n Cadastro de Fornecedores");
                                    printf("\n Insira os dados do fornecedor: \n");

                                    printf("\n Informe o código do fornecedor: ");
                                    scanf("%d", &fornec[countFornec].codigoFornec);
                                    setbuf(stdin, NULL);
                                    printf(" Informe o nome do fornecedor: ");
                                    fgets(fornec[countFornec].nomeFornec, sizeof(fornec[countFornec].nomeFornec), stdin);
                                    printf(" Informe a razão social do fornecedor: ");
                                    fgets(fornec[countFornec].razaoSocialFornec, sizeof(fornec[countFornec].razaoSocialFornec), stdin);
                                    printf(" Informe a inscrição estadual do fornecedor: ");
                                    fgets(fornec[countFornec].inscricaoEstFornec, sizeof(fornec[countFornec].inscricaoEstFornec), stdin);
                                    printf(" Informe o CNPJ do fornecedor: ");
                                    fgets(fornec[countFornec].cnpj, sizeof(fornec[countFornec].cnpj), stdin);
                                    printf(" Informe o telefone do fornecedor: ");
                                    fgets(fornec[countFornec].telefoneFornec, sizeof(fornec[countFornec].telefoneFornec), stdin);
                                    printf(" Informe o email do fornecedor: ");
                                    fgets(fornec[countFornec].email, sizeof(fornec[countFornec].email), stdin);
                                    printf(" Endereço do Fornecedor: ");
                                    printf("\n Informe o número do fornecedor: ");
                                    fgets(fornec[countFornec].enderFornec.numFornec, sizeof(fornec[countFornec].enderFornec.numFornec), stdin);
                                    printf("\n Informe a rua do fornecedor: ");
                                    fgets(fornec[countFornec].enderFornec.ruaFornec, sizeof(fornec[countFornec].enderFornec.ruaFornec), stdin);
                                    printf(" Informe o bairro do fornecedor: ");
                                    fgets(fornec[countFornec].enderFornec.bairroFornec, sizeof(fornec[countFornec].enderFornec.bairroFornec), stdin);
                                    printf(" Informe a cidade do fornecedor: ");
                                    fgets(fornec[countFornec].enderFornec.cidadeFornec, sizeof(fornec[countFornec].enderFornec.cidadeFornec), stdin);
                                    printf(" Informe o estado do fornecedor: ");
                                    fgets(fornec[countFornec].enderFornec.estadoFornec, sizeof(fornec[countFornec].enderFornec.estadoFornec), stdin);
                                    printf(" Informe o país do fornecedor: ");
                                    fgets(fornec[countFornec].enderFornec.paisFornec, sizeof(fornec[countFornec].enderFornec.paisFornec), stdin);

                                    fornec[countFornec].nomeFornec[strcspn(fornec[countFornec].nomeFornec, "\n")] = 0;
                                    fornec[countFornec].razaoSocialFornec[strcspn(fornec[countFornec].razaoSocialFornec, "\n")] = 0;
                                    fornec[countFornec].inscricaoEstFornec[strcspn(fornec[countFornec].inscricaoEstFornec, "\n")] = 0;
                                    fornec[countFornec].cnpj[strcspn(fornec[countFornec].cnpj, "\n")] = 0;
                                    fornec[countFornec].telefoneFornec[strcspn(fornec[countFornec].telefoneFornec, "\n")] = 0;
                                    fornec[countFornec].email[strcspn(fornec[countFornec].email, "\n")] = 0;
                                    fornec[countFornec].enderFornec.numFornec[strcspn(fornec[countFornec].enderFornec.numFornec, "\n")] = 0;
                                    fornec[countFornec].enderFornec.ruaFornec[strcspn(fornec[countFornec].enderFornec.ruaFornec, "\n")] = 0;
                                    fornec[countFornec].enderFornec.bairroFornec[strcspn(fornec[countFornec].enderFornec.bairroFornec, "\n")] = 0;
                                    fornec[countFornec].enderFornec.cidadeFornec[strcspn(fornec[countFornec].nomeFornec, "\n")] = 0;
                                    fornec[countFornec].enderFornec.estadoFornec[strcspn(fornec[countFornec].enderFornec.estadoFornec, "\n")] = 0;
                                    fornec[countFornec].enderFornec.paisFornec[strcspn(fornec[countFornec].enderFornec.paisFornec, "\n")] = 0;

                                    countFornec++;

                                    GravarDadosFornecedores(countFornec, fornec, TipoArq);

                                    printf("\n 1. Cadastrar outro fornecedor");
                                    printf("\n 2. Voltar ao menu principal");
                                    printf("\n Digite a opção desejada: ");
                                    scanf("%d", &opFornec);
                                    setbuf(stdin, NULL);
                                }while(opFornec != 2 && countFornec<hot->quantFornec);
                            }else{
                                printf("\n É necessário que os dados do hotel estejam cadastrados\n");
                            }

                            break;

                        case 7: //Cadastramento de Operadores
                            if(countHot == 1){
                                do{
                                    printf("\n Informe o código do operador: ");
                                    scanf("%d", &ope[countOpe].codigoOpe);
                                    setbuf(stdin, NULL);
                                    printf(" Informe o nome do operador: ");
                                    fgets(ope[countOpe].nomeOpe, sizeof(ope[countOpe].nomeOpe), stdin);
                                    printf(" Informe o usúario do operador: ");
                                    fgets(ope[countOpe].usuario, sizeof(ope[countOpe].usuario), stdin);
                                    printf(" Informe a senha do operador: ");
                                    fgets(ope[countOpe].senha, sizeof(ope[countOpe].senha), stdin);
                                    printf(" Informe as permissões de acesso do operador: ");
                                    fgets(ope[countOpe].permissoesAcess, sizeof(ope[countOpe].permissoesAcess), stdin);

                                    printf("\n 1. Cadastrar outro operador: ");
                                    printf("\n 2. Voltar ao menu principal: ");
                                    printf("\n Digite a opção desejada: ");
                                    scanf("%d", &opOpe);
                                    setbuf(stdin, NULL);

                                }while(opOpe != 2);
                            }else{
                                printf("\n É necessário que os dados do hotel estejam cadastrados\n");
                            }
                            break;
                        }
                    } else {
                        printf("Opção inválida");
                    }
                break;

                case 2:
                    if(countHot == 1){
                        printf("\n Modificar Dados");
                        printf("\n 1. Modificar dados do hotel");
                        printf("\n 2. Modificar dados de hóspedes");
                        printf("\n 3. Modificar dados de categorias de acomodação");
                        printf("\n 4. Modificar dados de acomodações");
                        printf("\n 5. Modificar dados de produtos para os hóspedes");
                        printf("\n 6. Modificar dados de Fornecedores");
                        printf("\n 7. Modificar dados de operadores do sistema");

                        printf("\n Digite uma opção para modificar: ");
                        scanf("%d", &opMod);
                        setbuf(stdin, NULL);
                        if(opMod >= 1 && opMod <=7){
                            switch(opMod){
                                case 1:
                                    do{
                                        printf("\n Modificar Dados do Hotel");
                                        printf("\n 1. Modificar nome do hotel");
                                        printf("\n 2. Modificar razão social do hotel");
                                        printf("\n 3. Modificar inscrição estadual do hotel");
                                        printf("\n 4. Modificar cnpj do hotel");
                                        printf("\n 5. Modificar telefone do hotel");
                                        printf("\n 6. Modificar email do hotel");
                                        printf("\n 7. Modificar responsável do hotel");
                                        printf("\n 8. Modificar telefone do responsável pelo hotel");
                                        printf("\n 9. Modificar horário de check in do hotel");
                                        printf("\n 10. Modificar horário de check out do hotel");
                                        printf("\n 11. Modificar margem de lucro do hotel");
                                        printf("\n 12. Modificar capacidade do hotel");
                                        printf("\n 13. Modificar tamanho do estoque do hotel");
                                        printf("\n 14. Modificar quantidade de Fornecedores do hotel");
                                        printf("\n 15. Modificar quantidade de operadores do hotel");
                                        printf("\n Modificar Endereço do Hotel");
                                        printf("\n 16. Modificar número do hotel");
                                        printf("\n 17. Modificar rua do hotel");
                                        printf("\n 18. Modificar bairro do hotel");
                                        printf("\n 19. Modificar cidade do hotel");
                                        printf("\n 20. Modificar estado hotel");
                                        printf("\n Digite uma opção para modificar: ");
                                        scanf("%d", &op);
                                        setbuf(stdin, NULL);

                                        if(op>=1 && op<=20){
                                            ModificarDadosHotel(op, hot);
                                        }else{
                                            printf("Opção Inválida");
                                        }
                                        printf("\n Digite '1' para modificar outro dado");
                                        printf("\n Digite '2' voltar ao menu principal");
                                        printf("\n Digite a opção desejada: ");
                                        scanf("%d", &opHot);
                                        setbuf(stdin, NULL);
                                    }while(opHot != 2);
                                break;

                                case 2:
                                    do{
                                        printf("\n Modificar Dados do Hóspede");
                                        printf("\n 1. Modificar código do hóspede");;
                                        printf("\n 2. Modificar CPF do hóspede");
                                        printf("\n 3. Modificar telefone do hóspede");
                                        printf("\n 4. Modificar email do hóspede");
                                        printf("\n 5. Modificar estado civil do hóspede");
                                        printf("\n Modificar Endereço do Hóspede");
                                        printf("\n 6. Modificar número da casa do hóspede");
                                        printf("\n 7 Modificar rua do hóspede");
                                        printf("\n 8. Modificar bairro hóspede");
                                        printf("\n 9. Modificar cidade do hóspede");
                                        printf("\n 10. Modificar estado do hóspede");
                                        printf("\n 11. Modificar país do hóspede");
                                        printf("\n Informe o dado que deseja modificar: ");
                                        scanf("%d", &op);
                                        setbuf(stdin, NULL);

                                        if(op>=1 && op<=12){
                                            printf("Informe o nome que deseja pesquisar:");
                                            fgets(pesqNomeHosp, sizeof(pesqNomeHosp), stdin);

                                            ModificarDadosHospede(op, countHosp, hosp);
                                        }else{
                                            printf("Opção Inválida");
                                        }

                                        printf("\n 1. Modificar outro dado do hóspede");
                                        printf("\n 2. Sair");
                                        printf("\n Digite a opção desejada");
                                        scanf("%d", &op2);
                                        setbuf(stdin, NULL);

                                        GravarDadosHospedes(countHosp, hosp, TipoArq);
                                    }while(op2 != 2);

                                break;

                                case 3:
                                    do{
                                        printf("\n 1. Modificar código da categoria de acomodação");
                                        printf("\n 2. Modificar descrição da categoria de acomodação");
                                        printf("\n 3. Modificar valor da diária da categoria de acomodação");
                                        printf("\n 4. Modificar a quantidade de crianças que a categoria de acomodação comporta");
                                        printf("\n 5. Modificar a quantidade de adultos que a categoria de acomodação comporta: ");
                                        scanf("%d", &op3);
                                        setbuf(stdin, NULL);

                                        if(op3>=1 && op3<=5){
                                            ModificarDadosCat(op3, countCat, cat);
                                        }else{
                                            printf("Opção Inválida");
                                        }
                                        printf("\n 1. Modificar outro dado da categoria de acomodação");
                                        printf("\n 2. Sair");
                                        printf("\n Digite a opção desejada");
                                        scanf("%d", &op4);
                                        setbuf(stdin, NULL);
                                        GravarDadosCategoria(countCat, cat, TipoArq);

                                    }while(op4 != 2);
                                break;

                                case 4:
                                    do{
                                        printf("\n 1. Modificar código da acomodação");
                                        printf("\n 2. Modificar descrição da acomodação");
                                        printf("\n 3. Modificar facilidades da acomodação");
                                        printf("\n 4. Modificar categoria da acomodação");
                                        printf("\n Informe qual campo deseja modificar: ");
                                        scanf("%d", &op5);
                                        setbuf(stdin, NULL);
                                        if(op5>=1 && op5<=4){
                                            ModificarDadosAcomod(op5, countAc, acomod);
                                        }else{
                                            printf("Opção Inválida");
                                        }
                                        printf("\n 1. Modificar outro dado da acomodação");
                                        printf("\n 2. Sair");
                                        printf("\n Digite a opção desejada: ");
                                        scanf("%d", &op6);
                                        setbuf(stdin, NULL);

                                        GravarDadosAcomodacoes(countAc, acomod, TipoArq);
                                    }while(op6 != 2);
                                break;

                                case 5:
                                    do{
                                        printf("\n 1. Modificar código do produto");
                                        printf("\n 2. Modificar descrição do produto");
                                        printf("\n 3. Modificar estoque do produto");
                                        printf("\n 4. Modificar estoque mínimo do produto");
                                        printf("\n 5. Modificar preço de venda");
                                        printf("\n 6. Modificar preço de custo");
                                        printf("\n Informe qual campo deseja modificar: ");
                                        scanf("%d", &op7);
                                        setbuf(stdin, NULL);

                                        if(op7 >= 1 && op7 <= 4){
                                            ModificarDadosProd(op7, countPro, prod);
                                        }else{
                                            printf("Opção inválida");
                                        }
                                        printf("\n 1. Modificar outro dado dos produtos");
                                        printf("\n 2. Sair");
                                        printf("\n Digite a opção desejada: ");
                                        scanf("%d", &op8);
                                        setbuf(stdin, NULL);
                                    }while(op8 != 2);
                                break;

                                case 6:
                                    do{
                                        printf("\n 1. Modificar código do fornecedor: ");
                                        printf("\n 2. Modificar nome do fornecedor: ");
                                        printf("\n 3. Modificar razão social do fornecedor: ");
                                        printf("\n 4. Modificar inscrição estadual do fornecedor: ");
                                        printf("\n 5. Modificar CNPJ do fornecedor: ");
                                        printf("\n 6. Modificar telefone do fornecedor: ");
                                        printf("\n 7. Modificar email do fornecedor: ");
                                        printf("\n Modificar Endereço do Fornecedor: ");
                                        printf("\n 8. Modificar número do fornecedor: ");
                                        printf("\n 9. Modificar rua do fornecedor: ");
                                        printf("\n 10. Modificar bairro do fornecedor: ");
                                        printf("\n 11. Modificar cidade do fornecedor: ");
                                        printf("\n 12. Modificar estado do fornecedor: ");
                                        printf("\n 13. Modificar país do fornecedor: ");
                                        printf("\n Informe qual campo deseja modificar: ");
                                        scanf("%d", &op9);
                                        setbuf(stdin, NULL);

                                        if(op9 >= 1 && op9 <= 13){
                                            ModificarDadosFornec(op9, countFornec, fornec);
                                        }else{
                                            printf("Opção inválida");
                                        }
                                        printf("\n 1. Modificar outro dado dos produtos");
                                        printf("\n 2. Sair");
                                        printf("\n Digite a opção desejada: ");
                                        scanf("%d", &op10);
                                        setbuf(stdin, NULL);

                                        GravarDadosFornecedores(countFornec, fornec, TipoArq);
                                    }while(op10 != 2);
                                break;

                                case 7:
                                    do{
                                        printf("\n 1. Modificar código do operador: ");
                                        printf("\n 2. Modificar nome do operador: ");
                                        printf("\n 3. Modificar usuário do operador: ");
                                        printf("\n 4. Modificar senha do operador: ");
                                        printf("\n 5. Modificar permissão de acesso do operador: ");
                                        printf("\n Informe qual campo deseja modificar: ");
                                        scanf("%d", &op11);
                                        setbuf(stdin, NULL);

                                        if(op11 >= 1 && op11 <= 20){
                                            ModificarDadosOpe(op11, countOpe, ope);
                                        } else {
                                            printf("\nOpção inválida");
                                        }
                                        printf("\n 1. Modificar outro dado dos produtos");
                                        printf("\n 2. Sair");
                                        printf("\n Digite a opção desejada: ");
                                        scanf("%d", &op12);
                                        setbuf(stdin, NULL);

                                    }while(op12 != 2);
                                break;
                            }
                        } else {
                            printf("Opção inválida");
                        }
                    }else{
                        printf("\n É necessário que os dados do hotel estejam cadastrados\n");
                    }
                break;

                case 3:

                    if(countHot == 1){

                        printf("\n Excluir Dados");
                        printf("\n 1. Excluir dados de hóspedes");
                        printf("\n 2. Excluir dados de categorias de acomodação");
                        printf("\n 3. Excluir dados de acomodações");
                        printf("\n 4. Excluir dados de produtos para os hóspedes");
                        printf("\n 5. Excluir dados de Fornecedores");
                        printf("\n 6. Excluir dados de operadores do sistema");
                        printf("\n Digite uma opção de exclusão: ");
                        scanf("%d", &opExc);
                        setbuf(stdin, NULL);
                            if(opExc >= 1 && opExc <= 7){
                                switch(opExc){
                                    case 1:
                                        do{
                                            countHosp = ExcluirDadosHospedes(countHosp, hosp);
                                            printf("\n 1. Excluir outro hóspede");
                                            printf("\n 2. Sair");
                                            printf("\n Digite a opção desejada");
                                            scanf("%d", &op13);
                                            setbuf(stdin, NULL);
                                        }while(op13 != 2);
                                    break;

                                    case 2:
                                        do{
                                            countCat = ExcluirDadosCat(countCat, cat);
                                            printf("\n 1. Excluir outra categoria de acomadação");
                                            printf("\n 2. Sair");
                                            printf("\n Digite a opção desejada");
                                            scanf("%d", &op14);
                                            setbuf(stdin, NULL);

                                            GravarDadosCategoria(countCat, cat, TipoArq);
                                        }while(op14 != 2);
                                    break;

                                    case 3:
                                        do{
                                            countAc =  ExcluirDadosAcomod(countAc, acomod);
                                            printf("\n 1. Excluir outra acomodação");
                                            printf("\n 2. Sair");
                                            printf("\n Digite a opção desejada");
                                            scanf("%d", &op15);
                                            setbuf(stdin, NULL);
                                        }while(op15 != 2);
                                    break;

                                    case 4:
                                        do{
                                            countPro = ExcluirDadosProd(countPro, prod);
                                            printf("\n 1. Excluir outro produto");
                                            printf("\n 2. Sair");
                                            printf("\n Digite a opção desejada");
                                            scanf("%d", &op16);
                                            setbuf(stdin, NULL);

                                            GravarDadosAcomodacoes(countAc, acomod, TipoArq);
                                        }while(op16 != 2);
                                    break;

                                    case 5:
                                        do{
                                            countFornec = ExcluirDadosFornec(countFornec, fornec);
                                            printf("\n 1. Excluir outro fornecedor");
                                            printf("\n 2. Sair");
                                            printf("\n Digite a opção desejada");
                                            scanf("%d", &op17);
                                            setbuf(stdin, NULL);

                                            GravarDadosFornecedores(countFornec, fornec, TipoArq);
                                        }while(op17 != 2);
                                    break;

                                    case 6:
                                        do{
                                        countOpe = ExcluirDadosOpe(countOpe, ope);
                                        printf("\n 1. Excluir outro fornecedor");
                                        printf("\n 2. Sair");
                                        printf("\n Digite a opção desejada");
                                        scanf("%d", &op18);
                                        setbuf(stdin, NULL);
                                    }while(op18 != 2);
                                    break;
                                }
                            } else {
                                printf("Opção inválida");
                            }
                    }else{
                        printf("\n É necessário que os dados do hotel estejam cadastrados\n");
                    }
                break;

                case 4:

                    if(countHot == 1){

                        printf("\n Mostrar Dados");
                        printf("\n 1. Mostrar dados do hotel");
                        printf("\n 2. Mostrar dados de hóspedes");
                        printf("\n 3. Mostrar dados de categorias de acomodação");
                        printf("\n 4. Mostrar dados de acomodações");
                        printf("\n 5. Mostrar dados de produtos para os hóspedes");
                        printf("\n 6. Mostrar dados de Fornecedores");
                        printf("\n 7. Mostrar dados de operadores do sistema");
                        printf("\n Digite uma opção para mostrar os dados: ");
                        scanf("%d", &opMost);
                        setbuf(stdin, NULL);

                            if(opMost >= 1 && opMost <=7){
                                switch(opMost){
                                    case 1:
                                        MostrarDadosHotel(hot);
                                    break;

                                    case 2:
                                        MostrarDadosHospedes(countHosp, hosp);
                                    break;

                                    case 3:
                                        MostrarDadosCat(countCat, cat);
                                    break;

                                    case 4:
                                        MostrarDadosAcomod(countAc, acomod);
                                    break;

                                    case 5:
                                       MostrarDadosProd(countPro, prod);
                                    break;

                                    case 6:
                                        MostrarDadosFornec(countFornec, fornec);
                                    break;

                                    case 7:
                                        MostrarDadosOpe(countOpe, ope);
                                    break;
                            }
                        } else {
                            printf("\n Opção inválida");
                        }
                    }else{
                        printf("\n É necessário que os dados do hotel estejam cadastrados\n");
                    }
                break;

                case 5:

                    if(countHot == 1){

                        if(countAc >= 0){

                            printf("--------------------- Acomodações cadastradas para reserva ---------------------\n");

                                for(i=0; i<countAc; i++){
                                    printf("\n%d - Codigo = %d\n",i+1,acomod[i].codigoAcomod);
                                    printf("    Categoria = %s",acomod[i].categoria.descricaoCat);
                                    printf("\n    Facilidades = %s",acomod[i].facilidades);
                                    printf("\n    Limite quantidade de crianças = %d",acomod[i].categoria.QuantCriancas);
                                    printf("\n    Limite quantidade de adultos = %d\n",acomod[i].categoria.QuantAdultos);
                                    printf("\n    Data de reservas agendadas: ");
                                    for(j=0; j<*pTotRes; j++){
                                        if(acomod[i].codigoAcomod == reserva[j].codAcomodRes){
                                            printf("\n    De %s até %s", reserva[j].strDataIni, reserva[j].strDataFinal);
                                        }
                                    }
                                }

                            printf("\n--------------------------------------------------------------------------------\n");

                                do{
                                    printf("\n Agende sua reserva\n\n");

                                    verificarRes = AgendarReserva(pTotRes, countAc, reserva, acomod); //Função que verifica a disponibilidade da reserva que deseja ser agendada

                                    if(verificarRes[6] == 0){
                                        printf("\n Sua reserva foi agendada");
                                    }else{
                                        printf("\n Sua reserva nao foi agendada. Motivos:\n");
                                    }

                                    if(verificarRes[0] == 1){
                                        printf("\n Código de acomodação inexistente");
                                    }
                                    if(verificarRes[1] == 1){
                                        printf("\n Data indisponível para esta reserva");
                                    }
                                    if(verificarRes[2] == 1){
                                        printf("\n Categoria incompatível com o código digitado");
                                    }
                                    if(verificarRes[3] == 1){
                                        printf("\n Facilidade indisponível para esta acomodação");
                                    }
                                    if(verificarRes[4] == 1){
                                        printf("\n Quantidade de crianças excede a acomodação");
                                    }
                                     if(verificarRes[5] == 1){
                                        printf("\n Quantidade de adultos excede a acomodação");
                                    }

                                    GravarDadosReservas(totRes, reserva, TipoArq);

                                    printf("\n\n 1. Agendar outra reserva");
                                    printf("\n 2. Sair");
                                    printf("\n Digite a opção desejada: ");
                                    scanf("%d", &op19);
                                    setbuf(stdin, NULL);


                                }while(op19 != 2);
                            }else{
                                printf("\n É necessário que uma acomodação esteja cadastrada\n");
                            }
                        }else{
                            printf("\n É necessário que os dados do hotel estejam cadastrados\n");
                        }
                    break;

                    case 6:
                        if(countHot == 1){
                            do{
                                CancelarReserva(pTotRes, reserva); //Função responsável pelo cancelamento de uma reserva

                                GravarDadosReservas(totRes, reserva, TipoArq);

                                printf("\n 1. Cancelar outra reserva");
                                printf("\n 2. Sair");
                                printf("\n Digite a opção desejada: ");
                                scanf("%d", &op20);
                                setbuf(stdin, NULL);
                            }while(op20 != 2);
                    }else{
                        printf("\n É necessário que os dados do hotel estejam cadastrados\n");
                    }
                break;

                case 7:
                    printf("\n Reservas");
                    for(i=0; i<totRes; i++){
                        printf("\n Nome do responsável pela reserva: %s", reserva[i].nomePessoa);
                        printf("\n Código da acomodação: %d", reserva[i].codAcomodRes);
                        printf("\n Data inicial da reserva: %s", reserva[i].strDataIni);
                        printf("\n Data final da reserva: %s\n", reserva[i].strDataFinal);
                    }
                break;

                case 8:
                    printf("\n Informe os dados que deseja Ler: ");
                    printf("\n 1. Ler dados do Hotel");
                    printf("\n 2. Ler dados dos hóspedes");
                    printf("\n 3. Ler dados das categorias de acomodação");
                    printf("\n 4. Ler dados das acomodações");
                    printf("\n 5. Ler dados dos produtos para os hóspedes ");
                    printf("\n 6. Ler dados dos fornecedores");
                    printf("\n 7. Ler dados das reservas");
                    printf("\n Digite uma opção: ");
                    scanf("%d", &op22);
                    setbuf(stdin, NULL);
                    switch(op22){
                        case 1:
                            countHot = LerDadosTxtHotel(hot);

                            if(countHot == 1){
                                hosp = (hospede*)malloc(hot->capacidadeHotel * sizeof(hospede));

                                cat = (categoriaAcomod*)malloc(20 * sizeof(categoriaAcomod));

                                acomod = (acomodacoes*)malloc(hot->qtdAcomod * sizeof(acomodacoes));

                                prod = (produtos*)malloc(hot->tamEstoque * sizeof(produtos));

                                fornec = (fornecedores*)malloc(hot->quantFornec * sizeof(fornecedores));

                                ope = (operadores*)malloc(hot->quantOpe * sizeof(operadores));

                                reserva = (reservas*)malloc(hot->quantFornec * sizeof(reservas));
                            }
                        break;

                        case 2:
                            countHosp = LerDadosTxtHospedes(hosp);
                        break;

                        case 3:
                            countCat = LerDadosTxtCategorias(cat);
                        break;

                        case 4:
                            countAc = LerDadosTxtAcomodacoes(acomod);
                            if(countAc > 0){
                                CriarAcomodacaoArquivos(countAc, countCat, acomod, cat);
                            }
                        break;

                        case 5:
                            countPro = LerDadosTxtProdutos(prod);
                        break;

                        case 6:
                            countFornec = LerDadosTxtFornecedores(fornec);
                        break;

                        case 7:
                            totRes = LerDadosTxtReservas(reserva);
                        break;
                    }
                break;

                case 9:
                    printf("\n Informe os dados que deseja Ler: ");
                    printf("\n 1. Ler dados do Hotel");
                    printf("\n 2. Ler dados dos hóspedes");
                    printf("\n 3. Ler dados das categorias de acomodação");
                    printf("\n 4. Ler dados das acomodações");
                    printf("\n 5. Ler dados dos produtos para os hóspedes ");
                    printf("\n 6. Ler dados dos fornecedores");
                    printf("\n 7. Ler dados das reservas");
                    printf("\n Digite uma opção: ");
                    scanf("%d", &op22);
                    setbuf(stdin, NULL);

                    switch(op22){
                        case 1:
                            countHot = LerDadosBinHotel(hot);

                            if(countHot == 1){
                                hosp = (hospede*)malloc(hot->capacidadeHotel * sizeof(hospede));

                                cat = (categoriaAcomod*)malloc(20 * sizeof(categoriaAcomod));

                                acomod = (acomodacoes*)malloc(hot->qtdAcomod * sizeof(acomodacoes));

                                prod = (produtos*)malloc(hot->tamEstoque * sizeof(produtos));

                                fornec = (fornecedores*)malloc(hot->quantFornec * sizeof(fornecedores));

                                ope = (operadores*)malloc(hot->quantOpe * sizeof(operadores));

                                reserva = (reservas*)malloc(hot->quantFornec * sizeof(reservas));
                            }
                        break;

                        case 2:
                            countHosp = LerDadosBinHospedes(hosp);
                        break;

                        case 3:
                            countCat = LerDadosBinCategorias(cat);
                        break;

                        case 4:
                            countAc = LerDadosBinAcomodacoes(acomod);
                            if(countAc > 0){
                                CriarAcomodacaoArquivos(countAc, countCat, acomod, cat);
                            }
                        break;

                        case 5:
                            countPro = LerDadosBinProdutos(prod);
                        break;

                        case 6:
                            countFornec = LerDadosBinFornecedores(fornec);
                        break;

                        case 7:
                            totRes = LerDadosBinReservas(reserva);
                        break;
                    }
                break;

                case 10:
                    printf("\n 1. Check In");
                    printf("\n 2. Saída de produtos");
                    printf("\n 3. Gerar nota de um hóspede");
                    printf("\n 4. Realizar pagamento");
                    printf("\n 5. Mostraros transações realizadas");
                    printf("\n 6. Entrada de produtos Industrializados");
                    printf("\n 7. Pagar fornecedor");
                    printf("\n 8. Mostrar contas de hóspedes");
                    printf("\n 9. Mostrar contas de fornecedores");
                    printf("\n 10. Ler arquivo de contas de hóspedes");
                    printf("\n 11. Ler arquivo de contas de fornecedores");
                    printf("\n 12. Ler arquivo do caixa");
                    printf("\n Digite uma opção: ");
                    scanf("%d", &op23);
                    setbuf(stdin, NULL);

                    switch(op23){
                        case 1:
                            CheckinRes(pTotTran, pTotContReceb, pTotDiariaAc, reserva, pTotRes, cat, countCat, cont, pCont, caixaHotel, contReceb, TipoArq, pCountHosp, hosp, diariaAc);
                        break;

                        case 2:
                            do{
                                SaidaDeProdutos(pCont, pTotTran, prod, reserva, cont, caixaHotel, TipoArq);
                                printf("\n Deseja adicionar outro produto? ");
                                printf("\n 1. Sim");
                                printf("\n 2. Não");
                                scanf("%d", &op24);
                                setbuf(stdin, NULL);
                            }while(op24 != 2);
                        break;

                        case 3:
                            GerarNota(pCont, cont);
                        break;

                        case 4:
                            do{
                                printf("\n 1. Pagamento à vista");
                                printf("\n 2. Pagamento no cartão de crédito/débito");
                                printf("\n Digite a opção desejada: ");
                                scanf("%d", &op25);
                                setbuf(stdin, NULL);

                                CheckOut(op25, pCont, pTotTran, pTotPag, pTotContReceb, cont, contReceb, caixaHotel, TipoArq);
                                printf("\n Realizar outro pagamento?");
                                printf("\n 1. Sim");
                                printf("\n 2. Não");
                                printf("\n Digite a opção desejada: ");
                                scanf("%d", &op26);
                                setbuf(stdin, NULL);
                            }while(op26 != 2);
                        break;

                        case 5:
                            MostrarTransacoes(pTotTran, caixaHotel);
                        break;

                        case 6:
                            do{
                                EntradaProdutosInd(pProdInd, prodInd);

                                do{
                                    PrecoProdutosInd(pProdInd, pCountPro, pQtdProdComp, pTotProdComp, prodInd, prod, hot, TipoArq);

                                    printf("\n Cadastrar mais produtos?");
                                    printf("\n 1. Sim");
                                    printf("\n 2. Não");
                                    printf("\n Digite a opção desejada: ");
                                    scanf("%d", &op27);
                                    setbuf(stdin, NULL);
                                }while(op27 != 2);

                                *pQtdProdComp = 0;

                                printf("\n Forma de pagamento");
                                printf("\n 1. À vista");
                                printf("\n 2. À prazo");
                                printf("\n Digite a opção desejada: ");
                                scanf("%d", &op29);
                                setbuf(stdin, NULL);

                                if(op29 == 1){
                                    PagamentoFornecedorAVista(pTotTran, pTotContPag, pProdInd, prodInd, caixaHotel, cont3, TipoArq);
                                }else if(op29 == 2){
                                    printf("\n Realizar pagamento de entrada?");
                                    printf("\n 1. Sim");
                                    printf("\n 2. Não");
                                    printf("\n Digite a opção desejada: ");
                                    scanf("%d", &op30);
                                    setbuf(stdin, NULL);

                                    if(op30 == 2){
                                        valEnt = 0;
                                        parc = 1;
                                        PagamentoFornecedorAPrazo(pTotTran, valEnt, parc, pTotContPag, pProdInd, prodInd, caixaHotel, cont3);
                                    } else if(op30 == 1){
                                        printf("Informe o valor da entrada: ");
                                        scanf("%f", &valEnt);
                                        setbuf(stdin, NULL);
                                        printf("Informe em quantas parcelas deseja dividir o pagamento total: ");
                                        scanf("%d", &parc);
                                        setbuf(stdin, NULL);
                                        PagamentoFornecedorAPrazo(pTotTran, valEnt, parc, pTotContPag, pProdInd, prodInd, caixaHotel, cont3);
                                    }
                                }

                                printf("\n Realizar outra entrada de produtos?");
                                printf("\n 1. Sim");
                                printf("\n 2. Não");
                                printf("\n Digite a opção desejada: ");
                                scanf("%d", &op27);
                                setbuf(stdin, NULL);
                            }while(op27 != 2);
                        break;

                        case 7:
                            PagarFornecedor(pTotTran, pTotContPag, caixaHotel, cont3, TipoArq);
                        break;

                        case 8:
                            MostrarContasHospede(pCont, cont);
                        break;

                        case 9:
                            printf("\n 1. Mostrar todas as movimentações de fornecedores: ");
                            printf("\n 2. Pesquisar por fornecedor: ");
                            printf("\n 3. Mostrar contas a pagar: ");
                            printf("\n Digite a opção desejada: ");
                            scanf("%d", &op33);
                            setbuf(stdin, NULL);
                            MostrarContasFornec(op33, pProdInd, pTotContPag, prodInd, cont3);
                        break;

                        case 10:

                        break;

                        case 11:

                            *pTotContPag = ContAPagarFornecArquivo(pProdInd, prodInd, cont3);

                            do{
                            printf("\n Parcelar pagamento? (1.Sim/ 2.Não");
                            scanf("%d", &op31);

                                if(op31 == 1){
                                    printf("\n Informe a quantidade de parcelas: ");
                                    scanf("%d", &parc2);
                                    printf("\n Deseja dar valor de entrada? (1.Sim/ 2.Não)");
                                    scanf("%d", &op32);
                                    if(op32 == 1){
                                        printf("\n Informe o valor de entrada: ");
                                        scanf("%f", &valEnt2);
                                        setbuf(stdin, NULL);
                                        ParcelarContFornec(valEnt2, parc2, pTotContPag, caixaHotel, cont3);

                                    } else if(op32 == 2){
                                        valEnt2 = 0;
                                        ParcelarContFornec(valEnt2, parc2, pTotContPag, caixaHotel, cont3);
                                    }
                                }
                            }while(op31 == 1);
                        break;
                    }
                break;
                
                case 11:
                    printf("\n 1. Imprimir Relatórios de Hóspedes");
                    printf("\n 2. Imprimir Relatórios de Acomodações"); 
                    printf("\n 3. Imprimir Relatórios de Reservas"); 
                    printf("\n 4. Imprimir Relatórios da Movimentação de Acomodações"); 
                    printf("\n 5. Imprimir Relatórios de Produtos Para Consumo"); 
                    printf("\n 6. Imprimir Relatórios de Produto em Estoque Mínimo"); 
                    printf("\n 7. Imprimir Relatórios de Vendas"); 
                    printf("\n 8. Imprimir Relatórios de Contas a Receber"); 
                    printf("\n 9. Imprimir Relatórios de Contas a Pagar"); 
                    printf("\n 10. Imprimir Relatórios de Movimentações do Caixa");
                    printf("\n Digite a opção desejada: ");
                    scanf("%d", &op35);
                    setbuf(stdin, NULL);

                    switch(op35){
                        case 1:
                            printf("\n 1. Imprimir relatório em arquivo texto");
                            printf("\n 2. Imprimir o relatório em tela");
                            printf("\n Digite a opção desejada: ");
                            scanf("%d", &op36);
                            setbuf(stdin, NULL);

                            printf("\n Informe o código inicial do intervalo dos hóspedes que deseja imprimir: ");
                            scanf("%d", &codIni);
                            setbuf(stdin, NULL);

                            printf(" Informe o código final do intervalo dos hóspedes que deseja imprimir: ");
                            scanf("%d", &codFin);
                            setbuf(stdin, NULL);

                            printf(" Informe o sexo dos hóspedes que deseja imprimir: ");
                            fgets(sexoHosp, sizeof(sexoHosp), stdin);

                            sexoHosp[strcspn(sexoHosp, "\n")] = 0;

                            if(op36 == 1){
                               RelatorioHospedes(sexoHosp, codIni, codFin, hosp);
                            }else if(op36 == 2){

                                for(i=codIni; i<=codFin; i++){
                                    if(strcmp(hosp[i-1].sexo, sexoHosp) == 0){
                                        printf("\n Código do Hóspede: %d", hosp[i-1].codigoHospede);
                                        printf("\n Nome do Hóspede: %s", hosp[i-1].nomeHospede);
                                        printf("\n CPF do Hóspede: %s", hosp[i-1].cpf);
                                        printf("\n Telefone do Hóspede: %s", hosp[i-1].telHospede);
                                        printf("\n Email do Hóspede: %s", hosp[i-1].emailHospede);
                                        printf("\n Sexo do Hóspede: %s", hosp[i-1].sexo);
                                        printf("\n Estado Civil do Hóspede: %s", hosp[i-1].estCivHospede);
                                        printf("\n Data de Nascimento do Hóspede: %s", hosp[i-1].dataNasci);
                                        printf("\n Endereço do Hóspede: %s", hosp[i-1].enderHosp.num);
                                        printf("\n Rua do Hóspede: %s", hosp[i-1].enderHosp.rua);
                                        printf("\n Bairro do Hóspede: %s", hosp[i-1].enderHosp.bairro);
                                        printf("\n Cidade do Hóspede: %s", hosp[i-1].enderHosp.cidade);
                                        printf("\n Estado do Hóspede: %s", hosp[i-1].enderHosp.estado);
                                        printf("\n País do Hóspede: %s\n", hosp[i-1].enderHosp.pais);
                                    }
                                }
                            }
                        break;

                        case 2:
                            printf("\n 1. Imprimir relatório em arquivo texto");
                            printf("\n 2. Imprimir o relatório em tela");
                            printf("\n Digite a opção desejada: ");
                            scanf("%d", &op39);
                            setbuf(stdin, NULL);

                            printf("\n Deseja filtrar a reserva pelo nome(opção 1) ou sexo(opção 2) do hóspede:");
                            printf("\n Digite a opção desejada: ");
                            scanf("%d", &op40);
                            setbuf(stdin, NULL);

                            switch(op40){
                                case 1:
                                    printf("\n Informe o nome do hóspede responsável pela reserva que deseja imprimir: ");
                                    fgets(nomeHosp, sizeof(nomeHosp), stdin);
                                break;
                                case 2:
                                    printf("\n Informe o sexo dos hóspedes que deseja imprimir: ");
                                    fgets(sexoHosp, sizeof(sexoHosp), stdin);
                                break;
                            }

                            printf("\n Deseja filtrar a reserva pela categoria(opção 1) ou código(opção 2) da acomodação:");
                            printf("\n Digite a opção desejada: ");
                            scanf("%d", &op41);
                            setbuf(stdin, NULL);

                            switch(op41){
                                case 1:
                                    printf("\n Informe a categoria da acomodação de reserva que deseja imprimir: ");
                                    fgets(categoria, sizeof(categoria), stdin);
                                break;
                                case 2:
                                    printf("\n Informe o código da acomodação de reserva que deseja imprimir ");
                                    scanf("%d", &codAcomod);
                                    setbuf(stdin, NULL);
                                break;
                            }
                            nomeHosp[strcspn(nomeHosp, "\n")] = 0;
                            sexoHosp[strcspn(sexoHosp, "\n")] = 0;
                            categoria[strcspn(categoria, "\n")] = 0;

                            if(op39 == 1){
                               RelatorioReservas(op40, op41, nomeHosp, sexoHosp, categoria, codAcomod, pTotRes, reserva);
                            }else if(op39 == 2){
                                if(op40 == 1 && op41 == 1){
                                    for(i=0; i<*pTotRes; i++){
                                        if(strcmp(reserva[i].catReserva, categoria) == 0){
                                            if(strcmp(reserva[i].nomePessoa, nomeHosp) == 0){
                                                printf("\n Nome do responsável pela reserva: %s", reserva[i].nomePessoa);
                                                printf("\n Sexo do responsável: %s", reserva[i].sexo);
                                                printf("\n Código da acomodação reservada: %d", reserva[i].codAcomodRes);
                                                printf("\n Categoria da acomodação reservada: %s", reserva[i].catReserva);
                                                printf("\n Data inicial da reserva: %s", reserva[i].strDataIni);
                                                printf("\n Data final da reserva: %s\n", reserva[i].strDataFinal);
                                            }
                                        }
                                    }
                                }
                                if(op40 == 1 && op41 == 2){
                                    for(i=0; i<*pTotRes; i++){
                                        if(reserva[i].codAcomodRes == codAcomod){
                                            if(strcmp(reserva[i].nomePessoa, nomeHosp) == 0){
                                                printf("\n Nome do responsável pela reserva: %s", reserva[i].nomePessoa);
                                                printf("\n Sexo do responsável: %s", reserva[i].sexo);
                                                printf("\n Código da acomodação reservada: %d", reserva[i].codAcomodRes);
                                                printf("\n Categoria da acomodação reservada: %s", reserva[i].catReserva);
                                                printf("\n Data inicial da reserva: %s", reserva[i].strDataIni);
                                                printf("\n Data final da reserva: %s\n", reserva[i].strDataFinal);
                                            }
                                        }
                                    }
                                }
                                if(op40 == 2 && op41 == 1){
                                    for(i=0; i<*pTotRes; i++){
                                        if(strcmp(reserva[i].catReserva, categoria) == 0){
                                            if(strcmp(reserva[i].sexo, sexoHosp) == 0){
                                                printf("\n Nome do responsável pela reserva: %s", reserva[i].nomePessoa);
                                                printf("\n Sexo do responsável: %s", reserva[i].sexo);
                                                printf("\n Código da acomodação reservada: %d", reserva[i].codAcomodRes);
                                                printf("\n Categoria da acomodação reservada: %s", reserva[i].catReserva);
                                                printf("\n Data inicial da reserva: %s", reserva[i].strDataIni);
                                                printf("\n Data final da reserva: %s\n", reserva[i].strDataFinal);
                                            }
                                        }
                                    }
                                }
                                if(op40 == 2 && op41 == 2){
                                    for(i=0; i<*pTotRes; i++){
                                        if(reserva[i].codAcomodRes == codAcomod){
                                            if(strcmp(reserva[i].sexo, sexoHosp) == 0){
                                                printf("\n Nome do responsável pela reserva: %s", reserva[i].nomePessoa);
                                                printf("\n Sexo do responsável: %s", reserva[i].sexo);
                                                printf("\n Código da acomodação reservada: %d", reserva[i].codAcomodRes);
                                                printf("\n Categoria da acomodação reservada: %s", reserva[i].catReserva);
                                                printf("\n Data inicial da reserva: %s", reserva[i].strDataIni);
                                                printf("\n Data final da reserva: %s\n", reserva[i].strDataFinal);
                                            }
                                        }
                                    }
                                }
                            }
                        break;

                        case 3:
                            printf("\n 1. Imprimir relatório em arquivo texto");
                            printf("\n 2. Imprimir o relatório em tela");
                            printf("\n Digite a opção desejada: ");
                            scanf("%d", &op39);
                            setbuf(stdin, NULL);

                            printf("\n Deseja filtrar a reserva pelo nome(opção 1) ou sexo(opção 2) do hóspede:");
                            printf("\n Digite a opção desejada: ");
                            scanf("%d", &op40);
                            setbuf(stdin, NULL);

                            switch(op40){
                                case 1:
                                    printf("\n Informe o nome do hóspede responsável pela reserva que deseja imprimir: ");
                                    fgets(nomeHosp, sizeof(nomeHosp), stdin);
                                break;
                                case 2:
                                    printf("\n Informe o sexo dos hóspedes que deseja imprimir: ");
                                    fgets(sexoHosp, sizeof(sexoHosp), stdin);
                                break;
                            }

                            printf("\n Deseja filtrar a reserva pela categoria(opção 1) ou código(opção 2) da acomodação:");
                            printf("\n Digite a opção desejada: ");
                            scanf("%d", &op41);
                            setbuf(stdin, NULL);

                            switch(op41){
                                case 1:
                                    printf("\n Informe a categoria da acomodação de reserva que deseja imprimir: ");
                                    fgets(categoria, sizeof(categoria), stdin);
                                break;
                                case 2:
                                    printf("\n Informe o código da acomodação de reserva que deseja imprimir ");
                                    scanf("%d", &codAcomod);
                                    setbuf(stdin, NULL);
                                break;
                            }
                            nomeHosp[strcspn(nomeHosp, "\n")] = 0;
                            sexoHosp[strcspn(sexoHosp, "\n")] = 0;
                            categoria[strcspn(categoria, "\n")] = 0;

                            RelatorioReservas(op40, op41, nomeHosp, sexoHosp, categoria, codAcomod, pTotRes, reserva);
                        break;

                        case 4:
                            printf("\n 1. Pesquisar por faixa de códigos da acomodação");
                            printf("\n 2. Pesquisar categoria da acomodação");
                            scanf("%d", &op41);
                            setbuf(stdin, NULL);

                            switch(op41){
                                case 1:
                                    printf("\n Informe o código inicial do intervalo de acomodações hospedadas que que deseja imprimir: ");
                                    scanf("%d", &codIni);

                                    setbuf(stdin, NULL);
                                break;

                                case 2:
                                    printf("\n Informe a categoria da acomodação hospedada que deseja imprimir: ");
                                    fgets(pesqCatAcomod, sizeof(pesqCatAcomod), stdin);
                                break;
                            }
                            printf("\n Informe a quantidade de diárias ocupadas da acomodação que deseja imprimir: ");
                            scanf("%d", &qtdDiaOcup);

                            printf("\n Informe o valor mínimo de rendimento da acomodação que deseja imprimir: ");
                            scanf("%f", &rendAcomod);

                            setbuf(stdin, NULL);

                            printf("\n 1. Imprimir relatório em arquivo texto");
                            printf("\n 2. Imprimir o relatório em tela");
                            printf("\n Digite a opção desejada: ");
                            scanf("%d", &op40);
                            setbuf(stdin, NULL);
                            
                            if(op40 == 1){
                                MovAcomodacoes(op41, codIni, pesqCatAcomod, qtdDiaOcup, pTotDiariaAc, rendAcomod, diariaAc);
                            } else if(op36 == 2){
                                for(i=0; i<totDiariaAc; i++){
                                    switch(op41){
                                        case 1:
                                           for(i=0; i<totDiariaAc; i++){
                                                if(diariaAc[i].totDiaria > rendAcomod && qtdDiaOcup < diariaAc[i].totalDia){
                                                    if(diariaAc[i].codAcomod == codIni){
                                                        printf("Código da acomodacação: %d", diariaAc[i].codAcomod);
                                                        
                                                        printf("Categoria da acomodação: %s", diariaAc[i].categoria);

                                                        printf("Rendimento da acomodação: %f", diariaAc[i].totDiaria);

                                                        printf("%d", diariaAc[i].totalDia);
                                                    }
                                                }
                                            }
                                        break;
                                        
                                        case 2:
                                            for(i=0; i<totDiariaAc; i++){
                                                if(diariaAc[i].totDiaria > rendAcomod && qtdDiaOcup < diariaAc[i].totalDia){
                                                    if(strcmp(pesqCatAcomod, diariaAc[i].categoria) == 0){
                                                        printf("Código da acomodacação: %d", diariaAc[i].codAcomod);
                                                        
                                                        printf("Categoria da acomodação: %s", diariaAc[i].categoria);

                                                        printf("Rendimento da acomodação: %f", diariaAc[i].totDiaria);

                                                        printf("%d", diariaAc[i].totalDia);
                                                    }
                                                }
                                            }
                                        break;
                                    } 
                                }
                            }
                        break;

                        case 5:
                            printf("\n 1. Imprimir relatório em arquivo texto");
                            printf("\n 2. Imprimir o relatório em tela");
                            printf("\n Digite a opção desejada: ");
                            scanf("%d", &op42);
                            setbuf(stdin, NULL);

                            printf("\n Informe o código inicial do intervalo dos produtos que deseja imprimir: ");
                            scanf("%d", &codIni);

                            printf(" Informe o código final do intervalo dos produtos que deseja imprimir: ");
                            scanf("%d", &codFin);

                            if(op42 == 1){
                                RelatorioProdutos(codIni, codFin, prod);
                            }else if(op42 == 2){
                                for(i=codIni; i<=codFin; i++){

                                    printf("\n Código do Produto: %d", prod[i-1].codigoProduto);
                                    printf("\n Descrição do Produto: %s", prod[i-1].descricao);
                                    printf("\n Estoque do Produto: %d", prod[i-1].estoque);
                                    printf("\n Estoque do Mínimo do Produto: %d", prod[i-1].estoqueMin);
                                    printf("\n Preço de custo: %d", prod[i-1].precoCusto);
                                    printf("\n Preço de venda: %f", prod[i-1].precoVenda);
                                }
                            }
                        break;

                        case 6:
                            printf("\n 1. Imprimir relatório em arquivo texto");
                            printf("\n 2. Imprimir o relatório em tela");
                            printf("\n Digite a opção desejada: ");
                            scanf("%d", &op43);
                            setbuf(stdin, NULL);

                            printf("\n Informe o código inicial do intervalo dos produtos que deseja imprimir: ");
                            scanf("%d", &codIni);

                            printf(" Informe o código final do intervalo dos produtos que deseja imprimir: ");
                            scanf("%d", &codFin);

                            if(op43 == 1){
                                RelatorioProdutosEstMin(codIni, codFin, prod);
                            }else if(op43 == 2){
                                for(i=codIni; i<=codFin; i++){
                                    if(prod[i-1].estoque <= prod[i-1].estoqueMin){
                                        printf("\n Código do Produto: %d", prod[i-1].codigoProduto);
                                        printf("\n Descrição do Produto: %s", prod[i-1].descricao);
                                        printf("\n Estoque do Produto: %d", prod[i-1].estoque);
                                        printf("\n Estoque do Mínimo do Produto: %d", prod[i-1].estoqueMin);
                                        printf("\n Preço de custo: %d", prod[i-1].precoCusto);
                                        printf("\n Preço de venda: %f\n", prod[i-1].precoVenda);
                                    }
                                }
                            }
                        break;
                        
                        case 7:
                            printf("\n Informe o código inicial do intervalo dos hóspedes que que deseja imprimir: ");
                            scanf("%d", &codIni);

                            printf("\n Informe o código final do intervalo dos hóspedes que que deseja imprimir: ");
                            scanf("%d", &codFin);
                            
                            setbuf(stdin, NULL);

                            printf("Digite a data do pagamento que deseja filtrar (DD/MM/AAAA): ");
                            fgets(dataCont, sizeof(dataCont), stdin);
                            
                            dataCont[strcspn(dataCont, "\n")] = 0;
                            
                            printf("\n 1. Imprimir relatório em arquivo texto");
                            printf("\n 2. Imprimir o relatório em tela");
                            printf("\n Digite a opção desejada: ");
                            scanf("%d", &op44);
                            
                            if(op44 == 1){
                                RelatorioContReceber(codIni, codFin, dataCont, contReceb);
                            } else if(op44 == 2){
                                for(i=codIni; i<codFin; i++){
                                    for(i=codIni; i<=codFin; i++){
                                        if(strcmp(contReceb[i].dataReceb, dataCont) == 0){
                                            printf("%d", contReceb[i-1].codCont);
                                            printf("%s", contReceb[i-1].nomeHosp);
                                            printf("%f", contReceb[i-1].totalPag);
                                            printf("%d", contReceb[i-1].venciCart);
                                        }
                                    }
                                }
                            }
                            setbuf(stdin, NULL);    
                        break;
                    }
                break;
                
                case 12:
                    printf("\n 1. Exportar dados dos hóspedes");
                    printf("\n 2. Exportar dados das categorias de acomodação");
                    printf("\n 3. Exportar dados das acomodações");
                    printf("\n 4. Exportar dados dos produtos para os hóspedes ");
                    printf("\n 5. Exportar dados dos fornecedores");
                    printf("\n 6. Exportar dados das reservas");
                    printf("\n Informe os números que deseja exportar (separadores por vírgula): ");
                    fgets(numTab, sizeof(numTab), stdin);
                    setbuf(stdin, NULL);
                    
                    ExportarDados(numTab, countHosp, countAc, countCat, countPro, countFornec, hosp, acomod, cat, prod, fornec);
                break;
                
                case 13:
                    printf("\n 1. Importar dados dos hóspedes");
                    printf("\n 2. Importar dados das categorias de acomodação");
                    printf("\n 3. Importar dados das acomodações");
                    printf("\n 4. Importar dados dos produtos para os hóspedes ");
                    printf("\n 5. Importar dados dos fornecedores");
                    printf("\n 6. Importar dados das reservas");
                    scanf("%d", &op39);
                    setbuf(stdin, NULL); 
                    
                    ImportarDados(op39, pCountHosp, pCountCat, pCountAc, pCountPro, pCountFornec, hosp, acomod, cat, prod, fornec);
                break;
            }
        } else {
            printf("\n Opção inválida");
        }
        RecebimentoCartao(pTotTran, pCont, pTotContReceb, caixaHotel, cont, contReceb, TipoArq);
    }while(opMenu != 14);

    getchar( );
    return (EXIT_SUCCESS);
}
