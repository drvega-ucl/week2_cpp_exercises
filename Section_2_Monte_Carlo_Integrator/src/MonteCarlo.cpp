#include <iostream>
#include <random>
#include <functional>

//Is InsideUnitSphere lambda function

auto InsideUnitSphere = [](double x, double y, double z) {return (x*x + y*y + z*z) <= 1;};

double IntegrateMonteCarlo3D(int n_points, double min, double max)
{
    int count = 0;
    // N.B. std::pow with integer arguments can be less efficient than
    // writing the multiplication explicitly, so be careful about using it
    // inside loops for example!
    double VolCube = std::pow((max - min), 3);

    //set up random number generator here
    std::mt19937 rng_mt;

    //set up real number distribution
    std::uniform_real_distribution<double> uniform_dist(min,max);

    //Set up std::function
    std::function<bool(double,double,double)> isInside = InsideUnitSphere;

    //Create bind

    auto bindRandom = std::bind(uniform_dist,rng_mt);

    for(int i = 0; i < n_points; i++)
    {
        //generate random points here
        double x = bindRandom();
        double y = bindRandom();
        double z = bindRandom();

        if(isInside(x, y, z)) count++;
    }

    return static_cast<double>(count) / n_points * VolCube;
}


int main()
{
    int N_points = 10000;
    
    double UnitSphereVol = IntegrateMonteCarlo3D(N_points, -1.0, 1.0);

    std::cout << "Volume estimate of sphere using " << N_points << " points = " << UnitSphereVol << std::endl;

    return 0;
}