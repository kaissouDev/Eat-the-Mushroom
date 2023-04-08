#include <iostream>
#include <string>

struct perso{

    int vie;
    std::string nom = "kaissou";

};

void AfficherConsole(){

    perso kais;


    std::cout << "--------------------------------" << std::endl;
    std::cout << "Nom du Joueur : " << kais.nom << std::endl;
}