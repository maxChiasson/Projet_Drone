/*
	Auteur :					Maxyme Chiasson
	Date de création : 			1er mai 2018
	Dernière modification :		28 mai 2018
	Titre :						TP1 - Parcours Drone
	Nom fichier :				main.cpp
	
	Dans le cadre de : 			420-P66-SI PROJET DE PROGRAMMATION
	
	
	Description :		Programme en C++ qui gère l'IA du drone Matrice 100 de DJI,
						de sorte que l'exécution de ce code lui permette de faire un parcours
						bien précis, et de façon autonome.
		
		
			-----------------	 Sources	-----------------
	
					DJI Developper
					
	Source :			https://developer.dji.com/onboard-api-reference/index.html
	Consulté le :		2 avril 2018

*/




//Appel le fichier "parcours.hpp", contenant toutes les prototypages des fonctions qui permettent au drone de se déplacer.
#include "parcours.hpp"

//Déclare les namespace pour ne pas à avoir à les écrires à chaque commande.
using namespace DJI::OSDK;
using namespace std;

//Fonction MAIN
int main (int argc, char** argv)
{
	//Déclaration et initialisation des variables.
	int functionTimeout = 1;
	

/*  Validation et test de démarrage du drone  */
	
	//Démarrage de L'OSDK.
	LinuxSetup linuxEnvironment(argc, argv);
	
	//Déclare un objet "Vehicule" et y affecte la référence de notre drone (Matrice 100) sur le manifold.
	Vehicle*  dwone = linuxEnvironment.getVehicle();
	
	//Vérifie si l'appareil est initialisé. Quitte le programme s'il ne l'est pas.
	if (dwone == NULL)
	{
		cout << "Appareil non-initialise. Fin du programme...\n";
		//Retourne la valeur - 1 pour indiquer que le programme s'est terminé avec des erreurs.
		return -1;
	}
	
	//Commande qui obtient l'autorité du contrôle de l'appareil. Le pilote n'auras donc pas le contrôle absolu.
	dwone->obtainCtrlAuthority(functionTimeout);


/*  Parcours et appel des fonctions nécessaires  */

	
	//Appel de la fonction permettant le décollage.
	cout << "Decollage...\n";
  	dwoneDecolle(dwone, functionTimeout);
	
	//Bloque le thread pendant 10 secondes
	cout << "Attente de la fin du decollage...\n";
	sleep(10);
	
	//Fais monter le drone de 1,5 metres supplémentaire, afin de contrer l'effet du système de climatisation du gym sur le drone.
	cout << "Augmente l'altitude de 1,5 m.";
	mouvement(dwone, 1500, 0, 0, 1, 0);

	//Appel de la fonction permettant d'avancer le drone, avec des paramètres envoyés pour avancer de 3,1 mètres.
	cout << "Avancer de 3,1 m.\n";
	mouvement(dwone, 3100, 1, 0, 0, 0);
	
	//Appel de la fonction permettant au drone d'effectuer une rotation sur lui-même, avec un angle fourni en paramètre.
	cout << "Rotation à 90 degres vers la droite.\n";
	mouvement(dwone, 2500, 0, 0, 0, 30);

	//Avance le drone de 1.7 mètres.
	cout << "Avancer de 1,7 m.\n";
	mouvement(dwone, 1700, 1, 0, 0, 0);
	
	//Tourne le drone autour du premier cône, dans le sens horaire.
	cout << "Tourne autour du premier cone...\n";
	mouvement(dwone, 8000, 1, 0, 0, 45);

	//Avance le drone de 8 mètres.
	cout << "Avance de 8 metres.\n";
	mouvement(dwone, 8000, 1, 0, 0, 0);

	//Repositionne le drone
	cout << "Repositionnement du drone\n";
	mouvement(dwone, 2500, 0, 0, 0, -17);
	
	//Tourne autour du 2e cône, caméra face au cône.
	cout << "Tourne autour du 2e cone...\n";
	mouvement(dwone, 4000, 0, 1, 0, -45);
	
	//Repositionne le drone.
	cout << "Repositionnement du drone.\n";
	mouvement(dwone, 1500, 0, 0, 0, 45);
	
	//Avance de 8 mètres.
	cout << "Avance de 8 m.\n";
	mouvement(dwone, 8000, 1, 0, 0, 0);
	
	//Repositinne le drone.
	cout << "Repositionnement du drone\n";
	mouvement(dwone, 2500, 0, 0, 0, 28);

	//Tourne autour du 3e cône, caméra face au cône.
	cout << "Tourne autour du 3e cone...\n";
	mouvement(dwone, 4000, 0, -1, 0, 45);

	//Repositinne le drone.
	cout << "Repositionnement du drone\n";
	mouvement(dwone, 3500, 0, 0, 0, -22);

	//Avance de 3.2 mètres.
	cout << "Avance de 3,2 m.\n";
	mouvement(dwone, 3200, 1, 0, 0, 0);

	//Repositionne le drone.
	cout << "Repositionnement du drone\n";
	mouvement(dwone, 2000, 0, 0, 0, 55);
	
	//Tourne autour du dernier cône, caméra vers l'extérieur.
	cout << "Tourne autour du 4e cone...\n";
	mouvement(dwone, 10000, 0, -1, 0, -37);	

	//Ramènes le drone près de son point de départ.
	cout << "Avance de 11 m.\n";
	mouvement(dwone, 11000, 1, 0, 0, 0);
	//Bloque le thread pendant 2 secondes, comme quoi le drone prends bien de le temps d'être stable avant d'entammer son attérissage.
	sleep(2);	
	
	//Appel de la fonction permettant l'atterissage de l'appareil.
	cout << "Atterissage...\n";
	dwoneAtterit(dwone, functionTimeout);	

	//Retour la valeur zéro, indiquant que le programme s'est exécuté sans erreur.
	cout << "Parcours terminer.\n";
	return 0;
}
