// Utilisation des algorithmes de la STL sur le conteneur vector
#include <sstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>

// Espace de nom utilisé
using namespace std;

// Fonction réalisant la conversion décimal -> binaire 
/**
 * @brief Utilisation du type <bitset>
 */
bitset<8> convertion_ip_binaire(int i)
{
    bitset<8> b1(i);

    return b1;
}
//Fonction permettant de retrouver la partie réseau d'une adresse IP
/**
* @brief Utilisation de l'opérateur & bit à bit
*/
bitset<8> op_et(bitset<8> adresse, bitset<8> masque)
{

    bitset<8> p1 = adresse & masque;

    return p1;
}
// Fonction permettant de retrouver la partie hote d'une adresse IP
/**
* @brief Utilisation d'un NON bit à bit
*/
bitset<8> op_non_ip(bitset<8> adresse, bitset<8> masque)
{
    // 1 = 0 & 0 = 1
    bitset<8> p1 = ~masque;

    // opérateur & logique
    bitset<8> p2 = adresse & p1;

    return p2;
}
// Fonction permettant de retrouver la partie hote d'une adresse IP
/**
* @brief Utilisation d'un NON bit à bit
*/
bitset<8> op_non_reseau(bitset<8> masque)
{
    // 1 = 0 & 0 = 1
    bitset<8> p1 = ~masque;

    return p1;
}
//Fonction permettant de convertir le binaire vers du décimal
/**
* @brief Utilisation de la méthode to_ulong() pour reconvertir le binaire en décimal 
*/
int convertion_bin_dec (bitset<8> adresse)
{

    int d1 = adresse.to_ulong();
    return d1;
}

/**
 * @brief Fonction pour afficher le menu utilisateur
 * @param Aucun
 * @return Le choic de l'utilisateur sous forme d'entier
 */
int afficher_menu()
{
	int choix;

	cout << "\033[1;31m===== Menu de gestion des entiers =====\033[0m" << endl;
	cout << "\033[0;33m[1]\033[0m - Resoudre une adresse IP :" << endl;
	cout << "\033[0;33m[2]\033[0m - Resoudre un reseau :" << endl;
	cout << "\033[0;33m[0]\033[0m - Sortir !" << endl;
	cout << "\033[1;31mVotre choix : \033[0m";
	cin >> choix;
    cout << endl;

	return choix;
}

