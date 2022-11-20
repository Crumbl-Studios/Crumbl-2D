#include <Crumbl2d.h>

class Sandbox : public  crumbl2d::Application
{
public:
    Sandbox()
    {
    }

    ~Sandbox()
    {
    }
};

crumbl2d::Application* crumbl2d::CreateApplication()
{
    return new Sandbox;
}