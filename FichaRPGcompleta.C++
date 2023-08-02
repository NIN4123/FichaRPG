#include <iostream>
#include <string>
#include <locale>
using namespace std;


bool contemApenasLetrasESpacos(const std::string& str) {
    for (char c : str) {
        if (!isalpha(c) && !isspace(c)) {
            return false;
        }
    }
    return true;
}

bool contemApenasCaracteresPermitidos(const std::string& str) {
    return true;
}

int main() {

    std::locale::global(std::locale("pt_BR.UTF-8"));
    std::cout.imbue(std::locale()); // para declarar a lingua portuguesa no código


 // introduzir ao jogador o contexto e a história do RPG
    cout << "\nO universo de Ordem Paranormal se passa em um mundo onde existem duas dimensões: o Normal e o Paranormal. O Normal é onde nós vivemos como humanos, enquanto o Paranormal é um lugar completamente diferente, onde tudo que parece impossível pode se tornar real, o que normalmente estaria associado a espíritos, demônios, entre outros tipos de anormalidades ligadas ao pós vida, por exemplo." << endl;
    cout << "\nEsses dois locais são divididos por uma camada chamada de Membrana, que impede que o Normal e o Paranormal entrem em contato. No entanto, essa Membrana pode se enfraquecer com o aumento do medo do sobrenatural, levando monstros horrendos e muito perigosos a invadirem nossa realidade. Esse fenômeno geralmente ocorre em locais bem específicos, propensos à percepção de medo, como hospitais abandonados, casas antigas e sanatórios desativados." << endl;
    cout << "\nAo redor do mundo inteiro diversos grupos se formaram, buscando enfraquecer a Membrana o máximo possível, a fim de destruí-la e levar à fusão das dimensões, com o objetivo de buscar seus próprios desejos ou, quem sabe, cumprindo um propósito maior. Os membros desses grupos são chamados de Ocultistas (nessa época, Esoterroristas)." << endl;
    cout << "\nPara impedir que o caos se instale, uma organização global secreta foi criada: a Ordo Realitas (\"Ordem da Realidade\", nessa época chamada de Ordo Veritatis, \"Ordem da Verdade\"). Pessoas comuns que vivem vidas duplas para impedir os atos Ocultistas, que têm como objetivo o aumento do contato entre a população com o paranormal, aumentando seu medo e, consequentemente, enfraquecendo a membrana e permitindo a interferência do paranormal." << endl;


 // Pergunta se o jogador deseja se juntar à Ordo Realitas e verifica a resposta.
   char confirmacaoInicial;
    std::cout << "Está pronta(o) para enfrentar o paranormal, lutar contra o outro lado, impedir que o caos reine nessa dimensão, se juntando à Ordo Realitas? (S/N) ";
    std::cin >> confirmacaoInicial;

    if (toupper(confirmacaoInicial) == 'S') {
        std::cout << "\nVocê está oficialmente preparado(a) para se juntar à Ordo Realitas! Bem-vindo(a) Agente!" << std::endl;
    } else {
        std::cout << "\nEscolha cancelada. Seu personagem ainda não está preparado para enfrentar os desafios da Ordem. Talvez em uma próxima aventura!" << std::endl;
        return 0; // Encerra o programa imediatamente caso a escolha seja 'N'.
    }


   // Obtenção do nome do personagem, verificando se é uma entrada válida.
    string nomeEpico;
    
    // Obtenção da idade do personagem, verificando se é uma entrada válida.
    string idadeStr;

    // Obter o nome épico, garantindo que não seja vazio
    do {
        cout << "Qual nome seus parceiros irão te chamar? ";
        getline(cin, nomeEpico);

        if (nomeEpico.empty()) {
            cout << "Você precisa digitar um nome épico." << endl;
        } else if (!contemApenasLetrasESpacos(nomeEpico)) {
            cout << "O nome não pode conter números ou caracteres especiais. Tente novamente." << endl;
        }
    } while (nomeEpico.empty() || !contemApenasLetrasESpacos(nomeEpico));

    cout << "Seus parceiros irão te chamar de: " << nomeEpico << endl;
    // Loop para verificar a entrada válida da idade
    do {
        cout << "Qual a idade de " << nomeEpico << "? ";
        getline(cin, idadeStr);

        if (idadeStr.empty()) {
            cout << "Você precisa digitar uma idade. Tente novamente." << endl;
            continue;
        }

        bool apenasNumeros = true;
        for (char c : idadeStr) {
            if (!isdigit(c)) {
                apenasNumeros = false;
                break;
            }
        }

        if (!apenasNumeros) {
            cout << "A idade deve conter apenas números. Tente novamente." << endl;
            continue;
        }

        // Verifica se a idade não é um número positivo
        if (stoi(idadeStr) <= 0) {
            cout << "A idade deve ser um número positivo. Tente novamente." << endl;
            continue;
        }
        // Se chegou aqui, a idade é válida.
        break;

    } while (true);

    std::string historia; // feito para o jogador escrever a história do personagem criado
    std::cout << "\nConte-nos a história de " << nomeEpico << ". De onde ele vem, quais desafios enfrentou e como chegou à Ordem? ";
    std::getline(std::cin, historia); 

    std::cout << "\nHistória do personagem: " << historia << std::endl;

    std::string aparencia; // feito para o jogador escrever a aparência do personagem criado
    cout << "\nDescreva-nos alguns detalhes marcantes que o tornam inconfundível, seja um olhar penetrante, uma cicatriz intrigante ou um estilo de vestimenta singular: ";
    getline(cin, aparencia);

    cout << "\nAparência do personagem: " << aparencia << endl;

    std::string personalidade; // o jogador deve inserir a personalidade do personagem criado
    std::cout << "\nDescreva brevemente a personalidade do seu personagem. Quais são os traços que o definem e o tornam especial? ";
    std::getline(std::cin, personalidade);

    std::cout << "\nPersonalidade do personagem: " << personalidade << std::endl;

    int origem;
    // escolher a origem do personagem, qual a ocupaçao que ele ocupava antes de entrar para a Ordem
    std::string descricaoOrigem;

    do {
        std::cout << "\nConte-nos o que você fazia antes de entrar para a Ordem: (1-Abastado, 2-Acadêmico, 3-Agente da Saúde, 4-Artista, 5-Atleta, 6-Camponês, 7-Exorcista, 8-Detetive, 9-Criminoso, 10-T.I, 11-Policial, 12-Mercenário) ";
        std::cin >> origem;

        switch (origem) {
            case 1:
                descricaoOrigem = "\nAbastado: Você é membro de alguma família importante ou dono de recursos que te fazem ter dinheiro.";
                break;
            case 2:
                descricaoOrigem = "\nAcadêmico: Estudioso de algum campo do conhecimento, podendo ser professor ou pesquisador universitário.";
                break;
            case 3:
                descricaoOrigem = "\nAgente da Saúde: Profissional da saúde como enfermeiro, médico ou socorrista.";
                break;
            case 4:
                descricaoOrigem = "\nArtista: Profissional das artes como músico, ator, pintor, etc.";
                break;
            case 5:
                descricaoOrigem = "\nAtleta: Profissional de algum time ou federação esportiva, como nadadores olímpicos ou jogadores de futebol.";
                break;
            case 6:
                descricaoOrigem = "\nCamponês: Vive no campo, fazenda ou uma pequena comunidade agrícola.";
                break;
            case 7:
                descricaoOrigem = "\nExorcista: Sacerdote ou devoto religioso dedicado a confrontar e expulsar forças sobrenaturais que prejudicam as pessoas, independentemente da religião que pratica.";
                break; 
            case 8:
                descricaoOrigem = "\nDetetive: Investigador, seja parte de uma força policial ou um detetive particular.";
                break;
            case 9:
                descricaoOrigem = "\nCriminoso: De um mero abatedor de carteiras a um membro do crime organizado.";
                break;
            case 10:
                descricaoOrigem = "\nT.I: Programador, engenheiro de software ou simplesmente o 'Cara da T.I'.";
                break;
            case 11:
                descricaoOrigem = "\nPolicial: Força de segurança pública, civil ou militar.";
                break;
            case 12:
                descricaoOrigem = "\nMercenário: Soldado de aluguel, que trabalha sozinho ou como membro de uma organização que vende serviços militares personalizados.";
                break;
            default:
                std::cout << "\nOrigem Inválida!" << std::endl;
                continue; // Voltar ao início do loop para nova entrada.
        }

       if (!contemApenasCaracteresPermitidos(descricaoOrigem)) {
            std::cout << "\nDescrição da origem contém caracteres não permitidos. Tente novamente." << std::endl;
            continue;
        }

        std::cout << "\nDescrição da Origem: " << descricaoOrigem << std::endl;

        char confirmacao;
        std::cout << "\nVocê confirma sua escolha? (S/N) ";
        std::cin >> confirmacao;

        if (toupper(confirmacao) == 'S') {
            std::cout << "\nOrigem escolhida: " << descricaoOrigem << std::endl;
            break; // Sai do loop se a escolha foi confirmada.
        } else {
            std::cout << "\nEscolha cancelada. Você pode tentar novamente." << std::endl;
        }
    } while (true); // Loop infinito até que a escolha seja confirmada.

    int classe;
    // o jogador deve selecionar a classe que ele mais se encaixa diante as escolhas anteriores
    std::string descricaoClasse;

    do {
        std::cout << "\nSelecione sua Classe: (1-Combatente, 2-Especialista, 3-Ocultista): ";
        std::cin >> classe;

        switch (classe) {
            case 1:
                descricaoClasse = "\nCombatente: Treinado para lutar, capacitado para usar armas brancas e armas de fogo. Com abordagens diretas e costuma atirar primeiro e perguntar depois.";
                break;
            case 2:
                descricaoClasse = "\nEspecialista: Confia mais em suas habilidades técnicas e intelectuais do que sua força bruta. Conta com raciocínio rápido, astúcia e até um pouco de lábia.";
                break;
            case 3:
                descricaoClasse = "\nOcultista: Estudioso do Outro Lado, que busca compreender e dominar os mistérios paranormais para usá-los ao seu favor. Possui um talento especial para se conectar com as Entidades.";
                break;
            default:
                std::cout << "\nClasse Inválida! Escolha novamente." << std::endl;
                continue; 
        }

        std::cout << "\nClasse escolhida: " << descricaoClasse << std::endl;

        char confirmacao;
        std::cout << "\nVocê confirma sua escolha? (S/N) ";
        std::cin >> confirmacao;

        if (toupper(confirmacao) == 'S') {
            break; 
        } else {
            std::cout << "\nEscolha cancelada. Você pode tentar novamente." << std::endl;
        }
    } while (true);

    int patente;
    // o jogador deve informar qual nível ele está dentro da Ordo Realitas
    std::string descricaoPatente;

    do {
        std::cout << "\nEscolha a patente do seu personagem (1-Recruta, 2-Operador, 3-Analista, 4-Veterano, 5-Elite): ";
        std::cin >> patente;

        switch (patente) {
            case 1:
                descricaoPatente = "\nRecruta: Ainda sem experiência em missões.";
                break;
            case 2:
                descricaoPatente = "\nOperador: Possui alguma experiência e já resolveu alguns casos paranormais.";
                break;
            case 3:
                descricaoPatente = "\nAnalista: Agente experiente chamado para resolver casos mais difíceis e complexos.";
                break;
            case 4:
                descricaoPatente = "\nVeterano: Agente com dezenas de casos resolvidos, selecionado para missões de alta importância e risco.";
                break;
            case 5:
                descricaoPatente = "\nElite: As grandes lendas da Ordem, os sobreviventes da guerra contra o Outro Lado por muitos anos. Resolvem casos em escala global.";
                break;
            default:
                std::cout << "\nPatente Inválida! Escolha novamente." << std::endl;
                continue; // Continue the loop for a new choice.
        }

        std::cout << "\nPatente escolhida: " << descricaoPatente << std::endl;

        char confirmacao;
        std::cout << "\nVocê confirma sua escolha? (S/N) ";
        std::cin >> confirmacao;

        if (toupper(confirmacao) == 'S') {
            break; // Exit the loop if the choice is confirmed.
        } else {
            std::cout << "\nEscolha cancelada. Você pode tentar novamente." << std::endl;
        }
    } while (true);

    int habilidade;
    // O jogador deve inserir qual habilidade ele quer dominar
    std::cout << "\nSeu personagem possui algum talento especial que deixa o Deus da Morte com medo? Conte-nos sobre a habilidade extraordinária que ele(a) domina! (1-Ataque Físico, 2-Magia Ofensiva, 3-Defesa, 4-Roubo, 5-Ilusão, 6-Furtividade, 7-Persuasão): ";
    std::cin >> habilidade;

    std::string descricaoHabilidade;

    switch (habilidade) {
        case 1:
            descricaoHabilidade = "\nAtaque Físico: Seu personagem é um verdadeiro vendaval de golpes, um dançarino com armas que domina a arte da luta. Seus ataques são como relâmpagos, rápidos e devastadores.";
            break;
        case 2:
            descricaoHabilidade = "\nMagia Ofensiva: Nas mãos do seu personagem, a magia se transforma em pura destruição. Ele conjura feitiços ardentes e raios fulminantes, desafiando as leis da natureza e deixando seus inimigos de joelhos.";
            break;
        case 3:
            descricaoHabilidade = "\nDefesa: Seu personagem é uma fortaleza ambulante, um escudo impenetrável contra as investidas do inimigo. Com habilidades defensivas impressionantes, ele se torna um muro intransponível, protegendo seus aliados e desafiando qualquer ameaça.";
            break;
        case 4:
            descricaoHabilidade = "\nRoubo: Nas mãos ágeis do seu personagem, a arte do roubo se transforma em uma dança encantadora. Ele desliza pelas sombras, subtraindo tesouros sem deixar rastro. Seus truques são tão habilidosos que até mesmo os olhos mais atentos se perdem em sua presença.";
            break;
        case 5:
            descricaoHabilidade = "\nIlusão: Com a habilidade da ilusão, seu personagem é capaz de moldar a realidade com um simples gesto. Ele cria miragens deslumbrantes e altera percepções, confundindo e manipulando os sentidos dos outros. Seus inimigos nunca sabem o que é real e o que é mera ilusão.";
            break;
        case 6:
            descricaoHabilidade = "\nFurtividade: Seu personagem é uma sombra em movimento, um fantasma que passa despercebido. Ele se move sem emitir um único som, evitando a detecção dos inimigos. Sua habilidade em se camuflar e se esconder o torna um mestre da furtividade, capaz de se infiltrar nos lugares mais bem guardados.";
            break;
        case 7:
            descricaoHabilidade = "\nPersuasão: Seu personagem possui uma língua afiada e uma habilidade persuasiva incomparável. Com palavras eloquentes e carisma magnético, ele consegue convencer até mesmo os mais relutantes. Suas palavras são como encantamentos, persuadindo e manipulando as mentes daqueles ao seu redor.";
            break;
        default:
            std::cout << "\nOpção Inválida!" << std::endl;
            return 1; 
    }

    std::cout << "\nHabilidade escolhida: " << descricaoHabilidade << std::endl;

    std::string equipamentoPrincipal;
    // Equipamento de combate e defesa
    std::cout << "\nAgora me diga, qual é o equipamento principal que ele empunha, capaz de deixar seus adversários em estado de pura admiração ou temor? (exemplo: Pistola, Adaga, Arco, Lança Chamas, etc.): ";
    std::cin.ignore();
    std::getline(std::cin, equipamentoPrincipal);

    std::string equipamentosGerais;
    // Equipamento de sobrevivencia que pode ajudar e auxiliar durante as missoes
    std::cout << "\nSeu personagem precisa de equipamentos para sobrevivência! Descreva quais são eles (exemplo: Lanterna, Kit Médico, etc.): ";
    std::getline(std::cin, equipamentosGerais);

    std::cout << "\nEquipamento principal: " << equipamentoPrincipal << std::endl;
    std::cout << "\nEquipamentos gerais: " << equipamentosGerais << std::endl;

    return 0;
}