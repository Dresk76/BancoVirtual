#include <iostream>
#include <cstring>
#include <string.h>
#include <time.h> 
#include <stdlib.h>
#include <conio.h> //getch
#include <iomanip>

/*
	Convertir un string a int
string dinero;
money = atoi(dinero.c_str()); 
*/

/*
system("pause");
*/

/*
//Este codigo es para que indique cuantas cifras tiene un numero ingresado
while(ahorros >= 10){
	ahorros /= 10;
	cifras++;
}
*/

using namespace std;

//Variables globales
#define longiCedula 11
#define longitud 4
#define longiEscape 7
#define longiRetiro 6
#define longiQuestion 2
#define longiNumeroCuenta 20

int key, e, i, j, k = 1, l = 1, m = 1, dineroIngreso, dineroRetiro, dineroTransferencia, dineroTotal, valorIngreso, 
	valorRetiro, valorTransferencia;

bool bloqueoIngreso = false, bloqueoRetiro = false, bloqueoTransaccion = false;

char documento[longiCedula], caracter, password[longitud], valor[longiEscape], numeroCuenta[longiNumeroCuenta];



void clear();
void continuar();
void cambioDocumento();
void preguntaRegistrarCorreo();
void cambioCorreo();
void claveAutomatica(int key);
void preguntaCambioClave();
void menuOpciones();
void validarClaveGlobal();
void limiteCero();
void escape();
void cambioClave();
void seeKey();
void clearCambioClave();
void clearCambioClaveDos();
void clearIngresar();
void clearIngresarDos();
void clearRetirar();
void clearRetirarDos();
void clearTransferencias();
void clearTransferenciasDos();
void ingresarDinero();
void validarClaveIngresoDinero();
void retirarDinero();
void validarClaveRetiroDinero();
void transferencias();
void cuentaAhorros();
void validarNumeroCuenta();
void validarCantidadTransferir();
void validarClaveTransferenciaDinero();
void cuentaCorriente();
void otrosBancos();
void bancos();



/*Programa que simule un cajero automático con un saldo inicial de 1000 dólares*/


//Inicio Funcion main()
int main(int argc, char** argv) {
	
		//Variables
	string nombre_y_apellido;
	
		//Saludo de bienvenida
	cout<<"\n"<<setw(85)<<"************************************************************"
		<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
		<<"\n"<<setw(26)<<"*"<<setw(43)<<"Bienvenido a tu Banco Virtual"<<setw(16)<<"*"
		<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
		<<"\n"<<setw(85)<<"************************************************************";
	
		//Validacion del Nombre
	cout<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
		<<"\n"<<setw(26)<<"*"<<setw(49)<<"-Ingrese su primer nombre y primer apellido: "<<setw(10)<<"*"
		<<"\n"<<setw(28)<<"***"<<setw(57)<<"***"
		<<"\n"<<setw(35)<<"-> ";
	
	getline(cin, nombre_y_apellido);
	
	while(nombre_y_apellido.empty()){
		clear();
		cout<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
			<<"\n"<<setw(26)<<"*"<<setw(55)<<"----------------------------------------------------"<<setw(4)<<"*";
		cerr<<"\n"<<setw(26)<<"*"<<setw(55)<<"ERROR :O | El campo esta vacio, ingrese una opcion."<<setw(4)<<"*";
		cout<<"\n"<<setw(26)<<"*"<<setw(55)<<"----------------------------------------------------"<<setw(4)<<"*"
			<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
			<<"\n"<<setw(28)<<"***"<<setw(57)<<"***";
		continuar();
		clear();
		cout<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
			<<"\n"<<setw(26)<<"*"<<setw(49)<<"-Ingrese su primer nombre y primer apellido: "<<setw(10)<<"*"
			<<"\n"<<setw(28)<<"***"<<setw(57)<<"***"
			<<"\n"<<setw(35)<<"-> ";
		getline(cin, nombre_y_apellido);
	}
	
	cout<<"\n"<<setw(85)<<"------------------------------------------------------------"
	//cin.ignore();
		<<"\n"<<setw(78)<<">>>> Presione la tecla enter para continuar <<<<"
		<<"\n"<<setw(85)<<"------------------------------------------------------------"
		<<"\n"<<setw(55)<<":V";
	//cin.get();
	limiteCero();
	
		//Ingreso de documento
	cambioDocumento();
	cout<<"\n";
	continuar();
	
		//Ingreso de correo
	preguntaRegistrarCorreo();
	
	
		//Clave aleatoria
	clear();
	cout<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
		<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
		<<"\n"<<setw(26)<<"*"<<setw(13)<<"Hola, "<<nombre_y_apellido<<" esta es su clave,"
		<<"\n"<<setw(26)<<"*"<<setw(52)<<"la cual se ha generado de manera automatica, "<<setw(7)<<"*"
		<<"\n"<<setw(26)<<"*"<<setw(26)<<"desea modificarla? "<<setw(33)<<"*";
	srand(time(NULL));
	key = 0 + rand()%(10000-1);
	claveAutomatica(key);
	
		//Cambio de clave
	preguntaCambioClave();
	

	return 0;
}
//Final Funcion main()




//Inicio Funcion clear()
void clear(){
	system("cls");
	cout<<"\n"<<setw(85)<<"************************************************************"
		<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
		<<"\n"<<setw(26)<<"*"<<setw(43)<<"BIENVENIDO A TU BANCO VIRTUAL"<<setw(16)<<"*"
		<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
		<<"\n"<<setw(85)<<"************************************************************";
}
//Final Funcion clear()




//Inicio Funcion continuar()
void continuar(){
	cout<<"\n"<<setw(85)<<"------------------------------------------------------------"
		<<"\n"<<setw(78)<<">>>> Presione la tecla enter para continuar <<<<"
		<<"\n"<<setw(85)<<"------------------------------------------------------------"
		<<"\n"<<setw(55)<<":V";
	limiteCero();
}
//Final Funcion continuar()




//Inicio Funcion cambioDocumento()
void cambioDocumento(){
	
	clear();
	
	int i;
	char caracter;
	
	cout<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
		<<"\n"<<setw(26)<<"*"<<setw(40)<<"-Ingrese su documento de identidad: "<<setw(19)<<"*"
		<<"\n"<<setw(28)<<"***"<<setw(57)<<"***"
		<<"\n"<<setw(35)<<"-> ";
	
	while(caracter = getch()){ 
		if(caracter == 13){
			documento[i] = '\0';
			break;
			
		} else if(caracter == 8){
			if(i > 0){
				i--;
				cout<<"\b \b";
			}
		} else{
			if(i < longiCedula){
				cout<<caracter;
				documento[i] = caracter;
				i++;
			}
		}
	}
	
	if(i == 0){
		clear();
		cout<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
			<<"\n"<<setw(26)<<"*"<<setw(55)<<"----------------------------------------------------"<<setw(4)<<"*"
			<<"\n"<<setw(26)<<"*"<<setw(55)<<"ERROR :O | El campo esta vacio, ingrese una opcion."<<setw(4)<<"*"
			<<"\n"<<setw(26)<<"*"<<setw(55)<<"----------------------------------------------------"<<setw(4)<<"*"
			<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
			<<"\n"<<setw(28)<<"***"<<setw(57)<<"***";
		continuar();
		cambioDocumento();
	}
	
	if(strlen(documento) < 8){
		clear();
		cout<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
			<<"\n"<<setw(26)<<"*"<<setw(55)<<"----------------------------------------------------"<<setw(4)<<"*";
		cerr<<"\n"<<setw(26)<<"*"<<setw(53)<<"ERROR :O | El documento ingresado no es valido."<<setw(6)<<"*";
		cout<<"\n"<<setw(26)<<"*"<<setw(55)<<"----------------------------------------------------"<<setw(4)<<"*"
			<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
			<<"\n"<<setw(28)<<"***"<<setw(57)<<"***";
		continuar();
		cambioDocumento();
	}
}
//Final Funcion cambioDocumento()




//Inicio Funcion preguntaRegistrarCorreo()
void preguntaRegistrarCorreo(){
	
	clear();
	
	string preguntaCorreo;
	
	cout<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
		<<"\n"<<setw(26)<<"*"<<setw(43)<<"-Desea registrar un correo electronico?"<<setw(16)<<"*"
		<<"\n"<<setw(28)<<"***"<<setw(57)<<"***"
		<<"\n"<<setw(35)<<"s/n: ";

	getline(cin, preguntaCorreo);

	if( preguntaCorreo.empty() ){
		clear();
		cout<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
			<<"\n"<<setw(26)<<"*"<<setw(55)<<"----------------------------------------------------"<<setw(4)<<"*";
		cerr<<"\n"<<setw(26)<<"*"<<setw(55)<<"ERROR :O | El campo esta vacio, ingrese una opcion."<<setw(4)<<"*";
		cout<<"\n"<<setw(26)<<"*"<<setw(55)<<"----------------------------------------------------"<<setw(4)<<"*"
			<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
			<<"\n"<<setw(28)<<"***"<<setw(57)<<"***";
		continuar();
		preguntaRegistrarCorreo();
		
	} else if(preguntaCorreo == "s" || preguntaCorreo == "S" || preguntaCorreo == "si" || preguntaCorreo == "SI" || preguntaCorreo == "sI" || preguntaCorreo == "Si"){
		continuar();
		cambioCorreo();
		
	} else if(preguntaCorreo == "n" || preguntaCorreo == "N" || preguntaCorreo == "no" || preguntaCorreo =="NO" || preguntaCorreo == "nO" || preguntaCorreo == "No"){
		continuar();
		
	} else{
		clear();
		cout<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
			<<"\n"<<setw(26)<<"*"<<setw(55)<<"----------------------------------------------------"<<setw(4)<<"*";
		cerr<<"\n"<<setw(26)<<"*"<<setw(47)<<"ERROR :O | Ingrese una opcion valida."<<setw(12)<<"*";
		cout<<"\n"<<setw(26)<<"*"<<setw(55)<<"----------------------------------------------------"<<setw(4)<<"*"
			<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
			<<"\n"<<setw(28)<<"***"<<setw(57)<<"***";
		continuar();
		preguntaRegistrarCorreo();
	}
}
//Final Funcion preguntaRegistrarCorreo()




