#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define N 10 //Numero massimo di numeri presi in considerazione
int main() {
	FILE *inFile; //Dichiarazione del file in ingresso
	char fileName[100]; //Dichiarazione stringa che conterrà il nome del file di testo con un massimo di 100 caratteri
	int i=0, vectorNumbers[N], n, showN, minOfAll, positionMin; //

	do { //Ciclo per la richiesta del nome del file di testo corretto
		printf("Inserire il nome del file di testo: "); //Richiesta all'utente
		scanf("%s", fileName); //Inizializzazione della varibile con il nome del file dato dall'utente
		if (!strstr(fileName, ".txt")) strcat(fileName, ".txt"); //Inserimento del tipo di file nella stringa se non è stato specificato
		inFile = fopen(fileName, "r"); //Inizializzazione del file di ingresso aprendolo in modalità di sola lettura
		if (inFile == NULL) printf("Il file non esiste\n"); //Se il file risulta essere nulla viene avvisato l'utente
	} while (inFile == NULL); //Condizione di uscita, il file deve esistere

	while (i < N && !feof(inFile)) { //Ciclo per il conteggio delle coppie e delle medie presenti sul file con condzione di un massimo di 10 coppie prima della fine del file
		if (fscanf(inFile, "%d", &n) == EOF && i == 0) { //Controllo se il file risulta essere vuoto associando il valore alla rispettiva posizione nell'array
		    printf("Il file e' vuoto\n"); //Avviso l'utente se il file è vuoto
			return 1; //Termino il programma con errore
		}
		if (n % 2 != 0) { //Se il numero è dispari
			vectorNumbers[i] = n; //Associo il numero alla rispettiva posizione nell'array
		    i++; //Aggiorno il numero di numeri
		}
	}
	fclose(inFile); //Chiusura del file in ingresso

	minOfAll = vectorNumbers[0]; //Inizializzo la variabile col primo numero contenuto nell'array
	for(showN = i-1; showN >= 0; showN--) { //Avvio un ciclo per la determinazione dei numeri partendo dall'ultima posizione e per la determinazione del numero più piccolo
		if(showN == i - 1) printf("Ecco i numeri dispari in ordine inverso:\n"); //Avviso l'utente
		printf("%d\n", vectorNumbers[showN]); //Mostro i numeri
		if (vectorNumbers[showN] <= minOfAll) { //Se il valore è minore del numero conservato nella variabile
			minOfAll = vectorNumbers[showN]; //Viene sostituito
			positionMin = showN; //Viene assegnata la posizione del valore minimo nell'array
		}
	}
	printf("Ecco il valore minimo trovato e la rispettiva posizione: %d %d\n", minOfAll, positionMin); //Mostra il valore minimo e la rispettiva posizione
	return 0; //Termino il programma
}