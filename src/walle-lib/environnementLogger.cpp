#include "environnementLogger.hpp"
#include "environnement.hpp"
#include "element.hpp"

#include <fstream>
#include <vector>
#include <iostream>
#include <sstream>

EnvironmentLogger::EnvironmentLogger(Environment *environment, const std::string &filename)
    : environment_(environment), filename_(filename) {}

void EnvironmentLogger::begin()
{
    // Ouvrir le fichier en mode écriture pour écraser le contenu existant et écrire la première accolade
    std::ofstream file(filename_, std::ios::trunc); // Mode écriture
    file << "[\n";                                  // Début du fichier JSON

    // Fermer le fichier
    file.close();
}

void EnvironmentLogger::log_state()
{
    std::ofstream file(filename_, std::ios::app); // Mode append

    if (!file.is_open())
    {
        std::cerr << "Error: Cannot open file " << filename_ << " for writing.\n";
        return;
    }

    // Récupérer les éléments de l'environnement
    const auto &elements = environment_->get_elements();

    // Commencer le formatage JSON
    file << "{\n";
    file << "  \"iteration\": " << iteration_ << ",\n";
    file << "  \"bounds\": {\n";
    file << "    \"left\": " << environment_->left() << ",\n";
    file << "    \"right\": " << environment_->right() << ",\n";
    file << "    \"top\": " << environment_->top() << ",\n";
    file << "    \"bottom\": " << environment_->bottom() << "\n";
    file << "  },\n";

    file << "  \"elements\": [\n";

    for (size_t i = 0; i < elements.size(); ++i)
    {
        const auto *element = elements[i];
        // Générer un id unique basé sur l'adresse mémoire
        uintptr_t element_id = reinterpret_cast<uintptr_t>(element);

        file << "    {\n";
        file << "      \"id\": " << element_id << ",\n";
        file << "      \"position_x\": " << element->get_position_x() << ",\n";
        file << "      \"position_y\": " << element->get_position_y() << ",\n";
        file << "      \"orientation\": " << element->get_orientation() << ",\n";
        file << "      \"size\": " << element->get_size() << "\n";

        if (i == elements.size() - 1)
        {
            file << "    }\n"; // Dernier élément sans virgule
        }
        else
        {
            file << "    },\n"; // Autres éléments avec une virgule
        }
    }

    file << "  ]\n";
    file << "},\n"; // Fin de l'itération

    file.close();

    // Incrémentation du time_step pour l'étape suivante (ou l'initialiser si nécessaire)
    ++iteration_;
}

void EnvironmentLogger::end()
{
    std::ofstream output_file(filename_, std::ios::app); // Mode append

    if (!output_file.is_open())
    {
        std::cerr << "Error: Cannot open file " << filename_ << " for writing.\n";
        return;
    }
    // Fermer le tableau JSON
    output_file << "\n]"; // Fermer le tableau JSON
    output_file.close();
}
