#include <iostream>
#include <cmath>

int main(int argc, char *argv[])
{
	const float e = 2.7182818284590f;
	
	const float min = 1e-5f;
	const float max = 1e+5f;
	const float steps = 1e+8f;
	const float dx = (max - min) / steps;
	
	std::cout << "Step size: " << dx << std::endl;
	
    float x = min;
    float val = 0;
	
	while (x <= max)
	{
		float x2 = -x * x;
		val += std::pow(e, x2) * dx;
		x += dx;
	}
	
	std::cout << 4 * val * val << std::endl;
	return 0;
}