#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <string.h >
#include <windows.h>
#include <stdlib.h>

using namespace std;

const char *Traductor = "Traductor.dat"; //nombre_archivo

void gotoxy(int x, int y){
	HANDLE hcon;
	hcon= GetStdHandle (STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X=x;
	dwPos.Y=y;
	SetConsoleCursorPosition (hcon,dwPos); 
}


struct Palabras{
	char pal_ing[20];
	char pal_esp[20];
	char pal_info[300];
};

struct Traduc{
	char cadena[500];
	
	
	
};

void abrir_palabra();
void ingresar_palabra();
void modificar_palabra();
void traducir();
void eliminar_palabra();

int main(){
	char cargando=219;
	system("color 3F");
    int opcion;
    
        system("cls");
    	gotoxy(45,1);
    	cout<<"Universidad Mariano Galvez de Guatemala";
    	gotoxy(45,2);
    	cout<<"La antigua Guatemala";
    	gotoxy(45,3);
    	cout<<"Curso: Programacion l";
    	gotoxy(45,5);
    	cout<<"Integrantes:";
    	gotoxy(45,6);
    	cout<<"1.EDGAR ENRIQUE GARCIA CATALAN ";
    	gotoxy(45,7);
    	cout<<"2. KENNY ABRAHAM ANDRINO CHAVEZ";
    	gotoxy(45,8);
    	cout<<"3. GUADALUPE BERONICA ARREAGA ARREAGA";
    	gotoxy(45,9);
    	cout<<"4. ALLAN GABRIEL CARCUZ VILLATORO";
    	gotoxy(45,10);
    	cout<<"5.GUSTAVO ADOLFO LAZARO CHACON";
 //       system("cls"); 
//		cout<<endl;
		gotoxy(50,13);       
        cout << "Menu principal" << endl;
        gotoxy(50,16);
        cout << "1. Leer palabras guardadas" << endl;
        gotoxy(50,18);
        cout << "2. Ingresar nueva palabra" << endl;
        gotoxy(50,20);
        cout << "3. Modificar Palabra" << endl;
        gotoxy(50,22);
        cout << "4. Traducir Codigo" << endl;
        gotoxy(50,24);
        cout << "5. Eliminar palabra" << endl;
        gotoxy(50,26);
        cout << "6. SALIR" << endl;
        gotoxy(50,28);
        cout << "Que deseas realizar: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                system("cls");
                cout<<"Cargando ";
                for(int q = 0; q<=60;q++){
                	Sleep(60);
                	cout<<cargando;
				}
                abrir_palabra();
                break;
                
            case 2:
                system("cls");
                cout<<"Cargando ";
                for(int w = 0; w<=60;w++){
                	Sleep(60);
                	cout<<cargando;
				}
                ingresar_palabra();
                break;
                
            case 3:
                system("cls");
                cout<<"Cargando ";
                for(int e = 0; e<=60;e++){
                	Sleep(60);
                	cout<<cargando;
				}
				modificar_palabra();  
                break;
                
            case 4:
                system("cls");
                cout<<"Cargando ";
                for(int r = 0; r<=60;r++){
                	Sleep(60);
                	cout<<cargando;
				}
				traducir();  
                break;
			    
            case 5:
                system("cls");
                cout<<"Cargando ";
                for(int t = 0; t<=60;t++){
                	Sleep(60);
                	cout<<cargando;
				}
				eliminar_palabra();    
                break;
                
            case 6:
                system("cls");
				return 0;
				   
        }     
           
    return 0;
    
}

void abrir_palabra(){
	system("cls");
	FILE* archivo = fopen(Traductor, "rb");
	if(!archivo) {
		archivo = fopen(Traductor, "w+b");
	}
	Palabras palabras;
	int registro=1;
	fread ( &palabras, sizeof(Palabras), 1, archivo );
	do{
	cout<<"| No."<<registro<<" | \n"<<"Palabra original: "<< palabras.pal_ing <<"\nPalabra traducida: "<< palabras.pal_esp<<"\nDescripcion: "<<palabras.pal_info<<"\n"<<endl;
	
	fread ( &palabras, sizeof(Palabras), 1, archivo );
		registro += 1;	
		} while (feof( archivo ) == 0);
		
    cout<<endl;    
	fclose(archivo);
	
	_getch();
	main();
}

