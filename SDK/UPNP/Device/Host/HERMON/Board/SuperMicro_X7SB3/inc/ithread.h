
#ifndef ITHREADH
#define ITHREADH
#ifdef __cplusplus
extern "C" {
#endif


#ifdef DEBUG
#define DEBUG_ONLY(x) x
#else
#define DEBUG_ONLY(x)
#endif

#include <pthread.h>
#include <unistd.h>

#define ITHREAD_MUTEX_FAST_NP PTHREAD_MUTEX_FAST_NP
#define ITHREAD_MUTEX_RECURSIVE_NP PTHREAD_MUTEX_RECURSIVE_NP
#define ITHREAD_MUTEX_ERRORCHECK_NP PTHREAD_MUTEX_ERRORCHECK_NP
#define ITHREAD_CANCELED PTHREAD_CANCELED
  
  

  typedef pthread_t ithread_t; 
  

  typedef pthread_attr_t ithread_attr_t;	



  typedef void * (*start_routine) (void *arg);

  

  typedef pthread_cond_t ithread_cond_t;



  typedef pthread_mutexattr_t ithread_mutexattr_t;	



  typedef pthread_mutex_t ithread_mutex_t;



  typedef pthread_condattr_t ithread_condattr_t;	


  
#define ithread_mutexattr_init pthread_mutexattr_init
  

#define ithread_mutexattr_destroy pthread_mutexattr_destroy
  
  

#define ithread_mutexattr_setkind_np pthread_mutexattr_setkind_np



#define ithread_mutexattr_getkind_np pthread_mutexattr_getkind_np

  

#define ithread_mutex_init pthread_mutex_init
  

#define ithread_mutex_lock pthread_mutex_lock
  


#define ithread_mutex_unlock pthread_mutex_unlock



#define ithread_mutex_destroy pthread_mutex_destroy

  

#define ithread_cond_init pthread_cond_init




#define ithread_cond_signal pthread_cond_signal



#define ithread_cond_broadcast pthread_cond_broadcast
  


#define ithread_cond_wait pthread_cond_wait
  


 
#define ithread_cond_timedwait pthread_cond_timedwait
  


#define ithread_cond_destroy pthread_cond_destroy



#define ithread_create pthread_create



#define ithread_cancel pthread_cancel
  


#define ithread_exit pthread_exit


#define ithread_get_current_thread_id pthread_self



#define ithread_self pthread_self


#define ithread_detach pthread_detach  


#define ithread_join pthread_join
  



#define isleep sleep


#define imillisleep(x) usleep(1000*x)



int pthread_mutexattr_setkind_np(pthread_mutexattr_t *attr, int kind);

#ifdef __cplusplus
}
#endif

#endif 
