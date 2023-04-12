#include <unistd.h>
#include <error.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

#define MAXDELAY_S     2      // Maximum execution time in seconds
#define ERRORTHR      50      // between 0-100, the higher the threshold, the higher the error chance

#define HALFDELAY_US	((MAXDELAY_S/2)*1000000)    // microseconds (1 s=10^6 microseconds)

long
compute_sum (int fd)
{
  long int sum = 0, current = 0;
  char c;
  int n;

  while ((n = read (fd, &c, 1)) > 0)
    {
      if (c == '\n')
        {
          sum += current;
          current = 0;
        }
      else if ((c < '0') || (c > '9'))
        error (1, 0, "Unexpected char");
      else
        current = 10 * current + (c - '0');
    }
  if (n < 0)
    error (1, errno, "Reading");

  sum += current;
  return (sum);
}

int
main (int argc, char *argv[])
{
  int fd;
  char s[80];

  if (argc != 2)
    error (1, 0, "Wrong parameters");

  fd = open (argv[1], O_RDONLY);
  if (fd < 0)
    error (1, errno, "Open input file");

  sprintf (s, "%d : %ld\n", getpid (), compute_sum (fd));

  // Init random generator
  srand (getpid ());

  // Random abort (non zero exit code)
  int errpercent = rand () % 101;
//  fprintf(stderr, "%d:%d\n", getpid(), errratio);
  if (errpercent <= ERRORTHR)
    {
      // Random delay (up to HALFDELAY_US) and exit code
      usleep (rand () % HALFDELAY_US);
      exit (1 + rand () % 9);
    }

  // Random abort (non handled signal)
  int signalpercent = rand () % 101;
  if (signalpercent <= ERRORTHR)
    {
      int signals[] =
        { SIGUSR1, SIGINT, SIGUSR2, SIGPIPE, SIGSEGV, SIGKILL, SIGALRM };
      int idx = rand () % (sizeof (signals) / sizeof (int));

      // Random delay (up to HALFDELAY_US) and signal
      usleep (rand () % HALFDELAY_US);
      kill (getpid (), signals[idx]);
      error (1, 0, "Unexpected error");
    }

  // Random delay (from HALFDELAY_US to 2*HALFDELAY_US)
  long delay = HALFDELAY_US + (rand () % HALFDELAY_US);
//  fprintf(stderr, "%d:%ld\n", getpid(), delay);
  usleep (delay);

  // Write result
  if (write (1, s, strlen (s)) < 0)
    error (1, errno, "write");

  exit(0);
}
