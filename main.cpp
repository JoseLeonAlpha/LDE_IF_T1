//
//  main.cpp
//  LDE_I_F
//
//  Created by Jafeth Alonso Carreón on 4/2/20.
//  Copyright © 2020 Jafeth Alonso Carreón. All rights reserved.
//

#include <iostream>
using namespace std;

class Nodo
{
private:
    int dato;
    Nodo *sig;
    Nodo *ant;
public:
    Nodo()
    {    dato=0;
        sig=NULL;
        ant=NULL;
    }
    Nodo(int x)
    {    dato=x;
        sig=NULL;
        ant=NULL;
    }
    void Asignasig(Nodo*);
    void Asignaant(Nodo*);
    void Leer(int);
    void Imprimir();
    Nodo *Obtienesig();
    Nodo *Obtieneant();
    int Obtienedato();
};
class LDE
{    private:
    Nodo *Inicio, *Fin;
public:
    void InsertarI(int);
    void InsertarF(int);
    void BorrarI();
    void BorrarF();
    void Imprimir();
    void ImprimirR();
    int Contar();
    Nodo *Buscar(int);
    void Borrar(int);
    LDE()
    {
        Inicio=NULL;
        Fin=NULL;
        
    }
    
};





void Nodo::Asignasig(Nodo *x)
{
    this->sig=x;
}
void Nodo::Asignaant(Nodo *x)
{
    this->ant=x;
}


void Nodo::Leer(int x)
{
    this->dato=x;
}
void Nodo::Imprimir()
{
    cout<<this->dato<<endl;
}
Nodo* Nodo::Obtienesig()
{
    return(this->sig);
}

Nodo* Nodo::Obtieneant()
{
    return(this->ant);
}


int Nodo::Obtienedato()
{
    return(this->dato);
}

void LSE::InsertarI(int x)
{      if(!Inicio){//Si no hay un inicio
	Inicio=new Nodo(x);//Crea un nodo y lo iguala con inicio
    Fin=Inicio;//si hay un solo dato ese dato es el inicio y el fin
}else
    {
        Nodo *helpx3=new Nodo(x);//Crea un nodo que guarda una direccion
        helpx3->Asignasig(Inicio);//helpx3 esta apuntanto a asigna siguiente que este a su vez es inicio
        Inicio=helpx3;
    }
}


void LSE::InsertarF(int x){
	if(Inicio==NULL){//Si inicio esta vacio
		Inicio=new Nodo(x); //Creamos un nuevo nodo
		Fin=Inicio;//Para que este a su vez sea el ultimo datp ingresado
	}else{
			Nodo *ayuda=new Nodo(x); //Si ya hay algun dato creamos un nuevo nodo que guarde la direecion
			Fin->Asignasig(ayuda); //al ingresar el ultimo dato asignamos al nodo sig que apunte al nodo que se creo
			Nodo *b=Fin; //Guardamos la direccion al nodo fin
			Fin=ayuda; //Ingualamos ayuda a fin que es el ulttimo valor ingresado

	}

}



int main(int argc, const char * argv[])
{
    
    
    
    LDE A;
    int opc, dato;
    do{
        cout<<"1.- Insertar Inicio"<<endl;
        cout<<"2.- Insertar Fin"<<endl;
        cout<<"3.- Borrar Inicio"<<endl;
        cout<<"4.- Borrar Fin"<<endl;
        cout<<"5.- Contar"<<endl;
        cout<<"6.- Borrar"<<endl;
        cout<<"7.- Imprimir"<<endl;
        cout<<"8.- Imprimir en Reversa"<<endl;
        cout<<"9.- Salir"<<endl;
        cout<<"Teclee la opcion"<<endl;
        cin>>opc;
        
        switch(opc)
        {
            case 1:
                cout<<"teclee el dato a insertar"<<endl;
                cin>>dato;
                A.InsertarI(dato);
                break;
            case 2:
                cout<<"Teclee el dato a insertar"<<endl;
                cin>>dato;
                A.InsertarF(dato);
                break;
            case 3:
                A.BorrarI();
                break;
            case 4:
                A.BorrarF();
                break;
            case 5:
                dato=A.Contar();
                cout<<"Hay "<<dato<<" nodos en la Lista"<<endl;
                break;
            case 6:
                cout<<"Teclee el dato a borrar"<<endl;
                cin>>dato;
                A.Borrar(dato);
                break;
            case 7:
                A.Imprimir();
                break;
            case 8:
                A.ImprimirR();
                break;
            default:
                cout<<"opción salir...";
                break;
        }
    }while(opc<9);
    
    return 0;
}
