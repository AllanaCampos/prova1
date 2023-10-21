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