
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Paciente {
private:

    string nome, cpf, convenio; 
    int dia, mes, ano;

public:
    void setNome(string _Nome){
        nome = _Nome;
    }
    string getNome(){
        return nome;
    }
    string getCPF(){
        return cpf;
    }
    void setData (int _dia, int _mes, int _ano){
        dia = _dia;
        mes = _mes;
        ano = _ano;
    }
    string getData(){
       return to_string(dia)+"/"+to_string(mes)+"/"+to_string(ano);
    }
    

Paciente(){
    cout << "Digite um nome: " << endl;
    cin.ignore();
    getline(cin, nome);
    cout << "Digite o CPF: " << endl;
    cin >> cpf;
    cout <<"Digite a data de nascimento:" << endl;
    cin >> dia >> mes >> ano;
}
};