void ingresar_palabra(){
	
	char continuar;
	FILE* archivo = fopen(Traductor, "ab");
	if(!archivo) {
		archivo = fopen(Traductor, "w+b");
	}
	
		Palabras palabras;
		string pal_ing,pal_esp,pal_info;
		system("cls");
		
		do{
			fflush(stdin);
			
		cout<<"Ingrese palabra en ingles: ";
		getline(cin,pal_ing);
        strcpy(palabras.pal_ing, pal_ing.c_str()); 
        
		cout<<"Ingrese palabra en espanol: ";
		getline(cin,pal_esp);
    	strcpy(palabras.pal_esp, pal_esp.c_str()); 
    	
		cout<<"Ingrese definicion: ";
		getline(cin,pal_info);
    	strcpy(palabras.pal_info, pal_info.c_str()); 
		
		fwrite( &palabras, sizeof(Palabras), 1, archivo );
		
		cout<<"Desea agregar otra palabra S/N: ";
		cin>>continuar;
		}
		while((continuar=='s') || (continuar=='S'));
		
		
		fclose(archivo);
		
	_getch();
	main();
}

void modificar_palabra(){
	system("cls");
	
	FILE* archivo = fopen(Traductor, "r+b");
	int id;
		
    	Palabras palabras;
		string pal_ing,pal_esp,pal_info;
    	
    	cout << "Ingrese el id que desea Modificar: ";
    	cin >> id;
    	id=id-1;
    	fseek ( archivo, id * sizeof(Palabras), SEEK_SET );
		
		getline(cin,pal_ing);
        strcpy(palabras.pal_ing, pal_ing.c_str());
		
		cout<<"Ingrese palabra en ingles: ";
		getline(cin,pal_ing);
        strcpy(palabras.pal_ing, pal_ing.c_str()); 
        
		cout<<"Ingrese palabra en espanol: ";
		getline(cin,pal_esp);
    	strcpy(palabras.pal_esp, pal_esp.c_str()); 
    	
		cout<<"Ingrese definicion: ";
		getline(cin,pal_info);
    	strcpy(palabras.pal_info, pal_info.c_str());
    	
    	fwrite( &palabras, sizeof(Palabras), 1, archivo );
		fclose(archivo);
		
	_getch();
	main();	
}

void traductor(string& frase, string buscar,string rempl){
	int pos= frase.find(buscar);
	while (pos != -1){
		frase.replace(pos,buscar.size(),rempl);
		pos = frase.find(buscar, pos + rempl.size());
	}
}

void traducir(){
	system("cls");
	
	FILE* archivo = fopen(Traductor, "rb");
	string frase;
	Palabras palabras;
	cout<<"Ingrese codigo para traducir: "<<endl;
	cout<<"Ingrese el caracter '$' para traducir tu codigo"<<endl;
	getline(cin,frase,'$');
	
	fread(&palabras,sizeof(Palabras),1,archivo);	
	do{
		
		traductor(frase, palabras.pal_ing, palabras.pal_esp);
		fread ( &palabras, sizeof(Palabras), 1, archivo );
	} while (feof( archivo ) == 0);
	cout<<"\n\nEste es el codigo traducido: "<<endl;
	
	
	cout<<frase<<endl;
	fclose(archivo);
	
	_getch();
	main();
}



void eliminar_palabra(){
	system("cls");
	
	const char *nombre_temp = "temp.dat";
	int aux=0;
	char borrar[20];
	
	Palabras palabras;

	FILE* archivo = fopen(Traductor, "rb");
	FILE* temp = fopen(nombre_temp, "wb");
	cout<<"ingrese palabra que desea borrar: ";
	cin>>borrar;
	
	while (fread(&palabras,sizeof(Palabras),1,archivo) != NULL) {
		if (strcmp (borrar, palabras.pal_ing) == 0) {
			cout<<"\nla palabra ha sido eliminada.";
			aux=1;
		} else {
			fwrite(&palabras, sizeof(Palabras), 1, temp);
		}
	}

	fclose(archivo);
	fclose(temp);

	remove("Traductor.dat");
	rename("temp.dat", "Traductor.dat");
	 
	
	_getch();
	main();
}
