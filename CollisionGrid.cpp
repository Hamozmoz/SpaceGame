#include "CollisionGrid.h"

CollisionGrid::CollisionGrid(int Rows,int Columns,float BoxWidth, float BoxHeight)
{
Init(Rows,Columns,BoxWidth,BoxHeight);
}

void CollisionGrid::Init(int Rows, int Columns, float BoxWidth, float BoxHeight)
{
    m_Rows = (Rows > 255)?255:Rows;
    m_Columns = (Columns > 255)?255:Columns;
    m_BoxWidth = BoxWidth;
    m_BoxHeight = BoxHeight;
    m_Boxes.resize(m_Rows*m_Columns);
}

void CollisionGrid::CalculateEntityLocations(const std::array<Entity, EntityCount> &EntityArray,int ArraySize)
{
ClearBoxes();
    for(int i{0};i<ArraySize;++i){
  uint8_t FirstRow = static_cast<uint8_t>(EntityArray[i].m_CollisionBox.m_TopCorner/m_BoxHeight);
  uint8_t LastRow = static_cast<uint8_t>(EntityArray[i].m_CollisionBox.m_BottomCorner/m_BoxHeight);
  uint8_t FirstColumn = static_cast<uint8_t>(EntityArray[i].m_CollisionBox.m_LeftCorner/m_BoxWidth);
  uint8_t LastColumn = static_cast<uint8_t>(EntityArray[i].m_CollisionBox.m_RightCorner/m_BoxWidth);

        for(int row{FirstRow}; row<=LastRow;++row){
            for(int column{FirstColumn};column<=LastColumn;++column){
                m_Boxes[row*m_Columns + column].push_back(i);
            }

        }
    }
}
//Returns A Vector Of The Entities In The Same CollisionGridBoxes
const std::vector<uint16_t> &CollisionGrid::getNearbyEntities(const CollisionBox &box)
{
    m_NearbyEntitiesBuffer.clear();
    uint8_t FirstRow = static_cast<uint8_t>(box.m_TopCorner/m_BoxHeight);
    uint8_t LastRow = static_cast<uint8_t>(box.m_BottomCorner/m_BoxHeight);
    uint8_t FirstColumn = static_cast<uint8_t>(box.m_LeftCorner/m_BoxWidth);
    uint8_t LastColumn = static_cast<uint8_t>(box.m_RightCorner/m_BoxWidth);
    for(int row{FirstRow}; row<=LastRow;++row){
        for(int column{FirstColumn};column<=LastColumn;++column){
            for(auto index : m_Boxes[row*m_Columns+column]){
              m_NearbyEntitiesBuffer.push_back(index);
            }

        }
    }

    return m_NearbyEntitiesBuffer;
}

void CollisionGrid::ClearBoxes()
{
    for(int i {0}; i<m_Boxes.size();++i){
        m_Boxes[i].clear();
    }
}


