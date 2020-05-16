#ifndef ARRAYSECTOR_H_INCLUDED
#define ARRAYSECTOR_H_INCLUDED
typedef struct
{
   int idSector;
   char descripcion[20];
   int isEmpty;
}  eSector;


#endif // ARRAYSECTOR_H_INCLUDED

/** \brief Agrega sectores y su id al vector
 *
 * \param listaSector eSector*
 * \param lenSector int
 * \return int devuelve -1 si no pudo agregar datos y 1 si  pudo
 *
 */
int addSectors(eSector* listaSector,int lenSector);
/** \brief menu de sectores
 *
 * \param listaSector eSector*
 * \param lenSector int
 * \return int devuele la opcion elegida por el usuario
 *
 */
int menuSectors(eSector* listaSector,int lenSector);
/** \brief carga el nombre del sector segun el id del vector de empleados
 *
 * \param sectorName[] char
 * \param id int
 * \param listaSector eSector*
 * \param lenSector int
 * \return int
 *
 */
int loadSectorName(char sectorName[],int id,eSector* listaSector,int lenSector);
