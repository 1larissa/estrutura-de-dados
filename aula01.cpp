/* ♡♡♡♡ LISTAS ENCADEADAS ♡♡♡♡ */

#include <cstddef> // NULL
#include <iostream>
#include <new> // ???
using namespace std;

// Definição dos nós da lista encadeada
struct Node
{
    int info;      // Dados
    Node *proximo; // Ponteiro para o prox objeto
};

// Definição da lista encadeada
class ListaEncadeada
{
private:
    Node *inicio = nullptr;
    Node *fim = nullptr;
    int tam = 0;

public:
    // Função para criar um novo nó
    Node *novoDado()
    {
        Node *novo = new Node;
        // Verifica se a alocação deu certo
        if (novo == nullptr)
        {
            cout << "Erro:  alocacao de memoria\n";
            return nullptr;
        }
        else
        {
            cout << "Digite a informacao: ";
            cin >> novo->info;
            novo->proximo = nullptr;
            return (novo);
        }
    }

    // Função para adicionar nó no ínicio da lista
    void inserirNoInicio()
    {
        Node *novo = novoDado();
        novo->proximo = inicio;
        // Se for o primeiro elemento da lista atualiza o fim tb
        if (inicio == nullptr)
            fim = novo;
        inicio = novo;
        tam++;
    }

    // Função para adicionar nó no fim da lista
    void inserirNoFinal()
    {
        Node *novo = novoDado();
        novo->proximo = nullptr;
        fim->proximo = novo;
        fim = novo;
        tam++;
    }

    // Função para adicionar um nó antes de um nó endereçado por k
    void inserirEmK(int k)
    {
        int i;
        Node *novo = novoDado();
        // Localiza a posição k-1
        Node *aux = inicio;
        for (i = 0; i < k-1; i++)
            aux = aux->proximo;
        // Insere na posição k-1
        novo->proximo = aux->proximo;
        aux->proximo = novo;
        tam++;
    }

    // Função para remover um nó no inicio da lista
    int removeNoInicio()
    {
        // Verifica se está vazia
        if (inicio == nullptr)
        {
            cout << "A lista ja esta vazia\n";
            return -1;
        }
        else  // Remove o nó do começo
        {
            Node *aux = inicio;
            int valor = aux->info;
            inicio = inicio->proximo;
            delete aux; // Desaloca a memoria
            tam--;
            return valor;
        }
    }

    // Função para remover um nó no final da lista
    int removeNoFinal()
    {
        int valor;
        // Se a lista está vazia
        if (inicio == nullptr)
        {
            cout << "A lista ja esta vazia\n";
            return -1;
        }
        // Se a lista possui somente um elemento
        else if (inicio->proximo == nullptr)
        {
            valor = inicio->info;
            delete inicio;
            inicio = nullptr;
            fim = nullptr;
            tam--;
            return valor;
        }
        // Se a lista possui mais de um elemento
        else
        {
            Node *ptr;
            Node *aux;
            for (ptr = inicio; ptr->proximo != nullptr; ptr = ptr->proximo)
                aux = ptr;
            valor = ptr->info;
            aux->proximo = nullptr;
            fim = aux;
            delete ptr;
            tam--;
            return valor;
        }

    }
    // Função para imprimir a lista
    void imprimeLista()
    {
        if(inicio == nullptr)
            cout << "A lista esta vazia\n";
        Node *aux = inicio;
        for(int i = 0; i < tam; i++)
        {
            cout << "[" << i << "]= " << aux->info << endl;
            aux = aux->proximo;
        }
    }
};

/* --------- MAIN PARA TESTES --------- */
int main()
{
    /* Criação da lista encadeada */
    ListaEncadeada lista1;

    lista1.inserirNoInicio();
    lista1.inserirNoInicio();

    lista1.imprimeLista();

    cout << lista1.removeNoFinal()<< "removido" << endl;
    lista1.imprimeLista();

    cout << lista1.removeNoFinal()<< "removido" << endl;
    lista1.imprimeLista();

    return 0;
}
