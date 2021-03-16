#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define NDATA 10 //Numero massimo di dati presi in considerazione

int main() {
	FILE *inFile; //Dichiarazione del file in ingresso
	int  data = 0; //Inizializzazione della varibile per il ciclo per l'ottenimento dei dati
    char fileName[100]; //Dichiarazione stringa che conterrà il nome del file di testo con un massimo di 100 caratteri
	float maxOfIMC; //Dichiarazione della variabile float per il massimo IMC
	struct data { //Dichiarazione di una struttura contente altezza e peso
		float height; 
		float weight;
	};
	struct data dates[NDATA]; //Dichiarazione array contenente la coppia di dati

    do { //Ciclo per la richiesta del nome del file di testo corretto
	   printf("Inserire il nome del file di testo: "); //Richiesta all'utente
	   scanf("%s", fileName); //Inizializzazione della varibile con il nome del file dato dall'utente
	   if (!strstr(fileName, ".txt")) strcat(fileName, ".txt"); //Inserimento del tipo di file nella stringa se non è stato specificato
	   inFile = fopen(fileName, "r"); //Inizializzazione del file di ingresso aprendolo in modalità di sola lettura
	   if (inFile == NULL) printf("Il file non esiste\n"); //Se il file risulta essere nulla viene avvisato l'utente
    } while (inFile == NULL); //Condizione di uscita, il file deve esistere

    while (data < NDATA && !feof(inFile)) { //Ciclo per il conteggio delle coppie, degli individui normopeso e del massimo IMC presenti sul file con condizione di un massimo di 10 coppie prima della fine del file
	 if (fscanf(inFile, "%f%f", &dates[data].height, &dates[data].weight) == EOF && data == 0) { //Controllo se il file risulta essere vuoto associando i valori alle variabili float
		printf("Il file e' vuoto\n"); //Avviso l'utente se il file è vuoto
		return 1; //Termino il programma con errore
	 }
	 float IMC = dates[data].weight / (dates[data].height*dates[data].height); //Inizializzazione della variabile 
	 if (data == 0) { //Se è il primo dato ottenuto
		 printf("Ecco gli IMC degli individui normopeso:\n"); //Avviso l'utente
	      maxOfIMC = IMC; //Inizializzo la variabile 
	 }
	 if (IMC >= 18.5 && IMC <= 24.99) printf("%.2f\n", IMC); //Stampo gli IMC compresi nel range
	 if (IMC>maxOfIMC) { //Se il valore è maggiore del numero conservato nella variabile
		maxOfIMC = IMC; //Viene sostituito
	 }
	 data++; //Aggiorno il numero di dati ottenuti
   }
	printf("Ecco l'IMC piu' elevato: %.2f\n", maxOfIMC); //Mostra il valore massimo e la rispettiva posizione
  return fclose(inFile); //Termino il programma con risultato della chiusura del file in ingresso
}