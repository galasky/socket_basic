#include <iostream>
#include <stdlib.h>
#include "Serveur.hpp"
#include "Client.hpp"

void	its_client(const char *ip)
{
  Client c(ip);
  std::string str;

  while (true)
    {
      c.output("renvoi cette phrase");
      str = c.input();
      std::cout << str << std::endl;
      usleep(1000000);
    }
}

void	its_serveur()
{
  Serveur s;
  std::string str;

  while (true)
    {
      str = s.input();
      std::cout << str << std::endl;
      s.output(str);
    }
}

int	main(int ac, char **av)
{
  if (ac >= 2)
    its_client(av[1]);
  else
    its_serveur();
  return (0);
}
