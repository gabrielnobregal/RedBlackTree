#Makefile para a construção do projeto Lab04 - Árvores Rubro Negras
#Criado por: Gabriel Nobrega de Lima
#Disciplina: Algoritmo e Estrutura de Dados II

LIB=lib/

CC=g++

all: main
	$(CC) main.o RedBlackApp.o RedBlackTree.o Node.o -o redblackapp

main:RedBlackApp
	$(CC) -c main.cpp

RedBlackApp:RedBlackTree
	$(CC)  -std=c++0x -c RedBlackApp.cpp

RedBlackTree:Node
	$(CC) -c $(LIB)RedBlackTree.cpp

Node:
	$(CC) -c $(LIB)Node.cpp

clear:
	rm *.o redblackapp
