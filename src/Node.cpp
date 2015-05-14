#include "Node.h"

Node::Node(NodeType type):
   m_type(type)
{}

NodeType Node::GetType() const
{
   return m_type;
}
