#include <component.hpp>
#include <iostream>
#include <local_communicator.hpp>
#include <messages/local/local_hello.hpp>

class ExampleComponent : public Component
{
public:
  ExampleComponent(Component::Com com = nullptr) : Component(com) {}

  virtual void appInit()
  {
    std::cout << "Example app initializing!" << '\n';

    uint8_t version = 0;
    uint8_t priority = 0;
    LogicalAddress destination(1,3);
    LogicalAddress source(1,2);
    uint16_t flags = 0;
    uint16_t sourcePort = 8888;
    uint64_t uuid = 1;
    uint8_t componentType = 1;

    auto message = std::make_shared<LocalHello>(
      version,
      priority,
      destination,
      source,
      flags,
      sourcePort,
      uuid,
      componentType
    );
    sendMsg(message);
  }
};

int main()
{
  uint16_t port = 8888;
  std::shared_ptr<ServerSocket> sock = std::make_shared<ServerSocket>();
  std::shared_ptr<RoutingTable> routingTable = std::make_shared<RoutingTable>();
  routingTable->insert(LogicalAddress(1, 3), 8888);

  LogicalAddress localAddress(1, 0);
  std::vector<SpaCommunicator::Com> comms = {
      std::make_shared<LocalCommunicator>(sock, routingTable, localAddress)};
  std::shared_ptr<SpaCommunicator> spaCom = std::make_shared<SpaCommunicator>(localAddress, comms);

  ExampleComponent comp(spaCom);
  comp.appInit();
  return 0;
}
