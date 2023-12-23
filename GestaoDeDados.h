#ifndef GESTAODEDADOS_H
#define GESTAODEDADOS_H

#ifdef __cplusplus
extern "C" {
#endif

struct EnderecoHotel {
    char ruaHotel[50];
    char bairroHotel[50];
    char numHotel[50];
    char cidadeHotel[50];
    char estadoHotel[50];
};

typedef struct EnderecoHotel enderecohotel;

struct Hotel {
    char nomeHotel[50];
    char razaoSocialHotel[50];
    char inscriEstadualHotel[50];
    char cnpjHotel[50];
    char telefoneHotel[50];
    char emailHotel[50];
    char responsavelHotel[50];
    char telResponsavelHotel[50];
    char horaCheckInHotel[50];
    char horaCheckOutHotel[50];
    float margemLucroHotel;
    int capacidadeHotel;
    int qtdAcomod;
    int tamEstoque;
    int quantFornec;
    int quantOpe;

    struct EnderecoHotel ender;
};

typedef struct Hotel hotel;

struct EnderecoHosp {
    char rua[50];
    char bairro[50];
    char num[50];
    char cidade[50];
    char estado[50];
    char pais[30];
};

struct Hospede {
    int codigoHospede;
    char nomeHospede[50];
    char cpf[20];
    char telHospede[20];
    char emailHospede[30];
    char sexo[30];
    char estCivHospede[30];
    char dataNasci[20];

    struct EnderecoHosp enderHosp;
};
typedef struct Hospede hospede;

struct CategoriaAcomodacao{
    int codigoCategoriaAcomod;
    char descricaoCat[100];
    float valorDiaria;
    int QuantAdultos;
    int QuantCriancas;
    int capacidadeAcomod;
};
typedef struct CategoriaAcomodacao categoriaAcomod;

struct Acomodacoes {
    int codigoAcomod;
    char descricaoAcomod[100];
    char facilidades[100];
    struct CategoriaAcomodacao categoria;
};
typedef struct Acomodacoes acomodacoes;

struct ProdutosHospedes {
    int codigoProduto;
    char descricao[50];
    int estoque;
    int estoqueMin;
    int precoCusto;
    float precoVenda;
};
typedef struct ProdutosHospedes produtos;

struct EnderecoFornec {
    char ruaFornec[20];
    char bairroFornec[20];
    char numFornec[20];
    char cidadeFornec[20];
    char estadoFornec[20];
    char paisFornec[20];
};

struct Fornecedores {
    int codigoFornec;
    char nomeFornec[20];
    char razaoSocialFornec[20];
    char inscricaoEstFornec[20];
    char cnpj[20];
    char telefoneFornec[20];
    char email[30];
    struct EnderecoFornec enderFornec;
};

typedef struct Fornecedores fornecedores;

struct OperadoresSistema {
    int codigoOpe;
    char nomeOpe[30];
    char usuario[20];
    char senha[20];
    char permissoesAcess[20];
};

typedef struct OperadoresSistema operadores;

void CadastrarProdutos(int *countPro, produtos *prod, int TipoArq);

void CadastrarHospedes(int *countHosp, hospede *hospedes, int TipoArq);

void CriarAcomodacao(int x, int totCat, acomodacoes *acomodacao, categoriaAcomod *categoria);

void CriarAcomodacaoArquivos(int x, int totCat, acomodacoes *acomodacao, categoriaAcomod *categoria);

void MostrarDadosHotel(struct Hotel *x);

void MostrarDadosHospedes(int x, struct Hospede *y);

void MostrarDadosCat(int x, struct CategoriaAcomodacao *y);

void MostrarDadosAcomod(int x, struct Acomodacoes *y);

void MostrarDadosProd(int x, struct ProdutosHospedes *y);

void MostrarDadosFornec(int x, struct Fornecedores *y);

void MostrarDadosOpe(int x, struct OperadoresSistema *y);

void ModificarDadosHotel(int y, struct Hotel *x);

void ModificarDadosHospede(int z, int x, struct Hospede *y);

void ModificarDadosCat(int z, int x, struct CategoriaAcomodacao *y);

void ModificarDadosAcomod(int z, int x, struct Acomodacoes *y);

void ModificarDadosProd(int z, int x, struct ProdutosHospedes *y);

void ModificarDadosFornec(int z, int x, struct Fornecedores *y);

void ModificarDadosOpe(int z, int x, struct OperadoresSistema *y);

int ExcluirDadosHospedes(int x, struct Hospede *y);

int ExcluirDadosCat(int x, struct CategoriaAcomodacao *y);

int ExcluirDadosAcomod(int x, struct Acomodacoes *y);

int ExcluirDadosProd(int x, struct ProdutosHospedes *y);

int ExcluirDadosFornec(int x, struct Fornecedores *y);

int ExcluirDadosOpe(int x, struct OperadoresSistema *y);

int VerificarCategoria(int countAc, int countCat, struct Acomodacoes *acomod, struct CategoriaAcomodacao *cat);

#ifdef __cplusplus
}
#endif

#endif /* GESTAODEDADOS_H */
