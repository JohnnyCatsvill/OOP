#pragma once
#include <memory>
#include "CMyListError.h"

template <typename T>
struct Node
{
	T data;
	Node<T>* next;
	Node<T>* prev;
};

template <typename T>
class CMyList
{

	template <typename T, bool IsConst>
	class IteratorBase
	{
		friend CMyList;
		friend class IteratorBase<T, true>;
	public:
		using MyType = IteratorBase<T, IsConst>;
		using value_type = std::conditional_t<IsConst, const T, T>;
		using reference = value_type&;
		using pointer = value_type*;
		using difference_type = ptrdiff_t;
		using iterator_category = std::random_access_iterator_tag;

		IteratorBase() = default;
		IteratorBase(Node<T>* other)
			: m_item(other)
		{
		}

		T& operator*()
		{
			if (m_item->prev == nullptr)
			{
				throw CMyListError("Out of range: rend() element can't contain any data");
			}
			else if (m_item->next == nullptr)
			{
				throw CMyListError("Out of range: end() element can't contain any data");
			}
			return m_item->data;
		}

		const bool operator==(const MyType& other) const
		{
			return this->m_item == other.m_item;
		}

		const bool operator!=(const MyType& other) const
		{
			return this->m_item != other.m_item;
		}

		MyType& operator++()
		{
			if (m_item->next == nullptr)
			{
				throw CMyListError("Out of range: Can't increment iterator");
			}
			else
			{
				m_item = m_item->next;
				return *this;
			}
		}

		MyType& operator--()
		{
			if (m_item->prev == nullptr)
			{
				throw CMyListError("Out of range: Can't decrement iterator");
			}
			else
			{
				m_item = m_item->prev;
				return *this;
			}
		}

		MyType& operator=(const MyType& other)
		{
			m_item = other.m_item;
			return *this;
		}

	protected:
		Node<T>* m_item = nullptr;
	};

public:
	
	CMyList()
	{
		m_begin->prev = nullptr;
		m_begin->next = m_end;
		m_end->prev = m_begin;
		m_end->next = nullptr;
		m_size = 0;
	}

	CMyList(CMyList<T>& other)
	{
		m_begin->prev = nullptr;
		m_begin->next = m_end;
		m_end->prev = m_begin;
		m_end->next = nullptr;
		m_size = 0;
		for (CMyList<T>::iterator it = other.begin(); it != other.end(); ++it)
		{
			PushBack(*it);
		}
	}

	~CMyList()
	{
	}

	CMyList& operator=(CMyList& other)
	{
		Clear();
		m_begin->prev = nullptr;
		m_begin->next = m_end;
		m_end->prev = m_begin;
		m_end->next = nullptr;
		m_size = 0;
		for (CMyList<T>::iterator it = other.begin(); it != other.end(); ++it)
		{
			PushBack(*it);
		}
		return *this;
	}

	CMyList& Clear()
	{
		CMyList<T>::iterator it;
		for (CMyList<T>::iterator next = begin(); next != end();)
		{
			it = next;
			++next;
			free(it.m_item);
		}
		return *this;
	}

	CMyList& PushFront(const T& obj)
	{
		Node<T>* temp = new Node<T>;
		temp->data = obj;
		temp->prev = m_begin;
		temp->next = m_begin->next;
		m_begin->next->prev = temp;
		m_begin->next = temp;
		m_size++;
		return *this;
	}

	CMyList& PushBack(const T& obj)
	{
		Node<T>* temp = new Node<T>;
		temp->data = obj;
		temp->next = m_end;
		temp->prev = m_end->prev;
		m_end->prev->next = temp;
		m_end->prev = temp;
		m_size++;
		return *this;
	}


	using iterator = IteratorBase<T, false>;

	iterator begin()
	{
		return m_begin->next;
	}

	iterator end()
	{
		return m_end;
	}

	iterator rbegin()
	{
		return m_end->prev;
	}

	iterator rend()
	{
		return m_begin;
	}

	CMyList& Insert(iterator it, const T& obj)
	{
		if (it == rend())
		{
			throw CMyListError("Out of range: Can't insert after rend() element");
		}
		else
		{
			Node<T>* temp = new Node<T>;
			temp->data = obj;
			temp->next = it.m_item;
			temp->prev = it.m_item->prev;
			it.m_item->prev->next = temp;
			it.m_item->prev = temp;
			m_size++;
		}
		return *this;
	}

	CMyList& Delete(iterator it)
	{
		if (it == rend())
		{
			throw CMyListError("Out of range: Can't delete rend() element");
		}
		else if (it == end())
		{
			throw CMyListError("Out of range: Can't delete end() element");
		}
		else
		{ 
			it.m_item->next->prev = it.m_item->prev;
			it.m_item->prev->next = it.m_item->next;
			free(it.m_item);
			m_size--;
		}
		return *this;
	}

	size_t Size() const
	{
		return m_size;
	}



private:
	Node<T>* m_begin = new Node<T>;
	Node<T>* m_end = new Node<T>;
	size_t m_size;
}; 

