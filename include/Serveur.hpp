#ifndef	__SERVEUR_HPP__
#define	__SERVEUR_HPP__

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

#define INVALID_SOCKET -1
#define SOCKET_ERROR -1
#define closesocket(s) close(s)

typedef         int SOCKET;
typedef struct  sockaddr_in SOCKADDR_IN;
typedef struct  sockaddr SOCKADDR;
typedef struct  in_addr IN_ADDR;

class	Serveur
{
public:
  Serveur();
  ~Serveur();
  std::string	input();
  void		output(std::string);
  void		end();

private:
  SOCKET                sock;
  SOCKET                csock;
  struct hostent        *hostinfo;
  SOCKADDR_IN           sin;
  SOCKADDR_IN           csin;
  char                  buffer[1024];
  int                   n;
  int                   sinsize;
  int	PORT;
};

#endif/*__SERVEUR_HPP__*/
