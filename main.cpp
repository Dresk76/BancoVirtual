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

int key, e, j, k = 1, l = 1, m = 1, dineroIngreso, dineroRetiro, dineroTransferencia, dineroTotal, i, valorIngreso, valorRetiro, valorTransferencia;
bool bloqueoIngreso = false, bloqueoRetiro = false, bloqueoTransaccion = false;
char documento[longiCedula], caracter, password[longitud], valor[longiEscape], numeroCuenta[longiNumeroCuenta];



void clear();
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
void validarNumeroCuenta();
void validarCantidadTransferir();
void validarClaveTransferenciaDinero();
void cuentaAhorros();
void cuentaCorriente();
void otrosBancos();



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
			<<"\n"<<setw(28)<<"***"<<setw(57)<<"***"
			<<"\n"<<setw(85)<<"------------------------------------------------------------"
			<<"\n"<<setw(78)<<">>>> Presione la tecla enter para continuar <<<<"
			<<"\n"<<setw(85)<<"------------------------------------------------------------"
			<<"\n"<<setw(55)<<":V";
		limiteCero();
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
	cout<<"\n\n"<<setw(85)<<"------------------------------------------------------------"
		<<"\n"<<setw(78)<<">>>> Presione la tecla enter para continuar <<<<"
		<<"\n"<<setw(85)<<"------------------------------------------------------------"
		<<"\n"<<setw(55)<<":V";
	limiteCero();
	
	
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




//Inicio funcion clear()
void clear(){
	system("cls");
	cout<<"\n"<<setw(85)<<"************************************************************"
		<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
		<<"\n"<<setw(26)<<"*"<<setw(43)<<"BIENVENIDO A TU BANCO VIRTUAL"<<setw(16)<<"*"
		<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
		<<"\n"<<setw(85)<<"************************************************************";
}
//Final funcion clear()




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
			<<"\n"<<setw(28)<<"***"<<setw(57)<<"***"
			<<"\n"<<setw(85)<<"------------------------------------------------------------"
			<<"\n"<<setw(78)<<">>>> Presione la tecla enter para continuar <<<<"
			<<"\n"<<setw(85)<<"------------------------------------------------------------"
			<<"\n"<<setw(55)<<":V";
		limiteCero();
		cambioDocumento();
	}
	
	if(strlen(documento) < 8){
		clear();
		cout<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
			<<"\n"<<setw(26)<<"*"<<setw(55)<<"----------------------------------------------------"<<setw(4)<<"*";
		cerr<<"\n"<<setw(26)<<"*"<<setw(53)<<"ERROR :O | El documento ingresado no es valido."<<setw(6)<<"*";
		cout<<"\n"<<setw(26)<<"*"<<setw(55)<<"----------------------------------------------------"<<setw(4)<<"*"
			<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
			<<"\n"<<setw(28)<<"***"<<setw(57)<<"***"
			<<"\n"<<setw(85)<<"------------------------------------------------------------"
			<<"\n"<<setw(78)<<">>>> Presione la tecla enter para continuar <<<<"
			<<"\n"<<setw(85)<<"------------------------------------------------------------"
			<<"\n"<<setw(55)<<":V";
		limiteCero();
		cambioDocumento();
	}
}
//Final Funcion cambioDocumento()




