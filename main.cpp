#include <iostream>
#include <string>
#include <time.h> 
#include <stdlib.h>
#include <conio.h> //getch
#include <ctype.h>

/*
	Convertir un string a int
string dinero;
money = atoi(dinero.c_str()); 
*/


using namespace std;

//Variables globales
#define longitud 4
#define longitudCedula 8
int key, j, l = 1, k = 1, m = 1, dineroIngreso, dineroRetiro, dineroTotal, i, valorIngreso, valorRetiro;
bool bloqueoIngreso = false, bloqueoRetiro = false;
char caracter, password[longitud];



void clear();
void cambioDocumento();
void preguntaRegistrarCorreo();
void cambioCorreo();
int claveAutomatica(int key);
void preguntaCambioClave();
void menuOpciones();
void validarClaveGlobal();
void cambioClave();
void seeKey();
void clearIngresar();
void clearRetirar();
void ingresarDinero();
void validarClaveIngresoDinero();
void retirarDinero();
void validarClaveRetiroDinero();

/*Programa que simule un cajero automático con un saldo inicial de 1000 dólares*/


//Inicio Funcion main()
int main(int argc, char** argv) {
	
	string nombre_y_apellido;
	
		//Saludo de bienvenida
	cout<<"\t\t\t\tBienvenido a Tu Banco Virtual"<<endl;
	
		//Validacion del Nombre
	cout<<"\n\n\t- Ingrese su primer nombre y primer apellido: ";
	getline(cin, nombre_y_apellido);
	
	while(nombre_y_apellido.empty()){
		clear();
		cout<<"\n\n\t\tERROR // El campo esta vacio, ingrese una opcion."<<endl;
		cout<<"\n\t- Ingrese su primer nombre y primer apellido: ";
		getline(cin, nombre_y_apellido);
	}
	clear();
	
	
		//Ingreso de documento
	cambioDocumento();
	clear();
	
	
		//Ingreso de correo
	preguntaRegistrarCorreo();
	
	
		//Clave aleatoria
	cout<<"\n\n\t\tHola, "<<nombre_y_apellido<<" esta es su clave que se ha generado de manera automatica, desea modificarla?"<<endl;	
	srand(time(NULL));
	key = 0 + rand()%(10000-1);
	claveAutomatica(key);
	
		//Cambio de clave
	preguntaCambioClave();
	

	return 0;
}
//Final Funcion main()




//Inicio funcion clear()
void clear(){
	system("cls");
	cout<<"\t\t\t\tBienvenido a Tu Banco Virtual"<<endl;
}
//Final funcion clear()




//Inicio Funcion cambioDocumento()
void cambioDocumento(){
	string documento;
	
	cout<<"\n\n\t- Ingrese su documento de identidad: ";
	getline(cin, documento);

	if(documento.empty()){
		clear();
		cout<<"\n\n\t\tERROR // El campo esta vacio, ingrese una opcion.";
		cambioDocumento();
		
	} else if(documento.length() < longitudCedula){
		clear();
		cout<<"\n\n\t\tERROR // El documento ingresado no es valido.";
		cambioDocumento();
	}
}
//Final Funcion cambioDocumento()




//Inicio funcion preguntaRegistrarCorreo()
void preguntaRegistrarCorreo(){
	string preguntaCorreo;
	
	cout<<"\n\n\t- Desea registrar un correo electronico?";
	cout<<"\n\t- s/n: ";
	getline(cin, preguntaCorreo);
	
	if( preguntaCorreo.empty() ){
		clear();
		cout<<"\n\n\t\tERROR // El campo esta vacio, ingrese una opcion."; 
		preguntaRegistrarCorreo();
		
	} else if(preguntaCorreo == "s" || preguntaCorreo == "S" || preguntaCorreo == "si" || preguntaCorreo == "SI" || preguntaCorreo == "sI" || preguntaCorreo == "Si"){
		clear();
		cambioCorreo();
		
	} else if(preguntaCorreo == "n" || preguntaCorreo == "N" || preguntaCorreo == "no" || preguntaCorreo =="NO" || preguntaCorreo == "nO" || preguntaCorreo == "No"){
		clear();
		
	} else{
		clear();
		cout<<"\n\n\t\tERROR // Ingrese una opcion valida."; 
		preguntaRegistrarCorreo();
	}
}
//Final funcion preguntaRegistrarCorreo()




