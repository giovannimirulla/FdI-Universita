#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define NCOUPLE 10 //Numero massimo di coppie prese in considerazione

int main() {
FILE *inFile; //Dichiarazione dei file in ingresso
int  showNumber, couple = 0; //Dichiarazione delle variabili intere: numeri da mostrare e coppie
int vectorNumbers[NCOUPLE], firstNumber, secondNumber, sum=0; //Dichiarazione delle variabili float: array dei numeri, primo e secondo numero della coppia e somma
char fileName[100]; //Dichiarazione stringa che conterrà il nome del file di testo con un massimo di 100 caratteri

do { //Ciclo per la richiesta del nome del file di testo corretto
	printf("Inserire il nome del file di testo: "); //Richiesta all'utente
	scanf("%s", fileName); //Inizializzazione della varibile con il nome del file dato dall'utente
	if (!strstr(fileName, ".txt")) strcat(fileName, ".txt"); //Inserimento del tipo di file nella stringa se non è stato specificato
	inFile = fopen(fileName, "r"); //Inizializzazione del file di ingresso aprendolo in modalità di sola lettura
	if (inFile == NULL) printf("Il file non esiste\n"); //Se il file risulta essere nulla viene avvisato l'utente
} while (inFile == NULL); //Condizione di uscita, il file deve esistere

while (couple < NCOUPLE && !feof(inFile)) { //Ciclo per il conteggio delle coppie e delle medie presenti sul file con condizione di un massimo di 10 coppie prima della fine del file
	if (fscanf(inFile, "%d%d", &firstNumber, &secondNumber) == EOF && couple == 0) { //Controllo se il file risulta essere vuoto associando i valori alle variabili float
		printf("Il file e' vuoto\n"); //Avviso l'utente se il file è vuoto
		return 1; //Termino il programma con errore
	}
	if (firstNumber<secondNumber) vectorNumbers[couple] = firstNumber; //Se il primo numero è minore del secondo viene salvato sull'array
	else vectorNumbers[couple] = secondNumber; //Viceversa
	couple++; //Aggiorno il numero di coppie
}
fclose(inFile); //Chiusura del file in ingresso

for(showNumber=0;showNumber<couple;showNumber++) { //Ciclo per mostrare i numeri nelle posizioni di spari e fare una somma totale
	if (showNumber == 0) printf("Ecco i numeri nelle posizioni dispari:\n"); //Aviso l'utente
    if (showNumber % 2 != 0) printf("%d\n", vectorNumbers[showNumber]); //Stampo i numeri
	sum = sum + vectorNumbers[showNumber]; //Sommo il numero al resto della somma
}

printf("La media e' pari a : %.1f\n", (float) sum / couple); //Stampo la media
return 0; //Concludo il programma
}