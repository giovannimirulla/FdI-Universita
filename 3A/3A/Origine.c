#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define NSTR 10 //Numero massimo di stringhe prese in considerazione

int main() {
	FILE *inFile; //Dichiaro il file in ingresso
	char string[100]; //Dichiaro la variabile stringa con un massimo di 100 caratteri
	int vectorLen[NSTR],nStr = 0,maxLen, threshold,printLen=0, nullLen=0, thresholdLen=0; //Dichiaro le variabili intere: un array che conterrà le lunghezze, il numero di stringhe, la lunghezza massima, la soglia, le lunghezze da stampare, il numero di stringhe nulle e il numero di stringhe che superano la soglia
	
	inFile = fopen("ingresso.txt", "r"); //Inizializzazione del file di ingresso aprendolo in modalità di sola lettura
	if (inFile == NULL) { //Se il file non esiste
		printf("Il file non esiste\n"); //Avviso l'utente
		return 0; //Termino il programma
	}
	while (nStr < NSTR && !feof(inFile)) { //Ciclo per il conteggio del numero di stringhe sul file con condizione di un massimo di 10 coppie prima della fine del file
		if (fgets(string,100,inFile) == EOF && nStr == 0) { //Controllo se il file risulta essere vuoto associando i valori alle variabili float
			printf("Il file e' vuoto\n"); //Avviso l'utente se il file è vuoto
			return 1; //Termino il programma con errore
		}
		if (strstr(string, "\n"))vectorLen[nStr] = strlen(string)-1; //Viene associata la lunghezza priva del ritorno a capo nella posizione corrente dell'array data dal ciclo 
		else vectorLen[nStr] = strlen(string); //Viene associata la lunghezza nella posizione corrente dell'array data dal ciclo 
		nStr++; //Aggiorno il numero di stringhe
	}
	fclose(inFile); //Chiusura del file in ingresso

	printf("Inserisci un valore di soglia: "); //Chiedo all'utente il numero di soglia
	scanf("%d", &threshold); //Inizializzo la variabile

	maxLen = vectorLen[0]; //Inizializzo il valore massimo col primo numero incontrato
	for (printLen = 0; printLen <= nStr - 1; printLen++) { //Ciclo per la determinazione dei valori sopra la soglia e il calcolo della somma totale
		if (vectorLen[printLen] > threshold) thresholdLen++; //Aumento la varibile se incontro stringhe superiori alla soglia
		if (vectorLen[printLen] >= maxLen) maxLen = vectorLen[printLen]; //Aggiorno il massimo se rilevato
		if (vectorLen[printLen] == 0) nullLen++;//Aumento la variabile se rilevate stringhe nulle
	}
	printf("Ecco il numero di righe con lunghezza superiore: %d\nIl numero di le righe nulle: %d\nE la lunghezza massima: %d\n", thresholdLen, nullLen, maxLen); //Stampo il numero di stringhe superiori alla soglia, quelle nulle e la lunghezza massima
	return 0; //Concludo il programma
}
