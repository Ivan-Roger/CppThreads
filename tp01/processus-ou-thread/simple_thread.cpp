#include <iostream>
#include <thread>
#include <unistd.h>  //pour getpid()
#include <sys/syscall.h> //pour syscall()

using namespace std;

static void ma_fonction (void)
{
  cout << "Je suis le thread " << this_thread::get_id()
       << " de tid " << syscall(SYS_gettid)
       << ", thread de " << getpid()
       << " fils de " << getppid() << endl;

}

int main (void)
{

  thread mon_thread(ma_fonction);

  // attente du thread
	mon_thread.join();

  cout << "Je suis le thread " << this_thread::get_id()
       << " de tid " << syscall(SYS_gettid)
       << ", thread de " << getpid()
       << " fils de " << getppid() << endl;

  return EXIT_SUCCESS;
}
