#include <Crumbl2d.h>

class Sandbox : public  Crumbl2D::Application
{
public:
    Sandbox()
    {
    }

    ~Sandbox()
    {
    }
};

Crumbl2D::Application* Crumbl2D::CreateApplication()
{
    return new Sandbox;
}