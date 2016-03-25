#include <iostream>
#include <thread>
#include <vector>
#include <unistd.h>  //pour getpid()
#include <sys/syscall.h> //pour syscall()

using namespace std;

static void ma_fonction(void)
{
  cout << "Je suis le thread " << this_thread::get_id()
       << " de tid " << syscall(SYS_gettid)
       << ", thread de " << getpid()
       << " fils de " << getppid() << endl;
}

int main(int argc, char* argv[])
{
  if (argc != 2)
  {
    cerr << "Usage : " << argv[0] << " nb_threads" << endl;
    throw;
  }

  unsigned long nb_threads = stoul(argv[1]);

  // création des threads
  vector<thread> mes_threads;
	for (unsigned long i=0; i<nb_threads; i++) {
		mes_threads.push_back(thread(ma_fonction));
	}

  // attente des threads
	for (unsigned long i=0; i<nb_threads; i++) {
		mes_threads.at(i).join();
	}

  cout << "Je suis le thread " << this_thread::get_id()
       << " de tid " << syscall(SYS_gettid)
       << ", thread de " << getpid()
       << " fils de " << getppid() << endl;

  return EXIT_SUCCESS;
}
