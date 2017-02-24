#ifndef	_sort_h_
#define	_sort_h_
//**********************************//
//	ascending order			//
//	[ start,  end )				//
//**********************************//
typedef unsigned int IndexType;

template<typename T>
void	print(T* data, int len){
	for (int i = 0; i < len; ++i)
		cout << data[i] << " ";
	cout << endl;
}


//*********	swap	*****************//
template<class T>
void	swap(T *a, T *b){
	T t = *a;
	*a = *b;
	*b = t;
}
//*********	BubbleSort	*****************//
template<class T>
void	BubbleSort(T* data, IndexType start, IndexType end){
	for (IndexType m; 1 < end; end = m){
		for (IndexType i = m =start+ 1; i < end; ++i){
			if (data[i - 1]>data[i]){
				swap(data+i - 1, data+i);
				m = i;
			}
		}
	}
}
template < class T >
void	BubbleSort(T* data, IndexType len){
	BubbleSort(data, 0, len);
}

//*********	InsertSort		*****************//
template<class T>
void	InserSort(T* data, IndexType start, IndexType end){
	print(data, end - start);
	T d;
	for (IndexType i = start + 1; i < end; ++i){
		d = data[i];
		IndexType j;
		for (j = i - 1; d<data[j]; --j)
			data[j + 1] = data[j];
		data[j + 1] = d;
	}
}
template<class T>
void	InserSort(T* data, IndexType len){
	InserSort(data, 0, len);
}

//*********	ChooseSort		*****************//
template<class T>
void	ChooseSort(T* data, IndexType start, IndexType end){	
	for (IndexType i = start; i < end; ++i){
		IndexType k = i;
		for (IndexType j = i + 1; j < end; ++j){
			if (data[j] < data[k])
				k = j;
		}
		if (k != i) swap(data + k, data + i);
	}
}
template<class T>
void ChooseSort(T* data, IndexType len){
	ChooseSort(data, 0, len);
}

//*********	ShellSort		*****************//
template<class T>
void	ShellSort(T* data, IndexType s, IndexType e){
	IndexType increment = e - s;
	do{
		increment = increment / 3 + 1;
		for (IndexType i = increment; i < e; ++i){
			T d = data[i];
			IndexType j;
			for ( j = i - increment; d < data[j]; j -= increment)
				data[j + increment] = data[j];
			data[j + increment] = d;
		}
	} while (increment>1);
}

template<class T>
void ShellSort(T* data, IndexType len){
	ShellSort(data, 0, len);
}

//*********	QuickSort		*****************//
template<class  T>
void	QuickSort(T* data, IndexType s, IndexType e){
	if (e - s > 1){
		T key = data[s];
		IndexType pos = s;
		IndexType high = e - 1;
		IndexType i;
		for ( i = s + 1; i !=high; ++i){
			if (data[i] < key)pos++;
			else {
				swap(data + i, data + high);
				--high;
				--i;
			}
		}
		if (data[i] < key)swap(data + s, data + i);
		else swap(data + s, data + i - 1);
		QuickSort(data, s, pos);
		QuickSort(data, pos + 1, e);
	}
}

template<class T>
void	QuickSort(T* data, IndexType len){
	QuickSort(data, 0, len);
}

//*********	MergerSort		*****************//
template<class T>
void	MergerSort(T* data, IndexType s, IndexType e){
	IndexType mid = (e + s) >> 1;
	if (e - s>1){
		MergerSort(data, s, mid);
		MergerSort(data, mid, e);	
		T*	d = new T[e - s];
		IndexType low = s;
		IndexType m = mid;
		IndexType i = 0;
		while (low < mid&& m < e){
			if (data[low] < data[m]){
				d[i] = data[low];
				++low;				
			}else	{
				d[i] = data[m];
				++m;				
			}
			++i;			
		}
		while (low < mid)	d[i++] = data[low++];
		while (m < e)d[i++] = data[m++];
		
		for (IndexType i = 0; i < e - s; ++i)
			data[s + i] = d[i];

		delete[] d;
	}
}


template<class T>
void	MergerSort(T* data, IndexType len){
	MergerSort(data, 0, len);
}

//*********	HeapSort		*****************//
template<class T>
void	Heap(T* data, IndexType s, IndexType e){
	for (IndexType i = ((s + e) >> 1)+1; i; --i){
		if (2 * (i - 1) <e&&data[2 * (i - 1)] > data[i - 1]) swap(data + 2 * (i - 1), data + i - 1);
		if (2 * (i - 1) + 1 <e&& data[2 * (i - 1) + 1] > data[i - 1]) swap(data + 2 * (i - 1) + 1, data + i - 1);
	}
}
template<class T>
void	HeapSort(T* data, IndexType s, IndexType e){
	for (IndexType i = s; i < e; ++i){
		Heap(data, s, e-i-1);
		swap(data+s, data+ e - i - 1);
	}
}
template<class T>
void	HeapSort(T* data, IndexType len){
	HeapSort(data, 0, len);
}




#endif