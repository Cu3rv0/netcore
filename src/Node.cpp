#include "Node.h"

Node::Node(NodeType type):
   m_type(type)
{}

NodeType Node::GetType()
{
   return m_type;
}
