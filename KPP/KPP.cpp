// NAMA		: Yahya Setiawan
// NRP		: 5022221112
// Jurusan	: Teknik Elektro

#include <iostream>
#include <cmath>

#define GRAVITASI 10 //10 m/s^2
#define START_PENGUKURAN 1 //pengukuran dimulai dari 1 meter
#define SUDUT 45 //sudut elevasi tembakan

int losses;
float v0, vtm, vt;

float mencari_V0(float vtm, int losses)
{
    return vtm - losses;
}

int speed_dgn_loss(float vtm)
{
	if (vtm >= 1 && vtm <=10){
        return 1;
    }
    else if (vtm >=11 && vtm <=20){
        return 3;
    }
    else if (vtm >=21 && vtm <= 30){
        return 5;
    }
    return 0;
}

int main() {
    float vtm;
  
  	/* input adalah kecepatan tangensial maksimum roller */
  	/* std::cin >> input */
    std::cin >> vtm;

    losses = speed_dgn_loss(vtm);
    v0 = mencari_V0(vtm, losses);

    int jarak_max = (v0*v0)/GRAVITASI;
    float v0 = sqrt(jarak_max*GRAVITASI);
    float vtr = v0 + losses;
  
  	/* std::cout << jarak << " " << kecepatan tangensial << std::endl */
    std::cout << jarak_max << " " << vtr << std::endl;
    return 0;
}