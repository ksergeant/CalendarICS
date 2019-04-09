//
//  main.cpp
//  CalendarICS
//
//  Created by Kevin on 09/04/2019.
//  Copyright © 2019 Moks. All rights reserved.
//

#include <iostream>
#include <ctime>
#include <time.h>
#include <stdio.h>
#include <string>
#include <vector>
#include <fstream>


using namespace std;



struct data { // structure data
    string debutEvent = "BEGIN:VEVENT";
    string dateDebut= "DTSTART:";
    string dateFin = "DTEND:";
    string heureDebut= "T";
    string heureFin= "T";
    string lieu = "LOCATION:Oxya";
    string vacation = "SUMMARY:";
    string jour;
    string finEvent = "END:VEVENT";
    
};



int main(int argc, const char * argv[]) {
    
    // initialisation des variables
    string const nomFichierAprem="/Users/Kevin/Desktop/Programmation/C++/Planning/Planning/Planning/Aprem.ics";
    string const nomFichierMatin="/Users/Kevin/Desktop/Programmation/C++/Planning/Planning/Planning/Matin.ics";
    string const nomFichierNuit="/Users/Kevin/Desktop/Programmation/C++/Planning/Planning/Planning/Nuit.ics";
    int nombreElement = 0;
    
    vector<data> Tabdata;
    const char * NomJourSemaine[] = {"Dim", "Lun", "Mar", "Mer", "Jeu", "Ven", "Sam"};
    const char * NomMois[] = {"Jan", "Fev", "Mar", "Avr", "Mai", "Jui", "Juy", "Aou", "Sep", "Oct", "Nov", "Dec"};
    int compteurJourVac = 1;
    char format[128];
    time_t timestamp;
    time_t start = 1510272000; // le 10/11/2017 nombre de secondes
    struct tm * t;
    long int decal = 86400;
    timestamp = start;
    t = localtime(&timestamp);
    
    cout << "       @@@@@ Planning 1.0 By MOKS @@@@@" <<endl<<endl;
    
    // Phrase de départ pour le commencement des calculs dans le temps
    
    cout << "\n### Lancement du calcul des dates\n"<<endl;
    printf("Nous sommes %s,  ", NomJourSemaine[t->tm_wday]);
    printf("le %02u %s %04u,  ", t->tm_mday, NomMois[t->tm_mon], 1900 + t->tm_year); // départ le 10 novembre 2017
    cout << "Start" <<endl<<endl;
    
    ofstream monFluxAprem(nomFichierAprem.c_str(),ios::out | ios::trunc ); // écriture et vide le ficiher
    ofstream monFluxMatin(nomFichierMatin.c_str(),ios::out | ios::trunc );
    ofstream monFluxNuit(nomFichierNuit.c_str(),ios::out | ios::trunc );
    
    
    if(monFluxAprem){cout <<"Ficiher Aprem Ouvert" <<endl;}
    else{cout << "ERREUR: Impossible d'ouvrir le fichier Aprem." << endl;}
    if(monFluxMatin){cout <<"Ficiher Aprem Ouvert" <<endl;}
    else{cout << "ERREUR: Impossible d'ouvrir le fichier Aprem." << endl;}
    if(monFluxNuit){cout <<"Ficiher Aprem Ouvert" <<endl;}
    else{cout << "ERREUR: Impossible d'ouvrir le fichier Aprem." << endl;}
    
    // entete du fichier ICS Aprem
    monFluxAprem<<"BEGIN:VCALENDAR"<<endl;
    monFluxAprem<<"VERSION:2.0"<<endl;
    monFluxAprem<<"PRODID:KS"<<endl;
    
    // entete du fichier ICS Matin
    monFluxMatin<<"BEGIN:VCALENDAR"<<endl;
    monFluxMatin<<"VERSION:2.0"<<endl;
    monFluxMatin<<"PRODID:KS"<<endl;
    
    // entete du fichier ICS Nuit
    monFluxNuit<<"BEGIN:VCALENDAR"<<endl;
    monFluxNuit<<"VERSION:2.0"<<endl;
    monFluxNuit<<"PRODID:KS"<<endl;
    
    int nombreDeJours=1800;
    
    // Boucle qui calcule les jours sur les 5 prochaines années (84 cas possibles)
    for(int i = 0; i<nombreDeJours; i++){
        
        timestamp = start+decal;
        t = localtime(&timestamp);
        
        if (compteurJourVac>84)
        {
            compteurJourVac = 1;
        }
        
        struct data dataX;
        // switch des 84 possibilitées
        switch (compteurJourVac) {
                
            case 1:
                strftime(format, 128, "%Y%m%d", t); // format de date utilisable pour ficiher ICS
                
                dataX.vacation = dataX.vacation + "Après-midi";
                
                dataX.heureDebut = dataX.heureDebut + "143000";
                dataX.heureFin= dataX.heureFin + "223000";
                
                dataX.dateDebut = dataX.dateDebut + format + dataX.heureDebut;
                dataX.dateFin = dataX.dateFin + format + dataX.heureFin;
                dataX.jour = NomJourSemaine[t->tm_wday];
                Tabdata.push_back(dataX);
                
                // Ecriture dans le ficiher Aprem
                monFluxAprem << dataX.debutEvent <<endl;
                monFluxAprem << dataX.dateDebut <<endl;
                monFluxAprem << dataX.dateFin <<endl;
                monFluxAprem << dataX.lieu <<endl;
                monFluxAprem << dataX.vacation <<endl;
                monFluxAprem << dataX.finEvent <<endl;
                
                break;//debut vac aprem
                
            case 2:
                strftime(format, 128, "%Y%m%d", t); // format de date utilisable pour ficiher ICS
                
                dataX.vacation = dataX.vacation + "Après-midi";
                
                dataX.heureDebut = dataX.heureDebut + "143000";
                dataX.heureFin= dataX.heureFin + "223000";
                
                dataX.dateDebut = dataX.dateDebut + format + dataX.heureDebut;
                dataX.dateFin = dataX.dateFin + format + dataX.heureFin;
                dataX.jour = NomJourSemaine[t->tm_wday];
                Tabdata.push_back(dataX);
                
                monFluxAprem << dataX.debutEvent <<endl;
                monFluxAprem << dataX.dateDebut <<endl;
                monFluxAprem << dataX.dateFin <<endl;
                monFluxAprem << dataX.lieu <<endl;
                monFluxAprem << dataX.vacation <<endl;
                monFluxAprem << dataX.finEvent <<endl;
                break;
                
            case 3:
                strftime(format, 128, "%Y%m%d", t); // format de date utilisable pour ficiher ICS
                
                dataX.vacation = dataX.vacation + "Après-midi";
                
                dataX.heureDebut = dataX.heureDebut + "143000";
                dataX.heureFin= dataX.heureFin + "223000";
                
                dataX.dateDebut = dataX.dateDebut + format + dataX.heureDebut;
                dataX.dateFin = dataX.dateFin + format + dataX.heureFin;
                dataX.jour = NomJourSemaine[t->tm_wday];
                Tabdata.push_back(dataX);
                
                monFluxAprem << dataX.debutEvent <<endl;
                monFluxAprem << dataX.dateDebut <<endl;
                monFluxAprem << dataX.dateFin <<endl;
                monFluxAprem << dataX.lieu <<endl;
                monFluxAprem << dataX.vacation <<endl;
                monFluxAprem << dataX.finEvent <<endl;
                break;
                
            case 4:
                strftime(format, 128, "%Y%m%d", t); // format de date utilisable pour ficiher ICS
                
                dataX.vacation = dataX.vacation + "Après-midi";
                
                dataX.heureDebut = dataX.heureDebut + "143000";
                dataX.heureFin= dataX.heureFin + "223000";
                
                dataX.dateDebut = dataX.dateDebut + format + dataX.heureDebut;
                dataX.dateFin = dataX.dateFin + format + dataX.heureFin;
                dataX.jour = NomJourSemaine[t->tm_wday];
                Tabdata.push_back(dataX);
                
                monFluxAprem << dataX.debutEvent <<endl;
                monFluxAprem << dataX.dateDebut <<endl;
                monFluxAprem << dataX.dateFin <<endl;
                monFluxAprem << dataX.lieu <<endl;
                monFluxAprem << dataX.vacation <<endl;
                monFluxAprem << dataX.finEvent <<endl;
                break;
                
            case 5:break;//Repos
            case 6:break;
            case 7:break;
            case 8:break;
            case 9:break;
                
            case 10:
                strftime(format, 128, "%Y%m%d", t); // format de date utilisable pour ficiher ICS
                
                dataX.vacation = dataX.vacation + "Après-midi";
                
                dataX.heureDebut = dataX.heureDebut + "143000";
                dataX.heureFin= dataX.heureFin + "223000";
                
                dataX.dateDebut = dataX.dateDebut + format + dataX.heureDebut;
                dataX.dateFin = dataX.dateFin + format + dataX.heureFin;
                dataX.jour = NomJourSemaine[t->tm_wday];
                Tabdata.push_back(dataX);
                
                monFluxAprem << dataX.debutEvent <<endl;
                monFluxAprem << dataX.dateDebut <<endl;
                monFluxAprem << dataX.dateFin <<endl;
                monFluxAprem << dataX.lieu <<endl;
                monFluxAprem << dataX.vacation <<endl;
                monFluxAprem << dataX.finEvent <<endl;
                break;
                
            case 11:
                strftime(format, 128, "%Y%m%d", t); // format de date utilisable pour ficiher ICS
                
                dataX.vacation = dataX.vacation + "Après-midi";
                
                dataX.heureDebut = dataX.heureDebut + "143000";
                dataX.heureFin= dataX.heureFin + "223000";
                
                dataX.dateDebut = dataX.dateDebut + format + dataX.heureDebut;
                dataX.dateFin = dataX.dateFin + format + dataX.heureFin;
                dataX.jour = NomJourSemaine[t->tm_wday];
                Tabdata.push_back(dataX);
                
                monFluxAprem << dataX.debutEvent <<endl;
                monFluxAprem << dataX.dateDebut <<endl;
                monFluxAprem << dataX.dateFin <<endl;
                monFluxAprem << dataX.lieu <<endl;
                monFluxAprem << dataX.vacation <<endl;
                monFluxAprem << dataX.finEvent <<endl;
                break;
                
            case 12:
                strftime(format, 128, "%Y%m%d", t); // format de date utilisable pour ficiher ICS
                
                dataX.vacation = dataX.vacation + "Après-midi";
                
                dataX.heureDebut = dataX.heureDebut + "143000";
                dataX.heureFin= dataX.heureFin + "223000";
                
                dataX.dateDebut = dataX.dateDebut + format + dataX.heureDebut;
                dataX.dateFin = dataX.dateFin + format + dataX.heureFin;
                dataX.jour = NomJourSemaine[t->tm_wday];
                Tabdata.push_back(dataX);
                
                monFluxAprem << dataX.debutEvent <<endl;
                monFluxAprem << dataX.dateDebut <<endl;
                monFluxAprem << dataX.dateFin <<endl;
                monFluxAprem << dataX.lieu <<endl;
                monFluxAprem << dataX.vacation <<endl;
                monFluxAprem << dataX.finEvent <<endl;
                break;
                
            case 13:
                strftime(format, 128, "%Y%m%d", t); // format de date utilisable pour ficiher ICS
                
                dataX.vacation = dataX.vacation + "Après-midi";
                
                dataX.heureDebut = dataX.heureDebut + "143000";
                dataX.heureFin= dataX.heureFin + "223000";
                
                dataX.dateDebut = dataX.dateDebut + format + dataX.heureDebut;
                dataX.dateFin = dataX.dateFin + format + dataX.heureFin;
                dataX.jour = NomJourSemaine[t->tm_wday];
                Tabdata.push_back(dataX);
                
                monFluxAprem << dataX.debutEvent <<endl;
                monFluxAprem << dataX.dateDebut <<endl;
                monFluxAprem << dataX.dateFin <<endl;
                monFluxAprem << dataX.lieu <<endl;
                monFluxAprem << dataX.vacation <<endl;
                monFluxAprem << dataX.finEvent <<endl;
                break;
                
            case 14:
                strftime(format, 128, "%Y%m%d", t); // format de date utilisable pour ficiher ICS
                
                dataX.vacation = dataX.vacation + "Après-midi";
                
                dataX.heureDebut = dataX.heureDebut + "143000";
                dataX.heureFin= dataX.heureFin + "223000";
                
                dataX.dateDebut = dataX.dateDebut + format + dataX.heureDebut;
                dataX.dateFin = dataX.dateFin + format + dataX.heureFin;
                dataX.jour = NomJourSemaine[t->tm_wday];
                Tabdata.push_back(dataX);
                
                monFluxAprem << dataX.debutEvent <<endl;
                monFluxAprem << dataX.dateDebut <<endl;
                monFluxAprem << dataX.dateFin <<endl;
                monFluxAprem << dataX.lieu <<endl;
                monFluxAprem << dataX.vacation <<endl;
                monFluxAprem << dataX.finEvent <<endl;
                break;
                
            case 15:break;//Repos
            case 16:break;
            case 17:break;
            case 18:break;
                
            case 19:
                strftime(format, 128, "%Y%m%d", t); // format de date utilisable pour ficiher ICS
                
                dataX.vacation = dataX.vacation + "Après-midi";
                
                dataX.heureDebut = dataX.heureDebut + "143000";
                dataX.heureFin= dataX.heureFin + "223000";
                
                dataX.dateDebut = dataX.dateDebut + format + dataX.heureDebut;
                dataX.dateFin = dataX.dateFin + format + dataX.heureFin;
                dataX.jour = NomJourSemaine[t->tm_wday];
                Tabdata.push_back(dataX);
                
                monFluxAprem << dataX.debutEvent <<endl;
                monFluxAprem << dataX.dateDebut <<endl;
                monFluxAprem << dataX.dateFin <<endl;
                monFluxAprem << dataX.lieu <<endl;
                monFluxAprem << dataX.vacation <<endl;
                monFluxAprem << dataX.finEvent <<endl;
                break;
                
            case 20:
                strftime(format, 128, "%Y%m%d", t); // format de date utilisable pour ficiher ICS
                
                dataX.vacation = dataX.vacation + "Après-midi";
                
                dataX.heureDebut = dataX.heureDebut + "143000";
                dataX.heureFin= dataX.heureFin + "223000";
                
                dataX.dateDebut = dataX.dateDebut + format + dataX.heureDebut;
                dataX.dateFin = dataX.dateFin + format + dataX.heureFin;
                dataX.jour = NomJourSemaine[t->tm_wday];
                Tabdata.push_back(dataX);
                
                monFluxAprem << dataX.debutEvent <<endl;
                monFluxAprem << dataX.dateDebut <<endl;
                monFluxAprem << dataX.dateFin <<endl;
                monFluxAprem << dataX.lieu <<endl;
                monFluxAprem << dataX.vacation <<endl;
                monFluxAprem << dataX.finEvent <<endl;
                break;
                
            case 21:
                strftime(format, 128, "%Y%m%d", t); // format de date utilisable pour ficiher ICS
                
                dataX.vacation = dataX.vacation + "Après-midi";
                
                dataX.heureDebut = dataX.heureDebut + "143000";
                dataX.heureFin= dataX.heureFin + "223000";
                
                dataX.dateDebut = dataX.dateDebut + format + dataX.heureDebut;
                dataX.dateFin = dataX.dateFin + format + dataX.heureFin;
                dataX.jour = NomJourSemaine[t->tm_wday];
                Tabdata.push_back(dataX);
                
                monFluxAprem << dataX.debutEvent <<endl;
                monFluxAprem << dataX.dateDebut <<endl;
                monFluxAprem << dataX.dateFin <<endl;
                monFluxAprem << dataX.lieu <<endl;
                monFluxAprem << dataX.vacation <<endl;
                monFluxAprem << dataX.finEvent <<endl;
                break;
                
            case 22:
                strftime(format, 128, "%Y%m%d", t); // format de date utilisable pour ficiher ICS
                
                dataX.vacation = dataX.vacation + "Après-midi";
                
                dataX.heureDebut = dataX.heureDebut + "143000";
                dataX.heureFin= dataX.heureFin + "223000";
                
                dataX.dateDebut = dataX.dateDebut + format + dataX.heureDebut;
                dataX.dateFin = dataX.dateFin + format + dataX.heureFin;
                dataX.jour = NomJourSemaine[t->tm_wday];
                Tabdata.push_back(dataX);
                
                monFluxAprem << dataX.debutEvent <<endl;
                monFluxAprem << dataX.dateDebut <<endl;
                monFluxAprem << dataX.dateFin <<endl;
                monFluxAprem << dataX.lieu <<endl;
                monFluxAprem << dataX.vacation <<endl;
                monFluxAprem << dataX.finEvent <<endl;
                break;
                
            case 23:
                strftime(format, 128, "%Y%m%d", t); // format de date utilisable pour ficiher ICS
                
                dataX.vacation = dataX.vacation + "Après-midi";
                
                dataX.heureDebut = dataX.heureDebut + "143000";
                dataX.heureFin= dataX.heureFin + "223000";
                
                dataX.dateDebut = dataX.dateDebut + format + dataX.heureDebut;
                dataX.dateFin = dataX.dateFin + format + dataX.heureFin;
                dataX.jour = NomJourSemaine[t->tm_wday];
                Tabdata.push_back(dataX);
                
                monFluxAprem << dataX.debutEvent <<endl;
                monFluxAprem << dataX.dateDebut <<endl;
                monFluxAprem << dataX.dateFin <<endl;
                monFluxAprem << dataX.lieu <<endl;
                monFluxAprem << dataX.vacation <<endl;
                monFluxAprem << dataX.finEvent <<endl;
                break;
                
            case 24:break; // Repos
            case 25:break;
            case 26:break;
            case 27:break;
            case 28:break; //fin vac aprem
                
            case 29:
                strftime(format, 128, "%Y%m%d", t); // format de date utilisable pour ficiher ICS
                
                dataX.vacation = dataX.vacation + "Matin";
                
                dataX.heureDebut = dataX.heureDebut + "063000";
                dataX.heureFin= dataX.heureFin + "143000";
                
                dataX.dateDebut = dataX.dateDebut + format + dataX.heureDebut;
                dataX.dateFin = dataX.dateFin + format + dataX.heureFin;
                dataX.jour = NomJourSemaine[t->tm_wday];
                Tabdata.push_back(dataX);
                
                monFluxMatin << dataX.debutEvent <<endl;
                monFluxMatin << dataX.dateDebut <<endl;
                monFluxMatin << dataX.dateFin <<endl;
                monFluxMatin << dataX.lieu <<endl;
                monFluxMatin << dataX.vacation <<endl;
                monFluxMatin << dataX.finEvent <<endl;
                break; //debut vac matin
                
            case 30:
                strftime(format, 128, "%Y%m%d", t); // format de date utilisable pour ficiher ICS
                
                dataX.vacation = dataX.vacation + "Matin";
                
                dataX.heureDebut = dataX.heureDebut + "063000";
                dataX.heureFin= dataX.heureFin + "143000";
                
                dataX.dateDebut = dataX.dateDebut + format + dataX.heureDebut;
                dataX.dateFin = dataX.dateFin + format + dataX.heureFin;
                dataX.jour = NomJourSemaine[t->tm_wday];
                Tabdata.push_back(dataX);
                
                monFluxMatin << dataX.debutEvent <<endl;
                monFluxMatin << dataX.dateDebut <<endl;
                monFluxMatin << dataX.dateFin <<endl;
                monFluxMatin << dataX.lieu <<endl;
                monFluxMatin << dataX.vacation <<endl;
                monFluxMatin << dataX.finEvent <<endl;
                break;
                
            case 31:
                strftime(format, 128, "%Y%m%d", t); // format de date utilisable pour ficiher ICS
                
                dataX.vacation = dataX.vacation + "Matin";
                
                dataX.heureDebut = dataX.heureDebut + "063000";
                dataX.heureFin= dataX.heureFin + "143000";
                
                dataX.dateDebut = dataX.dateDebut + format + dataX.heureDebut;
                dataX.dateFin = dataX.dateFin + format + dataX.heureFin;
                dataX.jour = NomJourSemaine[t->tm_wday];
                Tabdata.push_back(dataX);
                
                monFluxMatin << dataX.debutEvent <<endl;
                monFluxMatin << dataX.dateDebut <<endl;
                monFluxMatin << dataX.dateFin <<endl;
                monFluxMatin << dataX.lieu <<endl;
                monFluxMatin << dataX.vacation <<endl;
                monFluxMatin << dataX.finEvent <<endl;
                break;
                
            case 32:
                strftime(format, 128, "%Y%m%d", t); // format de date utilisable pour ficiher ICS
                
                dataX.vacation = dataX.vacation + "Matin";
                
                dataX.heureDebut = dataX.heureDebut + "063000";
                dataX.heureFin= dataX.heureFin + "143000";
                
                dataX.dateDebut = dataX.dateDebut + format + dataX.heureDebut;
                dataX.dateFin = dataX.dateFin + format + dataX.heureFin;
                dataX.jour = NomJourSemaine[t->tm_wday];
                Tabdata.push_back(dataX);
                
                monFluxMatin << dataX.debutEvent <<endl;
                monFluxMatin << dataX.dateDebut <<endl;
                monFluxMatin << dataX.dateFin <<endl;
                monFluxMatin << dataX.lieu <<endl;
                monFluxMatin << dataX.vacation <<endl;
                monFluxMatin << dataX.finEvent <<endl;
                break;
                
            case 33:break;// Repos
            case 34:break;
            case 35:break;
            case 36:break;
            case 37:break;
                
            case 38:
                strftime(format, 128, "%Y%m%d", t); // format de date utilisable pour ficiher ICS
                
                dataX.vacation = dataX.vacation + "Matin";
                
                dataX.heureDebut = dataX.heureDebut + "063000";
                dataX.heureFin= dataX.heureFin + "143000";
                
                dataX.dateDebut = dataX.dateDebut + format + dataX.heureDebut;
                dataX.dateFin = dataX.dateFin + format + dataX.heureFin;
                dataX.jour = NomJourSemaine[t->tm_wday];
                Tabdata.push_back(dataX);
                
                monFluxMatin << dataX.debutEvent <<endl;
                monFluxMatin << dataX.dateDebut <<endl;
                monFluxMatin << dataX.dateFin <<endl;
                monFluxMatin << dataX.lieu <<endl;
                monFluxMatin << dataX.vacation <<endl;
                monFluxMatin << dataX.finEvent <<endl;
                break;
                
            case 39:
                strftime(format, 128, "%Y%m%d", t); // format de date utilisable pour ficiher ICS
                
                dataX.vacation = dataX.vacation + "Matin";
                
                dataX.heureDebut = dataX.heureDebut + "063000";
                dataX.heureFin= dataX.heureFin + "143000";
                
                dataX.dateDebut = dataX.dateDebut + format + dataX.heureDebut;
                dataX.dateFin = dataX.dateFin + format + dataX.heureFin;
                dataX.jour = NomJourSemaine[t->tm_wday];
                Tabdata.push_back(dataX);
                
                monFluxMatin << dataX.debutEvent <<endl;
                monFluxMatin << dataX.dateDebut <<endl;
                monFluxMatin << dataX.dateFin <<endl;
                monFluxMatin << dataX.lieu <<endl;
                monFluxMatin << dataX.vacation <<endl;
                monFluxMatin << dataX.finEvent <<endl;
                break;
                
            case 40:
                strftime(format, 128, "%Y%m%d", t); // format de date utilisable pour ficiher ICS
                
                dataX.vacation = dataX.vacation + "Matin";
                
                dataX.heureDebut = dataX.heureDebut + "063000";
                dataX.heureFin= dataX.heureFin + "143000";
                
                dataX.dateDebut = dataX.dateDebut + format + dataX.heureDebut;
                dataX.dateFin = dataX.dateFin + format + dataX.heureFin;
                dataX.jour = NomJourSemaine[t->tm_wday];
                Tabdata.push_back(dataX);
                
                monFluxMatin << dataX.debutEvent <<endl;
                monFluxMatin << dataX.dateDebut <<endl;
                monFluxMatin << dataX.dateFin <<endl;
                monFluxMatin << dataX.lieu <<endl;
                monFluxMatin << dataX.vacation <<endl;
                monFluxMatin << dataX.finEvent <<endl;
                break;
                
            case 41:
                strftime(format, 128, "%Y%m%d", t); // format de date utilisable pour ficiher ICS
                
                dataX.vacation = dataX.vacation + "Matin";
                
                dataX.heureDebut = dataX.heureDebut + "063000";
                dataX.heureFin= dataX.heureFin + "143000";
                
                dataX.dateDebut = dataX.dateDebut + format + dataX.heureDebut;
                dataX.dateFin = dataX.dateFin + format + dataX.heureFin;
                dataX.jour = NomJourSemaine[t->tm_wday];
                Tabdata.push_back(dataX);
                
                monFluxMatin << dataX.debutEvent <<endl;
                monFluxMatin << dataX.dateDebut <<endl;
                monFluxMatin << dataX.dateFin <<endl;
                monFluxMatin << dataX.lieu <<endl;
                monFluxMatin << dataX.vacation <<endl;
                monFluxMatin << dataX.finEvent <<endl;
                break;
                
            case 42:
                strftime(format, 128, "%Y%m%d", t); // format de date utilisable pour ficiher ICS
                
                dataX.vacation = dataX.vacation + "Matin";
                
                dataX.heureDebut = dataX.heureDebut + "063000";
                dataX.heureFin= dataX.heureFin + "143000";
                
                dataX.dateDebut = dataX.dateDebut + format + dataX.heureDebut;
                dataX.dateFin = dataX.dateFin + format + dataX.heureFin;
                dataX.jour = NomJourSemaine[t->tm_wday];
                Tabdata.push_back(dataX);
                
                monFluxMatin << dataX.debutEvent <<endl;
                monFluxMatin << dataX.dateDebut <<endl;
                monFluxMatin << dataX.dateFin <<endl;
                monFluxMatin << dataX.lieu <<endl;
                monFluxMatin << dataX.vacation <<endl;
                monFluxMatin << dataX.finEvent <<endl;
                break;
                
                
            case 43:break; //Repos
            case 44:break;
            case 45:break;
            case 46:break;
                
            case 47:
                strftime(format, 128, "%Y%m%d", t); // format de date utilisable pour ficiher ICS
                
                dataX.vacation = dataX.vacation + "Matin";
                
                dataX.heureDebut = dataX.heureDebut + "063000";
                dataX.heureFin= dataX.heureFin + "143000";
                
                dataX.dateDebut = dataX.dateDebut + format + dataX.heureDebut;
                dataX.dateFin = dataX.dateFin + format + dataX.heureFin;
                dataX.jour = NomJourSemaine[t->tm_wday];
                Tabdata.push_back(dataX);
                
                monFluxMatin << dataX.debutEvent <<endl;
                monFluxMatin << dataX.dateDebut <<endl;
                monFluxMatin << dataX.dateFin <<endl;
                monFluxMatin << dataX.lieu <<endl;
                monFluxMatin << dataX.vacation <<endl;
                monFluxMatin << dataX.finEvent <<endl;
                break;
                
            case 48:
                strftime(format, 128, "%Y%m%d", t); // format de date utilisable pour ficiher ICS
                
                dataX.vacation = dataX.vacation + "Matin";
                
                dataX.heureDebut = dataX.heureDebut + "063000";
                dataX.heureFin= dataX.heureFin + "143000";
                
                dataX.dateDebut = dataX.dateDebut + format + dataX.heureDebut;
                dataX.dateFin = dataX.dateFin + format + dataX.heureFin;
                dataX.jour = NomJourSemaine[t->tm_wday];
                Tabdata.push_back(dataX);
                
                monFluxMatin << dataX.debutEvent <<endl;
                monFluxMatin << dataX.dateDebut <<endl;
                monFluxMatin << dataX.dateFin <<endl;
                monFluxMatin << dataX.lieu <<endl;
                monFluxMatin << dataX.vacation <<endl;
                monFluxMatin << dataX.finEvent <<endl;
                break;
                
            case 49:
                strftime(format, 128, "%Y%m%d", t); // format de date utilisable pour ficiher ICS
                
                dataX.vacation = dataX.vacation + "Matin";
                
                dataX.heureDebut = dataX.heureDebut + "063000";
                dataX.heureFin= dataX.heureFin + "143000";
                
                dataX.dateDebut = dataX.dateDebut + format + dataX.heureDebut;
                dataX.dateFin = dataX.dateFin + format + dataX.heureFin;
                dataX.jour = NomJourSemaine[t->tm_wday];
                Tabdata.push_back(dataX);
                
                monFluxMatin << dataX.debutEvent <<endl;
                monFluxMatin << dataX.dateDebut <<endl;
                monFluxMatin << dataX.dateFin <<endl;
                monFluxMatin << dataX.lieu <<endl;
                monFluxMatin << dataX.vacation <<endl;
                monFluxMatin << dataX.finEvent <<endl;
                break;
                
            case 50:
                strftime(format, 128, "%Y%m%d", t); // format de date utilisable pour ficiher ICS
                
                dataX.vacation = dataX.vacation + "Matin";
                
                dataX.heureDebut = dataX.heureDebut + "063000";
                dataX.heureFin= dataX.heureFin + "143000";
                
                dataX.dateDebut = dataX.dateDebut + format + dataX.heureDebut;
                dataX.dateFin = dataX.dateFin + format + dataX.heureFin;
                dataX.jour = NomJourSemaine[t->tm_wday];
                Tabdata.push_back(dataX);
                
                monFluxMatin << dataX.debutEvent <<endl;
                monFluxMatin << dataX.dateDebut <<endl;
                monFluxMatin << dataX.dateFin <<endl;
                monFluxMatin << dataX.lieu <<endl;
                monFluxMatin << dataX.vacation <<endl;
                monFluxMatin << dataX.finEvent <<endl;
                break;
                
            case 51:
                strftime(format, 128, "%Y%m%d", t); // format de date utilisable pour ficiher ICS
                
                dataX.vacation = dataX.vacation + "Matin";
                
                dataX.heureDebut = dataX.heureDebut + "063000";
                dataX.heureFin= dataX.heureFin + "143000";
                
                dataX.dateDebut = dataX.dateDebut + format + dataX.heureDebut;
                dataX.dateFin = dataX.dateFin + format + dataX.heureFin;
                dataX.jour = NomJourSemaine[t->tm_wday];
                Tabdata.push_back(dataX);
                
                monFluxMatin << dataX.debutEvent <<endl;
                monFluxMatin << dataX.dateDebut <<endl;
                monFluxMatin << dataX.dateFin <<endl;
                monFluxMatin << dataX.lieu <<endl;
                monFluxMatin << dataX.vacation <<endl;
                monFluxMatin << dataX.finEvent <<endl;
                break;
                
            case 52:break; // Repos
            case 53:break;
            case 54:break;
            case 55:break;
            case 56:break; //fin vac matin
                
            case 57:
                strftime(format, 128, "%Y%m%d", t); // format de date utilisable pour ficiher ICS
                
                dataX.vacation = dataX.vacation + "Nuit";
                
                dataX.heureDebut = dataX.heureDebut + "223000";
                dataX.heureFin= dataX.heureFin + "233000";
                
                dataX.dateDebut = dataX.dateDebut + format + dataX.heureDebut;
                dataX.dateFin = dataX.dateFin + format + dataX.heureFin;
                dataX.jour = NomJourSemaine[t->tm_wday];
                Tabdata.push_back(dataX);
                
                monFluxNuit << dataX.debutEvent <<endl;
                monFluxNuit << dataX.dateDebut <<endl;
                monFluxNuit << dataX.dateFin <<endl;
                monFluxNuit << dataX.lieu <<endl;
                monFluxNuit << dataX.vacation <<endl;
                monFluxNuit << dataX.finEvent <<endl;
                break; //debut vac nuit
                
            case 58:
                strftime(format, 128, "%Y%m%d", t); // format de date utilisable pour ficiher ICS
                
                dataX.vacation = dataX.vacation + "Nuit";
                
                dataX.heureDebut = dataX.heureDebut + "223000";
                dataX.heureFin= dataX.heureFin + "233000";
                
                dataX.dateDebut = dataX.dateDebut + format + dataX.heureDebut;
                dataX.dateFin = dataX.dateFin + format + dataX.heureFin;
                dataX.jour = NomJourSemaine[t->tm_wday];
                Tabdata.push_back(dataX);
                
                monFluxNuit << dataX.debutEvent <<endl;
                monFluxNuit << dataX.dateDebut <<endl;
                monFluxNuit << dataX.dateFin <<endl;
                monFluxNuit << dataX.lieu <<endl;
                monFluxNuit << dataX.vacation <<endl;
                monFluxNuit << dataX.finEvent <<endl;
                break;
                
            case 59:
                strftime(format, 128, "%Y%m%d", t); // format de date utilisable pour ficiher ICS
                
                dataX.vacation = dataX.vacation + "Nuit";
                
                dataX.heureDebut = dataX.heureDebut + "223000";
                dataX.heureFin= dataX.heureFin + "233000";
                
                dataX.dateDebut = dataX.dateDebut + format + dataX.heureDebut;
                dataX.dateFin = dataX.dateFin + format + dataX.heureFin;
                dataX.jour = NomJourSemaine[t->tm_wday];
                Tabdata.push_back(dataX);
                
                monFluxNuit << dataX.debutEvent <<endl;
                monFluxNuit << dataX.dateDebut <<endl;
                monFluxNuit << dataX.dateFin <<endl;
                monFluxNuit << dataX.lieu <<endl;
                monFluxNuit << dataX.vacation <<endl;
                monFluxNuit << dataX.finEvent <<endl;
                break;
                
            case 60:
                strftime(format, 128, "%Y%m%d", t); // format de date utilisable pour ficiher ICS
                
                dataX.vacation = dataX.vacation + "Nuit";
                
                dataX.heureDebut = dataX.heureDebut + "223000";
                dataX.heureFin= dataX.heureFin + "233000";
                
                dataX.dateDebut = dataX.dateDebut + format + dataX.heureDebut;
                dataX.dateFin = dataX.dateFin + format + dataX.heureFin;
                dataX.jour = NomJourSemaine[t->tm_wday];
                Tabdata.push_back(dataX);
                
                monFluxNuit << dataX.debutEvent <<endl;
                monFluxNuit << dataX.dateDebut <<endl;
                monFluxNuit << dataX.dateFin <<endl;
                monFluxNuit << dataX.lieu <<endl;
                monFluxNuit << dataX.vacation <<endl;
                monFluxNuit << dataX.finEvent <<endl;
                break;
                
            case 61:break; // Repos
            case 62:break;
            case 63:break;
            case 64:break;
            case 65:break;
                
            case 66:
                strftime(format, 128, "%Y%m%d", t); // format de date utilisable pour ficiher ICS
                
                dataX.vacation = dataX.vacation + "Nuit";
                
                dataX.heureDebut = dataX.heureDebut + "223000";
                dataX.heureFin= dataX.heureFin + "233000";
                
                dataX.dateDebut = dataX.dateDebut + format + dataX.heureDebut;
                dataX.dateFin = dataX.dateFin + format + dataX.heureFin;
                dataX.jour = NomJourSemaine[t->tm_wday];
                Tabdata.push_back(dataX);
                
                monFluxNuit << dataX.debutEvent <<endl;
                monFluxNuit << dataX.dateDebut <<endl;
                monFluxNuit << dataX.dateFin <<endl;
                monFluxNuit << dataX.lieu <<endl;
                monFluxNuit << dataX.vacation <<endl;
                monFluxNuit << dataX.finEvent <<endl;
                break;
                
            case 67:
                strftime(format, 128, "%Y%m%d", t); // format de date utilisable pour ficiher ICS
                
                dataX.vacation = dataX.vacation + "Nuit";
                
                dataX.heureDebut = dataX.heureDebut + "223000";
                dataX.heureFin= dataX.heureFin + "233000";
                
                dataX.dateDebut = dataX.dateDebut + format + dataX.heureDebut;
                dataX.dateFin = dataX.dateFin + format + dataX.heureFin;
                dataX.jour = NomJourSemaine[t->tm_wday];
                Tabdata.push_back(dataX);
                
                monFluxNuit << dataX.debutEvent <<endl;
                monFluxNuit << dataX.dateDebut <<endl;
                monFluxNuit << dataX.dateFin <<endl;
                monFluxNuit << dataX.lieu <<endl;
                monFluxNuit << dataX.vacation <<endl;
                monFluxNuit << dataX.finEvent <<endl;
                break;
                
            case 68:
                strftime(format, 128, "%Y%m%d", t); // format de date utilisable pour ficiher ICS
                
                dataX.vacation = dataX.vacation + "Nuit";
                
                dataX.heureDebut = dataX.heureDebut + "223000";
                dataX.heureFin= dataX.heureFin + "233000";
                
                dataX.dateDebut = dataX.dateDebut + format + dataX.heureDebut;
                dataX.dateFin = dataX.dateFin + format + dataX.heureFin;
                dataX.jour = NomJourSemaine[t->tm_wday];
                Tabdata.push_back(dataX);
                
                monFluxNuit << dataX.debutEvent <<endl;
                monFluxNuit << dataX.dateDebut <<endl;
                monFluxNuit << dataX.dateFin <<endl;
                monFluxNuit << dataX.lieu <<endl;
                monFluxNuit << dataX.vacation <<endl;
                monFluxNuit << dataX.finEvent <<endl;
                break;
                
            case 69:
                strftime(format, 128, "%Y%m%d", t); // format de date utilisable pour ficiher ICS
                
                dataX.vacation = dataX.vacation + "Nuit";
                
                dataX.heureDebut = dataX.heureDebut + "223000";
                dataX.heureFin= dataX.heureFin + "233000";
                
                dataX.dateDebut = dataX.dateDebut + format + dataX.heureDebut;
                dataX.dateFin = dataX.dateFin + format + dataX.heureFin;
                dataX.jour = NomJourSemaine[t->tm_wday];
                Tabdata.push_back(dataX);
                
                monFluxNuit << dataX.debutEvent <<endl;
                monFluxNuit << dataX.dateDebut <<endl;
                monFluxNuit << dataX.dateFin <<endl;
                monFluxNuit << dataX.lieu <<endl;
                monFluxNuit << dataX.vacation <<endl;
                monFluxNuit << dataX.finEvent <<endl;
                break;
                
            case 70:
                strftime(format, 128, "%Y%m%d", t); // format de date utilisable pour ficiher ICS
                
                dataX.vacation = dataX.vacation + "Nuit";
                
                dataX.heureDebut = dataX.heureDebut + "223000";
                dataX.heureFin= dataX.heureFin + "233000";
                
                dataX.dateDebut = dataX.dateDebut + format + dataX.heureDebut;
                dataX.dateFin = dataX.dateFin + format + dataX.heureFin;
                dataX.jour = NomJourSemaine[t->tm_wday];
                Tabdata.push_back(dataX);
                
                monFluxNuit << dataX.debutEvent <<endl;
                monFluxNuit << dataX.dateDebut <<endl;
                monFluxNuit << dataX.dateFin <<endl;
                monFluxNuit << dataX.lieu <<endl;
                monFluxNuit << dataX.vacation <<endl;
                monFluxNuit << dataX.finEvent <<endl;
                break;
                
            case 71:break; //Repos
            case 72:break;
            case 73:break;
            case 74:break;
                
            case 75:
                strftime(format, 128, "%Y%m%d", t); // format de date utilisable pour ficiher ICS
                
                dataX.vacation = dataX.vacation + "Nuit";
                
                dataX.heureDebut = dataX.heureDebut + "223000";
                dataX.heureFin= dataX.heureFin + "233000";
                
                dataX.dateDebut = dataX.dateDebut + format + dataX.heureDebut;
                dataX.dateFin = dataX.dateFin + format + dataX.heureFin;
                dataX.jour = NomJourSemaine[t->tm_wday];
                Tabdata.push_back(dataX);
                
                monFluxNuit << dataX.debutEvent <<endl;
                monFluxNuit << dataX.dateDebut <<endl;
                monFluxNuit << dataX.dateFin <<endl;
                monFluxNuit << dataX.lieu <<endl;
                monFluxNuit << dataX.vacation <<endl;
                monFluxNuit << dataX.finEvent <<endl;
                break;
                
            case 76:
                strftime(format, 128, "%Y%m%d", t); // format de date utilisable pour ficiher ICS
                
                dataX.vacation = dataX.vacation + "Nuit";
                
                dataX.heureDebut = dataX.heureDebut + "223000";
                dataX.heureFin= dataX.heureFin + "233000";
                
                dataX.dateDebut = dataX.dateDebut + format + dataX.heureDebut;
                dataX.dateFin = dataX.dateFin + format + dataX.heureFin;
                dataX.jour = NomJourSemaine[t->tm_wday];
                Tabdata.push_back(dataX);
                
                monFluxNuit << dataX.debutEvent <<endl;
                monFluxNuit << dataX.dateDebut <<endl;
                monFluxNuit << dataX.dateFin <<endl;
                monFluxNuit << dataX.lieu <<endl;
                monFluxNuit << dataX.vacation <<endl;
                monFluxNuit << dataX.finEvent <<endl;
                break;
                
            case 77:
                strftime(format, 128, "%Y%m%d", t); // format de date utilisable pour ficiher ICS
                
                dataX.vacation = dataX.vacation + "Nuit";
                
                dataX.heureDebut = dataX.heureDebut + "223000";
                dataX.heureFin= dataX.heureFin + "233000";
                
                dataX.dateDebut = dataX.dateDebut + format + dataX.heureDebut;
                dataX.dateFin = dataX.dateFin + format + dataX.heureFin;
                dataX.jour = NomJourSemaine[t->tm_wday];
                Tabdata.push_back(dataX);
                
                monFluxNuit << dataX.debutEvent <<endl;
                monFluxNuit << dataX.dateDebut <<endl;
                monFluxNuit << dataX.dateFin <<endl;
                monFluxNuit << dataX.lieu <<endl;
                monFluxNuit << dataX.vacation <<endl;
                monFluxNuit << dataX.finEvent <<endl;
                break;
                
            case 78:
                strftime(format, 128, "%Y%m%d", t); // format de date utilisable pour ficiher ICS
                
                dataX.vacation = dataX.vacation + "Nuit";
                
                dataX.heureDebut = dataX.heureDebut + "223000";
                dataX.heureFin= dataX.heureFin + "233000";
                
                dataX.dateDebut = dataX.dateDebut + format + dataX.heureDebut;
                dataX.dateFin = dataX.dateFin + format + dataX.heureFin;
                dataX.jour = NomJourSemaine[t->tm_wday];
                Tabdata.push_back(dataX);
                
                monFluxNuit << dataX.debutEvent <<endl;
                monFluxNuit << dataX.dateDebut <<endl;
                monFluxNuit << dataX.dateFin <<endl;
                monFluxNuit << dataX.lieu <<endl;
                monFluxNuit << dataX.vacation <<endl;
                monFluxNuit << dataX.finEvent <<endl;
                break;
                
            case 79:
                strftime(format, 128, "%Y%m%d", t); // format de date utilisable pour ficiher ICS
                
                dataX.vacation = dataX.vacation + "Nuit";
                
                dataX.heureDebut = dataX.heureDebut + "223000";
                dataX.heureFin= dataX.heureFin + "233000";
                
                dataX.dateDebut = dataX.dateDebut + format + dataX.heureDebut;
                dataX.dateFin = dataX.dateFin + format + dataX.heureFin;
                dataX.jour = NomJourSemaine[t->tm_wday];
                Tabdata.push_back(dataX);
                
                monFluxNuit << dataX.debutEvent <<endl;
                monFluxNuit << dataX.dateDebut <<endl;
                monFluxNuit << dataX.dateFin <<endl;
                monFluxNuit << dataX.lieu <<endl;
                monFluxNuit << dataX.vacation <<endl;
                monFluxNuit << dataX.finEvent <<endl;
                break;
                
            case 80:break; //Repos
            case 81:break;
            case 82:break;
            case 83:break;
            case 84:break; //fin vac nuit
                
            default:
                cout << "erreur" <<endl;
                break;
        }
        
        decal = decal+86400; // nombre de secondes par jour
        compteurJourVac = compteurJourVac+1;
        
    }
    
    //Affichage du vector
    cout << "### Affichage du conteneur de data ### \n" <<endl;
    string dataDate, dataVaction, dataAll;
    
    int compteur =0;
    
    for(int i = 0; Tabdata.size()!= i  ;++i)
    {
        if (compteur ==14 )
        {
            cout << "\n############\n";
            compteur = 0;
        }
        
        cout << Tabdata.at(i).debutEvent <<"\n";
        cout << Tabdata.at(i).dateDebut <<"\n";
        cout << Tabdata.at(i).dateFin <<"\n";
        cout << Tabdata.at(i).lieu <<"\n";
        cout << Tabdata.at(i).vacation <<"\n";
        cout << Tabdata.at(i).finEvent <<"\n";
        
        /*
         cout << "\n ### Ecriture dans le fichier ### \n" << endl;
         dataDate = Tabdata.at(i).date;
         dataVaction = Tabdata.at(i).vacation;
         dataAll = "DAY="+dataDate+"&VACATION="+dataVaction;
         
         cout << "Data : "<<dataAll << endl;
         
         compteur = compteur +1;
         
         */
        nombreElement = i ;
    }
    
    // Balise de fin des fichier ICS
    monFluxAprem<<"END:VCALENDAR"<<endl;
    monFluxMatin<<"END:VCALENDAR"<<endl;
    monFluxNuit<<"END:VCALENDAR"<<endl;
    
    // Fermeture des fichiers
    monFluxAprem.close();
    monFluxMatin.close();
    monFluxNuit.close();
    
    cout <<"\nNombre de jours travaillé sur 10 ans : " << nombreElement << endl;
    cout <<"        \n@@@@@ Planning ICS 1.0 By MOKS @@@@@" << endl << endl;
    
    return 0;
}

