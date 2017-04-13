//////////////////////////////////////////////////////////////////////////////////////////////
// Clase para el trabajar con matrices con entradas enteras                                 //
//                                                                                          //
// An�lisis y Dise�o y Programaci�n:                                                        //
//                                                                                          //
// Nombre:   Antonio Carrillo Ledesma                                                       //
// E-mail:   acl@www.mmc.geofisica.unam.mx                                                  //
// P�gina:   http://www.mmc.geofisica.unam.mx/acl                                           //
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



#ifndef __MatrizInt__
#define __MatrizInt__

#include "Matriz_Base.hpp"


/// Clase para el trabajar con matrices con etradas enteras
/** @author Antonio Carrillo Ledesma
    @date primavera 2009
    @version 1.0.1
    @bug No hay errores conocidos
*/
class MatrizInt: public Matriz_Base
{
protected:

   /// Puntero al contenido de la matriz
   int **M;

   /// Libera la memoria solicitada para la matriz
   void liberaMemoria(void);


public:

   /// Constructor de la clase
   /** Genera una matriz del tama�o expecificado por el n�mero renglones y de columnas e inicializado al valor indicado
      @param ren N�mero de renglones de la matriz
      @param col N�mero de columnas de la matriz
      @param nmb Nombre de la matriz
      @param val Valor por omisi�n para inicializar la matriz */
   MatrizInt(const int ren, const int col, const char *nmb, int val);

   /// Destructor de la clase
   ~MatrizInt()
   {
      liberaMemoria();
   }


   /// Inicializa la matriz al valor val indicado
   /** @param val Valor por omisi�n para inicializar la matriz */
   void inicializa(const int val);

   /// Retorna el valor del renglon y columna solicitado
   /** @param ren Renglon
       @param col Columna
       @return Valor */
   int operator() (size_t ren, size_t col)
   {
      return retorna(ren,col);
   }


#ifdef DEPURAR
   /// Asigna el valor indicado en el renglo y columna solicitado
   /** @param ren Renglon
       @param col Columna
       @param val Valor */
   void asigna(const int ren, const int col, const int val);

   /// Retorna el valor del renglon y columna solicitado
   /** @param ren Renglon
       @param col Columna
       @return Valor */
   int retorna(const int ren, const int col);
#else
   /// Asigna el valor indicado en el renglo y columna solicitado
   /** @param ren Renglon
       @param col Columna
       @param val Valor */
   inline void asigna(const int ren, const int col, const int val)
   {
      M[ren][col] = val;
   }

   /// Retorna el valor del renglon y columna solicitado
   /** @param ren Renglon
       @param col Columna
       @return Valor */
   inline int retorna(const int ren, const int col)
   {
      return M[ren][col];
   }
#endif

   /// Convierte el contenido del arreglo a en el renglon de la matriz indicado
   /** @param r Renglon
       @param arr Arreglo de tipo int
       @param tam Tama�o del arreglo */
   inline void asigna(int r, int *arr, int tam)
   {
      int i, t = Col < tam ? Col : tam;
      for (i = 0; i < t; i++) M[r][i] = arr[i];
   }

   /// Retorna el contenido del renglon indicado en un arreglo
   /** @param r Renglon
       @param arr Arreglo de tipo int
       @param tam Tama�o del arreglo */
   inline void retorna(int r, int *arr, int tam)
   {
      int i, t = Col < tam ? Col : tam;
      for (i = 0; i < t; i++) arr[i] = M[r][i];
   }

   /// Retorna el m�ximo tama�o en todas las columnas que sean distintos de cero
   /** @return M�ximo tama�o de columnas ocupadas en la matriz */
   int  maximoTamanoColumnaOcupado(void);

   /// Retorna el n�mero de entradas distintas de cero en la matriz
   /** @return N�mero de entradas distintas de cero en la matriz */
   int entradasDistintasCero(void);

   /// Retornal el numero de columnas del renglon indicado distintas del valor especificado
   /** @param ren Renglon
       @param val Valor
       @return Numero de columnas distintas del valor especificado  */
   int columnasDistintasDeValor(int ren, int val)
   {
      int i, sw = 0;
      for (i = 0; i < Col; i++)
      {
         if (M[ren][i] != val) sw ++;
      }
      return sw;
   }

   /// Visualiza la matriz
   void visualiza(void);

};

#endif

