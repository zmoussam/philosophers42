/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 15:15:22 by zmoussam          #+#    #+#             */
/*   Updated: 2022/08/19 16:52:04 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <pthread.h>
// #if defined (Win32)
// #  include <windows.h>
// #  define psleep(sec) sleep ((sec) * 1000)
// #elif defined (Linux)
// #  include <unistd.h>
// #  define psleep(sec) sleep ((sec))
// #endif

#define INITIAL_STOCK   20
#define NB_CLIENTS      5
#include <stdio.h>
#include <string.h>
#include<unistd.h>

/* Structure stockant les informations des threads clients et du magasin. */
typedef struct
{
   int stock;
   pthread_t thread_store;
   pthread_t thread_clients [NB_CLIENTS];
}
store_t;

static store_t store =
{
   .stock = INITIAL_STOCK,
};
/* Fonction pour tirer un nombre au sort entre 0 et max. */
static int get_random (int max)
{
   double val;
  val = (double) max * rand ();
   val = val / (RAND_MAX + 1.0);
   return ((int) val);
}
/* Fonction pour le thread du magasin. */
static void * fn_store (void * p_data)
{
   while (1)
   {
      if (store.stock <= 0)
      {
         store.stock = INITIAL_STOCK;
         printf ("Remplissage du stock de %d articles !\n", store.stock);
      }
   }
   return NULL;
}
/* Fonction pour les threads des clients. */
static void * fn_clients (void * p_data)
{
   int nb = (int) p_data;
   while (1)
   {
      int val = get_random (6);
      sleep (get_random (3));
      if(store.stock >= val)
      {
      store.stock = store.stock - val;
      printf (
         "Client %d prend %d du stock, reste %d en stock !\n",
         nb, val, store.stock
      );
          
      }
   }
   return NULL;
}

int main (void)
{
   int i = 0;
   int ret = 0;
   /* Creation du thread du magasin. */
   printf ("Creation du thread du magasin !\n");
   ret = pthread_create (
      & store.thread_store, NULL,
      fn_store, NULL
   );
   /* Creation des threads des clients si celui du magasin a reussi. */
   if (! ret)
   {
      printf ("Creation des threads clients !\n");
      for (i = 0; i < NB_CLIENTS; i++)
      {
         ret = pthread_create (
            & store.thread_clients [i], NULL,
            fn_clients, (void *)i
         );
         if (ret)
         {
            fprintf (stderr, "%s", strerror (ret));
         }
      }
   }
   else
   {
      fprintf (stderr, "%s", strerror (ret));
   }  
   /* Attente de la fin des threads. */
   i = 0;
   for (i = 0; i < NB_CLIENTS; i++)
   {
      pthread_join (store.thread_clients [i], NULL);
   }
   pthread_join (store.thread_store, NULL);
   return EXIT_SUCCESS;
}
/* semaphore */
/*
#include <semaphore.h>\
int sem_init(sem_t *sem, int pshared, unsigned int value);
int sem_destroy(sem_t *sem);
int sem_wait(sem_t * sem);
int sem_post(sem_t * sem);
int sem_trywait(sem_t * sem);
int sem_getvalue(sem_t * sem, int * sval);
*/