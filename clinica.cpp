#include <iostream>
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
                cout << "Digite o dia, o mes e o ano: " << endl;
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
    void setCPF(string _cpf){
        this->cpf = _cpf;
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
    static void addPaciente(vector<Paciente*> &pacientes){
        Paciente *p = new Paciente();
        string nome, cpf;
        Data * nascimento;
        cout <<"Digite o nome do paciente:" << endl;
        cin.ignore();
        getline(cin, nome);
        p->setNome(nome);
        do{
            cout <<"Digite o CPF do paciente com o seguinte formato: xxx.xxx.xxx-xx" << endl;
            getline(cin, cpf);
            p->setCPF(cpf);
        }while(!Paciente::validarCPF(cpf));
        cout << "Informe a data de nascimento. ";
        nascimento = Data::leData();
        p->setData(nascimento);
        pacientes.push_back(p);
    }
    static void deletePaciente(vector<Paciente *> &pacientes){
        string cpf;
        int pos;
        cout << "Digite o CPF do paciente que deve ser excluido" << endl;
        cin.ignore();
        getline(cin, cpf);
        pos = Paciente::getPosPaciente(cpf, pacientes);
        if(pos == -1){
            cout << "Paciente nao encontrado" << endl;
        }
        else{
            pacientes.erase(pacientes.begin() + pos);
            cout << "Paciente excluido" << endl;
        }
    }
    static void updatePaciente(vector<Paciente *> &pacientes){
        Paciente * alterado;
        string cpf, nome;
        char op;
        int pos;
        cout << "Digite o CPF do paciente que deve ser alterado" << endl;
        cin.ignore();
        getline(cin, cpf);
        pos = Paciente::getPosPaciente(cpf, pacientes);
        if(pos == -1){
            cout << "Paciente nao encontrado" << endl;
        }
        else{
            alterado = pacientes[pos];
            cout << "Nome: " << alterado->getNome() << endl;
            cout << "Data de nascimento: ";
            alterado->getData()->imprimirData();
            do{
                cout << "Deseja alterar o nome? (s/n)" << endl;
                cin >> op;
                if(op == 's'){
                    cout << "Digite o novo nome" << endl;
                    cin.ignore();
                    getline(cin, nome);
                    alterado->setNome(nome);
                }
            }while (op!='n' && op!='s');
            op = 'a';
            do{
                cout << "Deseja alterar a data de nascimento? (s/n)" << endl;
                cin >> op;
                if(op == 's'){
                    Data * data;
                    cout << "Digite a nova data. ";
                    data = Data::leData();
                    alterado->setData(data);
                }
            }while (op!='n' && op!='s');
        }
    }
    static bool validarCPF(string cpf){
        if(cpf.length() < 14){
            cout << "CPF invalido." << endl;
            return false;
        }
        for(int i = 0; i < int(cpf.length()); i++){
            if(i == 3 || i == 7){
                if(cpf[i]!= '.'){
                    cout << "CPF invalido." << endl;
                    return false;
                }
            }
            else if(i == 11){
                if(cpf[i] != '-'){
                    cout << "CPF invalido." << endl;
                    return false;
                }
            }
            else{
                if(!(cpf[i] >= '0' && cpf[i]<='9')){
                    cout << "CPF invalido." << endl;
                    return false;
                }
            }

        }
        return true;
    }
    static int getPosPaciente(string cpf, vector<Paciente * > pacientes){
            int pos = 0;
            for(Paciente * p : pacientes){
                if(p->getCPF() == cpf){
                    return pos;
                }
                pos++;
            }
            return -1;
        }
    static void locatePaciente(vector<Paciente * > pacientes){
        Paciente *encontrado;
        string cpf;
        int pos;
        cout << "Digite o CPF do paciente que deseja localizar" << endl;
        cin.ignore();
        getline(cin, cpf);
        pos = Paciente::getPosPaciente(cpf, pacientes);
        if(pos == -1){
            cout << "Paciente não encontrado" << endl;
        }
        else{
            encontrado = pacientes[pos];
            cout << "Nome: " << encontrado -> getNome() << endl;
            cout << "Data de nascimento: ";
            encontrado -> getData()-> imprimirData();
        }
    }
    static void listar(vector<Paciente*> pacientes){
        cout << "<__________PACIENTES CADASTRADOS__________>" << endl;
        for(auto p : pacientes){
            cout << "Nome: " << p -> getNome() << endl;
            cout << "CPF: " << p -> getCPF() << endl;
            cout << "Data de Nascimento: ";
            p ->getData()-> imprimirData();
        }
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

    static void addMedico(vector<Medico *> &medicos){
        Medico *m;
        string nome, especialidade, crm;
        cout <<"Digite o nome do medico:" << endl;
        cin.ignore();
        getline(cin, nome);
        cout <<"Digite o CRM do medico:" << endl;
        getline(cin, crm);
        cout << "Digite a especialidade do medico:" << endl;
        getline(cin, especialidade);
        m = new Medico(nome, crm, especialidade);
        medicos.push_back(m);
    }
    static void deleteMedico(vector<Medico *> &medicos){
        string crm;
        int pos;
        cout << "Digite o CRM do medico que deve ser excluido" << endl;
        cin.ignore();
        getline(cin, crm);
        pos = Medico::getPosMedico(crm, medicos);
        if(pos == -1){
            cout << "Medico nao encontrado" << endl;
        }
        else{
            medicos.erase(medicos.begin() + pos);
            cout << "Medico excluido" << endl;
        }
    }
    static void updateMedico(vector<Medico *> &medicos){
        Medico * alterado;
        string crm, nome, especialidade;
        char op;
        int pos;
        cout << "Digite o CRM do paciente que deve ser alterado" << endl;
        cin.ignore();
        getline(cin, crm);
        pos = Medico::getPosMedico(crm, medicos);
        if(pos == -1){
            cout << "Medico nao encontrado" << endl;
        }
        else{
            alterado = medicos[pos];
            cout << "Nome: " << alterado->Nome << endl;
            cout << "Especialidade: " << alterado->getEspecialidade() << endl;
            do{
                cout << "Deseja alterar o nome? (s/n)" << endl;
                cin >> op;
                if(op == 's'){
                    cout << "Digite o novo nome" << endl;
                    cin.ignore();
                    getline(cin, nome);
                    alterado->Nome = nome;
                }
            }while (op!='n' && op!='s');
            op = 'a';
            do{
                cout << "Deseja alterar a especialidade? (s/n)" << endl;
                cin >> op;
                if(op == 's'){
                    cout << "Digite a nova especialidade" << endl;
                    cin.ignore();
                    getline(cin, especialidade);
                    alterado->setEspecialidade(especialidade);
                }
            }while (op!='n' && op!='s');
        }
    }
    static int getPosMedico(string CRM, vector<Medico *> Medicos){
        int pos = 0;
        for(Medico * m : Medicos){
            if(m->getCRM() == CRM){
                return pos;
            }
            pos++;
        }
        return -1;
    }
    static void listar(vector<Medico *> Medicos){
        cout << "<____________MÉDICOS ENCONTRADOS____________>" << endl;
        for(auto m : Medicos){
            cout << "Nome: " << m->Nome << endl;
            cout << "CRM: " << m->getCRM() << endl;
            cout << "Especialidade: " << m->getEspecialidade() << endl;
        }
    }
    static void localizarMedico(vector<Medico *> Medicos){
        Medico *encontrado;
        string CRM;
        int pos;
        cout << "Digite o CRM do medico que deseja localizar:" << endl;
        cin.ignore();
        getline(cin >> ws, CRM);
        pos = Medico::getPosMedico(CRM, Medicos);
        if(pos == -1){
            cout << "Medico não encontrado" << endl;
        }
        else{
            encontrado = Medicos[pos];
            cout << "Nome: " << encontrado->Nome << endl;
            cout << "Especialidade: " << encontrado->getEspecialidade() << endl;
        }
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
        Data * data;
        Horario * horario;

    public:
        Consulta(){
            this->efetuada = 'n';
            this->convenio = "nenhum";
        }

        Data * getData(){
            return this->data;
        }
        void setData(Data * _data){
            this->data = _data;
        }
        Horario * getHorario(){
            return this->horario;
        }
        void setHorario(Horario * _horario){
           this->horario = _horario;
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
    
        static void addConsulta(vector<Paciente*> pacientes, vector<Medico*> medicos, vector<Consulta*> &consultas){
            int pos, tempo;
            char op;
            string cpf, crm, _convenio;
            Data *dataConsulta;
            Horario *horarioConsulta;
            Consulta * novaConsulta = new Consulta();
            cout << "Informe o CPF do paciente utilizando o formato a seguir: xxx.xxx.xxx-xx" << endl;
            cin >> cpf;
            pos = Paciente::getPosPaciente(cpf, pacientes);
            if(pos == -1){
                cout << "Paciente inexistente" << endl;
                return;
            }
            novaConsulta->setPaciente(pacientes[pos]);
            cout << "Informe o CRM do medico" << endl;
            cin >> crm;
            pos = Medico::getPosMedico(crm, medicos);
            if( pos == -1){
                cout << "Medico inexistente" << endl;
                return;
            }
            novaConsulta->setMedico(medicos[pos]);
            cout << "Informe a data da consulta. ";
            dataConsulta = Data::leData();
            novaConsulta->setData(dataConsulta);
            cout << "Informe o horario da consulta. ";
            horarioConsulta = Horario::leHorario();
            novaConsulta->setHorario(horarioConsulta);
            cout << "Informe a duracao da consulta em minutos" << endl;
            cin >> tempo;
            novaConsulta->setTempConsulta(tempo);
            cout << "Possui convenio?" << endl;
            cin >> op;
            if(op == 's'){
                cout << "Informe o convenio" << endl;
                cin >> _convenio;
                novaConsulta->setConvenio(_convenio);
            }
            consultas.push_back(novaConsulta);
        }
        static void deleteConsulta(vector<Consulta *> &consultas){
            int pos;
            string crm, cpf;
            cout << "Informe o CRM do medico responsavel pela consulta" << endl;
            cin >> crm;
            if(!Consulta::existeConsulta(crm, consultas)){
                cout << "Nao foi possivel encontrar consultas com este medico" << endl;
                return;
            }
            Consulta::listarPacientes(crm, consultas);
            cout << "Informe o CPF do paciente" << endl;
            cin >> cpf;
            pos = Consulta::getPosPaciente(cpf, crm, consultas);
            if(pos == -1){
                cout << "Paciente nao encontrado" << endl;
                return;
            }
            consultas.erase(consultas.begin() + pos);

        }
        static void updateConsulta(vector<Consulta *> &consultas){
            int pos;
            string crm, cpf;
            char opcao;
            cout << "Informe o CRM do medico responsavel pela consulta" << endl;
            cin >> crm;
            if(!Consulta::existeConsulta(crm, consultas)){
                cout << "Nao foi possivel encontrar consultas com este medico" << endl;
                return;
            }
            Consulta::listarPacientes(crm, consultas);
            cout << "Informe o CPF do paciente" << endl;
            cin >> cpf;
            pos = Consulta::getPosPaciente(cpf, crm, consultas);
            if(pos == -1){
                cout << "Paciente nao encontrado" << endl;
                return;
            }
            cout << "Deseja registrar a consulta como realizada? (s/n)" << endl;
            cin >> opcao;
            if(opcao == 's'){
                consultas[pos]->setEfetuada('s');
            }
            if(opcao == 'n'){
                cout << "Deseja alterar a data da consulta? (s/n)" << endl;
                cin >> opcao;
                if(opcao == 's'){
                    Data * novaData;
                    cout << "Informe a nova data. "; 
                    novaData = Data::leData();
                    consultas[pos]->setData(novaData);
                }
                cout << "Deseja alterar o horario da consulta? (s/n)" << endl;
                cin >> opcao;
                if(opcao == 's'){
                    Horario * novoHorario;
                    cout << "Informe o novo horario. "; 
                    novoHorario = Horario::leHorario();
                    consultas[pos]->setHorario(novoHorario);
                }
                cout << "Deseja alterar a duracao da consulta? (s/n)" << endl;
                cin >> opcao;
                if(opcao == 's'){
                    int tempo;
                    cout << "Informe a nova duracao da consulta" << endl; 
                    cin >> tempo;
                    consultas[pos]->setTempConsulta(tempo);
                }
                cout << "Deseja alterar o convenio da consulta? (s/n)" << endl;
                cin >> opcao;
                if(opcao == 's'){
                    string novoConvenio;
                    cout << "Informe o novo convenio" << endl;
                    cin >> novoConvenio; 
                    consultas[pos]->setConvenio(novoConvenio);
                }

            }
        }
        static int getPosPaciente(string cpf, string crm, vector<Consulta *> consultas){
            int pos = 0;
            for(auto c : consultas){
                if(c->getMedico()->getCRM() == crm){
                    if(c->getPaciente()->getCPF() ==cpf){
                        return pos;
                    }
                }
                pos ++;
            }
            return -1;
        }
        static void listarPacientes(string crm, vector<Consulta *> consultas){
            cout << "_________PACIENTES COM CONSULTAS MARCADAS________" << endl;
            for(auto c : consultas){
                if(c->getMedico()->getCRM() == crm){
                    cout << "Nome: " << c->getPaciente()->getNome() << endl;
                    cout << "CPF: " << c->getPaciente()->getCPF() << endl;
                    cout << "Data de nascimento: " << c->getPaciente()->getData() << endl;
                }
            }
        }
        //verifica se existe consultas com o medico informado
        static bool existeConsulta(string crm, vector<Consulta *> consultas){
            for(auto c : consultas){
                if(c->getMedico()->getCRM() == crm){
                    return true;
                }
            }
            return false;
        }
        static void listarConsultas(vector<Consulta *> consultas){
            cout << "_________CONSULTAS REALIZADAS_________" << endl;
            for(auto c : consultas){
                if(c->getEfetuada() == 's'){
                    cout << "Medico: " << c->getMedico()->Nome << endl;
                    cout << "Paciente: " << c->getPaciente()->getNome() << endl;
                    cout << "Data: ";
                    c->getData()->imprimirData();
                    cout << "Horario: " << c->getHorario()->getHora() << ":" << c->getHorario()->getMinuto() << endl;
                    cout << "Duracao: " << c->getTempConsulta() << endl;
                    cout << "Convenio: " << c->getConvenio() << endl;
                }
            }
            cout << "_________CONSULTAS NAO REALIZADAS__________" << endl;
            for(auto c : consultas){
                if(c->getEfetuada() == 'n'){
                    cout << "Medico: " << c->getMedico()->Nome << endl;
                    cout << "Paciente: " << c->getPaciente()->getNome() << endl;
                    cout << "Data: ";
                    c->getData()->imprimirData();
                    cout << "Horario: " << c->getHorario()->getHora() << ":" << c->getHorario()->getMinuto() << endl;
                    cout << "Duracao: " << c->getTempConsulta() << endl;
                    cout << "Convenio: " << c->getConvenio() << endl;
                }
            }
        }

};

void menuPacientes(vector<Paciente *> &pacientes);
void menuMedicos(vector<Medico *> &medicos);
void menuConsultas(vector<Paciente *> pacientes, vector<Medico *> medicos, vector<Consulta *> &consultas);

int main (){
    vector<Paciente *> pacientes;
    vector<Medico *> medicos;
    vector<Consulta *> consultas;

    int opcao;
    do{
        cout << "_____________MENU_____________" << endl;
        cout << "1. Gestao de Pacientes" << endl;
        cout << "2. Gestao de Medicos" << endl;
        cout << "3. Gestao de Consultas" << endl;
        cout << "0. Sair" << endl;
        cin >> opcao;

        switch (opcao){
        case 1:
            menuPacientes(pacientes);
            break;
        case 2:
            menuMedicos(medicos);
            break;
        case 3:
            menuConsultas(pacientes, medicos, consultas);
            break;
        }
    }while (opcao != 0);
    return 0;
}

void menuPacientes(vector<Paciente*> &pacientes){
    int opcao;
    do{
        cout << "__________GESTAO DE PACIENTES__________" << endl;
        cout << "1- Incluir" << endl;
        cout << "2- Excluir" << endl;
        cout << "3- Alterar" << endl;
        cout << "4- Listar" << endl;
        cout << "5- Localizar" << endl;
        cout << "0- Sair" << endl;

        cin >> opcao;

        switch (opcao){
        case 1:
            Paciente::addPaciente(pacientes);
            break;
        case 2:
            Paciente::deletePaciente(pacientes);
            break;
        case 3:
            Paciente::updatePaciente(pacientes);
            break;
        case 4:
            Paciente::listar(pacientes);
            break;
        case 5:
            Paciente::locatePaciente(pacientes);
            break;
        }

    }while(opcao != 0);
}
void menuMedicos(vector<Medico*> &medicos){
    int opcao;
    do{
        cout << "__________GESTAO DE MEDICOS__________" << endl;
        cout << "1- Incluir" << endl;
        cout << "2- Excluir" << endl;
        cout << "3- Alterar" << endl;
        cout << "4- Listar" << endl;
        cout << "5- Localizar" << endl;
        cout << "0- Sair" << endl;

        cin >> opcao;

        switch (opcao){
        case 1:
            Medico::addMedico(medicos);
            break;
        case 2:
            Medico::deleteMedico(medicos);
            break;
        case 3:
            Medico::updateMedico(medicos);
            break;
        case 4:
            Medico::listar(medicos);
            break;
        case 5:
            Medico::localizarMedico(medicos);
            break;
        }

    }while(opcao != 0);
}
void menuConsultas(vector<Paciente *> pacientes, vector<Medico *> medicos, vector<Consulta *> &consultas){
    int opcao;
    do{
        cout << "__________GESTAO DE CONSULTAS__________" << endl;
        cout << "1- Incluir" << endl;
        cout << "2- Excluir" << endl;
        cout << "3- Alterar" << endl;
        cout << "4- Listar" << endl;
        cout << "0- Sair" << endl;

        cin >> opcao;

        switch (opcao){
        case 1:
            Consulta::addConsulta(pacientes, medicos, consultas);
            break;
        case 2:
            Consulta::deleteConsulta(consultas);
            break;
        case 3:
            Consulta::updateConsulta(consultas);
            break;
        case 4:
            Consulta::listarConsultas(consultas);
            break;
        }

    }while(opcao != 0);
}
