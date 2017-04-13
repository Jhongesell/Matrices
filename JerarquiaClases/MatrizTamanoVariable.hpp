//////////////////////////////////////////////////////////////////////////////////////////////
// Clase para el trabajar con matrices de tama�o variable                                   //
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



#ifndef __MatrizTamanoVariable__
#define __MatrizTamanoVariable__


#include "Matriz_Base.hpp"


/// Clase para el trabajar con matrices de tama�o variable
/** @author Antonio Carrillo Ledesma
    @date primavera 2010
    @version 1.0.0
    @bug No hay errores conocidos
*/
class MatrizTamanoVariable : public Matriz_Base
{
private:

   /// Solicita la memoria necesaria para contener los valores de la matriz
   /** @param ren N�mero de renglones de la matriz
       @param col N�mero de columnas en cada renglon de la matriz  */
   void solicitaMemoria(const int ren, const int *col);


   /// Puntero a la matriz de datos
   ldouble **M;
   /// Arreglo que contiene el tama�o de los renglones de la matriz
   int *TC;


public:

   /// Constructor de la clase
   /** @param ren N�mero de renglones de la matriz
       @param col N�mero de columnas en cada renglon de la matriz */
   MatrizTamanoVariable(const int ren, const int *col)
   {
      solicitaMemoria(ren, col);
      asignaNombre("SinNombre");
   }

   /// Constructor de la clase
   /** @param ren N�mero de renglones de la matriz
       @param col N�mero de columnas en cada renglon de la matriz
       @param nmb Nombre de la matriz */
   MatrizTamanoVariable(const int ren, const int *col, const char *nmb)
   {
      solicitaMemoria(ren, col);
      asignaNombre(nmb);
   }

   ~MatrizTamanoVariable()
   {
      liberaMemoria();
   }

   /// Libera la memoria solicitada para la matriz
   void liberaMemoria(void);

   /// Inicializa la matriz al valor indicado
   /** @param val Valor por omisi�n para inicializar la matriz */
   void inicializa(ldouble val);

#ifdef DEPURAR
   /// Asigna el valor indicado en el renglo y columna solicitado
   /** @param ren Renglon
       @param col Columna
       @param val Valor */
   void asigna(const int ren, const int col, const ldouble val);

   /// Retorna valor almacenado en el renglon y la columna indicada
   /** @param ren N�mero de renglon
       @param col N�mero de columna
       @return Valor almacenado en el renglon y la columna indicada  */
   ldouble retorna(const int ren, const int col);
#else
   /// Asigna el valor indicado en el renglo y columna solicitado
   /** @param ren Renglon
       @param col Columna
       @param val Valor */
   void asigna(const int ren, const int col, const ldouble val)
   {
      M[ren][col] = val;
   }

   /// Retorna valor almacenado en el renglon y la columna indicada
   /** @param ren N�mero de renglon
       @param col N�mero de columna
       @return Valor almacenado en el renglon y la columna indicada  */
   ldouble retorna(const int ren, const int col)
   {
      return (M[ren][col]);
   }
#endif

   /// Retorna el tama�o del n�mero de columna para dicho renglon
   /** @param ren N�mero de renglon
       @return N�mero de columnas del renglon */
   inline int retornaNumeroColumna(int ren)
   {
      return ( TC[ren]);
   }

   /// Copia el contenido de la matriz a la matriz pasada como par�metro
   /** @param a Puntero a una Matriz */
   void copia(MatrizTamanoVariable *a);

   /// Visualiza las matrices internas usadas para soportar a las matrices de tama�o variable
   void visualizaMatricesInternas(void);

   /// Retorna el m�ximo tama�o en todas las columnas que sean distintos de cero
   /** @return M�ximo tama�o de columnas ocupadas en la matriz */
   int maximoTamanoColumnaOcupado(void);

   /// Retorna el n�mero de entradas distintas de cero en la matriz
   /** @return N�mero de entradas distintas de cero en la matriz */
   int entradasDistintasCero(void);

};


/**
Esta clase implementa los componentes para el trabajar con matrices de Tama�o variable
@example EjemploTamanoVariable.cpp */

#endif
