
/*
legajo:102757   Dominguez Damian Email:d.dominguez@live.com.ar


teoria:


punto 1:

1_ la cola es un tipo de organizacion donde el orden se va dando por la llegada del registro,
la cola es del tipo primero en llegar , primero en salir. En cambio si bien la lista se puede organizar en base a
alguna variable dentro del registro y no presisamente por el orden de llegada. ademas que puede ser doblemente enlazada
para organizarse como el programador lo requiera.



punto 2:

2_ los comandos ddl son los referidos a la escritura de las bases de datos.
desntro de sql tenemos comandos como RENAME(renombrar un dato u objeto), TRUNCATE(eliminar datos o registros),
CREATE(crear datos, o registros, tablas, etc).



practica:

*/

#include <stdio.h>
#include <stdlib.h>
/*

1) Existe un archivo binario, “cliente.dat”, secuencial con la siguiente estructura:
int id, char n[30] , unsigned int tipo, int b(baja lógica b=0), que son los datos de un cliente,
donde cada bit del campo tipo representa alguna situación del cliente: el bit 5 en 1 significa que no tiene crédito
y el bit 4 en 1 que es deudor, etc.
 Crear una función que arme una pila con los registros que no sean deudores verificando que estén activos.
Realizar el main() con la llamada a dicha función y crear un archivo con los datos de la pila. No utilizar variables Globales
Enviar a Gustavo Viard: gviard_electronica@yahoo.com.ar
*/

typedef struct {
 int id;
 char n[30];
 insigned int tipo;
 int b;
}datos_t;
struct pila{
struct datos d;
struct pila *l;
}pila_t;

//void setPila(struct pila_t); esto es lo que yo puse mal
void crearPila (struct pila **l);

int main()
 {
  //void setpila(&p); esto es lo que yo puse mal
  crearPila(&p);
 
  struct pila *pila= NULL, *aux= NULL;
 
 
 
  //aux=(struct pila_t)malloc(sizeof(struct pila_t));esto es lo que yo puse mal
 
 if((pf=fopen("activos.dat","wb"))==NULL)
        {
            printf("no se puede abrir el archivo");
            return ;
        }
 
  // if(aux==NULL)
  // {
  // printf("\n no hay memoria disponible \n");
  // return 0;
  // }
  // setPila(&pila);
  // while(pila)
 while(p)
  {
  //printf("\n%d %s %d %d\n",pila->id,pila->n,pila->)tipo,pila->b);
  //aux=pila;
  //pila=pila->1;
  //free(aux);
       aux=p;
       fwrite(&p,sizeof(struct datos),1,pf);
       p=p->l;
       free(aux);
}
 
//return 0;
  fclose(pf);
}


//void setPila(struct pila_t)
void crearPila (struct pila **l)
{
//struct datos pl;
//struct pila *aux;
 struct pila *aux;
 struct datos bf;
 FILE *fp;
 
if((fp=fopen("paciente.dat","wb"))==NULL)
{
printf("\n error en la lectura \n");
  return 0;
}
 
 
//fread(&pl,sizeof(datos_t),1,fp);
while(p)
{
//if(pl.b!=0)
//{
//if((pl.tipo & 0x10)==0x00) // busco bit 4 en cero 0001 0000 /////////////////////////
//{
//aux=(struct pila*) malloc(sizeof(struct pila));
//if(aux)
//{
aux= pila;
 //pila= pila->l;
 fwrite(&p,sizeof(struct datos),1,pf);
 p=p->l;
 free(aux);
//pila=aux;
}
fclose(aux);     


}

void crearPila (struct pila **l)
{
    struct pila *aux;
    struct datos bf;
    FILE *fp;

    if((fp=fopen("clientes.dat","rb"))==NULL)
        {
            printf("no se puede abrir el archivo");
            return ;
        }

    fread(&bf,sizeof(struct datos),1,fp);
    while(!feof(fp))
    {
        if(bf.b!=0 && !(bf.tipo & 0x10))
        {
            aux=(struct pila *) malloc (sizeof(struct pila));
            aux->d=bf;
            aux->l=p;
            p=aux;
        }
    }
    fclose(fp);
}

//fin de parcial
