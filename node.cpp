#include "node.h"
#include <iostream>

//Υλοποιώ default constructor για το node
node::node()
{
    value=0;
    lc=NULL;
    rc=NULL;
}

//Υλοποιώ constructor για το node με παράμετρο την τιμή που παίρνει ως value
node::node(int timh)
{
    value=timh;
    lc=NULL;
    rc=NULL;
}

//Υλοποιώ setter για το lc
void node::setlc(node* apaidi)
{
    lc=apaidi;
}

//Υλοποιώ setter για το rc
void node::setrc(node* dpaidi)
{
    rc=dpaidi;
}

//Υλοποιώ setter για το pr
void node::setpr(node* parent)
{
    pr=parent;
}

//Υλοποιώ getter για το value
int node::getvalue()
{
    return value;
}

//Υλοποιώ setter για το value
void node::setvalue(int number)
{
    value=number;
}

//Υλοποιώ getter για το rc
node* node::getrc()
{
    return rc;
}

//Υλοποιώ getter για το lc
node* node::getlc()
{
    return lc;
}

//Υλοποιώ getter για το pr
node* node::getpr()
{
    return pr;
}