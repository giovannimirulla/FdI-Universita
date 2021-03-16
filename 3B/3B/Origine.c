#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define N 10 //Numero massimo di numeri presi in considerazione

int main() {
	FILE *inFile; //Dichiarazione fil e in ingresso
	int n = 0, printNumbers, positionMax; //Inizializzazione variabile numeri, dichiarazione dei numeri da stampare e della posizione massima
	float numbers[N], number, maxOfAll; //Inizializazzioni variabili float: array che conterrà i numeri, la variabile per ogni singolo numero e il numero massimo
	char fileName[100]; //Dichiarazione stringa che conterrà il nome del file di testo con un massimo di 100 caratteri

	do { //Ciclo per la richiesta del nome del file di testo corretto
		printf("Inserire il nome del file di testo: "); //Richiesta all'utente
		scanf("%s", fileName); //Inizializzazione della varibile con il nome del file dato dall'utente
		if (!strstr(fileName, ".txt")) strcat(fileName, ".txt"); //Inserimento del tipo di file nella stringa se non è stato specificato
		inFile = fopen(fileName, "r"); //Inizializzazione del file di ingresso aprendolo in modalità di sola lettura
		if (inFile == NULL) printf("Il file non esiste\n"); //Se il file risulta essere nulla viene avvisato l'utente
	} while (inFile == NULL); //Condizione di uscita, il file deve esistere

	while (n < N && !feof(inFile)) { //Ciclo per il conteggio dei numeri presenti sul file con condizione di un massimo di 10 numeri prima della fine del file
		if (fscanf(inFile, "%f", &number) == EOF && n == 0) { //Controllo se il file risulta essere vuoto associando i valori alle variabili float
			printf("Il file e' vuoto\n"); //Avviso l'utente se il file è vuoto
			return 1; //Termino il programma con errore
		}
		if(number>0) { //Se il numero è maggiori di 0
			numbers[n] = number; //aggiugo il numero nell'array
		    n++; //Aggiorno il numero di numeri
		}
	}
	fclose(inFile); //Chiusura del file in ingresso

	maxOfAll = numbers[0]; //Inizializzo la variabile col primo numero contenuto nell'array
	for(printNumbers = 0; printNumbers<= n; printNumbers ++) { //Ciclo per trovare i numeri nelle posizioni pari e il numero massimo e la rispettiva posizione
		if (printNumbers == 0) printf("Ecco i valori del vettore con indice pari:\n"); //Avviso l'utente 
		if (printNumbers%2 == 0) printf("%.2f\n", numbers[printNumbers]); //Stampo il numero
		if (numbers[printNumbers] >= maxOfAll) { //Se il valore è maggiore del numero conservato nella variabile
			maxOfAll = numbers[printNumbers]; //Viene sostituito
			positionMax = printNumbers; //Viene assegnata la posizione del valore massimo nell'array
		}
	}
	printf("Ecco il valore massimo trovato e la rispettiva posizione: %d %d\n", maxOfAll, positionMax); //Mostra il valore massimo e la rispettiva posizione
	return 0; //Termino il programma
}