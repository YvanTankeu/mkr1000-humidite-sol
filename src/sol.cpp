// 03 Includes pour faire fonctionner le rtc
#include <SPI.h>
#include <Wire.h>
#include "RTClib.h" 
#include "sol.hpp"

RTC_DS3231 rtc;
DateTime now = rtc.now();

// -----------------------------------------------------------------------------------------------------------------------
// -------------------------- Implémentation des Fonctions du sol --------------------------------------------------
// -----------------------------------------------------------------------------------------------------------------------

/**
 * @brief Construit un nouveau objet de la classe sol
 * 
 * @param humidite valeur d'humidité du sol
 * @param unixTime date du jour 
 */
Plante::Sol(unsigned int humidite, String unixTime, )
                :   humidite_(humidite), unixTime_(unixTime){}

/**
 * Retourne le taux d'humidité du sol
 * @return humidite_
 */
unsigned int Sole::humidite() const{
    return humidite_;
}

/**
 * Retourne la date du jour en format unixtime
 * @return mot de passe
 */
String Plante::unixTime() const{

    return  String(now.unixTime(), DEC) " ;
}


void Plante::initDateTime(){
      if (! rtc.begin()) {
    Serial.println("N'a pas pu trouver le RTC");
    Serial.flush();
    while (1) delay(10);
  }

  if (rtc.lostPower()) {
    Serial.println("Le RTC a perdu de l'énergie, remettons l'heure à jour !");
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }

}