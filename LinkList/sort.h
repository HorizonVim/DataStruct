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
	T t;
	for (IndexType i = start + 1; i < end;++i){
		for (IndexType j = i-1; j >= start; --j){
			if (data[i] < data[j-1])
				swap(data+j, data+j-1)
		}
	}
}
template<class T>
void	InserSort(T* data, IndexType len){
	ChooseSort(data, 0, len);
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
void	ShellSort(T* data, IndexType start, IndexType end){
	IndexType	incremet = (end - start+1) / 3 + 1;
	while (incremet>1){
		for (IndexType i = 0; i < incremet; ++i){
			for (IndexType j = i + incremet; j < end; j += incremet){
				for (int m = j - incremet; m >= (int)i; m -= incremet){
					if (data[j] > data[m]){
						swap(data + j, data + m);
					}
				}
			}
		}
		incremet = incremet / 3 + 1;
	}	
}

template<class T>
void ShellSort(T* data, IndexType len){
	ShellSort(data, 0, len);
}


//*********	QuickSort		*****************//
template<class T>
void	QuickSort(T* data, IndexType start, IndexType end){
	print(data, end - start);
	if (end - start > 1){
		IndexType i;
		IndexType h = end;
		T key = data[start];

		for (i = start + 1; i < h; ++i){
			if (data[i] < key) data[i-1] = data[i];
			else{
				swap(data + h - 1, data + i);
				--h;
				--i;
				print(data, end - start);
			}
		}
	}
}
template<class T>
void	QuickSort(T* data, IndexType len){
	QuickSort(data, 0, len);
}


//*********	MergerSort		*****************//
template<class T>
void	MergerSort(T* data, IndexType start, IndexType end){
	IndexType mid=(start+end)>>1;
	if (end - start > 1){
		mid = (start - end) >> 1;
		MergerSort(data, start, mid);
		MergerSort(data, mid + 1, end);
	}
	else{
		T* tmp = new T[end - start];
		IndexType i = 0;
		IndexType low = start;
		IndexType m = mid + 1;
		IndexType high = end;
		while (low <= mid && m<high){
			if (data[low] > data[m]){
				tmp[i++] = data[m];
				++m;
			}
			else{
				tmp[i++] = data[low];
				++low;
			}
		}
		if (low < mid)tmp[i++] = data[low++];
		if (m < high) tmp[i++] = data[m++];
		for (IndexType i = 0; i < high - start; ++i)
			data[start + i] = tmp[i];
		delete[] tmp;
	}
}
template<class T>
void	MergerSort(T* data, IndexType len){
	MergerSort(data, 0, len);
}
//*********	HeapSort		*****************//
template<class T>
void	heap_adjust(T* data, IndexType start, IndexType end){
	T tmp=data[start];
	for (IndexType j = 2 * start; j <= end; j *= 2){
		if (j < m&& data[j] < data[j + 1])
			++j;
		if (tmp >= data[j])
			break;
		data[start] = data[j];
		start = j;
	}
	data[start] = tmp; 
}

template<class T>
void	HeapSort(T* data, IndexType start, IndexType end){
	for (IndexType i = end - start; i > 0; --i)
		heap_adjust(data, i, end);
	for (IndexType i = end - start; i > 0; --i){
		swap(data, i);
		heap_adjust(data, 0, i - 1);
	}

}
template<class T>
void	HeapSort(T* data, IndexType len){
	HeapSort(data, 0, len);
}




#endif