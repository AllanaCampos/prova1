#include <iostream>
#include <string>
#include <vector>
#include <ctime>

using namespace std;

class Data{
    private:

        int Dia;
        int Mes;
        int Ano;

    public:
        void setDia(int _Dia){
            this->Dia = _Dia;
        }
        int getDia(){
            return this->Dia;
        }
        void setMes(int _Mes){
            this->Mes = _Mes;
        }
        int getMes(){
            return this->Mes;
        }
        void setAno(int _Ano){
            this->Ano = _Ano;
        }
        int getAno(){
            return this->Ano;
        }
        void imprimirData(){
            cout << this->Dia << "/" << this->Mes << "/" << this->Ano << endl;
        }
        static bool dataValida(Data * _Data){
            if ((_Data->Mes < 1) || (_Data->Mes > 12)) 
                return false; 
            int diaMax = 31; 
            if(_Data->Mes == 2){ 
                diaMax = 28; 
                if(_Data->Ano%4==0) 
                    diaMax = 29; 
            }
            if((_Data->Mes == 4) || (_Data->Mes == 6) || (_Data->Mes == 9) || (_Data->Mes == 11)) 
                diaMax = 30; 
            if((_Data->Dia >= 1) && (_Data->Dia <= diaMax)) 
                return true; 
            else return false; 

        }

        static Data *leData(){
            Data * novaData = new Data(); 
            int _Dia, _Mes, _Ano; 
            do {
                cout << "Digite o dia, o mês e o ano: " << endl;
                cin >> _Dia >> _Mes >> _Ano; 
                novaData->setDia(_Dia); 
                novaData->setMes(_Mes);
                novaData->setAno(_Ano);
            } while(!Data::dataValida(novaData)); 
            return novaData; 
        }
};

class Paciente {

private:

    string nome, cpf, convenio; 
    Data * dataNasc;

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
    Data * getData(){
        return this->dataNasc;
    }
    void setData(Data * _data){
         this -> dataNasc = _data;
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


class Horario{
    private:

        int hora;
        int minuto;

    public:
        int getHora(){
            return this -> hora;
        }
        void setHora(int _hora){
            this-> hora = _hora;
        }
        int getMinuto(){
            return this->minuto;
        }
        void setMinuto(int _minuto){
            this->minuto = _minuto;
        }
        static Horario * leHorario(){
            Horario * novoHorario = new Horario(); 
            int _hora, _minuto; 
            do {
                cout << "Digite a hora e os minutos: " << endl;
                cin >> _hora >> _minuto; 
                novoHorario->setHora(_hora); 
                novoHorario->setMinuto(_minuto);
            } while(!Horario::horarioValido(novoHorario)); 
            return novoHorario; 
        }
        static bool horarioValido(Horario * horario){
            if(horario->getHora() < 0 || horario->getHora() > 23){
                cout << "Horario invalido" << endl;
                return false; 
            }
            if(horario->getMinuto() < 0 || horario->getMinuto() > 59){
                cout << "Horario invalido" << endl;
                return false;
            }
            return true;
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

