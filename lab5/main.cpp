#include "realization.cpp"

int main()
{
	ElectronicDevice* arr[4];
	arr[0] = new ElectronicDevice("SilverName 400", 30, 105);
	arr[1] = new Television("Bronze 750", 40, 95, 1080, 60);
	arr[2] = new DigitalDevice("Gold 500", -5, 110, "MicrosoftCam", true);
	arr[3] = new Monitor("Bronze 450", 20, 87, 720, 120, "None", false, true, true, "LG");

	for (int i = 0; i < 4; i++)
		arr[i]->show();

	for (int i = 0; i < 4; i++)
		delete arr[i];

	return 0;
}