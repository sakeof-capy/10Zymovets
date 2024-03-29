#ifndef _ARRAY_QUEUE_
#define _ARRAY_QUEUE_
#include "IQueue.h"
#include "ArrayQueueIterator.h"

//***********************************************************
//	��������� ���� ����������� ���� �� ��������� ����� 
//	�������. ���������� ��������� ������������ �����
//	�) �� ��� ������ (�������� �����)
//	�) �� ��� ������
//	�) �� ��� ������ (���������� �����) *** (������� �����)
//	�� � ���� ���������� ����������?
//	Developed by Ruslan Zymovets (SE, group 1) on April 30
//	Version 1.0
//***********************************************************

namespace lab10
{
	template<size_t Capacity, typename T>
	class ArrayQueue : virtual public IQueue<T>
	{
	private:
		using IQueue<T>::QueueProblem;
	public:
		using Iterator = ArrayQueueIterator<false, T>;
		using ConstIterator = ArrayQueueIterator<true, T>;
	private:
		size_t _size;
		size_t _front;
		size_t _back;
		T _allocator[Capacity];
	public:
		ArrayQueue();
		~ArrayQueue();
		ArrayQueue(const ArrayQueue&) = delete;
		ArrayQueue& operator=(const ArrayQueue&) = delete;
		virtual inline ConstIterator& attach()		const	override;
		virtual inline Iterator& attach()					override;
	private:
		inline size_t	next_index(size_t)	const;
		virtual inline bool		do_empty()			const	override;
		virtual inline bool		do_full()			const	override;
		virtual inline const T& do_front()			const	override;
		virtual inline size_t	do_capacity()		const	override;
		virtual inline size_t	do_size()			const	override;
		virtual inline void		do_pop()					override;
		virtual inline void		do_put(const T& value)		override;
	};

	template<typename T>
	class ArrayQueue<0, T>;

	template<size_t Capacity, typename T>
	inline ArrayQueue<Capacity, T>::ArrayQueue()
		: IQueue<T>(), _size(0), _front(0), _back(-1)
	{
		return;
	};

	template<size_t Capacity, typename T>
	inline ArrayQueue<Capacity, T>::~ArrayQueue()
	{
		return;
	}

	template<size_t Capacity, typename T>
	inline typename ArrayQueue<Capacity, T>::ConstIterator& ArrayQueue<Capacity, T>::attach() const
	{
		return *(
				new ConstIterator
				(
					&_allocator[0], 
					&_allocator[_front], 
					&_allocator[_back], 
					IQueue<T>::size(), 
					IQueue<T>::capacity()
				)
				);
	}

	template<size_t Capacity, typename T>
	inline typename ArrayQueue<Capacity, T>::Iterator& ArrayQueue<Capacity, T>::attach()
	{
		return *(
				new Iterator
				(
					&_allocator[0], 
					&_allocator[_front], 
					&_allocator[_back], 
					IQueue<T>::size(), 
					IQueue<T>::capacity())
				);
	}

	template<size_t Capacity, typename T>
	inline size_t ArrayQueue<Capacity, T>::next_index(size_t i) const
	{
		return (i + 1) % IQueue<T>::capacity();
	}

	template<size_t Capacity, typename T>
	inline bool ArrayQueue<Capacity, T>::do_empty() const
	{
		return IQueue<T>::size() == 0;
	}

	template<size_t Capacity, typename T>
	inline bool ArrayQueue<Capacity, T>::do_full() const
	{
		return IQueue<T>::size() == IQueue<T>::capacity();
	}

	template<size_t Capacity, typename T>
	inline const T& ArrayQueue<Capacity, T>::do_front() const
	{
		if (IQueue<T>::empty())
			throw IQueue<T>::BadQueue(QueueProblem::EMPTY_QUEUE_FRONT);
		return _allocator[_front];
	}

	template<size_t Capacity, typename T>
	inline size_t ArrayQueue<Capacity, T>::do_capacity() const
	{
		return Capacity;
	}

	template<size_t Capacity, typename T>
	inline size_t ArrayQueue<Capacity, T>::do_size() const
	{
		return _size;
	}

	template<size_t Capacity, typename T>
	inline void ArrayQueue<Capacity, T>::do_pop()
	{
		if (IQueue<T>::empty())
			throw IQueue<T>::BadQueue(QueueProblem::EMPTY_QUEUE_POP);
		--_size;
		_front = next_index(_front);
	}

	template<size_t Capacity, typename T>
	inline void ArrayQueue<Capacity, T>::do_put(const T& value)
	{
		if (IQueue<T>::full())
			throw IQueue<T>::BadQueue(QueueProblem::FULL_QUEUE_PUT);
		++_size;
		_allocator[_back = next_index(_back)] = value;
	}
}
#endif // !_ARRAY_QUEUE_