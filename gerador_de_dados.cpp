#include <iostream>
#include <string>
#include <iostream>
#include <fstream>

std::string gerar_cpf()
{
    std::string cpf = "";
    for (int i = 0; i <= 10; i++)
        cpf += std::to_string(rand() % 10);

    return cpf;
}

std::string gerar_nome()
{
    std::ifstream nomes;

    if (rand() % 2 == 0) // fem
        nomes.open("ibge-fem-10000.txt");
    else // mas
        nomes.open("ibge-mas-10000.txt");

    int linha = rand() % 10000;

    std::string nome = "";
    for (int i = 0; i < linha; i++)
    {
        std::getline(nomes, nome);
    }
    getline(nomes, nome);

    nomes.close();
    return nome;
}

std::string gerar_sobrenome()
{
    std::ifstream sobrenomes("sobrenomes.txt");

    int sobrenome_num = rand() % 254;
    std::string sobrenome = "";

    int x = 0;
    while (x < sobrenome_num)
    {
        std::getline(sobrenomes, sobrenome);
        x++;
    }
    std::getline(sobrenomes, sobrenome);

    sobrenomes.close();

    return sobrenome;
}

std::string gerar_data_nascimento()
{
    std::string ano = std::to_string((rand() % 74) + 1950);

    bool umdigito = false;

    std::string mes = "";
    int mes_n = (rand() % 12) + 1;
    if (mes_n < 10)
        umdigito = true;
    if (umdigito == true)
        mes = '0' + std::to_string(mes_n);
    else
        mes = std::to_string(mes_n);

    umdigito = false;
    std::string dia = "";
    int dia_n = (rand() % 30) + 1;
    if (dia_n < 10)
        umdigito = true;
    if (umdigito == true)
        dia = '0' + std::to_string(dia_n);
    else
        dia = std::to_string(dia_n);

    return ano + "-" + mes + "-" + dia;
}

int main()
{
    srand((unsigned)time(NULL));

    for (int i = 0; i < 100; i++)
    {
        std::cout << "nome: " << gerar_nome() << " " << gerar_sobrenome() << " cpf: " << gerar_cpf() << " data nascimento : " << gerar_data_nascimento() << "\n";
    }
}