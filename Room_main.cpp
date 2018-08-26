/*Author: Konrad Gasior
e-mail: konrado1235@gmail.com
tel: 07466779702

*/


#include <iostream>
#include "Room_var.h"
#include <string>
int main()
{
	Room room_1;
	float wid, len, h;
	std::string uni;

	get_unit(uni);

	room_1.get_dimensions(wid, len, h);
	room_1.calc_area(wid, len);
	room_1.volume(h);
	room_1.calc_paint(len, wid, h, uni);
	room_1.show(room_1, uni);

	system("PAUSE");
	return 0;
}