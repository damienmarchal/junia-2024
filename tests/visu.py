import cv2
import json
import numpy as np

def load_json(filename):
    with open(filename, 'r') as f:
        return json.load(f)

def calculate_window_size(bounds, size=500):
    """Calcule la taille de la fenêtre en pixels en fonction des limites et du facteur d'échelle."""
    width = int((bounds['right'] - bounds['left']))
    height = int((bounds['bottom'] - bounds['top']))
    factor = size / max(width, height)
    width = int(width * factor)
    height = int(height * factor)
    
    return width, height, factor

def visualize_environment(data, delay=1):
    # Récupérer les limites initiales de l'environnement
    bounds = data[0]['bounds']
    width, height, factor = calculate_window_size(bounds)

    # Créer une fenêtre noire
    for iteration_data in data:
        iteration = iteration_data['iteration']
        elements = iteration_data['elements']

        # Créer une image vide pour chaque itération
        img = np.zeros((height, width, 3), dtype=np.uint8)

        # Pour chaque élément, dessiner un cercle
        for element in elements:
            # Convertir les coordonnées dans l'espace de la fenêtre
            x = int((element['position_x'] - bounds['left']) * factor)
            y = int((bounds['bottom'] - element['position_y']) * factor)  # Inverser Y pour afficher correctement
            size = int(element['size'] * factor)

            # Dessiner un cercle représentant l'élément
            cv2.circle(img, (x, y), size, (255, 0, 0), -1)  # Couleur rouge et rempli

        # Ajouter le numéro d'itération sur l'image
        cv2.putText(img, f"Iteration: {iteration}", (10, 30), cv2.FONT_HERSHEY_SIMPLEX, 1, (255, 255, 255), 2)

        # Afficher l'image dans une fenêtre
        cv2.imshow("Environment Visualization", img)

        # Pause pour afficher l'image pendant le délai
        key = cv2.waitKey(delay * 1)  # Convertir le délai en millisecondes
        if key == 27:  # Escape pour quitter
            break

    cv2.destroyAllWindows()

if __name__ == "__main__":
    filename = 'C:\\Users\\robin\\junia-2024\\build\\log.json'  # Remplacez par le chemin de votre fichier JSON
    data = load_json(filename)
    visualize_environment(data, delay=1)  # Ajustez le facteur d'échelle et le délai
