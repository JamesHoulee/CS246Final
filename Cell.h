#ifndef _CELL_H_
#define _CELL_H_

#include <memory>
#include <string>
#include <vector>
#include "Subject.h"
#include "Observer.h"


class Player;

class Cell : public Subject, public Observer {
	protected:
		std::string name;
		std::vector<bool> on_cell;
	public:
		Cell (const std::string &name);
		void action (std::shared_ptr<Player> p, bool b) = 0;
};

#endif
