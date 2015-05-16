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
   NodeType GetType() const;
   void SetType(NodeType);

   operator NodeType() const { return m_type; };

private:
   NodeType m_type;
};
