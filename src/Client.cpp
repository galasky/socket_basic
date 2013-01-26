#include "Client.hpp"

Client::Client(const char *ip)
{
  PORT = 4000;

  sin = { 0 };
  hostname = ip;
  n = 0;

  sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock == INVALID_SOCKET)
    {
      perror("socket()");
      exit(errno);
    }

  hostinfo = gethostbyname(hostname);
  if (hostinfo == NULL)
    {
      fprintf (stderr, "Unknown host %s.\n", hostname);
      exit(EXIT_FAILURE);
    }
  sin.sin_addr = *(IN_ADDR *) hostinfo->h_addr;
  sin.sin_port = htons(PORT);
  sin.sin_family = AF_INET;
  if (connect(sock,(SOCKADDR *) &sin, sizeof(SOCKADDR)) == SOCKET_ERROR)
    {
      perror("connect()");
      exit(errno);
    }
}

Client::~Client()
{
  closesocket(sock);
}

std::string	Client::input()
{
  std::string	str;

  if ((n = recv(sock, buffer, sizeof buffer - 1, 0)) < 0)
    {
      perror("recv()");
      exit(errno);
    }
  buffer[n] = '\0';
  str += buffer;
  return (str);
}

void	Client::output(std::string str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      buffer[i] = str[i];
      i++;
    }
  buffer[i] = '\0';

  if (send(sock, buffer, strlen(buffer), 0) < 0)
    {
      perror("send()");
      exit(errno);
    }
}

void	Client::end()
{
  closesocket(sock);
}
