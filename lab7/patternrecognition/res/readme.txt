/**********************************************************************
 *  M�nsterigenk�nning readme.txt
 **********************************************************************/

/**********************************************************************
 *  Empirisk    Fyll i tabellen nedan med riktiga k�rtider i sekunder
 *  analys      n�r det k�nns vettigt att v�nta p� hela ber�kningen.
 *              Ge uppskattningar av k�rtiden i �vriga fall.
 *
 **********************************************************************/
    
      N       brute       sortering
 ----------------------------------
    150       0.027
    200       0.073
    300       0.240
    400       0.610
    800       4.144
   1600      31.789
   3200        ?    
   6400        ?
  12800        ?


/**********************************************************************
 *  Teoretisk   Ge ordo-uttryck f�r v�rstafallstiden f�r programmen som
 *  analys      en funktion av N. Ge en kort motivering.
 *
 **********************************************************************/

Brute: Är O(N⁴)eftersom att när programmet itererar gör den det med 4
loopar i varandra, där varje loop går upp till N.

Sortering:
