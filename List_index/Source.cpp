#include<iostream>
using namespace std;

template<typename T>
class List;


template<typename T>
class Node
{
	T value;
	Node* next;
	Node* prev;
	int index;
	friend class List<T>;
public:
	Node<T>(T _value)
	{
		next = nullptr;
		prev = nullptr;
		value = _value;
		index = 0;
	}
	T get_value()
	{
		if (this != nullptr)
			return value;
		else
			cout << "No value\n";
			return (T)(-1);
	}
	int get_index()
	{
		if (this != nullptr)
			return index;
		else
			cout << "No value\n";
			return (T) - 1;

	}
	~Node()
	{

	}

};
template<typename T>
class List
{
	Node<T>* first;
	Node<T>* last;
public:
	List<T>()
	{
		first = nullptr;
		last = nullptr;
	}
	List<T>(T _value) 
	{
		Node<T>* p = new Node<T>(_value);
		first = p;
		last = p;
		
	}
	bool isEmpty()
	{
		return first == nullptr;
	}
	void pushBack(T _value)
	{
		Node<T>* p = new Node<T>(_value);
			if (isEmpty())
			{
				first = p;
				p->index = 0;
				last = p;
			}
			else
			{
				last->next = p;
				p->prev = last;
				last = p;
				p->index = p->prev->index + 1;
			}

	}

	void pushFovard(T _value)
	{
		Node<T>* p = new Node<T>(_value);
		if (isEmpty())
		{
			first = p;
			p->index = 0;
			last = p;
		}
		else
		{
			first->prev = p;
			p->next = first;
			p->index = 0;
			first = p;
			while (p->next)
			{
				p->next->index++;
				p = p->next;
			}

		}

	}
	Node<T>* getByIndex(int _index)
	{
		if (_index > last->get_index() || _index < 0)
		{
			cout << "No object\n";
			return nullptr;
		}
		Node<T>* p = first;
		int i = 0;
		while (i < _index)
		{
			p = p->next;
			i++;
		}
		return p;
	
	}
	Node<T>* operator[](int _index) 
	{
		if (_index > last->get_index() || _index < 0)
		{
			cout << "No object\n";
			return nullptr;
		}
		Node<T>* p = first;
		int i = 0;
		while (i < _index)
		{
			p = p->next;
			i++;
		}
		return p;
	}
	void simplePrint()
	{
	
		if (isEmpty())
			return;
		Node<T>* p = first;
		while (p)
		{
			cout <<"Index: "<<p->get_index()<<". Value: " << p->get_value() << "\n";
			p = p->next;
		}
		delete p;
	}
	void reversePrint()
	{

		if (isEmpty())
			return;
		Node<T>* p = last;
		while (p)
		{
			cout << "Index: " << p->get_index() << ". Value: " << p->get_value() << "\n";
			p = p->prev;
		}
		delete p;
	}
	void deleteByIndex(int _index)
	{
		Node<T>* temp = this->getByIndex(_index);
		Node<T>* p = this->getByIndex(_index);

		p->prev->next = p->next;
		p->next->prev = p->prev;
		while (p->next)
		{
			p->next->index--;
			p = p->next;
		}
		delete temp;
	}
	void pushBefore(int _index, T _value) 
	{
		Node<T>* current = getByIndex(_index);
		Node<T>* temp = new Node<T>(_value);
		
		temp->next = current;
		temp->prev = current->prev;
		temp->index = current->index;
		current->prev->next = temp;
		current->prev = temp;
		while (current) 
		{
			current->index++;
			current = current->next;
		}
	}

};


int main()
{
	List<int>list;
	list.pushBack(5);
	list.pushBack(10);

	list.pushFovard(1);
	list.simplePrint();
	list.pushBefore(1,3);
	list.simplePrint();


	return 0;
}