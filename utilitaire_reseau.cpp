// Utilisation des algorithmes de la STL sur le conteneur vector
#include <sstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
#include <cmath>

// Espace de nom utilisé
using namespace std;

/**
 * @brief Fonction réalisant la conversion décimal -> binaire
 * @param i soit la valeur entrée en décimal
 */
bitset<8> convertion_ip_binaire(int i)
{
    bitset<8> b1(i);

    return b1;
}

/**
 * @brief Fonction permettant de retrouver la partie réseau d'une adresse IP
 * @param adresse soit l'adresse IP en binaire
 * @param masque soit le masque de l'adresse en binaire
 */
bitset<8> op_et(bitset<8> adresse, bitset<8> masque)
{

    bitset<8> p1 = adresse & masque;

    return p1;
}

/**
 * @brief Fonction permettant de retrouver la partie hote d'une adresse IP
 * @param adresse en binaire
 * @param masque en binaire
 */
bitset<8> op_non_ip(bitset<8> adresse, bitset<8> masque)
{
    // 1 = 0 & 0 = 1
    bitset<8> p1 = ~masque;

    // opérateur & logique
    bitset<8> p2 = adresse & p1;

    return p2;
}

/**
 * @brief Fonction permettant de retrouver la partie hote d'une adresse IP
 * @param masque en binaire
 */
bitset<8> op_non_reseau(bitset<8> masque)
{
    // 1 = 0 & 0 = 1
    bitset<8> p1 = ~masque;

    return p1;
}

/**
 * @brief Fonction permettant de convertir le binaire vers du décimal
 * @param adresse en binaire
 */
int convertion_bin_dec(bitset<8> adresse)
{
    // u_long effectue la conversion du binaire vers le décimal
    int d1 = adresse.to_ulong();
    return d1;
}

/**
 * @brief Fonction pour afficher le menu utilisateur
 * @param Aucun
 * @return Le choix de l'utilisateur sous forme d'entier
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

int main()
{

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

    // Variable de calcul pour la partie résolution de réseau
    std::bitset<32> adresse_ip_bits;
    std::bitset<32> masque_bits;

    std::bitset<32> adresse_diffusion;
    std::bitset<32> premiere_adresse_util;
    std::bitset<32> derniere_adresse_util;

    int nb_bit_adr_hote;
    int nb_hotes;

    // Boucle de gestion du menu
    int fin = 0;
    while (fin == 0)
    {
        switch (afficher_menu())
        {
        // --------------- Résoudre une adresse IP --------------- //
        case 1:

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

            // convertion pour masque sous réseau
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
            cout << ad3 << c << ad2 << c << ad1 << c << ad0 << endl;

            cout << "\033[0;33mVotre masque (binaire) = \033[0m";
            cout << mas3 << c << mas2 << c << mas1 << c << mas0 << endl;
            cout << endl;
            // Affichage partie réseau NETID
            cout << "\033[1;31m=======NETID=======\033[0m" << endl;
            cout << "\033[0;33mPartie reseau (netid binaire) = \033[0m";
            cout << add_res3 << c << add_res2 << c << add_res1 << c << add_res0 << endl;

            cout << "\033[0;33mPartie reseau (netid decimal) = \033[0m";
            cout << convertion_bin_dec(add_res3) << c << convertion_bin_dec(add_res2) << c << convertion_bin_dec(add_res1) << c << convertion_bin_dec(add_res0) << endl;
            cout << endl;
            // Affichage partie réseau HOSTID
            cout << "\033[1;31m=======HOSTID=======\033[0m" << endl;
            cout << "\033[0;33mPartie machine (hostid binaire) = \033[0m";
            cout << add_hote3 << c << add_hote2 << c << add_hote1 << c << add_hote0 << endl;

            cout << "\033[0;33mPartie machine (hostid decimal) = \033[0m";
            cout << convertion_bin_dec(add_hote3) << c << convertion_bin_dec(add_hote2) << c << convertion_bin_dec(add_hote1) << c << convertion_bin_dec(add_hote0) << endl;
            cout << endl;

            break;

        case 2:

            // Saisie de l'adresse IP réseau et du masque
            cout << "\033[1;31mEntrez une adresse IP reseau : \033[0m" << endl;
            cin >> adresse_ip;
            cout << "\033[1;31mEntrez le masque de sous-reseau : \033[0m" << endl;
            cin >> masque_ip;
            cout << endl;

            // Découpage en mémoire de l'adresse IP
            iss1 = istringstream(adresse_ip);
            iss1 >> i3 >> c >> i2 >> c >> i1 >> c >> i0;

            // Découpage en mémoire du masque
            iss2 = istringstream(masque_ip);
            iss2 >> m3 >> c >> m2 >> c >> m1 >> c >> m0;

            // Conversion des parties de l'adresse IP et du masque en chaînes binaires
            adresse_ip_bits = (i3 << 24) | (i2 << 16) | (i1 << 8) | i0 + 1;
            masque_bits = (m3 << 24) | (m2 << 16) | (m1 << 8) | m0;

            // Calculs sur l'adresse IP et le masque
            nb_bit_adr_hote = 32 - masque_bits.count();
            nb_hotes = std::pow(2, nb_bit_adr_hote) - 2;

            adresse_diffusion = adresse_ip_bits | (~masque_bits);
            
            // ATTENTION ERREUR SUR LA PREMIERE ADRESSE SUR CERTAINS CALCULS
            premiere_adresse_util = adresse_ip_bits;
            premiere_adresse_util.set(31, 1);
            
            // Affichage des résultats
            cout << "\033[1;31m=======Plage d'adresses=======\033[0m" << endl;
            cout << "\033[0;33mPlage d'adresses possibles : \033[0m";
            cout << ((premiere_adresse_util.to_ulong() >> 24) & 0xFF) << "."
                 << ((premiere_adresse_util.to_ulong() >> 16) & 0xFF) << "."
                 << ((premiere_adresse_util.to_ulong() >> 8) & 0xFF) << "."
                 << (premiere_adresse_util.to_ulong() & 0xFF);

            cout << " - "
                 << ((adresse_diffusion.to_ulong() >> 24) & 0xFF) << "."
                 << ((adresse_diffusion.to_ulong() >> 16) & 0xFF) << "."
                 << ((adresse_diffusion.to_ulong() >> 8) & 0xFF) << "."
                 << (adresse_diffusion.to_ulong() & 0xFF) - 1 << endl;

            cout << "\033[0;33mAdresse de diffusion : \033[0m"
                 << ((adresse_diffusion.to_ulong() >> 24) & 0xFF) << "."
                 << ((adresse_diffusion.to_ulong() >> 16) & 0xFF) << "."
                 << ((adresse_diffusion.to_ulong() >> 8) & 0xFF) << "."
                 << (adresse_diffusion.to_ulong() & 0xFF) << endl;

            cout << "\033[1;31m=======Nombre de machines possibles=======\033[0m" << endl;
            cout << "\033[0;33mNombre de machines possibles : \033[0m" << nb_hotes << endl;

            break;

        case 0:
            fin = 1;
            break;
        }
    }

    return 0;
}
