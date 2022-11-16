#include <Crumbl2d.h>

class Sandbox : public  Crumbl::Application
{
public:
    Sandbox()
    {
    }

    ~Sandbox()
    {
    }
};

Crumbl::Application* Crumbl::CreateApplication()
{
    return new Sandbox;
}