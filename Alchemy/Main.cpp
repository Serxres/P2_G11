#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>
#include <cstdlib>


//STRUCT QUE NOS SERVIRA PARA CREAR LAS KEYS DEL UNORDERED_MAP
struct combinations
{
	std::string first;
	std::string second;
};

//FUNCION QUE IMPRIME LAS INSTRUCCIONES
void printInstructions()
{
	std::cout << "//////////////////" << "\n"
			<< "TEAM ANCIA ALCHEMY\n" <<
			"//////////////////" << "\n" << "\n" <<
			"- Enter two number of your elemtns list to combine them.\n" <<
			"- Enter the word 'add' and a number of an element to add a new instance of that element\n" <<
			"- Enter 'add basics' to add new instances of the 4 basic elemtns.\n" <<
			"- Enter the word 'delete' and the number of an element to erase it from your list.\n" <<
			"- Enter the word 'info' and the number of an element to get the information about it in the explorer.\n" <<
			"- Enter the word 'sort' to sort by alphabetical order the elements in the list.\n" <<
			"- Enter the word 'clean' to delete all the instances of repeated elements.\n" <<
			"- Enter the word 'help' to show this tutorial." << std::endl;
}

//FUNCION QUE GUARDA TODA LA LISTA DE ELEMENTOS EN UN UNORDERED_MAP
void fillListOfElements(std::unordered_map<std::string, std::string> &elementsList)
{ 

	std::ifstream elements("elements.dat");
	//STRING DONDE GUARDAREMOS CADA LINEA PARA DESPUES UTILZARLA
	std::string line;

	
	//COMPROBAMOS SI EL ARCHIVO SE HA ABIERTO CORRECTAMENTE
	if (elements.is_open() == true)
	{
		size_t equalPosition;
		size_t plusPosition;
		std::string key1;
		std::string key2;
		std::string keyTotal;
		std::string value;
 
		//QUE VAYA LEYENDO MIENTRAS NO SE LLEGUE AL FINAL DEL ARCHIVO
		while (elements.eof() != true)
		{
			getline(elements, line);
			equalPosition = line.find("=");
			plusPosition = line.find('+');

			value = line.substr(0, equalPosition - 1);
			key1 = line.substr(equalPosition + 2, plusPosition - 2);
			key2 = line.substr(plusPosition + 2, line.size());


			std::cout << value << "!" << "\n";
			std::cout << key1 << "!" << "\n";
			std::cout << key2 << "!" << std::endl;

		}
	}
}


void main()
{
	//printInstructions();

	std::unordered_map<std::string, std::string> elementsList;

	std::ifstream elements("elements.dat");
	//STRING DONDE GUARDAREMOS CADA LINEA PARA DESPUES UTILZARLA
	std::string line;


	
		size_t equalPosition;
		size_t plusPosition;
		int sizeKey1;
		std::string key1;
		std::string key2;
		std::string keyTotal;
		std::string value;

		for (int i = 0; i < 10; i++)
		{
			getline(elements, line);
			equalPosition = line.find("=");
			plusPosition = line.find('+');
			
			value = line.substr(0, equalPosition - 1);	
			key1 = line.substr(equalPosition + 2, plusPosition-2);
			key2 = line.substr(plusPosition + 2, line.size());
			

			std::cout << value << "!" << "\n";
			std::cout << key1 << "!" << "\n";
			std::cout << key2 << "!" << std::endl;
		}

}