//Inicio Funcion cambioCorreo()
void cambioCorreo(){
	string correo;
	char caracter = '@';
	bool b;
	
	cout<<"\n\n\t- Ingrese el correo electronico a registrar: ";
	getline(cin, correo);
	
	if( !correo.empty() ){
		for(int c = 0; c < correo.length(); c++){
			if(correo[c] == caracter) {
				b = true;
			}
		}	
		
		if(b == true){
			clear();
			cout<<"\n\n\n\t\t*** Registro de correo electronico exitoso. ***"<<endl
			<<"\n\t\t*** Recuerde que puede modificar su correo electronico desde el menu de opciones. ***"<<endl
			<<"\n\n\t------------------------------------------------------------------------------------------------"<<endl;
						
		} else if(b == false){
			clear();
			cout<<"\n\n\t\tERROR // La direccion de correo electronico no es valida, debe ingresar el '@'.";
			cambioCorreo();
		}
	} else{
		clear();
		cout<<"\n\n\t\tERROR // El campo esta vacio, ingrese una opcion."; 
		cambioCorreo();
	}
}
//Final Funcion cambioCorreo()




//Inicio funcion claveAutomatica(int clave)
int claveAutomatica(int key) {
	cout<<"\n\t\tClave: "<<key<<endl;
}
//Final funcion claveAutomatica(int clave)




//Inicio funcion preguntaCambioClave()
void preguntaCambioClave(){
	
	string modificarClave;
	
	cout<<"\n\t- s/n: ";
	getline(cin, modificarClave);
		
	if(modificarClave.empty()){
		clear();
		cout<<"\n\n\t\tERROR // El campo esta vacio, ingrese una opcion."
		<<"\n\n\t- Esta es su clave "<<key<< ", desea modificarla?";
		preguntaCambioClave();
			
	} else if(modificarClave == "s" || modificarClave == "S" || modificarClave == "si" || modificarClave == "SI" || modificarClave == "sI" || modificarClave == "Si"){
		cambioClave();
		
	} else if (modificarClave == "n" || modificarClave == "N" || modificarClave == "no" || modificarClave == "NO" || modificarClave == "nO" || modificarClave == "No"){
		clear();
		menuOpciones();

	} else{
		clear();
		cout<<"\n\n\t\tERROR // Ingrese una opcion valida."
		<<"\n\n\t- Esta es su clave "<<key<< ", desea modificarla?";
		preguntaCambioClave();	
	}
}
//Final funcion preguntaCambioClave()




//Inicio Funcion menuOpciones()
void menuOpciones(){
	l = 1;
	k = 1;
	
	int opcionMenu;
	
	cout<<"\n\n\t\t\t//Menu de opciones//"<<endl;
	cout<<"\n\t\t\t1. Ingresar dinero"<<endl;
	cout<<"\n\t\t\t2. Retirar dinero"<<endl;
	cout<<"\n\t\t\t3. Transferencias"<<endl;
	cout<<"\n\t\t\t4. Ver saldo"<<endl;
	cout<<"\n\t\t\t5. Ver mis datos"<<endl;
	cout<<"\n\t\t\t6. Modificar nombre"<<endl;
	cout<<"\n\t\t\t7. Cambiar clave"<<endl;
	cout<<"\n\t\t\t8. Salir"<<endl;
	cout<<"\n\t-Elija una opcion: ";
	cin>>opcionMenu;
	cin.ignore(); // Se coloca despues de un cin para ignore el ultimo \n
	
	
	switch(opcionMenu){
		case 1: 
		if(bloqueoIngreso == true){
			clear();
			cout<<"\n\n\t\tUsted ya ha superado el numero mayor de intentos, para realizar el ingreso de su dinero\n"
			<<" \t\tcomuniquese al 01-8000-555-666 o acerquese a una de nuestras oficinas."<<endl;
			cout<<"\n\n\n\t------------------------------------------------------------------------------------------------"<<endl;
			menuOpciones();
		
		} else{
			clearIngresar(); 
			ingresarDinero();
		}
		
		case 2: 
		if(bloqueoRetiro == true){
			clear();
			cout<<"\n\n\t\tUsted ya ha superado el numero mayor de intentos, para realizar el retiro de su dinero\n"
			<<" \t\tcomuniquese al 01-8000-555-666 o acerquese a una de nuestras oficinas."<<endl;
			cout<<"\n\n\n\t------------------------------------------------------------------------------------------------"<<endl;
			menuOpciones();
		
		} else{
			clearRetirar(); 
			retirarDinero();
		}
		//case 3: transferencias(); break;
		//case 4: verSaldo(); break;
		//case 5: verMisDatos(); break;
		//case 6: modificarNombre(); break;
		//case 7: cambiarClave(); break;
		//case 8: salir(); break;
		default: cout<<"\n\t\tLa opcion no es correcta, intentelo de nuevo."; clear(); menuOpciones();
	}
}
//Final Funcion menuOpciones()




