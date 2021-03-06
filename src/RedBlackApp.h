/**
 *Implementação do aplicativo de árvores Rubro-Negras requisitado na atividade 04 da disciplina de AED2, UFABC 2012.
 *@author Gabriel Nobrega de Lima
 */

#ifndef AVLAPP_H
#define AVLAPP_H

#include <iostream>
#include <string.h>
#include <fstream>

#include "lib/RedBlackTree.h"

using namespace std;

class RedBlackApp{

private:
	BinaryTree *tree; // Árvore binária	
	string inputFile; // Arquivo de entrada
	string outputFile; // Arquivo de saída
public:
	~RedBlackApp();

	/** 
	 *Executa as operações de árvore contidas no arquivo de caminho inputFile. A saída de cada comando é gravada no arquivo com 		 *caminho outputFile.
	 *@param inputFile Caminho do arquivo de entrada.	
	 *@param outputFile Caminho do arquivo de saida.
	 */
	void process(string inputFile, string outputFile);
};

#endif
