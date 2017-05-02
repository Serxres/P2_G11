#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <windows.h>

template<>
struct std::hash<std::pair<std::string, std::string>>
{
	size_t operator()(const std::pair<std::string, std::string> &p) const
	{

		return ((hash<std::string>()(p.first)
			^ (hash<std::string>()(p.second) << 1)) >> 1);
	}
};


//STRUCT QUE NOS SERVIRA PARA CREAR LAS KEYS DEL UNORDERED_MAP
struct combinations
{
	std::string first;
	std::string second;
};

//ENUM CLASS PARA EL CONTROL DE OPERACIONES
enum class Instructions{add,
						basics,
						remove,
						info,
						sort,
						clean,
						help };


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
			"- Enter the words 'sort list' to sort by alphabetical order the elements in the list.\n" <<
			"- Enter the words 'clean list' to delete all the instances of repeated elements.\n" <<
			"- Enter the words 'help me' to show this tutorial." << std::endl;
}

//FUNCION QUE CASTEA DE STRING A ENUM PARA PODER HACER EL SWITCH(CAMBIO A INT PORQUE DABA PROBLEMAS EN EL CAST CON EL ENUM)
int castToEnum(std::string word)
{
	int casted = 999;
	if (word == "add")
		casted = 0;
	if (word == "basics")
		casted = 1;
	if (word == "remove")
		casted = 2;
	if (word == "info")
		casted = 3;
	if (word == "sort")
		casted = 4;
	if (word == "clean")
		casted = 5;
	if (word == "help")
		casted = 6;
	


		return casted;
};

//FUNCION QUE GUARDA TODA LA LISTA DE ELEMENTOS EN UN UNORDERED_MAP
void fillListOfElements(std::unordered_map<std::pair <std::string, std::string>, std::string> &elementsList)
{ 

	std::ifstream elements("elements.dat");
	//STRING DONDE GUARDAREMOS CADA LINEA PARA DESPUES UTILZARLA
	std::string line;

	
	//COMPROBAMOS SI EL ARCHIVO SE HA ABIERTO CORRECTAMENTE
	if (elements.is_open() )
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
			//SEPARAMOS LA LINEA POR LOS SIMBOLOS ANTES NOMBRADOS
			value = line.substr(0, equalPosition - 1);
			key1 = line.substr(equalPosition + 2, sizeKey1);
			key2 = line.substr(plusPosition + 2, line.size());
			//GENERAMOS LA KEY QUE SERA LOS DOS ELEMENTOS DE LA COMBINACION EN UN STRING
			keyTotal = key1 + key2;
			//LO GUARDAMOS EN NUESTRO UNORDERD_MAP
			std::pair<std::string, std::string> myKey (key1, key2);
			elementsList.insert({myKey,value});
			
		}
	}
	else
	{
		system("pause");
	}

	elements.close();
}


