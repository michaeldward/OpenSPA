
#ifndef PHYSICAL_COMMUNICATOR_HPP
#define PHYSICAL_COMMUNICATOR_HPP

#include "logical_address.hpp"
#include "spa_message.hpp"

class PhysicalCommunicator
{
public:
  typedef void (*MessageCallback)(uint8_t *, uint32_t);

  PhysicalCommunicator(LogicalAddress la) : subnetAddress(la) {}

  virtual ~PhysicalCommunicator() {}
  virtual bool sendMsg(std::shared_ptr<SpaMessage> message) { return false; }
  virtual void listen(PhysicalCommunicator::MessageCallback) {}

  virtual LogicalAddress getSubnetAddress() { return subnetAddress; }

  LogicalAddress subnetAddress;
};
#endif