//Inicio Funcion validarClaveGlobal()
void validarClaveGlobal(){
	
	int i;
	
	cout<<"\n\n\t- Ingrese su clave, tiene 3 intentos: ";
	
	while(caracter = getch()){ //No mostrar cuando escribe
		if(caracter == 13){ //tecla de enter
			password[i] = '\0'; //caracter nulo para indicar el final de una cadena, si doy enter y no hay nada no me arroja el cacter del enter
			break;
				
		} else if(caracter == 8){
			if(i > 0){
				i--;
				cout<<"\b \b";
			}	
		} else{
			if(i < longitud){
				cout<<"*";
				password[i] = caracter;
				i++;
			}
		}
	}
	j = i;
}
//Final Funcion validarClaveGlobal()




//Inicio Funcion cambioClave()
void cambioClave(){
	
	validarClaveGlobal();
	
	if(j == 0){
		clear();
		cout<<"\n\n\t\tERROR // No ha ingresado ningun numero.";
		cambioClave();
	}
	
	if(j < longitud){
		clear();
		
		while(k < 3){
			cout<<"\n\n\n\t\tERROR // Debe ingresar una clave valida."
			<<"\n\n\t\t*** Numero de intentos: "<<k<<" de 3 ***";
			k++;
			cambioClave(); 
		}
		
		if(k > 2){
			cout<<"\n\n\t\t*** Numero de intentos: "<<k<<" de 3 ***"
			<<"\n\n\t\tHa superado el numero mayor de intentos, para realizar el cambio de su clave\n"
			<<" \t\tcomuniquese al 01-8000-555-666 o acerquese a una de nuestras oficinas."<<endl;
			cout<<"\n\n\n\t------------------------------------------------------------------------------------------------"<<endl;
			menuOpciones();
		}
			
	} else{
		clear();
		seeKey();
	}
}
//Final Funcion cambioClave()




//Inicio Funcion seeKey()
void seeKey(){
	
	string verClave;
	
	cout<<"\n\n\t- Desea ver su clave? s/n: ";
	getline(cin, verClave);
	clear();
	
	if(verClave.empty()){
		cout<<"\n\n\t\tERROR // El campo esta vacio, ingrese una opcion.";
		seeKey();
		
	} else if(verClave == "s" || verClave == "S" || verClave == "si" || verClave == "SI" || verClave == "sI" || verClave == "Si"){
		key = atoi(password);
		cout<<"\n\n\t\t*** Su nueva clave es: "<<key<<" // recuerde que puede cambiar su clave desde el menu de opciones. ***"<<endl;
		cout<<"\n\n\t------------------------------------------------------------------------------------------------"<<endl;
		menuOpciones();
		
	} else if (verClave == "n" || verClave == "N" || verClave == "no" || verClave == "NO" || verClave == "nO" || verClave == "No"){
		key = atoi(password);
		menuOpciones();
			
	} else{
		cout<<"\n\n\t\tERROR // Ingrese una opcion valida.";
		seeKey();
	}
}
//Final Funcion seeKey()




