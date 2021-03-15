#include<iostream>
#include <fstream>
#include <windows.h>
using namespace std;



int menu() {
	int CodigoEmpleado;
	char Nombres;
	char Apellidos;
	char Puesto;
	int SueldoBase=0;
	int Bonificacion=0;
	int sum=0;
	int suma=0;
	int opc;
	float resultado=0;
	int x;
	system("cls");
	
	cout<<"\tBienvenido,eliga una de estas opciones: "<<endl;
	cout<<"1. Ingrese el empleado"<<endl;
	cout<<"2. Mostrar los registros: "<<endl;
	cout<<"3. Buscar Empleado"<<endl;
	cout<<"4. Modificar"<<endl;
	cout<<"5. Eliminar Registro"<<endl;
	cout<<"6. Saldo Total"<<endl;
	cout<<"7. salir"<<endl;
	cout<<"Opcion: "; 
	cin>>x;
	return x;
	}
	
	bool verifica(string codi){
		ifstream leer("Empleados.txt", ios::in);
		string Nom;
		string Codi;
		string Ape;
		string Pues;
		string Suel;
		string Boni;
		leer>>Nom;
		while(!leer.eof()){
		leer>>Ape;
		leer>>Codi;
		
		if(Codi == codi){
			leer.close();
			return false;
			
		}
		
		leer>>Nom;
	}
	leer.close();
			return true;	
	}
	
	void agregar (ofstream &es) {
			system("cls");
		string Nom;
		string Codi;
		string Ape;
		string Pues;
		string Suel;
		string Boni;
		es.open("Empleados.txt", ios::out | ios::app);
		cout<<"Nombre";
		cin>>Nom;
		cout<<"Apellido";
		cin>>Ape;
		cout<<"Codigo";
		cin>>Codi;
		cout<<"Puesto";
		cin>>Pues;
		cout<<"SueldoBase";
		cin>>Suel;
		cout<<"Bonificacion";
		cin>>Boni;
		if(verifica(Codi))
		es<<Nom<<" "<<Ape<<" "<<Codi<<" "<<Pues<<" "<<Suel<<" "<<Boni<<"\n ";
		es.close();
		
		
	}
	
	
	void verRegistros(ifstream &Lec){
		system("cls");
		string nom;
		string codi;
		string ape;
		string pues;
		string suel;
		string boni;
		Lec.open("Empleados.txt", ios::in);
		cout<<"-----------Personas Registradas--------"<<endl<<endl;
		Lec>>nom;
		while(!Lec.eof()){
			Lec>>ape;
			Lec>>codi;
			Lec>>pues;
			Lec>>suel;
			Lec>>boni;
			cout<<"Nombre-----: "<<nom<<endl;
			cout<<"Apellidos-----: "<<ape<<endl;
			cout<<"Codigo-----: "<<codi<<endl;
			cout<<"Puesto-----: "<<pues<<endl;
			cout<<"SueldoBase-----: "<<suel<<endl;
			cout<<"Bonificacion-----: "<<boni<<endl;
			cout<<"--------------------------------"<<endl;
			Lec>>nom;
			
		
		
		}
	Lec.close();
	system("pause");
	
	}
	
	
	void buscarEmpleado(ifstream &Lec){
		system("cls");
		Lec.open("Empleados.txt", ios::in);
		string nom,ape,codi,pues,suel,boni, codiaux;
		bool encontrado = false;
		cout<<"Digite el codigo";
		cin>>codiaux;
		Lec>>nom;
		while(!Lec.eof()  &&  !encontrado)  {
		Lec>>ape;
		Lec>>codi;
		Lec>>pues;
		Lec>>suel;
		Lec>>boni;
		if(codi == codiaux){
			cout<<"Nombre-----: "<<nom<<endl;
			cout<<"Apellidos-----: "<<ape<<endl;
			cout<<"Codigo-----: "<<codi<<endl;
			cout<<"Puesto-----: "<<pues<<endl;
			cout<<"SuelBase-----: "<<suel<<endl;
			cout<<"Bonificacion-----: "<<boni<<endl;
			cout<<"--------------------------------"<<endl;
			encontrado = true;
			
		}
		Lec>>nom;
		
		
		}
		Lec.close();
		
		if(!encontrado)
		cout<<"Dato no encontrado"<<endl;
	system("pause");
	}
	
	
	void modificarRegistro(ifstream &Lec){
	system("cls");
		string nom;
		string codi;
		string ape;
		string codiaux;
		string nomaux;
		Lec.open("Empleados.txt", ios::in);
		ofstream aux("auxiliar.txt", ios::out);
		if(Lec.is_open()){
			cout<<"Codigo ";
			cin>>codiaux;
			Lec>>nom;
			while(!Lec.eof()){
			Lec>>ape;
			Lec>>codi;
			if(codi == codiaux){
				cout<<"Nuevo Nombre ";
				cin>>nomaux;
				aux<<nomaux<<" "<<ape<<" "<<codi<<"\n";
				
			}else{
				aux<<nom<<" "<<ape<<" "<<codi<<"\n";
			
			}
			Lec>>nom;
			
			}
			
			Lec.close();
			aux.close();
		}else
		cout<<"Error"<<endl;
		remove("Empleados.txt");
		rename("auxiliar.txt", "Empleados.txt");
	
	
	
	}
	
	void eliminarRegistro(ifstream &Lec){
		system("cls");
		string nom;
		string codi;
		string ape;
		string codiaux;
		string nomaux;
		Lec.open("Empleados.txt", ios::in);
		ofstream aux("auxiliar.txt", ios::out);
		if(Lec.is_open()){
			cout<<"Codigo ";
			cin>>codiaux;
			Lec>>nom;
			while(!Lec.eof()){
			Lec>>ape;
			Lec>>codi;
		
			if(codi == codiaux){
				cout<<"Eliminado** ";
				Sleep(1500);
				
				
			}else{
				aux<<nom<<" "<<ape<<" "<<codi<<"\n";
			
			}
			Lec>>nom;
			
			}
			
			Lec.close();
			aux.close();
		}else
		cout<<"Error"<<endl;
		remove("Empleados.txt");
		rename("auxiliar.txt", "Empleados.txt");
		
		
		
	
	
	
	}
	

	void SaldoTotal(ifstream &Lec){
		
		system("cls");
		string suel;
		string boni;
		string sum;
		cout<<"Ingrese el sueldo";
		cin>>suel;
		cout<<"Ingrese la bonificacion";
		cin>>boni;
		
		sum = suel+boni;
		
		cout<<"El saldo total es: "<<sum<<endl;
		
		
		system("pause");
	
	/* en este no entiendo porque me tira mal la suma literal suma los numeros jaja 50+10= 5010 */
		
		
	}
	
	
	int main() {
		ofstream Esc;
		ifstream Lec;
		int op;
		do{
			system("cls");
			op = menu();
			
		switch(op){
		case 1:
			agregar(Esc);
		break;
			case 2:
				verRegistros(Lec);
				
				
				case 3:
					buscarEmpleado(Lec);
					
					
					
					break;
			case 4:
				modificarRegistro(Lec);
				break;
				
			case 5:
				eliminarRegistro(Lec);
				
				break;
				
			case 6:
				SaldoTotal(Lec);
				
				break;
		}	
			
		} while(op !=7);
			   
				
	return 0;

}
