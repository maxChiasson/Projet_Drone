/*
	Auteur :					Maxyme Chiasson
	Date de création : 			15 mai 2018
	Dernière modification :		22 mai 2018
	Titre :						TP1 - Parcours Drone
	Nom fichier :				parcours.cpp
	
	Dans le cadre de : 			420-P66-SI PROJET DE PROGRAMMATION
	
	
	Description :		Fichiers contenant les fonctions permettant les déplacements
						de l'appareil. Ces fonctions seront appellés dans le main.
*/

//Inclu notre fichier header contenant le prototype de nos fonctions.
#include "parcours.hpp"

//Déclaration de namespace pour éviter de les ré-écrire à chaque commande.
using namespace DJI::OSDK;
using namespace DJI::OSDK::Telemetry;
using namespace std;


//Déclare une fonction pour le décollage.
void dwoneDecolle(Vehicle* m100, int timeout)
{
	//Appel de la fonction "takeoff" dans les librairies de l'OSDK de DJI.
	m100->control->takeoff(timeout);
}

//Déclare une fonction pour l'attérissage.
void dwoneAtterit(Vehicle* m100, int timeout)
{
	//Appel de la fonction "land" dans les librairies de l'OSDK de DJI.
	m100->control->land(timeout);
}

//Déclare une fonction pour effectuer les mouvements du drone.
void mouvement(Vehicle* m100, int temps, int x, int y, int z, int yaw)
{
	int elapsedTimeInMs = 0;	//Déclare une variable contenant le temps écouler en milisecondes.
	int cycleTimeInMs = 20;		//Variable contenant la valeur du cycle temporel. On le mets à 20 

	//Boucle qui déplace le drone tant et aussi longtemps que le temps écouler ne dépasse pas le temps fourni en paramètre.
	while (elapsedTimeInMs < temps)
	{
		//Appel de la fonction des librairies de l'OSDK de DJI, permettant au Matrice 100 d'effectuer un mouvement quelconque une fois dans les airs.
		m100->control->flightCtrl(Control::CtrlData((DJI::OSDK::Control::HORIZONTAL_VELOCITY | DJI::OSDK::Control::VERTICAL_VELOCITY | 
		DJI::OSDK::Control::YAW_RATE | DJI::OSDK::Control::HORIZONTAL_BODY | DJI::OSDK::Control::STABLE_ENABLE), x, y, z, yaw));

		usleep(cycleTimeInMs * 1000);
		//Incrément le compteur de temps
		elapsedTimeInMs += cycleTimeInMs;
	}
}





