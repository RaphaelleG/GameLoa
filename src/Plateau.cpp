#include "Plateau.hpp"


Plateau::Plateau(string chemin)
{
    ifstream fichier(chemin); // ouverture en mode lecture

    // si le fichier est ouvert
    if (fichier)
    {
        char c;
        // on récupère la taille du fcihier pour savoir quand on arrive à la fin
        fichier.seekg(0, ios::end);
        int taille = fichier.tellg();
        fichier.seekg(0, ios::beg);

        while(fichier.tellg() != taille)
        {
            vector<Case> v;

            while(c!='\n')
            {
                fichier.get(c);
                switch(c)
                {
                  case ' ': // vide
                    v.push_back(Case());
                    break;

                  case 'X': // mur
                    v.push_back(Mur());
                    break;

                  case '-': // porte
                    v.push_back(Porte());
                    break;

                  case '$': // diamant
                    v.push_back(Diamant());
                    break;

                  case '*': // chargeur
                    v.push_back(Chargeur());
                    break;

                  case 'J': // joueur
                    v.push_back(Joueur());
                    break;

                  case 'm' : // monstre
                    v.push_back(Monstre());
                    break;

                  default :
                    break;
                }
            }
            c =' ';
            plateau.push_back(v);
        }
    }

    else
    {
        cout << "Prout" << endl;
    }
}

const Case& Plateau::getCase(int i, int j) const
{
  return plateau[i][j];
}

const Pion& Plateau::getJoueur() const
{
    for (size_t i = 0; i < plateau.size(); i++) {
        for (size_t j = 0; j < plateau[i].size(); j++) {
            if (plateau[i][j].getPion().getSymbole()== 'J')
                return plateau[i][j].getPion();
        }
    }
    // CECI N4EST PAS CENSÉ SE PRODUIRE !!!
    cout << "Joueur non trouvé" << endl;
    return plateau[0][0].getPion();
}



void Plateau::parseMouv(char c)
{
    int x = 0, y = 0;
    switch (c)
    {
        case 'a': // en haut à gauche
            x = -1;
            y = -1;
            break;
        case 'z': // en haut au milieu
            y = -1;
            break;
        case 'e': // en haut à droite
            x = 1;
            y = -1;
            break;
        case 'q': // à gauche
            x = -1;
            break;
        case 'd': // à droite
            x = 1;
            break;
        case 'w': // en bas à gauche
            x = -1;
            y = 1;
            break;
        case 'x': // en bas au milieu
            y = 1;
            break;
        case 'c' : // en bas à droite
            x = 1;
            y = 1;
            break;
        default:
            break;
    }

    for (size_t i = 0; i < plateau.size(); i++) {
        for (size_t j = 0; j < plateau[i].size(); j++) {
            if (plateau[i][j].getPion().getSymbole()== 'J')
            {
                int a = i + x;
                int b = j + y;
                plateau[i][j].getPion().moving(a, b, *this);
            }
        }
    }

}

ostream &operator<<(ostream &out, Plateau p)
{
    for (int i = 0; i < p.plateau.size(); i++)
    {
        for (int j = 0; j < p.plateau[i].size(); j++)
            out << p.plateau[i][j];
        out << endl;
    }
    return out;
}
