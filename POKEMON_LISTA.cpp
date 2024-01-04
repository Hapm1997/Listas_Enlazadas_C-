# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <iostream>

using namespace std ;

class POKEMON{
	public:
		char NOMBRE[15] ;
		char TIPO[15] ;
		int ATAQUE ;
		POKEMON * SIG ;
		POKEMON( char * , char * , int ) ;
};

POKEMON::POKEMON( char * NOM , char * TIP , int ATQ ) {
	strcpy( NOMBRE , NOM ) ;
	strcpy( TIPO , TIP ) ;
	ATAQUE = ATQ ;
	SIG = NULL ;
}
class LISTA{
	private :
		POKEMON * INICIO ;
	public :	
		LISTA() ;
		void AGREGAR_POKEMON( char * , char * , int ) ;
		void MIRAR() ;
		void AGUA( char * ) ;
		void MAX_ATQ() ;
		int CANT() ;
		void BORRAR( char * ) ;
};

LISTA::LISTA(){
	INICIO = NULL ;
}

void LISTA::AGREGAR_POKEMON( char * NOMBRE , char * TIPO , int ATAQUE ){
	POKEMON * NUEVO = new POKEMON( NOMBRE , TIPO , ATAQUE ) ;
	NUEVO->SIG = INICIO ;
	INICIO = NUEVO ;
}

void LISTA::MIRAR(){
	POKEMON * P ;
	P = INICIO ;
	while(P){
		cout << "\n\t  " << P->NOMBRE << "\t  "<< P->TIPO << "\t " << P->ATAQUE ;
//		printf("\n\t	NOMBRE = %10s	TIPO = %10s	ATAQUE = %d" , P->NOMBRE , P->TIPO , P->ATAQUE ) ;
		P = P->SIG	 ;
	}
}

void LISTA::AGUA( char * TIP ){
	POKEMON * P ;
	P = INICIO ;
	while(P){
		if(!(strcmp( P->TIPO , TIP ))){
			printf("\n\t	%10s	%10s	%d" , P->NOMBRE , P->TIPO , P->ATAQUE ) ;	
		}
		P = P->SIG ;
	}
}

void LISTA::MAX_ATQ(){
	POKEMON * P , * W;
	int max_f = 0 , max = 0;
	
	P = INICIO ;
	while(P){
		if( max_f = 0 ){
			max_f = 1 ;
			max = P->ATAQUE ;
			W = P ;
		}else{
			if( max < P->ATAQUE ){
				max = P->ATAQUE ;
				W = P ;
			}
		}
		P = P->SIG ;
	}
	cout << "\n\t	 " << W->NOMBRE << "\t		" << W->TIPO << " \t	" << W->ATAQUE ;
//	cout << "\n\t\t WWWWWWWWWWWWWWWWWWWWWWW" ;
//	W = INICIO ;
//	while(W){
//		cout << "\n\t  " << W->NOMBRE << "\t  "<< W->TIPO << "\t " << W->ATAQUE ;
////		printf("\n\t	NOMBRE = %10s	TIPO = %10s	ATAQUE = %d" , P->NOMBRE , P->TIPO , P->ATAQUE ) ;
//		W = W->SIG	 ;
//	}
}

int LISTA::CANT() {
	POKEMON * P ;
	int C = 0 ;
	P = INICIO ;
	while(P){
		C ++ ;
		P = P->SIG ;
	}
	return C ;
}

void LISTA::BORRAR( char * POKEMONaelIMINAR ){
	POKEMON * PAELIMINAR , * ANTERIOR ;
	PAELIMINAR = INICIO ;
	while(strcmp( PAELIMINAR->NOMBRE , POKEMONaelIMINAR )){
		
		PAELIMINAR = PAELIMINAR -> SIG ;
	} 
//	PAELIMINAR APUNTA AL QUE QUIERO ELIMINAR
	if( INICIO == PAELIMINAR ){		//NODO INICIAL
		INICIO = PAELIMINAR->SIG ;
	}else{		//NODO INTERMEDIO O FINAL
		ANTERIOR = INICIO ;
		while(ANTERIOR->SIG != PAELIMINAR){ //MIENTRAS QUE  EL CAMPO SIG NO COINCIDA CON EL QUE QUIERO ELIMINAR
			ANTERIOR = ANTERIOR->SIG ;		//MUEVO EL PUNTERO ANTERIOR			
		}	
		ANTERIOR->SIG = PAELIMINAR->SIG ;	//HACEMOS EL ENGANCHE
	}		
	delete PAELIMINAR ;
}
int main(){
	LISTA * L = new LISTA() ;
	L->AGREGAR_POKEMON( "PIKACHU" , "ELECTRICO" , 9 ) ;
	L->AGREGAR_POKEMON( "BULBASAUR" , "PLANTA" , 6 ) ;
	L->AGREGAR_POKEMON( "CHARMANDER" , "FUEGO" , 10 ) ;
	L->AGREGAR_POKEMON( "SQUIRTLE" , "AGUA" , 7 ) ;
	L->AGREGAR_POKEMON( "GENGAR" , "FANTASMA" , 12) ;
	L->AGREGAR_POKEMON( "PSYDUCK" , "AGUA" , 18 ) ;
	L->AGREGAR_POKEMON( "MEOWTH" , "NORMAL" , 11) ;
	L->MIRAR() ;
	L->AGUA("AGUA") ;
	
	printf("\n El Pokemon de mayor ataque es: ");
    L->MAX_ATQ();
    
    printf("\n La Lista tiene %d nodos" , L->CANT() );
    
    L->BORRAR("SQUIRTLE");
    L->MIRAR() ;
    printf("\n La Lista tiene %d nodos" , L->CANT() );
}

