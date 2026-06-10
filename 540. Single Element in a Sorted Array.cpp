class Solution {
	public: int singleNonDuplicate(vector < int > & A) {
		int n = A.size();

		//    // o(n) approch 
		//     for (int i = 1; i < n; i++){
		//        if (A[i - 1] != A[i] && A[i] != A[i + 1])
		//        {
		//           return A[i];
		//         }
		//      }
		//     return -1;


		//     // edge cases but spce O(n)
		//      if (n == 1)
		//     return A[0];
		//   if (A[0] != A[1])
		//     return A[0];
		//     if (A[n - 1] != A[n - 2])
		//     return A[n - 1];
		//    for (int i = 1; i < n - 1; i++)
		// {
		//     if (A[i] != A[i - 1] && A[i] != A[i + 1])
		//     {
		//         return A[i];
		//     }
		// }
		// return -1;

        // /// O(n) liner Search
        // int ans = 0 ;
        // for(int i = 0 ; i<n ; i++){
        //     ans ^= A[i];
        // }
        // return ans;



		// //// O(log n )
		if(n == 1) return A[0];
		int st = 0, end = n - 1;
		while(st <= end) {
			int mid = st + (end - st) / 2;
			if(mid == 0 && A[0] != A[1]) return A[mid];
			if(mid == n - 1 && A[n - 1] != A[n - 2]) return A[mid];
            
			if(A[mid - 1] != A[mid] && A[mid] != A[mid + 1]) return A[mid];
			if(mid % 2 == 0) // even
			{
				if(A[mid - 1] == A[mid]) {
					end = mid - 1;
				} else {
					st = mid + 1;
				}
			} else { // odd
				if(A[mid - 1] == A[mid]) {
					st = mid + 1;
				} else {
					end = mid - 1;
				}
			}
		}
		return -1;


	}
};
