#pragma once
#include "Move.h"
#include <memory>

class Node : public enable_shared_from_this<Node>
{
public:
	Move move; //move that leads to this node
	weak_ptr<Node> parent;
	shared_ptr<vector<shared_ptr<Node>>> children;

	Node(void);
	Node(Move const& m);
	Node(Move const& m,weak_ptr<Node> const& n);
	~Node(void);

	Node operator=(Node const& n);

	void setChildren(vector<Move> const& v);
	void addChild(Node & n);
	void addChild(Move const& m);

	shared_ptr<Node> getptr();
};