//Inicio Funcion cambioCorreo()
void cambioCorreo(){
	
	clear();
	
	string correo;
	char caracter = '@';
	bool b;
	
	cout<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
		<<"\n"<<setw(26)<<"*"<<setw(48)<<"-Ingrese el correo electronico a registrar: "<<setw(11)<<"*"
		<<"\n"<<setw(28)<<"***"<<setw(57)<<"***"
		<<"\n"<<setw(35)<<"-> ";
	getline(cin, correo);
	
	if( !correo.empty() ){
		for(int c = 0; c < correo.length(); c++){
			if(correo[c] == caracter) {
				b = true;
			}
		}	
		
		if(b == true){
			clear();
			cout<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(54)<<"++++++++++++++++++++++++++++++++++++++++++++++++++"<<setw(5)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(5)<<"+"<<setw(49)<<"+"<<setw(5)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(5)<<"+"<<setw(46)<<">> Registro de correo electronico exitoso <<"<<setw(3)<<"+"<<setw(5)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(5)<<"+"<<setw(49)<<"+"<<setw(5)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(5)<<"+"<<setw(33)<<"|Recuerde que puede modificar"<<setw(16)<<"+"<<setw(5)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(5)<<"+"<<setw(26)<<"|su correo electronico"<<setw(23)<<"+"<<setw(5)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(5)<<"+"<<setw(31)<<"|desde el menu de opciones."<<setw(18)<<"+"<<setw(5)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(5)<<"+"<<setw(49)<<"+"<<setw(5)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(54)<<"++++++++++++++++++++++++++++++++++++++++++++++++++"<<setw(5)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
				<<"\n"<<setw(28)<<"***"<<setw(57)<<"***";
				
			continuar();
						
		} else if(b == false){
			clear();
			cout<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(55)<<"----------------------------------------------------"<<setw(4)<<"*";
			cerr<<"\n"<<setw(26)<<"*"<<setw(42)<<"|----> :O ERROR :O <----|"<<setw(17)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(54)<<"La direccion de correo electronico no es valida,"<<setw(5)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(27)<<"debe ingresar el '@'."<<setw(32)<<"*";
			cout<<"\n"<<setw(26)<<"*"<<setw(55)<<"----------------------------------------------------"<<setw(4)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
				<<"\n"<<setw(28)<<"***"<<setw(57)<<"***";
			continuar();
			cambioCorreo();
		}
	} else{
		clear();
		cout<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
			<<"\n"<<setw(26)<<"*"<<setw(55)<<"----------------------------------------------------"<<setw(4)<<"*";
		cerr<<"\n"<<setw(26)<<"*"<<setw(55)<<"ERROR :O | El campo esta vacio, ingrese una opcion."<<setw(4)<<"*";
		cout<<"\n"<<setw(26)<<"*"<<setw(55)<<"----------------------------------------------------"<<setw(4)<<"*"
			<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
			<<"\n"<<setw(28)<<"***"<<setw(57)<<"***";
		continuar();
		cambioCorreo();
	}
}
//Final Funcion cambioCorreo()




//Inicio Funcion claveAutomatica(int clave)
void claveAutomatica(int key) {
	cout<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
		<<"\n"<<setw(26)<<"*"<<setw(43)<<"Clave: "<<key<<setw(12)<<"*";
}
//Final Funcion claveAutomatica(int clave)




//Inicio Funcion preguntaCambioClave()
void preguntaCambioClave(){
	
	string modificarClave;
	
	cout<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
		<<"\n"<<setw(28)<<"***"<<setw(57)<<"***"
		<<"\n"<<setw(35)<<"s/n: ";
	getline(cin, modificarClave);
		
	if(modificarClave.empty()){
		clear();
		cout<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
			<<"\n"<<setw(26)<<"*"<<setw(55)<<"----------------------------------------------------"<<setw(4)<<"*";
		cerr<<"\n"<<setw(26)<<"*"<<setw(55)<<"ERROR :O | El campo esta vacio, ingrese una opcion."<<setw(4)<<"*";
		cout<<"\n"<<setw(26)<<"*"<<setw(55)<<"----------------------------------------------------"<<setw(4)<<"*"
			<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
			<<"\n"<<setw(28)<<"***"<<setw(57)<<"***";
		continuar();
		clear();
		cout<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
			<<"\n"<<setw(26)<<"*"<<setw(22)<<"-Esta es su clave "<<key<< ", desea modificarla?"<<setw(13)<<"*";
		preguntaCambioClave();
			
	} else if(modificarClave == "s" || modificarClave == "S" || modificarClave == "si" || modificarClave == "SI" || modificarClave == "sI" || modificarClave == "Si"){
		continuar();
		cambioClave();
		
	} else if (modificarClave == "n" || modificarClave == "N" || modificarClave == "no" || modificarClave == "NO" || modificarClave == "nO" || modificarClave == "No"){
		continuar();
		menuOpciones();

	} else{
		clear();
		cout<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
			<<"\n"<<setw(26)<<"*"<<setw(56)<<"----------------------------------------------------"<<setw(3)<<"*";
		cerr<<"\n"<<setw(26)<<"*"<<setw(48)<<"ERROR :O | Ingrese una opcion valida."<<setw(11)<<"*";
		cout<<"\n"<<setw(26)<<"*"<<setw(56)<<"----------------------------------------------------"<<setw(3)<<"*"
			<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
			<<"\n"<<setw(28)<<"***"<<setw(57)<<"***";
		continuar();
		clear();
		cout<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
			<<"\n"<<setw(26)<<"*"<<setw(22)<<"-Esta es su clave "<<key<< ", desea modificarla?"<<setw(13)<<"*";
		preguntaCambioClave();	
	}
}
//Final Funcion preguntaCambioClave()




//Inicio Funcion menuOpciones()
void menuOpciones(){
	
	clear();
	
	l = 1;
	k = 1;
	
	int opcionMenu;
	
	cout<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
		<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
		<<"\n"<<setw(26)<<"*"<<setw(53)<<"++++++++++++++++++++++++++++++++++++++++++++++++"<<setw(6)<<"*"
		<<"\n"<<setw(26)<<"*"<<setw(6)<<"+"<<setw(47)<<"+"<<setw(6)<<"*"
		<<"\n"<<setw(26)<<"*"<<setw(6)<<"+"<<setw(36)<<"|--> Menu de opciones <--|"<<setw(11)<<"+"<<setw(6)<<"*"
		<<"\n"<<setw(26)<<"*"<<setw(6)<<"+"<<setw(47)<<"+"<<setw(6)<<"*"
		<<"\n"<<setw(26)<<"*"<<setw(6)<<"+"<<setw(19)<<"1. Ingresar dinero"<<setw(23)<<"5. Ver mis datos"<<setw(5)<<"+"<<setw(6)<<"*"
		<<"\n"<<setw(26)<<"*"<<setw(6)<<"+"<<setw(18)<<"2. Retirar dinero"<<setw(27)<<"6. Modificar nombre"<<setw(2)<<"+"<<setw(6)<<"*"
		<<"\n"<<setw(26)<<"*"<<setw(6)<<"+"<<setw(18)<<"3. Transferencias"<<setw(24)<<"7. Cambiar clave"<<setw(5)<<"+"<<setw(6)<<"*"
		<<"\n"<<setw(26)<<"*"<<setw(6)<<"+"<<setw(13)<<"4. Ver saldo"<<setw(21)<<"8. Salir"<<setw(13)<<"+"<<setw(6)<<"*"
		<<"\n"<<setw(26)<<"*"<<setw(6)<<"+"<<setw(47)<<"+"<<setw(6)<<"*"
		<<"\n"<<setw(26)<<"*"<<setw(53)<<"++++++++++++++++++++++++++++++++++++++++++++++++"<<setw(6)<<"*"
		<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
		<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
		<<"\n"<<setw(28)<<"***"<<setw(57)<<"***"
		<<"\n"<<setw(63)<<"Elija una opcion: ";
	cin>>opcionMenu;
	cin.ignore(); // Se coloca despues de un cin para ignore el ultimo \n
	
	
	switch(opcionMenu){
		case 1: 
			if(bloqueoIngreso == true){
				clear();
				cout<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
					<<"\n"<<setw(26)<<"*"<<setw(53)<<"|Usted ya ha superado el numero mayor de intentos"<<setw(6)<<"*"
					<<"\n"<<setw(26)<<"*"<<setw(43)<<"|para realizar el ingreso de su dinero."<<setw(16)<<"*"
					<<"\n"<<setw(26)<<"*"<<setw(37)<<"|Comuniquese al 01-8000-555-666 o"<<setw(22)<<"*"
					<<"\n"<<setw(26)<<"*"<<setw(42)<<"|acerquese a una de nuestras oficinas."<<setw(17)<<"*"
					<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
					<<"\n"<<setw(28)<<"***"<<setw(57)<<"***";
				continuar();
				menuOpciones();
		
			} else{
				ingresarDinero();
			}
		
		case 2:
			if(bloqueoRetiro == true){
				clear();
				cout<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
					<<"\n"<<setw(26)<<"*"<<setw(53)<<"|Usted ya ha superado el numero mayor de intentos"<<setw(6)<<"*"
					<<"\n"<<setw(26)<<"*"<<setw(42)<<"|para realizar el retiro de su dinero."<<setw(17)<<"*"
					<<"\n"<<setw(26)<<"*"<<setw(37)<<"|Comuniquese al 01-8000-555-666 o"<<setw(22)<<"*"
					<<"\n"<<setw(26)<<"*"<<setw(42)<<"|acerquese a una de nuestras oficinas."<<setw(17)<<"*"
					<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
					<<"\n"<<setw(28)<<"***"<<setw(57)<<"***";
				continuar();
				menuOpciones();
		
			} else{
				retirarDinero();
			}
		
		case 3:
			if(bloqueoTransaccion == true){
				clear();
				cout<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
					<<"\n"<<setw(26)<<"*"<<setw(50)<<"|Ha superado el numero mayor de intentos,"<<setw(9)<<"*"
					<<"\n"<<setw(26)<<"*"<<setw(50)<<"|para realizar la transferencia de dinero"<<setw(9)<<"*"
					<<"\n"<<setw(26)<<"*"<<setw(42)<<"|comuniquese al 01-8000-555-666 o"<<setw(17)<<"*"
					<<"\n"<<setw(26)<<"*"<<setw(47)<<"|acerquese a una de nuestras oficinas."<<setw(12)<<"*"
					<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
					<<"\n"<<setw(28)<<"***"<<setw(57)<<"***";
				continuar();
				menuOpciones();
				
			} else{
				transferencias(); 
			}
				
		//case 4: verSaldo(); break;
		//case 5: verMisDatos(); break;
		//case 6: modificarNombre(); break;
		//case 7: clearCambioClave(); cambiarClave(); break;
		//case 8: salir(); break;
		default: clear(); cout<<"\n\t\tLa opcion no es correcta, intentelo de nuevo."; menuOpciones();
	}
}
//Final Funcion menuOpciones()




