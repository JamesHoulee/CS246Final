#ifndef _SUBJECT_H_
#define _SUBJECT_H_

#include <memory>
#include <vector>
#include <string>

class Player;
class Observer;
class Subject {

	private:
		std::vector<std::shared_ptr<Observer>> observers;

	public:
		void attach(std::shared_ptr<Observer> o);
		virtual void notifyObservers();
		virtual std::string getName() const = 0;
		virtual std::shared_ptr<Player> getOwner() = 0;
};

#endif
