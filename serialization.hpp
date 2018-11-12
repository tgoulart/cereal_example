#include "definitions.hpp"

/* Entity */

CEREAL_CLASS_VERSION(Entity, 1);

template <class Archive>
void serialize(Archive &archive, Entity &obj, const std::uint32_t version) {
    archive(
        obj._guid,
        obj._components
    );
}

/* IComponent */

//CEREAL_REGISTER_TYPE(IComponent)
CEREAL_CLASS_VERSION(IComponent, 1);

template <class Archive>
void serialize(Archive &archive, IComponent &obj, const std::uint32_t version) {
    archive(
        obj._owner
    );
}

/* SimpleComponent */

//CEREAL_REGISTER_POLYMORPHIC_RELATION(IComponent, SimpleComponent);
CEREAL_CLASS_VERSION(SimpleComponent, 1);

template <class Archive>
void save(Archive &archive, const SimpleComponent &obj, const std::uint32_t version) {
    archive(
        cereal::base_class<IComponent>(&obj),
        obj._someData
    );
}

template <class Archive>
void load(Archive &archive, SimpleComponent &obj, const std::uint32_t version) {
    archive(
        cereal::base_class<IComponent>(&obj),
        obj._someData
    );
}

/* ComplexComponent */

//CEREAL_REGISTER_POLYMORPHIC_RELATION(SimpleComponent, ComplexComponent);
CEREAL_CLASS_VERSION(ComplexComponent, 1);

template <class Archive>
void save(Archive &archive, const ComplexComponent &obj, const std::uint32_t version) {
    archive(
        cereal::base_class<SimpleComponent>(&obj),
        obj._moreData
    );
}

template <class Archive>
void load(Archive &archive, ComplexComponent &obj, const std::uint32_t version) {
    archive(
        cereal::base_class<SimpleComponent>(&obj),
        obj._moreData
    );
}
