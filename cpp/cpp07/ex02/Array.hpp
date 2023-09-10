#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <cstdlib>

template <typename T>
class Array {
	private:
		std::size_t _size;
		T* _data;

	public:
		Array() : _size(0), _data(NULL) {}

		explicit Array(std::size_t n) 
		: _size(n), _data(NULL) {
			if (_size)
				_data = new T[_size];
		}

		Array(const Array& a)
		: _size(a.size()), _data(NULL) {
			if (_size)
				_data = new T[_size];
			for (std::size_t i = 0 ; i < _size ; ++i)
				_data[i] = _size;
		}

		~Array() {
			if (_size) {
				delete[] _data;
				_data = NULL;
				_size = 0;
			}
		}

		T& operator[](std::size_t i) {
			if (i >= _size)
				throw std::out_of_range("Index out of bounds");
			return _data[i];
		}

		const T& operator[](std::size_t i) const {
			if (i >= _size)
				throw std::out_of_range("Index out of bounds");
			return _data[i];
		}

		Array& operator=(const Array& a) {
			if (this != &a) {
				if (_size) {
					delete[] _data;
					_data = NULL;
					_size = 0;
				}
				_size = a.size();
				if (_size)
					_data = new T[_size];
				for (std::size_t i = 0 ; i < _size ; ++i)
					_data[i] = a[i];
			}
			return *this;
		}

		size_t size(void) const {
			return _size;
		}

};

#endif