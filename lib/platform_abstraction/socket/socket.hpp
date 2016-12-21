#ifndef SOCKET_HPP
#define SOCKET_HPP

#include <cstdint>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>

#include <string>
#include <iostream>

#include "socket_address.hpp"

class Socket{
public:
  Socket():fd(-1){
    if(init() == false){
      handleFailure();
    }
  }

  ~Socket(){
    if(fd >= 0) {close(fd);}
  }

  //! Send message to port

  //! \param address - ip address of destination
  //! \return true if successful, false otherwise
  bool send(std::string address, uint16_t port, std::string message){

    if(fd < 1){ handleFailure(); }

    SocketAddress addr(address, port);
    struct sockaddr_in saddr = addr.to_sockaddr_in();
    int8_t result = sendto(
      fd,
      message.c_str(),
      strlen(message.c_str()),
      0,
      (struct sockaddr *) &saddr,
      sizeof(saddr)
    );

    if(result == -1) {
      handleFailure();
      return false;
    }
    return true;
  }

protected:
  bool init(){
    if ( (fd=socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == -1){
      return false;
    }
    return true;
  }

  void handleFailure(){
    // TODO not sure how to die just yet :)
    std::cout << "Socket Failure" << std::endl;
    exit(1);
  }

  int32_t fd;
};

#endif