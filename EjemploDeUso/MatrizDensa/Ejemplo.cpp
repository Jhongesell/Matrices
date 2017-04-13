//////////////////////////////////////////////////////////////////////////////////////////////
// Programa para usar la clase de matriz densa                                              //
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
#include "MatrizDensa.hpp"


int main(void)
{
   int i;

   const int TAM = 5;
   ldouble A[][TAM] = {
     {0.2,0.1,1.0,1.0,0.0},
     {0.1,4.0,-1.0,1.0, -1.0},
     {1.0,-1.0,60.0,0.0,-2.0},
     {1.0,1.0,0.0,8.0,4.0},
     {0.0,-1.0,-2.0,4.0,700.0}
   }; 

   MatrizDensa b(100,100,"B");
   
   MatrizDensa *a = new MatrizDensa(TAM,TAM,"A");
   for (i = 0; i < TAM; i++) a->convierte(A[i],i,TAM);
   a->visualiza(0);
   
   b.redimensiona(TAM,TAM);
   a->copia(&b);
   b.visualiza(0);
   
   printf("\n%lf\n",b(0,0));
   
   MatrizDensa c(b);
   c.visualiza(0);
   
   delete a;

   return 0;
}
