#if 1
#include <iostream>
#include <vector>

using namespace std;
#if 1
int binarySearch( vector<int>& arr, int low , int high, int target )
{  
   if (low > high )
      return -1;
    else {
        int mid = (low + high) / 2 ;
        if (target == arr[mid] )
            return mid;
         else if (target > arr[mid])
            return binarySearch (arr,mid+1,high,target);
         else
            return binarySearch (arr,low,mid-1,target);

    }
}
int binarySearchLeft( vector<int>& arr, int low , int high, int target,int lastIndex)
{
  
   if (low > high )
      return -1;
    else {
         int mid = low + (high-low) / 2 ;
        if (target == arr[mid] && ( mid == 0 || arr[mid-1] < target) )
            return mid;
         else if (target > arr[mid])
            return binarySearchLeft (arr,mid+1,high,target,lastIndex);
         else
            return binarySearchLeft (arr,low,mid-1,target,lastIndex);

    }
}
int binarySearchRight( vector<int>& arr, int low , int high , int target,int lastIndex)
{
 if (low > high )
      return -1;
    else {
         int mid = low + (high-low) / 2 ;
        if (target == arr[mid] && ( mid == lastIndex || target < arr[mid+1]))
            return mid;
        else if (target <  arr[mid] )
            return binarySearchRight(arr,low,mid-1,target,lastIndex);
         else
            return binarySearchRight(arr,mid+1,high,target,lastIndex);
    //// when I kept like below it was failed for case 2,2 h
      //else if (target >  arr[mid] )
     //       return binarySearchRight(arr,mid+1,high,target,lastIndex);
     //    else
     //       return binarySearchRight(arr,low,mid-1,target,lastIndex);

    }
}
vector<int> searchRange(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size()-1;
        vector<int> res{0,0};
        res[0] = binarySearchLeft(nums,l,r,target,r); 
        res[1] = binarySearchRight(nums,l,r,target,r);
        return res; 
    }
#endif
#if 0 
// submitted code
int BinarySearchSimple(vector<int>& A, int lo, int hi, int key, bool isMIN)
{
	int mid;
	int result = -1;
	while (lo <= hi)
	{
		mid = lo + (hi - lo) / 2;

		if (A[mid] == key)
		{
			//return mid;
			result = mid;
			if (isMIN == true)
				hi = mid - 1;
			else
				lo = mid + 1;
		}
		else if	(A[mid] < key) 
			lo = mid + 1;
		else
			hi = mid - 1;
	}

	return result;
}
 vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> res;
	int lo = 0;
	int hi = nums.size() - 1;
	//int no = binarySearch(nums, lo, hi, target,true); /// recur
	int no = BinarySearchSimple(nums, lo, hi, target, true); // iter 
	res.push_back(no);
	//no = binarySearch(nums, lo, hi, target,false);
	no = BinarySearchSimple(nums, lo, hi, target, false);
	res.push_back(no);
	return res;
    }

#endif
int main()
{
    vector<int> data{3,5,8,34,67,90,109,110};
   // int result = binarySearch(data,0,7,8);
  //  cout<<result<<endl;
    vector<int> data1{5,7,7,8,8,10};
    vector<int> res = searchRange(data1,8);
    cout<<"Range: ["<<res[0]<<","<<res[1]<<"]"<<endl;
    res = searchRange(data1,6);
    cout<<"Range: ["<<res[0]<<","<<res[1]<<"]"<<endl;
    vector<int> data2{5,7,8,8,10};
     res = searchRange(data2,7);  
    cout<<"Range: ["<<res[0]<<","<<res[1]<<"]"<<endl;
        vector<int> data3{2,2};
     res = searchRange(data3,2);  
    cout<<"Range: ["<<res[0]<<","<<res[1]<<"]"<<endl;

    return 0;
}
#endif
