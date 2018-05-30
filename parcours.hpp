/*
	Auteur :					Maxyme Chiasson
	Date de création : 			15 mai 2018
	Dernière modification :		22 mai 2018
	Titre :						TP1 - Parcours Drone
	Nom fichier :				parcours.hpp
	
	Dans le cadre de : 			420-P66-SI PROJET DE PROGRAMMATION
	
	
	Description :				Fichiers contenant les headers.
								On y déclare ici les fonctions utilisé dans le fichier cpp,
								et on inclu ce fichier dans le main. En d'autres termes,
								ce fichier nous permet de faire le prototypage de nos fonctions
								permettant de déplacer le drone.
*/


//Défini notre fichier, afin de pouvoir l'inclure dans notre CPP.
#ifndef PARCOURS_HPP
#define PARCOURS_HPP

// Include des système
#include <cmath>

// Include de l'OSDK de DJI
#include "dji_status.hpp"
#include <dji_vehicle.hpp>
#include <dji_control.hpp>

// Include helper de DJI
#include <dji_linux_helpers.hpp>

#define C_EARTH (double)6378137.0
#define DEG2RAD 0.01745329252

//Fonction permettant le décollage, recevant en argument un véhicule *Vehicle* et une valeur de timeout (temporel) en Integer.
void dwoneDecolle(DJI::OSDK::Vehicle* m100, int timeout);

//Fonction permettant l'attérissage, recevant en argument un véhicule *Vehicle* et une valeur de timeout (temporel) en Integer.
void dwoneAtterit(DJI::OSDK::Vehicle* m100, int timeout);

//Fonction permettant tout autre type de déplacement du parcours.
void mouvement(DJI::OSDK::Vehicle* m100, int tempsMs, int x, int y, int z, int yaw);
/* 
	Elle reçoit en argument :
		- un véhicule *Vehicle*
		- une valeur temporel en miliseconde, en Integer
		- une valeur pour la vitesse de l'axe des X, en Integer
		- une valeur pour la vitesse de l'axe des Y, en Integer
		- une valeur pour la vitesse de l'axe des Z, en Integer
		- une valeur pour l'angle du YAW sur 360 degrées, en Integer
*/

#endif
