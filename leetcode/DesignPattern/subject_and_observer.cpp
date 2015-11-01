#include "subject_and_observer.h"



Subject::~Subject()
{

}

void Subject::Notify()
{
	std::for_each(	observers_.begin(),
		observers_.end(), 
		[&](const Observers::value_type& _observer){
			std::for_each(
				_observer.second.begin(), 
				_observer.second.end(),
				[&](const Event& _event){
					Event::first_type  tObserver = _event.first;
					Event::second_type callback = _event.second;
					callback(tObserver,this);
			});
	});
}

void Subject::Notify( const std::string& _event_name, const Event& _event )
{
	if (observers_.find(_event_name) != observers_.end()){
		std::for_each(
			observers_[_event_name].begin(), 
			observers_[_event_name].end(),
			[&](const Event& _tmp_event){
				Event::first_type  tObserver = _tmp_event.first;
				if (_event.first == tObserver){
					Event::second_type callback = _tmp_event.second;
					callback(tObserver,this);
				}
		});
	}
}

void Subject::Notify( const std::string& _event_name )
{
	if (observers_.find(_event_name) != observers_.end()){
		std::for_each(
			observers_[_event_name].begin(), 
			observers_[_event_name].end(),
			[&](const Event& _event){
				Event::first_type  tObserver = _event.first;
				Event::second_type callback = _event.second;
				callback(tObserver,this);}
		);
	}
}

void Subject::Attach( const std::string& _event_name, const Event& _event )
{
	if(observers_.find(_event_name) == observers_.end()){
		std::list<Event> event_list;
		event_list.push_back(_event);
		observers_.insert(observers_.end(),std::make_pair(_event_name, event_list));
	}
	else
	{
		observers_[_event_name].push_back(_event);
	}
}

void Subject::Remove()
{
	observers_.clear();
}

void Subject::Remove( const std::string& _event_name, const Event& _event )
{
	if (observers_.find(_event_name) !=observers_.end()){
		observers_[_event_name].remove_if(
			[&](const Event& _tmp_event){
				return _event.first == _tmp_event.first;
		});

	}
}

void Subject::Remove( const std::string& _event_name )
{
	if (observers_.find(_event_name) != observers_.end()){
		observers_.erase(_event_name);
	}
}

Subject::Subject() :
	observers_()
{

}
