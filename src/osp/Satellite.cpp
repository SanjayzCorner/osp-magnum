#include <iostream>

#include "Satellite.h"

namespace osp
{

SatelliteObject::SatelliteObject()
{

}

Satellite::Satellite(Universe* universe) : m_universe(universe)
{
    m_name = "Innocent Satellite";

    // 2^10 = 1024
    // 1024 units = 1 meter
    // enough for a solar system
    //m_precision = 10;
    m_loadRadius = 30.0f; // 1km radius sphere around sat
    std::cout << "satellite created\n";
}


Satellite::Satellite(Satellite&& sat) :
        m_loadRadius(std::exchange(sat.m_loadRadius, 0)),
        m_loadedBy(nullptr),
        m_object(std::move(sat.m_object)),
        m_name(std::move(sat.m_name)),
        m_position(sat.m_position)
{
    // TODO
    m_object->m_sat = this;
    std::cout << "satellite moved\n";
}

Satellite::~Satellite()
{
    std::cout << "satellite destroyed!\n";

    //m_object.release(); // not the right thing to do
}

bool Satellite::is_loadable() const
{
    if (m_object.get())
    {
         return m_object->is_loadable();
    }
    return false;
}

Vector3sp Satellite::position_relative_to(Satellite& referenceFrame) const
{
    // might do more stuff here
    return (m_position - referenceFrame.m_position);
}

//Satellite::~Satellite()
//{
//    m_object.reset();
//}

}
