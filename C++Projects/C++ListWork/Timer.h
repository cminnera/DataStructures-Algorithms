#ifndef TIMERCLASS_H_INCLUDED
#define TIMERCLASS_H_INCLUDED
//=======================================================================
// The code from http://cplus.about.com/od/howtodothingsin1/a/timing.htm
#include <windows.h>

typedef struct {
    LARGE_INTEGER start;
    LARGE_INTEGER stop;
} stopWatch;

  void startTimer( stopWatch *timer) ;
  void stopTimer( stopWatch *timer) ;
  double LIToSecs( LARGE_INTEGER * L) ;
  double getElapsedTime( stopWatch *timer) ;

void startTimer( stopWatch *timer) {
    QueryPerformanceCounter(&timer->start) ;
}

void stopTimer( stopWatch *timer) {
    QueryPerformanceCounter(&timer->stop) ;
}

double LIToSecs( LARGE_INTEGER * L) {
    LARGE_INTEGER frequency;
    QueryPerformanceFrequency( &frequency ) ;
    return ((double)L->QuadPart /(double)frequency.QuadPart) ;
}

double getElapsedTime( stopWatch *timer) {
    LARGE_INTEGER time;
    time.QuadPart = timer->stop.QuadPart - timer->start.QuadPart;
    return LIToSecs( &time) ;
}
//========================================================================


#endif // TIMERCLASS_H_INCLUDED
