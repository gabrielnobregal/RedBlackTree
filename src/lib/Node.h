/**
 *Modela os n�s de �rvores Rubro-Negras.
 *@author Gabriel Nobrega de Lima
 */

#ifndef NODE_H
#define NODE_H

// Cores dispon�veis para o n�
#define RED 'V'
#define BLACK 'P'

class Node{

public:
	/**
	 * Construtor de n�s padr�o.
	 *@param value Chave.
	 *@param color Cor do n�, pode ser 'P' para preto ou 'V' para vermelho.
	 *@param father N� pai.
	 *@param left Filho esquerdo.
	 *@param right Filho direito.
	 */

	Node(int value, char color, Node *father, Node *left, Node *right);

	/**
	 *Cor do n�, pode ser P:preto ou V:vermelho.
	 */
	char color; 
	/**
	 *Chave do n�.
	 */
	int value; 

	/**
	 *Pai do n�.
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
