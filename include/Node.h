#pragma once

enum NodeType
{
   Open,
   Socket,
   Cache,
   Ice,
   Port,
   Closed
};

class Node
{
public:
   Node(NodeType type = Open);
   NodeType GetType();

private:
   NodeType m_type;
};
