#include <iostream>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>

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

std::string gerar_email(std::string nome, std::string sobrenome)
{

    std::string email = nome + '.' + sobrenome + '@';
    std::replace(email.begin(), email.end(), ' ', '.');

    switch (rand() % 8)
    {
    case 0:
        email += "gmail.com";
        break;
    case 1:
        email += "outlook.com";
        break;
    case 2:
        email += "hotmail.com";
        break;
    case 3:
        email += "live.com";
        break;
    case 4:
        email += "msn.com";
        break;
    case 5:
        email += "yahoo.com";
        break;
    case 6:
        email += "ymail.com";
        break;
    case 7:
        email += "aol.com";
        break;
    }
    return email;
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

    int quantidade = 0;
    std::cout << "quantos registros vc quer gerar? : ";
    std::cin >> quantidade;

    for (int i = 0; i < quantidade; i++)
    {
        std::string nome = gerar_nome();
        std::string sobrenome = gerar_sobrenome();
        std::string email = gerar_email(nome, sobrenome);

        std::cout << "(\"" << nome << "\",\"" << sobrenome << "\"," << gerar_cpf() << ",\"ENDERECO\",\"" << email << "\"," << gerar_data_nascimento() << "),\n";

        //("haru","lourenco",19516113737,"rua da cruz , barreto , niteroi RJ" , "joao.sobreira.vieira@gmail.com" , 2000-08-20),
    }

    std::cin >> quantidade;
}