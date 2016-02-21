 /**Defini��o de interface p�blica para �rvores bin�rias.
  *@author Gabriel Nobrega de Lima
  */
#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <string>

using namespace std;

class BinaryTree{
public:
	/**
	 *Insere um n� na �rvore.
	 *@param value Chave a ser inserida na �rvore.	
	 */
	virtual void insert(int value) = 0; 
	
	/**
	 *Obtem �rvore em pr�-ordem.
	 *@return �rvore em pr�-ordem codificada como (R,E,D). Onde R � o n� pai, E filho esquerdo e D filho direito.
	 */
	virtual string preOrderedState() = 0; 
	
	/**
	 *Remove uma chave da �rvore.
	 *@param value Chave a ser removida da �rvore.	
	 *@return True caso o n� tenha sido removido e False caso negativo.
	 */
	virtual bool remove(int value) = 0; 
	
	/**
	 *Verifica se uma chave est� presente na �rvore.
	 *@param value Chave a ser procurada na �rvore.	
	 *@return True caso o n� esteja presente e False caso negativo.
	 */
	virtual bool find(int value) = 0; 

	/**
	 *Retorna todos os n�s percorridos na tentativa de encontrar a chave value.
	 *@param value Chave a ser procurada na �rvore.	
	 *@return Uma string com todas as chaves percorridas at� que a busca se encerre.
	 */
	virtual string traceFind(int value) = 0; // Retorna os n�s visitados no processo de busca
	
	/**
	 *Libera mem�ria.
	 */
	virtual void release() = 0; 
	
	/**
	 *Destrutor.
	*/
	virtual ~BinaryTree(){
	}
};



#endif
