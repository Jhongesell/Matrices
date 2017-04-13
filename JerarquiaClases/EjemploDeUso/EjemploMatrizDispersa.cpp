//////////////////////////////////////////////////////////////////////////////////////////////
// Programa para usar la clase de matriz Dispersa                                           //
//                                                                                          //
// An�lisis y Dise�o y Programaci�n:                                                        //
//                                                                                          //
// Nombre:   Antonio Carrillo Ledesma                                                       //
// E-mail:   acl@www.mmc.igeofcu.unam.mx                                                    //
// P�gina:   http://www.mmc.igeofcu.unam.mx/acl                                             //
//                                                                                          //
//                                                                                          //
// Este programa es software libre. Puede redistribuirlo y/o modificarlo                    //
// bajo los t�rminos de la Licencia P�blica General de GNU seg�n es                         //
// publicada por la Free Software Foundation, bien de la versi�n 2 de                       //
// dicha Licencia o bien (seg�n su elecci�n) de cualquier versi�n                           //
// posterior.                                                                               //
//                                                                                          //
// Este programa se distribuye con la esperanza de que sea �til, pero SIN                   //
// NINGUNA GARANT�A, incluso sin la garant�a MERCANTIL impl�cita o sin                      //
// garantizar la CONVENIENCIA PARA UN PROP�SITO PARTICULAR. V�ase la                        //
// Licencia P�blica General de GNU para m�s detalles.                                       //
//                                                                                          //
// Deber�a haber recibido una copia de la Licencia P�blica General junto                    //
// con este programa. Si no ha sido as�, escriba a la Free Software                         //
// Foundation, Inc., en 675 Mass Ave, Cambridge, MA 02139, EEUU.                            //
//                                                                                          //
//                                                                                          //
//////////////////////////////////////////////////////////////////////////////////////////////



#include "Definiciones.hpp"
#include "MatrizDispersa.hpp"


int main(void)
{
   int i, j, k, xcol;

   const int TAM = 5;
   ldouble A[TAM][TAM] = {
     {0.2,0.0,0.0,0.0,1.0},
     {0.1,0.0,1.0,0.0,1.0},
     {0.0,1.0,6.0,1.0,0.0},
     {0.0,0.0,1.0,8.0,4.0},
     {2.9,0.0,0.0,0.0,7.0}
   }; 
   
   MatrizDispersa *a = new MatrizDispersa(TAM,TAM,3,"A");
   for (i = 0; i < TAM; i++) a->convierte(A[i],i,TAM);

   a->visualiza(0);
   a->visualizaMatricesInternas();
     
   Vector *c = new Vector(TAM,"c");
   Vector *b = new Vector(TAM,1.0);
   a->multiplica(b,c);
   c->visualiza(1);
   
   
   delete b;
   delete c;

   delete a;
   
   return 0;
}
