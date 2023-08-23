cpp
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <random>
#include <algorithm>
#include <limits>

using namespace std;

// Definição da estrutura que representa uma pergunta
struct Question {
    string question;         // A pergunta em si
    vector<string> options;  // Opções de resposta
    int correctOption;       // Índice da opção correta
};

// Definição da estrutura que representa uma equipe
struct Team {
    string name;  // Nome da equipe
    int score;    // Pontuação da equipe

    Team(const string& _name) : name(_name), score(0) {}  // Construtor
};

// Função para exibir uma pergunta na saída padrão
void displayQuestion(const Question& q) {
    cout << q.question << endl;
    for (size_t i = 0; i < q.options.size(); i++) {
        cout << i + 1 << ". " << q.options[i] << endl;
    }
}

// Função para verificar se a resposta do jogador está correta
bool checkAnswer(int playerAnswer, const Question& q) {
    return playerAnswer == q.correctOption;
}

int main() {
    // Inicialização da semente para geração de números aleatórios
    srand(static_cast<unsigned int>(time(nullptr)));

    // Criação das equipes
    vector<Team> teams;
    teams.emplace_back("Grupo 1");
    teams.emplace_back("Grupo 2");
    teams.emplace_back("Grupo 3");

    // Criação das perguntas
    vector<Question> questions = {
        {"Qual é o tipo de dado usado para armazenar números inteiros?",
         {"a) long", "b) float", "c) char", "d) int"},
         4},
        {"Qual é a função usada para ler dados do usuário?",
         {"a) input()", "b) scanf()", "c) cout", "d) print()"},
         2},
         {"Qual operador é usado para realizar uma comparação?",
         {"a) =", "b) +", "c) ==", "d) *"},
         3},
         {"Qual desses símbolos é usado para destacar um comentário de múltiplas linhas?";
         {"a) long", "b) float", "c) char", "d) int" },
         4},
    }

    int choice = 0;
    while (choice != 5) {
        // Exibição do menu principal
        cout << "========================================" << endl;
        cout << "1. 'Grupo 1'" << endl;
        cout << "2. 'Grupo 2'" << endl;
        cout << "3. 'Grupo 3'" << endl;
        cout << "4. 'Ver Pontuação'" << endl;
        cout << "5. 'Sair'" << endl;
        cout << "Escolha uma opção: ";
        cout << "========================================" << endl;

        // Leitura e validação da escolha do usuário
        while (!(cin >> choice) || choice < 1 || choice > 5) {
            cout << "Opção inválida. Escolha novamente: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        if (choice >= 1 && choice <= 3) {
            int groupChoice = choice - 1;

            int totalRounds = 1;
            int totalQuestionsPerRound = 4;

            // Exibição do cabeçalho da rodada
            cout << "-----------------------------------------" << endl;
            cout << "Rodada - " << teams[groupChoice].name << endl;

            // Embaralhamento das perguntas para cada rodada
            random_device rd;
            mt19937 g(rd());
            shuffle(questions.begin(), questions.end(), g);

            // Loop para exibir e processar perguntas da rodada
            for (int questionIndex = 0; questionIndex < totalQuestionsPerRound; ++questionIndex) {
                const Question& currentQuestion = questions[questionIndex];

                cout << "Pergunta " << questionIndex + 1 << ":" << endl;
                displayQuestion(currentQuestion);

                int playerAnswer;

                // Loop para receber uma resposta válida do jogador
                while (true) {
                    cout << "Digite a opção correta (1, 2, 3, ...): ";
                    while (!(cin >> playerAnswer)) {
                        cout << "Entrada inválida. Digite novamente: ";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }

                    // Verificação e processamento da resposta
                    if (playerAnswer >= 1 && playerAnswer <= currentQuestion.options.size()) {
                        if (checkAnswer(playerAnswer, currentQuestion)) {
                            teams[groupChoice].score++;
                            cout << "Resposta correta! Pontuação atual de " << teams[groupChoice].name << ": " << teams[groupChoice].score << endl;
                        } else {
                            cout << "Resposta incorreta!" << endl;
                        }
                        break; // Avança para a próxima pergunta
                    } else {
                        cout << "Opção inválida. Digite novamente: ";
                    }
                }
            }

            cout << "-----------------------------------------" << endl;
        } else if (choice == 4) {
            // Exibição da pontuação atual das equipes
            cout << "Pontuação atual:" << endl;
            for (const Team& team : teams) {
                cout << team.name << ": " << team.score << endl;
            }
        } else if (choice == 5) {
            // Mensagem de saída do programa
            cout << "Saindo do programa." << endl;
        } else {
            // Mensagem de opção inválida
            cout << "Opção inválida. Escolha novamente." << endl;
        }
    }

    return 0;
}