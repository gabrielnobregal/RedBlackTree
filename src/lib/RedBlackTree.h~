/**
 * Implementa árvores binárias Rubro-Negras.
 * @author Gabriel Nobrega de Lima
*/

#ifndef AVLTREE_H
#define AVLTREE_H

#include <string>
#include <sstream>
#include <iostream>

#include "BinaryTree.h"
#include "Node.h"


using namespace std;




class RedBlackTree: public BinaryTree{
private:
	Node *treeRoot; // Raiz da árvore
	Node *nil;
	
	//*Para maiores informações veja a documentação no diretório .../doc	
	
	// Inserção de nós
	void internalInsert(Node *node, int value);
	
	// Verifica e arruma a árvore para o nó node recém incluido
	void fixUp(Node *node);
	
	// Busca na árvore
	string internalTraceFind(Node *node, int value);
	bool internalFind(Node *node, int value);

	// Visualização da árvore	
	string internalViewTree(Node *node);
	string internalPreOrderedState(Node *node);
	
	// Liberação de memória
	void internalRelease(Node *node);
	
	// Rotações
	void rotateLeft(Node *node);
	void rotateRight(Node *node);

public:
	// Construtor
	RedBlackTree();
	
	// Destrutor
	~RedBlackTree();
		
	/*
	* Métodos da interface pública. Em sua maioria implementam os métodos abstratos de BinaryTree
	*/
	
	// Inseri um nó na árvore
	void insert(int value); 
	
	// Imprime a árvore em pré-ordem seguindo a sintaxe (R,E,D)
	string preOrderedState(); 
	
	// Remove o nó de valor "value" da árvore
	bool remove(int value); 
	
	// Procura o nó de valor "value". Retorna verdadeiro caso encontre, do contrário, falso
	bool find(int value); 
	
	// Retorna uma string com os nós percorridos a partir da rais até o nó de valor "value"
	string traceFind(int value);	
	
	/**
	 *Obtem toda a configuração da árvore. Cada nó é exibido mostrando sua cor, filhos e pai.
	 *@return String com as configurações de todos os nós da árvore.
	 */
	string viewTree();
	
	// Libera memória. Geralmente não necessário, o destrutor chama automáticamente.	
	void release();
};


#endif
