#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define NCOUPLE 10 //Numero massimo di coppie prese in considerazione

int main() {
FILE *inFile, *outFile; //Dichiarazione dei file in ingresso e uscita
int  showCouple, printCouple, couple=0, positionMax=0; //Dichiarazione delle variabili intere: numeri di coppie da mostrare e stampare, numero di coppie presenti nel file di ingresso, posizione nell'array dell'elemento massimo
float vectorAverage[NCOUPLE], firstNumber, secondNumber, min, max, maxOfAll=0; //Dichiarazione delle variabili float: array delle medie, primo e secondo numero della coppia, valore minimo e massimo dati dall'utente, valore massimo presente nell'array
char fileName[100]; //Dichiarazione stringa che conterrà il nome del file di testo con un massimo di 100 caratteri

 do { //Ciclo per la richiesta del nome del file di testo corretto
	printf("Inserire il nome del file di testo: "); //Richiesta all'utente
	scanf("%s", fileName); //Inizializzazione della varibile con il nome del file dato dall'utente
	if(!strstr(fileName,".txt")) strcat(fileName, ".txt"); //Inserimento del tipo di file nella stringa se non è stato specificato
	inFile = fopen(fileName, "r"); //Inizializzazione del file di ingresso aprendolo in modalità di sola lettura
	if (inFile == NULL) printf("Il file non esiste\n"); //Se il file risulta essere nulla viene avvisato l'utente
 } while (inFile == NULL); //Condizione di uscita, il file deve esistere

 while(couple < NCOUPLE && !feof(inFile)) { //Ciclo per il conteggio delle coppie e delle medie presenti sul file con condizione di un massimo di 10 coppie prima della fine del file
	 if (fscanf(inFile, "%f%f", &firstNumber, &secondNumber) == EOF && couple == 0) { //Controllo se il file risulta essere vuoto associando i valori alle variabili float
		 printf("Il file e' vuoto\n"); //Avviso l'utente se il file è vuoto
		 return 1; //Termino il programma con errore
	 }
	 vectorAverage[couple] = (firstNumber + secondNumber) / 2; //Viene associata la media tra i due numeri nella posizione corrente dell'array data dal ciclo
	 couple++; //Aggiorno il numero di coppie
 }
 fclose(inFile); //Chiusura del file in ingresso

 printf("Inserisci un valore minimo: "); //Richiesta del valore minimo
 scanf("%f", &min); //Inizializzazione della varibile con il valore minimo
 printf("Inserisci un valore massimo: "); //Richiesta del valore massimo
 scanf("%f", &max); //Inizializzazione della varibile con il valore massimo

 maxOfAll = vectorAverage[0]; //Associo il primo valore dell'array al valore massimo
 for (showCouple = 0; showCouple <= couple-1; showCouple++) { //Ciclo per mostrare i valori tra il minimo e il massimo e la ricerca del valore massimo nell'array
	 if (min <= vectorAverage[showCouple] && max >= vectorAverage[showCouple]) {
		 if(showCouple==0) printf("Ecco i valori compresi:\n"); //Avviso l'utente
		 printf("%.2f\n", vectorAverage[showCouple]); //Se il valore è compreso viene mostrato
	 }
	 if (vectorAverage[showCouple]>=maxOfAll) { //Se il valore è maggiore del numero conservato nella variabile
		 maxOfAll = vectorAverage[showCouple]; //Viene sostituito
		 positionMax = showCouple; //Viene assegnata la posizione del valore massimo nell'array
	 }
 }

 printf("Ecco il valore massimo trovato e la rispettiva posizione: %.2f %d\n", maxOfAll, positionMax); //Mostra il valore massimo e la rispettiva posizione
 
 outFile = fopen("uscita.txt", "w"); //Creazione o sostituzione del file in uscita in modalità scrittura
 for (printCouple = 0; printCouple <= couple-1; printCouple++) { //Ciclo per stampare su file tutte le medie trovate
	 fprintf(outFile, "%.2f\n", vectorAverage[printCouple]); //Stampa ogni variabile contenuta
 }
 return fclose(outFile); //Se la chiusurà del file in uscita avviene con successo il programma risulta essere privo di errori
}