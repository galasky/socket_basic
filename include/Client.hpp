#ifndef	__CLIENT_HPP__
#define	__CLIENT_HPP__

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

class	Client
{
 public:

  Client(const char *ip);
  ~Client();
  std::string	input();
  void		output(std::string str);
  void		end();

 private:

  SOCKET                sock;
  struct hostent        *hostinfo;
  SOCKADDR_IN           sin;
  const char            *hostname;
  char                  buffer[1024];
  int                   n;
  int	PORT;
};

#endif/*__CLIENT_HPP__*/