//Inicio Funcion validarClaveGlobal()
void validarClaveGlobal(){
	
	int i;
	
	cout<<"\n"<<setw(26)<<"*"<<setw(59)<<"*";
	cout<<"\n"<<setw(26)<<"*"<<setw(39)<<"-Ingrese su clave, tiene 3 intentos"<<setw(20)<<"*";
	cout<<"\n"<<setw(28)<<"***"<<setw(57)<<"***";
	cout<<"\n"<<setw(35)<<"-> ";
	
	while(caracter = getch()){ //No mostrar cuando escribe
		if(caracter == 13){ //tecla de enter
			password[i] = '\0'; //caracter nulo para indicar el final de una cadena, si doy enter y no hay nada no me arroja el cacter del enter
			break;

		} else if(caracter == 27){
			clear();
			menuOpciones();
			
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




//Inicio Funcion limiteCero()
void limiteCero(){
	
	char caracter;
	
	while(caracter = getch()){ 
		if(caracter == 13){
			break;
		}
	}
}
//Inicio Funcion limiteCero()




//Inicio Funcion escape()
void escape(){

	int i;
	char caracter;
	
	while(caracter = getch()){ 
		if(caracter == 13){
			valor[i] = '\0';
			break;

		} else if(caracter == 27){
			clear();
			menuOpciones();
			
		} else if(caracter == 8){
			if(i > 0){
				i--;
				cout<<"\b \b";
			}
		} else{
			if(i < longiEscape){
				cout<<caracter;
				valor[i] = caracter;
				i++;
			}
		}
	}
	e = i;
}
//Final Funcion escape()




//Inicio Funcion cambioClave()
void cambioClave(){
	
	clearCambioClave();
	validarClaveGlobal();
	
	if(j == 0){
		clearCambioClave();		
		cout<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
			<<"\n"<<setw(26)<<"*"<<setw(55)<<"----------------------------------------------------"<<setw(4)<<"*";
		cerr<<"\n"<<setw(26)<<"*"<<setw(39)<<"ERROR :O |El campo esta vacio,"<<setw(20)<<"*"
			<<"\n"<<setw(26)<<"*"<<setw(49)<<"|No ha ingresado ningun numero."<<setw(10)<<"*";
		cout<<"\n"<<setw(26)<<"*"<<setw(55)<<"----------------------------------------------------"<<setw(4)<<"*"
			<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
			<<"\n"<<setw(28)<<"***"<<setw(57)<<"***";
		continuar();
		cambioClave();
	}
	
	if(j < longitud){
		clearCambioClave();
		
		while(k < 3){
			cout<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(55)<<"----------------------------------------------------"<<setw(4)<<"*";
			cerr<<"\n"<<setw(26)<<"*"<<setw(49)<<"ERROR :O | Debe ingresar una clave valida."<<setw(10)<<"*";
			cout<<"\n"<<setw(26)<<"*"<<setw(55)<<"----------------------------------------------------"<<setw(4)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(35)<<">> Numero de intentos: "<<k<<" de 3 <<"<<setw(15)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
				<<"\n"<<setw(28)<<"***"<<setw(57)<<"***";
			continuar();
			k++;
			cambioClave(); 
		}
		
		if(k > 2){
			clearCambioClaveDos();
			cout<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(35)<<">> Numero de intentos: "<<k<<" de 3 <<"<<setw(15)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(50)<<"|Ha superado el numero mayor de intentos,"<<setw(9)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(45)<<"|para realizar el cambio de su clave"<<setw(14)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(42)<<"|comuniquese al 01-8000-555-666 o"<<setw(17)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(47)<<"|acerquese a una de nuestras oficinas."<<setw(12)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
				<<"\n"<<setw(28)<<"***"<<setw(57)<<"***";
			continuar();
			menuOpciones();
		}
			
	} else{
		continuar();
		seeKey();
	}
}
//Final Funcion cambioClave()




//Inicio Funcion seeKey()
void seeKey(){
	
	clearCambioClaveDos();
	string verClave;
	
	cout<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
		<<"\n"<<setw(26)<<"*"<<setw(44)<<">>> CAMBIO DE CLAVE EXITOSO <<<"<<setw(15)<<"*"
		<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
		<<"\n"<<setw(26)<<"*"<<setw(24)<<"-Desea ver su clave?"<<setw(35)<<"*"
		<<"\n"<<setw(28)<<"***"<<setw(57)<<"***"
		<<"\n"<<setw(35)<<"s/n: ";
		
	getline(cin, verClave);
	
	if(verClave.empty()){
		clearCambioClaveDos();
		cout<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
			<<"\n"<<setw(26)<<"*"<<setw(55)<<"----------------------------------------------------"<<setw(4)<<"*";
		cerr<<"\n"<<setw(26)<<"*"<<setw(55)<<"ERROR :O | El campo esta vacio, ingrese una opcion."<<setw(4)<<"*";
		cout<<"\n"<<setw(26)<<"*"<<setw(55)<<"----------------------------------------------------"<<setw(4)<<"*"
			<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
			<<"\n"<<setw(28)<<"***"<<setw(57)<<"***";
		continuar();
		seeKey();
		
	} else if(verClave == "s" || verClave == "S" || verClave == "si" || verClave == "SI" || verClave == "sI" || verClave == "Si"){
		key = atoi(password);
		clearCambioClaveDos();
		cout<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
			<<"\n"<<setw(26)<<"*"<<setw(49)<<"++++++++++++++++++++++++++++++++++++++++++"<<setw(10)<<"*"
			<<"\n"<<setw(26)<<"*"<<setw(8)<<"+"<<setw(41)<<"+"<<setw(10)<<"*"
			<<"\n"<<setw(26)<<"*"<<setw(8)<<"+"<<setw(27)<<">>> Su nueva clave es: "<<key<<" <<<"<<setw(6)<<"+"<<setw(10)<<"*"
			<<"\n"<<setw(26)<<"*"<<setw(8)<<"+"<<setw(41)<<"+"<<setw(10)<<"*"
			<<"\n"<<setw(26)<<"*"<<setw(8)<<"+"<<setw(38)<<"|Recuerde que puede cambiar su clave"<<setw(3)<<"+"<<setw(10)<<"*"
			<<"\n"<<setw(26)<<"*"<<setw(8)<<"+"<<setw(29)<<"|desde el menu de opciones."<<setw(12)<<"+"<<setw(10)<<"*"
			<<"\n"<<setw(26)<<"*"<<setw(8)<<"+"<<setw(41)<<"+"<<setw(10)<<"*"
			<<"\n"<<setw(26)<<"*"<<setw(49)<<"++++++++++++++++++++++++++++++++++++++++++"<<setw(10)<<"*"
			<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
			<<"\n"<<setw(28)<<"***"<<setw(57)<<"***";
		continuar();
		menuOpciones();
		
	} else if (verClave == "n" || verClave == "N" || verClave == "no" || verClave == "NO" || verClave == "nO" || verClave == "No"){
		key = atoi(password);
		continuar();
		menuOpciones();
			
	} else{
		clearCambioClaveDos();
		cout<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
			<<"\n"<<setw(26)<<"*"<<setw(55)<<"----------------------------------------------------"<<setw(4)<<"*";
		cerr<<"\n"<<setw(26)<<"*"<<setw(47)<<"ERROR :O | Ingrese una opcion valida."<<setw(12)<<"*";
		cout<<"\n"<<setw(26)<<"*"<<setw(55)<<"----------------------------------------------------"<<setw(4)<<"*"
			<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
			<<"\n"<<setw(28)<<"***"<<setw(57)<<"***";
		continuar();
		seeKey();
	}
}
//Final Funcion seeKey()




//Inicio Funcion clearCambioClave()
void clearCambioClave(){
	system("cls");
	cout<<"\n"<<setw(85)<<"************************************************************"
		<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
		<<"\n"<<setw(26)<<"*"<<setw(43)<<"BIENVENIDO A TU BANCO VIRTUAL"<<setw(16)<<"*"
		<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
		<<"\n"<<setw(26)<<"*"<<setw(40)<<"|--> CAMBIO DE CLAVE <--|"<<setw(19)<<"*"
		<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
		<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
		<<"\n"<<setw(26)<<"*"<<setw(40)<<">>|Si desea cancelar el procedimiento,"<<setw(19)<<"*"
		<<"\n"<<setw(26)<<"*"<<setw(49)<<"|presione la tecla 'Esc' en cualquier momento"<<setw(10)<<"*"
		<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
		<<"\n"<<setw(85)<<"************************************************************";	
}
//Final Funcion clearCambioClave()




//Inicio Funcion clearCambioClaveDos()
void clearCambioClaveDos(){
	system("cls");
	cout<<"\n"<<setw(85)<<"************************************************************"
		<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
		<<"\n"<<setw(26)<<"*"<<setw(43)<<"BIENVENIDO A TU BANCO VIRTUAL"<<setw(16)<<"*"
		<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
		<<"\n"<<setw(26)<<"*"<<setw(40)<<"|--> CAMBIO DE CLAVE <--|"<<setw(19)<<"*"
		<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
		<<"\n"<<setw(85)<<"************************************************************";
}
//Final Funcion clearCambioClaveDos()




//Inicio Funcion clearIngresar()
void clearIngresar(){
	system("cls");
	cout<<"\n"<<setw(85)<<"************************************************************"
		<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
		<<"\n"<<setw(26)<<"*"<<setw(43)<<"BIENVENIDO A TU BANCO VIRTUAL"<<setw(16)<<"*"
		<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
		<<"\n"<<setw(26)<<"*"<<setw(41)<<"|--> INGRESAR DINERO <--|"<<setw(18)<<"*"
		<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
		<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
		<<"\n"<<setw(26)<<"*"<<setw(43)<<">>|Si desea cancelar el procedimiento,"<<setw(16)<<"*"
		<<"\n"<<setw(26)<<"*"<<setw(52)<<"|presione la tecla 'Esc' en cualquier momento"<<setw(7)<<"*"
		<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
		<<"\n"<<setw(85)<<"************************************************************";
}
//Final Funcion clearIngresar()




//Inicio Funcion clearIngresarDos()
void clearIngresarDos(){
	system("cls");
	cout<<"\n"<<setw(85)<<"************************************************************"
		<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
		<<"\n"<<setw(26)<<"*"<<setw(43)<<"BIENVENIDO A TU BANCO VIRTUAL"<<setw(16)<<"*"
		<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
		<<"\n"<<setw(26)<<"*"<<setw(41)<<"|--> INGRESAR DINERO <--|"<<setw(18)<<"*"
		<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
		<<"\n"<<setw(85)<<"************************************************************";
}
//Final Funcion clearIngresarDos()




//Inicio Funcion clearRetirar()
void clearRetirar(){
	system("cls");
	cout<<"\n"<<setw(85)<<"************************************************************"
		<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
		<<"\n"<<setw(26)<<"*"<<setw(43)<<"BIENVENIDO A TU BANCO VIRTUAL"<<setw(16)<<"*"
		<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
		<<"\n"<<setw(26)<<"*"<<setw(40)<<"|--> RETIRAR DINERO <--|"<<setw(19)<<"*"
		<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
		<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
		<<"\n"<<setw(26)<<"*"<<setw(43)<<">>|Si desea cancelar el procedimiento,"<<setw(16)<<"*"
		<<"\n"<<setw(26)<<"*"<<setw(52)<<"|presione la tecla 'Esc' en cualquier momento"<<setw(7)<<"*"
		<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
		<<"\n"<<setw(85)<<"************************************************************";
}
//Final Funcion clearRetirar()




//Inicio Funcion clearRetirarDos()
void clearRetirarDos(){
	system("cls");
	cout<<"\n"<<setw(85)<<"************************************************************"
		<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
		<<"\n"<<setw(26)<<"*"<<setw(43)<<"BIENVENIDO A TU BANCO VIRTUAL"<<setw(16)<<"*"
		<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
		<<"\n"<<setw(26)<<"*"<<setw(40)<<"|--> RETIRAR DINERO <--|"<<setw(19)<<"*"
		<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
		<<"\n"<<setw(85)<<"************************************************************";
}
//Final Funcion clearRetirarDos()




//Inicio Funcion clearTransferencias()
void clearTransferencias(){
	system("cls");
	cout<<"\n"<<setw(85)<<"************************************************************"
		<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
		<<"\n"<<setw(26)<<"*"<<setw(43)<<"BIENVENIDO A TU BANCO VIRTUAL"<<setw(16)<<"*"
		<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
		<<"\n"<<setw(26)<<"*"<<setw(40)<<"|--> TRANSFERENCIA <--|"<<setw(19)<<"*"
		<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
		<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
		<<"\n"<<setw(26)<<"*"<<setw(43)<<">>|Si desea cancelar el procedimiento,"<<setw(16)<<"*"
		<<"\n"<<setw(26)<<"*"<<setw(52)<<"|presione la tecla 'Esc' en cualquier momento"<<setw(7)<<"*"
		<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
		<<"\n"<<setw(85)<<"************************************************************";
}
//Final Funcion clearTransferencias()




//Inicio Funcion clearTransferenciasDos()
void clearTransferenciasDos(){
	system("cls");
	cout<<"\n"<<setw(85)<<"************************************************************"
		<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
		<<"\n"<<setw(26)<<"*"<<setw(43)<<"BIENVENIDO A TU BANCO VIRTUAL"<<setw(16)<<"*"
		<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
		<<"\n"<<setw(26)<<"*"<<setw(40)<<"|--> TRANSFERENCIA <--|"<<setw(19)<<"*"
		<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
		<<"\n"<<setw(85)<<"************************************************************";
}
//Final Funcion clearTransferenciasDos()




//Inicio Funcion ingresarDinero()
void ingresarDinero(){
	
	clearIngresar(); 
	
	cout<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
		<<"\n"<<setw(26)<<"*"<<setw(34)<<"-Cuanto dinero desea ingresar?"<<setw(25)<<"*"
		<<"\n"<<setw(28)<<"***"<<setw(57)<<"***"
		<<"\n"<<setw(35)<<"$ ";
	escape();
	
	if(e == 0){
		clearIngresar();
		cout<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
			<<"\n"<<setw(26)<<"*"<<setw(55)<<"----------------------------------------------------"<<setw(4)<<"*";
		cerr<<"\n"<<setw(26)<<"*"<<setw(52)<<"ERROR :O El campo esta vacio, ingrese un valor."<<setw(7)<<"*";
		cout<<"\n"<<setw(26)<<"*"<<setw(55)<<"----------------------------------------------------"<<setw(4)<<"*"
			<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
			<<"\n"<<setw(28)<<"***"<<setw(57)<<"***";
		continuar();
		ingresarDinero();
	}
	
		//Convertir un char a int 
	dineroIngreso = atoi(valor);
	
	if(dineroIngreso > 1000000){
		clearIngresar();		
		cout<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
			<<"\n"<<setw(26)<<"*"<<setw(55)<<"----------------------------------------------------"<<setw(4)<<"*";
		cerr<<"\n"<<setw(26)<<"*"<<setw(39)<<"ERROR :O |Lo maximo permitido"<<setw(20)<<"*"
			<<"\n"<<setw(26)<<"*"<<setw(47)<<"|para ingresar es $1.000.000"<<setw(12)<<"*";
		cout<<"\n"<<setw(26)<<"*"<<setw(55)<<"----------------------------------------------------"<<setw(4)<<"*"
			<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
			<<"\n"<<setw(28)<<"***"<<setw(57)<<"***";
		continuar();
		ingresarDinero();
	
	} else if (dineroIngreso > 0 && dineroIngreso < 20000){
		clearIngresar();
		cout<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
			<<"\n"<<setw(26)<<"*"<<setw(55)<<"----------------------------------------------------"<<setw(4)<<"*";
		cerr<<"\n"<<setw(26)<<"*"<<setw(40)<<"ERROR :O |Lo minimo permitido"<<setw(19)<<"*"
			<<"\n"<<setw(26)<<"*"<<setw(45)<<"|para ingresar es $20.000"<<setw(14)<<"*";
		cout<<"\n"<<setw(26)<<"*"<<setw(55)<<"----------------------------------------------------"<<setw(4)<<"*"
			<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
			<<"\n"<<setw(28)<<"***"<<setw(57)<<"***";
		continuar();
		ingresarDinero();
			
	} else if(dineroIngreso > 19999 && dineroIngreso < 1000001){
		cout<<"\n";
		continuar();
		validarClaveIngresoDinero();
		
	} else{
		clearIngresar();
		cout<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
			<<"\n"<<setw(26)<<"*"<<setw(55)<<"----------------------------------------------------"<<setw(4)<<"*";
		cerr<<"\n"<<setw(26)<<"*"<<setw(50)<<"ERROR :O | El valor ingresado no es valido."<<setw(9)<<"*";
		cout<<"\n"<<setw(26)<<"*"<<setw(55)<<"----------------------------------------------------"<<setw(4)<<"*"
			<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
			<<"\n"<<setw(28)<<"***"<<setw(57)<<"***";
		continuar();
		ingresarDinero();
	}
}
//Final Funcion ingresarDinero()




//Inicio Funcion validarClaveIngresoDinero()
void validarClaveIngresoDinero(){
	
	clearIngresar();
	validarClaveGlobal();
	
	if(j == 0){
		clearIngresar();
		cout<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
			<<"\n"<<setw(26)<<"*"<<setw(55)<<"----------------------------------------------------"<<setw(4)<<"*";
		cerr<<"\n"<<setw(26)<<"*"<<setw(49)<<"ERROR :O | No ha ingresado ningun numero."<<setw(10)<<"*";
		cout<<"\n"<<setw(26)<<"*"<<setw(55)<<"----------------------------------------------------"<<setw(4)<<"*"
			<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
			<<"\n"<<setw(28)<<"***"<<setw(57)<<"***";
		continuar();
		validarClaveIngresoDinero();
	}
	
	if(j < longitud){
	
		while(l < 3){
			clearIngresar();
			cout<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(55)<<"----------------------------------------------------"<<setw(4)<<"*";
			cerr<<"\n"<<setw(26)<<"*"<<setw(45)<<"ERROR :O | La clave no es valida."<<setw(14)<<"*";
			cout<<"\n"<<setw(26)<<"*"<<setw(55)<<"----------------------------------------------------"<<setw(4)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(35)<<">> Numero de intentos: "<<l<<" de 3 <<"<<setw(15)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
				<<"\n"<<setw(28)<<"***"<<setw(57)<<"***";
			continuar();
			l++;
			validarClaveIngresoDinero();
		}
		
		if(l > 2){
			clearIngresarDos();
			bloqueoIngreso = true;
			cout<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(35)<<">> Numero de intentos: "<<l<<" de 3 <<"<<setw(15)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(50)<<"|Ha superado el numero mayor de intentos,"<<setw(9)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(47)<<"|para realizar el ingreso de su dinero"<<setw(12)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(42)<<"|comuniquese al 01-8000-555-666 o"<<setw(17)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(47)<<"|acerquese a una de nuestras oficinas."<<setw(12)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
				<<"\n"<<setw(28)<<"***"<<setw(57)<<"***";
			continuar();
			menuOpciones();
		}
	} else {
		
		valorIngreso = atoi(password);
		
		if(valorIngreso == key){
			cout<<"\n";
			continuar();
			clearIngresarDos();
			dineroTotal += dineroIngreso;
			cout<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(45)<<">>> INGRESO DE DINERO EXITOSO <<<"<<setw(14)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(47)<<"++++++++++++++++++++++++++++++++++++"<<setw(12)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(12)<<"+"<<setw(35)<<"+"<<setw(12)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(12)<<"+"<<setw(27)<<">>Ingreso realizado por: $"<<dineroIngreso<<setw(2)<<"+"<<setw(12)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(12)<<"+"<<setw(35)<<"+"<<setw(12)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(12)<<"+"<<setw(21)<<">>Saldo en cuenta: $"<<dineroTotal<<setw(8)<<"+"<<setw(12)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(12)<<"+"<<setw(35)<<"+"<<setw(12)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(47)<<"++++++++++++++++++++++++++++++++++++"<<setw(12)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
				<<"\n"<<setw(28)<<"***"<<setw(57)<<"***";
			continuar();
			menuOpciones();
		}
		
		while(l < 3){
			clearIngresar();
			cout<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(55)<<"----------------------------------------------------"<<setw(4)<<"*";
			cerr<<"\n"<<setw(26)<<"*"<<setw(45)<<"ERROR :O | La clave no es valida."<<setw(14)<<"*";
			cout<<"\n"<<setw(26)<<"*"<<setw(55)<<"----------------------------------------------------"<<setw(4)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(35)<<">> Numero de intentos: "<<l<<" de 3 <<"<<setw(15)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
				<<"\n"<<setw(28)<<"***"<<setw(57)<<"***";
			continuar();
			l++;
			validarClaveIngresoDinero();
		}
		
		if(l > 2){
			clearIngresarDos();
			bloqueoIngreso = true;
			cout<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(35)<<">> Numero de intentos: "<<l<<" de 3 <<"<<setw(15)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(50)<<"|Ha superado el numero mayor de intentos,"<<setw(9)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(47)<<"|para realizar el ingreso de su dinero"<<setw(12)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(42)<<"|comuniquese al 01-8000-555-666 o"<<setw(17)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(47)<<"|acerquese a una de nuestras oficinas."<<setw(12)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
				<<"\n"<<setw(28)<<"***"<<setw(57)<<"***";
			continuar();
			menuOpciones();
		}
	}
}
//Final Funcion validarClaveIngresoDinero()




//Inicio Funcion retirarDinero()
void retirarDinero(){
	
	clearRetirar(); 
	
	cout<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
		<<"\n"<<setw(26)<<"*"<<setw(34)<<"-Cuanto dinero desea retirar?"<<setw(25)<<"*"
		<<"\n"<<setw(28)<<"***"<<setw(57)<<"***"
		<<"\n"<<setw(35)<<"$ ";
	
	int i;
	char caracter;
	
	while(caracter = getch()){ 
		if(caracter == 13){
			valor[i] = '\0';
			break;

		} else if(caracter == 27){
			clear();
			menuOpciones();
			
		} else if(caracter == 8){
			if(i > 0){
				i--;
				cout<<"\b \b";
			}
		} else{
			if(i < longiRetiro){
				cout<<caracter;
				valor[i] = caracter;
				i++;
			}
		}
	}
	e = i;
	
	if(e == 0){
		clearRetirar();
		cout<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
			<<"\n"<<setw(26)<<"*"<<setw(55)<<"----------------------------------------------------"<<setw(4)<<"*";
		cerr<<"\n"<<setw(26)<<"*"<<setw(52)<<"ERROR :O El campo esta vacio, ingrese un valor."<<setw(7)<<"*";
		cout<<"\n"<<setw(26)<<"*"<<setw(55)<<"----------------------------------------------------"<<setw(4)<<"*"
			<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
			<<"\n"<<setw(28)<<"***"<<setw(57)<<"***";
		continuar();
		retirarDinero();
	}
			
	dineroRetiro = atoi(valor); //Convertir un string a int
	
	if(dineroRetiro > dineroTotal){
		clearRetirar();
		cout<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
			<<"\n"<<setw(26)<<"*"<<setw(55)<<"----------------------------------------------------"<<setw(4)<<"*";
		cerr<<"\n"<<setw(26)<<"*"<<setw(44)<<"ERROR :O | Fondos inuficientes."<<setw(15)<<"*";
		cout<<"\n"<<setw(26)<<"*"<<setw(55)<<"----------------------------------------------------"<<setw(4)<<"*"
			<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
			<<"\n"<<setw(28)<<"***"<<setw(57)<<"***";
		continuar();
		retirarDinero();
	
	} else if (dineroRetiro > 500000){
		clearRetirar();		
		cout<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
			<<"\n"<<setw(26)<<"*"<<setw(55)<<"----------------------------------------------------"<<setw(4)<<"*";
		cerr<<"\n"<<setw(26)<<"*"<<setw(45)<<"ERROR :O |Lo maximo permitido por"<<setw(14)<<"*"
			<<"\n"<<setw(26)<<"*"<<setw(46)<<"|cada retiro son $500.000"<<setw(13)<<"*";
		cout<<"\n"<<setw(26)<<"*"<<setw(55)<<"----------------------------------------------------"<<setw(4)<<"*"
			<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
			<<"\n"<<setw(28)<<"***"<<setw(57)<<"***";
		continuar();
		retirarDinero();
		
	}else if(dineroRetiro > 0 && dineroRetiro < 20000){
		clearRetirar();
		cout<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
			<<"\n"<<setw(26)<<"*"<<setw(55)<<"----------------------------------------------------"<<setw(4)<<"*";
		cerr<<"\n"<<setw(26)<<"*"<<setw(41)<<"ERROR :O |Lo minimo permitido"<<setw(18)<<"*"
			<<"\n"<<setw(26)<<"*"<<setw(45)<<"|para retirar es $20.000"<<setw(14)<<"*";
		cout<<"\n"<<setw(26)<<"*"<<setw(55)<<"----------------------------------------------------"<<setw(4)<<"*"
			<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
			<<"\n"<<setw(28)<<"***"<<setw(57)<<"***";
		continuar();
		retirarDinero();
	
	} else if (dineroRetiro > 19999 && dineroRetiro <= dineroTotal){
		cout<<"\n";
		continuar();
		validarClaveRetiroDinero();
			
	} else {
		clearRetirar();
		cout<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
			<<"\n"<<setw(26)<<"*"<<setw(56)<<"----------------------------------------------------"<<setw(3)<<"*";
		cerr<<"\n"<<setw(26)<<"*"<<setw(51)<<"ERROR :O | El valor ingresado no es valido."<<setw(8)<<"*";
		cout<<"\n"<<setw(26)<<"*"<<setw(56)<<"----------------------------------------------------"<<setw(3)<<"*"
			<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
			<<"\n"<<setw(28)<<"***"<<setw(57)<<"***";
		continuar();
		retirarDinero();
	}
}
//Final Funcion retirarDinero()




//Inicio Funcion validarClaveRetiroDinero()
void validarClaveRetiroDinero(){
	
	clearRetirar();
	validarClaveGlobal();
	
	if(j == 0){
		clearRetirar();
		cout<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
			<<"\n"<<setw(26)<<"*"<<setw(55)<<"----------------------------------------------------"<<setw(4)<<"*";
		cerr<<"\n"<<setw(26)<<"*"<<setw(49)<<"ERROR :O | No ha ingresado ningun numero."<<setw(10)<<"*";
		cout<<"\n"<<setw(26)<<"*"<<setw(55)<<"----------------------------------------------------"<<setw(4)<<"*"
			<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
			<<"\n"<<setw(28)<<"***"<<setw(57)<<"***";
		continuar();
		validarClaveRetiroDinero();
	}
	
	if(j < longitud){
	
		while(k < 3){
			clearRetirar();
			cout<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(55)<<"----------------------------------------------------"<<setw(4)<<"*";
			cerr<<"\n"<<setw(26)<<"*"<<setw(45)<<"ERROR :O | La clave no es valida."<<setw(14)<<"*";
			cout<<"\n"<<setw(26)<<"*"<<setw(55)<<"----------------------------------------------------"<<setw(4)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(35)<<">> Numero de intentos: "<<k<<" de 3 <<"<<setw(15)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
				<<"\n"<<setw(28)<<"***"<<setw(57)<<"***";
			continuar();
			k++;
			validarClaveRetiroDinero();
		}
		
		if(k > 2){
			clearRetirarDos();
			bloqueoRetiro = true;
			cout<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(35)<<">> Numero de intentos: "<<k<<" de 3 <<"<<setw(15)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(50)<<"|Ha superado el numero mayor de intentos,"<<setw(9)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(46)<<"|para realizar el retiro de su dinero"<<setw(13)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(42)<<"|comuniquese al 01-8000-555-666 o"<<setw(17)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(47)<<"|acerquese a una de nuestras oficinas."<<setw(12)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
				<<"\n"<<setw(28)<<"***"<<setw(57)<<"***";
			continuar();
			menuOpciones();
		}
		
	} else {
		
		valorRetiro = atoi(password);
		
		if(valorRetiro == key){
			cout<<"\n";
			continuar();
			clearRetirarDos();
			dineroTotal -= dineroRetiro;
			cout<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(45)<<">>> RETIRO DE DINERO EXITOSO <<<"<<setw(14)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(46)<<"+++++++++++++++++++++++++++++++++++"<<setw(13)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(12)<<"+"<<setw(34)<<"+"<<setw(13)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(12)<<"+"<<setw(26)<<">>Retiro realizado por: $"<<dineroRetiro<<setw(2)<<"+"<<setw(13)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(12)<<"+"<<setw(34)<<"+"<<setw(13)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(12)<<"+"<<setw(21)<<">>Saldo en cuenta: $"<<dineroTotal<<setw(7)<<"+"<<setw(13)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(12)<<"+"<<setw(34)<<"+"<<setw(13)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(46)<<"+++++++++++++++++++++++++++++++++++"<<setw(13)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
				<<"\n"<<setw(28)<<"***"<<setw(57)<<"***";
			continuar();
			menuOpciones();
		}
		
		while(k < 3){
			clearRetirar();
			cout<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(55)<<"----------------------------------------------------"<<setw(4)<<"*";
			cerr<<"\n"<<setw(26)<<"*"<<setw(45)<<"ERROR :O | La clave no es valida."<<setw(14)<<"*";
			cout<<"\n"<<setw(26)<<"*"<<setw(55)<<"----------------------------------------------------"<<setw(4)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(35)<<">> Numero de intentos: "<<k<<" de 3 <<"<<setw(15)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
				<<"\n"<<setw(28)<<"***"<<setw(57)<<"***";
			continuar();
			k++;
			validarClaveRetiroDinero();
		}
		
		if(k > 2){
			clearRetirarDos();
			bloqueoRetiro = true;
			cout<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(35)<<">> Numero de intentos: "<<k<<" de 3 <<"<<setw(15)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(50)<<"|Ha superado el numero mayor de intentos,"<<setw(9)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(46)<<"|para realizar el retiro de su dinero"<<setw(13)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(42)<<"|comuniquese al 01-8000-555-666 o"<<setw(17)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(47)<<"|acerquese a una de nuestras oficinas."<<setw(12)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
				<<"\n"<<setw(28)<<"***"<<setw(57)<<"***";
			continuar();
			limiteCero();
			menuOpciones();
		}
	}
}
//Final Funcion validarClaveRetiroDinero()




//Inicio Funcion transferencias()
void transferencias(){
	
	clearTransferencias();
	
	cout<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
		<<"\n"<<setw(26)<<"*"<<setw(57)<<">>Por favor indique a donde quiere transferir el dinero."<<setw(2)<<"*"
		<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
		<<"\n"<<setw(26)<<"*"<<setw(44)<<"1. A Cuenta de Ahorros Tu banco virtual."<<setw(15)<<"*"
		<<"\n"<<setw(26)<<"*"<<setw(43)<<"2. A Cuenta Corriente Tu banco virtual."<<setw(16)<<"*"
		<<"\n"<<setw(26)<<"*"<<setw(20)<<"3. A otro Banco."<<setw(39)<<"*"
		<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
		<<"\n"<<setw(26)<<"*"<<setw(22)<<"-Elija una opcion:"<<setw(37)<<"*"
		<<"\n"<<setw(28)<<"***"<<setw(57)<<"***"
		<<"\n"<<setw(35)<<"-> ";
	escape();
	
	if(e == 0){
		clearTransferencias();
		cout<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
			<<"\n"<<setw(26)<<"*"<<setw(55)<<"----------------------------------------------------"<<setw(4)<<"*";
		cerr<<"\n"<<setw(26)<<"*"<<setw(52)<<"ERROR :O El campo esta vacio, ingrese un valor."<<setw(7)<<"*";
		cout<<"\n"<<setw(26)<<"*"<<setw(55)<<"----------------------------------------------------"<<setw(4)<<"*"
			<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
			<<"\n"<<setw(28)<<"***"<<setw(57)<<"***";
		continuar();
		transferencias();
	}
	
	int opcionTransferencia = atoi(valor);
	
	switch(opcionTransferencia){
		case 1:
		cout<<"\n";
		continuar();
		cuentaAhorros();
		
		case 2:
		cout<<"\n";
		continuar();
		cuentaCorriente();
		
		case 3:
		cout<<"\n";
		continuar();
		otrosBancos();
		
		default:
		clearTransferencias();
		cout<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
			<<"\n"<<setw(26)<<"*"<<setw(55)<<"----------------------------------------------------"<<setw(4)<<"*";
		cerr<<"\n"<<setw(26)<<"*"<<setw(46)<<"ERROR :O |La opcion no es correcta,"<<setw(13)<<"*"
			<<"\n"<<setw(26)<<"*"<<setw(40)<<"|intentelo de nuevo."<<setw(19)<<"*";
		cout<<"\n"<<setw(26)<<"*"<<setw(55)<<"----------------------------------------------------"<<setw(4)<<"*"
			<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
			<<"\n"<<setw(28)<<"***"<<setw(57)<<"***";
		continuar();
		transferencias();
	}
}
//Final Funcion transferencias()




//Inicio Funcion cuentaAhorros()
void cuentaAhorros(){
	
	validarNumeroCuenta();
}
//Final Funcion cuentaAhorros()




//Inicio Funcion validarNumeroCuenta()
void validarNumeroCuenta(){
	
	clearTransferencias();
	
	cout<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
		<<"\n"<<setw(26)<<"*"<<setw(45)<<">>>|Por favor complete todos los datos"<<setw(14)<<"*"
		<<"\n"<<setw(26)<<"*"<<setw(45)<<"|para continuar con la transaccion."<<setw(14)<<"*"
		<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
		<<"\n"<<setw(26)<<"*"<<setw(22)<<"-Numero de Cuenta:"<<setw(37)<<"*"
		<<"\n"<<setw(28)<<"***"<<setw(57)<<"***"
		<<"\n"<<setw(35)<<"-> ";
	
	
	int i;
	char caracter;
	
	while(caracter = getch()){ 
		if(caracter == 13){
			numeroCuenta[i] = '\0';
			break;

		} else if(caracter == 27){
			clear();
			menuOpciones();
			
		} else if(caracter == 8){
			if(i > 0){
				i--;
				cout<<"\b \b";
			}
		} else{
			if(i < longiNumeroCuenta){
				cout<<caracter;
				numeroCuenta[i] = caracter;
				i++;
			}
		}
	}
	
	if(i == 0){
		clearTransferencias();
		cout<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
			<<"\n"<<setw(26)<<"*"<<setw(55)<<"----------------------------------------------------"<<setw(4)<<"*";
		cerr<<"\n"<<setw(26)<<"*"<<setw(52)<<"ERROR :O El campo esta vacio, ingrese un valor."<<setw(7)<<"*";
		cout<<"\n"<<setw(26)<<"*"<<setw(55)<<"----------------------------------------------------"<<setw(4)<<"*"
			<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
			<<"\n"<<setw(28)<<"***"<<setw(57)<<"***";
		continuar();
		validarNumeroCuenta();
	}
	
	if(strlen(numeroCuenta) < longiNumeroCuenta){
		clearTransferencias();
		cout<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
			<<"\n"<<setw(26)<<"*"<<setw(55)<<"----------------------------------------------------"<<setw(4)<<"*";
		cerr<<"\n"<<setw(26)<<"*"<<setw(50)<<"ERROR :O |El numero ingresado no es valido."<<setw(9)<<"*";
		cout<<"\n"<<setw(26)<<"*"<<setw(55)<<"----------------------------------------------------"<<setw(4)<<"*"
			<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
			<<"\n"<<setw(28)<<"***"<<setw(57)<<"***";
		continuar();
		validarNumeroCuenta();	
		
	} else if(strlen(numeroCuenta) == longiNumeroCuenta){
		validarCantidadTransferir();
	}	
}
//Final Funcion validarNumeroCuenta()




//Inicio Funcion validarCantidadTransferir()
void validarCantidadTransferir(){
	
	clearTransferencias();
	
	cout<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
		<<"\n"<<setw(26)<<"*"<<setw(45)<<">>>|Por favor complete todos los datos"<<setw(14)<<"*"
		<<"\n"<<setw(26)<<"*"<<setw(45)<<"|para continuar con la transaccion."<<setw(14)<<"*"
		<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
		<<"\n"<<setw(26)<<"*"<<setw(36)<<"-Cuanto dinero desea transferir:"<<setw(23)<<"*"
		<<"\n"<<setw(28)<<"***"<<setw(57)<<"***"
		<<"\n"<<setw(35)<<"$ ";
	escape();
	
	if(e == 0){
		clearTransferencias();
		cout<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
			<<"\n"<<setw(26)<<"*"<<setw(55)<<"----------------------------------------------------"<<setw(4)<<"*";
		cerr<<"\n"<<setw(26)<<"*"<<setw(52)<<"ERROR :O El campo esta vacio, ingrese un valor."<<setw(7)<<"*";
		cout<<"\n"<<setw(26)<<"*"<<setw(55)<<"----------------------------------------------------"<<setw(4)<<"*"
			<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
			<<"\n"<<setw(28)<<"***"<<setw(57)<<"***";
		continuar();
		validarCantidadTransferir();
	}
	
	dineroTransferencia = atoi(valor);
	
	if(dineroTransferencia > dineroTotal){
		clearTransferencias();
		cout<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
			<<"\n"<<setw(26)<<"*"<<setw(55)<<"----------------------------------------------------"<<setw(4)<<"*";
		cerr<<"\n"<<setw(26)<<"*"<<setw(43)<<"ERROR :O Fondos inuficientes."<<setw(16)<<"*";
		cout<<"\n"<<setw(26)<<"*"<<setw(55)<<"----------------------------------------------------"<<setw(4)<<"*"
			<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
			<<"\n"<<setw(28)<<"***"<<setw(57)<<"***";
		continuar();
		validarCantidadTransferir();
	
	} else if (dineroTransferencia > 0 && dineroTransferencia < 20000){
		clearTransferencias();
		cout<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
			<<"\n"<<setw(26)<<"*"<<setw(55)<<"----------------------------------------------------"<<setw(4)<<"*";
		cerr<<"\n"<<setw(26)<<"*"<<setw(40)<<"ERROR :O |Lo minimo permitido"<<setw(19)<<"*"
			<<"\n"<<setw(26)<<"*"<<setw(47)<<"|para transferir es $20.000"<<setw(12)<<"*";
		cout<<"\n"<<setw(26)<<"*"<<setw(55)<<"----------------------------------------------------"<<setw(4)<<"*"
			<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
			<<"\n"<<setw(28)<<"***"<<setw(57)<<"***";
		continuar();
		validarCantidadTransferir();
			
	} else if (dineroTransferencia > 19999 && dineroTransferencia <= dineroTotal){
		cout<<"\n";
		continuar();
		validarClaveTransferenciaDinero();
	
	} else{
		clearTransferencias();
		cout<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
			<<"\n"<<setw(26)<<"*"<<setw(55)<<"----------------------------------------------------"<<setw(4)<<"*";
		cerr<<"\n"<<setw(26)<<"*"<<setw(50)<<"ERROR :O |El valor ingresado no es valido."<<setw(9)<<"*";
		cout<<"\n"<<setw(26)<<"*"<<setw(55)<<"----------------------------------------------------"<<setw(4)<<"*"
			<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
			<<"\n"<<setw(28)<<"***"<<setw(57)<<"***";
		continuar();
		validarCantidadTransferir();
	}
}
//Final Funcion validarCantidadTransferir()




//Inicio Funcion validarClaveTransferenciaDinero()
void validarClaveTransferenciaDinero(){
	
	clearTransferencias();
	validarClaveGlobal();
	
	if(j == 0){
		clearTransferencias();
		cout<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
			<<"\n"<<setw(26)<<"*"<<setw(55)<<"----------------------------------------------------"<<setw(4)<<"*";
		cerr<<"\n"<<setw(26)<<"*"<<setw(49)<<"ERROR :O | No ha ingresado ningun numero."<<setw(10)<<"*";
		cout<<"\n"<<setw(26)<<"*"<<setw(55)<<"----------------------------------------------------"<<setw(4)<<"*"
			<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
			<<"\n"<<setw(28)<<"***"<<setw(57)<<"***";
		continuar();
		validarClaveTransferenciaDinero();
	}
	
	if(j < longitud){
	
		while(l < 3){
			cout<<"\n";
			continuar();
			clearTransferencias();
			cout<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(55)<<"----------------------------------------------------"<<setw(4)<<"*";
			cerr<<"\n"<<setw(26)<<"*"<<setw(45)<<"ERROR :O | La clave no es valida."<<setw(14)<<"*";
			cout<<"\n"<<setw(26)<<"*"<<setw(55)<<"----------------------------------------------------"<<setw(4)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(35)<<">> Numero de intentos: "<<l<<" de 3 <<"<<setw(15)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
				<<"\n"<<setw(28)<<"***"<<setw(57)<<"***";
			continuar();
			l++;
			validarClaveTransferenciaDinero();
		}
		
		if(l > 2){
			clearTransferenciasDos();
			bloqueoTransaccion = true;
			cout<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(35)<<">> Numero de intentos: "<<l<<" de 3 <<"<<setw(15)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(50)<<"|Ha superado el numero mayor de intentos,"<<setw(9)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(50)<<"|para realizar la transferencia de dinero"<<setw(9)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(42)<<"|comuniquese al 01-8000-555-666 o"<<setw(17)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(47)<<"|acerquese a una de nuestras oficinas."<<setw(12)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
				<<"\n"<<setw(28)<<"***"<<setw(57)<<"***";
			continuar();
			menuOpciones();
		}
		
	} else {
		
		valorTransferencia = atoi(password);
		cout<<"\n";
		continuar();
		if(valorTransferencia == key){
			clearTransferenciasDos();
			dineroTotal -= dineroTransferencia;
			cout<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(48)<<">>> TRANSFERENCIA DE DINERO EXITOSA <<<"<<setw(11)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(53)<<"+++++++++++++++++++++++++++++++++++++++++++++++"<<setw(6)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(7)<<"+"<<setw(46)<<"+"<<setw(6)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(7)<<"+"<<setw(33)<<">>Transferencia realizada por: $"<<dineroTransferencia<<setw(7)<<"+"<<setw(6)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(7)<<"+"<<setw(46)<<"+"<<setw(6)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(7)<<"+"<<setw(24)<<">>Al numero de cuenta: "<<numeroCuenta<<setw(2)<<"+"<<setw(6)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(7)<<"+"<<setw(46)<<"+"<<setw(6)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(7)<<"+"<<setw(21)<<">>Saldo en cuenta: $"<<dineroTotal<<setw(19)<<"+"<<setw(6)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(7)<<"+"<<setw(46)<<"+"<<setw(6)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(53)<<"+++++++++++++++++++++++++++++++++++++++++++++++"<<setw(6)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
				<<"\n"<<setw(28)<<"***"<<setw(57)<<"***";
			continuar();
			menuOpciones();
		}
		
		while(l < 3){
			clearTransferencias();
			cout<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(55)<<"----------------------------------------------------"<<setw(4)<<"*";
			cerr<<"\n"<<setw(26)<<"*"<<setw(45)<<"ERROR :O | La clave no es valida."<<setw(14)<<"*";
			cout<<"\n"<<setw(26)<<"*"<<setw(55)<<"----------------------------------------------------"<<setw(4)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(35)<<">> Numero de intentos: "<<l<<" de 3 <<"<<setw(15)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
				<<"\n"<<setw(28)<<"***"<<setw(57)<<"***";
			continuar();
			l++;
			validarClaveTransferenciaDinero();
		}
		
		if(l > 2){
			clearTransferenciasDos();
			bloqueoTransaccion = true;
			cout<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(35)<<">> Numero de intentos: "<<l<<" de 3 <<"<<setw(15)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(50)<<"|Ha superado el numero mayor de intentos,"<<setw(9)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(50)<<"|para realizar la transferencia de dinero"<<setw(9)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(42)<<"|comuniquese al 01-8000-555-666 o"<<setw(17)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(47)<<"|acerquese a una de nuestras oficinas."<<setw(12)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
				<<"\n"<<setw(28)<<"***"<<setw(57)<<"***";
			continuar();
			menuOpciones();
		}
	}
}
//Final Funcion validarClaveTransferenciaDinero()




//Inicio Funcion cuentaCorriente()
void cuentaCorriente(){
	
	validarNumeroCuenta();
}
//Final Funcion cuentaCorriente()




//Inicio Funcion otrosBancos()
void otrosBancos(){
	
	clearTransferencias();
	
	cout<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
		<<"\n"<<setw(26)<<"*"<<setw(43)<<"1. A cuentas no inscritas."<<setw(16)<<"*"
		<<"\n"<<setw(26)<<"*"<<setw(40)<<"2. Seleccionar cuentas."<<setw(19)<<"*"
		<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
		<<"\n"<<setw(26)<<"*"<<setw(22)<<"-Elija una opcion:"<<setw(37)<<"*"
		<<"\n"<<setw(28)<<"***"<<setw(57)<<"***"
		<<"\n"<<setw(35)<<"-> ";
	escape();
	
	if(e == 0){
		clearTransferencias();
		cout<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
			<<"\n"<<setw(26)<<"*"<<setw(55)<<"----------------------------------------------------"<<setw(4)<<"*";
		cerr<<"\n"<<setw(26)<<"*"<<setw(52)<<"ERROR :O El campo esta vacio, ingrese un valor."<<setw(7)<<"*";
		cout<<"\n"<<setw(26)<<"*"<<setw(55)<<"----------------------------------------------------"<<setw(4)<<"*"
			<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
			<<"\n"<<setw(28)<<"***"<<setw(57)<<"***";
		continuar();
		otrosBancos();
	}
	
	int opcionBancos = atoi(valor);
	
	switch(opcionBancos){
		case 1:
			bancos();
			
		case 2:
			continuar();
			clearTransferenciasDos();
			cout<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(48)<<"+++++++++++++++++++++++++++++++++++++"<<setw(11)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(12)<<"+"<<setw(36)<<"+"<<setw(11)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(12)<<"+"<<setw(34)<<"Usted no tiene cuentas inscritas."<<setw(2)<<"+"<<setw(11)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(12)<<"+"<<setw(36)<<"+"<<setw(11)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(48)<<"+++++++++++++++++++++++++++++++++++++"<<setw(11)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
				<<"\n"<<setw(28)<<"***"<<setw(57)<<"***";
			continuar();
			otrosBancos();
			
		default:
			clearTransferencias();
			cout<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(55)<<"----------------------------------------------------"<<setw(4)<<"*";
			cerr<<"\n"<<setw(26)<<"*"<<setw(46)<<"ERROR :O |La opcion no es correcta,"<<setw(13)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(40)<<"|intentelo de nuevo."<<setw(19)<<"*";
			cout<<"\n"<<setw(26)<<"*"<<setw(55)<<"----------------------------------------------------"<<setw(4)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
				<<"\n"<<setw(28)<<"***"<<setw(57)<<"***";
			continuar();
			otrosBancos();
	}
}
//Final Funcion otrosBancos()




//Inicio Funcion bancos()
void bancos(){
	
	clearTransferencias();
	
	cout<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
		<<"\n"<<setw(26)<<"*"<<setw(47)<<">>> INGRESE EL NUMERO DEL BANCO <<<"<<setw(12)<<"*"
		<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
		<<"\n"<<setw(26)<<"*"<<setw(17)<<"1. BBVA"<<setw(42)<<"*"
		<<"\n"<<setw(26)<<"*"<<setw(20)<<"2. POPULAR"<<setw(39)<<"*"
		<<"\n"<<setw(26)<<"*"<<setw(34)<<"3. ITAU antes Corpobanca"<<setw(25)<<"*"
		<<"\n"<<setw(26)<<"*"<<setw(24)<<"4. BANCOLOMBIA"<<setw(35)<<"*"
		<<"\n"<<setw(26)<<"*"<<setw(21)<<"5. CITIBANK"<<setw(38)<<"*"
		<<"\n"<<setw(26)<<"*"<<setw(26)<<"6. GNB SUDAMERIS"<<setw(33)<<"*"
		<<"\n"<<setw(26)<<"*"<<setw(19)<<"7. BOGOTA"<<setw(40)<<"*"
		<<"\n"<<setw(26)<<"*"<<setw(17)<<"8. ITAU"<<setw(42)<<"*"
		<<"\n"<<setw(26)<<"*"<<setw(28)<<"9. SCOTIABANK COLP"<<setw(31)<<"*"
		<<"\n"<<setw(26)<<"*"<<setw(22)<<"10. OCCIDENTE"<<setw(37)<<"*"
		<<"\n"<<setw(26)<<"*"<<setw(28)<<"11. BANCO BANCOLDEX"<<setw(31)<<"*"
		<<"\n"<<setw(26)<<"*"<<setw(24)<<"12. CAJA SOCIAL"<<setw(35)<<"*"
		<<"\n"<<setw(26)<<"*"<<setw(26)<<"13. BANCO AGRARIO"<<setw(33)<<"*"
		<<"\n"<<setw(26)<<"*"<<setw(24)<<"14. BNP PARIBAS"<<setw(35)<<"*"
		<<"\n"<<setw(26)<<"*"<<setw(30)<<"15. BANCO MUNDO MUJER"<<setw(29)<<"*"
		<<"\n"<<setw(26)<<"*"<<setw(22)<<"16. AV VILLAS"<<setw(37)<<"*"
		<<"\n"<<setw(26)<<"*"<<setw(20)<<"17. BANCO W"<<setw(39)<<"*"
		<<"\n"<<setw(26)<<"*"<<setw(35)<<"18. BANCO PROCREDIT COLOMB"<<setw(24)<<"*"
		<<"\n"<<setw(26)<<"*"<<setw(21)<<"19. BANCAMIA"<<setw(38)<<"*"
		<<"\n"<<setw(26)<<"*"<<setw(28)<<"20. BANCO PICHINCHA"<<setw(31)<<"*"
		<<"\n"<<setw(26)<<"*"<<setw(23)<<"21. BANCOOMEVA"<<setw(36)<<"*"
		<<"\n"<<setw(26)<<"*"<<setw(28)<<"22. BANCO FALABELLA"<<setw(31)<<"*"
		<<"\n"<<setw(26)<<"*"<<setw(28)<<"23. BANCO FINANDINA"<<setw(31)<<"*"
		<<"\n"<<setw(26)<<"*"<<setw(37)<<"24. BANCO SANTANDER COLOMBIA"<<setw(22)<<"*"
		<<"\n"<<setw(26)<<"*"<<setw(30)<<"25. BANCO COOPCENTRAL"<<setw(29)<<"*"
		<<"\n"<<setw(26)<<"*"<<setw(26)<<"26. BANCO MIBANCO"<<setw(33)<<"*"
		<<"\n"<<setw(26)<<"*"<<setw(29)<<"27. BANCO SERFINANZA"<<setw(30)<<"*"
		<<"\n"<<setw(26)<<"*"<<setw(35)<<"28. COMPANIA FIN JURISCOOP"<<setw(24)<<"*"
		<<"\n"<<setw(26)<<"*"<<setw(27)<<"29. BANCO RAPPIPAY"<<setw(32)<<"*"
		<<"\n"<<setw(26)<<"*"<<setw(48)<<"30. COOPERATIVA FINANCIERA DE ANTIOQUIA"<<setw(11)<<"*"
		<<"\n"<<setw(26)<<"*"<<setw(43)<<"31. COOPERATIVA FINANCIERA COTRAFA"<<setw(16)<<"*"
		<<"\n"<<setw(26)<<"*"<<setw(21)<<"32. COOFINEP"<<setw(38)<<"*"
		<<"\n"<<setw(26)<<"*"<<setw(20)<<"33. CONFIAR"<<setw(39)<<"*"
		<<"\n"<<setw(26)<<"*"<<setw(29)<<"34. GIROS Y FINANZAS"<<setw(30)<<"*"
		<<"\n"<<setw(26)<<"*"<<setw(28)<<"35. COLTEFINANCIERA"<<setw(31)<<"*"
		<<"\n"<<setw(26)<<"*"<<setw(18)<<"36. NEQUI"<<setw(41)<<"*"
		<<"\n"<<setw(26)<<"*"<<setw(34)<<"37. BANCO CREDIFINANCIERA"<<setw(25)<<"*"
		<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
		<<"\n"<<setw(26)<<"*"<<setw(22)<<"-Elija una opcion:"<<setw(37)<<"*"
		<<"\n"<<setw(28)<<"***"<<setw(57)<<"***"
		<<"\n"<<setw(35)<<"-> ";
	escape();
			
	if(e == 0){
		clearTransferencias();
		cout<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
			<<"\n"<<setw(26)<<"*"<<setw(55)<<"----------------------------------------------------"<<setw(4)<<"*";
		cerr<<"\n"<<setw(26)<<"*"<<setw(52)<<"ERROR :O El campo esta vacio, ingrese un valor."<<setw(7)<<"*";
		cout<<"\n"<<setw(26)<<"*"<<setw(55)<<"----------------------------------------------------"<<setw(4)<<"*"
			<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
			<<"\n"<<setw(28)<<"***"<<setw(57)<<"***";
		continuar();
		bancos();
	}
	
	int opcionesBancos = atoi(valor);
	
	switch(opcionesBancos){
		case 1: 
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
		case 8:
		case 9:
		case 10:
		case 11:
		case 12:
		case 13:
		case 14:
		case 15:
		case 16:
		case 17:
		case 18:
		case 19:
		case 20:
		case 21:
		case 22:
		case 23:
		case 24:
		case 25:
		case 26:
		case 27:
		case 28:
		case 29:
		case 30:
		case 31:
		case 32:
		case 33:
		case 34:
		case 35:
		case 36:
		case 37: validarNumeroCuenta();
		default:
			clearTransferencias();
			cout<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(55)<<"----------------------------------------------------"<<setw(4)<<"*";
			cerr<<"\n"<<setw(26)<<"*"<<setw(46)<<"ERROR :O |La opcion no es correcta,"<<setw(13)<<"*"
		    	<<"\n"<<setw(26)<<"*"<<setw(40)<<"|intentelo de nuevo."<<setw(19)<<"*";
			cout<<"\n"<<setw(26)<<"*"<<setw(55)<<"----------------------------------------------------"<<setw(4)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
				<<"\n"<<setw(28)<<"***"<<setw(57)<<"***";
			continuar();
			bancos();
	}
}
//Final Funcion bancos()

