// Fonte: site GeeksforGeeks
#include <iostream>

using namespace std;

// Abstraction: Shape
class Shape {
    public:
    virtual void draw() = 0;
};

// Implementations: Renderer (VectorRenderer and
// RasterRenderer)
class Renderer {
    public:
    virtual void render() = 0;
};

class VectorRenderer : public Renderer {
    public:
    void render() override
    {
        cout << "Rendering as a vector\n";
    }
};

class RasterRenderer : public Renderer {
    public:
    void render() override
    {
        cout << "Rendering as a raster\n";
    }
};

// Concrete Abstractions: Circle and Square
class Circle : public Shape {
    public:
    Circle(Renderer& renderer)
        : renderer(renderer)
    {
    }

    void draw() override{
        cout << "Drawing a circle\n";
        renderer.render();
    }

    private:
    Renderer& renderer;
};

class Square : public Shape {
    public:
    Square(Renderer& renderer)
        : renderer(renderer)
    {
    }

    void draw() override {
        cout << "Drawing a square\n";
        renderer.render();
    }

    private:
    Renderer& renderer;
};

int main()
{
    VectorRenderer vectorRenderer;
    RasterRenderer rasterRenderer;

    Circle circle(vectorRenderer);
    Square square(rasterRenderer);

    circle.draw(); // Output: Drawing a circle Rendering as
                   // a vector
    square.draw(); // Output: Drawing a square Rendering as
                   // a raster

    return 0;
}