 /**Definição de interface pública para árvores binárias.
  *@author Gabriel Nobrega de Lima
  */
#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <string>

using namespace std;

class BinaryTree{
public:
	/**
	 *Insere um nó na árvore.
	 *@param value Chave a ser inserida na árvore.	
	 */
	virtual void insert(int value) = 0; 
	
	/**
	 *Obtem árvore em pré-ordem.
	 *@return Árvore em pré-ordem codificada como (R,E,D). Onde R é o nó pai, E filho esquerdo e D filho direito.
	 */
	virtual string preOrderedState() = 0; 
	
	/**
	 *Remove uma chave da árvore.
	 *@param value Chave a ser removida da árvore.	
	 *@return True caso o nó tenha sido removido e False caso negativo.
	 */
	virtual bool remove(int value) = 0; 
	
	/**
	 *Verifica se uma chave está presente na árvore.
	 *@param value Chave a ser procurada na árvore.	
	 *@return True caso o nó esteja presente e False caso negativo.
	 */
	virtual bool find(int value) = 0; 

	/**
	 *Retorna todos os nós percorridos na tentativa de encontrar a chave value.
	 *@param value Chave a ser procurada na árvore.	
	 *@return Uma string com todas as chaves percorridas até que a busca se encerre.
	 */
	virtual string traceFind(int value) = 0; // Retorna os nós visitados no processo de busca
	
	/**
	 *Libera memória.
	 */
	virtual void release() = 0; 
	
	/**
	 *Destrutor.
	*/
	virtual ~BinaryTree(){
	}
};



#endif
