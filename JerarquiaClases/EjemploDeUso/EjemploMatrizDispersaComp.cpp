//////////////////////////////////////////////////////////////////////////////////////////////
// Programa para usar la clase de matriz bandada                                            //
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
#include "MatrizDispersaComp.hpp"



int main(void)
{
   int i, j, inc = 100000;
   ldouble a=0;             // Inicio dominio
   ldouble c=1;             // Fin dominio

   for (i=inc; i <= inc*30; i+=inc)
   {
      printf("\n\nMatriz de %dx%d\n",i,i);
      MatrizDispersaComp *A = new MatrizDispersaComp(i,i,3,"A");
      
      ldouble h=(c-a)/(i-1);   // Incremento en la malla
      ldouble P=2/(h*h);
      ldouble Q=-1/(h*h)+1/(2*h);
      ldouble R=-1/(h*h)-1/(2*h);
      
      // LLena la matriz
      A->asigna(0,0,P);
      A->asigna(0,1,Q);
      for(j=1;j < i-1;j++) 
      {
        A->asigna(j,j-1,R);
        A->asigna(j,j,P);
        A->asigna(j,j+1,Q);
      }
      A->asigna(i-1,i-2,R);
      A->asigna(i-1,i-1,P);
      //A->visualizaMatricesInternas();
      //A->visualiza(0);
      
      delete A;
   }
   
   
   return 0;
}