//Inicio funcion clearIngresar()
void clearIngresar(){
	system("cls");
	cout<<"\t\t\t\tBienvenido a Tu Banco Virtual"<<endl;
	cout<<"\n\n\n\t\t***Ingresar dinero***"<<endl;
}
//Final funcion clearIngresar()




//Inicio funcion clearRetirar()
void clearRetirar(){
	system("cls");
	cout<<"\t\t\t\tBienvenido a Tu Banco Virtual"<<endl;
	cout<<"\n\n\n\t\t***Retirar dinero***"<<endl;
}
//Final funcion clearRetirar()




//Inicio Funcion ingresarDinero()
void ingresarDinero(){
	
	string ingreso;
	
	cout<<"\n\t- Cuanto dinero desea ingresar: $ ";
	getline(cin, ingreso);
	
	if(ingreso.empty()){
		clearIngresar();
		cout<<"\n\n\t\tERROR // El campo esta vacio, ingrese un valor."<<endl;
		ingresarDinero();
	}
	
	dineroIngreso = atoi(ingreso.c_str()); //Convertir un string a int
	
	if(dineroIngreso > 1000000){
		clearIngresar();
		cout<<"\n\n\t\tERROR // Lo maximo permitido para ingresar es $1.000.000."<<endl;
		ingresarDinero();
	
	} else if (dineroIngreso > 0 && dineroIngreso < 20000){
		clearIngresar();
		cout<<"\n\n\t\tERROR // Lo minimo permitido para ingresar es $20.000."<<endl;
		ingresarDinero();
			
	} else if(dineroIngreso > 19999 && dineroIngreso < 1000001){
		clearIngresar();
		validarClaveIngresoDinero();
		
	} else{
		clearIngresar();
		cout<<"\n\n\t\tERROR // El campo esta vacio, ingrese un valor."<<endl;
		ingresarDinero();
	}
}
//Final Funcion ingresarDinero()




//Inicio Funcion validarClaveIngresoDinero()
void validarClaveIngresoDinero(){
	
	validarClaveGlobal();

	if(j == 0){
		clearIngresar();
		cout<<"\n\n\t\tERROR // No ha ingresado ningun numero.";
		validarClaveIngresoDinero();
	}
	
	if(j < longitud){
	
		while(l < 3){
			clearIngresar();
			cout<<"\n\n\t\tERROR // La clave no es valida."
			<<"\n\n\t\t*** Numero de intentos: "<<l<<" de 3 ***";
			l++;
			validarClaveIngresoDinero();
		}
		
		if(l > 2){
			clear();
			bloqueoIngreso = true;
			cout<<"\n\n\t\t*** Numero de intentos: "<<l<<" de 3 ***"
			<<"\n\n\t\tHa superado el numero mayor de intentos, para realizar el ingreso de su dinero\n"
			<<" \t\tcomuniquese al 01-8000-555-666 o acerquese a una de nuestras oficinas."<<endl;
			cout<<"\n\n\n\t------------------------------------------------------------------------------------------------"<<endl;
			menuOpciones();
		}
	} else {
		
		valorIngreso = atoi(password);
		
		if(valorIngreso == key){
			clear();
			dineroTotal += dineroIngreso;
			cout<<"\n\n\t\t*** Ingreso de dinero exitoso. ***"<<endl;
			cout<<"\n\n\t\tAcabo de ingresar: $"<<dineroIngreso
			<<"\n\n\t\tEn su cuenta hay: $"<<dineroTotal;
			cout<<"\n\n\t------------------------------------------------------------------------------------------------"<<endl;
			menuOpciones();
		}
		
		while(l < 3){
			clearIngresar();
			cout<<"\n\n\t\tERROR // La clave no es valida."
			<<"\n\n\t\t*** Numero de intentos: "<<l<<" de 3 ***";
			l++;
			validarClaveIngresoDinero();
		}
		
		if(l > 2){
			clear();
			bloqueoIngreso = true;
			cout<<"\n\n\t\t*** Numero de intentos: "<<l<<" de 3 ***"
			<<"\n\n\t\tHa superado el numero mayor de intentos, para realizar el ingreso de su dinero\n"
			<<" \t\tcomuniquese al 01-8000-555-666 o acerquese a una de nuestras oficinas."<<endl;
			cout<<"\n\n\n\t------------------------------------------------------------------------------------------------"<<endl;
			menuOpciones();
		}
	}
}
//Final Funcion validarClaveIngresoDinero()




