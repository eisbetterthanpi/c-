sort




void bubble(int a[], int N) {
  // for (int L = 0; L <= N-2; ++L) { // O(N)
  //   int X = min_element(a+L, a+N) - a; // O(N)
  //   swap(a[X], a[L]); // O(1), X may be equal to L (no actual swap)
  // }
}
for (j = 0; j < 3; j++) // 3 passes
  for (i = 0; i < n-j-1; i++)
    if (A[i] > A[i+1])
      swap(A[i], A[i+1]);

void selectionSort(int a[], int N) {
  for (int L = 0; L <= N-2; ++L) { // O(N)
    int X = min_element(a+L, a+N) - a; // O(N)
    swap(a[X], a[L]); // O(1), X may be equal to L (no actual swap)
  }
}
for (i = 0; i < 3; i++) { // 3 passes
  cur_min = i;
  for (j = i+1; j < n; j++)
    if (A[j] < A[cur_min])
      cur_min = j;
  swap(A[i], A[cur_min]);
}

void insertionSort(int a[], int N) {
  for (int i = 1; i < N; ++i) { // O(N)
    int X = a[i]; // X is the item to be inserted
    int j = i-1;
    for (; j >= 0 && a[j] > X; --j) // can be fast or slow
      a[j+1] = a[j]; // make a place for X
    a[j+1] = X; // index j+1 is the insertion point
  }
}
for (i = 1; i <= 3; i++) { // 3 passes
  e = A[i]; j = i;
  while (j > 0) {
    if (A[j-1] > e)
      A[j] = A[j-1];
    else
      break;
    j--;
  }
  A[j] = e;
}

void mergeSort(int a[], int low, int high) {
  // the array to be sorted is a[low..high]
  if (low < high) { // base case: low >= high (0 or 1 item)
    int mid = (low+high) / 2;
    mergeSort(a, low  , mid ); // divide into two halves
    mergeSort(a, mid+1, high); // then recursively sort them
    merge(a, low, mid, high); // conquer: the merge subroutine
  }
}

void merge(int a[], int low, int mid, int high) {
  // subarray1 = a[low..mid], subarray2 = a[mid+1..high], both sorted
  int N = high-low+1;
  int b[N]; // discuss: why do we need a temporary array b?
  int left = low, right = mid+1, bIdx = 0;
  while (left <= mid && right <= high) // the merging
    b[bIdx++] = (a[left] <= a[right]) ? a[left++] : a[right++];
  while (left <= mid) b[bIdx++] = a[left++]; // leftover, if any
  while (right <= high) b[bIdx++] = a[right++]; // leftover, if any
  for (int k = 0; k < N; k++) a[low+k] = b[k]; // copy back
}

int main(){
   mergeSort(int a[], int low, int high)

}
