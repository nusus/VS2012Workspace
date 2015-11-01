#ifndef subject_and_observer_h__
#define subject_and_observer_h__

#include <string>
#include <memory>
#include <unordered_map>
#include <functional>
#include <algorithm>

class IObserver;
class Subject;

typedef std::pair<IObserver*, std::function<void(IObserver*, Subject*)> > Event;
typedef std::unordered_map<std::string, std::list<Event> > Observers;

class Subject
{
public:
	Subject();
	virtual ~Subject();
	void Notify();
	void Notify(const std::string& _event_name);
	void Notify(const std::string& _event_name, const Event& _event);
	void Attach(const std::string& _event_name, const Event& _event);
	void Remove();
	void Remove(const std::string& _event_name);
	void Remove(const std::string& _event_name, const Event& _event);

private:
	Observers observers_;
};


class IObserver
{
public:
	IObserver();
	virtual void Subscribe()=0;
	virtual void Unsubscribe()=0;
protected:
	~IObserver();
private:
};


#endif // subject_and_observer_h__
