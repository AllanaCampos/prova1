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

static void listarPacientes(string crm, vector<Consulta > consultas){
            cout << "<_________PACIENTES COM CONSULTAS MARCADAS________>" << endl;
            for(auto c : consultas){
                if(c->getMedico()->getCRM() == crm){
                    cout << "Nome: " << c->getPaciente()->getNome() << endl;
                    cout << "CPF: " << c->getPaciente()->getCPF() << endl;
                    cout << "Data de nascimento: " << c->getPaciente()->getDtNascimento() << endl;
                }
            }
        }
        //verifica se existe consultas com o medico informado
        static bool existeConsulta(string crm, vector<Consulta> consultas){
            for(auto c : consultas){
                if(c->getMedico()->getCRM() == crm){
                    return true;
                }
            }
            return false;
        }
static void listarConsultas(vector<Consulta *> consultas){
            cout << "<----------Consultas realizadas---------->" << endl;
            for(auto c : consultas){
                if(c->getEfetuada() == 's'){
                    cout << "Medico: " << c->getMedico()->Nome() << endl;
                    cout << "Paciente: " << c->getPaciente()->getNome() << endl;
                    cout << "Data: ";
                    c->getData()->imprimirData();
                    cout << "Horario: " << c->getHorario()->getHora() << ":" << c->getHorario()->getMinuto() << endl;
                    cout << "Duracao: " << c->getTempConsulta() << endl;
                    cout << "Convenio: " << c->getConvenio() << endl;
                }
            }
            cout << "<----------Consultas nao realizadas---------->" << endl;
            for(auto c : consultas){
                if(c->getEfetuada() == 'n'){
                    cout << "Medico: " << c->getMedico()->getNome() << endl;
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

int main (){
    vector<Paciente *> pacientes;
    vector<Medico *> medicos;
    vector<Consulta *> consulta;

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