//Inicio funcion preguntaRegistrarCorreo()
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
			<<"\n"<<setw(28)<<"***"<<setw(57)<<"***"
			<<"\n"<<setw(85)<<"------------------------------------------------------------"
			<<"\n"<<setw(78)<<">>>> Presione la tecla enter para continuar <<<<"
			<<"\n"<<setw(85)<<"------------------------------------------------------------"
			<<"\n"<<setw(55)<<":V";
		limiteCero();
		preguntaRegistrarCorreo();
		
	} else if(preguntaCorreo == "s" || preguntaCorreo == "S" || preguntaCorreo == "si" || preguntaCorreo == "SI" || preguntaCorreo == "sI" || preguntaCorreo == "Si"){
		cout<<"\n"<<setw(85)<<"------------------------------------------------------------"
			<<"\n"<<setw(78)<<">>>> Presione la tecla enter para continuar <<<<"
			<<"\n"<<setw(85)<<"------------------------------------------------------------"
			<<"\n"<<setw(55)<<":V";
		limiteCero();
		cambioCorreo();
		
	} else if(preguntaCorreo == "n" || preguntaCorreo == "N" || preguntaCorreo == "no" || preguntaCorreo =="NO" || preguntaCorreo == "nO" || preguntaCorreo == "No"){
		cout<<"\n"<<setw(85)<<"------------------------------------------------------------"
			<<"\n"<<setw(78)<<">>>> Presione la tecla enter para continuar <<<<"
			<<"\n"<<setw(85)<<"------------------------------------------------------------"
			<<"\n"<<setw(55)<<":V";
		limiteCero();
		
	} else{
		clear();
		cout<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
			<<"\n"<<setw(26)<<"*"<<setw(55)<<"----------------------------------------------------"<<setw(4)<<"*";
		cerr<<"\n"<<setw(26)<<"*"<<setw(47)<<"ERROR :O | Ingrese una opcion valida."<<setw(12)<<"*";
		cout<<"\n"<<setw(26)<<"*"<<setw(55)<<"----------------------------------------------------"<<setw(4)<<"*"
			<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
			<<"\n"<<setw(28)<<"***"<<setw(57)<<"***"
			<<"\n"<<setw(85)<<"------------------------------------------------------------"
			<<"\n"<<setw(78)<<">>>> Presione la tecla enter para continuar <<<<"
			<<"\n"<<setw(85)<<"------------------------------------------------------------"
			<<"\n"<<setw(55)<<":V";
		limiteCero();
		preguntaRegistrarCorreo();
	}
}
//Final funcion preguntaRegistrarCorreo()




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
				
			cout<<"\n"<<setw(85)<<"------------------------------------------------------------"
				<<"\n"<<setw(78)<<">>>> Presione la tecla enter para continuar <<<<"
				<<"\n"<<setw(85)<<"------------------------------------------------------------"
				<<"\n"<<setw(55)<<":V";
			limiteCero();
						
		} else if(b == false){
			clear();
			cout<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(55)<<"----------------------------------------------------"<<setw(4)<<"*";
			cerr<<"\n"<<setw(26)<<"*"<<setw(42)<<"|----> :O ERROR :O <----|"<<setw(17)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(54)<<"La direccion de correo electronico no es valida,"<<setw(5)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(27)<<"debe ingresar el '@'."<<setw(32)<<"*";
			cout<<"\n"<<setw(26)<<"*"<<setw(55)<<"----------------------------------------------------"<<setw(4)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
				<<"\n"<<setw(28)<<"***"<<setw(57)<<"***"
				<<"\n"<<setw(85)<<"------------------------------------------------------------"
				<<"\n"<<setw(78)<<">>>> Presione la tecla enter para continuar <<<<"
				<<"\n"<<setw(85)<<"------------------------------------------------------------"
				<<"\n"<<setw(55)<<":V";
			limiteCero();
			cambioCorreo();
		}
	} else{
		clear();
		cout<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
			<<"\n"<<setw(26)<<"*"<<setw(55)<<"----------------------------------------------------"<<setw(4)<<"*";
		cerr<<"\n"<<setw(26)<<"*"<<setw(55)<<"ERROR :O | El campo esta vacio, ingrese una opcion."<<setw(4)<<"*";
		cout<<"\n"<<setw(26)<<"*"<<setw(55)<<"----------------------------------------------------"<<setw(4)<<"*"
			<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
			<<"\n"<<setw(28)<<"***"<<setw(57)<<"***"
			<<"\n"<<setw(85)<<"------------------------------------------------------------"
			<<"\n"<<setw(78)<<">>>> Presione la tecla enter para continuar <<<<"
			<<"\n"<<setw(85)<<"------------------------------------------------------------"
			<<"\n"<<setw(55)<<":V";
		limiteCero();
		cambioCorreo();
	}
}
//Final Funcion cambioCorreo()




//Inicio funcion claveAutomatica(int clave)
void claveAutomatica(int key) {
	cout<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
		<<"\n"<<setw(26)<<"*"<<setw(43)<<"Clave: "<<key<<setw(12)<<"*";
}
//Final funcion claveAutomatica(int clave)




