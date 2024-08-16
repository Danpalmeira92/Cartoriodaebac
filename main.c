////
//  main.c
//  Atividade01
//
//  Created by Daniel Palmeira on 16/07/24.
//

#include <stdio.h> //biblioteca deomunicação com o usuário
#include <stdlib.h> //biblioteca de alocaçao de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

int registro(void) // Função responsável por cadastrar os usuários no sistema
{
    
    //Início da criação de variáveis/Strings
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    //Final da criação de variáveis/Strings
    
    printf("Digite o CPF a ser cadastrado: "); //Coletando informações do usuário
    scanf("%s", cpf); //%s refere-se a string
    
    strcpy(arquivo, cpf);  //Responsável por copiar os valores das strings
    
    FILE *file = fopen(arquivo, "w"); //Cria o arquivo e o "w" signfica escrever
    fprintf(file, "%s,", cpf); //Salva o valor da variável
    fclose(file); //Fecha o arquivo
    
    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);
    
    printf("Digite o nome a ser cadastrado: ");
    scanf("%s", nome);
    
    file = fopen(arquivo, "a"); //o "a" significa atualizar o arquivo
    fprintf(file, "%s,", nome);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);
    
    printf("Digite o sobrenome a ser cadastrado: ");
    scanf("%s", sobrenome);
    
    fopen(arquivo, "a");
    fprintf(file, "%s,", sobrenome);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);
    
    printf("Digite o cargo a ser cadastrado: ");
    scanf("%s", cargo);
    
    fopen(arquivo, "a");
    fprintf(file, "%s,", cargo);
    fclose(file);
    
    printf("Dados salvos com sucesso.\n");
    getchar();

    
    return 0;
    
}




int consulta(void)

{
    setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
    

    char cpf[40];
    char conteudo[200];
    
    printf("Digite o CPF a ser consultado: ");
    scanf("%s", cpf);
    
    FILE *file = fopen(cpf, "r"); // o "r'significa ler o arquivo
    
    if(file == NULL)
    {
        printf("Não foi possível abrir o arquivo, não localizado.\n");
        getchar();
    }
    
    
    
    while (fgets(conteudo, 200, file) != NULL)
    {
        printf("\nEssas são as informações do usuário: ");
        
        printf("%s\n", conteudo);
        printf("\n\n");
        getchar();
        
    }
    
    
    
    return 0;

}

int deletar(void)
{
    char cpf[40];
    
    printf("Digite o CPF a ser Deletado: ");
    scanf("%s", cpf);
    
    
    FILE *file = fopen(cpf, "r");
    fclose(file);
    
    
    if(file == NULL)
    {
        printf("O usuário não se encontra no sistema!.\n");
        getchar();

    }
    
    else
    {
        remove(cpf);
        printf("Usuário deletado!.\n");
        getchar();
    }
    
    
    
        return 0;
}

int main(void)
    {
    int opcao=0; //Definindo variáveis
    int x=1;
    
    for(x=1;x=1;)
    {
        system("clear"); //Limpa a tela
        
        setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
        
        printf("### Cartório da EBAC ### \n\n"); //Início do menu
        printf("Escolha a opção desejada do menu: \n\n");
        printf("\t1 - Registrar nomes\n");
        printf("\t2 - Consultar nomes\n");
        printf("\t3 - Deletar nomes\n\n");
        printf("\t4 - Sair do sistema\n\n");
        printf("Opção: "); //Fim do menu
        
        scanf("%d", &opcao); //Armazenando a escolha do usuário
        
        system("clear");
        
        switch(opcao) //início da seleção
        {
            case 1:
                registro();
                break;
                
            case 2:
                consulta();
                break;
                
            case 3:
                deletar();
                break;
                
            case 4:
                printf("Obrigado por utilizar o sistema!\n");
                return 0;
                break;
                
            default:
                printf("Essa opção não é válida\n");
                getchar();
                break;
                
                
                
                
        }
        
        
        } //Fim da seleção
    }



