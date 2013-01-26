#include "Serveur.hpp"

Serveur::Serveur()
{
  PORT = 4000;

  sin = { 0 };
  csin = { 0 };
  n = 0;
  sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock == INVALID_SOCKET)
    {
      perror("socket()");
      exit(errno);
    }
  sin.sin_addr.s_addr = htonl(INADDR_ANY);
  sin.sin_family = AF_INET;
  sin.sin_port = htons(PORT);
  if (bind (sock, (SOCKADDR *) &sin, sizeof sin) == SOCKET_ERROR)
    {
      perror("bind()");
      exit(errno);
    }
  if (listen(sock, 5) == SOCKET_ERROR)
    {
      perror("listen()");
      exit(errno);
    }
  sinsize = sizeof(csin);
  csock = accept(sock, (SOCKADDR *)&csin, &sinsize);
  if (csock == INVALID_SOCKET)
    {
      perror("accept()");
      exit(errno);
    }
}

Serveur::~Serveur()
{
  closesocket(sock);
  closesocket(csock);
}

std::string	Serveur::input()
{
  std::string	str;

  if ((n = recv(csock, buffer, sizeof buffer - 1, 0)) < 0)
    {
      perror("recv()");
      exit(errno);
    }
  buffer[n] = '\0';
  str += buffer;
  return (str);
}

void	Serveur::output(std::string str)
{
  int   i;

  i = 0;
  while (str[i])
    {
      buffer[i] = str[i];
      i++;
    }
  buffer[i] = '\0';

  if (send(csock, buffer, strlen(buffer), 0) < 0)
    {
      perror("send()");
      exit(errno);
    }
}

void	Serveur::end()
{
  closesocket(sock);
  closesocket(csock);
}
