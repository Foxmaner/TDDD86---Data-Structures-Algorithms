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
    150       0.027         0.013
    200       0.073         0.070
    300       0.240         0.084
    400       0.610         0.125
    800       4.144         0.536
   1600      31.789         1.489
   3200                     6.343
   6400                     28.397
   12800                    108.691


/**********************************************************************
 *  Teoretisk   Ge ordo-uttryck f�r v�rstafallstiden f�r programmen som
 *  analys      en funktion av N. Ge en kort motivering.
 *
 **********************************************************************/

Brute: Är O(N⁴)eftersom att när programmet itererar gör den det med 4
loopar i varandra, där varje loop går upp till N.

Sortering:
fast: ÄR O(N²*logn) eftersom att när programmet itererar gör den det med 2
loppar med storleken N och en till lopp som är försumbar för den blir en
konstant.
