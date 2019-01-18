#include "pch.h"
#include <iostream>
#include<time.h>
#include<vector>
std::vector<int> searchIslands(int *arr, int sizeOfArray);
std::vector<int> searchOneToZero(int *arr, int sizeOfArray);

int main()
{	
	srand(time(NULL));
	int sizeOfArr,i,oneMax;
	std::vector<int> numbOfIslands;//wektor jest praktyczniejszy, w przypadku gdy jest wiecej niz jedna najwieksza "wyspa"
	std::vector<int> oneToZero; //na wektrorze zapisane beda miejsca ostatnich jedynek na wyspie (chociaz tylko do wyswietlania tych indeksow nie jest potrzebny :) )

	//tworzenie dynamicznej tablicy 
	printf("podaj rozmiar tablicy ");
	std::cin >> sizeOfArr;
	if(sizeOfArr<0)
	{
		printf("liczba ponizej zera"); 
		return 0;
	}
	int * arr = new int[sizeOfArr];
	
	//wypelnianie randem
	for (i = 0; i < sizeOfArr; i++)
	{
		arr[i] = std::rand() % 2;
		//if (i % 10 == 0)
		//	printf("\n"); // ulatiwenie weryfikacji
		printf("%d ", arr[i]);
	}
	
	numbOfIslands = searchIslands(arr, sizeOfArr);
	oneMax = numbOfIslands.back();
	numbOfIslands.pop_back();

	printf("\nnajwieksza 'wyspa' ma rozmiar %d,\nilosc w tablicy: %d\nmaja one indeksy: \n",oneMax,numbOfIslands.size());
	for (std::vector<int>::iterator it = numbOfIslands.begin(); it != numbOfIslands.end(); ++it)
		printf("od %d do %d\n", *it-oneMax+1, *it);

	oneToZero = searchOneToZero(arr, sizeOfArr);

	printf("\n\n indeksowanie tablic od 0\n");
	system("PAUSE");
	delete[] arr;
	return 0;
}


std::vector<int> searchIslands(int * arr, int sizeOfArray) //wyszukiwanie najwiekszej wyspy
{
	std::vector<int> numbOfIslands;
	int oneMax = 0, counter = 0,i; //oneMax - aktualnie najwiekszy rozmiar wyspy
	for (i = 0; i < sizeOfArray; i++)
	{
		if (arr[i] == 1)
		{
			counter++;
		}
		else
		{
			counter = 0;
		}
		if (counter == oneMax)
		{
			numbOfIslands.push_back(i);
		}

		if (counter > oneMax)
		{
			numbOfIslands.clear();
			numbOfIslands.push_back(i);
			oneMax = counter;
		}
	}
	numbOfIslands.push_back(oneMax); //zapisanie rozmiaru najwiekszej wyspy jako ostatniego elementu w wektorze
	if (oneMax == 0)
	{
		printf("\nnie ma zadnej 'wyspy' w tej tablicy");
		exit(1);
	}
	return numbOfIslands;
}

std::vector<int> searchOneToZero(int * arr, int sizeOfArray) //wyszukiwanie przejsc jedynek w zera
{
	std::vector<int> oneToZero;
	printf("\nmiejsca przejsc jedynek w zera: \n");
	for (int i = 0; i < sizeOfArray; i++)
	{
		if (arr[i] == 0) { continue; }
		while (arr[i] == 1)
		{
			if (i >= sizeOfArray - 1) return oneToZero;
			i++;
		}
		oneToZero.push_back(i - 1);
		printf("%d ", i - 1);
	}
	return oneToZero;
}
