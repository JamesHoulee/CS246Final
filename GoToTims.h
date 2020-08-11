#ifndef _GOTOTIMS_H_
#define _GOTOTIMS_H_

#include "Cell.h"

class GoToTims : public Cell {
	
	public:
		GoToTims ();
		virtual void action (std::shared_ptr<Player> p, bool b) override;
};

#endif