void main()
{
	
	printInstructions();

	std::unordered_map<std::pair <std::string,std::string>, std::string> elementsList;

	fillListOfElements(elementsList);
	
	

	
	//std::cout<< elementsList[myAuxKey] <<std::endl;


	std::vector<std::string> gameList({ "Air","Earth","Fire","Water" });
	//ES DONDE NOS GUARDAMOS LOS LOGROS DEL JUGADOR
	std::vector<std::string> scoreList(gameList);
	std::vector<std::string> auxList(390);
	

	//VARIABLE QUE CONTROLA LA PUNTUACION
	int score = 0;
	//LA PRIMERA Y SEGUNDA PALABRA QUE NOS ESCRIBA EL USUARIO
	std::string firstWord;
	std::string secondWord;
	//EL ENUM CON EL QUE RECORREREMOS EL SWITCH 
	int order;

	while (score <= 395)
	{
		std::cout << "SCORE: " << score << "\n" << std::endl;
		//IMPRIMIMOS LA LISTA QUE TIENE EL JUGADOR CON LOS ELEMENTOS
		//(LA DE JUEGO NO LA QUE TIENE TODOS LOS QUE HA CONSEGUIDO)
		for (int i = 0; i < gameList.size(); i++)
		{
			std::cout << i + 1 << ". " << gameList[i] << std::endl;
		}
		
		//GUARDAMOS LOS COMANDOS ELEGIOS POR EL USUARIO
		std::cin >> firstWord >> secondWord;

		//NOS LO DA EL ENUNCIADO PARA LIMPIAR Y EVITAR POSIBLES ERRORES
		std::cin.clear(); // clears all error state flags						  
		std::cin.ignore(std::cin.rdbuf()->in_avail());// extracts characters from the input buffer and discards them


		//PARA PODER HACER EL SWITCH HACEMOS UN CAST DE STRING A NUESTRO ENUM DE ORDENES
		//CON UNA FUNCION PREVIAMENT CREADA(CAMBIO A INT PORQUE DABA PROBLEMAS EN EL CAST CON EL ENUM)
		order = castToEnum(firstWord);
		int number;
		int number2;
		std::string firstKey;
		std::string secondKey;

		
		switch (order)
		{
				//ADD
				case 0:
					//LIMPIAMOS LA PANTALLA PORQUE HABRÁ ALGUN CAMBIO
					system("cls");

					if (secondWord == "basics")
					{
						gameList.push_back(scoreList[0]);
						gameList.push_back(scoreList[1]);
						gameList.push_back(scoreList[2]);
						gameList.push_back(scoreList[3]);
						
					}
					else
					{
				
						number = atoi(secondWord.c_str());
						gameList.push_back(gameList[number-1]);
					}
					break;

				//REMOVE
				case 2:
					//LIMPIAMOS LA PANTALLA PORQUE HABRÁ ALGUN CAMBIO
					system("cls");

					number = atoi(secondWord.c_str());
					gameList.erase(gameList.begin()+(number-1));			
					break;

				//INFO
				case 3: {

					//LIMPIAMOS LA PANTALLA PORQUE HABRÁ ALGUN CAMBIO
					system("cls");

					//CONVERTIMOS EL NUMERO DE STRING A INT PARA PODER ACCEDER AL UNORERED_MAP 
					//E IR A BUSCAR EL ELEMENTO EN STRING Y AÑADIRLO A LA URL
					number = atoi(secondWord.c_str());
					std::string reference = gameList[number - 1];

					//TENEMOS LA URL BASICA Y LE AÑADIMOS LA PALABRA EL ELMEMENTO DEL QUE QUEREMOS SABER INFORMACION
					std::string urlBase = "https://en.wikipedia.org/wiki/";
					std::string finalUrl = urlBase + reference;

					//AQUI CON ESTA FUNCION DADA EN EL ENUNCIADO ABRIMOS EL EXPLORADOR POR LA PAGINA DEL ELEMENTO
					ShellExecuteA(nullptr, "open", finalUrl.c_str(), nullptr, nullptr, SW_SHOWNORMAL);
					break;
				}
				//SORT
				case 4: {
					//LIMPIAMOS LA PANTALLA PORQUE HABRÁ ALGUN CAMBIO
					system("cls");
					
					std::sort(gameList.begin(), gameList.end());
					/*gameList.clear();
					for (int i = 0; i < auxList.size(); i++)
					{
						gameList[i] = auxList[i];
					}*/
					break;

				}
				//CLEAN
				case 5: {
					//LIMPIAMOS LA PANTALLA PORQUE HABRÁ ALGUN CAMBIO
					system("cls");
					bool equal = false;
					int counter;
					do {
						counter = 0;
						for (int i = 0; i < gameList.size(); i++)
						{
							for (int j = i + 1; j < gameList.size(); j++)
							{

								if (gameList[i] == gameList[j])
								{
									gameList.erase(gameList.begin() + j);
									counter++;
									if (j + 1 >= gameList.size())
									{
										break;
									}
								}
								if (i + 1 >= gameList.size())
								{
									break;
								}

							}
						}
					}while(counter != 0);
					break;

				}

				//HELP
				case 6:
					//LIMPIAMOS LA PANTALLA PORQUE HABRÁ ALGUN CAMBIO
					system("cls");
					printInstructions();
					std::cout << firstWord << std::endl;
					break;

				//POR DEFECTO EN ESTE CASO SERA CUANDO EL USUARIO NOS DE DOS ELEMENTOS QUE COMBINAR
				default:
					//LIMPIAMOS LA PANTALLA PORQUE HABRÁ ALGUN CAMBIO
					system("cls");
					if (firstWord == secondWord)
					{
						break;
					}
					number = atoi(firstWord.c_str());
					number2 = atoi(secondWord.c_str());
					firstKey = gameList[number - 1];
					secondKey = gameList[number2 - 1];
					
					std::pair<std::string, std::string> myAuxKey(firstKey, secondKey);
					if (elementsList.count(myAuxKey) == 1)
					{
						gameList.push_back(elementsList[myAuxKey]);

						int counter = 0;
						for (int i = 0; i < scoreList.size(); i++)
							{
								if (scoreList[i] == elementsList[myAuxKey])
								{
									counter++;
									break;
								}
							}

						if (counter == 0)
						{
							scoreList.push_back(elementsList[myAuxKey]);
							score++;
						}
						
					}
					else if (elementsList.count(myAuxKey) == 0)
					{
						std::pair<std::string, std::string> myAuxKey(secondKey, firstKey);
						if (elementsList.count(myAuxKey) == 1)
						{
							gameList.push_back(elementsList[myAuxKey]);

							int counter = 0;
							for (int i = 0; i < scoreList.size(); i++)
							{
								if (scoreList[i] == elementsList[myAuxKey])
								{
									counter++;
									break;
								}
							}

							if (counter == 0)
							{
								scoreList.push_back(elementsList[myAuxKey]);
								score++;
							}

						}
					}
					break;
		}		
	}
}