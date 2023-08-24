#include <iostream>
#include <string>
#include <vector>
#include <limits>

using namespace std;

// Representação da pergunta
struct Question {
    string question;
    vector<string> options;
    int correctOption;
};

// Define a equipe
struct Team {
    string name;
    int score;

    Team(const string& _name) : name(_name), score(0) {}
};

// Exibir uma pergunta na saída padrão
void displayQuestion(const Question& q) {
    cout << q.question << endl;
    for (size_t i = 0; i < q.options.size(); i++) {
        cout << char('a' + i) << ") " << q.options[i] << endl;
    }
}

// Verifica se a resposta do jogador está correta
bool checkAnswer(int playerAnswer, const Question& q) {
    return playerAnswer == q.correctOption;
}

int main() {
    // Criando as equipes
    vector<Team> teams;
    teams.emplace_back("Grupo 1");
    teams.emplace_back("Grupo 2");
    teams.emplace_back("Grupo 4");

    // Criação das perguntas
    vector<vector<Question>> groupQuestions = {
        // Grupo 1
        {
            {"Qual e o simbolo usado para iniciar um comentario de uma linha em C++?",
             {"//", "/*", "<!--", "--"},
             0},
            {"Qual e a saida padrao em C++?",
             {"input()", "console.log()", "cout", "print()"},
             2},
            {"Qual e a finalidade de usar a palavra-chave `cin` em C++?",
             {"Imprimir mensagens na tela", "Ler entradas do usuario a partir do teclado", "Realizar calculos complexos", "Definir uma funcao"},
             0},
            {"Qual operador e usado para realizar uma comparacao de desigualdade?",
             {"!=", "==", "<=", ">="},
             0},
        },
        // Grupo 2
        {
            {"O que e um loop em C++ e qual e a sua finalidade?",
             {"Um tipo de dado para armazenar multiplos valores", "Uma declaracao que define uma classe", "Uma estrutura que permite a execucao repetida de um bloco de codigo", "Uma funcao para imprimir valores na tela"},
             2},
            {"Qual operador e usado para realizar uma comparacao?",
             {"=", "+", "==", "*"},
             2},
            {"Explique a diferenca entre um array e um vetor em C++",
             {"Nao ha diferenca; são termos intercambiaveis", "Arrays sao usados para armazenar valores do mesmo tipo, enquanto vetores armazenam tipos diferentes", "Vetores sao usados para armazenar valores do mesmo tipo, enquanto arrays podem armazenar tipos diferentes", "Arrays sao mais eficientes que vetores na alocacao de memoria"},
             0},
            {"O que e uma funcao em C++ e por que ela e util?",
             {"Uma variavel global que pode ser acessada de qualquer lugar", "Um trecho de codigo que nao pode ser reutilizado", "Uma instrucao que define um loop", "Um bloco de codigo que realiza uma tarefa especifica e pode ser reutilizado"},
             3},
        },
        // Grupo 4
        {
            {"Qual e a principal vantagem de utilizar vetores na programacao?",
             {"Armazenamento de Dados", "Manipulacao de Dados", "Flexibilidade", "Controle de Fluxo"},
             0},
            {"O que um bloco de codigo delimitado por chaves ({}) em C++ representa?",
             {"Uma declaracao de variavel", "Um comentario", "Um loop infinito", "Um escopo de codigo"},
             3},
            {"Qual e a funcao da biblioteca <cstdlib> em C++?",
             {"Manipular strings", "Controlar estruturas de repeticao", "Realizar operacoes matematicas", "Fornecer funcoes para gerar números aleatorios"},
             3},
            {"Qual e o operador usado para acessar o valor armazenado em um vetor em C++?",
             {":", "*", "->", "[]"},
             3},
        }
    };

    int choice = 0;
    while (true) {
        cout << "========================================" << endl;
        cout << "1. Grupo 1" << endl;
        cout << "2. Grupo 2" << endl;
        cout << "3. Grupo 4" << endl;
        cout << "4. Ver Pontuacao" << endl;
        cout << "5. Sair" << endl;
        cout << "Escolha uma opcao: ";

        while (!(cin >> choice)) {
            cout << "Digite um numero valido: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        cout << "========================================" << endl;

        if (choice >= 1 && choice <= 3) {
            int groupChoice = choice - 1;
            const vector<Question>& groupQuestionsList = groupQuestions[groupChoice];

            cout << "----------------------------------------" << endl;
            cout << "Rodada - " << teams[groupChoice].name << endl;

            for (int questionIndex = 0; questionIndex < groupQuestionsList.size(); ++questionIndex) {
                const Question& currentQuestion = groupQuestionsList[questionIndex];

                cout << "Pergunta " << questionIndex + 1 << ":" << endl;
                displayQuestion(currentQuestion);

                int playerAnswer;
                string userResponse;

                while (true) {
                    cout << "Digite a opcao correta: ";
                    cin >> userResponse;

                    char responseChar = tolower(userResponse[0]);

                    if (responseChar >= 'a' && responseChar <= 'd') {
                        playerAnswer = responseChar - 'a';
                        break;
                    } else {
                        cout << "Digite uma opcao valida." << endl;
                    }
                }

                if (checkAnswer(playerAnswer, currentQuestion)) {
                    teams[groupChoice].score++;
                    cout << "Resposta correta! Pontuacao atual de " << teams[groupChoice].name << ": " << teams[groupChoice].score << endl;
                } else {
                    cout << "Resposta incorreta!" << endl;
                }
            }

            cout << "----------------------------------------" << endl;
        } else if (choice == 4) {
            cout << "Pontuacao atual:" << endl;
            for (const Team& team : teams) {
                cout << team.name << ": " << team.score << endl;
            }
        } else if (choice == 5) {
            cout << "Saindo do programa." << endl;
            break;
        } else {
            cout << "Opcao invalida. Escolha novamente." << endl;
        }
    }

    cout << "-----------------------------------------" << endl;
    cout << "Pontuacao total:" << endl;
    for (const Team& team : teams) {
        cout << team.name << ": " << team.score << endl;
    }

    return 0;
}
