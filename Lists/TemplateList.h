#pragma once
// Foi consultada a lista template do professor Simão presente na versão final do sistema acadêmico para implementar algumas operações desta lista

namespace np_TemplateList {
template<class T>
class TemplateList
{
private:
	class Element
	{
	private:
		Element* next;
		Element* prev;
		T info;
	public:
		Element() { next = prev = nullptr; info = nullptr; }
		~Element() { next = prev = nullptr; info = nullptr; }
		void setNext(Element* elem) { next = elem; }
		Element* getNext() { return next; }
		void setPrev(Element* elem) { prev = elem; }
		Element* getPrev() { return prev; }
		void setInfo(const T val) { info = val; }
   		const T getInfo() { return info; }
	};
	Element* first;
	Element* last;

public:
	class Iterator
	{
	private:
		Element* ptr;
	public:
		Iterator() { ptr = nullptr; }
		~Iterator() { ptr = nullptr; }
		void operator++(int) { if (ptr != nullptr)	ptr = ptr->getNext(); }
		void operator--(int) { if (ptr != nullptr)	ptr = ptr->getPrev(); }
		bool operator !=(Element* elem) { return !(elem == ptr); }
		bool operator ==(Element* elem) { return (elem == ptr); }
		void operator =(Element* elem) { ptr = elem; }
		T operator *() { return ptr->getInfo(); }
	};
public:
	TemplateList() { first = last = nullptr; }
	~TemplateList() { }
	void include(const T info) {
		Element* node = new Element;
		node->setInfo(info);
		if (nullptr == first) {
			last = first = node;
		}
		else {
			node->setPrev(last);
			last->setNext(node);
			last = node;
		}
	}
	void Remove(T info) {
		Element* aux1 = nullptr;
		Element* aux2 = first;
		while (aux2 != nullptr && aux2->getInfo() != info) {
			aux1 = aux2;
			aux2 = aux2->getNext();
		}
		if (aux2 != nullptr && aux2->getInfo() == info) {
			if (aux2 == first) {
				first = first->getNext();
				if (first != nullptr)
					first->setPrev(nullptr);
			}
			else if (aux2 == last) {
				last = last->getPrev();
				if (last != nullptr)
					last->setNext(nullptr);
			}
			else {
				aux1->setNext(aux2->getNext());
				aux1->getNext()->setPrev(aux1);
			}
			delete aux2;
			aux2 = nullptr;
		}
	}
	Element* begin() { return first; }
	Element* end() { return last->getNext(); }
		void clear() {
			Element* aux;
			Element* aux2;
			for (aux = begin()->getPrev(); aux->getNext() != end(); aux = aux->getNext()) {
				aux2 = aux;
				aux = aux->getNext();
				delete aux2;
				aux2 = nullptr;
			}
		}
	};
}