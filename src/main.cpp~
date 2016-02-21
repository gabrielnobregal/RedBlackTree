#include <iostream>
#include "RedBlackApp.h"

using namespace std;


int main(int argc, char *argv[]){

	

	if(argc<=2){
		cout<<"Sintaxe incorreta, utilize: ./redblackapp arquivo_de_entrada arquivo_de_saida"<<endl<< "\t Por exemplo: ./redblackapp input.txt output.txt"<<endl;		
	}else{
		RedBlackApp *app = new RedBlackApp();	
		app->process(argv[1], argv[2]);
		delete app;
	}	

	
	return 0;
}

