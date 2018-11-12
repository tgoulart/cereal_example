#include <fstream>

#include <cereal/archives/json.hpp>
#include <cereal/types/memory.hpp>
#include <cereal/types/polymorphic.hpp>
#include <cereal/types/unordered_map.hpp>
#include <cereal/types/vector.hpp>

#include "serialization.hpp"

#define ADD_COMPONENT(e, c) { e->_components.push_back(c); c->_owner = e; }

int main() {
  const std::string kFileName = "output.json";

  { // create and persist an object
    auto person = std::make_shared<Entity>();
    person->_guid = "joe";

    auto simpleComp = std::make_shared<SimpleComponent>();
    simpleComp->_someData = 11.2;

    auto complexComp = std::make_shared<ComplexComponent>();
    complexComp->_someData = 34.56;
    complexComp->_moreData = "hello!";

    ADD_COMPONENT(person, simpleComp);
    ADD_COMPONENT(person, complexComp);

    std::ofstream os(kFileName);
    cereal::JSONOutputArchive archive(os);
    archive(person);
  }

  { // load and print it to stdout, for validation
    std::shared_ptr<Entity> person;

    std::ifstream is(kFileName);
    cereal::JSONInputArchive input(is);
    input(person);

    cereal::JSONOutputArchive output(std::cout);
    output(person);
  }


  return 0;
}
