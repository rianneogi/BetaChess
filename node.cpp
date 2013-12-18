#include "Node.h"

Node::Node(void)
{
	cout << "start" << endl;
	parent = weak_ptr<Node>();
	children = make_shared<vector<shared_ptr<Node>>>(vector<shared_ptr<Node>>(0));
	move = Move();
	cout << "end" << endl;
}

Node::Node(Move const& m)
{
	parent = weak_ptr<Node>();
	children = make_shared<vector<shared_ptr<Node>>>(vector<shared_ptr<Node>>(0));
	move = m;
}

Node::Node(Move const& m,weak_ptr<Node> const& n)
{
	parent = n;
	children = make_shared<vector<shared_ptr<Node>>>(vector<shared_ptr<Node>>(0));
	move = m;
}

Node::~Node(void)
{
	//cout << "dtor called" << endl;
	parent.reset();
	for(unsigned int i = 0;i<children->size();i++)
	{
		children->at(i).reset();
	}
	children.reset();
}

Node Node::operator=(Node const& n)
{
	parent = n.parent;
	move = n.move;
	children = n.children;
	return *this;
}

void Node::setChildren(vector<Move> const& v)
{
	children->clear();
	for(unsigned int i = 0;i<v.size();i++)
	{
		addChild(v.at(i));
	}
}

void Node::addChild(Node & n)
{
	shared_ptr<Node> ptr = make_shared<Node>(n);
	children->push_back(ptr);
	n.parent = shared_from_this();
}

void Node::addChild(Move const& m)
{
	Node n(m,shared_from_this());
	shared_ptr<Node> ptr = make_shared<Node>(n);
	children->push_back(ptr);
}

shared_ptr<Node> Node::getptr()
{
	return shared_from_this();
}