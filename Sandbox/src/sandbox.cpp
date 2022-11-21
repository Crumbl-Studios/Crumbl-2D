#include <Crumbl2d.h>

class Sandbox : public  crumbl2d::application
{
public:
    Sandbox()
    {
    }

    ~Sandbox()
    {
    }
};

crumbl2d::application* crumbl2d::createApplication()
{
    return new Sandbox;
}