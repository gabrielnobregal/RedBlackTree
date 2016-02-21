/**
 *Modela os nós de árvores Rubro-Negras.
 *@author Gabriel Nobrega de Lima
 */

#ifndef NODE_H
#define NODE_H

// Cores disponíveis para o nó
#define RED 'V'
#define BLACK 'P'

class Node{

public:
	/**
	 * Construtor de nós padrão.
	 *@param value Chave.
	 *@param color Cor do nó, pode ser 'P' para preto ou 'V' para vermelho.
	 *@param father Nó pai.
	 *@param left Filho esquerdo.
	 *@param right Filho direito.
	 */

	Node(int value, char color, Node *father, Node *left, Node *right);

	/**
	 *Cor do nó, pode ser P:preto ou V:vermelho.
	 */
	char color; 
	/**
	 *Chave do nó.
	 */
	int value; 

	/**
	 *Pai do nó.
	 */
	Node *father; 

	/**
	 *Filho esquerdo.
	 */
	Node *left; 

	/**
	 * Filho direito.
	 */
	Node *right; 
};

#endif
