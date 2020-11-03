#include <iostream>
#include <cstring>
#include <string>
#include <time.h> 
#include <stdlib.h>
#include <conio.h> //getch

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
void escape();
void cambioClave();
void seeKey();
void clearCambioClave();
void clearIngresar();
void clearRetirar();
void clearTransferencias();
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
	
	int i;
	char caracter;
	
	cout<<"\n\n\t- Ingrese su documento de identidad: ";
	
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
		cout<<"\n\n\t\tERROR // El campo esta vacio, ingrese una opcion.";
		cambioDocumento();
	}
	
	if(strlen(documento) < longiCedula){
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
void claveAutomatica(int key) {
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
	
	cout<<"\n\n\t\t\t//Menu de opciones//"<<endl
		<<"\n\t\t\t1. Ingresar dinero"<<endl
		<<"\n\t\t\t2. Retirar dinero"<<endl
		<<"\n\t\t\t3. Transferencias"<<endl
		<<"\n\t\t\t4. Ver saldo"<<endl
		<<"\n\t\t\t5. Ver mis datos"<<endl
		<<"\n\t\t\t6. Modificar nombre"<<endl
		<<"\n\t\t\t7. Cambiar clave"<<endl
		<<"\n\t\t\t8. Salir"<<endl
		<<"\n\t-Elija una opcion: ";
	cin>>opcionMenu;
	cin.ignore(); // Se coloca despues de un cin para ignore el ultimo \n
	
	
	switch(opcionMenu){
		case 1: 
			if(bloqueoIngreso == true){
				clear();
				cout<<"\n\n\t\tUsted ya ha superado el numero mayor de intentos, para realizar el ingreso de su dinero\n"
					<<" \t\tcomuniquese al 01-8000-555-666 o acerquese a una de nuestras oficinas."<<endl
					<<"\n\n\n\t------------------------------------------------------------------------------------------------"<<endl;
				menuOpciones();
		
			} else{
				clearIngresar(); 
				ingresarDinero();
			}
		
		case 2:
			if(bloqueoRetiro == true){
				clear();
				cout<<"\n\n\t\tUsted ya ha superado el numero mayor de intentos, para realizar el retiro de su dinero\n"
					<<" \t\tcomuniquese al 01-8000-555-666 o acerquese a una de nuestras oficinas."<<endl
					<<"\n\n\n\t------------------------------------------------------------------------------------------------"<<endl;
				menuOpciones();
		
			} else{
				clearRetirar(); 
				retirarDinero();
			}
		
		case 3:
			if(bloqueoTransaccion == true){
				clear();
				cout<<"\n\n\t\tUsted ya ha superado el numero mayor de intentos, para realizar la transaccion\n"
					<<" \t\tcomuniquese al 01-8000-555-666 o acerquese a una de nuestras oficinas."<<endl
					<<"\n\n\n\t------------------------------------------------------------------------------------------------"<<endl;
				menuOpciones();
				
			} else{
				clearTransferencias();
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
	
	cout<<"\n\n\t- Ingrese su clave, tiene 3 intentos: ";
	
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
	
	validarClaveGlobal();
	
	if(j == 0){
		clearCambioClave();
		cout<<"\n\n\t\tERROR // No ha ingresado ningun numero."<<endl;
		cambioClave();
	}
	
	if(j < longitud){
		clearCambioClave();
		
		while(k < 3){
			cout<<"\n\n\n\t\tERROR // Debe ingresar una clave valida."<<endl
			<<"\n\n\t\t*** Numero de intentos: "<<k<<" de 3 ***"<<endl;
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
		clearCambioClave();
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




//Inicio Funcion clearCambioClave()
void clearCambioClave(){
	system("cls");
	cout<<"\t\t\t\tBienvenido a Tu Banco Virtual"<<endl
	<<"\n\n\n\t\t\t\t***Cambio de clave***"<<endl
	<<"\n\t\t***Si desea cancelar el procedimiento, presione la tecla 'Esc' en cualquier momento***"<<endl<<endl;
}
//Final Funcion clearCambioClave()




//Inicio Funcion clearIngresar()
void clearIngresar(){
	system("cls");
	cout<<"\t\t\t\tBienvenido a Tu Banco Virtual"<<endl
	<<"\n\n\n\t\t\t\t***Ingresar dinero***"<<endl
	<<"\n\t\t***Si desea cancelar el procedimiento, presione la tecla 'Esc' en cualquier momento***"<<endl<<endl;
}
//Final Funcion clearIngresar()




//Inicio Funcion clearRetirar()
void clearRetirar(){
	system("cls");
	cout<<"\t\t\t\tBienvenido a Tu Banco Virtual"<<endl
	<<"\n\n\n\t\t\t***Retirar dinero***"<<endl
	<<"\n\t\t***Si desea cancelar el procedimiento, presione la tecla 'Esc' en cualquier momento***"<<endl<<endl;
}
//Final Funcion clearRetirar()




//Inicio Funcion clearTransferencias()
void clearTransferencias(){
	system("cls");
	cout<<"\t\t\t\tBienvenido a Tu Banco Virtual"<<endl
	<<"\n\n\n\t\t\t***Transferencia***"<<endl
	<<"\n\t\t***Si desea cancelar la transaccion, presione la tecla 'Esc' en cualquier momento***"<<endl<<endl;
}
//Final Funcion clearTransferencias()




//Inicio Funcion ingresarDinero()
void ingresarDinero(){
	
	cout<<"\n\t- Cuanto dinero desea ingresar: $ ";
	escape();
	
	if(e == 0){
		clearIngresar();
		cout<<"\n\n\t\tERROR // El campo esta vacio, ingrese un valor."<<endl;
		ingresarDinero();
	}
	
		//Convertir un char a int 
	dineroIngreso = atoi(valor);
	
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
		cout<<"\n\n\t\tERROR // El valor ingresado no es valido."<<endl;
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
	
	cout<<"\n\t- Cuanto dinero desea retirar: $ ";
	escape();
		
	if(e == 0){
		clearRetirar();
		cout<<"\n\n\t\tERROR // El campo esta vacio, ingrese un valor."<<endl;
		retirarDinero();
	}
	
	dineroRetiro = atoi(valor); //Convertir un string a int
	
	if(dineroRetiro > dineroTotal){
		clearRetirar();
		cout<<"\n\n\t\tERROR // Fondos inuficientes."<<endl;
		retirarDinero();
	
	} else if (dineroRetiro > 0 && dineroRetiro <= dineroTotal){
		clearRetirar();	
		validarClaveRetiroDinero();	
			
	} else{
		clearRetirar();
		cout<<"\n\n\t\tERROR // El valor ingresado no es valido."<<endl;
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




//Inicio Funcion transferencias()
void transferencias(){
	
	int opcionTransferencia;
	
	cout<<"\n\t//Por favor indique a donde quiere transferir el dinero.//"<<endl
		<<"\n\t\t\t1. A Cuenta de Ahorros Tu banco virtual."<<endl
		<<"\n\t\t\t2. A Cuenta Corriente Tu banco virtual."<<endl
		<<"\n\t\t\t3. A otro Banco."<<endl
		<<"\n\t-Elija una opcion: ";
	cin>>opcionTransferencia;
	cin.ignore();
	
	switch(opcionTransferencia){
		case 1: clearTransferencias(); cuentaAhorros();
		case 2: clearTransferencias(); cuentaCorriente();
		case 3: clearTransferencias(); otrosBancos();
		default: clearTransferencias(); cout<<"\n\t\tLa opcion no es correcta, intentelo de nuevo."<<endl; transferencias();
	}
}
//Final Funcion transferencias()




//Inicio Funcion validarNumeroCuenta()
void validarNumeroCuenta(){
	
	int i;
	char caracter;
	
	cout<<"\n\t\tPor favor complete todos los datos para continuar con la transaccion."<<endl
		<<"\n\t- Numero de Cuenta de Ahorros: ";
	
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
		cout<<"\n\n\t\tERROR // El campo esta vacio, ingrese un valor."<<endl;
		validarNumeroCuenta();
	}
	
	if(strlen(numeroCuenta) < longiNumeroCuenta){
		clearTransferencias();
		cout<<"\n\n\t\tERROR // El numero ingresado no es valido."<<endl;
		validarNumeroCuenta();	
	} 
}
//Final Funcion validarNumeroCuenta()




//Inicio Funcion validarCantidadTransferir()
void validarCantidadTransferir(){
	
	cout<<"\n\t\tPor favor complete todos los datos para continuar con la transaccion."<<endl
		<<"\n\t- Cuanto dinero desea transferir: $ ";
	escape();
	
	if(e == 0){
		clearTransferencias();
		cout<<"\n\n\t\tERROR // El campo esta vacio, ingrese un valor."<<endl;
		validarCantidadTransferir();
	}
	
	dineroTransferencia = atoi(valor);
	
	if(dineroTransferencia > dineroTotal){
		clearTransferencias();
		cout<<"\n\n\t\tERROR // Fondos inuficientes."<<endl;
		validarCantidadTransferir();
	
	} else if (dineroTransferencia > 0 && dineroTransferencia <= dineroTotal){
		clearTransferencias();	
		validarClaveTransferenciaDinero();	
			
	} else{
		clearTransferencias();
		cout<<"\n\n\t\tERROR // El valor ingresado no es valido."<<endl;
		validarCantidadTransferir();
	}
}
//Final Funcion validarCantidadTransferir()




//Inicio Funcion validarClaveTransferenciaDinero()
void validarClaveTransferenciaDinero(){
	
	validarClaveGlobal();
	
	if(j == 0){
		clearTransferencias();
		cout<<"\n\n\t\tERROR // No ha ingresado ningun numero.";
		validarClaveTransferenciaDinero();
	}
	
	if(j < longitud){
	
		while(l < 3){
			clearTransferencias();
			cout<<"\n\n\t\tERROR // La clave no es valida."
			<<"\n\n\t\t*** Numero de intentos: "<<l<<" de 3 ***";
			l++;
			validarClaveTransferenciaDinero();
		}
		
		if(l > 2){
			clear();
			bloqueoTransaccion = true;
			cout<<"\n\n\t\t*** Numero de intentos: "<<l<<" de 3 ***"
			<<"\n\n\t\tHa superado el numero mayor de intentos, para realizar el ingreso de su dinero\n"
			<<" \t\tcomuniquese al 01-8000-555-666 o acerquese a una de nuestras oficinas."<<endl;
			cout<<"\n\n\n\t------------------------------------------------------------------------------------------------"<<endl;
			menuOpciones();
		}
	} else {
		
		valorTransferencia = atoi(password);
		
		if(valorTransferencia == key){
			clear();
			dineroTotal -= dineroTransferencia;
			cout<<"\n\n\t\t*** Transferencia de dinero exitosa. ***"<<endl;
			cout<<"\n\n\t\tAcabo de transferir: $"<<dineroTransferencia
			<<"\n\n\t\tSaldo en cuenta: $"<<dineroTotal;
			cout<<"\n\n\t------------------------------------------------------------------------------------------------"<<endl;
			menuOpciones();
		}
		
		while(l < 3){
			clearTransferencias();
			cout<<"\n\n\t\tERROR // La clave no es valida."
			<<"\n\n\t\t*** Numero de intentos: "<<l<<" de 3 ***";
			l++;
			validarClaveTransferenciaDinero();
		}
		
		if(l > 2){
			clear();
			bloqueoTransaccion = true;
			cout<<"\n\n\t\t*** Numero de intentos: "<<l<<" de 3 ***"
			<<"\n\n\t\tHa superado el numero mayor de intentos, para realizar el ingreso de su dinero\n"
			<<" \t\tcomuniquese al 01-8000-555-666 o acerquese a una de nuestras oficinas."<<endl;
			cout<<"\n\n\n\t------------------------------------------------------------------------------------------------"<<endl;
			menuOpciones();
		}
	}
}
//Final Funcion validarClaveTransferenciaDinero()




//Inicio Funcion cuentaAhorros()
void cuentaAhorros(){
	
	validarNumeroCuenta();
	clearTransferencias();
	validarCantidadTransferir();
	
	validarClaveTransferenciaDinero();
}
//Final Funcion cuentaAhorros()








void cuentaCorriente(){
	cout<<"\n\t\tPor favor complete todos los datos para coninuar con la transaccion."<<endl;
}

void otrosBancos(){
	cout<<"\n\t\tPor favor complete todos los datos para coninuar con la transaccion."<<endl;
}

/*cout<"Indique el banco (lista de bancos)"
cout<<"Numero de cuenta"*/

