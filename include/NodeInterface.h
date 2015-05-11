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

class NodeInterface {
public:
   virtual NodeType GetType() = 0;
};
