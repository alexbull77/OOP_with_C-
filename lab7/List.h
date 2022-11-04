#ifndef LIST_H_
#define LIST_H_
#include <iostream>

template <typename Type>
struct ListItem
{
	Type data;
	ListItem* next;
	ListItem(Type _data = 0, ListItem* _next = nullptr) : data(_data), next(_next) {}
};

template<typename Type>
inline std::ostream& operator<<(std::ostream& os, const ListItem<Type>& self)
{
	os << self.data;
	return os;
}

template<typename Type>
inline std::istream& operator>>(std::istream& is, const ListItem<Type>& self)
{
	is >> self.data;
	return is;
}

template <typename Type>
class List : private ListItem<Type>
{
	ListItem<Type>* _front;
	unsigned int _size;
	void delete_front();
public:
	List(ListItem<Type>* front = nullptr, const unsigned int size = 0)
		: _front(front), _size(size) {};
	~List();
	bool is_empty() const { return _front ? false : true; }
	ListItem<Type>* front_item() const { return _front; }
	Type& front_data();
	Type& front_data() const;
	unsigned int getLength() const { return _size; }
	bool contains(const Type& data) const;
	void push_front(const Type& data);
	void push_back(const Type& data = 0);
	void pop_front();
	void pop_back();
	void insert(const int& index, const Type& data);
	void remove(const Type& data);
	Type& operator[] (const unsigned int index) const;
	Type& operator[] (const unsigned int index);
	//declare overridden operators friends and "<>" templates
	//https://isocpp.org/wiki/faq/templates#fn-templates-explicit-calls
	friend std::ostream& operator << <>(std::ostream& os, const List<Type>& self);
	friend std::istream& operator >> <>(std::istream& is, const List<Type>& self);
};

template<typename Type>
inline void List<Type>::pop_back()
{
	if (!_front)
	{
		std::cout << "Nothing to delete";
		throw false;
	}
	if (!_front->next)
	{
		pop_front();
		return;
	}

	ListItem<Type>* tmp = _front;
	while (tmp->next->next)
		tmp = tmp->next;
	delete tmp->next;
	tmp->next = nullptr;
	_size--;
}

template<typename Type>
inline void List<Type>::push_back(const Type& data)
{
	if (!_front)
		push_front(data);
	else
	{
		ListItem<Type>* tmp = _front;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new ListItem<Type>(data);
		_size++;
	}
}

template<typename Type>
inline void List<Type>::insert(const int& index, const Type& data)
{
	if (index < 0 || index > _size)
	{
		std::cout << "Index " << index << " out of bound";
		throw false;
	}
	else if (index == _size)
	{
		push_back(data);
		return;
	}
	else
	{
		ListItem<Type>* tmp = _front;
		for (unsigned int i = 0; i < index - 1; i++)
			tmp = tmp->next;
		ListItem<Type>* tmp2 = tmp->next;
		tmp->next = new ListItem<Type>(data);
		tmp->next->next = tmp2;
		_size++;
	}
}

template<typename Type>
inline void List<Type>::remove(const Type& data)
{
	if (contains(data))
	{
		ListItem<Type>* tmp = _front;
		while (tmp->next->data != data)
			tmp = tmp->next;
		ListItem<Type>* item_removed = tmp->next;
		tmp->next = tmp->next->next;
		delete item_removed;
	}
	else
	{
		std::cout << "Value " << data << " not in list" << std::endl;
		throw false;
	}
}

template<typename Type>
inline void List<Type>::delete_front()
{
	ListItem<Type>* old_front = _front;
	_front = _front->next;
	delete old_front;
	_size--;
}

template<typename Type>
inline List<Type>::~List()
{
	while (_front)
		delete_front();
}

template<typename Type>
inline Type& List<Type>::operator[](const unsigned int index)
{
	if (index >= _size)
	{
		std::cout << "Error: Index " << index << " out of bound";
		throw false;
	}
	ListItem<Type>* it = _front;
	for (unsigned int i = 0; i < index; i++)
		it = it->next;
	return it->data;
}

template<typename Type>
inline Type& List<Type>::operator[](const unsigned int index) const
{
	if (index >= _size)
	{
		std::cout << "Error: Index " << index << " out of bound";
		throw false;
	}
	ListItem<Type>* it = _front;
	for (unsigned int i = 0; i < index; i++)
		it = it->next;
	return it->data;
}

template<typename Type>
inline bool List<Type>::contains(const Type& data) const
{
	for (ListItem<Type>* it = _front; it; it = it->next)
		if (it->data == data)
			return true;
	return false;
}

template<typename Type>
inline Type& List<Type>::front_data()
{
	if (_front)
		return _front->data;
	else
		throw false;
}

template<typename Type>
inline Type& List<Type>::front_data() const
{
	if (_front)
		return _front->data;
	else
		throw false;
}

template<typename Type>
inline void List<Type>::push_front(const Type& data)
{
	ListItem<Type>* new_item = new ListItem<Type>(data);
	if (_front != nullptr)
	{
		ListItem<Type>* old_front = _front;
		new_item->next = old_front;
	}
	_front = new_item;
	_size++;
}

template<typename Type>
inline void List<Type>::pop_front()
{
	if (_front)
		delete_front();
	else
	{
		std::cout << "Nothing to remove";
		throw false;
	}
}

template <typename Type>
inline std::ostream& operator<<<>(std::ostream& os, const List<Type>& self)
{
	if (!self.is_empty())
	{
		for (ListItem<Type>* it = self._front; it; it = it->next)
			os << it << " ";
	}
	else
		std::cout << "List is empty!";
	return os;
}

template <typename Type>
inline std::istream& operator>><>(std::istream& is, const List<Type>& self)
{
	for (ListItem<Type>* it = self._front; it; it = it->next)
		is >> it;
	return is;
}

#endif
