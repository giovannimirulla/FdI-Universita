#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define NPEOPLE 10 //Numero massimo di persone prese in considerazione

int main() {
	FILE *inFile, *outFile; //Dichiaro il file in ingresso
	char name[100]; //Dichiaro la variabile stringa con un massimo di 100 caratteri
	float salary, sum=0,average; //Dichiaro la variabile stipendio, somma e media come float
	struct data { //Dichiarazione di una struttura contente nome e salario
		char name[100];
		float salary;
	};
	struct data dates[NPEOPLE]; //Dichiarazione array contenente la coppia di dati
	int nPeople = 0,nAverage,nSupAverage=0,printPeople; //Dichiarazione numero di persone, numero media, numero superiore alla media e il numero di persone da inserire nel file di uscita

	inFile = fopen("ingresso.txt", "r"); //Inizializzazione del file di ingresso aprendolo in modalità di sola lettura
	if (inFile == NULL) { //Se il file non esiste
		printf("Il file non esiste\n"); //Avviso l'utente
		return 0; //Termino il programma
	}
	while (nPeople < NPEOPLE && !feof(inFile)) { //Ciclo per il conteggio del numero di persone sul file con condizione di un massimo di 10 coppie prima della fine del file
		if (fscanf(inFile, "%s%f", &name, &salary) == EOF && nPeople == 0) { //Controllo se il file risulta essere vuoto associando i valori alle variabili 
			printf("Il file e' vuoto\n"); //Avviso l'utente se il file è vuoto
			return 1; //Termino il programma con errore
		}
		if(salary>1000) { //Se lo stipendio è superiore a 1000
			strcpy(dates[nPeople].name, name); //Copio il nome nell'array di strutture
			dates[nPeople].salary = salary;//Copio lo stipendio nell'array di strutture
			sum = sum + salary; //Sommo il salario alla somma
		    nPeople++; //Aggiorno il numero di stringhe
		}
	}
	fclose(inFile); //Chiusura del file in ingresso
	
	average = sum / nPeople; //Calcolo la media
	printf("Lo stipendio medio e' di: %.2f\n", average); //Stampo la media

	for (nAverage = 0; nAverage < nPeople; nAverage++){ //Ciclo per calcolare il numero di persone con uno stipendio superiore alla media
		if (dates[nAverage].salary > average) nSupAverage++; //Se superiore incremento la variabile
	}
	printf("Le persone con uno stipendio superiore alla media sono: %d\n", nSupAverage); //Stampo il numero di persone 

	outFile = fopen("uscita.txt", "w"); //Creazione o sostrituzione del file in uscita inizializzandolo in modalità scrittura
	for(printPeople=0;printPeople<nPeople;printPeople++) { //Ciclo per trarre i nomi e i rispettivi salari
		fprintf(outFile, "%s %.2f\n", dates[printPeople].name, dates[printPeople].salary); //Le variabile vengono inserite nel file
	}
	return fclose(outFile); //Il programma termina con l'esito della chiusura del file
}