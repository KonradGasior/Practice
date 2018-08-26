#include<iostream>
#include<cctype>
#include "Room_var.h"
#include <string>

void Room::get_dimensions(float & length, float & width, float & heigth)
{
	do
	{
		std::cout << "Please, enter length of a room: ";
		std::cin >> length;

	} while (data_check(length) == false); /*when the data is entered the function will check if data is correct.
										   also the loop will make user to write it again until entry will fit
										   requirements.*/
	do
	{
		std::cout << "Please, enter width of a room: ";
		std::cin >> width;
	} while (data_check(width) == false);
	do
	{
		std::cout << "Please, enter heigth of a room: ";
		std::cin >> heigth;
	}while (data_check(heigth) == false);
}

/*This function is making sure that data entered in the program will be correct.
The template use, helpes to cover all possible data types entered in order to make function work,
also it will make it easer to re-use it, without rewriting the same code.*/
template<typename T>
bool data_check(T & data)
{
	if (data < 0)
	{
		std::cin.clear();
		std::cout << "Entered value can't be lower than 0!\n";
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return false;
		//cin.ignore helped me to get rid of wrong data after input lower than 0.
	}
	else if (!std::cin)
	{
		std::cin.clear();
		std::cout << "Entered value is not an number!\n";
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return false;
	} 
	else
		return true;
}

void Room::calc_paint(float length, float width, float heigth, std::string unit)
{
	float paint_coverage = 400.00; //1 gall of paint is said to cover 400 sq ft of a room.

	paint_req = 2*(length * heigth) + 2*(width * heigth) + floor_area;

	if (unit == "m")
	{
		paint_coverage *= 0.09;
		paint_req = paint_req / paint_coverage;
	}
	else if (unit == "cm")
	{
		paint_coverage *= 929.03;
		paint_req = paint_req / paint_coverage;
	}
	else if (unit == "in")
	{
		paint_coverage *= 12;
		paint_req = paint_req / paint_coverage;
	}
	else
		paint_req = paint_req / paint_coverage;
}

void get_unit(std::string & unit)
{
	do
	{
		std::cout << "Enter unit type(m, cm, ft, in): ";
		getline(std::cin, unit);
	} while (unit != "m" and unit != "cm" and unit != "ft" and unit != "in");
}

void Room::show(const Room & data, std::string unit)
{
	
	std::cout << "\nArea of the floor: ";
	std::cout << floor_area << " sq(" << unit << ")" << std::endl;
	std::cout << "Volume of the room: ";
	std::cout << room_volume <<" cubic("<< unit << ")" << std::endl;
	std::cout << "Paint req: ";
	std::cout.precision(2);
		std::cout << paint_req << " gallons(US) of paint or "
				<< paint_req*3.78 << " litres of paint" << std::endl;
}