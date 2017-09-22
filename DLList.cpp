#include "DLList.h"
#include "NodeDL.cpp"
#include <string>
using namespace std;

template <template T> class DLList {
public:
	NodeDL<T>* first;
	NodeDL<T>* last;
	NodeDL<T>* pointer;
	int length;

	DLList() { //Constructor por defecto
		first = NULL;
		last = NULL;
		pointer = NULL;
		length = 0;
	}

	DLList(T d) {
		NodeDL<T> node = new NodeDL<T>(d);
		//Apuntamos primero y ultimo al nuevo nodo
		*first = node;
		*last = node;
		//Incrementamos el contador de elementos de la lista
		length++;
	}

	//Metodos: Esta vacía? 
	bool isEmpty() {
		return length == 0; //Si length es cero, regresa un True 
	}

	//Insertar al inicio
	//Escenarios: Lista Vacia, Lista con elementos;
	void insertFirst(T d) {
		NodeDL<T> node = NodeDL<T>(d);
		if (isEmpty()) { //Si la lista esta vacia
			*first = node;
			*last = node;
			
		}
		else { //Si la lista ya cuenta con elementos 
			//El siguiente del nuevo nodo apunta al nodo que apunta first
			node.next* = first; //Node es un objeto ya instanciado, tiene la propiedad .next
			//El nodo que apunta first en su apuntador back apuntara al nuevo nodo
			first->back = node; //Usamos flecha porque first es un apuntador, no tiene propiedades
			//El apuntador first apunta al nuevo nodo 
			*first = node;
			
		}
		length++;
	}

	void insertLast(T d) {
		NodeDL<T> node = NodeDL<T>(d);
		if (isEmpty()) { //Si la lista esta vacia
			*first = node;
			*last = node;
		}
		else {
			node.back* = last;
			last->next = node;
			*last = node;
		}
		length++;
	}

	void deleteFirst() {
		if (!isEmpty()) {
			if (first->next = NULL) {
				first = nullptr;
				last = nullptr;
			}
			else {
				first = first->next;
			}
			length--;
		}
	}
	//& es para obtener la direccion de memoria
	//* es para obtener el contenido
	void deleteLast() {
		if (!isEmpty()) {
			if (first->next = NULL) {
				first = nullptr;
				last = nullptr;
			}
			else {
				last = last->back;
			}
			length--;
		}
	}

	bool deleteNode(T d) {
		Node node = fetch(d);
		if (node != null) { //Si encuentra el elemento
			if (node.data == d) { //Si fue el primero o unico elemento de la lista...
				deleteFirst();
			}
			else { //Si esta dentro de la lista
				node.back.next = node.next;
				node.next.back = node.back;
			}                           
			return true;  
			length--;
		}
		return false;
	}

	void showListFirstLast() {
		pointer = first;
		System.out.print("first->");
		for (int i = 0; i<length; i++) {
			System.out.print("[" + std::string to_string(pointer.data); + "]->");
			pointer = pointer->next;
		}
		System.out.println("<-last");
	}
	
	void showListLastFirst() {
		pointer = last;
		System.out.print("last->");
		for (int i = length; i>0; i--) {
			System.out.print("[" + std::string to_string(pointer.data); +"]->");
			pointer = pointer->back;
		}
		System.out.println("<-first");
	}

	NodeDL fetch(T d){
		pointer = first;
		if (!isEmpty()) {
			if (first == last) { //Si hay un solo elemento
				if (first.data == d) { //Es el elemento que busco?
					return first; //Se devuelve a si mismo 
				}
				else {
					return nullptr;
				}
			}
			else { //Si hay mas elementos en la lista
				if (first.data == d) { //El elemento que busco es el primero?
					return first;
					/*}else if(last.data == n){
					return last;*/
				}
				else {
					pointer = first; //Iniciamos el puntero 

					while (pointer.next != last) { //Mientras que el puntero sea diferente al ultimo 
						if (pointer.data == d) { //La data del puntero es la que buscamos en d
							return pointer; //Regresamos el apuntador 
						}
						pointer = pointer.next; //En caso de que no, mueve el puntero 
					}
				}
			}
		}
	}

	
};






