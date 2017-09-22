#include "NodeDL.h"
template <typename T> class NodeDL {
T data;
NodeDL* next;
NodeDL* back;
 
NodeDL::NodeDL(T d)
{
	data = d;
	next = NULL;
	back = NULL;
}


NodeDL::~NodeDL()
{
}
};