int main(){

    // Variables
    string adresse_ip;
    string masque_ip;
    char c = '.';
    int i3, i2, i1, i0;
    int m3, m2, m1, m0;

    istringstream iss1;
    istringstream iss2;

    // Variable de calcul
    bitset<8> ad3, ad2, ad1, ad0;
    bitset<8> mas3, mas2, mas1, mas0;
    bitset<8> add_res3, add_res2, add_res1, add_res0;
    bitset<8> add_hote3, add_hote2, add_hote1, add_hote0;

    // Boucle de gestion du menu
    int fin = 0;
	while(fin == 0)
	{
		switch( afficher_menu() )
		{   
            // --------------- Résoudre une adresse IP --------------- //
			case 1 :
                
                // Saisie de l'adresse IP
                cout << "\033[1;31mEntrez une adresse IP : \033[0m" << endl;
                cin >> adresse_ip;
                cout << "\033[1;31mEntrez le masque : \033[0m" << endl;
                cin >> masque_ip;
                cout << endl;

                // Découpage en mémoire
                iss1 = istringstream(adresse_ip);
                iss1 >> i3 >> c >> i2 >> c >> i1 >> c >> i0;
                // Découpe masque
                iss2 = istringstream(masque_ip);
                iss2 >> m3 >> c >> m2 >> c >> m1 >> c >> m0;

                // convertion pour adresse IP
                ad3 = convertion_ip_binaire(i3);
                ad2 = convertion_ip_binaire(i2);
                ad1 = convertion_ip_binaire(i1);
                ad0 = convertion_ip_binaire(i0);

                //convertion pour masque sous réseau
                mas3 = convertion_ip_binaire(m3);
                mas2 = convertion_ip_binaire(m2);
                mas1 = convertion_ip_binaire(m1);
                mas0 = convertion_ip_binaire(m0);

                // & logique, utilisé pour la partie réseau
                add_res3 = op_et(ad3, mas3);
                add_res2 = op_et(ad2, mas2);
                add_res1 = op_et(ad1, mas1);
                add_res0 = op_et(ad0, mas0);

                // Non logique, utilisé pour la partie hote
                add_hote3 = op_non_ip(ad3, mas3);
                add_hote2 = op_non_ip(ad2, mas2);
                add_hote1 = op_non_ip(ad1, mas1);
                add_hote0 = op_non_ip(ad0, mas0);

                // Affichage @IP et masque 
                cout << "\033[1;31m=======STANDARD IP=======\033[0m" << endl;
                cout << "\033[0;33mVotre @IP (binaire) = \033[0m";
                cout << ad3 << c << ad2 << c << ad1 << c << ad0<< endl;

                cout << "\033[0;33mVotre masque (binaire) = \033[0m";
                cout << mas3 << c << mas2 << c << mas1 << c << mas0 << endl;
                cout << endl;
                // Affichage partie réseau NETID
                cout << "\033[1;31m=======NETID=======\033[0m" << endl;
                cout << "\033[0;33mPartie reseau (netid binaire) = \033[0m";
                cout << add_res3 << c << add_res2 << c << add_res1 << c << add_res0 << endl;
                
                cout << "\033[0;33mPartie reseau (netid decimal) = \033[0m";
                cout << convertion_bin_dec(add_res3)<< c << convertion_bin_dec(add_res2) << c <<  convertion_bin_dec(add_res1) << c << convertion_bin_dec(add_res0) << endl;
                cout << endl;
                // Affichage partie réseau HOSTID
                cout << "\033[1;31m=======HOSTID=======\033[0m" << endl;
                cout << "\033[0;33mPartie machine (hostid binaire) = \033[0m";
                cout << add_hote3 << c << add_hote2 << c << add_hote1 << c << add_hote0 <<endl;

                cout << "\033[0;33mPartie machine (netid decimal) = \033[0m";
                cout <<  convertion_bin_dec(add_hote3)<< c << convertion_bin_dec(add_hote2) << c <<  convertion_bin_dec(add_hote1) << c << convertion_bin_dec(add_hote0) << endl;
                cout << endl;

				break;

			case 2 :
                // Saisie de l'adresse IP
                cout << "\033[1;31mEntrez une adresse IP réseau : \033[0m" << endl;
                cin >> adresse_ip;
                cout << "\033[1;31mEntrez le masque de sous réseau : \033[0m" << endl;
                cin >> masque_ip;
                cout << endl;

                // Découpage en mémoire
                iss1 = istringstream(adresse_ip);
                iss1 >> i3 >> c >> i2 >> c >> i1 >> c >> i0;
                // Découpe masque
                iss2 = istringstream(masque_ip);
                iss2 >> m3 >> c >> m2 >> c >> m1 >> c >> m0;

                // convertion pour adresse IP
                ad3 = convertion_ip_binaire(i3);
                ad2 = convertion_ip_binaire(i2);
                ad1 = convertion_ip_binaire(i1);
                ad0 = convertion_ip_binaire(i0);

                //convertion pour masque sous réseau
                mas3 = convertion_ip_binaire(m3);
                mas2 = convertion_ip_binaire(m2);
                mas1 = convertion_ip_binaire(m1);
                mas0 = convertion_ip_binaire(m0);

                op_non_reseau(mas3);
                op_non_reseau(mas2);
                op_non_reseau(mas1);
                op_non_reseau(mas0);
                
                cout << "\033[1;31m=======Plage d'adresses=======\033[0m" << endl;
                cout << i3 << c << i2 << c << i1 << c << i0 +1<< endl;
                
				break;

            case 0 :
                
                fin = 1;
            break;
        }
    }
    
        

    return 0;
}

