#ifndef roomvar_h_ //This is making sure that header will not be defined twice.
#define roomvar_h_

/*This header file contain variables and a class to hold, group and organise them.
I did use class to hold room information becouse in my opinion, it will be easer to see
which of the functions used in program, are strictly related to performing it's goal, also private and 
public parts of a class protect the data from unintended data change performed by components of a program
not being class methods.*/

class Room
{
private:
	float floor_area = 0;
	float  paint_req = 0;
	float  room_volume = 0;
public:
	void get_dimensions(float & length, float & width, float & heigth);
	void calc_area(float length, float width) { floor_area = (length * width); }
	void calc_paint(float length, float width, float heigth, std::string unit);
	void volume(float & heigth) { room_volume = (floor_area * heigth); }
	void show(const Room & data, std::string unit);
};

template <typename T> 
bool data_check(T & data); //template prototype of function to check data entered.

void get_unit(std::string & u);

#endif