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

//ENUM CLASS PARA EL CONTROL DE OPERACIONES
enum class Instructions{add,basics,remove,info,sort,clean,help };


//FUNCION QUE IMPRIME LAS INSTRUCCIONES
void printInstructions()
{
	std::cout << "//////////////////" << "\n"
			<< "TEAM ANCIA ALCHEMY\n" <<
			"//////////////////" << "\n" << "\n" <<
			"- Enter two number of your elemtns list to combine them.\n" <<
			"- Enter the word 'add' and a number of an element to add a new instance of that element\n" <<
			"- Enter 'add basics' to add new instances of the 4 basic elemtns.\n" <<
			"- Enter the word 'remove' and the number of an element to erase it from your list.\n" <<
			"- Enter the word 'info' and the number of an element to get the information about it in the explorer.\n" <<
			"- Enter the word 'sort' to sort by alphabetical order the elements in the list.\n" <<
			"- Enter the word 'clean' to delete all the instances of repeated elements.\n" <<
			"- Enter the word 'help' to show this tutorial." << std::endl;
}

Instructions castToEnum(std::string word)
{
	Instructions casted;
	if (word == "add")
		casted = Instructions::add;
	if (word == "basics")
		casted = Instructions::basics;
	if (word == "remove")
		casted = Instructions::remove;
	if (word == "info")
		casted = Instructions::info;
	if (word == "sort")
		casted = Instructions::sort;
	if (word == "clean")
		casted = Instructions::clean;
	if (word == "help")
		casted = Instructions::help;
	


		return casted;
};
//FUNCION QUE GUARDA TODA LA LISTA DE ELEMENTOS EN UN UNORDERED_MAP
/*
void fillListOfElements(std::unordered_map<std::string, std::string> elementsList)
{ 

	std::ifstream elements("elements.dat");
	//STRING DONDE GUARDAREMOS CADA LINEA PARA DESPUES UTILZARLA
	std::string line;

	
	//COMPROBAMOS SI EL ARCHIVO SE HA ABIERTO CORRECTAMENTE
	if (elements.is_open() == true)
	{
		size_t equalPosition;
		size_t plusPosition;
		int sizeKey1;
		std::string key1;
		std::string key2;
		std::string keyTotal;
		std::string value;
 
		//QUE VAYA LEYENDO MIENTRAS NO SE LLEGUE AL FINAL DEL ARCHIVO
		while (elements.eof() != true)
		{
			//LEEMOS UNA LINEA DEL ARCHIVO Y ENCONTRAMOS LAS POSICIONES 
			//DEL = Y EL + QUE ES LO QUE NOS SEPARA CADA ELEMENTO
			getline(elements, line);
			equalPosition = line.find("=");
			plusPosition = line.find('+');
			sizeKey1 = (plusPosition - equalPosition) - 3;
			//SEPARAMOS LA LINEA POR LOS SIMBOLOS ANTES DICHOS
			value = line.substr(0, equalPosition - 1);
			key1 = line.substr(equalPosition + 2, sizeKey1);
			key2 = line.substr(plusPosition + 2, line.size());
			//GENERAMOS LA KEY QUE SERA LOS DOS ELEMENTOS DE LA COMBINACION EN UN STRING
			keyTotal = key1 + key2;
			//LO GUARDAMOS EN NUESTRO UNORDERD_MAP
			elementsList.insert(keyTotal, value);
			


		}
	}
	else
	{
		system("pause");
	}

	elements.close();
}*/


void main()
{
	//printInstructions();

	std::unordered_map<std::string, std::string> elementsList;

	//fillListOfElements(elementsList);

	std::vector<std::string> gameList({ "Air","Earth","Fire","Water" });
	std::vector<std::string> scoreList(gameList);
	
	//VARIABLE QUE CONTROLA LA PUNTUACION
	int score = 0;
	//LA PRIMERA Y SEGUNDA PALABRA QUE NOS ESCRIBA EL USUARIO
	std::string firstWord;
	std::string secondWord;
	//EL ENUM CON EL QUE RECORREREMOS EL SWITCH 
	Instructions order;

	while (score <= 395)
	{
		//GUARDAMOS LOS COMANDOS ELEGIOS POR EL USUARIO
		std::cin >> firstWord >> secondWord;
		//PARA PODER HACER EL SWITCH HACEMOS UN CAST DE STRING A NUESTRO ENUM DE ORDENES
		//CON UNA FUNCION PREVIAMENT CREADA
		order = castToEnum(firstWord);

		switch (order)
		{
		case Instructions::add:
			
			break;
		case Instructions::remove:

			break;
		case Instructions::info:

			break;
		case Instructions::sort:

			break;
		case Instructions::clean:

			break;
		case Instructions::help:

			break;
		default:
			break;
		}
		std::cout << firstWord << " " << secondWord << std::endl;
		score++;

	}
 

}