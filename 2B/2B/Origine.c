#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define NCOUPLE 10 //Numero massimo di coppie prese in considerazion
int main() {
	FILE *inFile; //Dichiarazione dei file in ingress
	int  couple = 0, printCouple; //Dichiarazione delle variabili intere: numeri di coppie e coppie da stampare
	float vectorSum[NCOUPLE], firstNumber, secondNumber, threshold, totSum=0; //Dichiarazioni variabili float: array contente le somme, primo numero, secondo numero, soglia e somma totale
	char fileName[100]; //Dichiarazione stringa che conterrà il nome del file di testo con un massimo di 100 caratteri

	do { //Ciclo per la richiesta del nome del file di testo corretto
		printf("Inserire il nome del file di testo: "); //Richiesta all'utente
		scanf("%s", fileName); //Inizializzazione della varibile con il nome del file dato dall'utente
		if (!strstr(fileName, ".txt")) strcat(fileName, ".txt"); //Inserimento del tipo di file nella stringa se non è stato specificato
		inFile = fopen(fileName, "r"); //Inizializzazione del file di ingresso aprendolo in modalità di sola lettura
		if (inFile == NULL) printf("Il file non esiste\n"); //Se il file risulta essere nulla viene avvisato l'utente
	} while (inFile == NULL); //Condizione di uscita, il file deve esistere
	
	while (couple < NCOUPLE && !feof(inFile)) { //Ciclo per il conteggio delle coppie e delle medie presenti sul file con condizione di un massimo di 10 coppie prima della fine del file
		if (fscanf(inFile, "%f%f", &firstNumber, &secondNumber) == EOF && couple == 0) { //Controllo se il file risulta essere vuoto associando i valori alle variabili float
			printf("Il file e' vuoto\n"); //Avviso l'utente se il file è vuoto
			return 1; //Termino il programma con errore
		}
		vectorSum[couple] = firstNumber + secondNumber; //Viene associata la media tra i due numeri nella posizione corrente dell'array data dal ciclo
		couple++; //Aggiorno il numero di coppie
	}
	fclose(inFile); //Chiusura del file in ingresso

	printf("Inserisci un valore di soglia: "); //Chiedo all'utente il numero di soglia
	scanf("%f", &threshold); //Inizializzo la variabile

	for(printCouple=0;printCouple<=couple-1;printCouple++) { //Ciclo per la determinazione dei valori sopra la soglia e il calcolo della somma totale
		if (printCouple == 0) printf("Ecco i valori sopra la soglia:\n"); //Avviso l'utente
		if (vectorSum[printCouple] >= threshold) printf("%.2f\n", vectorSum[printCouple]); //Stampo i valori sopra la soglia
		totSum = totSum + vectorSum[printCouple]; //Sommo la variabile al resto
	}
	printf("Ecco la somma totale: %.2f\n", totSum); //Stampo la somma totale
	return 0; //Concludo il programma
}
