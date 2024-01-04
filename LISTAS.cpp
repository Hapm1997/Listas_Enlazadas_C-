//LISTAS SIMPLEMENTE ENLAZADAS

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <iostream>

using namespace std ;

class NODO{
	public:
		char NOM[20] ;
		NODO * SIG ;  //PUNTERO ENLACE AL SIGUIENTE NODO -- PUNTERO A NODO
		NODO( char * ) ; 	//CONST. STRING QUE RECIBE EL NOMBRE QUE VAMOS A CARGAR 
		NODO () ;
		~NODO() ;		//NOS DICE A QUIEN DESTRUIMOS
};
 NODO::NODO( char * S ){		//COPIA EL VALOR INGRESADO Y LO GUARDA EN -NOM-
 	strcpy( NOM , S ) ;
 }
 NODO::NODO(){
 	
 }
 NODO::~NODO(){
 	cout << "\n\n MATANDO A .... " << NOM << "\n";
 	getchar() ;
 }
 
 class LISTA {
 	private :
 		NODO * INICIO ; 	// PUNTERO A NODO LLAMADO INICIO
 		void PONER_P( NODO *) ;		//RECIBE UN NODO
 		void PONER_F( NODO *) ;
 	public : 
 		LISTA() ; //PONE INICIO A NULL
 		~LISTA() ;		//DESHACERSE DE LOS NODOS
 		void AGREGAR_P( char * ) ;
 		void AGREGAR_F( char * ) ;
 		void MIRAR() ; 
 		void RARIM() ;
 };
 
 LISTA::LISTA(){
 	INICIO = NULL ;
 }
 LISTA::~LISTA(){
 	cout << "\n\n	DESTRUYENDO TODOS LOS NODOS\n" ;
 	cout << "\n\n	TAREA\n" ;
	getchar() ;
 }
 
 void LISTA::AGREGAR_P( char * S){		//CREA EL NODO
 	NODO * P ;		//CREAMOS UN PUNTERO AUXILIAR -P-
 	P = new NODO(S) ;	//TAREA DE GESTION , TENEMOS UN NODO CON EL NOMBRE PUESTO APUNTADO POR -P-
 	
 	PONER_P(P) ;		//LE DAMOS LA DIRECCION DEL NODO A UNA FUNCION PARA PONERLO EN LA LISTA
 }
 
 void LISTA::PONER_P( NODO * PN){		//ENLAZA EL NODO, RECIBEINDO UN PUNTERO NUEVO -PN-
 	PN->SIG = INICIO ;		//PUNTERO QUE RECIBIMOS -PN- QUE APUNTA A -SIG- SE CARGUE CON -INICIO-
 	INICIO = PN ;			//LUEGO QUE -INICIO- SE CARGUE CON -PN- 
 }
 
  void LISTA::AGREGAR_F( char * S){
 	NODO * P ;
 	P = new NODO(S) ;
 	
 	PONER_F(P) ;
 }
 
 void LISTA::PONER_F( NODO * PN){
 	NODO * P ;
 	P = INICIO ;
	PN->SIG = NULL ;
 	if (!INICIO){
// 		LISTA VACIA
	 	INICIO = PN ;	
	 	return ;
	}
//	LISTA NO VACIA
	while(P->SIG){
		P = P->SIG ; 		//LLEVO P AL ULTIMO NODO
	}
	P->SIG = PN ;
	 
 }
 void LISTA::MIRAR(){
 	NODO * P ;		//CREO EL PUNTERO -P-
 	cout << "\n\n\n\t CONTENIDO DE LA LISTA \n\n" ;
 	
 	P = INICIO ; 	//INICIALIZO -P-
 	while (P){
 		cout << "\n\n\t "<< &P->NOM ;
 		P = P->SIG ;
	 }
	 getchar() ;
 }
 
// --------------------------------------------------
void LISTA::RARIM(){
	NODO * P ;
	int N = 0 ;
	P = INICIO ;
	while(P){
		N ++ ;
		P = P->SIG ;
	}
	P = INICIO ;
	NODO * W ;
	W = INICIO ;
	cout << "\n\n\t INICIO W		"<< &W->NOM ;
	while(P){
		W->SIG = P ;
		P = P->SIG ;
	}
	
	for( int I = 0 ; I < N ; I ++ ){
		cout << "\n\n\t W	 "<< W->NOM ;
		W = W->SIG ;
	}
	cout << "\n\n\t CANT DE NOMBRES		"<< N ;
}
 
int main(){
	LISTA L ;
	char BUF[20] ;
	
	cout << "\n\n NOMBRE 	: 	" ;
	cin >> BUF ;
	
	while ( strcmp( BUF , "FIN" ) ){
		L.AGREGAR_P(BUF) ;
		cout << "\n\n NOMBRE	:	" ;
		cin >> BUF ;
	}
	
	L.MIRAR() ;
	L.RARIM() ;
	printf("\n\nFIN DEL PROGRAMA\n\n") ;
	return 0 ;
}
