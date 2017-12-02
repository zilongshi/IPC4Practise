AUTOMAKE_OPTIONS=foreign
bin_PROGRAMS = execprocesssemaphores execthreadsemaphores

execprocesssemaphores_SOURCES = process_semaphores.c ../sys/debug.c ../sys/debug.h
execprocesssemaphores_CPPFLAGS = -DDEBUG

execthreadsemaphores_SOURCES = thread_semaphores.c ../sys/debug.c ../sys/debug.h
execthreadsemaphores_CPPFLAGS = -DDEBUG

LIBS += -lpthread