//Inicio Funcion retirarDinero()
void retirarDinero(){
	
	string retiro;
	
	cout<<"\n\t- Cuanto dinero desea retirar: $ ";
	getline(cin, retiro);
	
	if(retiro.empty()){
		clearRetirar();
		cout<<"\n\n\t\tERROR // El campo esta vacio, ingrese una opcion."<<endl;
		retirarDinero();
	}
	
	dineroRetiro = atoi(retiro.c_str()); //Convertir un string a int
	
	if(dineroRetiro > dineroTotal){
		clearRetirar();
		cout<<"\n\n\t\tERROR // Fondos inuficientes."<<endl;
		retirarDinero();
	
	} else if (dineroRetiro >= 0 && dineroRetiro <= dineroTotal){
		clearRetirar();	
		validarClaveRetiroDinero();	
			
	} else{
		clearRetirar();
		cout<<"\n\n\t\tERROR // El campo esta vacio, ingrese un valor."<<endl;
		retirarDinero();
	}
}
//Final Funcion retirarDinero()




//Inicio Funcion validarClaveRetiroDinero()
void validarClaveRetiroDinero(){
	
	validarClaveGlobal();
	
	if(j == 0){
		clearIngresar();
		cout<<"\n\n\t\tERROR // No ha ingresado ningun numero.";
		validarClaveRetiroDinero();
	}
	
	if(j < longitud){
		
		while(k < 3){
			clearIngresar();
			cout<<"\n\n\t\tERROR // La clave no es valida."
			<<"\n\n\t\t*** Numero de intentos: "<<k<<" de 3 ***";
			k++;
			validarClaveRetiroDinero(); 
		}
		
		if(k > 2){
			clear();
			bloqueoRetiro = true;
			cout<<"\n\n\t\t*** Numero de intentos: "<<k<<" de 3 ***"
			<<"\n\n\t\tHa superado el numero mayor de intentos, para realizar el retiro de su dinero\n"
			<<" \t\tcomuniquese al 01-8000-555-666 o acerquese a una de nuestras oficinas."<<endl;
			cout<<"\n\n\n\t------------------------------------------------------------------------------------------------"<<endl;
			menuOpciones();
		}
			
	} else {
		
		valorRetiro = atoi(password);
		
		if(valorRetiro == key){
			clear();
			dineroTotal -= dineroRetiro;
			cout<<"\n\n\t\t*** Retiro de dinero exitoso. ***"<<endl;
			cout<<"\n\n\t\tAcabo de retirar: $"<<dineroRetiro
			<<"\n\n\t\tSaldo en cuenta: $"<<dineroTotal;
			cout<<"\n\n\t------------------------------------------------------------------------------------------------"<<endl;
			menuOpciones();
		}
		
		while(k < 3){
			clearIngresar();
			cout<<"\n\n\t\tERROR // La clave no es valida."
			<<"\n\n\t\t*** Numero de intentos: "<<k<<" de 3 ***";
			k++;
			validarClaveRetiroDinero(); 
		}
		
		
		if(k > 2){
			clear();
			bloqueoRetiro = true;
			cout<<"\n\n\t\t*** Numero de intentos: "<<k<<" de 3 ***"
			<<"\n\n\t\tHa superado el numero mayor de intentos, para realizar el retiro de su dinero\n"
			<<" \t\tcomuniquese al 01-8000-555-666 o acerquese a una de nuestras oficinas."<<endl;
			cout<<"\n\n\n\t------------------------------------------------------------------------------------------------"<<endl;
			menuOpciones();
		}
	}
}
//Final Funcion validarClaveRetiroDinero()







