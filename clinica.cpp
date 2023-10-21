
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

class Medico{
    string CRM;
    string Especialidade;

    public:
    string Nome;
   
    Medico(string _Nome, string _CRM, string _Especialidade){
        this -> Nome=_Nome;
        this -> setCRM(_CRM);
        this -> setEspecialidade(_Especialidade);
    }

    string getCRM(){
        return this -> CRM;
    }

    void setCRM(string _CRM){

        this->CRM = _CRM;
    }

    string getEspecialidade(){
        return this -> Especialidade;
    }

    void setEspecialidade(string _Especialidade){

        this -> Especialidade = _Especialidade;
    }

};

class Consulta{
    private:

        char efetuada;
        int tempConsulta;
        string convenio;
        Paciente * paciente;
        Medico * medico;

    public:
        Consulta(){
            this->efetuada = 'n';
            this->convenio = "nenhum";
        }
        char getEfetuada(){
            return this->efetuada;
        }
        void setEfetuada(char _efetuada){
            this->efetuada = _efetuada;
        }
        int getTempConsulta(){
            return this->tempConsulta;
        }
        void setTempConsulta(int _tempConsulta){
            this->tempConsulta = _tempConsulta;
        }
        string getConvenio(){
            return this->convenio;
        }
        void setConvenio(string _convenio){
            this->convenio = _convenio;
        }
        Paciente * getPaciente(){
            return this->paciente;
        }
        void setPaciente(Paciente * _paciente){
            this->paciente = _paciente;
        }
        Medico * getMedico(){
            return this->medico;
        }
        void setMedico(Medico * _medico){
            this->medico = _medico;
        }
};

int main (){
    vector<Paciente *> pacientes;
    vector<Medico *> medicos;

    int opcao;
    do{
        cout << "_____________MENU_____________" << endl;
        cout << "1. Gestão de Pacientes" << endl;
        cout << "2. Gestão de Medicos" << endl;
        cout << "3. Gestão de Consultas" << endl;
        cout << "0. Sair" << endl;
        cin >> opcao;

        switch (opcao){
        case 1:
            break;

        case 2:
            break;

        case 3:
            break;
        }
    }while (opcao != 0);
    return 0;
}