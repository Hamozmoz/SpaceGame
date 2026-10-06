#ifndef COLLISIONGRID_H
#define COLLISIONGRID_H
#include "Entity.h"
class CollisionGrid
{
public:
CollisionGrid(int Rows = 0, int Columns = 0, float BoxWidth = 0, float BoxHeight = 0);
void Init(int Rows,int Columns,float BoxWidth,float BoxHeight);
CollisionBox& operator[](int row,int column);
CollisionBox& getCollisionBox(int row,int column);
void CalculateEntityLocations(const std::array<Entity,EntityCount>& EntityArray, int ArraySize);
const std::vector<uint16_t>& getNearbyEntities(const CollisionBox& box);
private:
void ClearBoxes();
std::vector<std::vector<uint16_t>> m_Boxes;
std::vector<uint16_t>m_NearbyEntitiesBuffer;
float m_BoxWidth{0};
float m_BoxHeight{0};
int m_Columns{0};
int m_Rows{0};

};
#endif // COLLISIONGRID_H
