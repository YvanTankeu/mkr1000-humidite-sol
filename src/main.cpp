/*
  Titre      : Taux dhumidite du sol avec django
  Auteur     : Yvan Tankeu
  Date       : 14/10/2022
  Description: Determiner le taux dhumidite du sol
    # Description de la valeur du capteur
    # 00~300 sol sec
    # 300~700 sol humide
    # 700~950 dans l'eau
  Version    : 0.0.1
*/

#include "connect.hpp"
#include "sol.hpp"



// Identifiants du wifi
char* ssid = "Galaxi";
char* password = "12345678";

const int relaiLED = 33;
const unsigned long DELAI = 1000;
const unsigned int SEUIL_HUMIDITE = 300;

String actualDate = "";

Plante unePlante;

//Déclaration de variables
unsigned int soilHumidity = 0;

WebServer server(80);
Serveur unServeur;

/*
 * setup function
 */

void setup () {
  Serial.begin(9600);

  unePlante.initDateTime();

  Connect connect(ssid, password);
  // Attendre la connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connecter à ");
  Serial.println(ssid);
  Serial.print("Address IP: ");
  Serial.println(WiFi.localIP());
}

void loop () {
  // Recupère la date et l'heure
  actualDate = unePlante.date() + unePlante.heure();

  server.handleClient();

  // Code valeur du capteur d'humidité du sol
  soilHumidity = unePlante.getSoilHumidityVal(A0);
  Serial.println(soilHumidity);

  delay(DELAI);
}