//Inicio funcion preguntaCambioClave()
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
			<<"\n"<<setw(28)<<"***"<<setw(57)<<"***"
			<<"\n"<<setw(85)<<"------------------------------------------------------------"
			<<"\n"<<setw(78)<<">>>> Presione la tecla enter para continuar <<<<"
			<<"\n"<<setw(85)<<"------------------------------------------------------------"
			<<"\n"<<setw(55)<<":V";
		limiteCero();
		clear();
		cout<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
			<<"\n"<<setw(26)<<"*"<<setw(22)<<"-Esta es su clave "<<key<< ", desea modificarla?"<<setw(13)<<"*";
		preguntaCambioClave();
			
	} else if(modificarClave == "s" || modificarClave == "S" || modificarClave == "si" || modificarClave == "SI" || modificarClave == "sI" || modificarClave == "Si"){
		cout<<"\n"<<setw(85)<<"------------------------------------------------------------"
			<<"\n"<<setw(78)<<">>>> Presione la tecla enter para continuar <<<<"
			<<"\n"<<setw(85)<<"------------------------------------------------------------"
			<<"\n"<<setw(55)<<":V";
		limiteCero();
		cambioClave();
		
	} else if (modificarClave == "n" || modificarClave == "N" || modificarClave == "no" || modificarClave == "NO" || modificarClave == "nO" || modificarClave == "No"){
		cout<<"\n"<<setw(85)<<"------------------------------------------------------------"
			<<"\n"<<setw(78)<<">>>> Presione la tecla enter para continuar <<<<"
			<<"\n"<<setw(85)<<"------------------------------------------------------------"
			<<"\n"<<setw(55)<<":V";
		limiteCero();
		menuOpciones();

	} else{
		clear();
		cout<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
			<<"\n"<<setw(26)<<"*"<<setw(56)<<"----------------------------------------------------"<<setw(3)<<"*";
		cerr<<"\n"<<setw(26)<<"*"<<setw(48)<<"ERROR :O | Ingrese una opcion valida."<<setw(11)<<"*";
		cout<<"\n"<<setw(26)<<"*"<<setw(56)<<"----------------------------------------------------"<<setw(3)<<"*"
			<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
			<<"\n"<<setw(28)<<"***"<<setw(57)<<"***"
			<<"\n"<<setw(85)<<"------------------------------------------------------------"
			<<"\n"<<setw(78)<<">>>> Presione la tecla enter para continuar <<<<"
			<<"\n"<<setw(85)<<"------------------------------------------------------------"
			<<"\n"<<setw(55)<<":V";
		limiteCero();
		clear();
		cout<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
			<<"\n"<<setw(26)<<"*"<<setw(22)<<"-Esta es su clave "<<key<< ", desea modificarla?"<<setw(13)<<"*";
		preguntaCambioClave();	
	}
}
//Final funcion preguntaCambioClave()




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
				cout<<"\n"<<setw(85)<<"------------------------------------------------------------"
					<<"\n"<<setw(78)<<">>>> Presione la tecla enter para continuar <<<<"
					<<"\n"<<setw(85)<<"------------------------------------------------------------"
					<<"\n"<<setw(55)<<":V";
				limiteCero();
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
				cout<<"\n"<<setw(85)<<"------------------------------------------------------------"
					<<"\n"<<setw(78)<<">>>> Presione la tecla enter para continuar <<<<"
					<<"\n"<<setw(85)<<"------------------------------------------------------------"
					<<"\n"<<setw(55)<<":V";
				limiteCero();
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
				cout<<"\n"<<setw(85)<<"------------------------------------------------------------"
					<<"\n"<<setw(78)<<">>>> Presione la tecla enter para continuar <<<<"
					<<"\n"<<setw(85)<<"------------------------------------------------------------"
					<<"\n"<<setw(55)<<":V";
				limiteCero();
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
			<<"\n"<<setw(28)<<"***"<<setw(57)<<"***"
			<<"\n"<<setw(85)<<"------------------------------------------------------------"
			<<"\n"<<setw(78)<<">>>> Presione la tecla enter para continuar <<<<"
			<<"\n"<<setw(85)<<"------------------------------------------------------------"
			<<"\n"<<setw(55)<<":V";
		limiteCero();
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
				<<"\n"<<setw(28)<<"***"<<setw(57)<<"***"
				<<"\n"<<setw(85)<<"------------------------------------------------------------"
				<<"\n"<<setw(78)<<">>>> Presione la tecla enter para continuar <<<<"
				<<"\n"<<setw(85)<<"------------------------------------------------------------"
				<<"\n"<<setw(55)<<":V";
			limiteCero();
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
				<<"\n"<<setw(28)<<"***"<<setw(57)<<"***"
				<<"\n"<<setw(85)<<"------------------------------------------------------------"
				<<"\n"<<setw(78)<<">>>> Presione la tecla enter para continuar <<<<"
				<<"\n"<<setw(85)<<"------------------------------------------------------------"
				<<"\n"<<setw(55)<<":V";
			limiteCero();
			menuOpciones();
		}
			
	} else{
		cout<<"\n\n"<<setw(85)<<"------------------------------------------------------------"
			<<"\n"<<setw(78)<<">>>> Presione la tecla enter para continuar <<<<"
			<<"\n"<<setw(85)<<"------------------------------------------------------------"
			<<"\n"<<setw(55)<<":V";
		limiteCero();
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
	clearCambioClaveDos();
	
	if(verClave.empty()){
		cout<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
			<<"\n"<<setw(26)<<"*"<<setw(55)<<"----------------------------------------------------"<<setw(4)<<"*";
		cerr<<"\n"<<setw(26)<<"*"<<setw(55)<<"ERROR :O | El campo esta vacio, ingrese una opcion."<<setw(4)<<"*";
		cout<<"\n"<<setw(26)<<"*"<<setw(55)<<"----------------------------------------------------"<<setw(4)<<"*"
			<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
			<<"\n"<<setw(28)<<"***"<<setw(57)<<"***"
			<<"\n"<<setw(85)<<"------------------------------------------------------------"
			<<"\n"<<setw(78)<<">>>> Presione la tecla enter para continuar <<<<"
			<<"\n"<<setw(85)<<"------------------------------------------------------------"
			<<"\n"<<setw(55)<<":V";
		limiteCero();
		seeKey();
		
	} else if(verClave == "s" || verClave == "S" || verClave == "si" || verClave == "SI" || verClave == "sI" || verClave == "Si"){
		key = atoi(password);
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
		cout<<"\n"<<setw(85)<<"------------------------------------------------------------"
			<<"\n"<<setw(78)<<">>>> Presione la tecla enter para continuar <<<<"
			<<"\n"<<setw(85)<<"------------------------------------------------------------"
			<<"\n"<<setw(55)<<":V";
		limiteCero();
		menuOpciones();
		
	} else if (verClave == "n" || verClave == "N" || verClave == "no" || verClave == "NO" || verClave == "nO" || verClave == "No"){
		key = atoi(password);
		cout<<"\n"<<setw(85)<<"------------------------------------------------------------"
			<<"\n"<<setw(78)<<">>>> Presione la tecla enter para continuar <<<<"
			<<"\n"<<setw(85)<<"------------------------------------------------------------"
			<<"\n"<<setw(55)<<":V";
		limiteCero();
		menuOpciones();
			
	} else{
		cout<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
			<<"\n"<<setw(26)<<"*"<<setw(55)<<"----------------------------------------------------"<<setw(4)<<"*";
		cerr<<"\n"<<setw(26)<<"*"<<setw(47)<<"ERROR :O | Ingrese una opcion valida."<<setw(12)<<"*";
		cout<<"\n"<<setw(26)<<"*"<<setw(55)<<"----------------------------------------------------"<<setw(4)<<"*"
			<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
			<<"\n"<<setw(28)<<"***"<<setw(57)<<"***"
			<<"\n"<<setw(85)<<"------------------------------------------------------------"
			<<"\n"<<setw(78)<<">>>> Presione la tecla enter para continuar <<<<"
			<<"\n"<<setw(85)<<"------------------------------------------------------------"
			<<"\n"<<setw(55)<<":V";
		limiteCero();
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
			<<"\n"<<setw(28)<<"***"<<setw(57)<<"***"
			<<"\n"<<setw(85)<<"------------------------------------------------------------"
			<<"\n"<<setw(78)<<">>>> Presione la tecla enter para continuar <<<<"
			<<"\n"<<setw(85)<<"------------------------------------------------------------"
			<<"\n"<<setw(55)<<":V";
		limiteCero();
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
			<<"\n"<<setw(28)<<"***"<<setw(57)<<"***"
			<<"\n"<<setw(85)<<"------------------------------------------------------------"
			<<"\n"<<setw(78)<<">>>> Presione la tecla enter para continuar <<<<"
			<<"\n"<<setw(85)<<"------------------------------------------------------------"
			<<"\n"<<setw(55)<<":V";
		limiteCero();
		ingresarDinero();
	
	} else if (dineroIngreso > 0 && dineroIngreso < 20000){
		clearIngresar();
		cout<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
			<<"\n"<<setw(26)<<"*"<<setw(55)<<"----------------------------------------------------"<<setw(4)<<"*";
		cerr<<"\n"<<setw(26)<<"*"<<setw(40)<<"ERROR :O |Lo minimo permitido"<<setw(19)<<"*"
			<<"\n"<<setw(26)<<"*"<<setw(45)<<"|para ingresar es $20.000"<<setw(14)<<"*";
		cout<<"\n"<<setw(26)<<"*"<<setw(55)<<"----------------------------------------------------"<<setw(4)<<"*"
			<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
			<<"\n"<<setw(28)<<"***"<<setw(57)<<"***"
			<<"\n"<<setw(85)<<"------------------------------------------------------------"
			<<"\n"<<setw(78)<<">>>> Presione la tecla enter para continuar <<<<"
			<<"\n"<<setw(85)<<"------------------------------------------------------------"
			<<"\n"<<setw(55)<<":V";
		limiteCero();
		ingresarDinero();
			
	} else if(dineroIngreso > 19999 && dineroIngreso < 1000001){
		cout<<"\n\n"<<setw(85)<<"------------------------------------------------------------"
			<<"\n"<<setw(78)<<">>>> Presione la tecla enter para continuar <<<<"
			<<"\n"<<setw(85)<<"------------------------------------------------------------"
			<<"\n"<<setw(55)<<":V";
		limiteCero();
		validarClaveIngresoDinero();
		
	} else{
		clearIngresar();
		cout<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
			<<"\n"<<setw(26)<<"*"<<setw(55)<<"----------------------------------------------------"<<setw(4)<<"*";
		cerr<<"\n"<<setw(26)<<"*"<<setw(50)<<"ERROR :O | El valor ingresado no es valido."<<setw(9)<<"*";
		cout<<"\n"<<setw(26)<<"*"<<setw(55)<<"----------------------------------------------------"<<setw(4)<<"*"
			<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
			<<"\n"<<setw(28)<<"***"<<setw(57)<<"***"
			<<"\n"<<setw(85)<<"------------------------------------------------------------"
			<<"\n"<<setw(78)<<">>>> Presione la tecla enter para continuar <<<<"
			<<"\n"<<setw(85)<<"------------------------------------------------------------"
			<<"\n"<<setw(55)<<":V";
		limiteCero();
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
			<<"\n"<<setw(28)<<"***"<<setw(57)<<"***"
			<<"\n"<<setw(85)<<"------------------------------------------------------------"
			<<"\n"<<setw(78)<<">>>> Presione la tecla enter para continuar <<<<"
			<<"\n"<<setw(85)<<"------------------------------------------------------------"
			<<"\n"<<setw(55)<<":V";
		limiteCero();
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
				<<"\n"<<setw(28)<<"***"<<setw(57)<<"***"
				<<"\n"<<setw(85)<<"------------------------------------------------------------"
				<<"\n"<<setw(78)<<">>>> Presione la tecla enter para continuar <<<<"
				<<"\n"<<setw(85)<<"------------------------------------------------------------"
				<<"\n"<<setw(55)<<":V";
			limiteCero();
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
				<<"\n"<<setw(28)<<"***"<<setw(57)<<"***"
				<<"\n\n"<<setw(85)<<"------------------------------------------------------------"
				<<"\n"<<setw(78)<<">>>> Presione la tecla enter para continuar <<<<"
				<<"\n"<<setw(85)<<"------------------------------------------------------------"
				<<"\n"<<setw(55)<<":V";
			limiteCero();
			menuOpciones();
		}
	} else {
		
		valorIngreso = atoi(password);
		
		if(valorIngreso == key){
			clearIngresarDos();
			dineroTotal += dineroIngreso;
			cout<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(45)<<">>> INGRESO DE DINERO EXITOSO <<<"<<setw(14)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(47)<<"++++++++++++++++++++++++++++++++++++"<<setw(12)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(12)<<"+"<<setw(35)<<"+"<<setw(12)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(12)<<"+"<<setw(27)<<">>Ingreso realizado por: $"<<dineroIngreso<<setw(2)<<"+"<<setw(12)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(12)<<"+"<<setw(21)<<">>Saldo en cuenta: $"<<dineroTotal<<setw(8)<<"+"<<setw(12)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(12)<<"+"<<setw(35)<<"+"<<setw(12)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(47)<<"++++++++++++++++++++++++++++++++++++"<<setw(12)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
				<<"\n"<<setw(28)<<"***"<<setw(57)<<"***"
				<<"\n"<<setw(85)<<"------------------------------------------------------------"
				<<"\n"<<setw(78)<<">>>> Presione la tecla enter para continuar <<<<"
				<<"\n"<<setw(85)<<"------------------------------------------------------------"
				<<"\n"<<setw(55)<<":V";
			limiteCero();
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
				<<"\n"<<setw(28)<<"***"<<setw(57)<<"***"
				<<"\n"<<setw(85)<<"------------------------------------------------------------"
				<<"\n"<<setw(78)<<">>>> Presione la tecla enter para continuar <<<<"
				<<"\n"<<setw(85)<<"------------------------------------------------------------"
				<<"\n"<<setw(55)<<":V";
			limiteCero();
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
				<<"\n"<<setw(28)<<"***"<<setw(57)<<"***"
				<<"\n"<<setw(85)<<"------------------------------------------------------------"
				<<"\n"<<setw(78)<<">>>> Presione la tecla enter para continuar <<<<"
				<<"\n"<<setw(85)<<"------------------------------------------------------------"
				<<"\n"<<setw(55)<<":V";
			limiteCero();
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
			<<"\n"<<setw(28)<<"***"<<setw(57)<<"***"
			<<"\n"<<setw(85)<<"------------------------------------------------------------"
			<<"\n"<<setw(78)<<">>>> Presione la tecla enter para continuar <<<<"
			<<"\n"<<setw(85)<<"------------------------------------------------------------"
			<<"\n"<<setw(55)<<":V";
		limiteCero();
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
			<<"\n"<<setw(28)<<"***"<<setw(57)<<"***"
			<<"\n"<<setw(85)<<"------------------------------------------------------------"
			<<"\n"<<setw(78)<<">>>> Presione la tecla enter para continuar <<<<"
			<<"\n"<<setw(85)<<"------------------------------------------------------------"
			<<"\n"<<setw(55)<<":V";
		limiteCero();
		retirarDinero();
	
	} else if (dineroRetiro > 500000){
		clearRetirar();		
		cout<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
			<<"\n"<<setw(26)<<"*"<<setw(55)<<"----------------------------------------------------"<<setw(4)<<"*";
		cerr<<"\n"<<setw(26)<<"*"<<setw(45)<<"ERROR :O |Lo maximo permitido por"<<setw(14)<<"*"
			<<"\n"<<setw(26)<<"*"<<setw(46)<<"|cada retiro son $500.000"<<setw(13)<<"*";
		cout<<"\n"<<setw(26)<<"*"<<setw(55)<<"----------------------------------------------------"<<setw(4)<<"*"
			<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
			<<"\n"<<setw(28)<<"***"<<setw(57)<<"***"
			<<"\n"<<setw(85)<<"------------------------------------------------------------"
			<<"\n"<<setw(78)<<">>>> Presione la tecla enter para continuar <<<<"
			<<"\n"<<setw(85)<<"------------------------------------------------------------"
			<<"\n"<<setw(55)<<":V";
		limiteCero();
		retirarDinero();
		
	}else if(dineroRetiro > 0 && dineroRetiro < 20000){
		clearRetirar();
		cout<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
			<<"\n"<<setw(26)<<"*"<<setw(55)<<"----------------------------------------------------"<<setw(4)<<"*";
		cerr<<"\n"<<setw(26)<<"*"<<setw(41)<<"ERROR :O |Lo minimo permitido"<<setw(18)<<"*"
			<<"\n"<<setw(26)<<"*"<<setw(45)<<"|para retirar es $20.000"<<setw(14)<<"*";
		cout<<"\n"<<setw(26)<<"*"<<setw(55)<<"----------------------------------------------------"<<setw(4)<<"*"
			<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
			<<"\n"<<setw(28)<<"***"<<setw(57)<<"***"
			<<"\n"<<setw(85)<<"------------------------------------------------------------"
			<<"\n"<<setw(78)<<">>>> Presione la tecla enter para continuar <<<<"
			<<"\n"<<setw(85)<<"------------------------------------------------------------"
			<<"\n"<<setw(55)<<":V";
		limiteCero();
		retirarDinero();
	
	} else if (dineroRetiro > 19999 && dineroRetiro <= dineroTotal){	
		validarClaveRetiroDinero();	
			
	} else {
		clearRetirar();
		cout<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
			<<"\n"<<setw(26)<<"*"<<setw(56)<<"----------------------------------------------------"<<setw(3)<<"*";
		cerr<<"\n"<<setw(26)<<"*"<<setw(51)<<"ERROR :O | El valor ingresado no es valido."<<setw(8)<<"*";
		cout<<"\n"<<setw(26)<<"*"<<setw(56)<<"----------------------------------------------------"<<setw(3)<<"*"
			<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
			<<"\n"<<setw(28)<<"***"<<setw(57)<<"***"
			<<"\n"<<setw(85)<<"------------------------------------------------------------"
			<<"\n"<<setw(78)<<">>>> Presione la tecla enter para continuar <<<<"
			<<"\n"<<setw(85)<<"------------------------------------------------------------"
			<<"\n"<<setw(55)<<":V";
		limiteCero();
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
			<<"\n"<<setw(28)<<"***"<<setw(57)<<"***"
			<<"\n"<<setw(85)<<"------------------------------------------------------------"
			<<"\n"<<setw(78)<<">>>> Presione la tecla enter para continuar <<<<"
			<<"\n"<<setw(85)<<"------------------------------------------------------------"
			<<"\n"<<setw(55)<<":V";
		limiteCero();
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
				<<"\n"<<setw(28)<<"***"<<setw(57)<<"***"
				<<"\n"<<setw(85)<<"------------------------------------------------------------"
				<<"\n"<<setw(78)<<">>>> Presione la tecla enter para continuar <<<<"
				<<"\n"<<setw(85)<<"------------------------------------------------------------"
				<<"\n"<<setw(55)<<":V";
			limiteCero();
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
				<<"\n"<<setw(28)<<"***"<<setw(57)<<"***"
				<<"\n"<<setw(85)<<"------------------------------------------------------------"
				<<"\n"<<setw(78)<<">>>> Presione la tecla enter para continuar <<<<"
				<<"\n"<<setw(85)<<"------------------------------------------------------------"
				<<"\n"<<setw(55)<<":V";
			limiteCero();
			menuOpciones();
		}
		
	} else {
		
		valorRetiro = atoi(password);
		
		if(valorRetiro == key){
			clearRetirarDos();
			dineroTotal -= dineroRetiro;
			cout<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(45)<<">>> RETIRO DE DINERO EXITOSO <<<"<<setw(14)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(46)<<"+++++++++++++++++++++++++++++++++++"<<setw(13)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(12)<<"+"<<setw(34)<<"+"<<setw(13)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(12)<<"+"<<setw(26)<<">>Retiro realizado por: $"<<dineroRetiro<<setw(2)<<"+"<<setw(13)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(12)<<"+"<<setw(21)<<">>Saldo en cuenta: $"<<dineroTotal<<setw(7)<<"+"<<setw(13)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(12)<<"+"<<setw(34)<<"+"<<setw(13)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(46)<<"+++++++++++++++++++++++++++++++++++"<<setw(13)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
				<<"\n"<<setw(28)<<"***"<<setw(57)<<"***"
				<<"\n"<<setw(85)<<"------------------------------------------------------------"
				<<"\n"<<setw(78)<<">>>> Presione la tecla enter para continuar <<<<"
				<<"\n"<<setw(85)<<"------------------------------------------------------------"
				<<"\n"<<setw(55)<<":V";
			limiteCero();
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
				<<"\n"<<setw(28)<<"***"<<setw(57)<<"***"
				<<"\n"<<setw(85)<<"------------------------------------------------------------"
				<<"\n"<<setw(78)<<">>>> Presione la tecla enter para continuar <<<<"
				<<"\n"<<setw(85)<<"------------------------------------------------------------"
				<<"\n"<<setw(55)<<":V";
			limiteCero();
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
				<<"\n"<<setw(28)<<"***"<<setw(57)<<"***"
				<<"\n"<<setw(85)<<"------------------------------------------------------------"
				<<"\n"<<setw(78)<<">>>> Presione la tecla enter para continuar <<<<"
				<<"\n"<<setw(85)<<"------------------------------------------------------------"
				<<"\n"<<setw(55)<<":V";
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
			<<"\n"<<setw(28)<<"***"<<setw(57)<<"***"
			<<"\n"<<setw(85)<<"------------------------------------------------------------"
			<<"\n"<<setw(78)<<">>>> Presione la tecla enter para continuar <<<<"
			<<"\n"<<setw(85)<<"------------------------------------------------------------"
			<<"\n"<<setw(55)<<":V";
		limiteCero();
		transferencias();
	}
	
	int opcionTransferencia = atoi(valor);
	
	switch(opcionTransferencia){
		case 1:
		cout<<"\n\n"<<setw(85)<<"------------------------------------------------------------"
			<<"\n"<<setw(78)<<">>>> Presione la tecla enter para continuar <<<<"
			<<"\n"<<setw(85)<<"------------------------------------------------------------"
			<<"\n"<<setw(55)<<":V";
		limiteCero();
		cuentaAhorros();
		
		case 2:
		cout<<"\n\n"<<setw(85)<<"------------------------------------------------------------"
			<<"\n"<<setw(78)<<">>>> Presione la tecla enter para continuar <<<<"
			<<"\n"<<setw(85)<<"------------------------------------------------------------"
			<<"\n"<<setw(55)<<":V";
		limiteCero();
		clearTransferencias();
		cuentaCorriente();
		
		case 3:
		cout<<"\n\n"<<setw(85)<<"------------------------------------------------------------"
			<<"\n"<<setw(78)<<">>>> Presione la tecla enter para continuar <<<<"
			<<"\n"<<setw(85)<<"------------------------------------------------------------"
			<<"\n"<<setw(55)<<":V";
		limiteCero();
		clearTransferencias();
		otrosBancos();
		
		default: 
		clearTransferencias();
		cout<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
			<<"\n"<<setw(26)<<"*"<<setw(55)<<"----------------------------------------------------"<<setw(4)<<"*";
		cerr<<"\n"<<setw(26)<<"*"<<setw(46)<<"ERROR :O |La opcion no es correcta,"<<setw(13)<<"*"
			<<"\n"<<setw(26)<<"*"<<setw(40)<<"|intentelo de nuevo."<<setw(19)<<"*";
		cout<<"\n"<<setw(26)<<"*"<<setw(55)<<"----------------------------------------------------"<<setw(4)<<"*"
			<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
			<<"\n"<<setw(28)<<"***"<<setw(57)<<"***"
			<<"\n"<<setw(85)<<"------------------------------------------------------------"
			<<"\n"<<setw(78)<<">>>> Presione la tecla enter para continuar <<<<"
			<<"\n"<<setw(85)<<"------------------------------------------------------------"
			<<"\n"<<setw(55)<<":V";
		limiteCero();
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
		<<"\n"<<setw(26)<<"*"<<setw(33)<<"-Numero de Cuenta de Ahorros:"<<setw(26)<<"*"
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
			<<"\n"<<setw(28)<<"***"<<setw(57)<<"***"
			<<"\n"<<setw(85)<<"------------------------------------------------------------"
			<<"\n"<<setw(78)<<">>>> Presione la tecla enter para continuar <<<<"
			<<"\n"<<setw(85)<<"------------------------------------------------------------"
			<<"\n"<<setw(55)<<":V";
		limiteCero();
		validarNumeroCuenta();
	}
	
	if(strlen(numeroCuenta) < longiNumeroCuenta){
		clearTransferencias();
		cout<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
			<<"\n"<<setw(26)<<"*"<<setw(55)<<"----------------------------------------------------"<<setw(4)<<"*";
		cerr<<"\n"<<setw(26)<<"*"<<setw(50)<<"ERROR :O |El numero ingresado no es valido."<<setw(9)<<"*";
		cout<<"\n"<<setw(26)<<"*"<<setw(55)<<"----------------------------------------------------"<<setw(4)<<"*"
			<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
			<<"\n"<<setw(28)<<"***"<<setw(57)<<"***"
			<<"\n"<<setw(85)<<"------------------------------------------------------------"
			<<"\n"<<setw(78)<<">>>> Presione la tecla enter para continuar <<<<"
			<<"\n"<<setw(85)<<"------------------------------------------------------------"
			<<"\n"<<setw(55)<<":V";
		limiteCero();
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
			<<"\n"<<setw(28)<<"***"<<setw(57)<<"***"
			<<"\n"<<setw(85)<<"------------------------------------------------------------"
			<<"\n"<<setw(78)<<">>>> Presione la tecla enter para continuar <<<<"
			<<"\n"<<setw(85)<<"------------------------------------------------------------"
			<<"\n"<<setw(55)<<":V";
		limiteCero();
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
			<<"\n"<<setw(28)<<"***"<<setw(57)<<"***"
			<<"\n"<<setw(85)<<"------------------------------------------------------------"
			<<"\n"<<setw(78)<<">>>> Presione la tecla enter para continuar <<<<"
			<<"\n"<<setw(85)<<"------------------------------------------------------------"
			<<"\n"<<setw(55)<<":V";
		limiteCero();
		validarCantidadTransferir();
	
	} else if (dineroTransferencia > 0 && dineroTransferencia < 20000){
		clearTransferencias();
		cout<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
			<<"\n"<<setw(26)<<"*"<<setw(55)<<"----------------------------------------------------"<<setw(4)<<"*";
		cerr<<"\n"<<setw(26)<<"*"<<setw(40)<<"ERROR :O |Lo minimo permitido"<<setw(19)<<"*"
			<<"\n"<<setw(26)<<"*"<<setw(47)<<"|para transferir es $20.000"<<setw(12)<<"*";
		cout<<"\n"<<setw(26)<<"*"<<setw(55)<<"----------------------------------------------------"<<setw(4)<<"*"
			<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
			<<"\n"<<setw(28)<<"***"<<setw(57)<<"***"
			<<"\n"<<setw(85)<<"------------------------------------------------------------"
			<<"\n"<<setw(78)<<">>>> Presione la tecla enter para continuar <<<<"
			<<"\n"<<setw(85)<<"------------------------------------------------------------"
			<<"\n"<<setw(55)<<":V";
		limiteCero();
		validarCantidadTransferir();
			
	} else if (dineroTransferencia > 19999 && dineroTransferencia <= dineroTotal){
		validarClaveTransferenciaDinero();
	
	} else{
		clearTransferencias();
		cout<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
			<<"\n"<<setw(26)<<"*"<<setw(55)<<"----------------------------------------------------"<<setw(4)<<"*";
		cerr<<"\n"<<setw(26)<<"*"<<setw(50)<<"ERROR :O |El valor ingresado no es valido."<<setw(9)<<"*";
		cout<<"\n"<<setw(26)<<"*"<<setw(55)<<"----------------------------------------------------"<<setw(4)<<"*"
			<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
			<<"\n"<<setw(28)<<"***"<<setw(57)<<"***"
			<<"\n"<<setw(85)<<"------------------------------------------------------------"
			<<"\n"<<setw(78)<<">>>> Presione la tecla enter para continuar <<<<"
			<<"\n"<<setw(85)<<"------------------------------------------------------------"
			<<"\n"<<setw(55)<<":V";
		limiteCero();
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
			<<"\n"<<setw(28)<<"***"<<setw(57)<<"***"
			<<"\n"<<setw(85)<<"------------------------------------------------------------"
			<<"\n"<<setw(78)<<">>>> Presione la tecla enter para continuar <<<<"
			<<"\n"<<setw(85)<<"------------------------------------------------------------"
			<<"\n"<<setw(55)<<":V";
		limiteCero();
		validarClaveTransferenciaDinero();
	}
	
	if(j < longitud){
	
		while(l < 3){
			clearTransferencias();
			cout<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(55)<<"----------------------------------------------------"<<setw(4)<<"*";
			cerr<<"\n"<<setw(26)<<"*"<<setw(45)<<"ERROR :O | La clave no es valida."<<setw(14)<<"*";
			cout<<"\n"<<setw(26)<<"*"<<setw(55)<<"----------------------------------------------------"<<setw(4)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(35)<<">> Numero de intentos: "<<l<<" de 3 <<"<<setw(15)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
				<<"\n"<<setw(28)<<"***"<<setw(57)<<"***"
				<<"\n"<<setw(85)<<"------------------------------------------------------------"
				<<"\n"<<setw(78)<<">>>> Presione la tecla enter para continuar <<<<"
				<<"\n"<<setw(85)<<"------------------------------------------------------------"
				<<"\n"<<setw(55)<<":V";
			limiteCero();
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
				<<"\n"<<setw(28)<<"***"<<setw(57)<<"***"
				<<"\n"<<setw(85)<<"------------------------------------------------------------"
				<<"\n"<<setw(78)<<">>>> Presione la tecla enter para continuar <<<<"
				<<"\n"<<setw(85)<<"------------------------------------------------------------"
				<<"\n"<<setw(55)<<":V";
			limiteCero();
			menuOpciones();
		}
		
	} else {
		
		valorTransferencia = atoi(password);
		
		if(valorTransferencia == key){
			clearTransferenciasDos();
			dineroTotal -= dineroTransferencia;
			cout<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(48)<<">>> TRANSFERENCIA DE DINERO EXITOSA <<<"<<setw(11)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(50)<<"++++++++++++++++++++++++++++++++++++++++++"<<setw(9)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(9)<<"+"<<setw(41)<<"+"<<setw(9)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(9)<<"+"<<setw(33)<<">>Transferencia realizada por: $"<<dineroTransferencia<<setw(2)<<"+"<<setw(9)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(9)<<"+"<<setw(21)<<">>Saldo en cuenta: $"<<dineroTotal<<setw(14)<<"+"<<setw(9)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(9)<<"+"<<setw(41)<<"+"<<setw(9)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(50)<<"++++++++++++++++++++++++++++++++++++++++++"<<setw(9)<<"*"
				<<"\n"<<setw(26)<<"*"<<setw(59)<<"*"
				<<"\n"<<setw(28)<<"***"<<setw(57)<<"***"
				<<"\n"<<setw(85)<<"------------------------------------------------------------"
				<<"\n"<<setw(78)<<">>>> Presione la tecla enter para continuar <<<<"
				<<"\n"<<setw(85)<<"------------------------------------------------------------"
				<<"\n"<<setw(55)<<":V";
			limiteCero();
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
				<<"\n"<<setw(28)<<"***"<<setw(57)<<"***"
				<<"\n"<<setw(85)<<"------------------------------------------------------------"
				<<"\n"<<setw(78)<<">>>> Presione la tecla enter para continuar <<<<"
				<<"\n"<<setw(85)<<"------------------------------------------------------------"
				<<"\n"<<setw(55)<<":V";
			limiteCero();
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
				<<"\n"<<setw(28)<<"***"<<setw(57)<<"***"
				<<"\n"<<setw(85)<<"------------------------------------------------------------"
				<<"\n"<<setw(78)<<">>>> Presione la tecla enter para continuar <<<<"
				<<"\n"<<setw(85)<<"------------------------------------------------------------"
				<<"\n"<<setw(55)<<":V";
			limiteCero();
			menuOpciones();
		}
	}
}
//Final Funcion validarClaveTransferenciaDinero()









void cuentaCorriente(){
	cout<<"\n\t\tPor favor complete todos los datos para coninuar con la transaccion."<<endl;
}

void otrosBancos(){
	cout<<"\n\t\tPor favor complete todos los datos para coninuar con la transaccion."<<endl;
}

/*cout<"Indique el banco (lista de bancos)"
cout<<"Numero de cuenta"*/



