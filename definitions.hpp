#include <memory>
#include <string>
#include <vector>

struct IComponent;

struct Entity {
    std::string _guid;
    std::vector<std::shared_ptr<IComponent>> _components;
};

struct IComponent {
    std::weak_ptr<Entity> _owner;
};

struct SimpleComponent : public IComponent {
    double _someData;
};

struct ComplexComponent : public SimpleComponent {
    std::string _moreData;
};
