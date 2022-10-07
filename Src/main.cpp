#include <iostream>
#include <chrono>
#include <vector>

struct Timer
{
    std::chrono::time_point<std::chrono::steady_clock> start, end;
    std::chrono::duration<float> duration;
    
    Timer()
    {
        start = std::chrono::high_resolution_clock::now();
    }
    ~Timer()
    {
        end = std::chrono::high_resolution_clock::now();
        duration = end - start;
        float ms  = duration.count() * 1000.0f ;
        std::cout<<"Timer took "<<ms<<" ms "<<"\n";
    }
};

class Vertices
{
    float x,y,z;
public:
    Vertices(float x , float y , float z)
    :x(x), y(y),z(z){}
    
    Vertices ( const Vertices& obj)
    : x(obj.x), y(obj.y), z(obj.z)
    {
        std::cout<<"Copied"<<std::endl;
    }
    void getVertices()
    {
        std::cout<<x<<" , "<<y<<" , "<<z<<std::endl;
    }
    ~Vertices(){};
};

int main()
{
    Timer stopwatch;

    std::vector<Vertices> vect;
    vect.reserve(3);
    
    vect.emplace_back(10,20,30);
    vect.emplace_back(40,50,60);
    vect.emplace_back(70,80,90);
    
    return 0;
  
}
