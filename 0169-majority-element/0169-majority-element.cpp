class Solution {
	public:
		// Boyer–Moore Voting Algorithm
		int majorityElement(vector < int > vec) {
            
			//    int n = vec.size();
			//    int ans = 0 , feq = 0;
			//    for(int i= 0; i < n ; i++ ){
			//     if(feq == 0){
			//         ans = vec[i];
			//     }
			//     if(vec[i] == ans){
			//         feq++;
			//     }else{
			//         feq--;
			//     }
			//    }
			//    return ans;


			int ans = 0, fq = 0;
			for(int val: vec) {
				if(fq == 0) {
					ans = val;
				}
				if(val == ans) {
					fq++;
				} else {
					fq--;
				}
			}
			return ans;


			// int count = 0;
			// for (int val : vec)
			// {
			//     if (val == ans)
			//         count++;
			// }
			// if (count > n / 2)
			//     return ans;
			// else
			//     return -1;
		}
};